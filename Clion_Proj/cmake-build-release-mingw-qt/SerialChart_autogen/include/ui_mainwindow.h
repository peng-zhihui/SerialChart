/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "chart.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionNew;
    QAction *actionSaveAs;
    QAction *actionRun;
    QAction *actionStop;
    QAction *actionAbout;
    QAction *actionConfiguration;
    QAction *actionChart;
    QAction *actionToolbar;
    QAction *actionWebView;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QPlainTextEdit *dataText;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *sendText;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxCR;
    QCheckBox *checkBoxLF;
    QCheckBox *checkBoxEcho;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuProcess;
    QMenu *menu_Help;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetChart;
    QWidget *dockWidgetContentsChart;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    Chart *chart;
    QDockWidget *dockWidgetConfiguration;
    QWidget *dockWidgetContentsConfiguration;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *configurationText;
    QDockWidget *dockWidgetWebView;
    QWidget *dockWidgetContentsWebView;
    QVBoxLayout *verticalLayout_2;
    QWebView *webView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(976, 633);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/open.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon2);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon3);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        actionRun->setIcon(icon);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionStop->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon4);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionConfiguration = new QAction(MainWindow);
        actionConfiguration->setObjectName(QStringLiteral("actionConfiguration"));
        actionConfiguration->setCheckable(true);
        actionConfiguration->setChecked(true);
        actionChart = new QAction(MainWindow);
        actionChart->setObjectName(QStringLiteral("actionChart"));
        actionChart->setCheckable(true);
        actionChart->setChecked(true);
        actionToolbar = new QAction(MainWindow);
        actionToolbar->setObjectName(QStringLiteral("actionToolbar"));
        actionToolbar->setCheckable(true);
        actionToolbar->setChecked(true);
        actionWebView = new QAction(MainWindow);
        actionWebView->setObjectName(QStringLiteral("actionWebView"));
        actionWebView->setCheckable(true);
        actionWebView->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QStringLiteral(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(3, 3, 3, 3);
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(true);
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(label);


        verticalLayout->addWidget(frame_2);

        dataText = new QPlainTextEdit(frame);
        dataText->setObjectName(QStringLiteral("dataText"));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        font.setPointSize(10);
        dataText->setFont(font);

        verticalLayout->addWidget(dataText);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setAutoFillBackground(true);
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sendText = new QLineEdit(frame_3);
        sendText->setObjectName(QStringLiteral("sendText"));
        sendText->setEnabled(true);
        sendText->setMinimumSize(QSize(0, 0));
        sendText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(sendText);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        checkBoxCR = new QCheckBox(frame_3);
        checkBoxCR->setObjectName(QStringLiteral("checkBoxCR"));

        horizontalLayout_3->addWidget(checkBoxCR);

        checkBoxLF = new QCheckBox(frame_3);
        checkBoxLF->setObjectName(QStringLiteral("checkBoxLF"));
        checkBoxLF->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(checkBoxLF);

        checkBoxEcho = new QCheckBox(frame_3);
        checkBoxEcho->setObjectName(QStringLiteral("checkBoxEcho"));

        horizontalLayout_3->addWidget(checkBoxEcho);

        sendButton = new QPushButton(frame_3);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setEnabled(false);

        horizontalLayout_3->addWidget(sendButton);


        verticalLayout->addWidget(frame_3);


        horizontalLayout->addWidget(frame);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 976, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuProcess = new QMenu(menuBar);
        menuProcess->setObjectName(QStringLiteral("menuProcess"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidgetChart = new QDockWidget(MainWindow);
        dockWidgetChart->setObjectName(QStringLiteral("dockWidgetChart"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidgetChart->sizePolicy().hasHeightForWidth());
        dockWidgetChart->setSizePolicy(sizePolicy);
        dockWidgetChart->setMinimumSize(QSize(100, 201));
        dockWidgetChart->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContentsChart = new QWidget();
        dockWidgetContentsChart->setObjectName(QStringLiteral("dockWidgetContentsChart"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContentsChart);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(dockWidgetContentsChart);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 108, 374));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(0, 0, 0, 0);
        chart = new Chart(scrollAreaWidgetContents);
        chart->setObjectName(QStringLiteral("chart"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chart->sizePolicy().hasHeightForWidth());
        chart->setSizePolicy(sizePolicy1);
        chart->setMinimumSize(QSize(100, 100));

        formLayout->setWidget(0, QFormLayout::LabelRole, chart);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        dockWidgetChart->setWidget(dockWidgetContentsChart);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetChart);
        dockWidgetConfiguration = new QDockWidget(MainWindow);
        dockWidgetConfiguration->setObjectName(QStringLiteral("dockWidgetConfiguration"));
        dockWidgetConfiguration->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContentsConfiguration = new QWidget();
        dockWidgetContentsConfiguration->setObjectName(QStringLiteral("dockWidgetContentsConfiguration"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContentsConfiguration);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        configurationText = new QPlainTextEdit(dockWidgetContentsConfiguration);
        configurationText->setObjectName(QStringLiteral("configurationText"));
        configurationText->setEnabled(true);
        configurationText->setFont(font);
        configurationText->setReadOnly(false);

        verticalLayout_3->addWidget(configurationText);

        dockWidgetConfiguration->setWidget(dockWidgetContentsConfiguration);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetConfiguration);
        dockWidgetWebView = new QDockWidget(MainWindow);
        dockWidgetWebView->setObjectName(QStringLiteral("dockWidgetWebView"));
        sizePolicy.setHeightForWidth(dockWidgetWebView->sizePolicy().hasHeightForWidth());
        dockWidgetWebView->setSizePolicy(sizePolicy);
        dockWidgetWebView->setMinimumSize(QSize(100, 100));
        dockWidgetWebView->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContentsWebView = new QWidget();
        dockWidgetContentsWebView->setObjectName(QStringLiteral("dockWidgetContentsWebView"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContentsWebView);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        webView = new QWebView(dockWidgetContentsWebView);
        webView->setObjectName(QStringLiteral("webView"));
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        verticalLayout_2->addWidget(webView);

        dockWidgetWebView->setWidget(dockWidgetContentsWebView);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetWebView);
        dockWidgetWebView->raise();

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuProcess->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuProcess->addAction(actionRun);
        menuProcess->addAction(actionStop);
        menu_Help->addAction(actionAbout);
        menuView->addAction(actionToolbar);
        menuView->addSeparator();
        menuView->addAction(actionConfiguration);
        menuView->addAction(actionChart);
        menuView->addAction(actionWebView);
        menuView->addSeparator();
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRun);
        mainToolBar->addAction(actionStop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Serial Chart", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\205\215\347\275\256", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionExit->setText(QApplication::translate("MainWindow", "E&xit", 0));
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\351\205\215\347\275\256", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\351\205\215\347\275\256", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272\351\205\215\347\275\256", 0));
        actionRun->setText(QApplication::translate("MainWindow", "Run", 0));
        actionRun->setShortcut(QApplication::translate("MainWindow", "F5", 0));
        actionStop->setText(QApplication::translate("MainWindow", "&Stop", 0));
        actionStop->setShortcut(QApplication::translate("MainWindow", "F6", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&\345\205\263\344\272\216", 0));
        actionConfiguration->setText(QApplication::translate("MainWindow", "Configuration", 0));
        actionChart->setText(QApplication::translate("MainWindow", "Chart", 0));
        actionToolbar->setText(QApplication::translate("MainWindow", "Toolbar", 0));
        actionWebView->setText(QApplication::translate("MainWindow", "WebView", 0));
        label->setText(QApplication::translate("MainWindow", "Data", 0));
        sendText->setText(QString());
        checkBoxCR->setText(QApplication::translate("MainWindow", "\\ r", 0));
        checkBoxLF->setText(QApplication::translate("MainWindow", "\\ n", 0));
        checkBoxEcho->setText(QApplication::translate("MainWindow", "echo", 0));
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "&\346\226\207\344\273\266", 0));
        menuProcess->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234", 0));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&\345\270\256\345\212\251", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", 0));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Toolbar", 0));
        dockWidgetChart->setWindowTitle(QApplication::translate("MainWindow", "Chart", 0));
        dockWidgetConfiguration->setWindowTitle(QApplication::translate("MainWindow", "Configuration", 0));
        configurationText->setDocumentTitle(QString());
        configurationText->setPlainText(QString());
        dockWidgetWebView->setWindowTitle(QApplication::translate("MainWindow", "WebView", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
