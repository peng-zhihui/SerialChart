#ifndef PORTRS232_H
#define PORTRS232_H

#include "portbase.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#define MAX_DATA_LINE_LEN   1024

class PortRs232 : public PortBase
{
Q_OBJECT
public:
    explicit PortRs232(QObject *parent = 0,Configuration* config = 0);
    ~PortRs232();
    virtual void run();
    virtual void send(const QByteArray & data);


private:
    QSerialPort* serialPort;
    bool isRunning;

    void portSetup();
    void processDataLine();

signals:
    void newData(const QByteArray&);
    void stopped();
    void message(const QString& text,const QString& type);

public slots:
    void requestToStop();
};

#endif // PORTRS232_H
