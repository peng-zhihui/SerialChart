#ifndef DECODERBASE_H
#define DECODERBASE_H

#include <QObject>
#include "configuration.h"

 class DecoderBase : public QObject
{
Q_OBJECT
public:
    explicit DecoderBase(QObject *parent = 0, Configuration* config = 0);

    const QByteArray& getPacketBytes(){return packetBytes;};
    const QList<QByteArray>& getPacketParts(){return packetParts;};
    const QList<QVariant>& getPacketValues(){return packetValues;};



protected:
    Configuration* config;
    int packetMaxLen;
    bool packetStarted;
    QByteArray packetBytes;
    QList<QByteArray> packetParts;
    QList<QVariant> packetValues;

signals:
    //virtual void newPacket(const DecoderBase*);

public slots:
    virtual void newData(const QByteArray&) = 0;

};

DecoderBase* createDecoder(QObject *parent, Configuration* config);

#endif // DECODERBASE_H
