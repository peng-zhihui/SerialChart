#ifndef HIDDEVICE_H
#define HIDDEVICE_H


#include <windows.h>
#include <setupapi.h>
#include <QString>

#ifdef UNICODE
typedef LPCWSTR PCTSTR;
#else
typedef LPCSTR PCTSTR;
#endif


class HidDevice
{
public:
    HidDevice();
    bool connect(const QString& DeviceID);
    bool disconnect();
    bool read(unsigned char inEndpointNum,QByteArray& readData);

private:
    bool isConnected;
    unsigned int packetSize;
    HANDLE WriteHandle ;	//Need to get a write "handle" to our device before we can write to it.
    HANDLE ReadHandle ; 	//Need to get a read "handle" to our device before we can read from it.
};

#endif // HIDDEVICE_H
