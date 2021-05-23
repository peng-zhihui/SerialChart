#ifndef Plugin_H
#define Plugin_H

#include <QObject>
#include <QDebug>
#include "mainwindow.h"
#include "hiddevice.h"
#include <QWebView>
#include "decoderbase.h"
#include "decoderplugin.h"

class Plugin : public QObject
{
    Q_OBJECT
private:
    QString dataFormat = "string";
    MainWindow* mainwindow;
    QWebView* webView;


public:
    explicit Plugin(QObject *parent = 0, QWebView* webView = 0);
    Q_INVOKABLE QString hexPack(QVariant v,QString type);
    Q_INVOKABLE QVariant hexUnpack(QString hexString,QString type);
    Q_INVOKABLE QString hexEscape(QString string);
    Q_INVOKABLE QString hexUnescape(QString hexString);
    Q_INVOKABLE void newPacket(QString values);


    Q_INVOKABLE bool setDataFormat(QString dataFormat){
        if("string" == dataFormat || "hex" == dataFormat){
            this->dataFormat = dataFormat;
            return true;
        }
        return false;
    }

    Q_INVOKABLE QString getDataFormat(){ return this->dataFormat; }


    Q_INVOKABLE QVariant portSend(int portID,QString string);


    QVariant call(const QString function, QString params);

    void newData(const QByteArray& newBytes);
    void newLine(const QByteArray& line);


public slots:
    void slotNewPacket(DecoderBase* decoder);
    void slotPortReady(int portID);

signals:
    QVariant eval(const QString & scriptSource);

private slots:




};

#endif
