#include "configuration.h"

Configuration::Configuration(QObject *parent) :
    QObject(parent)
{

}

const QString Configuration::get(const QString& sectionName,const QString& propertyName,const QString& defaultValue){

    if(sections.contains(sectionName) && sections[sectionName].contains(propertyName)){
        return sections[sectionName][propertyName];
    }else{
        if(sectionName!="_setup_" && sectionName!="_default_")
            return get("_default_",propertyName,defaultValue);
        else
            return defaultValue;
    }
}


void Configuration::parse(const QString& str){
    //load defaults
    fields.clear();
    sections.clear();

    sections["_setup_"]["port"] = "COM1";
    sections["_setup_"]["baudrate"] = "9600";
    sections["_setup_"]["min"] = "-100";
    sections["_setup_"]["max"] = "100";

    sections["_default_"] ["color"] = "black";   //http://www.w3.org/TR/SVG/types.html#ColorKeywords
    sections["_default_"] ["min"] = "-100";
    sections["_default_"] ["max"] = "100";


    //parse configuration
    QString sectionName = "_setup_";
    QStringList lines = str.split(QRegExp("[\\x0D\\x0A]+"));
    QStringList::iterator i;
    for(i=lines.begin();i!=lines.end();i++){
        QString line = *i;
        //qDebug(("{"+ line +"}").toAscii());
        QRegExp rx("^\\s*\\[\\s*(\\w+)\\s*\\]\\s*$");
        if(rx.exactMatch(line)){
            //qDebug((" section["+rx.capturedTexts()[1]+"]").toAscii());
            sectionName = rx.capturedTexts()[1];
            if(!fields.contains(sectionName) && sectionName!="_setup_" && sectionName!="_default_") fields.append(sectionName);;
            continue;
        }
        rx.setPattern("^\\s*(\\w+)\\s*\\=(.*)$");
        if(rx.exactMatch(line)){
            QString value = rx.capturedTexts()[2];
            value = value.trimmed();
            sections[sectionName][rx.capturedTexts()[1]] = value;
            //qDebug((" pair["+rx.capturedTexts()[1]+","+value+"]").toAscii());
            continue;
        }
    }

}



