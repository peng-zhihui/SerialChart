#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "common.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Configuration : public QObject
{
Q_OBJECT
public:
    explicit Configuration(QObject *parent = 0);
    void parse(const QString& str);
    const QString get(const QString& sectionName,const QString& propertyName,const QString& defaultValue="");
    QStringList fields;

private:
    QHash<QString, QHash<QString,QString > > sections;




signals:

public slots:

};

#endif // CONFIGURATION_H
