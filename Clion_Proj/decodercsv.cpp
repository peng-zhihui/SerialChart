#include "decodercsv.h"

DecoderCsv::DecoderCsv(QObject *parent,Configuration* config) :
    DecoderBase(parent,config)
{

}


void DecoderCsv::newData(const QByteArray& newBytes){
    for(int i=0;i<newBytes.length();i++){
        char c = newBytes[i];
        if(13 == c || 10 == c){
            packetStarted = true;
            if(!packetBytes.isEmpty()){
                packetParts = packetBytes.split(',');
                packetValues.clear();
                QList<QByteArray>::iterator i;
                for(i=packetParts.begin();i!=packetParts.end();i++){
                    packetValues.append((*i).trimmed().toDouble());
                }
                emit newPacket(this);
            }
            packetBytes.clear();
        }else{
            if(packetStarted){
                packetBytes.append(c);
                if(packetBytes.length() > packetMaxLen){
                    packetBytes.clear();        //discard packet
                    packetStarted = false;
                }
            }
        }
    }
}




