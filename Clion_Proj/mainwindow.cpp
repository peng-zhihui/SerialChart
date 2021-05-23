#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "decoderbase.h"
#include "plugin.h"
#include "QWebFrame"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    documentIsDirty = false;

    config = new Configuration(this);
    portValid = false;

    setWindowTitle(APP_NAME " " APP_VERSION);
    loadDocument(settings.value("Last Configuration").toString());
    restoreGeometry(settings.value("WINDOW_GEOMETRY").toByteArray());
    restoreState(settings.value("DOCK_LOCATIONS").toByteArray());


    //WebView
    QWebSettings::clearMemoryCaches(); //clear cache
    //disable cache
    QWebSettings::globalSettings()->setMaximumPagesInCache(0);
    QWebSettings::globalSettings()->setObjectCacheCapacities(0, 0, 0);

    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true); //enable Inspector
    plugin = new Plugin(this,ui->webView);
    connect(ui->webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(mainFrame_javaScriptWindowObjectCleared()));
    connect(ui->webView->page()->mainFrame(), SIGNAL(loadFinished ( bool  )), this, SLOT(mainFrame_loadFinished ( bool  )));
    connect(plugin, SIGNAL(eval(const QString&)), ui->webView->page()->mainFrame(), SLOT(evaluateJavaScript ( const QString&)));

}

void MainWindow::mainFrame_javaScriptWindowObjectCleared(){
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject("PLUGIN", plugin);
}


void MainWindow::mainFrame_loadFinished (bool  ok){
    qDebug() << "mainFrame_loadFinished" << ok;
    if(this->pluginLoading){
        this->pluginReady = ok;
        this->pluginLoading = false;
    }
}

void MainWindow::showEvent(QShowEvent *e)
{
    QMainWindow::showEvent(e);
    //Update View menu checkboxes
    ui->actionToolbar->setChecked(ui->mainToolBar->isVisible());
    ui->actionConfiguration->setChecked(ui->dockWidgetConfiguration->isVisible());
    ui->actionChart->setChecked(ui->dockWidgetChart->isVisible());
    ui->actionWebView->setChecked(ui->dockWidgetWebView->isVisible());
}



MainWindow::~MainWindow()
{

    settings.setValue("WINDOW_GEOMETRY", saveGeometry());
    settings.setValue("DOCK_LOCATIONS",saveState());

    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void MainWindow::closeEvent(QCloseEvent *e)
{
    if(portValid) port->requestToStop();
    if(!checkDocument()) e->ignore();
}

void MainWindow::on_actionNew_triggered()
{
    if(checkDocument()){
        ui->configurationText->clear();
        documentFilePath = "";
        ui->statusBar->showMessage(documentFilePath);
        documentIsDirty  = false;
    }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionOpen_triggered()
{
    if(!checkDocument()) return;

    QString filePath = QFileDialog::getOpenFileName(this,
        tr("Open File"), documentFilePath, tr("SerialChart Configuration (*.scc);;All Files (*.*)"));

    if(!filePath.isEmpty()) loadDocument(filePath);

}

void MainWindow::on_actionSave_triggered()
{
    if(documentFilePath.isEmpty())
        on_actionSaveAs_triggered();
    else
        saveDocument(documentFilePath);
}

void MainWindow::on_actionSaveAs_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"),
                               documentFilePath,
                               tr("SerialChart Configuration (*.scc);;All Files (*.*)"));
    if(!filePath.isEmpty()) saveDocument(filePath);
}

bool MainWindow::checkDocument(){
    if(documentIsDirty)
        if(QMessageBox::No == QMessageBox::warning(0,"","Current configuration was changed but not saved.\nAre you sure you want to proceed ?",QMessageBox::Yes,QMessageBox::No|QMessageBox::Default))
            return false;
    return true;
}

bool MainWindow::saveDocument(const QString& filePath)
{
    bool success = false;
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream textStream(&file);
        textStream<<ui->configurationText->toPlainText();
        textStream.flush();
        documentIsDirty  = false;
        updateDocumentFilePath(filePath);
        success = true;
    }

    if(!success)
        QMessageBox::critical(0,"","Could not save file: " + filePath);
    else
        ui->statusBar->showMessage("File Saved",2000);

    return success;
}

bool MainWindow::loadDocument(const QString& filePath)
{
    bool success = true;
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream textStream(&file);
        ui->configurationText->setPlainText(textStream.readAll());
        updateDocumentFilePath(filePath);
        success = true;
    }

    if(!success) QMessageBox::critical(0,"","Could not load file: " + filePath);

    return success;
}

void MainWindow::updateDocumentFilePath(const QString& filePath){
    documentFilePath = filePath;
    settings.setValue("Last Configuration",filePath);
    this->setWindowTitle("串口示波器" " " APP_VERSION " - " + QFileInfo(filePath).fileName() );
    documentIsDirty  = false;
};


void MainWindow::on_configurationText_textChanged()
{
    documentIsDirty = true;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(0,"","SerialChart ver. " \
        APP_VERSION \
        "\nModified by Pengzhihui\nwww.pengzhihui.xyz");
}

void MainWindow::on_actionRun_triggered()
{
    config->parse( ui->configurationText->toPlainText());

    //webView
    this->pluginReady = false;  //will be set by mainFrame_loadFinished
    this->pluginLoading = false;

    QString plugin_url = config->get("_setup_","plugin","about:blank").trimmed();
    QUrl url(plugin_url);
    if( !(
        plugin_url.startsWith("http://",Qt::CaseInsensitive) ||
        plugin_url.startsWith("https://",Qt::CaseInsensitive) ||
        plugin_url.startsWith("about:",Qt::CaseInsensitive)
    )){
        //assume local file if no supported scheme given
        QDir base_dir = QFileInfo(documentFilePath).dir();
        QFileInfo fileinfo(plugin_url);
        if(fileinfo.isRelative()) fileinfo.setFile(base_dir,plugin_url);
        url = url.fromLocalFile(fileinfo.absoluteFilePath());
    }
    qDebug() << "plugin url:" << url.toString();
    ui->webView->load(QUrl("about:blank")); //clear previous page
    this->pluginLoading = true;
    ui->webView->load(url);

    //dataText
    ui->dataText->setMaximumBlockCount(MAX(1,config->get("_setup_","width").toInt()));
    ui->dataText->clear();

    //chart
    ui->chart->init(config);

    //actions
    ui->actionRun->setEnabled(false);
    ui->actionStop->setEnabled(true);
    ui->sendButton->setEnabled(true);

    //port
    port = createPort(this,config);
    decoder = createDecoder(this,config);
    display = createDisplay(this,config);
    portValid = true;


    //port signals
    connect(port,SIGNAL(newData(const QByteArray&)),decoder,SLOT(newData(const QByteArray&)));
    connect(port,SIGNAL(ready(int)),plugin,SLOT(slotPortReady(int)));
    connect(port,SIGNAL(stopped()),this,SLOT(portStopped()));

    connect(port,SIGNAL(message(const QString&,const QString&)),this,SLOT(message(const QString&,const QString&)));
    //decoder signals
    connect(decoder,SIGNAL(newPacket(DecoderBase*)),ui->chart,SLOT(newPacket(DecoderBase*)));
    connect(decoder,SIGNAL(newPacket(DecoderBase*)),display,SLOT(newPacket(DecoderBase*)));
    connect(decoder,SIGNAL(newPacket(DecoderBase*)),plugin,SLOT(slotNewPacket(DecoderBase*)));
    //display signals
    connect(display,SIGNAL(newDisplay(const QString&)),ui->dataText,SLOT(appendPlainText(const QString&)));

    //Startup send
    QString send_run = config->get("_setup_","send_run","").trimmed();
    if("" != send_run){
        port->forceSend = true; //append to send buffer even if port is not running
        sendString(send_run);
        port->forceSend = false;
    }

    port->start();

}

void MainWindow::on_actionStop_triggered()
{
    QString send_stop = config->get("_setup_","send_stop","").trimmed();
    if("" != send_stop){
        port->forceSend = true; //append to send buffer even if port is not running
        sendString(send_stop);
        port->forceSend = false;
    }

    ui->actionStop->setEnabled(false);
    ui->sendButton->setEnabled(false);

    this->pluginReady = false;  //will be set by mainFrame_loadFinished
    this->pluginLoading = false;

    port->requestToStop();
}

void MainWindow::portStopped(){
    ui->actionStop->setEnabled(false);
    ui->sendButton->setEnabled(false);
    ui->actionRun->setEnabled(true);
    port->deleteLater();
    portValid = false;
    delete decoder;
    delete display;
}

void MainWindow::on_actionToolbar_toggled(bool b)
{
    ui->mainToolBar->setVisible(b);
}

void MainWindow::on_actionChart_toggled(bool b)
{
    ui->dockWidgetChart->setVisible(b);
}

void MainWindow::on_actionConfiguration_toggled(bool b)
{
    ui->dockWidgetConfiguration->setVisible(b);
}


void MainWindow::on_actionWebView_toggled(bool b)
{
      ui->dockWidgetWebView->setVisible(b);
}


void MainWindow::on_sendButton_clicked(){
    sendString( ui->sendText->text());
}

bool MainWindow::sendString(QString str){
    if(portValid){
        if(ui->checkBoxCR->isChecked()) str.append('\r');
        if(ui->checkBoxLF->isChecked()) str.append('\n');
        QByteArray data = stringLiteralUnescape(str.toLatin1());
        if(ui->checkBoxEcho->isChecked()) ui->dataText->appendPlainText(data);
        port->send(data);
    }
    return portValid;
}



void MainWindow::message(const QString& text,const QString& type)
{
    if("critical"==type) QMessageBox::critical(0,"",text);
    else QMessageBox::information(0,"",text);
}

void MainWindow::on_sendText_returnPressed()
{
    on_sendButton_clicked();
}

PortBase* MainWindow::getPort(int portID){
    return portValid ? port : NULL;
 }
