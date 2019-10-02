#ifndef TCPSERVERBASE_H
#define TCPSERVERBASE_H

//#include <QObject>
#include<string>
#include <QtCore/qobject.h>
#include<QtNetwork/qnetworkreply.h>
#include<vector>
class QSemaphore;
class QNetworkAccessManager;
class QNetworkReply;
class CTCPServerBase;
class MyConnectClient
{
public:
    MyConnectClient();
    MyConnectClient(CTCPServerBase* pServer);
    ~MyConnectClient();
    int SendDataAsyn(const std::string& sData);
    static void* MyRecThread(void *arg);
public:
    int m_iConnectedSocket;
    pthread_t m_Recpthread_t;
    bool m_bClosed;
    std::string m_sDeviceID;
    std::string sTempData;
    QSemaphore* m_doingsemaphore;
    QSemaphore* m_RecFileEndsemaphore;
    std::string m_sGetFileTempBuffer;
    bool m_bRemoteHelping;
    int m_iLastCommTime;
    CTCPServerBase* m_pThisPointer;
};

struct SThreadParams
{
    int iSocketID;
    void* pThisPointer;
};
typedef struct
{
   MyConnectClient m_pConnetedClient;
   void* m_pThis;
}MyConnectArgs;

class CTCPServerBase : public QObject
{
//    Q_OBJECT
//public:
//    explicit CTCPServerBase(QObject *parent = 0);

//signals:

//public slots:

    Q_OBJECT
public:
    CTCPServerBase();
public:
    ~CTCPServerBase();

    //brief:init net
    //param:
    //[in] sIP:ip
    //[in] iPort:port
    //[in] bClient: client is true,server is false
    //[out] n.a
    //return:
    // 0 is ok,1 is not ok.
    int InitNetWork(const std::string& sIP,const int& iPort,bool bAutoClose=true);

    //brief:close net
    //param:
    //[in] iSocket:socket id
    //[out] n.a
    //return:
    // 0 is ok,1 is not ok.
    int CloseNetWork();
//    int SendDataAsyn(const int& iConnectedSocketID,const std::string& sData);
    virtual int RecvData(const int& iConnectedSocketID,const std::string& sData);
    int SetDeviceID(const std::string& sName,const int& iSocketID);
    int GetDeviceSocketID(const std::string& sName,int& iSocketID);
    int GetClientStrID(const int& iSocketClientID,std::string& sOut);
    MyConnectClient* GetMyConnectClient(const int& iSocketClientID,bool bUpdateLasetTime=true);
    MyConnectClient* GetMyConnectClient(const std::string& sName);
    bool ConnectIsValid(MyConnectClient* pIn);

private:
    void OnNewConnect(const int& iConnectedSocketID);
    void CloseSocketID(const int& iConnectedSocketID);
public:
    std::string m_sBufferData;
    QSemaphore *m_Recsemaphore;
protected:
    static void* MyConnectThread(void *arg);
//    static void* MyRecThread(void *arg);
    static void* MyCloseThread(void *arg);
    bool m_bRead;
    int  m_isockfd;    
    QSemaphore *m_semaphore;

    bool m_bAutoCloseSocket;
public:
    std::vector<MyConnectClient*> m_vClientSocket;
};

#endif // TCPSERVERBASE_H
