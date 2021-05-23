#include "portbase.h"
#include "portrs232.h"
#include "porthid.h"

PortBase::PortBase(QObject *parent,Configuration* config) :
    QThread(parent)
{
    this->mainwindow = (MainWindow*) (this->parent());
    this->config = config;
    this->forceSend = false;
    this->portID = 0;
}


PortBase* createPort(QObject *parent,Configuration* config){
    if(0 == config->get("_setup_","port").compare("hid",Qt::CaseInsensitive))
        return new PortHid(parent,config);
    //default
        return new PortRs232(parent,config);
}


PortBase::~PortBase(){

}



QByteArray stringLiteralUnescape(const QByteArray & data){
    QByteArray result;
    uchar escaped = 0;           //escaped char zone \n \r \t, etc
    uchar escaped_hex = 0;      //escaped hex byte zone  \x20
    uchar escaped_dec = 0;      //escaped dec byte zone  \d062 , \d158
    unsigned char digitsByte;   //byte built from escaped digits (hex, dec, etc)


    for(int i=0;i<data.size();i++){
        uchar c = data.data()[i];

        if(escaped_hex > 0){
            uchar c_lower = tolower(c);
            if('0'<=c && c<='9') {digitsByte = digitsByte*16 + (c-'0'); escaped_hex--;}
            else if('a'<=c_lower && c_lower<='f') {
                digitsByte = digitsByte*16 + (c-'a'+10); escaped_hex--;}
            else {
                escaped_hex = 0; i--; //invalid digit, process char again on next loop
            }
            if(0==escaped_hex){ result.append(digitsByte);};
        }else if(escaped_dec > 0){
            if('0'<=c && c<='9') {
                digitsByte = digitsByte*10 + (c-'0'); escaped_dec--;}
            else {
                escaped_dec = 0; i--; //process char again, process char again on next loop
            }
            if(0==escaped_dec){ result.append(digitsByte);};
        }else if(escaped){
            if('n'==c) result.append('\n');
            if('r'==c) result.append('\r');
            if('t'==c) result.append('\t');
            if('\\'==c) result.append('\\');
            if('x'==c) {escaped_hex = 2; digitsByte = 0;};    //expect 2 hex chars
            if('d'==c) {escaped_dec = 3;  digitsByte = 0;};   //expect 3 decimal chars
            escaped = 0;
        }else{
            if('\\'==c) escaped = 1;
            else result.append(c);

        }
    }
    return result;
}
