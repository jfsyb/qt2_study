#ifndef WIFICONNECTTHREAD_H
#define WIFICONNECTTHREAD_H

#include <QThread>
//#include <QStringList>

const int LINE_LENGTH = 128;
const int WPA_STATUS_NUM = 18;
const QString WIFI_DHCP_PID_FILE = "/var/run/wlanudhcpc.pid";

class WifiConnectThread : public QThread
{
    Q_OBJECT
public:
    enum WifiConnectState
    {
        FailureState = 0,
        ConnectingState = 1,
        ConfigureState = 2,
        ScanningState = 3,
        PasswordFailState = 4,
        CompleteState = 5,
        GetIPAddrState = 6,
        GetIPAddrFinishState = 7,
        ConnectSuccessState = 8,
        ConnectFailState = 9
    };

    explicit WifiConnectThread(QObject *parent = 0);
    ~WifiConnectThread();

    void configWifiInfo(QString name, QString ssid, QString password);

    inline void setWifiName(QString name){m_strName = name;}

    virtual void run();

    void notifyWifiConnectState(QString, int);

    bool checkNetwork() const;

    bool checkGateway() const;

private:
    void killWifiDHCP();
    int checkWifiProcess();
    void refreshNetworkList();

signals:
    void wifiConnectState(QString, int);

private:
    QString m_strName;
    QString m_strSSid;
    QString m_strPwd;
};

#endif // WIFICONNECTTHREAD_H
