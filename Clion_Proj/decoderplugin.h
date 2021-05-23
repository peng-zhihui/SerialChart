#ifndef DECODERPLUGIN_H
#define DECODERPLUGIN_H

#include "decoderbase.h"
class DecoderPlugin : public DecoderBase
{
    Q_OBJECT
public:
    explicit DecoderPlugin(QObject *parent = 0, Configuration* config = 0);


    void pluginNewPacket(QString values); //used by plugin to make decoder emit a new packet

signals:
    void newPacket(DecoderBase*);

public slots:
    void newData(const QByteArray&);
};



#endif // DECODERPLUGIN_H
