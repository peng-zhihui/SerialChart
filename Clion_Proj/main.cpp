#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qDebug(QCoreApplication::applicationDirPath().toLatin1());
    //The next 2 line have been added to solve https://github.com/starlino/serialchart/issues/11
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + "/platforms/");
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath());
    QCoreApplication::setOrganizationName("Starlino");
    QCoreApplication::setApplicationName(APP_NAME);
    MainWindow w;
    w.show();
    return a.exec();
}
