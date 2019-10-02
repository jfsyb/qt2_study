#ifndef COMMONMETHOD1_H
#define COMMONMETHOD1_H
#include<stdint.h>
#include<string>
#include "commonmethod1_global.h"
typedef struct
{
  quint32 protocaltype;
  quint32 protocalid;
  quint32 protocalidd;
  quint32 protocal_msglen;
}TCtrlHeader;
typedef struct
{
    uint32_t dwMagic;
    uint32_t dwCreateTime;
    uint32_t dwFileNum;
    uint32_t dwTotalLen;
}TVersionHeader;
#define PACK_U32(dwHost, pt)		{uint32_t dwNet = htonl(dwHost);memcpy(pt, &dwNet,sizeof(uint32_t));pt += sizeof(uint32_t);}
#define UNPACK_U32(dwHost, pt)		{uint32_t dwNet;memcpy(&dwNet, pt, sizeof(uint32_t));pt += sizeof(uint32_t);dwHost = ntohl(dwNet);}
#define VERSION_STR_MED "3.1.0"
class QStringList;
class COMMONMETHOD1SHARED_EXPORT CommonMethod1
{

public:
    CommonMethod1();
    ptrdiff_t UnPack_TCtrlHeader(const void *pBuf,uint32_t dwBufLen,TCtrlHeader *ptTHeader);
    static void GetCurrentVersion(QString& sOut);
    static bool UpdateFileIsOk(const std::string& sFileName);
    static ptrdiff_t UnPack_TVersionHeader(const void *pBuf,  uint32_t dwBufLen, TVersionHeader *ptTVersionHeader );
    static void GetSystemCmdResult(const std::string& sIn,std::string& sSout);
    static int GetFileData(const std::string& sPath,std::string& sOut);
    static int WriteFileData(const std::string& sPath,const std::string& sIn);
    static std::string ByteToHexStr(unsigned char* byte_arr, int arr_len);
    static void DecodeLicense(QString suuID,QString sIn,tm& licenseDate);
    static void EncodeLicense(QString suuID,QString slicenseDate,QString& sPassword);
    static bool CheckLicense(QString suuID,QString sIn,int& iRemainDay);
    static void writeLicense(QString sPath,QString license);
    static int AddWriteFileData(const std::string& sPath,const std::string& sIn);
    static std::string FindPID(QString sIn);
    static void RebootWifi(bool bRemoveConfFile=false);
    static std::string GetMacAddr();
    static u_int16_t Crc16(u_int8_t *puchMsg, u_int16_t usDataLen);
    static u_int16_t HighToLow(u_int16_t uiIn);
    static int GetVarSpace(std::string spath="/var");
    static void GetDirFiles(QStringList& string_list,std::string sPath="/var/logbak/",std::string sFilter="*.tar.gz");
    static int GetUpdateFlag();
    static void WriteUpdateFlagStep2();
    static void WriteUpdateFlagStep3();
    static QString decodeBase64(char *code);
};

#endif // COMMONMETHOD1_H
