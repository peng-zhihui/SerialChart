#include "decoderbin.h"

DecoderBin::DecoderBin(QObject *parent,Configuration *config) :
    DecoderBase(parent,config)
{

}


void DecoderBin::newData(const QByteArray& newBytes){
    //qDebug(newBytes.toHex());
    packetBytes.append(newBytes);
    processPacket();
}


void DecoderBin::processPacket(){
    packetStarted = true;
    if(!packetBytes.isEmpty()){
        packetParts.clear();
        packetValues.clear();
        QByteArray part;
        QVariant value;
        int j = 0;
        for(int i=0; i < config->fields.length(); i++){
            QString field = config->fields[i];
            QString type = config->get(field,"type","byte");
            bool msbf = (config->get(field,"endian","msbf") == "msbf");
            int len = 1;
            value = 0;
            part = QByteArray().append('\0');
            if("byte" == type){
                part = packetBytes.mid(j,len);
                value = (unsigned char)part[0];
            }else if("sbyte" == type){
                part = packetBytes.mid(j,len);
                value = (char)part[0];
            }else if("word" == type){
                len = 2;
                part = packetBytes.mid(j,len);
                if(msbf){
                   value = (unsigned short)((unsigned char)part[0]*256 + (unsigned char)part[1]);
                }else{
                   value = (unsigned short)((unsigned char)part[0] + (unsigned char)part[1]*256);
                }
            }else if("sword" == type){
                len = 2;
                part = packetBytes.mid(j,len);
                if(msbf){
                   value = (short)((char)part[0]*256 + (unsigned char)part[1]);
                }else{
                   value = (short)((unsigned char)part[0] + (char)part[1]*256);
                }
            }else if("float" == type){
                len = 4;
                part = packetBytes.mid(j,len);
                value = *(float*)(part.data());
            }
            packetValues.append(value);
            packetParts.append(part);
            j += len;
        }
        emit newPacket(this);
    }
    packetBytes.clear();

}
