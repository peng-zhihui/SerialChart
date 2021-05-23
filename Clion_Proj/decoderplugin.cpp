#include "decoderplugin.h"
#include "mainwindow.h"
#include "plugin.h"

DecoderPlugin::DecoderPlugin(QObject *parent,Configuration* config) :
    DecoderBase(parent,config)
{
}



void DecoderPlugin::newData(const QByteArray& newBytes){
    MainWindow* mainwindow = (MainWindow*) (this->parent());
    mainwindow->getPlugin()->newData(newBytes);

    //process line
    for(int i=0;i<newBytes.length();i++){
        char c = newBytes[i];
        if(13 == c || 10 == c){
            packetStarted = true;
            if(!packetBytes.isEmpty()){
                mainwindow->getPlugin()->newLine(packetBytes);
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


void DecoderPlugin::pluginNewPacket(QString values){
    packetParts = values.toLatin1().split(',');
    packetValues.clear();
    QList<QByteArray>::iterator i;
    for(i=packetParts.begin();i!=packetParts.end();i++){
        packetValues.append((*i).trimmed().toDouble());
    }
    emit newPacket(this);
}
