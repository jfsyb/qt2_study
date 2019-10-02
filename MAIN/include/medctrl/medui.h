#ifndef MEDCTRL_7INCH_H
#define MEDCTRL_7INCH_H
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
#include <QTableWidget>
#include <QDialog>
#include <QTreeWidget>
#include <QTableView>
#include <QCheckBox>
#include "../medctrl_c/medctrl_c.h"
//#include "../medctrl_c/medctrl_dev_protocol.h"
#include "medmisc.h"
#include "medctrl.h"
#include <QTimer>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QProcess>

#define SETTABLABEL(LAB) \
    LAB->setStyleSheet(QString::fromUtf8("QLabel {color:green;text-align:center;font:16px;}"));

#define SETTABBTN(newButtn) \
    newButtn->setFocusPolicy(Qt::NoFocus);\
    newButtn->setStyleSheet(QString::fromUtf8("QPushButton {font:16px;color:blue;text-align:right;} QPushButton:hover { background: green;}"));

#define SETHOMESTYLE7H(BTN) \
    BTN->setStyleSheet(QString::fromUtf8("QToolButton{ border-image: url(:/seven/images/home-152.png);color: white;padding: 2px;} QToolButton:hover { border-image: url(:/seven/images/home-156.png);color: blue;padding: 2px;} QToolButton:pressed { border-image: url(:/seven/images/home-156.png);color: white;padding: 2px;}"));
#define SETCONFIRM(BTN) \
    BTN->setStyleSheet(QString::fromUtf8("QToolButton{ border-image: url(:/seven/images/confirm-156.png);color: white;padding: 2px;} QToolButton:hover { border-image: url(:/seven/images/confirm-156.png);color: blue;padding: 2px;} QToolButton:pressed { border-image: url(:/seven/images/confirm-156.png);color: white;padding: 2px;}"));
#define SETREDO(BTN) \
    BTN->setStyleSheet(QString::fromUtf8("QToolButton{ border-image: url(:/seven/images/redo-156.png);color: white;padding: 2px;} QToolButton:hover { border-image: url(:/seven/images/redo-156.png);color: blue;padding: 2px;} QToolButton:pressed { border-image: url(:/seven/images/redo-156.png);color: white;padding: 2px;}"));
#define RESEIZE7H resize(800,480);

const int LockScreenTimeSecond = 3;
class CMainUI :public CMessageNotify
{
    Q_OBJECT
public:
    CMainUI(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    virtual ~CMainUI();
    void retranslateUi(QWidget *Form);
    void Update(QString);
    bool OnPrevious();
    bool OnConfirm();
    void OnMessage(int,int,quint32,quint32,quint8*,quint16);
public slots:
    void poweroff_timeout();
    void wendu_timeout();
    void protected_timeout();
    void OnStop(int);
    void OffStop(int);

    void btnLockScreenPressed();
    void btnLockScreenReleased();
    void lockScreenTimeout();
    void configRefreshUI();
    void SelectUser();

protected:
    bool eventFilter(QObject *, QEvent *);
    void refreshClinicalMode();

signals:
    void powerOffStart(int);

public:
    QTimer*        poweroff_timer;
    QTimer*        m_pWendu;
    int            poweroffTimers;
    //    QVBoxLayout *verticalLayout;
    //    QGridLayout *gridLayout;
    QSliderHumidness *frame_lt;
    QTimeAdjust *frame_rt;
    QButtonInput *frame_lb;
    QSelectUser* m_pSelectUser;
    QStartStop *frame_rb;

    QPushButton *m_pBtnOffScreen;
    QTimer *m_pLockScreenTimer;

    int m_iLockScreenSecond;
    QPushButton* m_pLableTemperature;
    QPushButton* m_pTemperature;
    QPushButton* m_pLableWuhua;
    QPushButton* m_pLableSetTime;
    QPushButton* m_pLableChanqiliang;
    QPushButton* m_pLableQingYangNongDu;
    CKBEdit *m_pQingYangNongDu;
//    CKBEdit *m_pUserName;
    QPushButton* m_pLableUser;
//    QPushButton* m_pSelectUser;
    //    QLabel* m_pFenzhong;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("CMainUI"));


        m_pLableTemperature= new QPushButton(this);
        m_pLableTemperature->hide();
        QSize qs1(124*CommonParam::m_iWidth/800,49*CommonParam::m_iHeight/480);
        if(MedctrlConfManager::instance()->getCurrentConf()->getLanguage() == 2)
        {
            qs1.setWidth(160*CommonParam::m_iWidth/800);
        }

        m_pLableTemperature->resize(qs1);
        m_pLableTemperature->move(486*CommonParam::m_iWidth/800,90*CommonParam::m_iHeight/480);
        m_pLableTemperature->setText(tr("wendu"));
        m_pLableTemperature->setStyleSheet(CommonParam::m_sStyle1);


        m_pLableQingYangNongDu= new QPushButton(this);
        m_pLableQingYangNongDu->hide();
        m_pLableQingYangNongDu->resize(qs1);
        if(MedctrlConfManager::instance()->getCurrentConf()->getLanguage() == 3)
        {
            m_pLableQingYangNongDu->resize(124,49);
        }
        m_pLableQingYangNongDu->move(198*CommonParam::m_iWidth/800,277*CommonParam::m_iHeight/480);
        m_pLableQingYangNongDu->setText(tr("QingYangNongDu"));
        m_pLableQingYangNongDu->setStyleSheet(CommonParam::m_sStyle41);

        m_pQingYangNongDu=new CKBEdit(this);
        m_pQingYangNongDu->hide();
        m_pQingYangNongDu->resize(396,49);
        m_pQingYangNongDu->move(345,279);
        m_pQingYangNongDu->setStyleSheet(CommonParam::m_sStyle46);
        m_pQingYangNongDu->setText(tr("EditQingYangNongDu"));

//        m_pUserName=new CKBEdit(Form);
//        connect(m_pUserName,SIGNAL(clicked()),this,SLOT(SelectUser()));
//        //m_pUserName->hide();
//        m_pUserName->resize(141,49);
//        m_pUserName->setEnabled(false);
//        m_pUserName->move(409,279);
//        m_pUserName->setStyleSheet(CommonParam::m_sStyle16);
//        m_pUserName->setText("");

        m_pTemperature= new QPushButton(this);
        m_pTemperature->hide();
        m_pTemperature->resize(110,45);
        m_pTemperature->move(633*CommonParam::m_iWidth/800,90*CommonParam::m_iHeight/480);
//        m_pTemperature->setText("x");
        m_pTemperature->setStyleSheet(CommonParam::m_sStyle2);
        m_pLableWuhua= new QPushButton(this);

        m_pLableWuhua->resize(qs1);
        m_pLableWuhua->move(198*CommonParam::m_iWidth/800,152*CommonParam::m_iHeight/480);
        m_pLableWuhua->setText(tr("wuhualiang"));
        m_pLableWuhua->setStyleSheet(CommonParam::m_sStyle1);


        m_pLableSetTime= new QPushButton(this);

        m_pLableSetTime->resize(qs1);
        m_pLableSetTime->move(198*CommonParam::m_iWidth/800,89*CommonParam::m_iHeight/480);
        m_pLableSetTime->setText(tr("timesetting"));
        m_pLableSetTime->setStyleSheet(CommonParam::m_sStyle1);

        m_pLableChanqiliang= new QPushButton(this);

        m_pLableChanqiliang->resize(qs1);
        m_pLableChanqiliang->move(198*CommonParam::m_iWidth/800,216*CommonParam::m_iHeight/480);
        m_pLableChanqiliang->setText(tr("Chanqiliang"));
        m_pLableChanqiliang->setStyleSheet(CommonParam::m_sStyle1);
        if(MedctrlConfManager::instance()->getCurrentConf()->getLanguage() == 2)
        {
            m_pLableTemperature->move(486*CommonParam::m_iWidth/800,90*CommonParam::m_iHeight/480);
            m_pLableWuhua->move(198*CommonParam::m_iWidth/800,152*CommonParam::m_iHeight/480);
            m_pLableSetTime->move(198*CommonParam::m_iWidth/800,89*CommonParam::m_iHeight/480);
            m_pLableChanqiliang->move(198*CommonParam::m_iWidth/800,216*CommonParam::m_iHeight/480);
        }

        m_pLableUser= new QPushButton(this);

        m_pLableUser->resize(qs1);
        m_pLableUser->move(198*CommonParam::m_iWidth/800,281*CommonParam::m_iHeight/480);
        m_pLableUser->setText(tr("Select User"));
        m_pLableUser->setStyleSheet(CommonParam::m_sStyle1);

//        m_pSelectUser= new QPushButton(Form);
//        connect(m_pSelectUser,SIGNAL(clicked()),this,SLOT(SelectUser()));
//        m_pSelectUser->resize(54,50);
//        m_pSelectUser->move(348*CommonParam::m_iWidth/800,281*CommonParam::m_iHeight/480);
//        m_pSelectUser->setText("");
//        m_pSelectUser->setStyleSheet(CommonParam::m_sStyle45);


        //m_pFenzhong=new QLabel();
        //m_pFenzhong->resize(124,49);
        //m_pFenzhong->move(514,204);
        //m_pFenzhong->setText(tr("min"));
        //m_pFenzhong->setStyleSheet("font: 24px;"
        //                              "color: rgb(0, 0, 0);");

        //        verticalLayout = new QVBoxLayout(Form);
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_H)
        {
            //            verticalLayout->setContentsMargins(32, 10, 32,0);
            //            gridLayout = new QGridLayout();
            //            gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
            //            gridLayout->setSpacing(24);
            //            if (MedctrlConfManager::instance()->getCurrentConf()->getAECOPDMode())
            //            {
            //                frame_lt->setEnabled(false);
            //            }

            //            gridLayout->addWidget(frame_lt, 0, 0, 1, 1);


            //            gridLayout->addWidget(frame_rt, 0, 1, 1, 1);



            ////            gridLayout->addWidget(frame_lb, 1, 0, 1, 1);

            frame_rb = new QStartStop(Form);
            frame_rb->setObjectName(QString::fromUtf8("frame_rb"));
            frame_rb->move(281*CommonParam::m_iWidth/800,337*CommonParam::m_iHeight/480);
            //            gridLayout->addWidget(frame_rb, 1, 1, 1, 1);
            //            verticalLayout->addLayout(gridLayout);

//            m_pBtnOffScreen->setFixedHeight(60);


            frame_lt = new QSliderHumidness(Form);
            frame_lt->setObjectName(QString::fromUtf8("frame_lt"));

            frame_lb = new QButtonInput(Form);
            frame_lb->setObjectName(QString::fromUtf8("frame_lb"));

            m_pSelectUser= new QSelectUser(Form);
            m_pSelectUser->setObjectName(QString::fromUtf8("m_pSelectUser"));

            frame_rt = new QTimeAdjust(Form);
            frame_rt->setObjectName(QString::fromUtf8("frame_rt"));
        }
        else
        {

            if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH )
            {
                //                verticalLayout->setContentsMargins(12,24,12,0);
                //                verticalLayout->setSpacing(0);
//                m_pBtnOffScreen->setFixedHeight(50);
            }
            else
            {
                //                verticalLayout->setContentsMargins(24,24,24,0);
                //                verticalLayout->setSpacing(8);
//                m_pBtnOffScreen->setFixedHeight(55);
            }
            frame_lt = new QSliderHumidness(Form);
            frame_lt->setObjectName(QString::fromUtf8("frame_lt"));
            //            verticalLayout->addWidget(frame_lt);

            frame_lb = new QButtonInput(Form);
            frame_lb->setObjectName(QString::fromUtf8("frame_lb"));
            //            verticalLayout->addWidget(frame_lb);
            m_pSelectUser= new QSelectUser(Form);
            m_pSelectUser->setObjectName(QString::fromUtf8("m_pSelectUser"));

            frame_rt = new QTimeAdjust(Form);
            frame_rt->setObjectName(QString::fromUtf8("frame_rt"));
            //            verticalLayout->addWidget(frame_rt);

            frame_rb = new QStartStop(Form);
            frame_rb->setObjectName(QString::fromUtf8("frame_rb"));
            //            verticalLayout->addWidget(frame_rb);
        }
//        m_pBtnOffScreen = new QPushButton(Form);

//        m_pBtnOffScreen->resize(195*CommonParam::m_iWidth/800,48*CommonParam::m_iHeight/480);
//        m_pBtnOffScreen->setEnabled(true);
//        m_pBtnOffScreen->move(605*CommonParam::m_iWidth/800,418*CommonParam::m_iHeight/480);
//        m_pBtnOffScreen->setStyleSheet("border-image:url(:/seven/Nimage/changan.png);"
//                                       "font: 20px;"
//                                       "color: rgb(0, 0, 0);"
//                                       "outline: none;"
//                                       "border-style:solid;"
//                                       "border-width:1px;"
//                                       "border-radius:38px;"
//                                       );
        //        verticalLayout->addWidget(m_pBtnOffScreen, 0, Qt::AlignCenter);

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class TempWorkThread;

class CCenterWidget:public QWidget
{
    Q_OBJECT
public:
    explicit CCenterWidget(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    virtual  ~CCenterWidget();
    void retranslateUi(QWidget *Form);
    void InitStatus();
public slots:
    void OnMessageUI(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    void previous();
    void next();
    void ShowUI(QString name,QString param);
    void timeout();
    void threadCheckNotify(int);
    void powerOffAnimation(int);
    void TankTemperatureLow(int);
    void groundCheck(int);
    void aecopdUseGasUpdateDisplay(int);

signals:
    void ChangeBackGround(int n);
protected:
    void resizeEvent(QResizeEvent *);
public:
    QTimer*             ptTimer;
    int                 mainindex;
    QUserErrorUI*       errorUI;
    QUserStopCheckUI*   stopCheckUI;
    int                 currentBackGround;
    QMainCtrlButtonUI*  ctrlBtns;
    //    QVBoxLayout *       verticalLayout;
    QStackedWidget*     stackedWidget;
    QUserRunPoll        *m_pUserRunPoll;
    QLabel *m_pLbAecopdUseGas;
    QLabel *m_pBoxTemp;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("CCenterWidget"));

        m_pLbAecopdUseGas = new QLabel(this);
        m_pLbAecopdUseGas->hide();
        m_pBoxTemp =new QLabel(this);
        m_pBoxTemp->setStyleSheet("font:12px");
        m_pBoxTemp->move(0,0);
        //        m_pBoxTemp->setFixedSize(20, 20);
        //        m_pBoxTemp->setText("L");
        //        m_pBoxTemp->show();
        //        verticalLayout = new QVBoxLayout(Form);
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        //        verticalLayout->setContentsMargins(0, 0, 0, 0);
        //        verticalLayout->setSpacing(0);
        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
        //        verticalLayout->addWidget(stackedWidget);
        ctrlBtns = new QMainCtrlButtonUI(this);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi

private:
    bool m_iGuideFlag;
    MedCtrlCheckThread *m_pChkThread;
    TempWorkThread *m_pCheckTankThread;
};

class CMedCtrlUI: public QMedCtrl
{
    Q_OBJECT
public:
    explicit CMedCtrlUI(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    virtual  ~CMedCtrlUI();
    void     restransLateAll();
    void     OnUIButtonChanged(int n,bool onoff,bool bPic,int nType,QString str);
    bool     GetCheckState();
    void clearCheckedState();
protected:
    void resizeEvent(QResizeEvent *);

private:
    void changeWaterIndictorUISize();
private:
    QPixmap pix_handle1;
    QPixmap pix_handle2;
public slots:
    void OnBackground(int n);
private:
    CCenterWidget*  widget;
};

#endif //INCH7
