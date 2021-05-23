#ifndef WebViewObject_H
#define WebViewObject_H

#include <QObject>
#include <QDebug>
#include "mainwindow.h"
#include "hiddevice.h"
#include <QWebView>

class WebViewObject : public QObject
{
Q_OBJECT
public:
    explicit WebViewObject(QObject *parent = 0, QWebView *webView = 0);

    Q_INVOKABLE QString hexPack(QVariant v, QString type);

    Q_INVOKABLE QVariant hexUnpack(QString hexString, QString type);


signals:

    QVariant eval(const QString &scriptSource);

private slots:


private:
    void call(QString function, QString parms);

    MainWindow *mainwindow;
    QWebView *webView;


};

#endif // WebViewObject_H
