#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define APP_NAME "SerialChart"
#define APP_VERSION "0.3.4"


#include <QMainWindow>
#include "common.h"
#include "portbase.h"
#include "displaybase.h"


class Plugin;
class DecoderBase;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    PortBase* getPort(int portID);
    Plugin* getPlugin(){return plugin;};
    DecoderBase* getDecoder(){return decoder;};
    bool isPluginReady(){return pluginReady;};

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);
    void showEvent(QShowEvent *e);



private:
    Ui::MainWindow *ui;

    QSettings settings;
    QString documentFilePath;
    void updateDocumentFilePath(const QString& filePath);

    bool saveDocument(const QString& filePath);
    bool loadDocument(const QString& filePath);
    bool checkDocument();
    bool documentIsDirty;
    Configuration* config;

    PortBase* port;
    DecoderBase* decoder;
    DisplayBase* display;

    bool portValid;
    bool sendString(QString str);

    Plugin* plugin;

    bool pluginReady = false;
    bool pluginLoading = false;

private slots:
    void on_sendButton_clicked();
    void on_actionConfiguration_toggled(bool );

    void on_actionChart_toggled(bool );
    void on_actionToolbar_toggled(bool );
    void on_actionWebView_toggled(bool arg1);

    void on_actionStop_triggered();
    void on_actionRun_triggered();
    void on_actionAbout_triggered();
    void on_actionSaveAs_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionNew_triggered();

    void on_configurationText_textChanged();

    void portStopped();
    void message(const QString& text,const QString& type);

    void on_sendText_returnPressed();

    void mainFrame_javaScriptWindowObjectCleared();
    void mainFrame_loadFinished (bool  ok);
};

#endif // MAINWINDOW_H
