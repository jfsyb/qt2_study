#ifndef MED_HTTP_H
#define MED_HTTP_H
#include <QThread>
#include <QFile>
#include <QTimer>
#include <QUrl>
#include <QHostInfo>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDateTime>
#include <QSocketNotifier>
#include "../../medctrl_c/medctrl_c.h"
#include "../../medctrl_c/medctrl_c_common.h"
//#include "../../medctrl_c/medctrl_dev_protocol.h"
#include"../commondefine.h"

#define SAFE_JFREE(a) if (a) {cJSON_Delete(a);a=NULL;}
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QHttp>
#endif

class CurlHttpClient
{
public:
    CurlHttpClient();
    ~CurlHttpClient();
public:
    int Post(QString url,QString& resp,char* content = NULL,int timeOut=20);
    int Get(QString url,QString& resp,int timeOut=20);
    int DownLoadFile(QString url,QString fileName);
    void setDebug(int d)
    {
        m_nDebug = d;
    }
    QString httpresp;
    QFile   fileOpen;
    int Status()
    {
        return status;
    }
    bool isBusy()
    {
        return (status>0);
    }
    size_t     recved_times_t;
    curl_off_t recved_bytes;
    int        recved_times;
    CURL*      hdowncurl;
private:
    int m_nDebug;
    int status;

};
enum
{
    HTTP_MAN_CMD_UPDATE_STATIS = 1,
    HTTP_MAN_CMD_UPDATE_LIST,
    HTTP_MAN_CMD_DELETE_USER,
    HTTP_MAN_CMD_TEL_USER,
    HTTP_MAN_CMD_GET_REGURL,
};

#define MAX_ILL_ENTRY 13
class CMedHttpManager:public QObject
{
    Q_OBJECT
public:
    enum
    {
        HTTP_CMD_IDLE = 0,
        HTTP_CMD_REGURL,
        HTTP_CMD_REGUSERS,
        HTTP_CMD_GETUSERS,
        HTTP_CMD_DOWNLOADURL,
        HTTP_CMD_DOWNLOADDATA,
        HTTP_CMD_LOGSEND,
        HTTP_CMD_REPORT_STATIS,
        HTTP_CMD_UPDATE_USERS
    };
    static CMedHttpManager* create(QObject* parent);
    static CMedHttpManager* get();
    virtual ~CMedHttpManager();
    void SendLocalUsers();
    void GetRemoteUsers();
//    void GetRemoteVersion();
    void SendRegisterUrl();
    void RerequestRegisterUrl();
//    void DownLoadVersion(QString url,QString file);
    void SendLog(bool bType);
    void RegisterUserMobile();
    int  GetCodeValidTime()
    {
        if ( CheckCodeTimeOut <= 0 )
            CheckCodeTimeOut = 30;
        return CheckCodeTimeOut;
    }
    void ClearUserTelValidCode()
    {
        userCheckCode.clear();
    }
    QString& GetUserTelValidCode()
    {
        return userCheckCode;
    }
    QString GetQueriedVersion()
    {
        return queryNewVersion;
    }
    void ReporteUserStatis(int id);
    void ReportUserList();
    bool GetIsDownLoading()
    {
        if ( httpVersionDown )
            return httpVersionDown->isBusy();
        return true;
    }
    bool ParserResp(char* buf);
protected:
    CMedHttpManager(QObject* parent=0);
    void retranslateUi(QObject* obj);
    void run()
    {
        timer = new QTimer(this);
        timer->setInterval(10000);
        connect(timer,SIGNAL(timeout()),this,SLOT(timeout()),Qt::DirectConnection);
        timer->start();
    }
public slots:
    void timeout();
    void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
private:
    void    ResetTimer();
    void    OnTimerLogStatus();
    void    processMsg(char *msg);
    QString userCheckCode;
    QString queryNewVersion;
    int  CheckCodeTimeOut;
    static  CMedHttpManager* instance;
    static  QThread* httpthread;
    int     VersionCompare(char* _new,char* _old);
    char*   ParserVerInfo(char* buf,char* url,int len,char* FileName,int flen);
    char    compile_ver_n[64];
    quint32 GetLogContent(int type,std::string& ppBuf,int len);
    void    ParserRegUrl(char* buf);
    quint32 timers;
    QTimer* timer;

    CurlHttpClient* httpClient;
    quint8          httpClientState;

    CurlHttpClient* httpCheckUser;

    CurlHttpClient* httpVersionDown;
    quint32 httpDownLoadSize;

};



class QProtocolTcpSocket:public QObject
{
    Q_OBJECT
public:
    enum
    {
        DATATYPE_APP,
        DATATYPE_STM,
        DATATYPE_ROOTFS,
        DATATYPE_CONFIG,
        DATATYPE_UPDATEALL,
        DATATYPE_FILERAW
    };
    QProtocolTcpSocket(QTcpSocket* newTcpSock,int dir = 0)
    {
        int opt = 1;
        m_dir = dir;
        m_hSock = newTcpSock;
        m_pRecvBuff = new quint8[MSG_CONTENT_LEN];
        m_nRecvLen = 0;
        m_nCurRecvFrameLen = 0;
        dataSendTimes = 0;
        setsockopt(m_hSock->socketDescriptor(),IPPROTO_TCP,TCP_NODELAY,(char*)&opt,sizeof(opt));
        QObject::connect(m_hSock,SIGNAL(readyRead()),this,SLOT(OnReadReady()));
        QObject::connect(m_hSock,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(OnStateChange(QAbstractSocket::SocketState)));
        QObject::connect(m_hSock,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(OnExceptReady(QAbstractSocket::SocketError)));
        QObject::connect(m_hSock,SIGNAL(disconnected()),this,SLOT(OnClose()));
    }
    virtual ~QProtocolTcpSocket()
    {
        if ( m_pRecvBuff )
            delete []m_pRecvBuff;
        if ( m_hSock )
            m_hSock->deleteLater();
    }
public slots:
    void OnReadReady(void);
    void OnClose();
    void OnStateChange(QAbstractSocket::SocketState);
    void OnExceptReady(QAbstractSocket::SocketError);
private:
    void processCtrlData(quint8* buf,quint32 nLen);
    void SendMessageBack(quint32 ev,QString result);
    int  m_dir;
    int  dataSendTimes;
public:
    QTcpSocket*     m_hSock;
    unsigned char*  m_pRecvBuff;
    int				m_nRecvLen;
    int				m_nCurRecvFrameLen;
    void ClearHeart()
    {
        dataSendTimes = 0;
    }
    void IncreateHB()
    {
        dataSendTimes++;
    }

    bool isTimeOut()
    {
        return (dataSendTimes >= 3);
    }
};

class CMedCtrlManager:public QObject
{
    Q_OBJECT
public:
    static CMedCtrlManager* create(QObject* parent);
    static CMedCtrlManager* get();
    virtual ~CMedCtrlManager();
    enum
    {
        REGISTER_IDLE,
        REGISTER_REQ,
        REGISTER_NORMAL,
    };
protected:
    CMedCtrlManager(QObject* parent);
public:
    void SendBroadCast();
    void SendDebugStatus(int obj,int state,int errors,int userId = 0);
    void SendIOStatus(int obj,int io_num,int io_status);
    void SendDebugListen();
    void Register(QUrl url);
    void ForwardConnected();
    QString& GetAppUrl();
public slots:
    void sendcmd(int cmd,int p1,int p2,int m);
    void sendDelUser(int cmd,QString name);
    void sendAddUser(int cmd,int uid);
    void OnUdpReceived();
    void OnConnection();
    void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
protected slots:
    void timeOut();
public:
    void run();
    void BroadCastMsg(quint8* buf,quint32 nLen);
    void RemoveClient(QProtocolTcpSocket* tcp);
    quint8 GetDbgLvl()
    {
        return debugLvlValue;
    }

    static CMedCtrlManager* instance;
    static QThread* netctrlthread;
    QHostAddress debugListen;
    quint16      debugListenPort;
    quint8      debugListenHB;
    quint8      debugLvlValue;

    QTimer* timer;
    QTcpServer* m_pTcpServer;
    QUdpSocket* m_pUdpServer;
    QProtocolTcpSocket* regisgterTcp;
    int     connectState;
    qint32  confilePackets;
    QList<QProtocolTcpSocket*> protocolList;
};

class CMedNetWorkCtrlManager:public QObject
{
    Q_OBJECT
public:
    static CMedNetWorkCtrlManager* create(QObject* parent);
    static CMedNetWorkCtrlManager* get();
    virtual ~CMedNetWorkCtrlManager();
    quint8  GetNetStatus();
public slots:
    int  ctrlRequest(const char *cmd, char *buf, size_t *buflen);
    void startInterface(QString name);
    void stopInterface(QString name);
    void updateNetworks();
    void ReadConfWIFI();
    void ReadConfEth();
    bool isWifiEnabled()
    {
        return wifi_enable;
    }
    bool isEthEnabled()
    {
        return eth_enable;
    }
    void ConfDefault();
Q_SIGNALS:
    void sendRequestGateWay(QString);
public:
    static CMedNetWorkCtrlManager* instance;
    static QThread* ncmthread;
    void   OnNCMTimer();
    bool   getNetGateWay(QString ifname);
    void recvWifiMsg();
protected:
    CMedNetWorkCtrlManager(QObject* parent=0);
public slots:
    void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    void ping();
    void timeout();
    void receiveMsgs();
    void netLinkMsgs();
    void getGateWay(QString ifname);
    void lookedUp(const QHostInfo host);
protected: //for wifi
    int openCtrlConnection(const char *ifname);
    void saveScanResults();
    void processMsg(char *msg);
public:
    QStringList networkLists;
    QStringList scanLists;
    bool         eth_enable;
    int          eth_dhcp;
    QHostAddress eth_ip;
    QHostAddress eth_mask;
    QHostAddress eth_gateway;

    bool         connectedToAp;
    bool         wifi_enable;
    int          wifi_dhcp;
    QHostAddress wifi_ip;
    QHostAddress wifi_mask;
    QHostAddress wifi_gateway;
    void saveWIFI();
    void saveEth();
    quint8  netStatus;
    struct wpa_ctrl *ctrl_conn;
private:
    QTimer *timer;
    int     statusTimes;
    pid_t   wifi_dhcp_pid;
    void ReadPid();
    void SendPid(bool renew = true);
    void Init();
    void ConInit(bool read = false);
    //QSocketNotifier *msg_tNotifier;
    //int  netLinksock;
    //QSocketNotifier *netLinkNotifier;

    //WIFI at this
    char *ctrl_iface;
    QSocketNotifier *msgNotifier;

    int pingsToStatusUpdate;
    char *ctrl_iface_dir;
    struct wpa_ctrl *monitor_conn;
    bool connectedToService;
};
#endif
