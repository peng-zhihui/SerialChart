#ifndef DECODERBIN_H
#define DECODERBIN_H


#include "decoderbase.h"

class DecoderBin : public DecoderBase
{
Q_OBJECT
public:
    explicit DecoderBin(QObject *parent = 0, Configuration* config = 0);

protected:
    void processPacket();

signals:
    void newPacket(DecoderBase*);

public slots:
    void newData(const QByteArray&);

};


#endif // DECODERBIN_H
