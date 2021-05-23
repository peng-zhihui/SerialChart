#include "mainwindow.h"
#include "porthid.h"

PortHid::PortHid(QObject *parent,Configuration* config)
    : PortBase(parent,config)
{
    isRunning = false;
    hidDevice = 0;
}



void PortHid::run(){
    if(isRunning) return;
    hidDevice = new HidDevice();
    if(hidDevice->connect("vid_"+config->get("_setup_","vid")+"&"+"pid_"+config->get("_setup_","pid"))){
        isRunning = true;
        unsigned char in_report_id = config->get("_setup_","in_report_id","0").toInt();
        int in_endpoint_size = config->get("_setup_","in_endpoint_size","64").toInt();


        dataBytes.resize(in_endpoint_size +1);

        readyEmitted = false;
        while(isRunning){
            if(!readyEmitted && mainwindow->isPluginReady()) {emit ready(portID); readyEmitted = true;}
            //read
            hidDevice->read(in_report_id,dataBytes);
            emit newData(dataBytes);
            qApp->processEvents();
        }

    }else{
        emit message("Could not open USB HID with VID="+config->get("_setup_","vid")+" PID="+config->get("_setup_","pid")+"\nMake sure the device is attached.","critical");
    };

    isRunning = false;

    delete hidDevice;
    emit stopped();

}

void PortHid::send(const QByteArray & data){

}


void PortHid::requestToStop(){
    isRunning = false;
}

PortHid::~PortHid(){

}
