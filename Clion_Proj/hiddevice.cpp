#include "hiddevice.h"

//Inspired from Microchip Application Libraries sample code, see for example:
//C:\microchip\mla\v2013-06-15\USB\Device - HID - Custom Demos\Simple Demo - Windows Software\Microsoft Visual C++ 2005 Express\Form1.h

HidDevice::HidDevice()
{
    WriteHandle = INVALID_HANDLE_VALUE;
    ReadHandle = INVALID_HANDLE_VALUE;
    isConnected = false;
}

bool HidDevice::connect(const QString& DeviceID)   //example DeviceID: "Vid_04d8&Pid_003F"
{
    WriteHandle = INVALID_HANDLE_VALUE;
    ReadHandle = INVALID_HANDLE_VALUE;


    /*
            Before we can "connect" our application to our USB embedded device, we must first find the device.
            A USB bus can have many devices simultaneously connected, so somehow we have to find our device, and only
            our device.  This is done with the Vendor ID (VID) and Product ID (PID).  Each USB product line should have
            a unique combination of VID and PID.

            Microsoft has created a number of functions which are useful for finding plug and play devices.  Documentation
            for each function used can be found in the MSDN library.  We will be using the following functions:

            SetupDiGetClassDevs()					//provided by setupapi.dll, which comes with Windows
            SetupDiEnumDeviceInterfaces()			//provided by setupapi.dll, which comes with Windows
            GetLastError()							//provided by kernel32.dll, which comes with Windows
            SetupDiDestroyDeviceInfoList()			//provided by setupapi.dll, which comes with Windows
            SetupDiGetDeviceInterfaceDetail()		//provided by setupapi.dll, which comes with Windows
            SetupDiGetDeviceRegistryProperty()		//provided by setupapi.dll, which comes with Windows
            malloc()								//part of C runtime library, msvcrt.dll?
            CreateFile()							//provided by kernel32.dll, which comes with Windows

            We will also be using the following unusual data types and structures.  Documentation can also be found in
            the MSDN library:

            PSP_DEVICE_INTERFACE_DATA
            PSP_DEVICE_INTERFACE_DETAIL_DATA
            SP_DEVINFO_DATA
            HDEVINFO
            HANDLE
            GUID

            The ultimate objective of the following code is to call CreateFile(), which opens a communications
            pipe to a specific device (such as a HID class USB device endpoint).  CreateFile() returns a "handle"
            which is needed later when calling ReadFile() or WriteFile().  These functions are used to actually
            send and receive application related data to/from the USB peripheral device.

            However, in order to call CreateFile(), we first need to get the device path for the USB device
            with the correct VID and PID.  Getting the device path is a multi-step round about process, which
            requires calling several of the SetupDixxx() functions provided by setupapi.dll.
    */


    //Globally Unique Identifier (GUID) for HID class devices.  Windows uses GUIDs to identify things.
    GUID InterfaceClassGuid = { 0x4d1e55b2, 0xf16f, 0x11cf, 0x88, 0xcb, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30};

    HDEVINFO DeviceInfoTable = INVALID_HANDLE_VALUE;
    PSP_DEVICE_INTERFACE_DATA InterfaceDataStructure = new SP_DEVICE_INTERFACE_DATA;
    PSP_DEVICE_INTERFACE_DETAIL_DATA DetailedInterfaceDataStructure = new SP_DEVICE_INTERFACE_DETAIL_DATA;
    SP_DEVINFO_DATA DevInfoData;

    DWORD InterfaceIndex = 0;
    DWORD dwRegType;
    DWORD dwRegSize;
    DWORD StructureSize = 0;

    bool success = false;


    //First populate a list of plugged in devices (by specifying "DIGCF_PRESENT"), which are of the specified class GUID.
    DeviceInfoTable = SetupDiGetClassDevs(&InterfaceClassGuid, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);

    //Now look through the list we just populated.  We are trying to see if any of them match our device.
    while(true)
    {
            InterfaceDataStructure->cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
            SetupDiEnumDeviceInterfaces(DeviceInfoTable, NULL, &InterfaceClassGuid, InterfaceIndex, InterfaceDataStructure);
            //ErrorStatus = GetLastError();
            if(ERROR_NO_MORE_ITEMS == GetLastError())	//Did we reach the end of the list of matching devices in the DeviceInfoTable?
            {	//Cound not find the device.  Must not have been attached.
                    SetupDiDestroyDeviceInfoList(DeviceInfoTable);	//Clean up the old structure we no longer need.
                    return false;
            }

            //Now retrieve the hardware ID from the registry.  The hardware ID contains the VID and PID, which we will then
            //check to see if it is the correct device or not.

            //Initialize an appropriate SP_DEVINFO_DATA structure.  We need this structure for SetupDiGetDeviceRegistryProperty().
            DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
            SetupDiEnumDeviceInfo(DeviceInfoTable, InterfaceIndex, &DevInfoData);

            //First query for the size of the hardware ID, so we can know how big a buffer to allocate for the data.
            SetupDiGetDeviceRegistryProperty(DeviceInfoTable, &DevInfoData, SPDRP_HARDWAREID, &dwRegType, NULL, 0, &dwRegSize);

            //Allocate a buffer for the hardware ID.
            QByteArray byteArrayBuffer(dwRegSize, 0);
            //Retrieve the hardware IDs for the current device we are looking at.  PropertyValueBuffer gets filled with a
            //REG_MULTI_SZ (array of null terminated strings).  To find a device, we only care about the very first string in the
            //buffer, which will be the "device ID".  The device ID is a string which contains the VID and PID, in the example
            //format "Vid_04d8&Pid_003f".
            QString DeviceIDFromRegistry = "";

            if(SetupDiGetDeviceRegistryProperty(DeviceInfoTable, &DevInfoData, SPDRP_HARDWAREID, &dwRegType, (BYTE*)(byteArrayBuffer.data()), dwRegSize, NULL)){
                DeviceIDFromRegistry = QString((const QChar*)(byteArrayBuffer.constData()), byteArrayBuffer.size() / 2 - 1).toLower();
                //qDebug(DeviceIDFromRegistry.toAscii());
            }

            //Now check if the hardware ID we are looking at contains the correct VID/PID
            if(DeviceIDFromRegistry.contains(DeviceID.toLower()))
            {
                    //Device must have been found.  Open read and write handles.  In order to do this, we will need the actual device path first.
                    //We can get the path by calling SetupDiGetDeviceInterfaceDetail(), however, we have to call this function twice:  The first
                    //time to get the size of the required structure/buffer to hold the detailed interface data, then a second time to actually
                    //get the structure (after we have allocated enough memory for the structure.)
                    DetailedInterfaceDataStructure->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

                    //First call populates "StructureSize" with the correct value
                    SetupDiGetDeviceInterfaceDetail(DeviceInfoTable, InterfaceDataStructure, NULL, NULL, &StructureSize, NULL);
                    DetailedInterfaceDataStructure = (PSP_DEVICE_INTERFACE_DETAIL_DATA)(malloc(StructureSize));		//Allocate enough memory
                    if(DetailedInterfaceDataStructure == NULL)	//if null, error, couldn't allocate enough memory
                    {	//Can't really recover from this situation, just exit instead.
                            SetupDiDestroyDeviceInfoList(DeviceInfoTable);	//Clean up the old structure we no longer need.
                            return false;
                    }
                    DetailedInterfaceDataStructure->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
                     //Now call SetupDiGetDeviceInterfaceDetail() a second time to receive the goods.
                    SetupDiGetDeviceInterfaceDetail(DeviceInfoTable, InterfaceDataStructure, DetailedInterfaceDataStructure, StructureSize, NULL, NULL);

                    //We now have the proper device path, and we can finally open read and write handles to the device.
                    //We store the handles in the global variables "WriteHandle" and "ReadHandle", which we will use later to actually communicate.
                    WriteHandle = CreateFile((DetailedInterfaceDataStructure->DevicePath), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
                    if(GetLastError() == ERROR_SUCCESS){
                        ReadHandle = CreateFile((DetailedInterfaceDataStructure->DevicePath), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, 0);
                        if(GetLastError() == ERROR_SUCCESS){
                            success = true;
                            qDebug("HID Connect OK");
                        }
                    }
                    SetupDiDestroyDeviceInfoList(DeviceInfoTable);	//Clean up the old structure we no longer need.
                    return success;
            }

            InterfaceIndex++;
            //Keep looping until we either find a device with matching VID and PID, or until we run out of items.
    }//end of while(true)

    return false;
}

bool HidDevice::disconnect(){
    return true;
}

bool HidDevice::read(unsigned char reportID, QByteArray& readData){
    //readData buffer must have size equal to our endpoint size + 1 for reportID
    DWORD BytesRead = 0;
    //The first byte is the "Report ID"
    readData[0] = reportID;
    //Now get the response packet from the firmware.
    //The following call to ReadFile() retrieves packetsize bytes of data from the USB device.
    //Blocking function, unless an "overlapped" structure is used
    ReadFile(ReadHandle, (BYTE*)(readData.data()), readData.size() , &BytesRead, 0);

    /*
    //following is used for debug
    QString str = "HID READ["+ QString::number(BytesRead)+"]:";
    for(unsigned int i=1;i<=readData.size()-1;i++){
        str += QString::number(readData[i])+",";
    }
    qDebug(str.toAscii());
    */

    return true;
}


