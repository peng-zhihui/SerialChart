#include <QWidget>
#include "plugin.h"
#include "mainwindow.h"
#include "portbase.h"
#include <QJsonDocument>
#include <QJsonArray>


//#define ARRAY_2_JSON(a) QJsonDocument(QJsonArray::fromVariantList(a)).toJson((QJsonDocument::Compact))


Plugin::Plugin(QObject *parent, QWebView *webView) :
    QObject(parent)
{
    this->mainwindow = (MainWindow *) (this->parent());
    this->webView = webView;
}

QVariant Plugin::call(const QString function, QString params)
{
    QString eval_str = "if('function'==typeof(" + function + ")) " + function + "(" + params + ");";
    //qDebug() << "eval_str: " << eval_str;
    return eval(eval_str);

}


void Plugin::newData(const QByteArray &newBytes)
{
    call("PLUGIN.onNewData", "'" + newBytes.toHex() + "'");
}

void Plugin::newLine(const QByteArray &line)
{
    call("PLUGIN.onNewLine", "PLUGIN.hexUnescape('" + line.toHex() + "')");
}


//****************************
//SLOTS
//****************************
void Plugin::slotNewPacket(DecoderBase *decoder)
{
    //QVariant result = call("PLUGIN.onNewPacket", ARRAY_2_JSON(decoder->getPacketValues()));

    QStringList stringList;
        foreach(const QVariant value, decoder->getPacketValues()) stringList.append(value.toString());
    QVariant result = call("PLUGIN.onNewPacket", "[" + stringList.join(',') + "]");


    //qDebug() << "Result: " << result;
}

void Plugin::slotPortReady(int portID)
{
    QVariant result = call("PLUGIN.onPortReady", QString::number(portID));
    //qDebug() << "Result: " << result;
}


//****************************
//INVOKABLE FUNCTIONS
//****************************

void Plugin::newPacket(QString values)
{
    DecoderPlugin *decoder = (DecoderPlugin *) (this->mainwindow->getDecoder());
    decoder->pluginNewPacket(values);
}

QString Plugin::hexPack(QVariant v, QString type)
{
    char buf[4];
    char size = 0;
    if ("byte" == type)
    {
        *((unsigned char *) buf) = v.value<unsigned char>();
        size = 1;
    } else if ("sbyte" == type)
    {
        *((signed char *) buf) = v.value<signed char>();
        size = 1;
    } else if ("word" == type)
    {
        *((unsigned short *) buf) = v.value<unsigned short>();
        size = 2;
    } else if ("sword" == type)
    {
        *((unsigned short *) buf) = v.value<signed short>();
        size = 2;
    } else if ("float" == type)
    {
        *((float *) buf) = v.value<float>();
        size = 4;
    }

    QByteArray qb(buf, size);
    return qb.toHex();
}

QVariant Plugin::hexUnpack(QString hexString, QString type)
{
    char buf[4];
    QByteArray qb = QByteArray::fromHex(hexString.toLatin1());
    memcpy(buf, qb.data(), qb.size());
    QVariant v = QVariant::Invalid;
    if ("float" == type)
    {
        v = QVariant::fromValue(*((float *) (buf)));
        return v; //return float as is
    } else if ("byte" == type)
    {
        v = QVariant::fromValue(*((unsigned char *) (buf)));
    } else if ("sbyte" == type)
    {
        v = QVariant::fromValue(*((signed char *) (buf)));
    } else if ("word" == type)
    {
        v = QVariant::fromValue(*((unsigned short *) (buf)));
    } else if ("sword" == type)
    {
        v = QVariant::fromValue(*((signed short *) (buf)));
    }
    v.convert(QVariant::LongLong); //convert all integer types to higher resolution
    return v;
}

QString Plugin::hexEscape(QString string)
{


}

QString Plugin::hexUnescape(QString hexString)
{
    QByteArray qb = QByteArray::fromHex(hexString.toLatin1());
    return QString::fromLatin1(qb.data());
}

QVariant Plugin::portSend(int portID, QString string)
{
    qDebug() << "Send:" << string << "] Format: " << this->dataFormat;
    if (PortBase *port = mainwindow->getPort(portID))
    {
        if ("string" == this->dataFormat)
            port->send(string.toLatin1());
        else if ("hex" == this->dataFormat)
            port->send(QByteArray::fromHex(string.toLatin1()));
        return true;
    }
    return false;
}
