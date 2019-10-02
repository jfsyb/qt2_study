#ifndef HARDWAREDEVICE_H
#define HARDWAREDEVICE_H
#include<string>
#include <QSocketNotifier>
#include "hardwaredevice_global.h"

class HARDWAREDEVICESHARED_EXPORT CHardWareDevice
{

public:
    CHardWareDevice();
    ~CHardWareDevice();
    int32_t OpenBlueTooth();
    int32_t CloseBlueTooth();
    //brief:change bluetooth role
    //param:
    //[in] iValue:1 is master,0 is slave,default is 0
    //[out] n.a
    //return:
    // 0 is ok,1 is not ok.
    int32_t ChangeBlueToothRoles(int iValue=0);
    //brief:change bluetooth name
    //param:
    //[in] sName:bluetooth's name
    //[out] n.a
    //return:
    // 0 is ok,1 is not ok.
    int32_t ChangeBlueToothName(std::string sName);
    //brief:Send Data to other
    //param:
    //[in] iAddr:address
    //[in] sValue:value
    //[out] n.a
    //return:
    // 0 is ok,1 is not ok.
    int32_t BlueToothSendData(int32_t iAddr,std::string sValue);
    //brief:Send Data to other
    //param:
    //[in] iAddr:address
    //[out] sValue:value
    //return:
    // 0 is ok,1 is not ok.
    int32_t BlueToothRecData(int32_t iAddr,std::string& sValue);
    //brief:Is BlueTooth open
    //param:
    //[in] n.a
    //[out] n.a
    //return:
    // true is open
    bool bIsBlueToothOpen();
    static int I2CReadPowerStatus(int fd,int addr);
    static int I2CReadFirmwareVersion(int fd,int addr,char* pOut,int ipOutLen);
    static int I2CReadSerialNum(int fd,int addr,char* pOut,int ipOutLen);
    static float I2CReadTemperature(int fd,int addr);
    static int I2CWritePowerValue(int fd,int addr,float powerValue);
    static float I2CReadOutputCurrent(int fd,int addr);
    static float I2CReadOutputVoltage(int fd,int addr);
private:
    int openttyBluz(char* name);
    int serialWrite(int hCom, char *pchBuf, long dwBytesToWrite, long *pdwBytesWrite);
private:
    int m_fd;
    bool m_bBlueToothIsOpened;
//    QSocketNotifier *msgNotifier;


};

#endif // HARDWAREDEVICE_H
