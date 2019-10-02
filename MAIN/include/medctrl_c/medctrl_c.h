#ifndef MED_CTRL_C_H
#define MED_CTRL_C_H
#include <time.h>
#include <stdint.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include<string.h>
#ifdef __cplusplus
extern "C"
{
#endif
#define MAX_STR_16LEN 16
#define MAX_STR_32LEN 32
#define MAX_STR_255LEN 255

#define REMAINING_SPACE         (5) //5M

enum
{
	GPIO_IN,
	GPIO_OUT,
	SERAIL_IN,
    SERAIL_OUT
};

enum
{
    WATER_LVL_NORMAL,
    WATER_LVL_LOW,
    WATER_LVL_HIGH
};

enum
{
    BOX_WATER_LVL_LOW_VALUE = 0,
    BOX_WATER_LVL_HIGH_VALUE = 0
};

enum
{
    LANGUAGE_CHINESE_SIMPLE,//0
    LANGUAGE_CHINESE_TAIWAN,//1
    LANGUAGE_ENGLISH, //2
    LANGUAGE_JAPANESE,//3
    LANGUAGE_UNKNOW
};

enum
{
    DEV_WIFI_ENABLED = 0,
    DEV_BT_ENABLED,
    DEV_BOXT_OLD,
    DEV_INBT_OLD,
    DEV_POWER_OLD,
    DEV_STM32_OLD,
    DEV_HCUPCHECK_ON,
    DEV_ICUPCHECK_ON,
    DEV_WIZARD_ON,
    DEV_TELE_CHECK_ON,
    DEV_INB_WARN_STOP,
    DEV_FACTORY_CHECK_ON,
    DEV_FACTORY_ENGINEER_ON,
    DEV_WORKMODE_ON,
    DEV_INB_INV_ON, //start 3second/5minute
    DEV_ADDWATER_HIGH_TEMP,
    DEV_POSION_CLEAN_ENABLED,
    DEV_GND_STATUS_ENABLED,
    DEV_NET_STATUS_ENABLED,
    DEV_SILENCE_MODE_OFF
};

typedef struct
{
    char     device_uuid[MAX_STR_32LEN+1];
    char     device_soft_version[MAX_STR_16LEN+1];
    char     device_hard_version[MAX_STR_16LEN+1];
    char     device_netpass[MAX_STR_32LEN+1];
    char     device_alias[MAX_STR_32LEN+1];
    //std::string sLicense;
    char     device_mac[MAX_STR_16LEN+1]; //not saved
    uint32_t dev_work_duration; //total duration
    uint32_t dev_work_hydrogen; //total hydrogen
    uint32_t dev_check_duration; //for last maintains
    uint32_t dev_startup_time; //from last startup(seconds from 1970)
    uint32_t dev_work_mode; //0--family 1--business
    int32_t  time_zone;
    uint32_t language;
    uint32_t accpet;
    uint32_t r1;//save capability
}TDevice;
//读取基本配置
int deviceReadConfigDevice(TDevice* tDevice);
//更新基本配置
int deviceWriteConfigDevice(TDevice* tDevice);

typedef struct
{
    uint32_t  ntpenabled;
    char ntp_svr_ip[MAX_STR_255LEN+1];
    uint32_t  ntp_svr_port;
    uint32_t  net_ver_enabled;
    char net_ver_ip[MAX_STR_255LEN+1];
    uint32_t  net_ver_port;
    uint32_t  net_rcv_enabled;
    char net_rcv_url[MAX_STR_255LEN+1];
    uint32_t  net_rcv_port;
    uint32_t  net_rcv_type;
    uint32_t  net_snd_enabled;
    char net_snd_url[MAX_STR_255LEN+1];
    uint32_t  net_snd_port;
    uint32_t  net_snd_type;
}TDeviceNet;
//初始化网络配置
int deviceConfigAddDeviceNet(TDeviceNet* ptDevice);
//读取基本网络配置
int deviceReadConfigDeviceNet(TDeviceNet* tDeviceNet);
//更新基本网络配置
int deviceWriteConfigDeviceNet(TDeviceNet* tDeviceNet);
enum
{
    WIRELESS_WIFI,
    WIRE_ETH,
    WIRELESS_BLUET
};

typedef struct
{
    uint32_t  net_id;
    uint32_t  net_type;
    uint32_t  is_default;
    char      wifi_name[MAX_STR_32LEN+1];
    char      wifi_pass[MAX_STR_32LEN+1];
}TDeviceNetWork;
int deviceConfigAddBT(char* name,char* pass);
int deviceConfigReadBTBySSID(char* name,TDeviceNetWork* ptWifi);
int deviceConfigReadBT(TDeviceNetWork* ptWifi);

uint32_t deviceDefaultCapability();
//调试使能
void deviceDebugInit(unsigned short port);
//调试退出
void deviceDebugExit();
//调试信息输出
void deviceDebug(int loglvl,const char* fmt,...);
//调试命令注册
void deviceCmdReg(char* cmdName,void* func,char* comment);

//创建配置文件
int deviceConfigInit();
//获取配置
int deviceGetConfigDevice(TDevice* ptDevice);
//获取网络配置
int deviceGetConfigDeviceNet(TDeviceNet* ptDevice);
enum
{
    EM_AUDIO_TYPE_TOUCH,    
    EM_AUDIO_TYPE_ADDWATER,
    EM_AUDIO_TYPE_ADDOFF,
    EM_AUDIO_TYPE_ADDWATER_US,
    EM_AUDIO_TYPE_ADDOFF_US,
    EM_AUDIO_TYPE_ADDWATER_JP,
    EM_AUDIO_TYPE_ADDOFF_JP,
    EM_AUDIO_TYPE_SHUTDOWN,    
    EM_AUDIO_TYPE_WARNING,
    EM_AUDIO_TYPE_STOP,
    EM_AUDIO_TYPE_MAX
};
int deviceWriteDeviceUUID(TDevice* tDevice);

//初始化
enum
{
    MACHINE_TYPE_7INCH,//0
    MACHINE_TYPE_4INCH,//1
    MACHINE_TYPE_5INCH_H,//2
    MACHINE_TYPE_5INCH_V,//3
    MACHINE_TYPE_12INCH,//4
    MACHINE_TYPE_CLIENT
};
void MedCtrSysInit();
//系统退出
void MedCtrSysExit();

//设置当前氢气值
enum
{
    emHyDrogen_LOW,
    emHyDrogen_MID,
    emHyDrogen_HIGH
};
float deviceGetConfigPowerValue(int size);

enum
{
	emWork_Family,
    emWork_NonFamily
};

enum
{
    emErrors_No_Error = 0,
    emErrors_MainTaince_Must,
    emErrors_No_LeaseInfo,//没有租赁信息 20
    emErrors_Cup_NotPresent, //水杯不在
    emErrors_Fan_Error, //风扇错误
    emErrors_Water_Level_Error, // water level error
    emErrors_Water_Need_But_Tempture_High, //电解箱需要加水温度高
    emErrors_Hydrogen_Tempture_High,//电解箱温度高
    emErrors_Tank_TimeOut,//电解箱自动补水
    emErrors_Inb_Tempture_Error,//雾化温度异常
    emErrors_Hydrogen_Tempture_Error,//电解箱温度异常
    emErrors_Hydrogen_WaterLow, //电解箱水位低
    emErrors_Inb_Tempture_High,
    emErrors_Inb_Water_Low,
    emErrors_Inb_Water_High,
    emErrors_Power_Tempture_High,//电源温度高
    emErrors_Power_OTP,//电源温度高
    emErrors_Power_OVP,
    emErrors_Power_OCP,
    emErrors_Power_UVP,
    emErrors_Power_GND,
    emErrors_Box_Over_Temperature_Force_Down,//wen du chuan gan qi kai lu
    emErrors_Box_OnLine,//电解箱
    emErrors_Stir_Water,//电解箱搅拌中
    emErrors_Cup_WaterLow, //湿滑杯低水
    emErrors_Cup_WaterHigh, //湿滑杯低水

    emErrors_QingShuiBeiLow,//qingshuibeidi
//    emErrors_Serial_Errors,//串口失败
    emErrors_HCup_NOT_Exist,//qingshuibeishifouzai
    emErrors_MiddleAddWater_TimeOut_EndWith_Low,
    emErrors_MiddleAddWater_TimeOut_EndWith_Middle,
    emErrors_AllAddWater_TimeOut,
    emErrors_I2C_Communite_Failed,
    emErrors_MAX_Ntf//
};

enum
{
    emUser_State_Reported = 0x01,
    emUser_State_Delete   = 0x02,
    emUser_State_Modefied = 0x04
};

typedef struct MedUser
{
    uint32_t  userid;
    char      username[MAX_STR_32LEN+1];
    char      userpass[MAX_STR_32LEN+1];
    char      user_tel[MAX_STR_16LEN+1];
    char      birthdate[MAX_STR_16LEN+1];
    char      med_record[MAX_STR_32LEN+1];
    uint32_t  user_illness;
    uint32_t  user_gender;
    uint32_t  user_net_id;
    uint32_t  user_hydrogenvalue;
    uint32_t  user_inbreathevalue;
    char      user_custom_picpath[MAX_STR_255LEN+1];
//    MedUser()
//    {
//        userid=0;
//        memset(username,0,sizeof(username));
//        memset(userpass,0,sizeof(userpass));
//        memset(user_tel,0,sizeof(user_tel));
//        memset(birthdate,0,sizeof(birthdate));
//        memset(med_record,0,sizeof(med_record));
//        user_illness=0;
//        user_gender=0;
//        user_net_id=0;
//        user_hydrogenvalue=0;
//        user_inbreathevalue=0;
//        memset(user_custom_picpath,0,sizeof(user_custom_picpath));
//    }
}TMedUser;

int deviceConfigReadUserPageSize(int sizePerPage);
int deviceConfigReadUsers(int refUserId,TMedUser* tUser,int inSize,int* outSize);
int deviceConfigReadUsersNotSync(int refUserId,TMedUser* tUser,int inSize,int* outSize);
int deviceConfigUpdateUsersSync();
int deviceConfigReadUser(int UserId,TMedUser* ptUser);
int deviceConfigFindUsers(char* exp,int refUserId,TMedUser* tUser,int inSize,int* outSize);
int deviceConfigReadUserFrom(int refUserId,int minus,TMedUser* tUser,int inSize,int* outSize);
int deviceConfigAddUser(TMedUser* tUser,int* outUserId);
int deviceConfigAddUserNet(TMedUser* tUser);
int deviceConfigReadUserId(char* userName);
int deviceConfigSyncAddUser(TMedUser* tUser);
int deviceConfigWriteUser(TMedUser* tUser);
int deviceConfigRemoveUser(char* userName);
int deviceConfigRemoveUserID(int userID);
int deviceConfigReadUserFromId(int flag, int startId,  int inSize, TMedUser *ptUser, int *row);
int deviceConfigReadFirstUser(TMedUser *tUser);

typedef struct
{
    char      username[MAX_STR_32LEN+1];
    uint32_t  time_id;
    uint32_t  user_start_time;
    uint32_t  user_lasted_time;
    uint32_t  user_duration_time;
    uint32_t  hydrogenvalue;
}TMedUserStatis;

int deviceConfigReadStatisId(int id,TMedUserStatis* ptStatis,char* userName);
int deviceConfigReadUserStatis(char* userName,int refId,TMedUserStatis* ptStatis,int inSize,int* outSize);
int deviceConfigReadUserStatisPrevious(char* userName,int refId,TMedUserStatis* ptStatis,int inSize,int* outSize);
int deviceConfigReadUserStatisSize(char* userName,int *outTimeSize,int* outHydrogenSize,int* countSize);

int deviceConfigAddUserStatis(char* userName,time_t start,time_t duration);
int deviceConfigWriteWorkStatis(int updateId,int Minute,int hydrogen);
int updateWorkStatis(int updateId, int minute, int hydrogen);

typedef struct
{
    uint32_t box_tempture_gate;//水箱温度
    uint32_t box_tempture_warn;//水箱温度停止工作
    uint32_t inb_tempture_gate;//雾化温度,停止
    uint32_t inb_tempture_warn;//保存为补水时一杯水时间s
    uint32_t power_change_time_limit;//电极互换
    uint32_t gas_time_limit;//换气时间设定
    uint32_t liqiud_time_limit;//换液时间设定
    float    power_low_v;
    float    power_mid_v;
    float    power_high_v;
    float    hydrogen_display_low;
    float    hydrogen_display_mid;
    float    hydrogen_display_high;
    uint32_t outputtime_limit;
    uint32_t maintaince_limit;
    uint32_t lease_time_limit;
    uint32_t lease_amount_limit;//FanSpeed
    float    price_perminute;//每小时单价
    char     device_superadmin[MAX_STR_32LEN+1];
    char     device_superadminp[MAX_STR_32LEN+1];
    char     device_super[MAX_STR_32LEN+1];
}TDeviceDefault;

void deviceConfigAddDefaultValue(TDeviceDefault* tDefault);
int  deviceGetConfigDeviceDefault(TDeviceDefault* tDefault);
void deviceConfigReadDevDefaultValue(TDeviceDefault* ptDefault);
void deviceConfigWriteDevDefaultValue(TDeviceDefault* ptDefault);

enum
{
  LOG_POWERON =  100,//设备开机启动
  LOG_HB = 200, //设备心跳包
  LOG_START = 300, //开始工作
  LOG_STOP = 400, //停止工作 	400
  LOG_POWEROFF = 500, //设备关机
  LOG_PASSWD = 600, //工程密码更改
  LOG_WORKMOD = 700, //机器类型改变
  LOG_ACCEPT = 701, //用户确认
  LOG_MACHINE_LOG = 703, //机器产生警告,异常

  LOG_NET_LOGIN = 800,      //网络用户登入
  LOG_NET_PASSCHANGE = 801, //网络用户更改密码
  LOG_NET_ADDUSER = 802,    //网络用户添加本地用户
  LOG_NET_DELUSER = 803,    //网络用户删除本地用户
  LOG_NET_SELECTUSER = 804, //网络用户选择本地用户
  LOG_NET_STARTWORK = 805,  //网络用户开始本机工作
  LOG_NET_STOPWORK = 806,   //网络用户停止本机工作
  LOG_NET_POWROFF = 807,    //网络用户关闭本机
  LOG_NET_PARAMCHANGE = 808//网络用户更改参数
};

typedef struct
{
    int log_id;
    int user_id;
    int op_type;
    int out_breathe;
    int out_hydrogen;
    int op_duration;
    int op_time;
    int up_load;
}TMedLog;

int deviceConfigAddLog(int Type,int UserId);
int deviceConfigReadLogs(uint32_t nRef,TMedLog* ptLog,int size,int* outSize);
int deviceConfigReadUnupload(TMedLog* ptLog);
int deviceConfigReadLogType(int op_type,TMedLog* ptLog,int size,int* outSize);
int deviceConfigWrtieUploaded(int log_id);
int deviceConfigDeleteLogs(time_t time);
int deviceEthIsActived();
int deviceEthInterfaceUp();
//this is new api
//for http api
typedef struct tagEthParam
{
    unsigned long	m_dwIpAddr;
    unsigned long	m_dwIpAddrMask;
    unsigned char   mac_addr[6];
}TEthParam;

#define EXTERN_GPIO_BASE 1000
enum
{
    USER_POS_AUTOMIZER = 0,//当前雾化值
    USER_POS_HYDROGEN,     //7寸不要写
    USER_POS_LED,          //当前LED显示值 2
    USER_POS_POWERSTATE,   //当前是否关机 3
    USER_POS_PUMP,         //水泵是否开启J29 4
    USER_POS_SA,           //电磁阀AJ25
    USER_POS_SB,           //电磁阀BJ26
    USER_POS_RA,           //继电器A
    USER_POS_RB,           //继电器B
    USER_POS_O3_PUMP,      //臭氧泵
    USER_POS_O3_STATE,     //臭氧状态
    USER_POS_POWER_FANSPEED,//电源风扇速度
    USER_SET_VALUE_MAX,

    USER_POS_IN_CUP_LOW, //13
    USER_POS_IN_CUP_HIGH,//14
    USER_POS_IN_INB_LOW,
    USER_POS_IN_INB_HIGH
};

enum
{
    BoxTempture = 0,      //水箱温度
    InbTempture,          //雾化温度
    CH1Voltage,           //CH1电压
    CH1Current,           //CH1电流
    SampleCurrent,        //采样电流
    HydrogenThickness,    //氢气浓度
    HotPlugHydrogenLow,   //外接水杯低
    HotPlugHydrogenHigh,  //外接水杯高
    PowerGnd,             //电源接地
    BoxState,             //水箱在线
    InbCupLow,            //雾化水位低
    InbCupHigh,           //雾化水位高
    InbCupLow_old,        //雾化水位高
    FanState,             //风扇状态
    FanSpeed,             //风扇速度
    BoxLow,               //水箱水位低
    BoxHigh,              //水箱水位高
    HyPower,
    InbOpened,
    InbPower,
    DCState,
    MoveState1,
    MoveState2,
    InitState,
    PowerStatus,
    CmdStatus
};

enum
{
    GPIO_PWM1_A8=0*32+20,
    GPIO_POWER_FAN_7 = 0*32+20,
    GPIO_INB_WORK_7 = 1*32+16,
    GPIO_SANRE_FAN_7 = 1*32+18,
    GPIO_POWER_EXCHANGE_7 = 1*32+19,
    GPIO_POWER_ENABLE_7 = 1*32+20,
    GPIO_LENGNING_FAN_7 = 1*32+24,
    GPIO_XUNHUAN_PUMP_7 = 1*32+25,
    GPIO_ZHENKONG_PUMP_7 = 1*32+26,
    GPIO_AUDIO_MUTE_7 = 1*32+27,
    GPIO_ZHENKONG_FA_7 = 3*32+18,
    GPIO_SHIHUA_FA_7 = 3*32+19,
    GPIO_WUHUA_SHUIWEI_7 = 1*32+17,
    GPIO_BOX_SHUIWEI_GAO_7 = 1*32+21,
    GPIO_BOX_SHUIWEI_DI_7 = 1*32+22,
    GPIO_SHUIBEI_ZAI_7 = 1*32+23,
    GPIO_CH1_SHUCHU_7 = 2*32+1,
    GPIO_DIANYUAN_WENDU_7 = 3*32+14,
    GPIO_RESERVED_7 = 3*32+16,
    GPIO_SHIHUA_FA_7_2 = 0*32+7,
};

enum
{
    STM_HARD = 0,//硬件版本
    STM_SOFT     //软件
};

int medctrlSetIfAddr(const char *ifname,const char *Ipaddr,const char *mask,const char *gateway);
int ethNetWorkConneted();
int ctrGetEthParam(TEthParam* ptParam);
int ctrGetEthParamByName(const char* name,TEthParam* ptParam);
int ctrGetWifiParam(TEthParam* ptParam);
int openttySRead(char* name);
int openttyBluz(char* name);
int openttySWrite(char* name);
int openI2CFd(char* name);
//int I2CReadPowerStatus(int fd,int addr);
//int I2CReadFirmwareVersion(int fd,int addr,char* pOut,int ipOutLen);
//int I2CWritePowerValue(int fd,int addr,float powerValue);
//float I2CReadOutputCurrent(int fd,int addr);
//float I2CReadOutputVoltage(int fd,int addr);
int serialWrite(int hCom, char *pchBuf, long dwBytesToWrite, long *pdwBytesWrite);
int serialRead(int hCom, char *pchBuf, long dwBytesToRead, long *pdwBytesRead);
int serialPrepare(int hCom);
uint16_t versionCalcCRC(uint8_t *data, int size);
char *random_uuid( char buf[]);
void devicePlayAudio(int Type);
int devicePlayMusic(char* fileName,int loop);

typedef struct tagIOEntry
{
    uint32_t gpio;
    uint8_t  direction;
    uint8_t  defaultValue;
    uint8_t  currentValue;
    const char* description;
}TIOEntry;

enum
{
    MACHINE_STATE_WAITED = 0,//
    MACHINE_STATE_INITED,//1
    MACHINE_STATE_IDLE,//Idle2
    MACHINE_STATE_BLEED,//抽气3
    MACHINE_STATE_RUN,//运行4
    MACHINE_STATE_ADDWATER,//AddWater5
    MACHINE_STATE_MIXWATER,//MixWater6
    MACHINE_STATE_CLEAN,//AddWater7
    MACHINE_STATE_CHECK,//SelfCheck8
    MACHINE_STATE_UPGRADE,//SelfCheck9
    MACHINE_STATE_WORKCHECK,//10
    MACHINE_STATE_MAX//Nothing11
};
enum
{
    DEBUG_LVL_FATAL = (1<<0),
    DEBUG_LVL_HTTP = (1<<1),
    DEBUG_LVL_CTRL = (1<<2),
    DEBUG_LVL_EQP = (1<<3),
    DEBUG_LVL_MACHINE = (1<<4),
    DEBUG_LVL_UI = (1<<5),
    DEBUG_LVL_POWER = (1<<6),
    DEBUG_LVL_UPDATE = (1<<7),
    DEBUG_LVL_ALL = 255
};

void meddebug(int lvl,const char* fmt,...);

enum
{
    POWER_TYPE_SPI,
    POWER_TYPE_I2C
};

//for tempture table--A2
typedef int (*QueryTempureTable)(float fVal);
int      device_water_tempture(float val);
int      device_PT100_tempture(float val);
int      device_NTC10Kwater_tempture(float val);
int      device_inbreathe_tempture(float val);
int      device_water_tempture_new(float val);
float    device_tank_tempture_val(float v);
float    device_inbreathe_tempture_val(float v);
void     setBoxTemptureTable(int nNew);
void     setInbTemptureTable(int nNew);

void     arm_write_spi_value(const char* ctrlName,uint32_t val);
void     arm_write_i2c_value(const char* ctrlName,uint32_t val);
void     arm_config_gpio(int exported,int gpio_num,int dir,int valDefault);
int      arm_gpio_read(int gpio_num);
void     arm_gpio_write(int gpio_num,int val);
float    arm_water_warn();
float    arm_water_fan_gate();
int      arm_clear_user_db();
void     arm_set_audio_play();
void     arm_change_brightness(int val);
int      arm_loadsound_val();
void     arm_writesound_val(int val);

//获取当前日志文件总共大小
double getLogFileCurrentSize(void);
//获取当前文件系统可用大小
double getSystemAvailableSize(void);
//删除用户最早一条记录
void delUserTimeTabEarliestRecord(void);
//检查剩余空间大小是否小于20M
int chechkRemainSpace(void);

//获取用户个数
int getUserAccountNumber();
//获取所有的用户
void getAlluser(TMedUser *ptUser);
//通过用户名查找指定用户的信息
int getUserInfoByName(TMedUser *ptUser, const char *name);

//获取所有使用的信息总数
int getUserUseNumber();
//获指定用户取所有使用的信息总数
int getUserUseNumberByName(const char *name);
//获取所有的使用信息
void getUserUseAllInfo(TMedUserStatis *useInfo);
//通过用户查找某个用户的使用信息
void getUserUseInfoByName(TMedUserStatis *useInfo, const char *name);
//增加操作日志接口
void addOperateLog(const char *name);

#ifdef __cplusplus
};
#endif

#endif
