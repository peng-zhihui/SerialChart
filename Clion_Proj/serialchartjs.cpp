#include <QWidget>
#include "serialchartjs.h"
#include "mainwindow.h"


WebViewObject::WebViewObject(QObject *parent,QWebView* webView) :
    QObject(parent)
{
    mainwindow = (MainWindow*) (this->parent());
    this->webView = webView;
}



QString WebViewObject::hexPack(QVariant v,QString type){
    char buf[4];
    char size = 0;
    if("byte" == type){
        *((unsigned char*)buf) = v.value<unsigned char>();
        size = 1;
    }else if("sbyte" == type){
        *((signed char*)buf) = v.value<signed char>();
        size = 1;
    }else if("word" == type){
        *((unsigned short*)buf) = v.value<unsigned short>();
        size = 2;
    }else if("sword" == type){
        *((unsigned short*)buf) = v.value<signed short>();
        size = 2;
    }else if("float" == type){
        *((float*)buf) = v.value<float>();
        size = 4;
    }

    QByteArray qb(buf,size);
    return qb.toHex();
}

QVariant WebViewObject::hexUnpack(QString hexString,QString type){
    char buf[4];
    QByteArray qb = QByteArray::fromHex(hexString.toLatin1());
    memcpy(buf,qb.data(),qb.size());
    QVariant v = QVariant::Invalid;
    if("byte" == type){
        v = QVariant::fromValue(*((unsigned char*)(buf)));
    }else if("sbyte" == type){
        v = QVariant::fromValue(*((signed char*)(buf)));
    }else if("word" == type){
        v = QVariant::fromValue(*((unsigned short*)(buf)));
    }else if("sword" == type){
        v = QVariant::fromValue(*((signed short*)(buf)));
    }else if("float" == type){
        v =  QVariant::fromValue(*((float*)(buf)));
        return v; //return float as is
    }
    v.convert(QVariant::LongLong); //convert all integer types to higher resolution
    return v;
}
