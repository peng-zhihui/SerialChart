#ifndef DECODERCSV_H
#define DECODERCSV_H

#include "decoderbase.h"

class DecoderCsv : public DecoderBase
{
Q_OBJECT
public:
    explicit DecoderCsv(QObject *parent = 0, Configuration* config = 0);


signals:
    void newPacket(DecoderBase*);

public slots:
    void newData(const QByteArray&);

};



#endif // DECODERCSV_H
