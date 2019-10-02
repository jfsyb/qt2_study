#ifndef MED_CTRL_H
#define MED_CTRL_H
#include <QMainWindow>
#include <QWidget>
#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QWidget>
#include <QToolButton>
#include <QColor>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QSignalMapper>
#include <QRadioButton>
#include <QLineEdit>
#include <QSlider>
#include <QFrame>
#include <QDialog>
#include <QGroupBox>
#include <QTableWidget>
#include <QPainter>
#include <QPlainTextEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QFileSystemWatcher>
#include<QDateTime>
#include "../medctrl_c/medctrl_c.h"
//#include "../medctrl_c/medctrl_dev_protocol.h"
#include "medkeyboard.h"
#include "../include/medctrl/network-protocol/medhttp.h"
#include <QTimer>
#include <QHash>
#include"packunpackdata.h"
#include "medctrlcheckcmd.h"

const int CHECK_THREAD_TIME = 5;//60s

#define DEF_WIFIPATH   "/var/lib/wifi.conf"

QString GetResource(int type);
void LoadResource(int Lan);
void UpdateScreenState(bool bOn = false);
void UpdateUserTime();
quint32 userMaxTimeLimitL();
quint32 userMaxTimeLimitH();
quint32 userMaxTimeLimitG();
bool isScreen();
int  currentMachineType();
int appGetCurrentLanguage();
int str_match_this(const char *a, const char *b);
#define DELAY usleep(100*1000)

class zTemplateApp;
class QGPIOEntry;
class QGPIOHashList;
class CSerialStatusValue;
class QMedStateObject
{
public:
    enum
    {
        SERIAL_INIT,//0
        SERIAL_ASK_SW,//1
        SERIAL_ASK_HW,//2
        SERIAL_NORMAL,//3
        SERIAL_UPDATE_REQ,//4
        SERIAL_UPDATE_LEN,//5
        SERIAL_UPDATE_DATA,//6
        SERIAL_UPDATE_FINISH//7
    };
    enum
    {
        FLAG_DEBUG = (1<<0),//0x1
        FLAG_IONOTIFY= (1<<1),//0x2
        FLAG_UIERRORS= (1<<2),//0x4
        FLAG_WATERADDED= (1<<3),//0x8
        FLAG_USERSTARTED= (1<<4),//0x10
        FLAG_TEMPHIGH= (1<<5),//0x20
        FLAG_AUDIOHIGH= (1<<6),//0x40
        FLAG_AUDIOLOW= (1<<7)//0x80
    };
    enum
    {
        TIMER_BREATHE_START = 4700,
        TIMER_BREATHE_STOP,
        TIMER_ERROR_REPORTS
    };
    QMedStateObject();
    virtual   ~QMedStateObject();
    virtual int       machineReadGpio(int num);
    virtual void      machineWriteGpio(int num,int val);
    virtual void      changePowerExchange();
    virtual bool      PowerExchangedTime() = 0;
    virtual bool      capability(int cap) = 0;
    virtual quint8    GetBoxStateH() = 0;
    virtual quint8    GetBoxStateL() = 0;
    virtual quint8    GetICupState() = 0;
    virtual quint8    GetHCupState() = 0;
    virtual quint8    GetHCupState2() = 0;
    virtual quint8    GetQingShuiCupState() = 0;
    virtual void      machineSetDuration(int val)
    {
        fDuration = val;
    }
    virtual void      OnDaemonRead(zTemplateApp* app);
    virtual void      OnDaemonTimer(zTemplateApp* app);

    virtual void      OnDeamonMessage(int,quint32,quint32,quint8*,quint16,zTemplateApp*)
    {
        LOG_DEBUG <<"OnMessage is default";
    }
    virtual void      OnTimer()
    {
        LOG_DEBUG <<"OnTimer is default";
    }
    virtual bool isWaterAdded()
    {
        return (fCtrlFlags&FLAG_WATERADDED);
    }
    virtual void SetFlag(quint32 f)
    {
        fCtrlFlags |= f;
    }
    virtual void ClearFlag(quint32 f)
    {
        fCtrlFlags &= ~f;
    }
    virtual bool TestFlag(quint32 f)
    {
        return (fCtrlFlags&f);
    }
    quint32& CtrlFlag()
    {
        return fCtrlFlags;
    }
    virtual void      OnMessage(int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size) = 0;
    virtual void      OnListTimer(int ev)
    {
        LOG_DEBUG <<"Parent OnListTimer"<<ev;
    }

    void setUser(TMedUser* ptUser)
    {
        if ( ptUser )
            memcpy(&fUser,ptUser,sizeof(fUser));
        updateStatisId = -1;
    }
    TMedUser& user()
    {
        return fUser;
    }
    bool userEmpty()
    {
        return (fUser.userid == 0);
    }
    void userClear()
    {
        memset(&fUser,0,sizeof(fUser));
        updateStatisId = -1;
    }
    int& breathe()
    {
        return fInbreathe;
    }
    int& hydrogen()
    {
        return fHydrogen;
    }
    int& duration()
    {
        return fDuration;
    }
    void UpdateUserStatis(bool bStart,int val);
    int& Type()
    {
        return fType;
    }
    int Num()
    {
        return fCtrlNum;
    }
    int& statuisId()
    {
        return updateStatisId;
    }
    int& LastError()
    {
        return fLastError;
    }
    int& PowerStatus()
    {
        return fPowerStatus;
    }

    QString& status()
    {
        return fStatus;
    }
    quint8& CurState()
    {
        return fState;
    }
    quint8& LastState()
    {
        return fLastState;
    }
    void NextState(quint8 state)
    {        
        LOG_DEBUG <<"change state"<<state;
        fLastState = fState;
        fState = state;
        if ( CMedCtrlManager::get() )
        {
//            LOG_DEBUG <<"send state"<<state;
            CMedCtrlManager::get()->SendDebugStatus(fCtrlNum,state,fLastError);
        }
    }
    bool Terminated()
    {
        if ( fCtrlFlags&FLAG_USERSTARTED )
            return false;
        else
            return true;
    }
    void SetTimer(quint32 timerid,quint32 timeEnd);
    void KillTimer(quint32 timerid);
    void PollTimer();
    QString& getErrorString(int e);
    virtual QString getStateString(int e);
    virtual void ParseData(zTemplateApp* app);
    virtual void WriteEmgerncyData(zTemplateApp* app,CSerialStatusValue* ptData);
    virtual void post(int dest,int destObj,int ev,quint32 p1=0,quint32 p2=0,quint8* buf=0,quint16 size=0);

    inline bool isPause(){return m_bPauseFlag;}
    inline void setPauseFlag(bool flag){m_bPauseFlag = flag;}

    QString getDeviceType();

public:
    int             fCtrlNum;
    quint8          fState;
    quint8          fLastState;
    zTemplateApp*   fParent;
    quint32         verPackNum;
    QFile           updateFile;
protected:
    TMedUser        fUser;
    int             fInbreathe;
    int             fHydrogen;
    int             fDuration;
    int             fType;
    int             fLastError;
    int             fPowerStatus;
    int             updateStatisId;
    bool            fTestMode;
    quint32         fCtrlFlags;
    QString         fStatus;
    QString         fLastStringErr;
    QByteArray      ctrlData;
    int             fTimeLimitSecond;
    QHash<quint32,quint32> listTimers;
    size_t          current_seconds;
    size_t          record_start_seconds;

    bool m_bPauseFlag;
    QMutex m_mutex;
    QMutex m_timerMutex;
};

class QDummyClass
{

};


class MsgAddr
{
public:
    MsgAddr()
    {

    }
    MsgAddr(void* p)
    {
        addr = p;
    }
    void*  addr;
};

class TemplateMsg
{
public:
    TemplateMsg()
    {
        memset(this,0,sizeof(*this));
    }
    ~TemplateMsg()
    {

    }
    TemplateMsg(int dest1,int destObj1,int ev1,quint32 p11 = 0,quint32 p21 = 0,quint8* buf1 = 0,quint16 size1 = 0):dest(dest1),
        destObj(destObj1),ev(ev1),p1(p11),p2(p21),buf(buf1),size(size1)
    {

    }

    int dest;
    int destObj;
    int ev;
    quint32 p1;
    quint32 p2;
    quint8* buf;
    quint16 size;
};
class QRollingBox : public QWidget
{
    Q_OBJECT
public:
    explicit QRollingBox(QWidget *parent = 0);
    void setRange(int min,int max,int ring);
    int readValue();
    void setValue(int val);
protected:
    int m_minRange;
    int m_maxRange;
    int m_currentValue;
    bool isDragging;
    int  m_mouseMoved;
    int  m_mouseSrcPos;
    int  m_ringed;
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
};

class QTimeDateSelect: public QDialog
{
    Q_OBJECT
public:
    enum
    {
        SELECT_DATE,
        SELECT_TIME
    };
    explicit QTimeDateSelect(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QTimeDateSelect();
    void setType(int n)
    {
        QPalette pal;
        pal.setBrush(QPalette::Background,QBrush(QPixmap(GetResource(0))));
        setPalette(pal);
        if ( n == SELECT_DATE )
        {
            box_year_hour->setRange(1900,2050,0);
            box_year_hour->setValue(2016);
            box_month_minute->setRange(1,12,1);
            box_month_minute->setValue(6);
            box_date_seconds->setRange(1,31,1);
            box_date_seconds->setValue(15);
        }
        else
        {
            box_year_hour->setRange(0,23,1);
            box_year_hour->setValue(12);
            box_month_minute->setRange(0,59,1);
            box_month_minute->setValue(30);
            box_date_seconds->setRange(0,59,1);
            box_date_seconds->setValue(30);
        }
        update();
        thisType = n;
    }
Q_SIGNALS:
    void textChanged(QString text);
private slots:
    void OnTextChange();
    void OnTextCancel();
public:
    int thisType;
    QVBoxLayout *verticalLayout_main;
    QHBoxLayout *horizontalLayout_main;
    QHBoxLayout *horizontalLayout_btns;
    QVBoxLayout *verticalLayout_year_hour;
    QVBoxLayout *verticalLayout_month_minute;
    QVBoxLayout *verticalLayout_date_seconds;
    //QPushButton *pushButton_year_hour_add;
    //QPushButton *pushButton_year_hour_del;
    QRollingBox* box_year_hour;
    //QPushButton *pushButton_month_minute_add;
    //QPushButton *pushButton_month_minute_del;
    QRollingBox* box_month_minute;
    //QPushButton *pushButton_date_seconds_add;
    //QPushButton *pushButton_date_seconds_del;
    QRollingBox* box_date_seconds;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    /*QDateEdit date = new QDateEdit();
    date->setCalendarPopup(true);*/
    void retranslateUi(QWidget *Form);

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QTimeDateSelect"));
        verticalLayout_main = new QVBoxLayout(Form);
        verticalLayout_main->setSpacing(0);
        verticalLayout_main->setObjectName(QString::fromUtf8("verticalLayout_main"));
        verticalLayout_main->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_main = new QHBoxLayout();
        horizontalLayout_main->setObjectName(QString::fromUtf8("horizontalLayout_main"));
        horizontalLayout_btns = new QHBoxLayout();
        horizontalLayout_btns->setObjectName(QString::fromUtf8("horizontalLayout_btns"));

        verticalLayout_year_hour= new QVBoxLayout();
        verticalLayout_year_hour->setObjectName(QString::fromUtf8("verticalLayout_year_hour"));
        verticalLayout_year_hour->setContentsMargins(0, 0, 0, 0);
        verticalLayout_year_hour->setSpacing(0);
        //pushButton_year_hour_add = new QPushButton(Form);
        //pushButton_year_hour_add->setObjectName(QString::fromUtf8("pushButton_year_hour_add"));
        //verticalLayout_year_hour->addWidget(pushButton_year_hour_add);
        box_year_hour = new QRollingBox(Form);
        box_year_hour->setObjectName(QString::fromUtf8("box_year_hour"));
        verticalLayout_year_hour->addWidget(box_year_hour);
        //pushButton_year_hour_del = new QPushButton(Form);
        //pushButton_year_hour_del->setObjectName(QString::fromUtf8("pushButton_year_hour_del"));
        //verticalLayout_year_hour->addWidget(pushButton_year_hour_del);
        horizontalLayout_main->addLayout(verticalLayout_year_hour);

        verticalLayout_month_minute= new QVBoxLayout();
        verticalLayout_month_minute->setObjectName(QString::fromUtf8("verticalLayout_month_minute"));
        verticalLayout_month_minute->setContentsMargins(0, 0, 0, 0);
        verticalLayout_month_minute->setSpacing(0);
        //pushButton_month_minute_add = new QPushButton(Form);
        //pushButton_month_minute_add->setObjectName(QString::fromUtf8("pushButton_month_minute_add"));
        //verticalLayout_month_minute->addWidget(pushButton_month_minute_add);
        box_month_minute = new QRollingBox(Form);
        box_month_minute->setObjectName(QString::fromUtf8("box_month_minute"));
        verticalLayout_month_minute->addWidget(box_month_minute);
        //pushButton_month_minute_del = new QPushButton(Form);
        //pushButton_month_minute_del->setObjectName(QString::fromUtf8("pushButton_month_minute_del"));
        //verticalLayout_month_minute->addWidget(pushButton_month_minute_del);
        horizontalLayout_main->addLayout(verticalLayout_month_minute);

        verticalLayout_date_seconds= new QVBoxLayout();
        verticalLayout_date_seconds->setObjectName(QString::fromUtf8("verticalLayout_date_seconds"));
        verticalLayout_date_seconds->setContentsMargins(0, 0, 0, 0);
        verticalLayout_date_seconds->setSpacing(0);
        //pushButton_date_seconds_add = new QPushButton(Form);
        //pushButton_date_seconds_add->setObjectName(QString::fromUtf8("pushButton_date_seconds_add"));
        //verticalLayout_date_seconds->addWidget(pushButton_date_seconds_add);
        box_date_seconds = new QRollingBox(Form);
        box_date_seconds->setObjectName(QString::fromUtf8("box_date_seconds"));
        verticalLayout_date_seconds->addWidget(box_date_seconds);
        //pushButton_date_seconds_del = new QPushButton(Form);
        //pushButton_date_seconds_del->setObjectName(QString::fromUtf8("pushButton_date_seconds_del"));
        //verticalLayout_date_seconds->addWidget(pushButton_date_seconds_del);
        horizontalLayout_main->addLayout(verticalLayout_date_seconds);
        verticalLayout_main->addLayout(horizontalLayout_main);

        pushButton_confirm = new QPushButton(Form);
        pushButton_confirm->setObjectName(QString::fromUtf8("pushButton_confirm"));
        horizontalLayout_btns->addWidget(pushButton_confirm);
        pushButton_cancel = new QPushButton(Form);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        horizontalLayout_btns->addWidget(pushButton_cancel);
        verticalLayout_main->addLayout(horizontalLayout_btns);

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

const int MAX_SERAIL_NUM=2;
class zTemplateApp:public QObject
{
    Q_OBJECT
public:
    enum
    {
        EVENT_MACHINE_POWER_ON = 3000,
        EVENT_MACHINE_EXIT,//3001
        EVENT_MACHINE_HB,//3002
        EVENT_MACHINE_REG_REQ,//3003
        EVENT_MACHINE_WIFI_SCAN_REQ,//3004
        EVENT_MACHINE_WIFI_SCANED,//3005
        EVENT_MACHINE_WIFI_LIST_GET,//3006
        EVENT_MACHINE_WIFI_SUCCESSED,//3007
        EVENT_MACHINE_REGISTER_IO_STATUS,//3008
        EVENT_MACHINE_IO_STATUS_NOTIFY,//3009
        EVENT_MACHINE_DEBUG_ONOFF,//3010
        EVENT_MACHINE_CONFIG_UPDATED,//3011
        EVENT_MACHINE_WRITE_GPIO_VALUE,//3012
        EVENT_MACHINE_WRITE_POWER_VALUE,//3013
        EVENT_MACHINE_QUERY_NEW_VERSION_REQ,//3014
        EVENT_MACHINE_QUERY_NEW_VERSION_ACK,//3015
        EVENT_MACHINE_DOWNLOAD_NEW_VERSION_REQ,//3016
        EVENT_MACHINE_DOWNLOAD_NEW_VERSION_PROGRESS_NTF,//3017
        EVENT_MACHINE_DOWNLOAD_NEW_VERSION_SPEED_NTF,//3018
        EVENT_MACHINE_DOWNLOAD_NEW_VERSION_ACK,//3019
        EVENT_MACHINE_QUERY_VALIDCODE_REQ,//3020
        EVENT_MACHINE_NETWORK_CHANGED,//3021
        EVENT_MACHINE_SHOW_USER_SELECTED,//3022
        EVENT_MACHINE_TIME_TERMINATE,//3023
        EVENT_MACHINE_TIME_TERMINATE_NTF,//3024
        EVENT_MACHINE_START_CLEAN_CMD,//3025
        EVENT_MACHINE_STOP_CLEAN_CMD,//3026
        EVENT_MACHINE_UIERROR_REG_CMD,//3027
        EVENT_MACHINE_LANGUAGE_CHANGED,//3028
        EVENT_MACHINE_POWER_STATUS_NTY,//3029
        EVENT_MACHINE_STATUS_QUERY,//3030
        EVENT_MACHINE_STATUS_QUERY_ACK,//3031
        EVENT_MACHINE_DEBUG_SERVER_REG,//3032
        EVENT_MACHINE_FATAL_TIMEOUT_CHECK,//3033
        EVENT_MACHINE_FATAL_UI_CHECK,//3034
        EVENT_MACHINE_PEEK_UI_CHECK,//3035
        EVENT_MACHINE_SET_TIMEELAPSE_UI,//3036
        EVENT_MACHINE_MAINUI_USER_SELECTED//3307
    };
    enum
    {
        EVENT_MACHINE_TEST_ALARM_ALL = 14200,
        EVENT_MACHINE_TEST_SET_BOX_L,//14201
        EVENT_MACHINE_TEST_SET_BOX_H,//14202
        EVENT_MACHINE_TEST_SET_BOX_T,//14203
        EVENT_MACHINE_TEST_SET_HCUP_L,//14204
        EVENT_MACHINE_TEST_SET_HCUP_H,//14205
        EVENT_MACHINE_TEST_SHOW_ERRORS,//14206
        EVENT_MACHINE_TEST_CLEAR_ERRORS,//14207
        EVENT_MACHINE_TEST_SHOW_STAT,//14208
        EVENT_MACHINE_TEST_OPEN_INB,//14209
        EVENT_MACHINE_TEST_SET_INB_T,//14210
        EVENT_MACHINE_TEST_SET_INB_L,//14211
        EVENT_MACHINE_TEST_SET_INB_H,//14212
        EVENT_MACHINE_TEST_SET_POWER_VALUE//14213
    };
    enum
    {
        MSG_DEST_ALL,//0
        MSG_DEST_CTRL,//1
        MSG_DEST_HTTP,//2
        MSG_DEST_UI,//3
        MSG_DEST_OWN,//4
        MSG_DEST_BT,//5
        MSG_DEST_NCM//6
    };
    enum
    {
        DAEMON = 0xfffe,
        EACH = 0xffff
    };
    enum
    {
        S1_OK = 0x01,
        S2_OK = 0x02
    };
    explicit zTemplateApp(QObject *parent = 0):QObject(parent)
    {
        powerstauts = 0x80;
        queRcv = queSnd = -1;
        i2c_powerfd = -1;
        readfd = -1;
        writefd = -1;
        for ( int i = 0 ;i < MAX_SERAIL_NUM;i++)
            appSerialFlags[i] = false;
        Instance = this;
        m_pcStatus = new CSerialStatusValue[MAX_SERAIL_NUM];
        timeSelect = new QTimeDateSelect(0);
        timeSelect->hide();
        appthread = new QThread;
        timer = new QTimer(this);
        timer->setInterval(1000);
        connect(timer,SIGNAL(timeout()),this,SLOT(timeout()),Qt::QueuedConnection);
        this->moveToThread(appthread);
    }
    virtual ~zTemplateApp()
    {
        if ( timer )
            delete timer;
        if ( m_pcStatus )
            delete []m_pcStatus;
    }
    static zTemplateApp* Get()
    {
        return Instance;
    }
    void Quit()
    {
        if ( appthread )
            appthread->quit();
    }
    void SndMsg(MsgAddr addr)
    {
        if ( queSnd )
            write(queSnd,&addr,sizeof(addr));
    }
    void run()
    {
        appthread->start();
    }
    static zTemplateApp* CreateApp(int Type);
    CSerialStatusValue* GetStatusValue(int n)
    {
        if ( m_pcStatus == NULL || n < 0 || n > 1 )
            return NULL;
        return &m_pcStatus[n];
    }
    virtual void OpenMsg() = 0;
    virtual void OpenCtrl(QString name) = 0;
    virtual void OpenPowerCtrl(QString name) = 0;
    virtual void SetTimer(int val) = 0;

    virtual int  Type() = 0;
    virtual QMedStateObject* GetObject(int num=0) = 0;
    QHash<int,QGPIOEntry*> ioInput;
    QHash<int,QGPIOEntry*> ioOutput;
    QTimeDateSelect* timeSelect;
private:
    static zTemplateApp* Instance;
    QThread*      appthread;
    CSerialStatusValue* m_pcStatus;
    bool         appSerialFlags[MAX_SERAIL_NUM];
public:
    friend class QMedStateObject;
    QTimer*   timer;
    int i2c_powerfd;
    int readfd;
    QFileSystemWatcher myWatcher;

    int writefd;
    int queRcv;
    int queSnd;
    int power_onstate;
    quint16  powerstauts;
    bool isSerialOK(int i)
    {
        if ( i < 0 || i >= MAX_SERAIL_NUM )
            return false;
        if(CommonParam::m_bTestMode)
            return true;
        return appSerialFlags[i];
    }
    void SetSerialOK(int i)
    {
        if ( i < 0 || i >= MAX_SERAIL_NUM )
            return;
        appSerialFlags[i] = true;
    }
    virtual void OnTimer() = 0;
    virtual int  GetObjectNum(void) = 0;
    virtual void DaemonRead1() = 0;
    virtual void DaemonMsgRead1() = 0;
    virtual void OnMessage1(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size) = 0;
    virtual void post(int dest,int destObj,int ev,quint32 p1=0,quint32 p2=0,quint8* buf=0,quint16 size=0) = 0;
public slots:
    virtual void DaemonRead()
    {
        DaemonRead1();
    }
    virtual void MessageRead()
    {
        DaemonMsgRead1();
    }

    virtual void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size)
    {
        OnMessage1(dest,ev,p1,p2,buf,size);
    }
    void timeout()
    {
        OnTimer();
    }
signals:
    void OnPostMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    void OnPostMessageHttp(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    void OnPostMessageCtrl(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    void OnPostMessageUI(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    void OnPostMessageNCM(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
};

void TemplatePost(int dest,int destObj,int ev,quint32 p1 = 0,quint32 p2 = 0,quint8* buf = 0,quint16 size = 0);

template <class I,int maxins=1,class A=QDummyClass>
class zTemplate:public zTemplateApp,public A
{
public:
    virtual QMedStateObject* GetObject(int num=0);
    virtual int  GetObjectNum(void);
    virtual void OpenCtrl(QString name);
    virtual void OpenMsg();
    virtual void OpenPowerCtrl(QString name);
    virtual void post(int dest,int destObj,int ev,quint32 p1=0,quint32 p2=0,quint8* buf=0,quint16 size=0);
    virtual int Type();
    virtual void SetTimer(int val);
private:
    I daemon;
    I objectArray[maxins];
    QSocketNotifier* ctrlNotifier;
    QSocketNotifier* ctrlMsgRead;

protected:
    virtual void OnTimer();
public:
    virtual void DaemonRead1();
    virtual void DaemonMsgRead1();
    virtual void OnMessage1(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
};

template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::SetTimer(int val)
{
    if ( timer )
    {
        if ( timer->isActive() )
            timer->stop();
        timer->setInterval(val);
    }
    timer->start();
}
template <class I,int maxins,class A>
int zTemplate<I,maxins,A>::GetObjectNum(void)
{
    return maxins;
}
template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::OnTimer()
{
    daemon.OnDaemonTimer(Get());
    for ( int i = 0 ;i<maxins;i++)
    {
        objectArray[i].OnTimer();
    }
    if ( timer && !timer->isActive() )
    {
        timer->start();
    }
}

template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::OnMessage1(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size)
{
    if ( dest == DAEMON )
    {
        daemon.OnDeamonMessage(ev,p1,p2,buf,size,Get());
    }
    else if ( dest == EACH )
    {
        for ( int i = 0 ;i<maxins;i++)
        {
            objectArray[i].OnMessage(ev,p1,p2,buf,size);
        }
    }
    else
    {
        if ( dest < 0 || dest >= maxins )
            return;
        objectArray[dest].OnMessage(ev,p1,p2,buf,size);
    }
    return;
}
template <class I,int maxins,class A>
int zTemplate<I,maxins,A>::Type()
{
    return daemon.Type();
}

template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::post(int dest,int destObj,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size)
{
    switch ( dest )
    {
    case MSG_DEST_ALL:
        break;
    case MSG_DEST_CTRL:
        emit OnPostMessageCtrl(destObj,ev,p1,p2,buf,size);
        break;
    case MSG_DEST_HTTP:
        emit OnPostMessageHttp(destObj,ev,p1,p2,buf,size);
        break;
    case MSG_DEST_UI:
        emit OnPostMessageUI(destObj,ev,p1,p2,buf,size);
        break;
    case MSG_DEST_NCM:
        emit OnPostMessageNCM(destObj,ev,p1,p2,buf,size);
        break;
    default:
        emit OnPostMessage(destObj,ev,p1,p2,buf,size);
        break;
    }
}

template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::OpenMsg()
{
    int fd[2];
    if ( pipe(fd) < 0 )
    {
        return;
    }
    queRcv = fd[0];
    queSnd = fd[1];
    ctrlMsgRead = new QSocketNotifier(queRcv,QSocketNotifier::Read,this);
    connect(ctrlMsgRead,SIGNAL(activated(int)),this,SLOT(MessageRead()));
}

template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::OpenCtrl(QString name)
{
    if(!CommonParam::m_bTestMode)//zhenshi
    {
        readfd = openttySRead((char*)name.toStdString().data());
        writefd = openttySWrite((char*)name.toStdString().data());
        CommonParam::m_iComRead=readfd;
        CommonParam::m_iComWrite=writefd;
        if(readfd>0)
            SetSerialOK(0);
        ctrlNotifier = new QSocketNotifier(readfd,QSocketNotifier::Read,this);
        connect(ctrlNotifier,SIGNAL(activated(int)),this,SLOT(DaemonRead()));
    }
    else
    {
        readfd = open("/AM/appdata/system/SerialR.dat",O_RDWR);
        writefd = open("/AM/appdata/system/SerialW.dat",O_RDWR);
        connect(&myWatcher, SIGNAL(fileChanged(QString)), this, SLOT(DaemonRead()));
        myWatcher.addPath("/AM/appdata/system/SerialR.dat");
    }

}

template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::DaemonMsgRead1()
{
    MsgAddr addr;
    if ( queRcv <= 3 )
        return;
    if ( read(queRcv,&addr,sizeof(addr)) == sizeof(addr) )
    {
        TemplateMsg* ptMsg = (TemplateMsg*)addr.addr;
        if ( ptMsg == NULL )
            return;
        post(ptMsg->dest,ptMsg->destObj,ptMsg->ev,ptMsg->p1,ptMsg->p2,ptMsg->buf,ptMsg->size);
        delete ptMsg;
    }
}

template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::DaemonRead1()
{
    daemon.OnDaemonRead(Get());
}

template <class I,int maxins,class A>
void zTemplate<I,maxins,A>::OpenPowerCtrl(QString name)
{
    if(!CommonParam::m_bTestMode)//todo
    {
        i2c_powerfd = openI2CFd((char*)name.toStdString().data());
        CommonParam::m_iI2CHandle=i2c_powerfd;
        if(-1 == i2c_powerfd)
        {
            LOG_DEBUG<<"open i2c error"<<errno;
        }
    }
    else
    {
        i2c_powerfd = open("/AM/appdata/system/I2C.dat",O_RDWR);
    }
}

template <class I,int maxins,class A>
QMedStateObject* zTemplate<I,maxins,A>::GetObject(int num)
{
    if ( num == DAEMON )
    {
        return &daemon;
    }
    if ( num < 0 || num >= maxins )
        return NULL;
    return &objectArray[num];
}

class QGPIOEntry
{
public:
    QGPIOEntry()
    {
        gpio = 0;
        defaultValue = 0;
        currentValue = -1;
    }

    QGPIOEntry(quint32 io,quint8 dValue,quint8 cValue,QString desc)
    {
        gpio = io;
        defaultValue = dValue;
        currentValue = cValue;
        description = desc;
    }
    ~QGPIOEntry()
    {
        description.clear();
    }
    quint8 GetDefault()
    {
        return defaultValue;
    }
    quint8 GetCurrent()
    {
        return currentValue;
    }
    void SetCurrent(quint8 val)
    {
        currentValue = val;
    }
    QString& GetDescription()
    {
        return description;
    }
    void SetDescription(QString desc)
    {
        description = desc;
    }
    quint32 gpio;
    quint8  defaultValue;
    quint8  currentValue;
    QString  description;
};


class QSeqCtrl
{
public:
    QSeqCtrl(quint32 Type,quint32 Sdelay,quint32 sPdelay)
    {
        seqType = Type;
        seqDelay = Sdelay;
        seqPerDelay = sPdelay;
    }
    ~QSeqCtrl()
    {
        m_listGpio.clear();
    }
    void AddSeq(int seq,QGPIOEntry* entry)
    {
        m_listGpio.insert(seq,entry);
    }
    QHash<int,QGPIOEntry*> m_listGpio;
    quint32 seqType;
    quint32 seqDelay;
    quint32 seqPerDelay;
};

//#define MAX_TANK_CHECK_LEVEL 5
#define MAX_TANK_CHECK_LEVEL2 2
#define PLAY_INTERVAL_SECOND 4
class QMed5StateMachine:public QMedStateObject
{
public:
    QMed5StateMachine(int CtrlNum = 0);
    virtual ~QMed5StateMachine();
    virtual bool capability(int cap);
    virtual void      OnDaemonTimer(zTemplateApp* app);
    virtual void      OnDaemonRead(zTemplateApp* app);
    virtual void      OnDeamonMessage(int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size,zTemplateApp* app);
    virtual void      OnTimer();
    virtual void      OnMessage(int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    virtual bool      PowerExchangedTime();
    virtual void      OnListTimer(int ev);
    virtual quint8    GetBoxStateH()
    {
        return fBoxLastStateH;
    }

    virtual quint8    GetBoxStateL()
    {
        return fBoxLastStateL;
    }
    virtual quint8    GetICupState()
    {
        return fICupLastState;
    }
    virtual quint8    GetHCupState()
    {
        return fHCupLastState;
    }
    virtual quint8    GetHCupState2()
    {
        return fHCupLastState2;
    }
    virtual quint8    GetQingShuiCupState()
    {
        return m_iQingShuiLevelState;
    }
    void ReadPowerVersion();
    static void* MyAddwaterThread(void *arg);
    void NotifyAddwater();
private:
    void              OnTestMessage(int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    void              DaemonInitGpio();//init gpio-table
    void              Start();
    void              Stop();
    void              OnTimerBreatheStart();
    void              OnTimerBreatheStop();
    void              StartAddWater();
    void              StopAddWater();
    void              StartMixing();
    bool              CheckMixing(size_t tNow);
    void              StopMixing();
    void              AddTimeOutError(int& error);

    bool              CheckWaterCanFeeded(int& errors);
    void              CheckTankWaterLevel();
    int               CheckTankStatus();
    int               CheckHCupWaterLevel();
    int               CheckQingShuiBeiLevel();
    int               CheckNebulizationWaterLevel();
    int               CheckNebulizationStatus();
    int               CheckErrors();
    void              ReportErrors(int currErrors);
    void              ReportState();
    void              WritePower(int val);
    void              CheckPowerError();
    void CheckMiddleAddWaterTimeOut();
    void CheckAddWaterTimeOut();
    int               currentErrors;
//    quint8            fTankWaterHighValuse[MAX_TANK_CHECK_LEVEL];
//    quint8            fTankWaterLowValuse[MAX_TANK_CHECK_LEVEL];
    quint8            fTankWaterCheckTimes;

    void              ResetNebulizationWaterStatis();
    quint8            fNebulizationWaterHighValuse[MAX_TANK_CHECK_LEVEL2];
    quint8            fNebulizationWaterLowValuse[MAX_TANK_CHECK_LEVEL2];
    quint8            fNebulizationWaterCheckTimes;


    quint8            fBoxLastStateH;
    quint8            fBoxLastStateL;
    quint8            fICupLastState;
    quint8            fHCupLastState;
    quint8            fHCupLastState2;
    quint8            m_iQingShuiLevelState;
    quint8            m_nCleanState;
    quint32           fPowerStatusTimes;
    quint32           m_dwCheckStatusTimes;
    TDeviceDefault    m_tDefault;
    TDevice           m_tDev;

    long long m_iPrevSecond;
    QString m_strPowerVersion;
    QDateTime m_startTime;
    QDateTime m_AddWaterTime;
    QDateTime m_stopTime;
    bool m_bStarted;
    pthread_t m_thread;
};

class QWaterIndictorUI;
class QMedCtrl:public QMainWindow
{
public:
    enum
    {
        BTN_PREVIOUS,
        BTN_NEXT,
        BTN_CHECKBOX,
        BTN_STATUS,
        BTN_LONGPRESS
    };
    enum
    {
        PIC_TYPE_PRE_NEXT,
        PIC_TYPE_HOME_NEXT
    };
    QMedCtrl(QWidget *parent=0, Qt::WindowFlags flags=0):QMainWindow(parent,flags),m_nAddUserFromStart(0)
    {
        status = status1 = NULL;
        m_bMainSelectUser=false;
    }
    ~QMedCtrl()
    {
    }
    virtual bool GetCheckState() = 0;
    virtual void restransLateAll() = 0;
    virtual void clearCheckedState(){}
    virtual void OnUIButtonChanged(int n,bool onoff,bool bPic,int nPicType,QString str) = 0;
    static QMedCtrl*    create(int nType,QWidget *parent=0, Qt::WindowFlags flags=0);
    static QMedCtrl*    Get()
    {
        return instance;
    }
    static void    ChangeButtonString(int n,bool onoff,bool bPic = false,int nPicType = 0,QString str = "")
    {
        if ( instance != NULL )
            instance->OnUIButtonChanged(n,onoff,bPic,nPicType,str);
    }
    static bool    CheckState()
    {
        if ( instance != NULL )
            return instance->GetCheckState();
        return false;
    }

    static void clearChecked()
    {
        if ( instance != NULL )
            instance->clearCheckedState();
    }

    void ClearUser()
    {
        memset(&m_tUser,0,sizeof(m_tUser));
    }
    TMedUser* GetUser()
    {
        return &m_tUser;
    }
    QWaterIndictorUI* GetIndictorUI(int id = 0)
    {
        if ( id ==0 )
            return status;
        else
            return status1;
    }
    void GetAddUserFrom(int& objid,int& val)
    {
        objid = (m_nAddUserFromStart>>16);
        val = (m_nAddUserFromStart&0xFFFF);
    }
    void SetAddUserFrom(int objid =0,int val = 0)
    {
        m_nAddUserFromStart = ((objid<<16)||val);
    }
    QString           m_zoneCode;
    QWaterIndictorUI* status;
    QWaterIndictorUI* status1;    
private:
    TMedUser          m_tUser;
    int               m_nAddUserFromStart;
public:
    bool m_bMainSelectUser;
protected:
    static QMedCtrl*    instance;
};

//测试校准
class QMedTouchCalibration:public QDialog
{
public:
    enum
    {
        TopLeft = 0,
        TopRight,
        BottomRight,
        BottomLeft,
        Center,
    };
    QMedTouchCalibration(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~QMedTouchCalibration();
protected:
    void paintEvent(QPaintEvent *paint);
    void mousePressEvent(QMouseEvent *mouse);
    void mouseReleaseEvent(QMouseEvent *mouse);
private:
    void   drawTarget(QPoint& center,int r,int nNum,QPainter& painter);
    QPoint points[Center+1];
    int    pressCount;
    int    nState;
};

//测试亮点
class QMedTouchColorTest:public QDialog
{
public:
    QMedTouchColorTest(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~QMedTouchColorTest();
protected:
    void paintEvent(QPaintEvent *paint);
    void mousePressEvent(QMouseEvent *);
private:
    int colorNum;
};

class MedCtrlCheckThread : public QThread
{
    Q_OBJECT
public:
    explicit MedCtrlCheckThread(QObject *parent = 0);
    ~MedCtrlCheckThread();

    void addCommand(MedctrlCheckCmd *cmd);

    virtual void run();

signals:
    void threadCheckErrorNotify(int);

private:
    bool m_bRunning;
    QList<MedctrlCheckCmd *> m_listCmd;

};


#endif // MEDCTRL_H
