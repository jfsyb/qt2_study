#ifndef NETWORKBASE_H
#define NETWORKBASE_H
#include<string>
#include <QtCore/qobject.h>
#include<QtNetwork/qnetworkreply.h>
#include<vector>
#include "networkbase_global.h"

class QSemaphore;
class QNetworkAccessManager;
class QNetworkReply;
class NETWORKBASESHARED_EXPORT CNetWorkBase:public QObject
{
    Q_OBJECT
public:
    CNetWorkBase();
private slots:
    QByteArray HttpGetnetwokReplyFinished(QNetworkReply*);
    void HttpGetloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void HttpGetloadError(QNetworkReply::NetworkError);

    QByteArray HttpPostnetwokReplyFinished(QNetworkReply*);
    void HttpPostloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void HttpPostloadError(QNetworkReply::NetworkError);
public:
    ~CNetWorkBase();

    //brief:init net
    //param:
    //[in] sIP:ip
    //[in] iPort:port
    //[in] bClient: client is true,server is false
    //[out] n.a
    //return:
    // 0 is ok,1 is not ok.
    int InitNetWork(const std::string& sIP,const int& iPort);

    //brief:close net
    //param:
    //[in] iSocket:socket id
    //[out] n.a
    //return:
    // 0 is ok,1 is not ok.
    int CloseNetWork();

    //brief:receQSemaphoreive net data
    //param:
    //[in]
    //[out] sData:data
    //return:
    // 0 is ok,1 is not ok.
    virtual int RecvData(std::string& sData);

    //brief:Send data synchronization
    //param:
    //[in] sData:data
    //[in] iTimeOut:time out
    //[out] sOut:out data
    //return:
    // 0 is ok,1 is not ok.
//    int SendDataSyn(const std::string& sData,std::string& sOut,const int& iTimeOut=-1);

    //brief:Send data asynchronization
    //param:
    //[in]
    //[out] sData:data
    //return:
    // 0 is ok,1 is not ok.
    int SendDataAsyn(const std::string& sData);

    //brief:post http
    //function HttpPostProcess: get post process
    //function HttpPostFinish:when post finish
    //function HttpPostError:get post error
    //param:
    //[in] networkReq:url
    //[in] sData:data
    //return:
    // 0 is ok,1 is not ok.
    int PostHttp(const QNetworkRequest& networkReq,const QByteArray& sData);

    //brief:get http
    //function HttpGetProcess: get Get process
    //function HttpGetFinish:when Get finish
    //function HttpGetError:get Get error
    //param:
    //[in] networkReq:url
    //[out] n.a
    //return:
    // 0 is ok,1 is not ok.
    int GetHttp(const std::string& sAddr);

    //brief:notify get http process
    //param:
    //[in] dValue:process percent
    //[out] n.a
    //return:
    virtual void HttpGetProcess(double dValue);

    //brief:notify post http process
    //param:
    //[in] dValue:process percent
    //[out] n.a
    //return:
    virtual void HttpPostProcess(double dValue);

    //brief:notify get http finish
    //param:
    //[in] qbValue:result
    //[out] n.a
    //return:
    virtual void HttpGetFinish(const QByteArray& qbValue);

    //brief:notify post http finish
    //param:
    //[in] n.a
    //[out] n.a
    //return:
    virtual void HttpPostFinish();

    //brief:notify get http error
    //param:
    //[in] iError:see QNetworkReply::NetworkError
    //[out] n.a
    //return:
    virtual void HttpGetError(int iError);

    //brief:notify post http error
    //param:
    //[in] iError:see QNetworkReply::NetworkError
    //[out] n.a
    //return:
    virtual void HttpPostError(int iError);
private:
    static void* MyRecThread(void *arg);
    bool m_bRead;
    int  m_isockfd;
    pthread_t m_thread;
    QSemaphore *m_Synsemaphore;
    std::string m_sSynBufferData;
    QSemaphore *m_Sendingsemaphore;
    QNetworkAccessManager *m_pHttpGetNetManager;
    QNetworkAccessManager *m_pHttpPostNetManager;
    QNetworkReply *m_pHttpGetNetReply;
    QNetworkReply *m_pHttpPostNetReply;
};

#endif // NETWORKBASE_H
