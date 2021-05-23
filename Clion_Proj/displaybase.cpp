#include "displaybase.h"

DisplayBase::DisplayBase(QObject *parent,Configuration* config) :
    QObject(parent)
{
    this->config = config;

}


DisplayBase* createDisplay(QObject *parent,Configuration *config){
    return new DisplayBase(parent,config);
}


void DisplayBase::newPacket(DecoderBase* decoder){
    QByteArray displayResult;
    QString display = config->get("_setup_","display","raw");

    if(display == "list"){
        QByteArray display_sep =  QByteArray::fromPercentEncoding(
            config->get("_setup_","display_sep",",").toLatin1()
        );
        int display_skip_transparent = config->get("_setup_","display_skip_transparent","0").toInt();
        QList<QVariant> packetValues = decoder->getPacketValues();
        QList<QByteArray> packetParts = decoder->getPacketParts();
        bool first = true;
        for(int i=0; i < MIN(config->fields.length(),packetValues.length()); i++){
            QString field = config->fields[i];
            QByteArray format =  config->get(field,"format","%f").toLatin1();
            int precision = config->get(field,"precision","6").toInt();

            if(!display_skip_transparent || config->get(field,"color") != "transparent"){
                if(!first) displayResult += QString(display_sep);
                QByteArray v = format;


                v.replace(QByteArray("%g"),QByteArray::number(packetValues[i].toDouble(),'g',precision));
                v.replace(QByteArray("%f"),QByteArray::number(packetValues[i].toDouble(),'f',precision));
                v.replace(QByteArray("%d"),QByteArray::number(packetValues[i].toInt(),'f',0));
                v.replace(QByteArray("%n"),field.toLatin1());
                v.replace(QByteArray("%s"),packetParts[i]);
                v.replace(QByteArray("%x"),packetParts[i].toHex());


                displayResult += v;
                first = false;
            }
        }



        emit newDisplay(displayResult);
    }else if(display == "hex"){
        emit newDisplay(decoder->getPacketBytes().toHex());
    }else{
        emit newDisplay(decoder->getPacketBytes());
    }

}
