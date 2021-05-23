#ifndef DISPLAYBASE_H
#define DISPLAYBASE_H

#include <QObject>
#include "configuration.h"
#include "decoderbase.h"

class DisplayBase : public QObject
{
Q_OBJECT
public:
    explicit DisplayBase(QObject *parent = 0,Configuration *config=0);
private:
    Configuration* config;

signals:
    void newDisplay(const QString& str);

public slots:
    void newPacket(DecoderBase* decoder);

};

DisplayBase* createDisplay(QObject *parent,Configuration *config);

#endif // DISPLAYBASE_H
