#ifndef MEDCTRL_C_COMMON_H
#define MEDCTRL_C_COMMON_H
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdio.h>
#include <sys/timeb.h> 
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <direct.h>
#include <WinSock2.h>
#include <Windows.h>
#define snprintf _snprintf
#define TASKHANDLE			 HANDLE
#define SEMHANDLE			 HANDLE
#define SOCKHANDLE			 SOCKET
#define SockClose			 closesocket
#define ioctl ioctlsocket
#define ERRNOGET GetLastError()
#define EWOULDBLOCK             WSAEWOULDBLOCK
#else
#include <pthread.h>
#include <stdint.h>
#include <malloc.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/times.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <linux/serial.h>
#include <dirent.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#define TASKHANDLE			 pthread_t
#define SEMHANDLE			 pthread_cond_t*
#define SOCKHANDLE			 int
#define INVALID_SOCKET		 (-1)
#define SockClose			 close
#define SOCKET_ERROR		  (-1)
#define ERRNOGET			 errno
#endif
#ifndef NULL
#define NULL	((void *)0)
#endif
#define DEF_SQLPATH    "/var/lib/medctrl/aspi.dat"
#define LOG_SQLPATH    "/var/lib/medctrl/operate.dat"
#define DEF_WIFIPATH   "/var/lib/wifi.conf"
#define CURRENT_ISSUE  "/var/lib/medctrl/issue"
#if defined(__linux__)
typedef struct
{
	pthread_cond_t m_tCond;
	pthread_mutex_t m_tMutex;
    unsigned long m_dwCurrentCount;
	unsigned long m_dwMaxCount;
}TSemCond;
#include <termios.h>
#include <fcntl.h>
#include <linux/serial.h>
#include <sys/timeb.h>
#include <stdio.h>
#include <sys/ioctl.h>
#endif
enum
{
    VALUE_MODEL_NAME,
    VALUE_FRIRM_VER,
    VALUE_SERIAL_NUM,
    VALUE_OUT_VALTAGE,
    VALUE_OUT_CURRENCY,
    VALUE_SET_CURRENCY,
    VALUE_CURRENT_STATUS,
    VALUE_SET_CURRENT_CURRENCY
};
enum
{
    ERROR_POWER_NONE = 0,
    ERROR_POWER_FAN2,
    ERROR_POWER_FAN1,
    ERROR_POWER_OCP,
    ERROR_POWER_UVP,
    ERROR_POWER_OVP,
    ERROR_POWER_OTP,
    ERROR_POWER_GND
};

typedef struct tagPowerCtrl
{
    int   fd;
    uint16_t addr;
    void*  private_data;
    void* (*Init)(char* name);
    void  (*Exit)(void* ptCtrl);
    int   (*PollStatus)(void* ptCtrl,int num);
    int   (*Get)(void* ptCtrl,int ctrlFlags,void* szValue,int len);
    void  (*Read)(void* ptCtrl,int ctrlFlags,int* values);
    void  (*Write)(void* ptCtrl,int ctrlFlags,float values);
}TPowerCtrl;
void* InitI2CCtrl(char* name);
void* InitSPICtrl(char* name);

typedef struct tagSerialCtrl
{
    int    fd_r;
    int    fd_w;
    void*  private_data;
    void* (*Init)(char* name);
    void  (*Exit)(void* ptCtrl);
    void  (*Set)(void* ptCtrl,int ctrlFlags,int nVal);
    int   (*Get)(void* ptCtrl,int ctrlFlags);
    float (*GetF)(void* ptCtrl,int ctrlFlags);
    int   (*Version)(void* ptCtrl,int ctrlFlags,char* buf,int inSize);
    void  (*Read)(void* ptCtrl);
    void  (*Write)(void* ptCtrl);
    void  (*Update)(void* ptCtrl);
    void  (*Print)(void* ptCtrl);
}TSerialCtrl;
void* A12_Init(char* name);
void* A4_Init(char* name);
void* A2_Init(char* name);

int medctrlFileExist(const char *strDirPath);
int ctrlSemGive(SEMHANDLE hSema);
int ctrlSemTakeByTime(SEMHANDLE hSema, unsigned long dwTimeout);
int ctrlSemDelete(SEMHANDLE hSema);
int ctrlSemCreate(SEMHANDLE *phSema);
void ctrlDelay(long dwMs);
size_t msTimeGet();
size_t monotonic_time_second();
void serialSetWriteState(int nState);
void serialSetWriteStateDebug(int nState);
char *random_device_uuid(char* buf);
typedef void *(*LINUXFUNC)(void *);

TASKHANDLE deviceTaskCreate(LINUXFUNC pvTaskEntry,
                             char *szName,
                             unsigned char byPriority,
                             unsigned dwStacksize,
                             void* pThreadParam,
                             unsigned short wFlag,
                             size_t *pdwTaskID);
unsigned long ctrlMsgFifoRead(void* hMsgFifo,unsigned char *pbyBuf,unsigned long bufLen,long dwTimeout,long *pdwRealLen);
unsigned long ctrlMsgWrite(void* hMsgFifo, unsigned char *pbyBuf, unsigned long dwBufLen);
int   ctrlMsgDelete(void* hHandle);
int   ctrlMsgReset(void* hHandle);
void* ctrlMsgCreate(unsigned long dwFifoSize);
void  addLogTable(char* fmt,...);
void  addjustLogTable();

#define BOOTP_BROADCAST 0x8000
#define DHCP_REQUEST        1
#define DHCP_REPLY          2
#define DHCP_HTYPE_ETHERNET 1
#define DHCP_HLEN_ETHERNET  6
#define DHCP_MSG_LEN      236

#define DHCPC_SERVER_PORT  67
#define DHCPC_CLIENT_PORT  68

#define DHCPDISCOVER  1
#define DHCPOFFER     2
#define DHCPREQUEST   3
#define DHCPDECLINE   4
#define DHCPACK       5
#define DHCPNAK       6
#define DHCPRELEASE   7

#define DHCP_OPTION_SUBNET_MASK   1
#define DHCP_OPTION_ROUTER        3
#define DHCP_OPTION_DNS_SERVER    6
#define DHCP_OPTION_REQ_IPADDR   50
#define DHCP_OPTION_LEASE_TIME   51
#define DHCP_OPTION_MSG_TYPE     53
#define DHCP_OPTION_SERVER_ID    54
#define DHCP_OPTION_REQ_LIST     55
#define DHCP_RENEWTIME			  58
#define DHCP_REBINDING			  59
#define DHCP_OPTION_END          255

#ifdef __cplusplus
};
#endif
#endif
