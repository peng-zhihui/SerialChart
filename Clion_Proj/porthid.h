#ifndef PORTHID_H
#define PORTHID_H

#include "portbase.h"
#include "hiddevice.h"

class PortHid : public PortBase
{
Q_OBJECT
public:
    explicit PortHid(QObject *parent = 0,Configuration* config = 0);
    ~PortHid();
    virtual void run();
    virtual void send(const QByteArray & data);






private:
    HidDevice* hidDevice;
    bool isRunning;
    bool newLine;
    void portSetup();

signals:
    void newData(const QByteArray&);
    void stopped();
    void message(const QString& text,const QString& type);




public slots:
    //void start();
    void requestToStop();
};

#endif // PORTHID_H
