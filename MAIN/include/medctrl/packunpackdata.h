#ifndef PACKUNPACKDATA_H
#define PACKUNPACKDATA_H
#include<qstring.h>
#include<vector>
#include"../../include/medctrl_c/medctrl_c.h"
#include"../include/common/commonmethod1.h"
#include"commondefine.h"
#define MemLenCheck_SIZE(s)	if((ptrdiff_t)(pt+s-(unsigned char*)pBuf) > dwBufLen) return (0)
#define MemLenCheck_U32		if((ptrdiff_t)(pt+sizeof(uint32_t)-(unsigned char*)pBuf) > dwBufLen) return (0)
#define MemLenCheck_LEN(L)		if((ptrdiff_t)(pt+(L)-(u_int8_t*)pBuf) > dwBufLen) return (0)
#define MemLenCheck_U8          if((ptrdiff_t)(pt+sizeof(u_int8_t)-(u_int8_t*)pBuf) > dwBufLen) return (0)
#define MemLenCheck_U16         if((ptrdiff_t)(pt+sizeof(u_int16_t)-(u_int8_t*)pBuf) > dwBufLen) return (0)
#define PACK_U8(val, pt)		{memcpy(pt, &val,sizeof(u_int8_t));pt += sizeof(u_int8_t);}
#define UNPACK_U8(val, pt)		{memcpy(&val, pt, sizeof(u_int8_t));pt += sizeof(u_int8_t);}
#define PACK_U16(wVal, pt)		{u_int16_t wByteOrder = htons(wVal);memcpy(pt, &wByteOrder,sizeof(u_int16_t));pt += sizeof(u_int16_t);}
#define UNPACK_U16(wVal, pt)	{u_int16_t wByteOrder;memcpy(&wByteOrder, pt, sizeof(u_int16_t));pt += sizeof(u_int16_t);wVal = ntohs(wByteOrder);}
#define DUNPACK_U16(wVal, pt)	{u_int16_t wByteOrder;memcpy(&wByteOrder, pt, sizeof(u_int16_t));pt += sizeof(u_int16_t);wVal = wByteOrder;}
#define DUNPACK_U16HHead(wVal, pt)	{u_int16_t wByteOrder=0;u_int8_t iLow;memcpy(&iLow, pt, sizeof(u_int8_t));memcpy(&wByteOrder, pt+1, sizeof(u_int8_t));if(iLow>0xf) wByteOrder<<=8;else wByteOrder<<=4;wByteOrder+=iLow;pt += sizeof(u_int16_t);wVal = wByteOrder;}
#define STM32_VERSION_LEN 11
#define STAT_CALC_TIMES 5
#define MAX_SERIAL_DATA 540
#define STAUTS_MPOS(n) (n&0x0F)

enum
{
    EXTERN_CMD_START = 0,
    STM32_HOST_STATUS_REQ = 1,
    HOST_STM32_STATUS_ACK = 2,
    STM32_HOST_VERS_REQ = 3,
    HOST_STM32_VERS_ACK = 4,
    STM32_HOST_VERH_REQ = 5,
    HOST_STM32_VERH_ACK = 6,
    HOST_STM32_CMD_REQ = 7,
    STM32_HOST_CMD_ACK = 8,
    HOST_STM32_VERH_REQ = 9,
    STM32_HOST_VERH_ACK = 10,
    HOST_STM32_VERS_REQ = 11,
    STM32_HOST_VERS_ACK = 12,
    HOST_STM32_UPDATE_REQ = 13,
    STM32_HOST_UPDATE_ACK = 14,
    STM32_HOST_UPDATE_REQ = 15,
    HOST_STM32_UPDATE_ACK = 16,
    HOST_STM32_FILESIZE_REQ = 17,
    STM32_HOST_FILESIZE_ACK = 18,
    HOST_STM32_FILEDATA_REQ = 19,
    STM32_HOST_FILEDATA_ACK = 20,
    HOST_STM32_FILEEND_REQ = 21,
    STM32_HOST_FILEEND_ACK = 22,
    HOST_STM32_TEST_REQ = 23,
    STM32_HOST_TEST_ACK = 24,
    STM32_HOST_TESTREPORT_REQ = 25,
    HOST_STM32_TESTREPORT_ACK = 26,
    HOST_STM32_STATUS_REQ = 27,
    STM32_HOST_STATUS_ACK = 28,
    STM32_HOST_SHUTDOWN_REQ = 29,
    HOST_STM32_SHUTDOWN_ACK = 30,
    EXTERN_CMD_END = 31
};

class CSerialStatusValue
{
public:
    CSerialStatusValue()
    {
        memset(this,0,sizeof(*this));
//        newPumpState=1;
//        newSAState=1;

        //o3pumpState=1;

    }
    ~CSerialStatusValue()
    {

    }
    u_int8_t  isUpdate;
    //write
    u_int8_t  m_iSetPWM1;
    u_int8_t  m_iSetPWM2;
    u_int8_t  m_iSetJ25;
    u_int8_t  inbValue;//0-100
    u_int8_t  ledState;
    u_int8_t  powerState;
    u_int8_t  newPumpState;
    u_int8_t  newSAState;
    u_int8_t  newSBState;
    u_int8_t  newRAState;
    u_int8_t  newRBState;
    u_int8_t  o3pumpState;
    u_int8_t  o3State;
    u_int8_t  powerFanSpeed;
    //read(this is raw)
    u_int8_t       version;
    u_int16_t      ch1voltage;//pt100 2018/05/14
    u_int16_t      boxtempture;
    u_int16_t      ch1currency;//qingqiadc 2018/05/14
    u_int16_t      inbtempture;
    u_int16_t      smaplecurrency;
    u_int16_t      hydrogenthickness;//B lu pt100 2018/05/14 //beiyong20190128
    u_int8_t       m_iRestore;//beiyong
    u_int16_t      m_iPWM1Speed;
    u_int8_t       m_iRestore2;
    u_int16_t      m_iPWM2Speed;
    u_int8_t       m_iWuHuaLevel;
    u_int8_t       m_iShiHuaLevel;
    u_int8_t       m_iZhuShuiKou;
    u_int8_t       m_iQingShuiBeiLevel;
    u_int8_t       hydrogenlow;//
    u_int8_t       hydrogenhigh;
    u_int8_t       powerGnd;
    u_int8_t       boxOnline;
    u_int8_t       inbCupLow;
    u_int8_t       inbCupHigh;
    u_int8_t       fanState;
    u_int16_t      fanSpeed;
    //convert to this
    u_int8_t     calc_times;
    float        f_currentWaterTempture[STAT_CALC_TIMES];
    float        f_currentInBreathTempture[STAT_CALC_TIMES];
    float        f_currentCH1Voltage[STAT_CALC_TIMES];//pt100
    float        f_currentCH1I[STAT_CALC_TIMES];
    u_int16_t    f_hydrogenthickness[STAT_CALC_TIMES];
    float        f_sampleCurrentI[STAT_CALC_TIMES];
    float        user_currentWaterTempture;
    float        user_currentInBreathTempture;
    float        user_currentCH1Voltage;
    float        user_currentCH1I;
    float        user_sampleCurrentI;
    float        user_hydrogenthickness;
    //this is for version update
    u_int8_t     stm32_version[STM32_VERSION_LEN+1];
    u_int8_t     stm32_hard_version[STM32_VERSION_LEN+1];
};

typedef struct tagCMsgEvent
{
    u_int8_t  event;
    u_int16_t eventLen;
    u_int8_t* eventContent;
    u_int8_t  eventAck;
}TCMsgEvent;
typedef struct tagCMsgHeader
{
    u_int8_t  syncCode;
    u_int8_t  srcAddr;
    u_int8_t  dstAddr;
    u_int16_t msgLen;
    TCMsgEvent msgEvent;
    u_int8_t  msgCrc;
    u_int8_t  endCode;
}TCMsgHeader;
class CPackUnPackData
{
public:
    CPackUnPackData();
    static int PackRegisterUserMobileUrl(const QString& sName,const QString& sTelNum,const QString& sZone,QString& sOut);
    static int ParseRegisterUserMobileResp(const QString& sIn,QString& userCheckCode,int& CheckCodeTimeOut);
    static int ParseRemoteUsers(const QString sIn,std::vector<TMedUser>& vUsers,std::vector<TMedUser>& vTodelUsers);
    static int PackLocalUsers(const std::vector<TMedUser>& vUsers,std::string& sOut);
    static int PackLog(const int& type,const TMedLog& tLog,const TDevice& tDevice,std::string& sOut);
    static int PackUserStatic(const TMedUserStatis& tStatis,const TDevice& tDevice,const std::string name,std::string& sOut);
    static ptrdiff_t Pack_TCtrlHeader(const TCtrlHeader *ptTHeader, uint32_t dwBufLen,void* pBuf );
    static ptrdiff_t Pack_TDebugHeader(TDebugHeader *ptTHeader, uint32_t dwBufLen,void* pBuf );
    static ptrdiff_t UnPack_TDebugHeader(const void *pBuf,uint32_t dwBufLen,TDebugHeader *ptTHeader);
    static ptrdiff_t Pack_TDataHeader(TDataHeader *ptTHeader, uint32_t dwBufLen,void* pBuf );
    static void Msg_TCtrleader(void *pBuf,int Msg);
    static ptrdiff_t UnPack_TCtrlHeader(const void *pBuf,uint32_t dwBufLen,TCtrlHeader *ptTHeader);
    static ptrdiff_t UnPack_TDataHeader(const void *pBuf,uint32_t dwBufLen,TDataHeader *ptTHeader);
    static int ParseemMsg_SetAlias_Cmd(const std::string& sIn,std::string& sOut);
    static int PackemMsg_Search_ID(const TDevice& tDev,const TEthParam& tEth,std::string& sOut);
    static int ParserRegUrl(const std::string& buf,QString& sUrl,int& iPort,QString& sAppUrl);
    static int ParserVerInfo(const std::string& buf,QString& url,QString& FileName);
    static int PackUserList(const std::vector<TMedUser>& vUsers,std::string& sOut);
    static int PackStatusValue(CSerialStatusValue* ptStatus,u_int32_t dwBufLen,void* pBuf);
    static int PackStatusValueA8(CSerialStatusValue* ptStatus,u_int32_t dwBufLen,void* pBuf);
    static int UnpackTCMsgEvent(const void *pBuf,u_int32_t dwBufLen,TCMsgHeader *ptMsg);
    static int UnpackStatusValue(const void *pBuf,u_int32_t dwBufLen,CSerialStatusValue* ptStatus);
    static int UnpackStatusValueA8(const void *pBuf,u_int32_t dwBufLen,CSerialStatusValue* ptStatus);
    static int PackTCMsgEvent(TCMsgHeader *ptMsg,u_int32_t dwBufLen,void* pBuf);
    static void TCMsgHeader_Init(TCMsgHeader* ptHeader);
    static void TCMsgEvent_Clear(TCMsgEvent* ptMsg);
    static void TCMsgEvent_Init(TCMsgEvent* ptMsg,u_int8_t e,u_int16_t le,u_int8_t* buf,u_int8_t ack);
};

#endif // PACKUNPACKDATA_H
