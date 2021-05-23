#ifndef PORTBASE_H
#define PORTBASE_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include "configuration.h"
#include "decoderbase.h"

class MainWindow;

class PortBase : public QThread
{
Q_OBJECT
public:
    explicit PortBase(QObject *parent = 0,Configuration* config = 0);
    virtual ~PortBase();
    DecoderBase* decoder;

    virtual void run() = 0;
    virtual void send(const QByteArray & data) = 0;

    bool forceSend;

    //int getPortID(){ return portID ;}

protected:
    Configuration* config;
    QByteArray dataBytes;
    QList<double> dataValues;
    QByteArray sendBytes;
    QMutex sendMutex;
    bool readyEmitted;
    int portID;
    MainWindow* mainwindow;

signals:
    //void stopped() = 0;
    //void newData(const QByteArray&);
    //void message(const QString& text,const QString& type);
    void ready(int portID);

public slots:
    //virtual void start() = 0;
    virtual void requestToStop() = 0;

};

PortBase* createPort(QObject *parent,Configuration* config);


QByteArray stringLiteralUnescape(const QByteArray & data);


#endif // PORTBASE_H
