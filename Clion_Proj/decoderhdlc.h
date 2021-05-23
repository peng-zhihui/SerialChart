#ifndef DECODERHDLC_H
#define DECODERHDLC_H

#include "decoderbin.h"

class DecoderHdlc : public DecoderBin
{
Q_OBJECT
public:
    explicit DecoderHdlc(QObject *parent = 0, Configuration* config = 0);

private:
    char hdlc_esc;
    char hdlc_sep;
    char hdlc_xor;
    bool escapeFlag;

/*
signals:
    void newPacket(DecoderBase*);
*/

public slots:
    void newData(const QByteArray&);
};

#endif // DECODERHDLC_H
