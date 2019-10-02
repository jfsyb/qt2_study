#ifndef COMMONDEF_H
#define COMMONDEF_H
#include"../include/LogServer/logserver.h"
#include"../include/medctrl_c/medctrl_c.h"
#define LICENSE_FILE        ("/AM/appdata/license/license.dat")
#define LICENSE_RECORD_FILE ("/AM/appdata/license/licenserecord.xml")
#define UPDATE_FILE         ("app.update")
#define UPDATE_DIR          ("/var/dl/")

class  CommonParam
{
public:
    CommonParam();
    static int iMachineWorkMode;//0 is normal,1 is repaire
    static bool bCheckBoxLev;
    static int m_pSBoxwaterHlev;
    static int m_pSBoxwaterLlev;
    static int m_pS2DuanShiHuaBeiHlev;
    static int m_pS2DuanShiHuaBeiLlev;
    static int m_pS4DuanShiHuaBeilev;
    static int m_pSWuHualev;
    static int m_pSQingSHuiBeilev;
    static bool bCheckBoxTemp;
    static bool bCheckAddCupLev;
    static bool bCheckWuhuaCupLev;
    static bool bCheckWuhuaTemp;
    static double dBoxTemp   ;
    static double dWuhuaTemp ;
    static int iBoxWaterLev;//2 is low,1 is high,3 is middle
    static int iAddCupWaterLev;//0 is normal,1 is low,2 is high
    static bool m_bTestMode;
    static bool m_bTimeAdjustAble;
    static bool m_bBlueToothOn;
    static int machineType;
    static int m_iStartupCount;
    static int m_iLicenseTotalCount;
    static bool m_b4INCHLow;
    static bool m_bNotifiedUserLicenseWarn;
    static bool m_bNotifiedUserLicenseFailed;
    static std::string m_sLicenseData;
    static bool m_bSynTimeSuccess;
    static std::string m_sNowDateTime;
    static bool m_bDetectBoxHighLev;
    static int m_iTankCheckTemperature; //水箱检测温度，用于提示温度过低，默认为-2
    static int m_iBackPicture;
    static bool m_bGnd;
    static int iDebugLevel;//0:is admin,1:service worker,2:product worker
    static int iCanRunTime;
    static bool bDownloading;
    static bool m_bMuteMode;
    static bool m_bDetectBoxLevelAndHcupLev5;
    static bool m_bAutoCloseDebug;
    static bool m_bShowProcess;
    static bool m_bDetectCup;
    static int m_iMiddleAddWaterTimeOut;
    static int m_iFanSpeedFeadback;
    static int m_iWuHuaSpeed;
    static bool m_bBeginUpgrade;
    static bool m_bUpgradeError;
    static bool m_bNotifyOK;
    static int m_iComWrite;
    static int m_iComRead;
    static int m_iI2CHandle;
    static int m_iWidth;
    static int m_iHeight;
    static bool m_bCloseLED;
    static int m_iVol;
    static QString m_sStyle1;
    static QString m_sStyle2;
    static QString m_sStyle3;//start
    static QString m_sStyle4;//pause
    static QString m_sStyle5;//stop
    static QString m_sStyle6;//stop chines
    static QString m_sStyle7;//start jap
    static QString m_sStyle8;//stop jap
    static QString m_sStyle9;//wuhua
    static QString m_sStyle10;//user
    static QString m_sStyle11;//mianze
    static QString m_sStyle12;//mianze2
    static QString m_sStyle13;//slider vertical
    static QString m_sStyle14;//slider vertical
    static QString m_sStyle15;//slider vertical
    static QString m_sStyle16;//white edit
    static QString m_sStyle17;//checkbox
    static QString m_sStyle18;//checkbox
    static QString m_sStyle19;//history
    static QString m_sStyle20;//history
    static QString m_sStyle21;//checkbox
    static QString m_sStyle22;//history eng
    static QString m_sStyle23;//history eng
    static QString m_sStyle24;//user network help
    static QString m_sStyle25;//user network help
    static QString m_sStyle26;//adv label
    static QString m_sStyle27;//failed connecting
    static QString m_sStyle28;//connecting
    static QString m_sStyle29;//connected
    static QString m_sStyle30;//setpassword
    static QString m_sStyle31;//shurufa q
    static QString m_sStyle32;//shurufa lang
    static QString m_sStyle33;//shurufa select lang
    static QString m_sStyle34;//shurufa del
    static QString m_sStyle35;//shurufa ok
    static QString m_sStyle36;//shurufa Aa
    static QString m_sStyle37;//info
    static QString m_sStyle38;//lang1
    static QString m_sStyle39;//lang2
    static QString m_sStyle40;//kongge
    static QString m_sStyle41;//qingyangnongdu
    static QString m_sStyle42;//
    static QString m_sStyle43;//
    static QString m_sStyle44;//
    static QString m_sStyle45;//
    static QString m_sStyle46;//
    static bool m_IsA8;
 public:
    static int currentMachineType();
    static int GetStartupCount();
    static int GetLicenseTotolCount();
    static void WriteStartupCount(int iCount);
    static void WriteLicenseTotolCount(int iCount);
    static void WriteNowDateTime(std::string sValue);
    static void WriteConfigFile();

private:


};
#define MAX_STR_16LEN 16
#define MAX_STR_32LEN 32
#define MAX_STR_255LEN 255
//#define MED_CTRL_HEADER_LEN 16
//#define MULTI_ADDR_STR "224.32.1.1"
//#define MULTI_ADDR_PORT 8000
typedef struct
{
  unsigned int protocaltype;
  unsigned int protocalid;
  unsigned int protocalidd; //maybe channage
  unsigned int protocal_msglen;
}THeader;

#define MED_CTRL_HEADER_LEN 16
#define MED_CTRL_HEADER_DATA_LEN (16+12)
#define MULTI_ADDR_STR "224.32.1.1"
#define MULTI_ADDR_PORT 8000


#define MSG_CONTENT_LEN (4096+MED_CTRL_HEADER_DATA_LEN)

typedef struct
{
  quint32 packType;
  quint32 packNum;
  quint32 packLen;
  quint8* packData;
}TDataHeader;

typedef struct
{
  quint32 packNum;
  quint32 packType;
  quint32 packIoNum;
  quint32 packIoStatus;
  quint8  device_uuid[MAX_STR_32LEN+1];
}TDebugHeader;
enum
{
    emMsg_Search_ID = 1000,
    emMsg_Search_Nty, //1001TSearchDevice

    emMsg_Register_Dev, //1002TSearchDevice
    emMsg_Register_Dev_Ack,//1003

    emMsg_UnRegister_Dev, //1004TSearchDevice
    emMsg_UnRegister_Dev_Ack,//1005

    emMsg_Login_Dev, //TLoginReq 1006
    emMsg_Login_Dev_Ack, //TLoginResp 1007

    emMsg_Ping_Dev, //heart between device 1008
    emMsg_Ping_Dev_Ack,//1009

    emMsg_Get_DevData,//1010
    emMsg_Get_DevData_Ack,//TDevice1011

    emMsg_Set_DevData, //TDevice 1012
    emMsg_Set_DevData_Ack, //TOperateResp 1013
    emMsg_Set_DevData_Ntf,//1014

    emMsg_Get_DevNetData,//1015
    emMsg_Get_DevNetData_Ack,//TDeviceNet1016

    emMsg_Set_DevNetData,//TDeviceNet1017
    emMsg_Set_DevNetData_Ack,//TOperateResp1018
    emMsg_Set_DevNetData_Ntf,//1019

    emMsg_Get_UserData, //TListGetReq1020
    emMsg_Get_UserData_Ack,//1021

    emMsg_Add_UserData,//TMedUser1022
    emMsg_Add_UserData_Ack,//TOperateResp1023
    emMsg_Add_UserData_Ntf,//1024

    emMsg_Del_UserData, //TUserDelReq1025
    emMsg_Del_UserData_Ack,//TOperateResp1026
    emMsg_Del_UserData_Ntf,//1027

    emMsg_Get_WiFiData, //TListGetReq1028
    emMsg_Get_WiFiData_Ack,//1029

    emMsg_Set_WiFiData, //TDeviceNetWifi1030
    emMsg_Set_WiFiData_Ack,//1031
    emMsg_Set_WiFiData_Ntf,//1032
    emMsg_Page_Notify,//1033

    emMsg_Select_User,//1034
    emMsg_Select_User_Ack,//1035
    emMsg_Select_User_Ntf,//1036

    emMsg_Select_User_Time,//1037
    emMsg_Select_User_Time_Ack,//1038
    emMsg_Select_User_Time_Ntf,//1039

    emMsg_Start_User_Work,//1040
    emMsg_Start_User_Work_Ack,//1041
    emMsg_Start_User_Work_Ntf,//1042

    emMsg_Stop_User_Work,//1043
    emMsg_Stop_User_Work_Ack,//1044
    emMsg_Stop_User_Work_Ntf,//1045

    emMsg_Change_User_InBreathe,//1046
    emMsg_Change_User_InBreathe_Ack,//1047
    emMsg_Change_User_InBreathe_Ntf,//1048

    emMsg_Change_User_HyDrogen,//1049
    emMsg_Change_User_HyDrogen_Ack,//1050
    emMsg_Change_User_HyDrogen_Ntf,//1051

    emMsg_PowerOff,//1052
    emMsg_PowerOff_Ack,//1053
    emMsg_PowerOff_Ntf,//1054

    emMsg_Debug_Reg_Cmd,//1055
    emMsg_Debug_Out_Cmd,//1056
    emMsg_Debug_Status_Ntf,//1057
    emMsg_Debug_Gpio_Ntf,//1058

    emMsg_SetAlias_Cmd,//1059
    emMsg_SetAlias_Ack,//1060
    emMsg_SetAlias_Ntf,//1061

    emMsg_GetUser_Statis_Data, //获取用户统计信息1062
    emMsg_GetUser_Statis_Data_Ack,//用户统计列表1063

    emMsg_BroadCast_NTF,//1064

    emMsg_LogOut_Dev,//1065
    emMsg_LogOut_Dev_Ack,//1066

    emMsg_UpdateData_REQ,//1067
    emMsg_UpdateData_ACK,//1068
    emMsg_UpdateData_NACK,//1069

    emMsg_UpdateData_Stop_REQ,//1070
    emMsg_UpdateData_Stop_ACK,//1071
    emMsg_UpdateData_Stop_NACK,//1072

    emMsg_DownLoadData_REQ,//1073
    emMsg_DownLoadData_ACK,//1074
    emMsg_DownLoadData_NACK,//1075

    emMsg_ExecuteCmd_REQ,//1076
    emMsg_ExecuteCmd_ACK,//1077
    emMsg_ExecuteCmd_NACK,//1078

    emMsg_GetDevice_ParamDefault_REQ,//1079
    emMsg_GetDevice_ParamDefault_ACK,//1080
    emMsg_GetDevice_ParamDefault_NACK,//1081

    emMsg_SetDevice_ParamDefault_REQ,//1082
    emMsg_SetDevice_ParamDefault_ACK,//1083
    emMsg_SetDevice_ParamDefault_NACK,//1084

    emMsg_Restore_Device_REQ,//1085
    emMsg_Restore_Device_ACK,//1086

    emMsg_Factory_Device_Cmd,//1087
    emMsg_Device_Reboot_Cmd,//1088

    emMsg_ShowProgress_Notify,//1089
    emMsg_ShowErrors_Notify,//1090

    emMsg_Update_UserStatis_Time,//1091
    emMsg_Connet_Notify,//1092
    emMsg_DisConnet_Notify,//1093
    emMsg_Empty_DataBase,//1094

    emMsg_BlueTooth_Cmd,//1095
    emMsg_BlueTooth_TransLicense,//1096

    emMsg_UI_Start_Pressed,//1097
    emMsg_UI_Stop_Pressed
};
#define NET_CTRL_CMD(n,v) (((n)<<16)|(v))
#define NET_CTRL_M(n)     ((n>>16)&0xFFFF)
#define NET_CTRL_EVENT(n) (n&0xFFFF)
#define NET_CTRL_CMD_COMP(n,v) NET_CTRL_CMD(NET_CTRL_M(n),v)
#define GET_MPOS(n) ((n>>16)&0xFF)
#endif // MEDCTRLDEBUG_H
