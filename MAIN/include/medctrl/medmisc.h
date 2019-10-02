#ifndef MEDCTRL_MISC_H
#define MEDCTRL_MISC_H

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
#include <QComboBox>
#include <QTableView>
#include <QTreeView>
#include <QProgressBar>
#include <QCheckBox>
#include <QStandardItemModel>
#include <QItemDelegate>
#include <QAbstractTableModel>
#include <QLabel>
#include <QSpacerItem>
#include <QPlainTextEdit>
#include <QSlider>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QSignalMapper>
#include <QStyleOptionSlider>
#include <QTreeWidgetItem>
#include <QToolButton>
#include <QListWidget>
#include <QRadioButton>
#include <QStatusBar>
#include <QToolBox>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTreeWidget>
#include <QCalendarWidget>
#include <QScrollBar>
#include "qrencode.h"
#include "../medctrl_c/medctrl_c.h"
#include "../include/medctrl/network-protocol/medhttp.h"
#include "../include/medctrl/medctrl.h"
#include "medkeyboard.h"
#include <QTouchEvent>
#include <QTimer>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include"commondefine.h"
#include "datetimeselectwidget.h"
#include "cmessagenotify.h"
#include "medctrlconfmanager.h"

class MedCtrlCalendarWidget : public QCalendarWidget
{
    Q_OBJECT
public:
    explicit MedCtrlCalendarWidget(QWidget *parent = 0);
    ~MedCtrlCalendarWidget();

protected:
    void showEvent(QShowEvent *);

private:
    void installSystemLanguage();

};


void InstallLanguage(int Lan);
void translatorLoad(int lang);
class QStateRcToolButton: public QToolButton
{
    Q_OBJECT
public:
    explicit QStateRcToolButton(QWidget *parent,int iconsize,int btnWidth,int btnHeight,int textsize);
    ~QStateRcToolButton();
    QRect _iconrect;
    QRect _textrect;
    QString text;
    QString rcText;
    QColor  textColor;
    QColor  textCheckColor;
    bool    _bSkipped;
    bool    fSkippOff;
    bool    _bHover;
    bool    _bPress;
    void SetSkipOff(bool b)
    {
        fSkippOff = b;
    }

    void SetDrawText(QString t)
    {
        text = t;
    }
    void SetSkip(bool bSkip,QColor clr)
    {
        _bSkipped = bSkip;
        textColor = clr;
    }
signals:
    void mouseOn();
    void mouseOff();
protected:
    void leaveEvent(QEvent *event);
    void enterEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    bool isHover();
};

class QMouseToolButton: public QToolButton
{
    Q_OBJECT
public:
    explicit QMouseToolButton(QWidget *parent=0):QToolButton(parent),fromId(0)
    {

    }
    virtual ~QMouseToolButton()
    {

    }
    void setControlId(int id)
    {
        fromId = id;
    }
signals:
    void mouseOn(int);
    void mouseOff(int);
protected:
    void mousePressEvent(QMouseEvent *e)
    {
        QToolButton::mousePressEvent(e);
        emit mouseOn(fromId);
    }
    void mouseReleaseEvent(QMouseEvent *e)
    {
        QToolButton::mouseReleaseEvent(e);
        emit mouseOff(fromId);
    }
private:
    int fromId;
};

const int LogoFixedSize = 80;

class QRWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QRWidget(QWidget *parent = 0);
    ~QRWidget();

    void setString(QString str);
    int getQRWidth() const;
    bool saveImage(QString name, int size);
    void setLogo(const QPixmap &pixmap);

protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

private:
    void draw(QPainter &painter, int width, int height);
    QString m_strData;
    QRcode *m_pQrcode;
    QPixmap m_pixmapLogo;

};

class QRoundProgressBar:public QWidget
{
    Q_OBJECT
Q_SIGNALS:
    void timeFinished();
public:
    explicit QRoundProgressBar(QWidget *parent = 0);

    double nullPosition() const { return m_nullPosition; }
    void setNullPosition(double position);
    enum BarStyle
    {
        /// Donut style (filled torus around the text)
        StyleDonut,
        /// Pie style (filled pie segment with the text in center)
        StylePie,
        /// Line style (thin round line around the text)
        StyleLine
    };
    void setBarStyle(BarStyle style);
    BarStyle barStyle() const { return m_barStyle; }
    void setOutlinePenWidth(double penWidth);
    double outlinePenWidth() const { return m_outlinePenWidth; }
    void setDataPenWidth(double penWidth);
    double dataPenWidth() const { return m_dataPenWidth; }
    void setDataColors(const QGradientStops& stopPoints);
    void setFormat(const QString& format);
    void resetFormat();
    QString	format() const { return m_format; }
    void setDecimals(int count);
    int decimals() const { return m_decimals; }
    double value() const { return m_tvalue; }
    double minimum() const { return m_min; }
    double maximum() const { return m_max; }
    void setChangeValue(bool b)
    {
        timer_mod_text = b;
    }

    void startCounter()
    {
        if ( ptTimer->isActive() )
            return;
        ptTimer->start();
    }
    void stopCounter()
    {
        if ( ptTimer->isActive() )
            ptTimer->stop();
    }
public Q_SLOTS:
    void setRange(double min, double max);
    void setMinimum(double min);
    void setMaximum(double max);
    void setValue(double val);
    void setValue(int val);
    void timeout();
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void drawBackground(QPainter& p, const QRectF& baseRect);
    virtual void drawBase(QPainter& p, const QRectF& baseRect);
    virtual void drawValue(QPainter& p, const QRectF& baseRect, double value, double arcLength);
    virtual void calculateInnerRect(const QRectF& baseRect, double outerRadius, QRectF& innerRect, double& innerRadius);
    virtual void drawInnerBackground(QPainter& p, const QRectF& innerRect);
    virtual void drawText(QPainter& p, const QRectF& innerRect, double innerRadius, double value);
    virtual QString valueToText(double value) const;
    virtual void valueFormatChanged();

    virtual QSize minimumSizeHint() const { return QSize(32,32); }

    virtual bool hasHeightForWidth() const { return true; }
    virtual int heightForWidth(int w) const { return w; }

    void rebuildDataBrushIfNeeded();

    int    m_min, m_max;
    int    m_value1;
    double m_tvalue;

    double m_nullPosition;
    BarStyle m_barStyle;
    double m_outlinePenWidth, m_dataPenWidth;

    QGradientStops m_gradientData;
    bool m_rebuildBrush;

    QString m_format;
    int m_decimals;
    QTimer* ptTimer;
    bool timer_mod_text;
    static const int UF_VALUE = 1;
    static const int UF_PERCENT = 2;
    static const int UF_MAX = 4;
    int m_updateFlags;
};

class QSwitchMenu:public QWidget
{
    Q_OBJECT
public:
    explicit QSwitchMenu(QWidget *parent = 0);
    ~QSwitchMenu();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:
    void StateChange(bool nState);
public:
    void initialize(const QString&, const QString&);
    void SetState(int stat);
    bool GetState();
private:
    QPixmap*    m_pixmapBk;
    QPixmap*    m_pixmapFore;
    bool        m_bOn;
    bool        m_bPicLoaded;
    bool        m_bLBtnDown;
};

class QLabelSwicthInput:public QWidget
{
    Q_OBJECT
public:
    explicit QLabelSwicthInput(QWidget *parent=0, Qt::WindowFlags flags=0);
    ~QLabelSwicthInput();
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSwitchMenu *onoff;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QLabelSwicthInput"));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setSpacing(0);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);
        horizontalLayout->addWidget(label);
        onoff = new QSwitchMenu(Form);
        onoff->setObjectName(QString::fromUtf8("onoff"));

        horizontalLayout->addWidget(onoff);
        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        QMetaObject::connectSlotsByName(Form);
    }
};
//for standard main gui control

class ClickableSlider : public QSlider
{
    Q_OBJECT
public:
    explicit ClickableSlider(QWidget *parent = 0) : QSlider(parent)
    {
        //setAutoFillBackground(false);
    }
signals:
    void mousebegin();
    void mouseend();
protected:
    void mouseReleaseEvent(QMouseEvent *event)
    {
        Q_UNUSED(event)
        emit mouseend();
    }

    void mousePressEvent(QMouseEvent *event)
    {
        QStyleOptionSlider opt;
        emit mousebegin();
        initStyleOption(&opt);
        QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle,this);
        if ( event->button() == Qt::LeftButton &&
             !sr.contains(event->pos()) ) {
            int newVal;
            if (orientation() == Qt::Vertical) {
                double halfHandleHeight = (0.5 * sr.height()) + 0.5;
                int adaptedPosY = height() - event->y();
                if ( adaptedPosY < halfHandleHeight )
                    adaptedPosY = halfHandleHeight;
                if ( adaptedPosY > height() - halfHandleHeight )
                    adaptedPosY = height() - halfHandleHeight;
                double newHeight = (height() - halfHandleHeight) - halfHandleHeight;
                double normalizedPosition = (adaptedPosY - halfHandleHeight)  / newHeight ;

                newVal = minimum() + (maximum()-minimum()) * normalizedPosition;
            } else {
                double halfHandleWidth = (0.5 * sr.width()) + 0.5;
                int adaptedPosX = event->x();
                if ( adaptedPosX < halfHandleWidth )
                    adaptedPosX = halfHandleWidth;
                if ( adaptedPosX > width() - halfHandleWidth )
                    adaptedPosX = width() - halfHandleWidth;
                double newWidth = (width() - halfHandleWidth) - halfHandleWidth;
                double normalizedPosition = (adaptedPosX - halfHandleWidth)  / newWidth ;

                newVal = minimum() + ((maximum()-minimum()) * normalizedPosition);
            }

            if (invertedAppearance())
            {
                setValue( maximum() - newVal );
                emit valueChanged(maximum() - newVal);
            }
            else
            {   setValue(newVal);
                emit valueChanged(newVal);
            }
            event->accept();
        } else {
            QSlider::mousePressEvent(event);
        }
    }
};
class MyMessageBox : public QDialog
{
public:
    explicit MyMessageBox(QWidget *parent = 0, Qt::WindowFlags f = 0)
    {
        v_layout=new QVBoxLayout(this);
        v_layout->addWidget(&m_info);
        m_info.setAlignment(Qt::AlignCenter);
        m_info.setWordWrap(true);
    }
    ~MyMessageBox()
    {
        delete v_layout;
        v_layout=NULL;
    }

    void setText(QString str)
    {
        m_info.setText(str);
    }
protected:
    void showEvent(QShowEvent* event)

    {
        QDialog::showEvent(event);
        setFixedSize(404*CommonParam::m_iWidth/800,245*CommonParam::m_iHeight/480);
    }
    //    void paintEvent(QPaintEvent *event)
    //    {
    ////        m_info.show();
    ////                QPainter paint(this);
    ////                paint.drawText(100,100,40,40,Qt::AlignVCenter|Qt::AlignHCenter,"hello");
    //    }
private:
    QLabel m_info;
    QVBoxLayout* v_layout;
};
class QSliderHumidness: public QWidget
{
    Q_OBJECT
public:
    explicit QSliderHumidness(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    virtual ~QSliderHumidness();
    void setValue(int nVal);
    void retranslateUi(QWidget *Form);
    void setControlId(int id)
    {
        machineNum = id;
    }
signals:
    void valueChange(int val);
protected:
    //    void resizeEvent(QResizeEvent* ev);
    //    void mousePressEvent(QMouseEvent *event);
    //    void mouseMoveEvent(QMouseEvent *event);
    //    void mouseReleaseEvent(QMouseEvent *event);
public slots:
    void clicked_btn(int);
    void clickedJian();
    void clickedJia();
    void clicked_progress(int);
    void sliderMouseRelease();
    void StateChange(bool bOnOff);
    void slotHideFinishedLabel();
private:
    int  btnGaps;
    int  mouseMove;
    int  start_pos;
    int  machineNum;
    int iSliderValue;

    //    QSignalMapper* signalMapper;
    //    QVBoxLayout* v_layout;
    QToolButton* horizontalSlider;
    QToolButton* horizontalSliderJian;
    QToolButton* horizontalSliderJia;
    //    QHBoxLayout *horizontalLayout;
    //    QPushButton *p1;
    //    QPushButton *p2;
    //    QPushButton *p3;
    //    QPushButton *p4;
    //    QPushButton *p5;
    //    QPushButton *p6;
    //    QPushButton *p7;
    //    QPushButton *p8;
    //    QPushButton *p9;
    //    QPushButton *p10;
    //    QList<QPushButton*> progressBtns;
    //    QLabel*      label;
    //    QSwitchMenu *onoff;

    MyMessageBox* m_pMsglabel;

    void setupUi(QWidget* Form)
    {
        m_pMsglabel=new MyMessageBox(this);
        m_pMsglabel->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        //        m_pMsglabel->setStandardButtons(0);
        m_pMsglabel->setStyleSheet("QDialog{color: white; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(244, 243, 241, 255), stop:1 rgba(233, 229, 226, 255)); border: 10px; border-radius: 20px;}"
                                   "QLabel{color: black;font: 32px;}"
                                   "QPushButton{color: white; border-radius: 15px; width: 80px; border: 0px solid;}"
                                   "QPushButton:focus{padding: -1;}");
        m_pMsglabel->setText(tr("Please pay attention to the atomizer level"));

        m_pMsglabel->hide();
        if ( Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QSliderHydrogen"));
        //        v_layout = new QVBoxLayout(Form);
        //        v_layout->setContentsMargins(0, 0, 0, 12);
        //        v_layout->setSpacing(0);
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH )
        {
            //            onoff = new QSwitchMenu(Form);
            //            onoff->setObjectName(QString::fromUtf8("onoff"));
            //            v_layout->addWidget(onoff);
        }
        else
        {
            horizontalSlider = new QToolButton(this);
            horizontalSliderJian = new QToolButton(this);
            horizontalSliderJia = new QToolButton(this);
            //设置最小值、最大值
//            horizontalSlider->setMinimum(0);
//            horizontalSlider->setMaximum(8);

//            bool b=horizontalSlider->isEnabled();
//            //设置初始值
//            horizontalSlider->setValue(0);
//            //            horizontalSlider->setEnabled(true);
//            horizontalSlider->setPageStep(1);




            //            horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
            //            horizontalSlider->setMaximum(10);
            //            horizontalSlider->setPageStep(1);
            //            horizontalSlider->setOrientation(Qt::Horizontal);
            //            horizontalLayout = new QHBoxLayout();
            //            horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
            //            horizontalLayout->setContentsMargins(6, 0, 6, 0);
            //            p1 = new QPushButton(Form);
            //            p1->setObjectName(QString::fromUtf8("p1"));
            ////            horizontalLayout->addWidget(p1, 0, Qt::AlignBottom);
            //            p2 = new QPushButton(Form);
            //            p2->setObjectName(QString::fromUtf8("p2"));
            ////            horizontalLayout->addWidget(p2, 0, Qt::AlignBottom);
            //            p3 = new QPushButton(Form);
            //            p3->setObjectName(QString::fromUtf8("p3"));
            ////            horizontalLayout->addWidget(p3, 0, Qt::AlignBottom);
            //            p4 = new QPushButton(Form);
            //            p4->setObjectName(QString::fromUtf8("p4"));
            ////            horizontalLayout->addWidget(p4, 0, Qt::AlignBottom);
            //            p5 = new QPushButton(Form);
            //            p5->setObjectName(QString::fromUtf8("p5"));
            ////            horizontalLayout->addWidget(p5, 0, Qt::AlignBottom);
            //            p6 = new QPushButton(Form);
            //            p6->setObjectName(QString::fromUtf8("p6"));
            ////            horizontalLayout->addWidget(p6, 0, Qt::AlignBottom);
            //            p7 = new QPushButton(Form);
            //            p7->setObjectName(QString::fromUtf8("p7"));
            ////            horizontalLayout->addWidget(p7, 0, Qt::AlignBottom);
            //            p8 = new QPushButton(Form);
            //            p8->setObjectName(QString::fromUtf8("p8"));
            ////            horizontalLayout->addWidget(p8, 0, Qt::AlignBottom);
            //            p9 = new QPushButton(Form);
            //            p9->setObjectName(QString::fromUtf8("p9"));
            ////            horizontalLayout->addWidget(p9, 0, Qt::AlignBottom);
            //            p10 = new QPushButton(Form);
            //            p10->setObjectName(QString::fromUtf8("p10"));
            ////            horizontalLayout->addWidget(p10, 0, Qt::AlignBottom);
            ////            v_layout->addLayout(horizontalLayout);
            ////            v_layout->addWidget(horizontalSlider);
            //            progressBtns.append(p1);
            //            progressBtns.append(p2);
            //            progressBtns.append(p3);
            //            progressBtns.append(p4);
            //            progressBtns.append(p5);
            //            progressBtns.append(p6);
            //            progressBtns.append(p7);
            //            progressBtns.append(p8);
            //            progressBtns.append(p9);
            //            progressBtns.append(p10);
            //            signalMapper = new QSignalMapper(this);
            //            for (int i= 0; i < progressBtns.count();i++)
            //            {
            //                progressBtns.at(i)->setCheckable(true);
            //                connect(progressBtns.at(i),SIGNAL(clicked()),signalMapper,SLOT(map()));
            //                signalMapper->setMapping(progressBtns.at(i),i);
            //                QObject::connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(clicked_btn(int)));
            //            }
        }
        //        label = new QLabel(this);
        //        label->setObjectName(QString::fromUtf8("label"));
        //        label->setAlignment(Qt::AlignCenter);
        //        v_layout->addWidget(label);
        retranslateUi(this);
        QMetaObject::connectSlotsByName(this);
    }
};

class QHydrogenLabel:public QLabel
{
    Q_OBJECT
public:
    explicit QHydrogenLabel(QWidget *parent = 0, Qt::WindowFlags flags = 0):QLabel(parent)
    {
        Q_UNUSED(flags)
        setAutoFillBackground(false);
        setMouseTracking(true);
    }
    ~QHydrogenLabel() {}
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event)
    {
        Q_UNUSED(event)
        emit clicked();
    }
};
//medctrl -platform linuxfb -plugin evdevtouch:/dev/input/event0 2> /dev/null > /dev/null
const int UseEndHintTime = 10*1000;//10s
class QTimeAdjust:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QTimeAdjust(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~QTimeAdjust();
public:
    unsigned& time()
    {
        return current_time;
    }
    void setTime(int Time);
    void startUI(bool start);
    void startCounts(bool bStart = true);//开始或者停止
    unsigned& timeSec()
    {
        return current_time_seconds;
    }
    void setControlId(int id)
    {
        machineNum = id;
    }
    void zeroCounterNum()
    {
        current_time_elapsed = 0;
    }
    void CheckState(quint8 state);

private:
    unsigned current_time;
    unsigned current_time_seconds;
    unsigned current_time_elapsed;
    unsigned machineNum;
    QTimer*  counterTimer;
public slots:
    void btn_timeDecrease();
    void btn_timeIncrease();
    void timerCounterElapsed();
public:
    //    QVBoxLayout *verticalLayout;
    //    QSpacerItem *spacerItem;
    //    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_del;
    QLabel *label;
    QLabel *label2;
    QToolButton *toolButton_add;
    //    QLabel *label_time;
    QMessageBox *m_pMsgBox;
    QTimer *timerClose;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QTimeAdjust"));
        //        verticalLayout = new QVBoxLayout(Form);
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        //        verticalLayout->setContentsMargins(0,0,0,0);
        //        verticalLayout->setSpacing(0);
        //        spacerItem = new QSpacerItem(4, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);
        //        verticalLayout->addItem(spacerItem);
        //        horizontalLayout = new QHBoxLayout();
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        horizontalLayout->setContentsMargins(0,0,0,0);
        //        horizontalLayout->setSpacing(0);
        toolButton_del = new QToolButton(Form);

        //        horizontalLayout->addWidget(toolButton_del);
        label = new QLabel(Form);

        label2 = new QLabel(Form);

        //        label->setAlignment(Qt::AlignCenter);

        //        horizontalLayout->addWidget(label);
        toolButton_add = new QToolButton(Form);

        //        horizontalLayout->addWidget(toolButton_add);

        //        horizontalLayout->setStretch(0, 1);
        //        horizontalLayout->setStretch(1, 2);
        //        horizontalLayout->setStretch(2, 1);
        //        verticalLayout->addLayout(horizontalLayout);
        //        label_time = new QLabel(Form);
        //        label_time->setObjectName(QString::fromUtf8("label_time"));
        //        label_time->setAlignment(Qt::AlignCenter);
        //        verticalLayout->addWidget(label_time,0,Qt::AlignBottom);

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }//setupUi
};

class QStartStop:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QStartStop(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~QStartStop();
public slots:
    void btn_start();
    void btn_pause();
    void btn_onshut(int);
    void btn_offshut(int);
signals:
    void onshut();
    void offshut();
public:
    enum
    {
        STYLE_PAUSE,//只有暂停
        STYLE_NORMAL//开始暂停
    };
    enum
    {
        BTN_TYPE_START,
        BTN_TYPE_STOP,
        BTN_TYPE_SHUTDOWN
    };
    void CheckState(quint8 state);
    void StateChange(bool bStart=true);
    void retranslateUi(QWidget* Form);
public:
    //    QHBoxLayout *horizontalLayout;
    QPushButton *toolButton_start;
    QToolButton *toolButton_pause;
    //    QToolButton *tbRepair;
    QMouseToolButton *toolButton_stop;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QStartStop"));
        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        horizontalLayout->setContentsMargins(16, 0, 16, 0);

        toolButton_start = new QPushButton(Form);

        toolButton_pause = new QToolButton(Form);


        toolButton_stop = new QMouseToolButton(Form);

        //        if(MedctrlConfManager::instance()->getCurrentConf()->getLanguage() == 2)
        //        {
        //            toolButton_start->resize(200*CommonParam::m_iWidth/800,71*CommonParam::m_iHeight/480);
        //            toolButton_stop->resize(200*CommonParam::m_iWidth/800,71*CommonParam::m_iHeight/480);
        //        }
        //        horizontalLayout->addWidget(toolButton_stop);

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }
};

class CBarCtrl : public QToolButton
{
    Q_OBJECT
public:
    explicit CBarCtrl(QString val,QWidget *parent = 0 );
    ~CBarCtrl();
    QSize sizeHint() const;
    void setSelected(bool b)
    {
        mSelect = b;
    }

signals:
    void BarClicked();
protected:
    bool mSelect;
    QString mVal;
    void paintEvent(QPaintEvent* ev);
};
class MyPushButton:public QWidget
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent=0);
    ~MyPushButton();
    void hide();
    void show();
    QToolButton* m_BackImg;
    QToolButton* m_userName;
    //void ButtonPressed();
public slots:
    void OnBtnClicked();
    void OnBtnReleased();
signals:
    void pressed();
    void released();
};
//产气量设置
class QButtonHydrogen:public QWidget
{
    Q_OBJECT
public:
    explicit QButtonHydrogen(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~QButtonHydrogen();
    void setValue(int val);
    void setControlId(int id)
    {
        machineNum = id;
    }
private:
    QSignalMapper* signalMapper;
public slots:
    void clicked_btn(int val);
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_text;
    QHydrogenLabel *label_l;
    QHydrogenLabel *label_m;
    QHydrogenLabel *label_h;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_btn;
    QPushButton *pushButton_l;
    QPushButton *pushButton_m;
    QPushButton *pushButton_h;
    QLabel      *label;
    unsigned     machineNum;
    void         retranslateUi(QWidget *Form);

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QButtonHydrogen"));
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_text = new QHBoxLayout();
        horizontalLayout_text->setObjectName(QString::fromUtf8("horizontalLayout_text"));
        horizontalLayout_text->setContentsMargins(0,0, 0, 0);
        label_l = new QHydrogenLabel(Form);
        label_l->setObjectName(QString::fromUtf8("label_l"));
        label_l->setAlignment(Qt::AlignCenter);
        horizontalLayout_text->addWidget(label_l);
        label_m = new QHydrogenLabel(Form);
        label_m->setObjectName(QString::fromUtf8("label_m"));
        label_m->setAlignment(Qt::AlignCenter);
        horizontalLayout_text->addWidget(label_m);
        label_h = new QHydrogenLabel(Form);
        label_h->setObjectName(QString::fromUtf8("label_h"));
        label_h->setAlignment(Qt::AlignCenter);
        horizontalLayout_text->addWidget(label_h);
        verticalLayout->addLayout(horizontalLayout_text);
        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_btn = new QHBoxLayout(frame);
        horizontalLayout_btn->setObjectName(QString::fromUtf8("horizontalLayout_btn"));
        horizontalLayout_btn->setContentsMargins(0, 0, 0, 0);
        pushButton_l = new QPushButton(frame);
        pushButton_l->setObjectName(QString::fromUtf8("pushButton_l"));
        horizontalLayout_btn->addWidget(pushButton_l);
        pushButton_m = new QPushButton(frame);
        pushButton_m->setObjectName(QString::fromUtf8("pushButton_m"));
        horizontalLayout_btn->addWidget(pushButton_m);
        pushButton_h = new QPushButton(frame);
        pushButton_h->setObjectName(QString::fromUtf8("pushButton_h"));
        horizontalLayout_btn->addWidget(pushButton_h);
        frame->setLayout(horizontalLayout_btn);
        verticalLayout->addWidget(frame);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        verticalLayout->addWidget(label);
        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        setLayout(verticalLayout);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};
class MyQPushButton : public QPushButton
{
public:
    explicit MyQPushButton(const QString &text, QWidget *parent=0):QPushButton( parent )
    {
        setText(text);
        m_bSelected=false;
    }
    void setSelected(bool bselected)
    {
        m_bSelected=bselected;
        if(bselected)
        {
            setStyleSheet("border-image:url(:/seven/Nimage/chanqi.png);"
                          "font: 28px;"
                          "color: rgb(7, 104, 157);"
                          "outline: none;"
                          "border-style:solid;"
                          "border-width:1px;"
                          "border-radius:38px;");
        }
        else
        {
            setStyleSheet("border-image:url(:/seven/Nimage/chanqi.png);"
                          "font: 28px;"
                          "color: rgb(0, 0, 0);"
                          "outline: none;"
                          "border-style:solid;"
                          "border-width:1px;"
                          "border-radius:38px;");
        }
    }
    bool IsSelected()
    {
        return m_bSelected;
    }
private:
    bool m_bSelected;
};
class QButtonInput:public QWidget
{
    Q_OBJECT
public:
    explicit QButtonInput(QWidget *parent=0, Qt::WindowFlags flags=0);
    ~QButtonInput();
    void SetInput(int val);
private slots:
    void Low();
    void Mid();
    void High();
public:
    //    QVBoxLayout *verticalLayout;
    //    QHBoxLayout *horizontalLayout;

    MyQPushButton *bar_l;
    MyQPushButton *bar_m;
    MyQPushButton *bar_h;
    //    QLabel *label;
    unsigned machineNum;
    void setControlId(int id)
    {
        machineNum = id;
    }
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QButtonInput"));
        //        verticalLayout = new QVBoxLayout(Form);
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        //        verticalLayout->setContentsMargins(0, 0, 0, 0);
        //        horizontalLayout = new QHBoxLayout();
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //
        switch ( CommonParam::currentMachineType() )
        {
        case MACHINE_TYPE_4INCH:
            //            if(MedctrlConfManager::instance()->getCurrentConf()->getInch4Low())
            //            {
            //                bar_l = new MyQPushButton("2.0L",Form);
            //                bar_l->setObjectName(QString::fromUtf8("QButtonInput-bar_l"));
            //                //                horizontalLayout->addWidget(bar_l);
            //                bar_m = new MyQPushButton("4.0L",Form);
            //                bar_m->setObjectName(QString::fromUtf8("QButtonInput-bar_m"));
            //                //                horizontalLayout->addWidget(bar_m);
            //                bar_h = new MyQPushButton("6.0L",Form);
            //                bar_h->setObjectName(QString::fromUtf8("QButtonInput-bar_h"));
            //                //                horizontalLayout->addWidget(bar_h);
            //            }
            //            else
            //            {
            //                bar_l = new QPushButton("0.4L",Form);
            //                bar_l->setObjectName(QString::fromUtf8("QButtonInput-bar_l"));
            //                //                horizontalLayout->addWidget(bar_l);
            //                bar_m = new QPushButton("0.5L",Form);
            //                bar_m->setObjectName(QString::fromUtf8("QButtonInput-bar_m"));
            //                //                horizontalLayout->addWidget(bar_m);
            //                bar_h = new QPushButton("0.6L",Form);
            //                bar_h->setObjectName(QString::fromUtf8("QButtonInput-bar_h"));
            //                //                horizontalLayout->addWidget(bar_h);
            //            }
            break;
        case MACHINE_TYPE_5INCH_H:
        case MACHINE_TYPE_5INCH_V:
            //            //bar_l = new CBarCtrl("1.0L",Form);
            //            //bar_l->setObjectName(QString::fromUtf8("QButtonInput-bar_l"));
            //            //horizontalLayout->addWidget(bar_l);
            //            bar_h = new QPushButton("1.5L",Form);
            //            bar_h->setObjectName(QString::fromUtf8("QButtonInput-bar_m"));
            //            //            horizontalLayout->addWidget(bar_h);
            //            //            setStyleSheet("QButtonInput QToolButton{font:28px;}");
            break;
        default:
            bar_l = new MyQPushButton("2.0L",Form);

            bar_l->setObjectName(QString::fromUtf8("QButtonInput-bar_l"));
            //            horizontalLayout->addWidget(bar_l);

            bar_m = new MyQPushButton("2.5L",Form);

            bar_m->setObjectName(QString::fromUtf8("QButtonInput-bar_m"));
            //            horizontalLayout->addWidget(bar_m);

            bar_h = new MyQPushButton("3.0L",Form);

            bar_h->setObjectName(QString::fromUtf8("QButtonInput-bar_h"));
            //            horizontalLayout->addWidget(bar_h);
            break;
        }
        //        verticalLayout->addLayout(horizontalLayout);
        //        label = new QLabel(Form);
        //        label->setObjectName(QString::fromUtf8("QButtonInput-label"));
        //        label->setAlignment(Qt::AlignCenter);
        //        verticalLayout->addWidget(label);
        //        verticalLayout->setStretch(0, 3);
        //        verticalLayout->setStretch(1, 1);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};
class QSelectUser:public QWidget
{
    Q_OBJECT
public:
    explicit QSelectUser(QWidget *parent=0, Qt::WindowFlags flags=0);
    ~QSelectUser();
private slots:
    void SelectUser();
public:
    //    QVBoxLayout *verticalLayout;
    //    QHBoxLayout *horizontalLayout;

    CKBEdit *m_pUserName;
    QPushButton* m_pButtonSelectUser;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QButtonInput"));
        //        verticalLayout = new QVBoxLayout(Form);
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        //        verticalLayout->setContentsMargins(0, 0, 0, 0);
        //        horizontalLayout = new QHBoxLayout();
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //
        m_pUserName=new CKBEdit(Form);
        connect(m_pUserName,SIGNAL(clicked()),this,SLOT(SelectUser()));
        //m_pUserName->hide();
        m_pUserName->resize(141,49);
        m_pUserName->setEnabled(false);
        m_pUserName->move(409,279);
        m_pUserName->setStyleSheet(CommonParam::m_sStyle16);
        m_pUserName->setText("");

        m_pButtonSelectUser= new QPushButton(Form);
        connect(m_pButtonSelectUser,SIGNAL(clicked()),this,SLOT(SelectUser()));
        m_pButtonSelectUser->resize(54,50);
        m_pButtonSelectUser->move(348*CommonParam::m_iWidth/800,281*CommonParam::m_iHeight/480);
        m_pButtonSelectUser->setText("");
        m_pButtonSelectUser->setStyleSheet(CommonParam::m_sStyle45);

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QLabelLineInput:public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent* ev);
public:
    explicit QLabelLineInput(QWidget *parent=0, Qt::WindowFlags flags=0);
    ~QLabelLineInput();
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    CKBEdit *lineEdit;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QLabelLineInput"));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setSpacing(0);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("QLabelLineInput-label"));
        horizontalLayout->addWidget(label);
        lineEdit = new CKBEdit(Form);
        lineEdit->setObjectName(QString::fromUtf8("QLabelLineInput-lineEdit"));
        horizontalLayout->addWidget(lineEdit);
        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        QMetaObject::connectSlotsByName(Form);
    }
};
class QCheckButtonInput:public QWidget
{
    Q_OBJECT
Q_SIGNALS:
    void clicked(bool b);
private slots:
    void OnClicked();
    void stateChanged(int);
public:
    enum
    {
        CHECK_RIGHT,
        CHECK_LEFT,
        CHECK_LEFT_SMALL,
    };
    explicit QCheckButtonInput(int type = CHECK_RIGHT,QWidget *parent=0, Qt::WindowFlags flags=0);
    ~QCheckButtonInput();
    bool isChecked()
    {
        return checkBox->isChecked();
    }

    void connectCBoxSignal(bool flag = true);

    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QCheckBox   *checkBox;
    void setupUi(int type,QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QLabelLineInput"));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setSpacing(0);
        if ( type == CHECK_RIGHT )
        {
            pushButton = new QPushButton(Form);
            pushButton->setObjectName(QString::fromUtf8("QCheckButtonInput-pushButton"));
            horizontalLayout->addWidget(pushButton);
            checkBox = new QCheckBox(Form);
            checkBox->setObjectName(QString::fromUtf8("QCheckButtonInput-checkBox"));
            horizontalLayout->addWidget(checkBox);
            horizontalLayout->setStretch(0, 2);
            horizontalLayout->setStretch(1, 1);
        }
        else
        {
            checkBox = new QCheckBox(Form);
            checkBox->setObjectName(QString::fromUtf8("QCheckButtonInput-checkBox"));
            horizontalLayout->addWidget(checkBox);
            pushButton = new QPushButton(Form);
            pushButton->setObjectName(QString::fromUtf8("QCheckButtonInput-pushButton"));
            horizontalLayout->addWidget(pushButton);
            horizontalLayout->setStretch(0, 1);
            horizontalLayout->setStretch(1, 2);
        }
        QMetaObject::connectSlotsByName(Form);
    }
};

class QLabelCheckBoxInput:public QWidget
{
    Q_OBJECT
private slots:
    void OnLClicked();
    void OnRClicked();
public:
    explicit QLabelCheckBoxInput(QColor color=Qt::white,QWidget *parent=0, Qt::WindowFlags flags=0);
    ~QLabelCheckBoxInput();
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_check;
    QCheckButtonInput* l;
    QCheckButtonInput* r;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QLabelLineInput"));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setSpacing(0);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("QLabelLineInput-label"));
        horizontalLayout->addWidget(label);
        horizontalLayout_check = new QHBoxLayout();
        horizontalLayout_check->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_check->setSpacing(0);
        horizontalLayout_check->setObjectName(QString::fromUtf8("horizontalLayout_check"));

        l = new QCheckButtonInput(QCheckButtonInput::CHECK_LEFT,Form);
        l->setObjectName(QString::fromUtf8("l"));
        horizontalLayout_check->addWidget(l);
        r = new QCheckButtonInput(QCheckButtonInput::CHECK_LEFT,Form);
        r->setObjectName(QString::fromUtf8("r"));
        horizontalLayout_check->addWidget(r);
        horizontalLayout->addLayout(horizontalLayout_check);
        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        QMetaObject::connectSlotsByName(Form);
    }
};

class QLabelDateTimeInput:public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent* ev);
public:
    explicit QLabelDateTimeInput(int type,QWidget *parent=0, Qt::WindowFlags flags=0);
    ~QLabelDateTimeInput();
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    CDateTimeEdit *lineEdit;
    int m_nType;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QLabelDateTimeInput"));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setSpacing(0);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumHeight(32);
        horizontalLayout->addWidget(label);
        lineEdit = new CDateTimeEdit(m_nType,Form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 32));
        lineEdit->setMaxLength(12);
        horizontalLayout->addWidget(lineEdit);
        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        QMetaObject::connectSlotsByName(Form);
    }
};
class QLanguageSelect:public CMessageNotify
{
    Q_OBJECT
public:
    enum showType
    {
        InvalidShowType = 10000,
        AdvanceShowType,
        GuideShowTyoe
    };

    explicit QLanguageSelect(QWidget *parent = 0, Qt::WFlags flags = 0);
    explicit QLanguageSelect(QLanguageSelect::showType type, QWidget *parent = 0);
    ~QLanguageSelect();
    void Update(QString param);
    bool OnConfirm();

    void setType(int type);

protected:
    void initUI();
    void showEvent(QShowEvent *);
private slots:
    void languageChangeClicked(int id);
public:
    //    QHBoxLayout *horizontalLayout;
    //    QSpacerItem *horizontalSpacer_2;
    //    QVBoxLayout *verticalLayout;
    //    QSpacerItem *verticalSpacer;
    //    QHBoxLayout *horizontalLayout_t;
    QToolButton *m_pLabel;
    QPushButton *pushButton_chn;
    QPushButton *pushButton_tw;
    //    QHBoxLayout *horizontalLayout_d;
    QPushButton *pushButton_jp;
    QPushButton *pushButton_en;
    //    QSpacerItem *verticalSpacer_4;

    QButtonGroup *m_pLangBtnGrp;

    int m_iPrevLang;

    showType m_iType;

    void setupUi(QWidget *Form)
    {
        //        verticalLayout = new QVBoxLayout(Form);
        //        verticalLayout->setSpacing(32);
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_pLabel = new QToolButton(Form);


        pushButton_chn = new QPushButton(Form);

        pushButton_tw = new QPushButton(Form);


        pushButton_jp = new QPushButton(Form);


        pushButton_en = new QPushButton(Form );


        //        verticalLayout->addWidget(pushButton_chn, 0, Qt::AlignCenter);
        //        verticalLayout->addWidget(pushButton_tw, 0, Qt::AlignCenter);
        //        verticalLayout->addWidget(pushButton_en, 0, Qt::AlignCenter);
        //        verticalLayout->addWidget(pushButton_jp, 0, Qt::AlignCenter);
        //        Form->setLayout(verticalLayout);

        m_pLangBtnGrp = new QButtonGroup(Form);
        m_pLangBtnGrp->setExclusive(true);
        m_pLangBtnGrp->addButton(pushButton_chn, LANGUAGE_CHINESE_SIMPLE);
        m_pLangBtnGrp->addButton(pushButton_tw, LANGUAGE_CHINESE_TAIWAN);
        m_pLangBtnGrp->addButton(pushButton_en, LANGUAGE_ENGLISH);
        m_pLangBtnGrp->addButton(pushButton_jp, LANGUAGE_JAPANESE);

        //        setFixedSize(parentWidget()->parentWidget()->width(),
        //                     parentWidget()->parentWidget()->height());

        int iBtnW = 240;
        int iBtnH = 48;
        int iSpacing = 25;
        int iLeft = 248;//248 logo width
        int iRight = 0;

        switch (CommonParam::currentMachineType())
        {
        case MACHINE_TYPE_4INCH:
            iBtnW = 160;
            iLeft = 0;
            iRight = 0;
            break;
        case MACHINE_TYPE_5INCH_V:
            iBtnW = 180;
            break;
        default:
            break;
        }

        //        pushButton_chn->setFixedSize(iBtnW, iBtnH);
        //        pushButton_tw->setFixedSize(iBtnW, iBtnH);
        //        pushButton_en->setFixedSize(iBtnW, iBtnH);
        //        pushButton_jp->setFixedSize(iBtnW, iBtnH);

        iRight = (parentWidget()->parentWidget()->width() - iLeft - iBtnW)/2;

        //        verticalLayout->setSpacing(iSpacing);

        int iScreenH = parentWidget()->parentWidget()->height();
        int iTop = (iScreenH - iBtnH*4 - iSpacing*3)/2;
        int iBottom = iTop;

        //        verticalLayout->setContentsMargins(iLeft + iRight, iTop, iRight, iBottom);
        if (QLanguageSelect::AdvanceShowType == m_iType)
        {
            //            verticalLayout->setContentsMargins(0, iTop, 0, iBottom);
        }

        retranslateUi(Form);
        QPalette palette;
        setAutoFillBackground(true);
        palette.setBrush(QPalette::Background, QBrush(QPixmap(":/seven/Nimage/user16.png")));
        setPalette(palette);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget*)
    {
        pushButton_chn->setText(tr("Cn"));
        pushButton_tw->setText(tr("Tw"));
        pushButton_jp->setText(tr("Jp"));
        pushButton_en->setText(tr("En"));
        m_pLabel->move(195,21);
        m_pLabel->resize(152,55);
        m_pLabel->setStyleSheet(CommonParam::m_sStyle10);
        m_pLabel->setText(tr("Advance"));
        pushButton_chn->move(266,150);
        pushButton_chn->resize(183,69);
        pushButton_chn->setObjectName(QString::fromUtf8("pushButton_chn"));
        pushButton_chn->setStyleSheet(CommonParam::m_sStyle19);

        pushButton_tw->move(495,150);
        pushButton_tw->resize(183,69);
        pushButton_tw->setObjectName(QString::fromUtf8("pushButton_tw"));
        pushButton_tw->setStyleSheet(CommonParam::m_sStyle19);

        pushButton_jp->move(266,260);
        pushButton_jp->resize(183,69);
        pushButton_jp->setObjectName(QString::fromUtf8("pushButton_jp"));
        pushButton_jp->setStyleSheet(CommonParam::m_sStyle20);

        pushButton_en->move(495,260);
        pushButton_en->resize(183,69);
        pushButton_en->setObjectName(QString::fromUtf8("pushButton_en"));
        pushButton_en->setStyleSheet(CommonParam::m_sStyle20);

    }
};

class QAdvanceLanguageSelect : public QLanguageSelect
{
    Q_OBJECT
public:
    explicit QAdvanceLanguageSelect(QLanguageSelect::showType type, QWidget *parent = 0)
        : QLanguageSelect(type, parent)
    {

    }

    ~QAdvanceLanguageSelect(){}
};

class QTimeZoneSelect: public CMessageNotify
{
    Q_OBJECT
public:
    explicit QTimeZoneSelect(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QTimeZoneSelect();
    bool OnConfirm();
    void Update(QString param);
    bool OnPrevious();
public slots:
    void nextpage();
    void previouspage();
    void OnTextChanged(const QString&);
    void ShowTimePicker(int type);
    void OnDatetextChanged(QString text);
    void OnTimetextChanged(QString text);
    void timeZoneChanged(QTreeWidgetItem *item, int column);

public:
    DateTimeSelectWidget *m_pDateTimeWidget;
    MedCtrlCalendarWidget *m_pCalendarWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_mod;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTreeWidget *m_pTreeWidget;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_down;
    QToolButton *toolButton_up;
    QString    selectString;
    QLabelDateTimeInput* dateEdit;
    QLabelDateTimeInput* timeEdit;
    QStringList m_strListCountry;
    QStringList m_strListTimeZone;
    void retranslateUi(QWidget *Form);
    void refreshText();
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QTimeZoneSelect"));

        m_pCalendarWidget = new MedCtrlCalendarWidget(this);
        m_pDateTimeWidget = new DateTimeSelectWidget(DateTimeSelectWidget::TimeShowType, this);
        m_pDateTimeWidget->hide();

        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        m_pTreeWidget = new QTreeWidget(Form);
        QStringList labels;
        labels << tr("TimeZone--typical city(major country)");
        m_pTreeWidget->setHeaderLabels(labels);
        m_pTreeWidget->setObjectName(QString::fromUtf8("TreeWidget"));
        m_pTreeWidget->verticalScrollBar()->hide();
        //        m_pTreeWidget->horizontalScrollBar()->hide();

        verticalLayout_2->addWidget(m_pTreeWidget);

        horizontalLayout->addLayout(verticalLayout_2);
        horizontalLayout_mod = new QHBoxLayout(Form);
        horizontalLayout_mod->setObjectName(QString::fromUtf8("horizontalLayout_mod"));
        dateEdit = new QLabelDateTimeInput(QTimeDateSelect::SELECT_DATE,Form);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        horizontalLayout_mod->addWidget(dateEdit);

        timeEdit = new QLabelDateTimeInput(QTimeDateSelect::SELECT_TIME,Form);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        horizontalLayout_mod->addWidget(timeEdit);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolButton_up = new QToolButton(Form);
        toolButton_up->setObjectName(QString::fromUtf8("toolButton_up"));

        verticalLayout->addWidget(toolButton_up);

        toolButton_down = new QToolButton(Form);
        toolButton_down->setObjectName(QString::fromUtf8("toolButton_down"));

        verticalLayout->addWidget(toolButton_down);
        horizontalLayout->addLayout(verticalLayout);
        verticalLayout_2->addLayout(horizontalLayout_mod);


        if (MACHINE_TYPE_4INCH == CommonParam::currentMachineType()
                || MACHINE_TYPE_5INCH_V == CommonParam::currentMachineType())
        {
            horizontalLayout->setContentsMargins(0,0, 0, 0);
        }
        else
        {
            horizontalLayout->setContentsMargins(0, 0, 0, 0);
        }

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi


};

class WifiInfoWidget;
class WifiPasswordWidget;
class WifiConnectThread;
class QNetWorkSelectScan:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QNetWorkSelectScan(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QNetWorkSelectScan();
    void Update(QString param);
    void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);

    QString decodeHexChar(QString &code);
    void hide();
public slots:
    void previous_scan();
    void next_scan(int iValue);
    void scanItemClicked(QListWidgetItem *item);
    void recvWifiConnectState(QString, int);
    void updateScanList(QStringList scanList, QStringList networkList);
    void viewNet();

public:
    WifiConnectThread *m_pWifiConnectThread;
    WifiInfoWidget *m_pWifiInfoWgt;
    WifiPasswordWidget *m_pWifiPwdWgt;

    //    QHBoxLayout *horizontalLayout;
    //    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *m_pLbState;
    QListWidget *ListView;
    QPushButton* m_State1;
    QPushButton* m_State2;
    //    QVBoxLayout *verticalLayout;
    //    QToolButton *toolButton_up;
    QSlider *toolButton_down;
    QString m_strSelectSSid;
    QString m_sConnectedWifi;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QNetWorkSelectScan"));
        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        //            horizontalLayout->setContentsMargins(0, 0, 0, 0);
        //        else if ( CommonParam::currentMachineType() == MACHINE_TYPE_12INCH )
        //            horizontalLayout->setContentsMargins(64, 0, 0, 0);
        //        else
        //            horizontalLayout->setContentsMargins(64, 32, 64, 0);
        //        verticalLayout_2 = new QVBoxLayout();
        //        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        label = new QLabel(Form);


        m_pLbState = new QLabel(Form);


        m_State1=new QPushButton(Form);


        m_State2=new QPushButton(Form);


        //        verticalLayout_2->addWidget(m_pLbState);

        //        verticalLayout_2->addWidget(label);

        ListView = new QListWidget(Form);


        //        horizontalLayout->addLayout(verticalLayout_2);

        //        verticalLayout = new QVBoxLayout();
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        //        toolButton_up = new QToolButton(Form);
        //        toolButton_up->setObjectName(QString::fromUtf8("toolButton_up"));

        //        verticalLayout->addWidget(toolButton_up);

        toolButton_down = new QSlider(Form);

toolButton_down->setObjectName(QString::fromUtf8("toolButton_down"));

//        verticalLayout->addWidget(toolButton_down);


//        horizontalLayout->addLayout(verticalLayout);


retranslateUi(Form);

QMetaObject::connectSlotsByName(Form);
} // setupUi


};

class QNetWorkSelectWifi:public CMessageNotify
{
    Q_OBJECT
public:
    enum {
        AUTH_NONE_OPEN,
        AUTH_NONE_WEP,
        AUTH_NONE_WEP_SHARED,
        AUTH_IEEE8021X,
        AUTH_WPA_PSK,
        AUTH_WPA_EAP,
        AUTH_WPA2_PSK,
        AUTH_WPA2_EAP
    };
    explicit QNetWorkSelectWifi(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QNetWorkSelectWifi();
    void Update(QString param);
    int setNetworkParam(int id, const char *field,const char *value, bool quote);
    void hide();
private slots:
    void OnPassword();
    void OnDelete();
    void StateChange(bool b);
public:
    //    QHBoxLayout *horizontalLayout;
    //    QHBoxLayout *horizontalLayout_1;
    //    QVBoxLayout *verticalLayout_2;
    QLabelSwicthInput* switchinput;
    QLabel *label_cfg;
    QLineEdit *lineEdit_cfg;
    QPushButton *push_cfg_del;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabelLineInput* LineInput;
    QString      selectedInfo;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QNetWorkSelectWifi"));
        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        //            horizontalLayout->setContentsMargins(0, 0, 0, 0);
        //        else if ( CommonParam::currentMachineType() == MACHINE_TYPE_12INCH )
        //            horizontalLayout->setContentsMargins(0, 0, 0, 0);
        //        else
        //            horizontalLayout->setContentsMargins(0, 0, 0, 0);
        //        verticalLayout_2 = new QVBoxLayout();
        //        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        switchinput = new QLabelSwicthInput(Form);
        switchinput->setObjectName(QString::fromUtf8("switchinput"));
        //        verticalLayout_2->addWidget(switchinput);

        label_cfg = new QLabel(Form);
        label_cfg->setObjectName(QString::fromUtf8("label_cfg"));
        //        verticalLayout_2->addWidget(label_cfg);
        lineEdit_cfg = new QLineEdit(Form);
        lineEdit_cfg->setObjectName(QString::fromUtf8("lineEdit_cfg"));
        lineEdit_cfg->setEnabled(false);
        //        horizontalLayout_1 = new QHBoxLayout();
        //        horizontalLayout_1->setObjectName(QString::fromUtf8("horizontalLayout_1"));
        //        horizontalLayout_1->addWidget(lineEdit_cfg);
        push_cfg_del = new QPushButton(Form);
        push_cfg_del->setObjectName(QString::fromUtf8("push_cfg_del"));
        //        horizontalLayout_1->addWidget(push_cfg_del);
        //        verticalLayout_2->addLayout(horizontalLayout_1);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        //        verticalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        //        verticalLayout_2->addWidget(lineEdit);
        LineInput = new QLabelLineInput(Form);
        LineInput->setObjectName(QString::fromUtf8("LineInput"));
        connect(LineInput->lineEdit,SIGNAL(textChanged1()),this,SLOT(OnPassword()));
        //        verticalLayout_2->addWidget(LineInput);
        //        horizontalLayout->addLayout(verticalLayout_2);
        retranslateUi(Form);
        connect(LineInput->lineEdit,SIGNAL(textChanged1()),this,SLOT(OnPassword()));
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};


class QNetWorkStatus:public CMessageNotify
{
    Q_OBJECT
public:
    QNetWorkStatus(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QNetWorkStatus();
    void Update(QString);
    void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
    void hide();
Q_SIGNALS:
    void requestGateWay(QString);
private slots:
    void stateChanged(bool);
    void stateChanged_if(bool);
    void textChanged();
    void gateWayChange(QString str);
public:
    //    QHBoxLayout *horizontalLayout;
    //    QVBoxLayout *verticalLayout_2;
    QSwitchMenu *ifupdown;
    QSwitchMenu *dhcp_ip;
    CKBEdit *LineInput_ip;
    CKBEdit *LineInput_mask;
    CKBEdit *LineInput_gw;
    CKBEdit *LineInput_dns;

    QPushButton* m_plable1;
    QPushButton* m_plable2;
    QPushButton* m_plable3;
    QPushButton* m_plable4;
    QPushButton* m_plable5;
    QPushButton* m_plable6;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QNetWorkStatus"));

        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        //            horizontalLayout->setContentsMargins(0, 0, 0, 0);
        //        else if ( CommonParam::currentMachineType() == MACHINE_TYPE_12INCH )
        //            horizontalLayout->setContentsMargins(64, 0, 0, 0);
        //        else
        //            horizontalLayout->setContentsMargins(0, 0, 0, 0);

        //        verticalLayout_2 = new QVBoxLayout();
        //        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_plable1= new QPushButton(Form);
        m_plable2= new QPushButton(Form);

        m_plable3= new QPushButton(Form);

        m_plable4= new QPushButton(Form);

        m_plable5= new QPushButton(Form);

        m_plable6= new QPushButton(Form);

        ifupdown = new QSwitchMenu(Form);
        ifupdown->setObjectName(QString::fromUtf8("ifupdown"));
        //        verticalLayout_2->addWidget(ifupdown);
        dhcp_ip = new QSwitchMenu(Form);
        dhcp_ip->setObjectName(QString::fromUtf8("dhcp_ip"));
        //        verticalLayout_2->addWidget(dhcp_ip);
        LineInput_ip = new CKBEdit(Form);

        //        verticalLayout_2->addWidget(LineInput_ip);

        LineInput_mask = new CKBEdit(Form);

        //        verticalLayout_2->addWidget(LineInput_mask);

        LineInput_gw = new CKBEdit(Form);

        //        verticalLayout_2->addWidget(LineInput_gw);

        LineInput_dns = new CKBEdit(Form);

        //        verticalLayout_2->addWidget(LineInput_dns);


        //        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QNetWorkWizard:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QNetWorkWizard(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QNetWorkWizard();
    bool OnConfirm();
    bool OnPrevious();
    void Update(QString param);
    void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
private slots:
    void stateChanged(bool b);
public:
    //    QHBoxLayout *horizontalLayout;
    //    QVBoxLayout *verticalLayout_2;
    //    QHBoxLayout *horizontalLayout_2;
    QToolButton* m_pUser;
    QCheckBox *toolButton_eth;
    QCheckBox *toolButton_wifi;
    QStackedWidget *stackedWidget;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QNetWorkWizard"));
        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        //            horizontalLayout->setContentsMargins(16, 32,16, 0);
        //        else if ( CommonParam::currentMachineType() == MACHINE_TYPE_12INCH )
        //            horizontalLayout->setContentsMargins(16, 64,16, 0);
        //        else
        //            horizontalLayout->setContentsMargins(32, 32,32, 0);
        //        verticalLayout_2 = new QVBoxLayout();
        //        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        //        horizontalLayout_2 = new QHBoxLayout();
        //        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        //            horizontalLayout_2->setContentsMargins(4, 8,4, 0);
        //        else
        //            horizontalLayout_2->setContentsMargins(64, 0, 64, 0);
        m_pUser=new QToolButton(Form);
        toolButton_eth = new QCheckBox(Form);
        toolButton_eth->setObjectName(QString::fromUtf8("toolButton_eth"));
        //        horizontalLayout_2->addWidget(toolButton_eth);
        toolButton_wifi = new QCheckBox(Form);
        //        horizontalLayout_2->addWidget(toolButton_wifi);
        //        verticalLayout_2->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        //        verticalLayout_2->addWidget(stackedWidget);
        //        horizontalLayout->addLayout(verticalLayout_2);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QBlueToothUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QBlueToothUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QBlueToothUI();
    void Update(QString param);
protected slots:
    void StateChange(bool on);
    void receiveMsgs();
public:
    int fd;
    QSocketNotifier *msgNotifier;
    QVBoxLayout *verticalLayout;

    QHBoxLayout *horizontalLayout;
    QLabelSwicthInput *label;
    QLabelLineInput *label_protocol;
    QListWidget *ListView;

    QVBoxLayout *verticalLayout_ud;
    QToolButton *toolButton_up;
    QToolButton *toolButton_down;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QBlueToothUI"));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
            horizontalLayout->setContentsMargins(0, 0,0, 0);
        else
            horizontalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabelSwicthInput(this);
        label->setObjectName(QString::fromUtf8("label"));
        verticalLayout->addWidget(label);
        label_protocol = new QLabelLineInput(this);
        label_protocol->setObjectName(QString::fromUtf8("label_protocol"));
        verticalLayout->addWidget(label_protocol);

        ListView = new QListWidget(this);
        ListView->setObjectName(QString::fromUtf8("ListView"));
        verticalLayout->addWidget(ListView);
        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_ud = new QVBoxLayout();
        verticalLayout_ud->setObjectName(QString::fromUtf8("verticalLayout_ud"));

        toolButton_up = new QToolButton(Form);
        toolButton_up->setObjectName(QString::fromUtf8("toolButton_up"));
        verticalLayout_ud->addWidget(toolButton_up);
        toolButton_down = new QToolButton(Form);
        toolButton_down->setObjectName(QString::fromUtf8("toolButton_down"));
        verticalLayout_ud->addWidget(toolButton_down);
        horizontalLayout->addLayout(verticalLayout_ud);
        connect(label->onoff,SIGNAL(StateChange(bool)),this,SLOT(StateChange(bool)));
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QHelpUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QHelpUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QHelpUI();
    void Update(QString param);
private slots:
    void OnPreviousPage();
    void OnNextPage();
public:
    //    QVBoxLayout *verticalLayout;

    //    QHBoxLayout *horizontalLayout;
    QToolButton *label;
    QPlainTextEdit *ListView;

    //    QVBoxLayout *verticalLayout_ud;
    //    QToolButton *toolButton_up;
    QSlider *toolButton_down;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QHelpUI"));
        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        //            horizontalLayout->setContentsMargins(16, 32,16, 0);
        //        else
        //            horizontalLayout->setContentsMargins(64, 32, 64, 0);

        //        verticalLayout = new QVBoxLayout();
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QToolButton(this);
        //        verticalLayout->addWidget(label);
        ListView = new QPlainTextEdit(this);

        //        verticalLayout->addWidget(ListView);
        //        horizontalLayout->addLayout(verticalLayout);

        //        verticalLayout_ud = new QVBoxLayout();
        //        verticalLayout_ud->setObjectName(QString::fromUtf8("verticalLayout_ud"));

        //        toolButton_up = new QToolButton(Form);
        //        toolButton_up->setObjectName(QString::fromUtf8("toolButton_up"));
        //        verticalLayout_ud->addWidget(toolButton_up);
        toolButton_down = new QSlider(Form);

//        verticalLayout_ud->addWidget(toolButton_down);
//        horizontalLayout->addLayout(verticalLayout_ud);
retranslateUi(Form);
QMetaObject::connectSlotsByName(Form);
} // setupUi
};

class QMainCtrlButtonUIExt:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QMainCtrlButtonUIExt(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QMainCtrlButtonUIExt();
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_l;
    QSpacerItem *horizontalSpacer_m;
    QPushButton *pushButton_r;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QMainCtrlButtonUIExt"));
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0,0,0,0);
        horizontalLayout->setSpacing(0);
        //horizontalSpacer_l = new QSpacerItem(40, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);
        //horizontalLayout->addItem(horizontalSpacer_l);
        pushButton_l = new QPushButton(this);
        pushButton_l->setObjectName(QString::fromUtf8("pushButton_l"));
        horizontalLayout->addWidget(pushButton_l);
        horizontalSpacer_m = new QSpacerItem(40, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);
        horizontalLayout->addItem(horizontalSpacer_m);
        pushButton_r = new QPushButton(this);
        pushButton_r->setObjectName(QString::fromUtf8("pushButton_r"));
        horizontalLayout->addWidget(pushButton_r);
        //horizontalSpacer_r = new QSpacerItem(40, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);
        //horizontalLayout->addItem(horizontalSpacer_r);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }
};
class QMainCtrlButtonUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QMainCtrlButtonUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QMainCtrlButtonUI();

    bool eventFilter(QObject *, QEvent *);
public slots:
    void btnLockScreenPressed();
    void btnLockScreenReleased();
    void lockScreenTimeout();
public:
    //    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_l;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_r;
    QCheckBox   *checkBox;
    QToolButton* powerErrors;
    QToolButton* networkStatus;
    QPushButton *m_pBtnOffScreen;
    QTimer *m_pLockScreenTimer;
    int m_iLockScreenSecond;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QMainCtrlButtonUI"));
        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V ||
             CommonParam::currentMachineType() == MACHINE_TYPE_12INCH )
        {
            //            horizontalLayout->setContentsMargins(0,0,0,0);
            //            horizontalLayout->setSpacing(0);
        }
        else
        {
            //            horizontalLayout->setContentsMargins(0,0,0,16);
            //            horizontalLayout->setSpacing(4);
        }
        pushButton_l = new QPushButton(this);

        //        pushButton_l->move(15,420);
        //        horizontalLayout->addWidget(pushButton_l,0,Qt::AlignLeft);

        checkBox = new QCheckBox(this);


//        horizontalLayout->addWidget(checkBox,0);
powerErrors= new QToolButton(this);

networkStatus= new QToolButton(this);

pushButton_r = new QPushButton(this);

m_pBtnOffScreen = new QPushButton(Form);

//        horizontalLayout->addWidget(pushButton_r,0,Qt::AlignRight);

retranslateUi(Form);
QMetaObject::connectSlotsByName(Form);
}
};

class QWaterChangeUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QWaterChangeUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QWaterChangeUI();
    void Update(QString);
private slots:
    void OnShowMain();
    void clicked_progress(int);
public:
    //    QVBoxLayout *verticalLayout;
    //    QHBoxLayout* horizontalLayout_t;
    //    QLabel*      label;

    //    QHBoxLayout* horizontalLayout_m;
    //    QToolButton* b1;
    //    QToolButton* b2;
    //    QToolButton* b3;

    //    QHBoxLayout* horizontalLayout_b;
    QLabel*      label_m;
    QLabel*      label_left;
    QLabel*      label_mid;
    QLabel*      label_right;


    //    QHBoxLayout* horizontalLayout_b1;
    QPushButton* pushButton;
    //    QSlider* horizontalSlider;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QWaterChangeUI"));

        //        horizontalSlider = new QSlider(this);
        //        horizontalSlider->setOrientation(Qt::Horizontal);  // 水平方向
        //            horizontalSlider->setStyleSheet("QSlider::groove:horizontal {\
        //                                            border: 1px solid #000000;\
        //                                            border-image:url(:/seven/Nimage/huakuai1.png);\
        //                                            height: 29px;\
        //                                            border-radius: 5px;\
        //                                            padding-left:-1px;\
        //                                            padding-right:-1px;\
        //                                            }\
        //                                            QSlider::sub-page:horizontal {\
        //                                            border-image:url(:/seven/Nimage/7zuo.png);\
        //                                            border: 1px solid #4A708B;\
        //                                            height: 10px;\
        //                                            border-radius: 2px;\
        //                                            }\
        //                                            QSlider::add-page:horizontal {\
        //                                            border-image:url(:/seven/Nimage/7you.png);\
        //                                            border: 0px solid #777;\
        //                                            height: 10px;\
        //                                            border-radius: 2px;\
        //                                            }\
        //                                            QSlider::handle:horizontal \
        //                                            {\
        //                                            border-image:url(:/seven/Nimage/huakuai.png);\
        //                                                width: 21px;\
        //                                                margin-top: 3px;\
        //                                                margin-bottom: 3px;\
        //                                                border-radius: 5px;\
        //                                            }");
        //        horizontalSlider->resize(392,29);
        ////            horizontalSlider->move(354,139);

        //        //设置最小值、最大值
        //        horizontalSlider->setMinimum(0);
        //        horizontalSlider->setMaximum(8);

        //        //设置初始值
        //        horizontalSlider->setValue(7);
        //        horizontalSlider->setEnabled(true);
        //        horizontalSlider->setPageStep(1);
        //connect(horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(clicked_progress(int)));
        //        verticalLayout = new QVBoxLayout(Form);
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V)
        //        {
        //            verticalLayout->setContentsMargins(4,4,4,8);
        //            verticalLayout->setSpacing(4);
        //        }
        //        else
        //        {
        //            verticalLayout->setSpacing(30);
        //        }
        //        horizontalLayout_t = new QHBoxLayout();
        //        horizontalLayout_t->setObjectName(QString::fromUtf8("horizontalLayout_t"));
        //        label = new QLabel(this);
        //        label->setObjectName(QString::fromUtf8("label"));
        //        horizontalLayout_t->addWidget(label);
        //        verticalLayout->addLayout(horizontalLayout_t);

        //        horizontalLayout_m = new QHBoxLayout();
        //        horizontalLayout_m->setObjectName(QString::fromUtf8("horizontalLayout_m"));
        //        b1 = new QToolButton(Form);
        //        b1->setObjectName(QString::fromUtf8("b1"));

        //        b2 = new QToolButton(Form);
        //        b2->setObjectName(QString::fromUtf8("b2"));

        //        b3 = new QToolButton(Form);
        //        b3->setObjectName(QString::fromUtf8("b3"));

        //        horizontalLayout_m->addWidget(b1);
        //        horizontalLayout_m->addWidget(b2);
        //        horizontalLayout_m->addWidget(b3);
        //        verticalLayout->addLayout(horizontalLayout_m);
        label_m = new QLabel(Form);
        label_mid = new QLabel(Form);
        label_left = new QLabel(Form);
        label_right = new QLabel(Form);

        label_m->setObjectName(QString::fromUtf8("label_m"));
        label_mid->setObjectName(QString::fromUtf8("label_mid"));
        label_left->setObjectName(QString::fromUtf8("label_left"));
        label_right->setObjectName(QString::fromUtf8("label_right"));

        label_m->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
        label_mid->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
        label_left->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
        label_right->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));

        //        horizontalLayout_b = new QHBoxLayout();
        //        horizontalLayout_b->setObjectName(QString::fromUtf8("horizontalLayout_b"));
        //        horizontalLayout_b->addWidget(label_m);
        //        verticalLayout->addLayout(horizontalLayout_b);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        //        horizontalLayout_b1 = new QHBoxLayout();
        //        horizontalLayout_b1->setObjectName(QString::fromUtf8("horizontalLayout_b1"));
        //        horizontalLayout_b1->addWidget(pushButton,0,Qt::AlignCenter);
        //        horizontalLayout_b1->setContentsMargins(0,20,0,0);
        //        verticalLayout->addLayout(horizontalLayout_b1);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QAcceptUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QAcceptUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QAcceptUI();
    void Update(QString param);
    bool OnConfirm();
private slots:
    void OnPreviousPage();
    void OnNextPage(int ivalue);
public:
    //    QVBoxLayout *verticalLayout;

    //    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton* m_pUser;

    QPlainTextEdit *ListView;

    //    QVBoxLayout *verticalLayout_ud;
    //    QToolButton *toolButton_up;
    QSlider *toolButton_down;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QAcceptUI"));
        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        horizontalLayout->setSpacing(0);
        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        //            horizontalLayout->setContentsMargins(4, 8,4, 0);
        //        else
        //            horizontalLayout->setContentsMargins(64, 32, 64, 0);

        //        verticalLayout = new QVBoxLayout();
        //        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_pUser=new QToolButton(Form);

        label = new QLabel(this);

        //        label->setAlignment(Qt::AlignCenter);
        //        verticalLayout->addWidget(label);
        ListView = new QPlainTextEdit(this);
        //        verticalLayout->addWidget(ListView);
        //        horizontalLayout->addLayout(verticalLayout);

        //        verticalLayout_ud = new QVBoxLayout();
        //        verticalLayout_ud->setObjectName(QString::fromUtf8("verticalLayout_ud"));

        //        toolButton_up = new QToolButton(Form);
        //        toolButton_up->setObjectName(QString::fromUtf8("toolButton_up"));
        //        verticalLayout_ud->addWidget(toolButton_up);
        toolButton_down = new QSlider(Form);
        toolButton_down->setObjectName(QString::fromUtf8("toolButton_down"));
        //        verticalLayout_ud->addWidget(toolButton_down);
        //        horizontalLayout->addLayout(verticalLayout_ud);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};



class QAboutUI:public CMessageNotify
{
    Q_OBJECT
public:
    QAboutUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QAboutUI();
    void Update(QString);

public slots:
    void OnTextChanged();

public:
    QPushButton* m_pReName;
    QPushButton* m_pNowVersion;
    QPushButton* m_pSerialNum;
    QToolButton* label;

    //    QHBoxLayout *horizontalLayout;
    //    QVBoxLayout *verticalLayout_2;
    CKBEdit *LineInput_version;
    CKBEdit *LineInput_uuid;
    //    QPushButton*     pushSearch;
    //    QSpacerItem*     verticalSpacer_1;
    //    QSpacerItem*     verticalSpacer_2;
    CKBEdit* m_pAliasEdit;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QAboutUI"));

        m_pReName=new QPushButton(Form);
        m_pReName->move(200,111);

        m_pNowVersion=new QPushButton(Form);


        m_pSerialNum=new QPushButton(Form);


        label = new QToolButton(this);

        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        horizontalLayout->setSpacing(0);
        m_pAliasEdit = new CKBEdit(this);

        {
            //            horizontalLayout->setContentsMargins(64, 120, 64, 120);
            //            verticalLayout_2 = new QVBoxLayout();
            //            verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

            LineInput_version = new CKBEdit(Form);

            //            verticalLayout_2->addWidget(m_pAliasEdit);
            //            verticalLayout_2->addWidget(LineInput_version);

            LineInput_uuid = new CKBEdit(Form);

            //            verticalLayout_2->addWidget(LineInput_uuid);

            //            pushSearch = new QPushButton(Form);
            //            pushSearch->setObjectName(QString::fromUtf8("pushSearch"));

            //            verticalLayout_2->addWidget(pushSearch);
            //            horizontalLayout->addLayout(verticalLayout_2);
        }


        connect(m_pAliasEdit,SIGNAL(textChanged1()),this,SLOT(OnTextChanged()));

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QVersonSearchUI:public CMessageNotify
{
    Q_OBJECT
public:
    QVersonSearchUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QVersonSearchUI();
    void Update(QString);
public:
    QHBoxLayout *horizontalLayout;
    QRoundProgressBar *LineInput_version;
    QLabel      *label;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QVersonSearchUI"));

        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
            horizontalLayout->setContentsMargins(0, 0,0,0);
        else
            horizontalLayout->setContentsMargins(0, 0, 0, 0);

        LineInput_version = new QRoundProgressBar(Form);
        LineInput_version->setObjectName(QString::fromUtf8("LineInput_version"));
        LineInput_version->setMaximumSize(QSize(128,128));
        horizontalLayout->addWidget(LineInput_version);

        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        horizontalLayout->addWidget(label);

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QVersonDownUI:public CMessageNotify
{
    Q_OBJECT
public:
    QVersonDownUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QVersonDownUI();
    void Update(QString);
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabelLineInput *LineInput_version;
    QLabelLineInput *LineInput_uuid;
    QLabelLineInput *LineInput_version_newest;
    QPushButton*     pushSearch;
    QSpacerItem*     verticalSpacer_1;
    QSpacerItem*     verticalSpacer_2;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QVersonSearchUI"));

        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
            horizontalLayout->setContentsMargins(0, 0,0,0);
            verticalLayout_2 = new QVBoxLayout();
            verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
            verticalSpacer_1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            verticalLayout_2->addItem(verticalSpacer_1);
            LineInput_version = new QLabelLineInput(Form);
            LineInput_version->setObjectName(QString::fromUtf8("LineInput_version"));

            verticalLayout_2->addWidget(LineInput_version);

            LineInput_uuid = new QLabelLineInput(Form);
            LineInput_uuid->setObjectName(QString::fromUtf8("LineInput_uuid"));

            verticalLayout_2->addWidget(LineInput_uuid);
            LineInput_version_newest = new QLabelLineInput(Form);
            LineInput_version_newest->setObjectName(QString::fromUtf8("LineInput_version_newest"));
            verticalLayout_2->addWidget(LineInput_version_newest);
            pushSearch = new QPushButton(Form);
            pushSearch->setObjectName(QString::fromUtf8("pushSearch"));
            verticalLayout_2->addWidget(pushSearch);
            verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            verticalLayout_2->addItem(verticalSpacer_2);
            horizontalLayout->addLayout(verticalLayout_2);
        }
        else
        {
            horizontalLayout->setContentsMargins(0, 0, 0,0);

            verticalLayout_2 = new QVBoxLayout();
            verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

            LineInput_version = new QLabelLineInput(Form);
            LineInput_version->setObjectName(QString::fromUtf8("LineInput_version"));

            verticalLayout_2->addWidget(LineInput_version);

            LineInput_uuid = new QLabelLineInput(Form);
            LineInput_uuid->setObjectName(QString::fromUtf8("LineInput_uuid"));

            verticalLayout_2->addWidget(LineInput_uuid);
            LineInput_version_newest = new QLabelLineInput(Form);
            LineInput_version_newest->setObjectName(QString::fromUtf8("LineInput_version_newest"));
            verticalLayout_2->addWidget(LineInput_version_newest);
            pushSearch = new QPushButton(Form);
            pushSearch->setObjectName(QString::fromUtf8("pushSearch"));
            verticalLayout_2->addWidget(pushSearch);
            horizontalLayout->addLayout(verticalLayout_2);
        }
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};
class QAboutMainUI:public CMessageNotify
{
    Q_OBJECT
public:
    QAboutMainUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QAboutMainUI();
    bool OnConfirm();
    bool OnPrevious();
    void Update(QString);
    void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
private slots:
    void OnSearch();
    void OnDownLoadTimeOut();
    void OnUpGrade();
public:
    QAboutUI* aboutUI;
    QVersonSearchUI* searchUI;
    QVersonDownUI* downUI;
    QHBoxLayout *horizontalLayout;
    QStackedWidget* stackedWidget;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QAboutMainUI"));

        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0,0,0,0);
        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        horizontalLayout->addWidget(stackedWidget);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QFunctionUI: public CMessageNotify
{
    Q_OBJECT
public:
    explicit QFunctionUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QFunctionUI();
    void retranslateUi(QWidget *Form);
    void Update(QString param);
    void OnMessage(int, int, quint32, quint32, quint8 *, quint16);
    virtual void mousePressEvent(QMouseEvent *);
private:
    static void* MyThread(void *arg);
private slots:
    void OnUser();
    void OnBlueTooth();
    void OnHelp();
    void OnNetwork();
    void OnAbout();
    void OnAdvance();
    void OnFactory();
    void OnService();
    void OnBtnTimeOut();
    void OnClinical();
private:
    pthread_t m_thread;
public:
    int hpos;
    int vpos;
    QHBoxLayout *horizontalLayout;
    //    QSpacerItem *horizontalSpacer_2;
    //    QGridLayout *gridLayout;
    QToolButton *pushButton_user;
    //QPushButton *pushButton_bt;
    QToolButton *pushButton_help;
    QToolButton *pushButton_nw;
    QToolButton *pushButton_about;
    QToolButton *pushButton_advance;
    QPushButton *pushButton_factory;
    QPushButton *pushButton_clinical;
    //    QSpacerItem *horizontalSpacer;
    QPushButton *pbService;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QFunctionUI"));
        hpos = vpos = 0;
        //        horizontalLayout = new QHBoxLayout(Form);
        //        horizontalLayout->setSpacing(24);
        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        //        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        //        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        //        horizontalLayout->addItem(horizontalSpacer_2);

        //        gridLayout = new QGridLayout();
        //        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        //        gridLayout->setContentsMargins(0,0,0,0);
        pushButton_user = new QToolButton(Form);
        //        horizontalLayout->addWidget(pushButton_user);
        //        pushButton_user->resize(96,71);
        //        pushButton_user->setObjectName(QString::fromUtf8("pushButton_user"));

        //        gridLayout->addWidget(pushButton_user, vpos/2, vpos%2, 1, 1);
        vpos++;
        //pushButton_bt = new QPushButton(Form);
        //pushButton_bt->setObjectName(QString::fromUtf8("pushButton_bt"));
        //gridLayout->addWidget(pushButton_bt, vpos/2, vpos%2, 1, 1);
        //vpos++;
        pushButton_help = new QToolButton(Form);
        //        horizontalLayout->addWidget(pushButton_help);
        pushButton_help->setObjectName(QString::fromUtf8("pushButton_help"));
        //        gridLayout->addWidget(pushButton_help,vpos/2, vpos%2, 1, 1);
        vpos++;
        pushButton_nw = new QToolButton(Form);        
        //        horizontalLayout->addWidget(pushButton_nw);
        pushButton_nw->setObjectName(QString::fromUtf8("pushButton_nw"));
        //        gridLayout->addWidget(pushButton_nw, vpos/2, vpos%2, 1, 1);
        vpos++;
        pushButton_about = new QToolButton(Form);
        pushButton_about->setObjectName(QString::fromUtf8("pushButton_about"));
        //        gridLayout->addWidget(pushButton_about, vpos/2, vpos%2, 1, 1);
        vpos++;
        pushButton_advance = new QToolButton(Form);
        pushButton_advance->setObjectName(QString::fromUtf8("pushButton_advance"));
        //        gridLayout->addWidget(pushButton_advance,vpos/2, vpos%2, 1, 1);
        vpos++;
        pushButton_factory = new QPushButton(Form);
        pushButton_factory->setObjectName(QString::fromUtf8("pushButton_factory"));
        //        gridLayout->addWidget(pushButton_factory, vpos/2, vpos%2, 1, 1);
        vpos++;
        pushButton_clinical = new QPushButton(Form);
        pushButton_clinical->setObjectName(QString::fromUtf8("pushButton_clinical"));
        //        gridLayout->addWidget(pushButton_clinical,vpos/2, vpos%2, 1, 1);
        pushButton_clinical->hide();
        vpos++;
        pbService=new QPushButton(Form);
        pbService->setObjectName(QString::fromUtf8("pbService"));
        //        gridLayout->addWidget(pbService, vpos/2, vpos%2, 1, 1);
        pbService->hide();
        vpos++;

        //        horizontalLayout->addLayout(gridLayout);

        //        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        //        horizontalLayout->addItem(horizontalSpacer);

        //        horizontalLayout->setStretch(0, 2);
        //        horizontalLayout->setStretch(1, 2);
        //        horizontalLayout->setStretch(2, 1);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QToolButtonPress:public QToolButton
{
    Q_OBJECT
public:
    QToolButtonPress(QWidget* parent):QToolButton(parent)
    {

    }

    virtual ~QToolButtonPress()
    {

    }

Q_SIGNALS:
    void pressed();
    void released();
protected:
    void mousePressEvent(QMouseEvent *)
    {
        emit pressed();
    }

    void mouseReleaseEvent(QMouseEvent *)
    {
        emit released();
    }
};

class QUserAddUI: public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserAddUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QUserAddUI();
    void Update(QString param);
    bool OnPrevious();
    bool OnConfirm();
    void ShowUser(bool isNextPage,int nStartId);
    void GetUserPictures(TMedUser* ptUser);
    QString decodeBase64(char *code);
private:
    int totalPage;
    int currentPage;
    int startId;
    int stopId;
    int isInTimer;
    int currentUserId;
protected slots:
    void OnBtnUserPressed();
    void OnBtnClicked(int iValue);
    void OnAddBtnClicked();
    void OnBtnReleased();
    void OnBtnTimeOut();

private:
    void prevNextBtnEnabled();

public:
    //    QHBoxLayout *horizontalLayout;
    //    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_add;

    //    QFrame *frame_user;
    //    QGridLayout *gridLayout_user;
    //    MyPushButton* m_pTest;
    MyPushButton *pushButton_u1;
    MyPushButton *pushButton_u2;
    MyPushButton *pushButton_u3;
    MyPushButton *pushButton_u4;
    MyPushButton *pushButton_u5;
    MyPushButton *pushButton_u6;
    QToolButton* m_pUser;
    QPushButton* m_pReturnUp;
    //    QToolButtonPress *pushButton_u7;
    //    QToolButtonPress *pushButton_u8;
    //    QToolButtonPress *pushButton_u9;

    //    QVBoxLayout *verticalLayout_2;
    //    QSpacerItem *verticalSpacer;
    //    QToolButton *pushButton_previous;
    //    QSpacerItem *verticalSpacer_2;
    QSlider *pushButton_next;
    //    QSpacerItem *verticalSpacer_3;
    QList<MyPushButton*> userBtns;
    QTimer* userBtnTimer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserAddUI"));


        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
            //            verticalLayout = new QVBoxLayout(Form);
            //            verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
            //            horizontalLayout = new QHBoxLayout();
            //            horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
            //            horizontalLayout->setSpacing(2);
            //            horizontalLayout->setContentsMargins(4,16,4,16);

            //            frame_user = new QFrame(Form);
            //            frame_user->setObjectName(QString::fromUtf8("frame_user"));

            //            gridLayout_user = new QGridLayout(frame_user);
            //            gridLayout_user->setObjectName(QString::fromUtf8("gridLayout_user"));
            //            gridLayout_user->setContentsMargins(0,0,0,0);

            pushButton_u1 = new MyPushButton(Form);
            pushButton_u1->setObjectName(QString::fromUtf8("pushButton_u1"));
            //            gridLayout_user->addWidget(pushButton_u1, 0, 0, 1, 1);

            pushButton_u2 = new MyPushButton(Form);
            pushButton_u2->setObjectName(QString::fromUtf8("pushButton_u2"));
            //            gridLayout_user->addWidget(pushButton_u2, 0, 1, 1, 1);

            pushButton_u3 = new MyPushButton(Form);
            pushButton_u3->setObjectName(QString::fromUtf8("pushButton_u3"));
            //            gridLayout_user->addWidget(pushButton_u3, 1, 0, 1, 1);

            pushButton_u4 = new MyPushButton(Form);
            pushButton_u4->setObjectName(QString::fromUtf8("pushButton_u4"));
            //            gridLayout_user->addWidget(pushButton_u4, 1, 1, 1, 1);

            pushButton_u5 = new MyPushButton(Form);
            pushButton_u5->setObjectName(QString::fromUtf8("pushButton_u5"));
            //            gridLayout_user->addWidget(pushButton_u5, 2, 0, 1, 1);

            pushButton_u6 = new MyPushButton(Form);
            pushButton_u6->setObjectName(QString::fromUtf8("pushButton_u6"));
            //            gridLayout_user->addWidget(pushButton_u6, 2, 1, 1, 1);

            //            pushButton_u7 = new QToolButtonPress(frame_user);
            //            pushButton_u7->setObjectName(QString::fromUtf8("pushButton_u7"));
            //            gridLayout_user->addWidget(pushButton_u7, 3, 0, 1, 1);

            //            pushButton_u8 = new QToolButtonPress(frame_user);
            //            pushButton_u8->setObjectName(QString::fromUtf8("pushButton_u8"));
            //            gridLayout_user->addWidget(pushButton_u8, 3, 1, 1, 1);

            //            pushButton_u9 = new QToolButtonPress(frame_user);
            //            pushButton_u9->setObjectName(QString::fromUtf8("pushButton_u9"));
            //            pushButton_u9->hide();
            //            gridLayout_user->addWidget(pushButton_u9, 4, 0, 1, 1);
            toolButton_add = new QToolButton(Form);
            toolButton_add->setObjectName(QString::fromUtf8("toolButton_add"));
            //            gridLayout_user->addWidget(toolButton_add, 4, 1, 1, 1);

            //            horizontalLayout->addWidget(frame_user);

            //            verticalLayout_2 = new QVBoxLayout();
            //            verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
            //            verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

            //            verticalLayout_2->addItem(verticalSpacer);

            //            pushButton_previous = new QToolButton(Form);
            //            pushButton_previous->setObjectName(QString::fromUtf8("toolButton_up"));
            //            verticalLayout_2->addWidget(pushButton_previous);
            //            verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            //            verticalLayout_2->addItem(verticalSpacer_2);

            pushButton_next = new QSlider(Form);
            pushButton_next->setObjectName(QString::fromUtf8("toolButton_down"));
            //            verticalLayout_2->addWidget(pushButton_next);
            //            verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

            //            verticalLayout_2->addItem(verticalSpacer_3);
            //            horizontalLayout->addLayout(verticalLayout_2);
            //            verticalLayout->addLayout(horizontalLayout);
            //toolButton_add = new QToolButton(Form);
            //toolButton_add->setObjectName(QString::fromUtf8("toolButton_add"));
            //verticalLayout->addWidget(toolButton_add);
            //            horizontalLayout->setStretch(1, 2);
        }
        else
        {
            //            horizontalLayout = new QHBoxLayout(Form);
            //            horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
            //            horizontalLayout->setSpacing(24);
            //            horizontalLayout->setContentsMargins(32, 0, 32, 0);
            //            verticalLayout = new QVBoxLayout();
            //            verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
            //            m_pReturnUp=new QPushButton(Form);
            //            m_pReturnUp->move(100,218);
            //            m_pReturnUp->setText(tr("Setting"));
            //            m_pReturnUp->resize(127,49);
            //            m_pReturnUp->setStyleSheet("border-image:url(:/seven/Nimage/chanqi.png);"
            //                                       "font: 28px;"
            //                                       "color: rgb(0, 0, 0);"
            //                                       "outline: none;"
            //                                       "border-style:solid;"
            //                                       "border-width:1px;"
            //                                       "border-radius:38px;"
            //                                       //"focus{padding: -1;};"
            //                                       //                              "padding:-1px;"
            //                                       );
            //            connect(m_pReturnUp,SIGNAL(clicked()),this,SLOT(previous()));

            toolButton_add = new QToolButton(Form);

            toolButton_add->setObjectName(QString::fromUtf8("toolButton_add"));


            //            m_pTest=new MyPushButton(Form);




            m_pUser=new QToolButton(Form);

            pushButton_u1 = new MyPushButton(Form);
            pushButton_u1->hide();

            pushButton_u1->setObjectName(QString::fromUtf8("pushButton_u1"));
            //            gridLayout_user->addWidget(pushButton_u1, 0, 0, 1, 1);

            pushButton_u2 = new MyPushButton(Form);
            pushButton_u2->hide();
            pushButton_u2->setObjectName(QString::fromUtf8("pushButton_u2"));
            //            gridLayout_user->addWidget(pushButton_u2, 0, 1, 1, 1);

            pushButton_u3 = new MyPushButton(Form);
            pushButton_u3->hide();
            pushButton_u3->setObjectName(QString::fromUtf8("pushButton_u3"));
            //            gridLayout_user->addWidget(pushButton_u3, 0, 2, 1, 1);

            pushButton_u4 = new MyPushButton(Form);
            pushButton_u4->hide();
            pushButton_u4->setObjectName(QString::fromUtf8("pushButton_u4"));
            //            gridLayout_user->addWidget(pushButton_u4, 1, 0, 1, 1);

            pushButton_u5 = new MyPushButton(Form);
            pushButton_u5->hide();
            pushButton_u5->setObjectName(QString::fromUtf8("pushButton_u5"));
            //            gridLayout_user->addWidget(pushButton_u5, 1, 1, 1, 1);

            pushButton_u6 = new MyPushButton(Form);
            pushButton_u6->hide();
            pushButton_u6->setObjectName(QString::fromUtf8("pushButton_u6"));
            //            gridLayout_user->addWidget(pushButton_u6, 1, 2, 1, 1);

            //            pushButton_u7 = new QToolButtonPress(frame_user);
            //            pushButton_u7->setObjectName(QString::fromUtf8("pushButton_u7"));
            //            gridLayout_user->addWidget(pushButton_u7, 2, 0, 1, 1);

            //            pushButton_u8 = new QToolButtonPress(frame_user);
            //            pushButton_u8->setObjectName(QString::fromUtf8("pushButton_u8"));
            //            gridLayout_user->addWidget(pushButton_u8, 2, 1, 1, 1);

            //            pushButton_u9 = new QToolButtonPress(frame_user);
            //            pushButton_u9->setObjectName(QString::fromUtf8("pushButton_u9"));
            //            gridLayout_user->addWidget(pushButton_u9, 2, 2, 1, 1);

            //            horizontalLayout->addWidget(frame_user);
            //            verticalLayout_2 = new QVBoxLayout();
            //            verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
            //            verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

            //            verticalLayout_2->addItem(verticalSpacer);

            //            pushButton_previous = new QToolButton(Form);
            //            pushButton_previous->setObjectName(QString::fromUtf8("toolButton_up"));
            //            verticalLayout_2->addWidget(pushButton_previous);
            //            verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            //            verticalLayout_2->addItem(verticalSpacer_2);

            pushButton_next = new QSlider(this);
            pushButton_next->setObjectName(QString::fromUtf8("toolButton_down"));

//设置最小值、最大值
pushButton_next->setMinimum(0);
pushButton_next->setMaximum(8);

//设置初始值
pushButton_next->setValue(0);
pushButton_next->setPageStep(1);
//            verticalLayout_2->addWidget(pushButton_next);
//            verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

//            verticalLayout_2->addItem(verticalSpacer_3);
//            horizontalLayout->addLayout(verticalLayout_2);

//            horizontalLayout->setStretch(1, 2);
}
userBtns.append(pushButton_u1);
userBtns.append(pushButton_u2);
userBtns.append(pushButton_u3);
userBtns.append(pushButton_u4);
userBtns.append(pushButton_u5);
userBtns.append(pushButton_u6);
//        userBtns.append(pushButton_u7);
//        userBtns.append(pushButton_u8);
//        userBtns.append(pushButton_u9);


retranslateUi(Form);
QMetaObject::connectSlotsByName(Form);
} // setupUi
void retranslateUi(QWidget *Form);
};

class QUserInputUI: public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserInputUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QUserInputUI();
    void Update(QString param);
    bool OnConfirm();
    bool OnPrevious();
private slots:
    void OnClickedNo(bool);
    void OnClickedHave(bool);
    void OnClickedMan(bool b);
    void OnClickedWoman(bool b);
    void OnDatetextChanged(QString str);
    void ShowTimePicker(int type);
private:
    QString decodeBase64(char *code);
    QString codeString;
public:
    //    QHBoxLayout *horizontalLayout;
    //    QVBoxLayout *verticalLayout;
    //    QHBoxLayout *m_pshorizontalLayout;

    QToolButton* m_pUser;
    QLabel* m_pAddUser;
    QToolButton* m_pID;
    QToolButton* m_pName;
    QToolButton* m_pBirthDay;
    QToolButton* m_pPhone;
    QToolButton* m_pSex;
    CKBEdit *pushButton_account;
    QLabel* m_pAccountInfo;
    CKBEdit *pushButton_name;
    QCheckBox *pushButton_genderMan;
    QCheckBox *pushButton_genderWoman;
    QLabelLineInput *pushButton_bot;
    CKBEdit *pushButton_mobile;
    //    QVBoxLayout *verticalLayout_2;
    //    QSpacerItem *verticalSpacer;
    //    QCheckButtonInput *pushButton_no;
    //    QSpacerItem *verticalSpacer_2;
    QCheckBox *pushButton_have;
    //    QSpacerItem *verticalSpacer_3;

    QLabel *m_pyear;
    QLabel *m_pmonth;
    QLabel *m_pday;

    CKBEdit *m_pInYear;
    CKBEdit *m_pInMonth;
    CKBEdit *m_pInDay;

    //    QHBoxLayout *m_pHLayoutBirth;

    int m_iID;

    QLayout *createBirthInput();
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserInputUI"));

        m_pUser=new QToolButton(Form);
        m_pUser->setStyleSheet(CommonParam::m_sStyle10);
        m_pUser->setText(tr("User"));
        m_pUser->resize(151,47);
        m_pUser->move(188,21);

        m_pAddUser=new QLabel(Form);
        m_pAddUser->setText(tr("addnew"));
        m_pAddUser->setStyleSheet(CommonParam::m_sStyle11);
        m_pAddUser->move(195,79);
        //        horizontalLayout = new QHBoxLayout(Form);
        //        m_pshorizontalLayout=new QHBoxLayout(Form);

        //        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //            CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
            //            horizontalLayout->setSpacing(4);
            //            horizontalLayout->setContentsMargins(4, 4, 4, 4);
            //            verticalLayout = new QVBoxLayout();
            //            verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
            //            verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            //            verticalLayout->addItem(verticalSpacer_3);
            m_pID=new QToolButton(Form);
            m_pID->hide();
            m_pID->move(186,118);
            m_pID->resize(86,49);
            m_pID->setStyleSheet(CommonParam::m_sStyle1);
            m_pID->setText(tr("ID"));

            m_pName=new QToolButton(Form);
            m_pName->move(186,184);
            m_pName->resize(86,49);
            m_pName->setStyleSheet(CommonParam::m_sStyle1);
            m_pName->setText(tr("name"));

            m_pBirthDay=new QToolButton(Form);
            m_pBirthDay->move(186,246);
            m_pBirthDay->resize(86,49);
            m_pBirthDay->setStyleSheet(CommonParam::m_sStyle1);
            m_pBirthDay->setText(tr("birthday"));

            m_pPhone=new QToolButton(Form);
            m_pPhone->move(186,310);
            m_pPhone->resize(86,49);
            m_pPhone->setStyleSheet(CommonParam::m_sStyle1);
            m_pPhone->setText(tr("tel"));

            m_pSex=new QToolButton(Form);
            m_pSex->move(451,184);
            m_pSex->resize(86,49);
            m_pSex->setStyleSheet(CommonParam::m_sStyle1);
            m_pSex->setText(tr("sex"));

            if(MedctrlConfManager::instance()->getCurrentConf()->getLanguage() == 2 |
                    MedctrlConfManager::instance()->getCurrentConf()->getLanguage() == 3)
            {
                m_pID->resize(110,49);
                m_pName->resize(110,49);
                m_pBirthDay->resize(110,49);
                m_pPhone->resize(110,49);
                m_pSex->resize(110,49);
            }


            pushButton_account = new CKBEdit(Form);
            pushButton_account->hide();
            pushButton_account->setStyleSheet(CommonParam::m_sStyle16);
            pushButton_account->move(295,119);
            pushButton_account->resize(448,47);
            pushButton_account->setPlaceholderText(tr("At least 6 letters or numbers"));
            pushButton_account->setObjectName(QString::fromUtf8("pushButton_account"));
            //            m_pshorizontalLayout->addWidget(pushButton_account);
            //            verticalLayout->addLayout(m_pshorizontalLayout);
            m_pAccountInfo =new QLabel();
            m_pAccountInfo->setStyleSheet("font:18px");
            //            m_pshorizontalLayout->addWidget(m_pAccountInfo);

            pushButton_name = new CKBEdit(Form);
            pushButton_name->setStyleSheet(CommonParam::m_sStyle16);
            pushButton_name->move(295,184);
            pushButton_name->resize(157,47);
            pushButton_name->setObjectName(QString::fromUtf8("pushButton_name"));

            //            verticalLayout->addWidget(pushButton_name);

            pushButton_genderMan = new QCheckBox(Form);
            pushButton_genderMan->setChecked(true);
            pushButton_genderMan->setObjectName(QString::fromUtf8("pushButton_gender"));
            pushButton_genderMan->move(568,191);
            pushButton_genderMan->setStyleSheet(CommonParam::m_sStyle17);
            pushButton_genderWoman = new QCheckBox(Form);
            pushButton_genderWoman->move(668,191);
            pushButton_genderWoman->setStyleSheet(CommonParam::m_sStyle17);
            //            verticalLayout->addWidget(pushButton_gender);

            //            pushButton_bot = new QLabelLineInput(Form);
            //            pushButton_bot->setObjectName(QString::fromUtf8("pushButton_bot"));

            //            verticalLayout->addWidget(pushButton_bot);

            //            verticalLayout->addLayout(createBirthInput());
            createBirthInput();
            pushButton_mobile = new CKBEdit(Form);
            pushButton_mobile->resize(449,47);
            pushButton_mobile->move(295,310);
            pushButton_mobile->setStyleSheet(CommonParam::m_sStyle16);
            pushButton_mobile->setObjectName(QString::fromUtf8("pushButton_mobile"));

            //            verticalLayout->addWidget(pushButton_mobile);

            //            pushButton_no = new QCheckButtonInput(QCheckButtonInput::CHECK_RIGHT,Form);
            //            pushButton_no->setObjectName(QString::fromUtf8("pushButton_no"));

            //            verticalLayout->addWidget(pushButton_no);

            pushButton_have = new QCheckBox(Form);
            pushButton_have->setObjectName(QString::fromUtf8("pushButton_have"));

            pushButton_have->move(407,376);
            pushButton_have->setStyleSheet(CommonParam::m_sStyle18);
            //            verticalLayout->addWidget(pushButton_have);
            //            verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            //            verticalLayout->addItem(verticalSpacer_2);
            //            horizontalLayout->addLayout(verticalLayout);
        }
        //        else
        //        {
        ////            horizontalLayout->setSpacing(24);
        ////            horizontalLayout->setContentsMargins(96, 32, 96, 32);
        ////            verticalLayout = new QVBoxLayout();
        ////            verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        //            pushButton_account = new QLabelLineInput(Form);
        //            pushButton_account->setObjectName(QString::fromUtf8("pushButton_account"));

        ////            m_pshorizontalLayout->addWidget(pushButton_account);
        ////            verticalLayout->addLayout(m_pshorizontalLayout);
        //            m_pAccountInfo =new QLabel();
        //            m_pAccountInfo->setStyleSheet("font:48px");
        ////            m_pshorizontalLayout->addWidget(m_pAccountInfo);

        //            pushButton_name = new QLabelLineInput(Form);
        //            pushButton_name->setObjectName(QString::fromUtf8("pushButton_name"));

        ////            verticalLayout->addWidget(pushButton_name);

        //            pushButton_gender = new QLabelCheckBoxInput(Qt::white,Form);
        //            pushButton_gender->setObjectName(QString::fromUtf8("pushButton_gender"));

        ////            verticalLayout->addWidget(pushButton_gender);

        ////            pushButton_bot = new QLabelLineInput(Form);
        ////            pushButton_bot->lineEdit->hide();
        ////            pushButton_bot->setObjectName(QString::fromUtf8("pushButton_bot"));

        ////            verticalLayout->addWidget(pushButton_bot);

        ////            verticalLayout->addLayout(createBirthInput());

        //            pushButton_mobile = new QLabelLineInput(Form);
        //            pushButton_mobile->setObjectName(QString::fromUtf8("pushButton_mobile"));

        ////            verticalLayout->addWidget(pushButton_mobile);


        ////            horizontalLayout->addLayout(verticalLayout);

        ////            verticalLayout_2 = new QVBoxLayout();
        ////            verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ////            verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ////            verticalLayout_2->addItem(verticalSpacer);

        ////            pushButton_no = new QCheckButtonInput(QCheckButtonInput::CHECK_RIGHT,Form);
        ////            pushButton_no->setObjectName(QString::fromUtf8("pushButton_no"));

        ////            verticalLayout_2->addWidget(pushButton_no);

        ////            verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ////            verticalLayout_2->addItem(verticalSpacer_2);

        //            pushButton_have = new QCheckButtonInput(QCheckButtonInput::CHECK_RIGHT,Form);
        //            pushButton_have->setObjectName(QString::fromUtf8("pushButton_have"));

        ////            verticalLayout_2->addWidget(pushButton_have);

        ////            verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ////            verticalLayout_2->addItem(verticalSpacer_3);


        ////            horizontalLayout->addLayout(verticalLayout_2);
        //        }

        pushButton_mobile->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);

        retranslateUi(Form);
        //        connect(pushButton_bot->lineEdit,SIGNAL(clicked(int)),this,SLOT(ShowTimePicker(int)));
        QMetaObject::connectSlotsByName(Form);
    } // setupUi

};

class QUserMobileUI: public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserMobileUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QUserMobileUI();
    void Update(QString param);
    bool OnConfirm();
    bool OnPrevious();
public slots:
    void UserMobileQuery();
    void timeout();
    void OnUserInput();
public:
    QTimer*      timer;
    quint32      time_out_times;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabelLineInput *lineinput_mobile_zone;
    QLabelLineInput *lineinput_mobile;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QLabelLineInput *lineinput_code;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserMobileUI"));

        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);
        lineinput_mobile_zone= new QLabelLineInput(Form);
        lineinput_mobile_zone->setObjectName(QString::fromUtf8("lineinput_mobile_zone"));
        verticalLayout->addWidget(lineinput_mobile_zone);

        lineinput_mobile = new QLabelLineInput(Form);
        lineinput_mobile->setObjectName(QString::fromUtf8("lineinput_mobile"));

        verticalLayout->addWidget(lineinput_mobile);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        lineinput_code = new QLabelLineInput(Form);
        lineinput_code->setObjectName(QString::fromUtf8("lineinput_code"));
        verticalLayout->addWidget(lineinput_code);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 1);

        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        horizontalLayout->addItem(horizontalSpacer_2);
        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 2);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QUserSelectHistoryUI: public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserSelectHistoryUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserSelectHistoryUI();
    void Update(QString param);
    bool OnConfirm();
    virtual bool OnPrevious();
protected:
    void UpdateUI(int lan);
private slots:
    void btn_clicked();
    void OnClickedNo(bool);
public:
    QString     historycode;
    QToolButton* m_pUser;
    QCheckBox *m_pcbNoHave;
    //    QGridLayout *gridLayout;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserSelectHistoryUI"));

        m_pUser=new QToolButton(Form);
        m_pcbNoHave=new QCheckBox(Form);

        //        gridLayout = new QGridLayout(Form);
        //        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
            //            gridLayout->setContentsMargins(4, 4, 4, 4);
        }
        else
        {
            //            gridLayout->setContentsMargins(32, 32, 32, 32);
        }
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QUserSelectHistoryDetailUI: public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserSelectHistoryDetailUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserSelectHistoryDetailUI();
    void Update(QString param);
    bool OnConfirm();
    bool OnPrevious();
    QStringList codeList;
    QToolButton* m_pUser;
private slots:
    void OnClicked(bool);
public:
    //    QHBoxLayout *gridLayout;
    //    QCheckBox*    toolBox;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserSelectHistoryDetailUI"));
        m_pUser=new QToolButton(Form);

        //        gridLayout = new QHBoxLayout(Form);
        //        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        //        gridLayout->setContentsMargins(0,0,0,0);
        //        toolBox = new QCheckBox(Form);
        //        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        //        gridLayout->addWidget(toolBox);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
    void retranslateUi(QWidget *)
    {
        m_pUser->setStyleSheet(CommonParam::m_sStyle10);
        m_pUser->setText(tr("History"));
        m_pUser->resize(151,47);
        if(MedctrlConfManager::instance()->getCurrentConf()->getLanguage() == 2)
        {
            m_pUser->resize(251,47);
        }
        m_pUser->move(192,21);
    }
};

class QUserOutputUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserOutputUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserOutputUI();
    void    Update(QString param);
    void    OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
private slots:
    void StateChange(bool b);
    void ValueChange1();
    void ValueChange2();
    void ValueChange3();
    void ValueChange4();
    void ValueChange5();
    void ValueChange6();
    void ValueChange7();
    void RepeatTest();
    void ShowAdvAndNet();
public:
    QGridLayout *gridLayout;
    QLabelSwicthInput* debugOnOff;
    QLabelLineInput* m_pSBoxwaterHlev;
    QLabelLineInput* m_pSBoxwaterLlev;
    QLabelLineInput* m_pS2DuanShiHuaBeiHlev;
    QLabelLineInput* m_pS2DuanShiHuaBeiLlev;
    QLabelLineInput* m_pS4DuanShiHuaBeilev;
    QLabelLineInput* m_pSWuHualev;
    QLabelLineInput* m_pSQingSHuiBeilev;
    QLabelLineInput* m_pRepeatPin;
    QLabelLineInput* m_pRepeatCount;
    QPushButton* m_RepeatTest;
    QLabelSwicthInput* m_pShowAdvAndNet;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {

        //        int col = 0,row = 0,limit=4;
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserOutputUI"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0,0,0,0);
        gridLayout->setSpacing(0);


        m_pSBoxwaterHlev = new QLabelLineInput(Form);
        m_pSBoxwaterHlev->label->setText("水箱高");
        gridLayout->addWidget(m_pSBoxwaterHlev,0,0,1,1);

        m_pSBoxwaterLlev= new QLabelLineInput(Form);
        m_pSBoxwaterLlev->label->setText("水箱低");
        gridLayout->addWidget(m_pSBoxwaterLlev,0,1,1,1);

        m_pS2DuanShiHuaBeiHlev= new QLabelLineInput(Form);
        m_pS2DuanShiHuaBeiHlev->label->setText("2段湿化杯高");
        gridLayout->addWidget(m_pS2DuanShiHuaBeiHlev,1,0,1,1);

        m_pS2DuanShiHuaBeiLlev= new QLabelLineInput(Form);
        m_pS2DuanShiHuaBeiLlev->label->setText("2段湿化杯低");
        gridLayout->addWidget(m_pS2DuanShiHuaBeiLlev,1,1,1,1);

        m_pS4DuanShiHuaBeilev= new QLabelLineInput(Form);
        m_pS4DuanShiHuaBeilev->label->setText("4段湿化杯");
        gridLayout->addWidget(m_pS4DuanShiHuaBeilev,1,2,1,1);

        m_pSWuHualev= new QLabelLineInput(Form);
        m_pSWuHualev->label->setText("雾化高");
        gridLayout->addWidget(m_pSWuHualev,2,0,1,1);


        m_pSQingSHuiBeilev= new QLabelLineInput(Form);
        m_pSQingSHuiBeilev->label->setText("氢水杯高");
        gridLayout->addWidget(m_pSQingSHuiBeilev,3,0,1,1);

        m_pRepeatPin= new QLabelLineInput(Form);
        m_pRepeatPin->label->setText("PIN");
        gridLayout->addWidget(m_pRepeatPin,3,1,1,1);
;
        m_pRepeatCount= new QLabelLineInput(Form);
        m_pRepeatCount->label->setText("次数");
        gridLayout->addWidget(m_pRepeatCount,3,2,1,1);

        m_RepeatTest= new QPushButton(Form);
        m_RepeatTest->setText("压力测试");
        gridLayout->addWidget(m_RepeatTest,3,3,1,1);

        m_pShowAdvAndNet=new QLabelSwicthInput(Form);
        m_pShowAdvAndNet->label->setText("显示网络高级");
        gridLayout->addWidget(m_pShowAdvAndNet,4,0,1,1);

        connect(m_pSBoxwaterHlev->lineEdit,SIGNAL(textChanged1()),this,SLOT(ValueChange1()));
        connect(m_pSBoxwaterLlev->lineEdit,SIGNAL(textChanged1()),this,SLOT(ValueChange2()));
        connect(m_pS2DuanShiHuaBeiHlev->lineEdit,SIGNAL(textChanged1()),this,SLOT(ValueChange3()));
        connect(m_pS2DuanShiHuaBeiLlev->lineEdit,SIGNAL(textChanged1()),this,SLOT(ValueChange4()));
        connect(m_pS4DuanShiHuaBeilev->lineEdit,SIGNAL(textChanged1()),this,SLOT(ValueChange5()));
        connect(m_pSWuHualev->lineEdit,SIGNAL(textChanged1()),this,SLOT(ValueChange6()));

        connect(m_pSQingSHuiBeilev->lineEdit,SIGNAL(textChanged1()),this,SLOT(ValueChange7()));

        connect(m_RepeatTest,SIGNAL(clicked()),this,SLOT(RepeatTest()));

        connect(m_pShowAdvAndNet->onoff,SIGNAL(StateChange(bool)),this,SLOT(ShowAdvAndNet()));

        //        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
        //            CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        //        {
        //            limit=2;
        //        }
        //        else
        //        {
        //            limit=4;
        //        }
        //        if ( zTemplateApp::Get() != NULL )
        //        {
        //            QHash<int,QGPIOEntry*>::const_iterator i = zTemplateApp::Get()->ioInput.constBegin();
        //            while (i != zTemplateApp::Get()->ioInput.constEnd())
        //            {
        //                QLabelSwicthInput* newSwitch = new QLabelSwicthInput(Form);
        //                newSwitch->label->setText(i.value()->GetDescription());
        //                newSwitch->onoff->setProperty("number",i.value()->gpio);
        //                gridLayout->addWidget(newSwitch,col,row);
        //                row++;
        //                if ( row >= limit )
        //                {
        //                    col++;
        //                    row = 0;
        //                }
        //                ++i;
        //            }
        //            col++;
        //            row = 0;
        //            i = zTemplateApp::Get()->ioOutput.constBegin();
        //            while (i != zTemplateApp::Get()->ioOutput.constEnd())
        //            {
        //                QLabelSwicthInput* newSwitch = new QLabelSwicthInput(Form);
        //                newSwitch->label->setText(i.value()->GetDescription());
        //                newSwitch->onoff->setProperty("number",i.value()->gpio);
        //                connect(newSwitch->onoff,SIGNAL(StateChange(bool)),this,SLOT(StateChange(bool)));
        //                gridLayout->addWidget(newSwitch,col,row);
        //                row++;
        //                if ( row >= limit )
        //                {
        //                    col++;
        //                    row = 0;
        //                }
        //                ++i;
        //            }
        //        }
        //        debugOnOff = new QLabelSwicthInput(Form);
        //        debugOnOff->onoff->setProperty("number",3000);
        //        connect(debugOnOff->onoff,SIGNAL(StateChange(bool)),this,SLOT(StateChange(bool)));
        //        gridLayout->addWidget(debugOnOff,col+1,0,1,2);
        //        retranslateUi(Form);
        //        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QUserDefaultUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserDefaultUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserDefaultUI();
    void Update(QString param);
private slots:
    void textChanged();
public:
    QGridLayout *gridLayout;
    QLabelLineInput* box_tempture_gate;//水箱温度
    QLabelLineInput* box_tempture_warn;//水箱温度停止工作
    QLabelLineInput* inb_tempture_gate;//雾化温度,停止
    QLabelLineInput* inb_tempture_warn;//保存为补水时一杯水时间s
    QLabelLineInput* power_change_time_limit;//电极互换
    QLabelLineInput* gas_time_limit;//换气时间设定
    QLabelLineInput* liqiud_time_limit;//换液时间设定
    QLabelLineInput* power_low_v;
    QLabelLineInput* power_mid_v;
    QLabelLineInput* power_high_v;
    QLabelLineInput* hydrogen_display_low;
    QLabelLineInput* hydrogen_display_mid;
    QLabelLineInput* hydrogen_display_high;
    QLabelLineInput* outputtime_limit;
    QLabelLineInput* maintaince_limit;
    QLabelLineInput* lease_time_limit;
    QLabelLineInput* device_superadmin;
    QLabelLineInput* device_superadminp;
    QLabelLineInput* device_super;
    QLabelLineInput* hydrogen_fanspeed;
    QLabelLineInput* single_wateradd_timelimit;
    QLabelLineInput* adjust_power_basic;
    QLabelLineInput* waterTankTemperature;
    QLabelLineInput* CheckAddWaterTime;
    QSlider*         device_powervalue;
    QLabel*          device_fv;
    QSlider*         device_fanvalue;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserDefaultUI"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
            device_superadmin = new QLabelLineInput(Form);
            device_superadmin->setObjectName(QString::fromUtf8("device_superadmin"));
            gridLayout->addWidget(device_superadmin,0,0,1,1);
            device_superadminp = new QLabelLineInput(Form);
            device_superadminp->setObjectName(QString::fromUtf8("device_superadminp"));
            gridLayout->addWidget(device_superadminp,0,1,1,1);

            inb_tempture_gate = new QLabelLineInput(Form);
            inb_tempture_gate->setObjectName(QString::fromUtf8("inb_tempture_gate"));
            gridLayout->addWidget(inb_tempture_gate,1,0,1,1);
            inb_tempture_warn = new QLabelLineInput(Form);
            inb_tempture_warn->setObjectName(QString::fromUtf8("inb_tempture_warn"));
            gridLayout->addWidget(inb_tempture_warn,1,1,1,1);

            power_change_time_limit = new QLabelLineInput(Form);
            power_change_time_limit->setObjectName(QString::fromUtf8("power_change_time_limit"));
            gridLayout->addWidget(power_change_time_limit,2,0,1,1);
            gas_time_limit = new QLabelLineInput(Form);
            gas_time_limit->setObjectName(QString::fromUtf8("gas_time_limit"));
            gridLayout->addWidget(gas_time_limit,2,1,1,1);
            liqiud_time_limit = new QLabelLineInput(Form);
            liqiud_time_limit->setObjectName(QString::fromUtf8("liqiud_time_limit"));
            gridLayout->addWidget(liqiud_time_limit,3,0,1,1);
            power_low_v = new QLabelLineInput(Form);
            power_low_v->setObjectName(QString::fromUtf8("power_low_v"));
            gridLayout->addWidget(power_low_v,3,1,1,1);

            power_mid_v = new QLabelLineInput(Form);
            power_mid_v->setObjectName(QString::fromUtf8("power_mid_v"));
            //            gridLayout->addWidget(power_mid_v,5,0,1,1);
            power_high_v = new QLabelLineInput(Form);
            power_high_v->setObjectName(QString::fromUtf8("power_high_v"));
            gridLayout->addWidget(power_high_v,4,0,1,1);
            hydrogen_display_low = new QLabelLineInput(Form);
            hydrogen_display_low->setObjectName(QString::fromUtf8("hydrogen_display_low"));
            //            gridLayout->addWidget(hydrogen_display_low,6,0,1,1);
            hydrogen_display_mid = new QLabelLineInput(Form);
            hydrogen_display_mid->setObjectName(QString::fromUtf8("hydrogen_display_mid"));
            //            gridLayout->addWidget(hydrogen_display_mid,6,1,1,1);

            hydrogen_display_high = new QLabelLineInput(Form);
            hydrogen_display_high->setObjectName(QString::fromUtf8("hydrogen_display_high"));
            //            gridLayout->addWidget(hydrogen_display_high,7,0,1,1);
            outputtime_limit = new QLabelLineInput(Form);
            outputtime_limit->setObjectName(QString::fromUtf8("outputtime_limit"));
            gridLayout->addWidget(outputtime_limit,4,1,1,1);
            lease_time_limit = new QLabelLineInput(Form);
            lease_time_limit->setObjectName(QString::fromUtf8("lease_time_limit"));
            gridLayout->addWidget(lease_time_limit,5,0,1,1);
            maintaince_limit = new QLabelLineInput(Form);
            maintaince_limit->setObjectName(QString::fromUtf8("maintaince_limit"));
            gridLayout->addWidget(maintaince_limit,5,1,1,1);

            box_tempture_gate = new QLabelLineInput(Form);
            box_tempture_gate->setObjectName(QString::fromUtf8("box_tempture_gate"));
            gridLayout->addWidget(box_tempture_gate,6,0,1,1);
            box_tempture_warn = new QLabelLineInput(Form);
            box_tempture_warn->setObjectName(QString::fromUtf8("box_tempture_warn"));
            gridLayout->addWidget(box_tempture_warn,6,1,1,1);

            device_super = new QLabelLineInput(Form);
            device_super->setObjectName(QString::fromUtf8("device_super"));
            gridLayout->addWidget(device_super,7,0,1,1);
            hydrogen_fanspeed = new QLabelLineInput(Form);
            hydrogen_fanspeed->setObjectName(QString::fromUtf8("hydrogen_fanspeed"));
            gridLayout->addWidget(hydrogen_fanspeed,7,1,1,1);
            single_wateradd_timelimit= new QLabelLineInput(Form);
            single_wateradd_timelimit->setObjectName(QString::fromUtf8("single_wateradd_timelimit"));
            gridLayout->addWidget(single_wateradd_timelimit,8,0,1,1);

            waterTankTemperature = new QLabelLineInput(Form);
            waterTankTemperature->setObjectName(QString::fromUtf8("waterTankTemperature"));
            gridLayout->addWidget(waterTankTemperature,8,1,1,1);

            CheckAddWaterTime = new QLabelLineInput(Form);
            CheckAddWaterTime->setObjectName(QString::fromUtf8("CheckAddWaterTime"));
            gridLayout->addWidget(CheckAddWaterTime,8,2,1,1);

            adjust_power_basic= new QLabelLineInput(Form);
            adjust_power_basic->setObjectName(QString::fromUtf8("adjust_power_basic"));
            gridLayout->addWidget(adjust_power_basic,9,0,1,1);
            device_powervalue = new QSlider(Qt::Horizontal,Form);
            device_powervalue->setObjectName(QString::fromUtf8("device_powervalue"));
            device_powervalue->setRange(0,20);
            device_powervalue->setValue(10);
            gridLayout->addWidget(device_powervalue,10,0,1,3);

            device_fv= new QLabel(Form);
            device_fv->setObjectName(QString::fromUtf8("device_fv"));

            QHBoxLayout *pHLayout = new QHBoxLayout;
            pHLayout->addWidget(device_fv);

            //            gridLayout->addWidget(device_fv,11,0,1,1);
            device_fanvalue = new QSlider(Qt::Horizontal,Form);
            device_fanvalue->setObjectName(QString::fromUtf8("device_fanvalue"));
            device_fanvalue->setRange(0,100);

            pHLayout->addWidget(device_fanvalue);
            gridLayout->addLayout(pHLayout, 11, 0, 1, 3);

            //            gridLayout->addWidget(device_fanvalue,11,1,1,3);

            //            power_mid_v->setVisible(false);
            hydrogen_display_low->setVisible(false);
            hydrogen_display_mid->setVisible(false);
            hydrogen_display_high->setVisible(false);
        }
        else
        {
            device_superadmin = new QLabelLineInput(Form);
            device_superadmin->setObjectName(QString::fromUtf8("device_superadmin"));
            gridLayout->addWidget(device_superadmin,0,0,1,1);
            device_superadminp = new QLabelLineInput(Form);
            device_superadminp->setObjectName(QString::fromUtf8("device_superadminp"));
            gridLayout->addWidget(device_superadminp,0,1,1,1);

            inb_tempture_gate = new QLabelLineInput(Form);
            inb_tempture_gate->setObjectName(QString::fromUtf8("inb_tempture_gate"));
            gridLayout->addWidget(inb_tempture_gate,0,2,1,1);
            inb_tempture_warn = new QLabelLineInput(Form);
            inb_tempture_warn->setObjectName(QString::fromUtf8("inb_tempture_warn"));
            gridLayout->addWidget(inb_tempture_warn,0,3,1,1);

            power_change_time_limit = new QLabelLineInput(Form);
            power_change_time_limit->setObjectName(QString::fromUtf8("power_change_time_limit"));
            gridLayout->addWidget(power_change_time_limit,1,0,1,1);
            gas_time_limit = new QLabelLineInput(Form);
            gas_time_limit->setObjectName(QString::fromUtf8("gas_time_limit"));
            gridLayout->addWidget(gas_time_limit,1,1,1,1);
            liqiud_time_limit = new QLabelLineInput(Form);
            liqiud_time_limit->setObjectName(QString::fromUtf8("liqiud_time_limit"));
            gridLayout->addWidget(liqiud_time_limit,1,2,1,1);
            power_low_v = new QLabelLineInput(Form);
            power_low_v->setObjectName(QString::fromUtf8("power_low_v"));
            gridLayout->addWidget(power_low_v,1,3,1,1);

            power_mid_v = new QLabelLineInput(Form);
            power_mid_v->setObjectName(QString::fromUtf8("power_mid_v"));
            gridLayout->addWidget(power_mid_v,2,0,1,1);
            power_high_v = new QLabelLineInput(Form);
            power_high_v->setObjectName(QString::fromUtf8("power_high_v"));
            gridLayout->addWidget(power_high_v,2,1,1,1);
            hydrogen_display_low = new QLabelLineInput(Form);
            hydrogen_display_low->setObjectName(QString::fromUtf8("hydrogen_display_low"));
            gridLayout->addWidget(hydrogen_display_low,2,2,1,1);
            hydrogen_display_mid = new QLabelLineInput(Form);
            hydrogen_display_mid->setObjectName(QString::fromUtf8("hydrogen_display_mid"));
            gridLayout->addWidget(hydrogen_display_mid,2,3,1,1);

            hydrogen_display_high = new QLabelLineInput(Form);
            hydrogen_display_high->setObjectName(QString::fromUtf8("hydrogen_display_high"));
            gridLayout->addWidget(hydrogen_display_high,3,0,1,1);
            outputtime_limit = new QLabelLineInput(Form);
            outputtime_limit->setObjectName(QString::fromUtf8("outputtime_limit"));
            gridLayout->addWidget(outputtime_limit,3,1,1,1);
            lease_time_limit = new QLabelLineInput(Form);
            lease_time_limit->setObjectName(QString::fromUtf8("lease_time_limit"));
            gridLayout->addWidget(lease_time_limit,3,2,1,1);
            maintaince_limit = new QLabelLineInput(Form);
            maintaince_limit->setObjectName(QString::fromUtf8("maintaince_limit"));
            gridLayout->addWidget(maintaince_limit,3,3,1,1);

            box_tempture_gate = new QLabelLineInput(Form);
            box_tempture_gate->setObjectName(QString::fromUtf8("box_tempture_gate"));
            gridLayout->addWidget(box_tempture_gate,4,0,1,1);
            box_tempture_warn = new QLabelLineInput(Form);
            box_tempture_warn->setObjectName(QString::fromUtf8("box_tempture_warn"));
            gridLayout->addWidget(box_tempture_warn,4,1,1,1);

            device_super = new QLabelLineInput(Form);
            device_super->setObjectName(QString::fromUtf8("device_super"));
            gridLayout->addWidget(device_super,4,2,1,1);
            hydrogen_fanspeed = new QLabelLineInput(Form);
            hydrogen_fanspeed->setObjectName(QString::fromUtf8("hydrogen_fanspeed"));
            gridLayout->addWidget(hydrogen_fanspeed,4,3,1,1);
            single_wateradd_timelimit= new QLabelLineInput(Form);
            single_wateradd_timelimit->setObjectName(QString::fromUtf8("single_wateradd_timelimit"));
            gridLayout->addWidget(single_wateradd_timelimit,5,0,1,1);

            waterTankTemperature = new QLabelLineInput(Form);
            waterTankTemperature->setObjectName(QString::fromUtf8("waterTankTemperature"));
            gridLayout->addWidget(waterTankTemperature,5,1,1,1);

            CheckAddWaterTime = new QLabelLineInput(Form);
            CheckAddWaterTime->setObjectName(QString::fromUtf8("CheckAddWaterTime"));
            gridLayout->addWidget(CheckAddWaterTime,5,2,1,1);

            adjust_power_basic= new QLabelLineInput(Form);
            adjust_power_basic->setObjectName(QString::fromUtf8("adjust_power_basic"));
            gridLayout->addWidget(adjust_power_basic,6,0,1,1);
            device_powervalue = new QSlider(Qt::Horizontal,Form);
            device_powervalue->setObjectName(QString::fromUtf8("device_powervalue"));
            device_powervalue->setRange(0,20);
            device_powervalue->setValue(10);
            gridLayout->addWidget(device_powervalue,6,1,1,3);
            device_fv= new QLabel(Form);
            device_fv->setObjectName(QString::fromUtf8("device_fv"));
            gridLayout->addWidget(device_fv,7,0,1,1);
            device_fanvalue = new QSlider(Qt::Horizontal,Form);
            device_fanvalue->setObjectName(QString::fromUtf8("device_fanvalue"));
            device_fanvalue->setRange(0,100);
            gridLayout->addWidget(device_fanvalue,7,1,1,3);
        }

        connect(device_fanvalue, SIGNAL(valueChanged(int)), this, SLOT(fanValueChange(int)));

        box_tempture_gate->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);//水箱温度
        box_tempture_warn->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);//水箱温度停止工作
        inb_tempture_gate->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);//雾化温度,停止
        inb_tempture_warn->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);//保存为补水时一杯水时间s
        power_change_time_limit->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);//电极互换
        gas_time_limit->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);//换气时间设定
        liqiud_time_limit->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);//换液时间设定
        power_low_v->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        power_mid_v->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        power_high_v->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        hydrogen_display_low->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        hydrogen_display_mid->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        hydrogen_display_high->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        outputtime_limit->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        maintaince_limit->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        lease_time_limit->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        device_super->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        hydrogen_fanspeed->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        single_wateradd_timelimit->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        adjust_power_basic->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);

        retranslateUi(Form);

        box_tempture_gate->lineEdit->setProperty("number",1);
        box_tempture_warn->lineEdit->setProperty("number",2);
        inb_tempture_gate->lineEdit->setProperty("number",3);
        inb_tempture_warn->lineEdit->setProperty("number",4);
        power_change_time_limit->lineEdit->setProperty("number",5);
        gas_time_limit->lineEdit->setProperty("number",6);
        liqiud_time_limit->lineEdit->setProperty("number",7);
        power_low_v->lineEdit->setProperty("number",8);
        power_mid_v->lineEdit->setProperty("number",9);
        power_high_v->lineEdit->setProperty("number",10);
        hydrogen_display_low->lineEdit->setProperty("number",11);
        hydrogen_display_mid->lineEdit->setProperty("number",12);
        hydrogen_display_high->lineEdit->setProperty("number",13);
        outputtime_limit->lineEdit->setProperty("number",14);
        lease_time_limit->lineEdit->setProperty("number",15);
        maintaince_limit->lineEdit->setProperty("number",16);
        device_superadmin->lineEdit->setProperty("number",17);
        device_superadminp->lineEdit->setProperty("number",18);
        device_super->lineEdit->setProperty("number",19);
        hydrogen_fanspeed->lineEdit->setProperty("number",20);
        single_wateradd_timelimit->lineEdit->setProperty("number",21);
        waterTankTemperature->lineEdit->setProperty("number", 22);
        CheckAddWaterTime->lineEdit->setProperty("number", 23);
        QList<CKBEdit *> btn = this->findChildren<CKBEdit *>();
        foreach (CKBEdit * b, btn)
        {
            connect(b, SIGNAL(textChanged1()), this, SLOT(textChanged()));
        }
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QUserDefaultNetUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserDefaultNetUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserDefaultNetUI();
    void Update(QString param);
private slots:
    void textChanged();
public:
    QGridLayout*     gridLayout;
    //QLabelSwicthInput* net_ver_enabled;
    QLabelLineInput* net_ver_ip;
    QLabelLineInput* net_ver_port;

    //QLabelSwicthInput* net_rcv_enabled;
    QLabelLineInput* net_rcv_url;
    QLabelLineInput* net_rcv_port;

    //QLabelSwicthInput* net_snd_enabled;
    QLabelLineInput* net_snd_url;
    QLabelLineInput* net_snd_port;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserDefaultUI"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
            //net_ver_enabled = new QLabelSwicthInput(Form);
            //net_ver_enabled->setObjectName(QString::fromUtf8("net_ver_enabled"));
            //gridLayout->addWidget(net_ver_enabled,0,0,1,1);
            net_ver_ip = new QLabelLineInput(Form);
            net_ver_ip->setObjectName(QString::fromUtf8("net_ver_ip"));
            net_ver_ip->lineEdit->setProperty("number",1);
            gridLayout->addWidget(net_ver_ip,0,0,1,1);
            net_ver_port = new QLabelLineInput(Form);
            net_ver_port->setObjectName(QString::fromUtf8("net_ver_port"));
            net_ver_port->lineEdit->setProperty("number",2);
            gridLayout->addWidget(net_ver_port,1,0,1,1);

            //net_rcv_enabled = new QLabelSwicthInput(Form);
            //net_rcv_enabled->setObjectName(QString::fromUtf8("net_rcv_enabled"));
            //gridLayout->addWidget(net_rcv_enabled,1,0,1,1);
            net_rcv_url = new QLabelLineInput(Form);
            net_rcv_url->setObjectName(QString::fromUtf8("net_rcv_url"));
            net_rcv_url->lineEdit->setProperty("number",3);
            gridLayout->addWidget(net_rcv_url,2,0,1,1);
            net_rcv_port = new QLabelLineInput(Form);
            net_rcv_port->setObjectName(QString::fromUtf8("net_rcv_port"));
            net_rcv_port->lineEdit->setProperty("number",4);
            gridLayout->addWidget(net_rcv_port,3,0,1,1);

            //net_snd_enabled = new QLabelSwicthInput(Form);
            //net_snd_enabled->setObjectName(QString::fromUtf8("net_snd_enabled"));
            //gridLayout->addWidget(net_snd_enabled,2,0,1,1);
            net_snd_url = new QLabelLineInput(Form);
            net_snd_url->setObjectName(QString::fromUtf8("net_snd_url"));
            net_snd_url->lineEdit->setProperty("number",5);
            gridLayout->addWidget(net_snd_url,4,0,1,1);
            net_snd_port = new QLabelLineInput(Form);
            net_snd_port->setObjectName(QString::fromUtf8("net_snd_port"));
            net_snd_port->lineEdit->setProperty("number",6);
            gridLayout->addWidget(net_snd_port,5,0,1,1);
        }
        else
        {
            //net_ver_enabled = new QLabelSwicthInput(Form);
            //net_ver_enabled->setObjectName(QString::fromUtf8("net_ver_enabled"));
            //gridLayout->addWidget(net_ver_enabled,0,0,1,1);
            net_ver_ip = new QLabelLineInput(Form);
            net_ver_ip->setObjectName(QString::fromUtf8("net_ver_ip"));
            net_ver_ip->lineEdit->setProperty("number",1);
            gridLayout->addWidget(net_ver_ip,0,0,1,1);
            net_ver_port = new QLabelLineInput(Form);
            net_ver_port->setObjectName(QString::fromUtf8("net_ver_port"));
            net_ver_port->lineEdit->setProperty("number",2);
            gridLayout->addWidget(net_ver_port,0,1,1,1);

            //net_rcv_enabled = new QLabelSwicthInput(Form);
            //net_rcv_enabled->setObjectName(QString::fromUtf8("net_rcv_enabled"));
            //gridLayout->addWidget(net_rcv_enabled,1,0,1,1);
            net_rcv_url = new QLabelLineInput(Form);
            net_rcv_url->setObjectName(QString::fromUtf8("net_rcv_url"));
            net_rcv_url->lineEdit->setProperty("number",3);
            gridLayout->addWidget(net_rcv_url,1,0,1,1);
            net_rcv_port = new QLabelLineInput(Form);
            net_rcv_port->setObjectName(QString::fromUtf8("net_rcv_port"));
            net_rcv_port->lineEdit->setProperty("number",4);
            gridLayout->addWidget(net_rcv_port,1,1,1,1);

            //net_snd_enabled = new QLabelSwicthInput(Form);
            //net_snd_enabled->setObjectName(QString::fromUtf8("net_snd_enabled"));
            //gridLayout->addWidget(net_snd_enabled,2,0,1,1);
            net_snd_url = new QLabelLineInput(Form);
            net_snd_url->setObjectName(QString::fromUtf8("net_snd_url"));
            net_snd_url->lineEdit->setProperty("number",5);
            gridLayout->addWidget(net_snd_url,2,0,1,1);
            net_snd_port = new QLabelLineInput(Form);
            net_snd_port->setObjectName(QString::fromUtf8("net_snd_port"));
            net_snd_port->lineEdit->setProperty("number",6);
            gridLayout->addWidget(net_snd_port,2,1,1,1);
        }
        gridLayout->setColumnStretch(0,2);
        gridLayout->setColumnStretch(1,1);
        retranslateUi(Form);
        QList<CKBEdit *> btn = this->findChildren<CKBEdit *>();
        foreach (CKBEdit * b, btn)
        {
            connect(b, SIGNAL(textChanged1()), this, SLOT(textChanged()));
        }
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};


class QUserConfigUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserConfigUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserConfigUI();
    void Update(QString param);
public slots:
    void textChanged();
    void StateChange(bool b);
    void WaterTankLevelChange(bool b);
    void NebulizationTankTHighChange(bool b);
    void WaterCupLevelChange(bool b);
    void NebulizationWaterLevelChange(bool b);
    void PhoneVerificationChange(bool b);
    void NebulizationAlarmChange(bool b);
    void CommercialSettingChange(bool b);
    void CheckI2CChange(bool b);
    void RealtimeMonitorChange(bool b);
    void ProjectModeChange(bool b);
    void NebulizationIntervalChange(bool b);
    void HightTReplenishChange(bool b);
    void DisinfectChange(bool b);
    void GroupDisplayChange(bool b);
    void NetworkDisplayChange(bool b);
    //    void AdjustTimeEnableChange(bool bValue);
    void OnCalibration();
    void OnColorTest();
    void LeaseEndDateChange();
    void backgroundChange(bool bValue);
    void TestModeChange(bool bValue);
public:
    QGridLayout *gridLayout;
    QLabelLineInput* uuid;
    QLabelSwicthInput*  boxtOLD;
    QLabelSwicthInput*  neutOLD;

    QLabelSwicthInput*  inb_inv;
    QLabelSwicthInput*  add_ht;

    QLabelSwicthInput*  hcupCheck;
    QLabelSwicthInput*  icupCheck;
    QLabelSwicthInput*  telCheck;

    QLabelSwicthInput*  neutStop;
    QLabelSwicthInput*  workMode;
    QLabelSwicthInput*  debugUI;
    QLabelSwicthInput*  fatoryUI;
    QLabelSwicthInput*  CheckI2C;

    QLabelSwicthInput*  posionEnable;
    QLabelSwicthInput*  gndStatus;
    QLabelSwicthInput*  netStatus;
    //    QLabelSwicthInput*  m_qlsiTimeAdjustable;

    QPushButton*        push_calibration;
    QPushButton*        push_colortest;
    QLabelSwicthInput*  m_pBackgroundSwitch;
    QLabelLineInput* m_pLeaseEndDate;
    QLabelSwicthInput*  m_pTestMode;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserConfigUI"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0,0,300,0);
        gridLayout->setSpacing(0);

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
            boxtOLD = new QLabelSwicthInput(Form);
            boxtOLD->setObjectName(QString::fromUtf8("boxtOLD"));
            boxtOLD->onoff->setProperty("number",1<<DEV_BOXT_OLD);
            connect(boxtOLD->onoff,SIGNAL(StateChange(bool)),this,SLOT(WaterTankLevelChange(bool)));
            gridLayout->addWidget(boxtOLD,0,0,1,1);

            inb_inv = new QLabelSwicthInput(Form);
            inb_inv->setObjectName(QString::fromUtf8("inb_inv"));
            inb_inv->onoff->setProperty("number",1<<DEV_INB_INV_ON);
            connect(inb_inv->onoff,SIGNAL(StateChange(bool)),this,SLOT(NebulizationIntervalChange(bool)));
            gridLayout->addWidget(inb_inv,0,1,1,1);
            add_ht = new QLabelSwicthInput(Form);
            add_ht->setObjectName(QString::fromUtf8("add_ht"));
            add_ht->onoff->setProperty("number",1<<DEV_ADDWATER_HIGH_TEMP);
            connect(add_ht->onoff,SIGNAL(StateChange(bool)),this,SLOT(HightTReplenishChange(bool)));
            gridLayout->addWidget(add_ht,1,0,1,1);
            posionEnable = new QLabelSwicthInput(Form);
            posionEnable->setObjectName(QString::fromUtf8("posionEnable"));
            posionEnable->onoff->setProperty("number",1<<DEV_POSION_CLEAN_ENABLED);
            connect(posionEnable->onoff,SIGNAL(StateChange(bool)),this,SLOT(DisinfectChange(bool)));
            gridLayout->addWidget(posionEnable,1,1,1,1);

            gndStatus = new QLabelSwicthInput(Form);
            gndStatus->setObjectName(QString::fromUtf8("gndStatus"));
            gndStatus->onoff->setProperty("number",1<<DEV_GND_STATUS_ENABLED);
            connect(gndStatus->onoff,SIGNAL(StateChange(bool)),this,SLOT(GroupDisplayChange(bool)));

            gridLayout->addWidget(gndStatus,2,0,1,1);
            netStatus = new QLabelSwicthInput(Form);
            netStatus->setObjectName(QString::fromUtf8("netStatus"));
            netStatus->onoff->setProperty("number",1<<DEV_NET_STATUS_ENABLED);
            connect(netStatus->onoff,SIGNAL(StateChange(bool)),this,SLOT(NetworkDisplayChange(bool)));

            gridLayout->addWidget(netStatus,2,1,1,1);

            neutOLD = new QLabelSwicthInput(Form);
            neutOLD->setObjectName(QString::fromUtf8("neutOLD"));
            neutOLD->onoff->setProperty("number",1<<DEV_INBT_OLD);
            connect(neutOLD->onoff,SIGNAL(StateChange(bool)),this,SLOT(NebulizationTankTHighChange(bool)));
            gridLayout->addWidget(neutOLD,3,0,1,1);
            hcupCheck = new QLabelSwicthInput(Form);
            hcupCheck->setObjectName(QString::fromUtf8("hcupCheck"));
            hcupCheck->onoff->setProperty("number",1<<DEV_HCUPCHECK_ON);
            connect(hcupCheck->onoff,SIGNAL(StateChange(bool)),this,SLOT(WaterCupLevelChange(bool)));
            gridLayout->addWidget(hcupCheck,3,1,1,1);

            icupCheck = new QLabelSwicthInput(Form);
            icupCheck->setObjectName(QString::fromUtf8("icupCheck"));
            icupCheck->onoff->setProperty("number",1<<DEV_ICUPCHECK_ON);
            connect(icupCheck->onoff,SIGNAL(StateChange(bool)),this,SLOT(NebulizationWaterLevelChange(bool)));
            gridLayout->addWidget(icupCheck,4,0,1,1);
            telCheck = new QLabelSwicthInput(Form);
            telCheck->setObjectName(QString::fromUtf8("telCheck"));
            telCheck->onoff->setProperty("number",1<<DEV_TELE_CHECK_ON);
            connect(telCheck->onoff,SIGNAL(StateChange(bool)),this,SLOT(PhoneVerificationChange(bool)));
            gridLayout->addWidget(telCheck,4,1,1,1);
            neutStop = new QLabelSwicthInput(Form);
            neutStop->setObjectName(QString::fromUtf8("hcupCheck"));
            neutStop->onoff->setProperty("number",1<<DEV_INB_WARN_STOP);
            connect(neutStop->onoff,SIGNAL(StateChange(bool)),this,SLOT(NebulizationAlarmChange(bool)));
            gridLayout->addWidget(neutStop,5,0,1,1);

            workMode = new QLabelSwicthInput(Form);
            workMode->setObjectName(QString::fromUtf8("workMode"));
            workMode->onoff->setProperty("number",1<<DEV_WORKMODE_ON);
            connect(workMode->onoff,SIGNAL(StateChange(bool)),this,SLOT(CommercialSettingChange(bool)));
            gridLayout->addWidget(workMode,5,1,1,1);

            CheckI2C = new QLabelSwicthInput(Form);
            CheckI2C->label->setText("cI2C");
            CheckI2C->setObjectName(QString::fromUtf8("CheckI2C"));
            connect(CheckI2C->onoff,SIGNAL(StateChange(bool)),this,SLOT(CheckI2CChange(bool)));
            gridLayout->addWidget(CheckI2C,5,2,1,1);



            debugUI = new QLabelSwicthInput(Form);
            debugUI->setObjectName(QString::fromUtf8("debugUI"));
            debugUI->onoff->setProperty("number",1<<DEV_FACTORY_CHECK_ON);
            connect(debugUI->onoff,SIGNAL(StateChange(bool)),this,SLOT(RealtimeMonitorChange(bool)));
            gridLayout->addWidget(debugUI,6,0,1,1);
            fatoryUI = new QLabelSwicthInput(Form);
            fatoryUI->setObjectName(QString::fromUtf8("fatoryUI"));
            fatoryUI->onoff->setProperty("number",1<<DEV_FACTORY_ENGINEER_ON);
            connect(fatoryUI->onoff,SIGNAL(StateChange(bool)),this,SLOT(ProjectModeChange(bool)));
            gridLayout->addWidget(fatoryUI,6,1,1,1);

            push_calibration = new QPushButton(Form);
            push_calibration->setObjectName(QString::fromUtf8("push_calibration"));
            connect(push_calibration,SIGNAL(clicked()),this,SLOT(OnCalibration()));
            gridLayout->addWidget(push_calibration,7,0,1,1);
            push_colortest = new QPushButton(Form);
            push_colortest->setObjectName(QString::fromUtf8("push_colortest"));
            connect(push_colortest,SIGNAL(clicked()),this,SLOT(OnColorTest()));
            gridLayout->addWidget(push_colortest,7,1,1,1);

            uuid = new QLabelLineInput(Form);
            uuid->setObjectName(QString::fromUtf8("uuid"));
            uuid->lineEdit->setProperty("number",63);
            gridLayout->addWidget(uuid,8,0,1,1);

            m_pBackgroundSwitch = new QLabelSwicthInput(Form);
            m_pBackgroundSwitch->setObjectName(QString::fromUtf8("m_pBackgroundSwitch"));
            connect(m_pBackgroundSwitch->onoff,SIGNAL(StateChange(bool)),this,SLOT(backgroundChange(bool)));
            gridLayout->addWidget(m_pBackgroundSwitch,8,1,1,1);

            m_pLeaseEndDate=new QLabelLineInput(Form);
            m_pLeaseEndDate->lineEdit->SetText("365");
            m_pLeaseEndDate->setObjectName(QString::fromUtf8("m_pLeaseEndDate"));
            m_pLeaseEndDate->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
            connect(m_pLeaseEndDate->lineEdit,SIGNAL(textChanged1()),this,SLOT(LeaseEndDateChange()));
            gridLayout->addWidget(m_pLeaseEndDate,9,0,1,1);

            m_pTestMode = new QLabelSwicthInput(Form);
            m_pTestMode->setObjectName(QString::fromUtf8("m_pTestMode"));
            connect(m_pTestMode->onoff,SIGNAL(StateChange(bool)),this,SLOT(TestModeChange(bool)));
            gridLayout->addWidget(m_pTestMode,9,1,1,1);

        }
        else
        {
            boxtOLD = new QLabelSwicthInput(Form);
            boxtOLD->setObjectName(QString::fromUtf8("boxtOLD"));
            boxtOLD->onoff->setProperty("number",1<<DEV_BOXT_OLD);
            connect(boxtOLD->onoff,SIGNAL(StateChange(bool)),this,SLOT(WaterTankLevelChange(bool)));
            gridLayout->addWidget(boxtOLD,0,0,1,1);

            //            m_qlsiTimeAdjustable=new QLabelSwicthInput(Form);
            //            m_qlsiTimeAdjustable->setObjectName(QString::fromUtf8("m_qlsiTimeAdjustable"));
            //            m_qlsiTimeAdjustable->onoff->setProperty("number",CommonParam::m_bTimeAdjustAble);
            //            connect(m_qlsiTimeAdjustable->onoff,SIGNAL(StateChange(bool)),this,SLOT(AdjustTimeEnableChange(bool)));
            //            gridLayout->addWidget(m_qlsiTimeAdjustable,3,1,1,1);

            neutOLD = new QLabelSwicthInput(Form);
            neutOLD->setObjectName(QString::fromUtf8("neutOLD"));
            neutOLD->onoff->setProperty("number",1<<DEV_INBT_OLD);
            connect(neutOLD->onoff,SIGNAL(StateChange(bool)),this,SLOT(NebulizationTankTHighChange(bool)));
            gridLayout->addWidget(neutOLD,0,1,1,1);
            hcupCheck = new QLabelSwicthInput(Form);
            hcupCheck->setObjectName(QString::fromUtf8("hcupCheck"));
            hcupCheck->onoff->setProperty("number",1<<DEV_HCUPCHECK_ON);
            connect(hcupCheck->onoff,SIGNAL(StateChange(bool)),this,SLOT(WaterCupLevelChange(bool)));
            gridLayout->addWidget(hcupCheck,0,2,1,1);

            icupCheck = new QLabelSwicthInput(Form);
            icupCheck->setObjectName(QString::fromUtf8("icupCheck"));
            icupCheck->onoff->setProperty("number",1<<DEV_ICUPCHECK_ON);
            connect(icupCheck->onoff,SIGNAL(StateChange(bool)),this,SLOT(NebulizationWaterLevelChange(bool)));
            gridLayout->addWidget(icupCheck,1,0,1,1);
            telCheck = new QLabelSwicthInput(Form);
            telCheck->setObjectName(QString::fromUtf8("telCheck"));
            telCheck->onoff->setProperty("number",1<<DEV_TELE_CHECK_ON);
            connect(telCheck->onoff,SIGNAL(StateChange(bool)),this,SLOT(PhoneVerificationChange(bool)));
            gridLayout->addWidget(telCheck,1,1,1,1);
            neutStop = new QLabelSwicthInput(Form);
            neutStop->setObjectName(QString::fromUtf8("hcupCheck"));
            neutStop->onoff->setProperty("number",1<<DEV_INB_WARN_STOP);
            connect(neutStop->onoff,SIGNAL(StateChange(bool)),this,SLOT(NebulizationAlarmChange(bool)));
            gridLayout->addWidget(neutStop,1,2,1,1);

            workMode = new QLabelSwicthInput(Form);
            workMode->setObjectName(QString::fromUtf8("workMode"));
            workMode->onoff->setProperty("number",1<<DEV_WORKMODE_ON);
            connect(workMode->onoff,SIGNAL(StateChange(bool)),this,SLOT(CommercialSettingChange(bool)));
            gridLayout->addWidget(workMode,3,0,1,1);
            debugUI = new QLabelSwicthInput(Form);
            debugUI->setObjectName(QString::fromUtf8("debugUI"));
            debugUI->onoff->setProperty("number",1<<DEV_FACTORY_CHECK_ON);
            connect(debugUI->onoff,SIGNAL(StateChange(bool)),this,SLOT(RealtimeMonitorChange(bool)));
            gridLayout->addWidget(debugUI,3,1,1,1);
            fatoryUI = new QLabelSwicthInput(Form);
            fatoryUI->setObjectName(QString::fromUtf8("fatoryUI"));
            fatoryUI->onoff->setProperty("number",1<<DEV_FACTORY_ENGINEER_ON);
            connect(fatoryUI->onoff,SIGNAL(StateChange(bool)),this,SLOT(ProjectModeChange(bool)));
            gridLayout->addWidget(fatoryUI,3,2,1,1);
            inb_inv = new QLabelSwicthInput(Form);
            inb_inv->setObjectName(QString::fromUtf8("inb_inv"));
            inb_inv->onoff->setProperty("number",1<<DEV_INB_INV_ON);
            connect(inb_inv->onoff,SIGNAL(StateChange(bool)),this,SLOT(NebulizationIntervalChange(bool)));
            gridLayout->addWidget(inb_inv,4,0,1,1);
            add_ht = new QLabelSwicthInput(Form);
            add_ht->setObjectName(QString::fromUtf8("add_ht"));
            add_ht->onoff->setProperty("number",1<<DEV_ADDWATER_HIGH_TEMP);
            connect(add_ht->onoff,SIGNAL(StateChange(bool)),this,SLOT(HightTReplenishChange(bool)));

            gridLayout->addWidget(add_ht,4,1,1,1);
            posionEnable = new QLabelSwicthInput(Form);
            posionEnable->setObjectName(QString::fromUtf8("posionEnable"));
            posionEnable->onoff->setProperty("number",1<<DEV_POSION_CLEAN_ENABLED);
            connect(posionEnable->onoff,SIGNAL(StateChange(bool)),this,SLOT(DisinfectChange(bool)));

            gridLayout->addWidget(posionEnable,4,2,1,1);

            gndStatus = new QLabelSwicthInput(Form);
            gndStatus->setObjectName(QString::fromUtf8("gndStatus"));
            gndStatus->onoff->setProperty("number",1<<DEV_GND_STATUS_ENABLED);
            connect(gndStatus->onoff,SIGNAL(StateChange(bool)),this,SLOT(GroupDisplayChange(bool)));
            gridLayout->addWidget(gndStatus,5,0,1,1);
            netStatus = new QLabelSwicthInput(Form);
            netStatus->setObjectName(QString::fromUtf8("netStatus"));
            netStatus->onoff->setProperty("number",1<<DEV_NET_STATUS_ENABLED);
            connect(netStatus->onoff,SIGNAL(StateChange(bool)),this,SLOT(NetworkDisplayChange(bool)));
            gridLayout->addWidget(netStatus,5,1,1,1);

            CheckI2C = new QLabelSwicthInput(Form);
            CheckI2C->label->setText("cI2C");
            CheckI2C->setObjectName(QString::fromUtf8("CheckI2C"));
            connect(CheckI2C->onoff,SIGNAL(StateChange(bool)),this,SLOT(CheckI2CChange(bool)));
            gridLayout->addWidget(CheckI2C,5,3,1,1);

            push_calibration = new QPushButton(Form);
            push_calibration->setObjectName(QString::fromUtf8("push_calibration"));
            connect(push_calibration,SIGNAL(clicked()),this,SLOT(OnCalibration()));
            gridLayout->addWidget(push_calibration,5,2,1,1);
            push_colortest = new QPushButton(Form);
            push_colortest->setObjectName(QString::fromUtf8("push_colortest"));
            connect(push_colortest,SIGNAL(clicked()),this,SLOT(OnColorTest()));
            gridLayout->addWidget(push_colortest,6,0,1,1);

            uuid = new QLabelLineInput(Form);
            uuid->setObjectName(QString::fromUtf8("uuid"));
            uuid->lineEdit->setProperty("number",63);
            gridLayout->addWidget(uuid,6,1,1,1);

            m_pBackgroundSwitch = new QLabelSwicthInput(Form);
            m_pBackgroundSwitch->setObjectName(QString::fromUtf8("m_pBackgroundSwitch"));
            connect(m_pBackgroundSwitch->onoff,SIGNAL(StateChange(bool)),this,SLOT(backgroundChange(bool)));
            gridLayout->addWidget(m_pBackgroundSwitch,6,2,1,1);

            m_pLeaseEndDate=new QLabelLineInput(Form);
            m_pLeaseEndDate->lineEdit->SetText("365");
            m_pLeaseEndDate->setObjectName(QString::fromUtf8("m_pLeaseEndDate"));
            m_pLeaseEndDate->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
            connect(m_pLeaseEndDate->lineEdit,SIGNAL(textChanged1()),this,SLOT(LeaseEndDateChange()));
            gridLayout->addWidget(m_pLeaseEndDate,7,0,1,1);

            m_pTestMode = new QLabelSwicthInput(Form);
            m_pTestMode->setObjectName(QString::fromUtf8("m_pTestMode"));
            connect(m_pTestMode->onoff,SIGNAL(StateChange(bool)),this,SLOT(TestModeChange(bool)));
            gridLayout->addWidget(m_pTestMode,7,1,1,1);
        }
        retranslateUi(Form);
        connect(uuid->lineEdit,SIGNAL(textChanged1()),this,SLOT(textChanged()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};
class QServiceConfigUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QServiceConfigUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QServiceConfigUI();
    void Update(QString param);
public slots:

    void AdjustTimeEnableChange(bool bValue);
    void Is4INCHLowChange(bool bValue);
    void MachineTypeChange();

    void useTimeChange(bool bValue);
    void clinicalModeChange(bool bValue);
    void timesOfDayChange();
    void startTimeChange();
    void endTimeChange();
    void silenceMode();
    void gndMode(bool);
    void codeModeChange(bool bValue);
    void textChanged();
    void aecopdModeChange(bool bValue);
    void oldWaterLevelChange(bool bValue);
    void OnChangeAbsorbTimePerDay();
    void HydrogenMachineChange(bool bValue);
    void TwoAnd2_5EnableModeChange(bool bValue);
    void WuHuaReverse(bool bValue);
    void WuHuaEnable(bool bValue);
    void TempShow(bool bValue);
public:
    QLabelLineInput* alias;

    QLabelLineInput* totalWorkTime;
    QLabelLineInput* totalWorkHL;
    QLabelLineInput* mainTance;

    QLabelLineInput* startUp;

    QGridLayout *gridLayout;
    QLabelSwicthInput*  m_qlsiTimeAdjustable;
    QLabelSwicthInput*  m_b4INCHLow;
    QLabelLineInput*    m_sMachineType;

    QLabelSwicthInput* m_pUseTimeSwitch;
    QLabelSwicthInput* m_p18Mode;

    QLabelSwicthInput* m_pClinicalMode;
    QLabelLineInput*    m_pTimesOfDay;
    QLabelLineInput*    m_pStarTime;
    QLabelLineInput*    m_pEndTime;
    QLabelLineInput* m_pStm32SoftVer;
    QLabelLineInput* m_pStm32HardVer;

    QLabelSwicthInput* m_pSerialNumberMode;

    QLabelSwicthInput* m_pGndMode;
    QLabelSwicthInput* m_pAecopd;
    QLabelSwicthInput* m_pOldWaterLevel;

    QLabelLineInput* m_pAbsorbTimePerDay;

    QLabelSwicthInput* m_pHydrogenMachine;
    QLabelSwicthInput*  m_pTwoAnd2_5Enable;
    QLabelSwicthInput*  m_pWuHuaReverse;

    QLabelSwicthInput*  m_pWuHuaEnable;
    QLabelSwicthInput*  m_pTempShow;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QServiceConfigUI"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0,0,0,0);
        gridLayout->setSpacing(0);

        //        uuid = new QLabelLineInput(Form);
        //        uuid->setObjectName(QString::fromUtf8("uuid"));
        //        uuid->lineEdit->setProperty("number",63);
        //        gridLayout->addWidget(uuid,0,0,1,2);

        //        alias = new QLabelLineInput(Form);
        //        alias->setObjectName(QString::fromUtf8("alias"));
        //        alias->lineEdit->setProperty("number",64);
        //        gridLayout->addWidget(alias,1,0,1,2);
        m_qlsiTimeAdjustable=new QLabelSwicthInput(Form);
        m_qlsiTimeAdjustable->setObjectName(QString::fromUtf8("m_qlsiTimeAdjustable"));
        m_qlsiTimeAdjustable->onoff->setProperty("number",CommonParam::m_bTimeAdjustAble);
        connect(m_qlsiTimeAdjustable->onoff,SIGNAL(StateChange(bool)),this,SLOT(AdjustTimeEnableChange(bool)));
        gridLayout->addWidget(m_qlsiTimeAdjustable,1,0,1,1);

        m_b4INCHLow=new QLabelSwicthInput(Form);
        m_b4INCHLow->setObjectName(QString::fromUtf8("m_b4INCHLow"));
        m_b4INCHLow->onoff->setProperty("number",MedctrlConfManager::instance()->getCurrentConf()->getInch4Low());
        connect(m_b4INCHLow->onoff,SIGNAL(StateChange(bool)),this,SLOT(Is4INCHLowChange(bool)));
        gridLayout->addWidget(m_b4INCHLow,1,1,1,1);

        m_sMachineType=new QLabelLineInput(Form);
        m_sMachineType->setObjectName(QString::fromUtf8("m_sMachineType"));
        connect(m_sMachineType->lineEdit,SIGNAL(textChanged1()),this,SLOT(MachineTypeChange()));
        gridLayout->addWidget(m_sMachineType,2,0,1,1);
        //m_sMachineType->hide();


        m_pUseTimeSwitch = new QLabelSwicthInput(Form);
        m_pUseTimeSwitch->setObjectName(QString::fromUtf8("m_b4INCHLow"));
        connect(m_pUseTimeSwitch->onoff,SIGNAL(StateChange(bool)),this,SLOT(useTimeChange(bool)));
        gridLayout->addWidget(m_pUseTimeSwitch,2,1,1,1);

        m_pClinicalMode = new QLabelSwicthInput(Form);
        m_pClinicalMode->setObjectName(QString::fromUtf8("m_pClinicalMode"));
        connect(m_pClinicalMode->onoff,SIGNAL(StateChange(bool)),this,SLOT(clinicalModeChange(bool)));
        gridLayout->addWidget(m_pClinicalMode,3,0,1,1);

        m_pTimesOfDay = new QLabelLineInput(Form);
        m_pTimesOfDay->setObjectName(QString::fromUtf8("m_pTimesOfDay"));
        connect(m_pTimesOfDay->lineEdit,SIGNAL(textChanged1()),this,SLOT(timesOfDayChange()));
        gridLayout->addWidget(m_pTimesOfDay,3,1,1,1);

        m_pStarTime = new QLabelLineInput(Form);
        m_pStarTime->setObjectName(QString::fromUtf8("m_pStarTime"));
        connect(m_pStarTime->lineEdit,SIGNAL(textChanged1()),this,SLOT(startTimeChange()));
        gridLayout->addWidget(m_pStarTime,4,0,1,1);

        m_pEndTime = new QLabelLineInput(Form);
        m_pEndTime->setObjectName(QString::fromUtf8("m_pEndTime"));
        connect(m_pEndTime->lineEdit,SIGNAL(textChanged1()),this,SLOT(endTimeChange()));
        gridLayout->addWidget(m_pEndTime,4,1,1,1);

        m_p18Mode = new QLabelSwicthInput(Form);
        m_p18Mode->setObjectName(QString::fromUtf8("m_pSilenceMode"));
        connect(m_p18Mode->onoff,SIGNAL(StateChange(bool)),this,SLOT(silenceMode()));
        gridLayout->addWidget(m_p18Mode,5,0,1,1);

        m_pGndMode = new QLabelSwicthInput(Form);
        m_pGndMode->setObjectName(QString::fromUtf8("m_pGndMode"));
        connect(m_pGndMode->onoff,SIGNAL(StateChange(bool)),this,SLOT(gndMode(bool)));
        gridLayout->addWidget(m_pGndMode,5,1,1,1);

        m_pTimesOfDay->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        m_pStarTime->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        m_pEndTime->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);

        m_pSerialNumberMode = new QLabelSwicthInput(Form);
        m_pSerialNumberMode->setObjectName(QString::fromUtf8("m_pSerialNumberMode"));
        connect(m_pSerialNumberMode->onoff,SIGNAL(StateChange(bool)),this,SLOT(codeModeChange(bool)));
        gridLayout->addWidget(m_pSerialNumberMode,6,0,1,1);

        m_pStm32SoftVer = new QLabelLineInput(Form);
        m_pStm32SoftVer->setDisabled(true);
        m_pStm32SoftVer->setObjectName(QString::fromUtf8("m_pStm32SoftVer"));
        gridLayout->addWidget(m_pStm32SoftVer,6,1,1,1);

        m_pStm32HardVer = new QLabelLineInput(Form);
        m_pStm32HardVer->setObjectName(QString::fromUtf8("m_pStm32HardVer"));
        m_pStm32HardVer->setDisabled(true);
        gridLayout->addWidget(m_pStm32HardVer,7,0,1,1);

        alias = new QLabelLineInput(Form);
        alias->setObjectName(QString::fromUtf8("alias"));
        alias->lineEdit->setProperty("number",64);
        gridLayout->addWidget(alias,7,1,1,2);
        connect(alias->lineEdit,SIGNAL(textChanged1()),this,SLOT(textChanged()));

        totalWorkTime = new QLabelLineInput(Form);
        totalWorkTime->setObjectName(QString::fromUtf8("totalWorkTime"));
        gridLayout->addWidget(totalWorkTime,8,0,1,1);
        totalWorkHL = new QLabelLineInput(Form);
        totalWorkHL->setObjectName(QString::fromUtf8("totalWorkHL"));
        gridLayout->addWidget(totalWorkHL,8,1,1,1);
        mainTance = new QLabelLineInput(Form);
        mainTance->setObjectName(QString::fromUtf8("mainTance"));
        gridLayout->addWidget(mainTance,9,0,1,1);

        m_pAecopd = new QLabelSwicthInput(Form);
        m_pAecopd->setObjectName(QString::fromUtf8("m_pAecopd"));
        gridLayout->addWidget(m_pAecopd,9,1,1,1);
        connect(m_pAecopd->onoff,SIGNAL(StateChange(bool)),this,SLOT(aecopdModeChange(bool)));

        m_pOldWaterLevel = new QLabelSwicthInput(Form);
        m_pOldWaterLevel->setObjectName(QString::fromUtf8("m_pOldWaterLevel"));
        gridLayout->addWidget(m_pOldWaterLevel,10,0,1,1);
        connect(m_pOldWaterLevel->onoff,SIGNAL(StateChange(bool)),this,SLOT(oldWaterLevelChange(bool)));

        //            m_qlsiTimeAdjustable=new QLabelSwicthInput(Form);
        //            m_qlsiTimeAdjustable->setObjectName(QString::fromUtf8("m_qlsiTimeAdjustable"));
        //            m_qlsiTimeAdjustable->onoff->setProperty("number",CommonParam::m_bTimeAdjustAble);
        //            connect(m_qlsiTimeAdjustable->onoff,SIGNAL(StateChange(bool)),this,SLOT(AdjustTimeEnableChange(bool)));
        //            gridLayout->addWidget(m_qlsiTimeAdjustable,3,1,1,1);

        startUp = new QLabelLineInput(Form);
        startUp->setObjectName(QString::fromUtf8("startUp"));

        m_pAbsorbTimePerDay = new QLabelLineInput(Form);
        m_pAbsorbTimePerDay->setObjectName(QString::fromUtf8("m_pAbsorbTimePerDay"));
        connect(m_pAbsorbTimePerDay->lineEdit,SIGNAL(textChanged1()),this,SLOT(OnChangeAbsorbTimePerDay()));
        m_pAbsorbTimePerDay->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        gridLayout->addWidget(m_pAbsorbTimePerDay,10,1,1,1);

        m_pWuHuaEnable = new QLabelSwicthInput(Form);
        m_pWuHuaEnable->setObjectName(QString::fromUtf8("m_pWuHuaEnable"));
        connect(m_pWuHuaEnable->onoff,SIGNAL(StateChange(bool)),this,SLOT(WuHuaEnable(bool)));
        gridLayout->addWidget(m_pWuHuaEnable,10,2,1,1);

        m_pTempShow = new QLabelSwicthInput(Form);
        m_pTempShow->setObjectName(QString::fromUtf8("m_pTempShow"));
        connect(m_pTempShow->onoff,SIGNAL(StateChange(bool)),this,SLOT(TempShow(bool)));
        gridLayout->addWidget(m_pTempShow,9,2,1,1);


        m_pHydrogenMachine = new QLabelSwicthInput(Form);
        m_pHydrogenMachine->setObjectName(QString::fromUtf8("m_pHydrogenMachine"));
        connect(m_pHydrogenMachine->onoff,SIGNAL(StateChange(bool)),this,SLOT(HydrogenMachineChange(bool)));
        gridLayout->addWidget(m_pHydrogenMachine,11,0,1,1);

        m_pTwoAnd2_5Enable = new QLabelSwicthInput(Form);
        m_pTwoAnd2_5Enable->setObjectName(QString::fromUtf8("m_pTwoAnd2_5Enable"));
        connect(m_pTwoAnd2_5Enable->onoff,SIGNAL(StateChange(bool)),this,SLOT(TwoAnd2_5EnableModeChange(bool)));
        gridLayout->addWidget(m_pTwoAnd2_5Enable,11,1,1,1);

        m_pWuHuaReverse = new QLabelSwicthInput(Form);
        m_pWuHuaReverse->setObjectName(QString::fromUtf8("m_pWuHuaReverse"));
        connect(m_pWuHuaReverse->onoff,SIGNAL(StateChange(bool)),this,SLOT(WuHuaReverse(bool)));
        gridLayout->addWidget(m_pWuHuaReverse,11,2,1,1);


        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QRepairUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QRepairUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    //    virtual ~QRepairUI();
    void Update(QString param);
    virtual bool OnPrevious();
public slots:
//    void textChanged();
    void StateChangeBoxwaterlevDetect(bool b);
    void StateChangeBoxwaterTempDetect(bool b);
    void StateChangeAddCupLevDetect(bool b);
    void StateChangeWuhuaLevDetect(bool b);
    void StateChangeWuhuaTempDetect(bool b);
    void StateChangeHCupDetect(bool b);
//    void ReadValues();
    void StateChangeDebugOn();
    //    void OnCalibration();
    //    void OnColorTest();
    void ButtonClick();
public:
    QTimer*  counterTimer;
    QGridLayout *gridLayout;
    QLabelLineInput* pBoxwaterlev;
    QLabelLineInput* pBoxwatertemp;
    QLabelLineInput* pAddCupWaterLev;
    QLabelLineInput* pWuhuaTemp;

//    QLabelSwicthInput*  pBoxwaterLevDetect;


    QLabelSwicthInput*  pBoxwaterTempDetect;
//    QLabelSwicthInput*  pAddCupLevDetect;
//    QLabelSwicthInput*  pWuhuaLevDetect;
    QLabelSwicthInput*  pWuhuaTempDetect;
    QLabelSwicthInput*  pHCupDetect;
    QLabelSwicthInput*  pDebugOn;

    QPushButton* m_pA;
    QPushButton* m_pB;
    QPushButton* m_pC;
    QPushButton* m_pD;
    QPushButton* m_pE;
    QPushButton* m_pF;
    QPushButton* m_pG;
    QPushButton* m_pH;
    QPushButton* m_pI;
    QPushButton* m_pJ;
    QPushButton* m_pK;
    QPushButton* m_pL;
    QPushButton* m_pM;
    QPushButton* m_pN;



    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QRepairUI"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0,0,300,300);
        gridLayout->setSpacing(5);

//                pBoxwaterlev = new QLabelLineInput(Form);
//                pBoxwaterlev->setObjectName(QString::fromUtf8("BoxWaterLevel"));
//        //        pBoxwaterlev->lineEdit->setProperty("number",63);
//                gridLayout->addWidget(pBoxwaterlev,0,0,1,1);

//                pBoxwatertemp = new QLabelLineInput(Form);
//                pBoxwatertemp->setObjectName(QString::fromUtf8("BoxWaterTemperature"));
//        //        pBoxwatertemp->lineEdit->setProperty("number",64);
//                gridLayout->addWidget(pBoxwatertemp,1,0,1,1);

//                pAddCupWaterLev = new QLabelLineInput(Form);
//                pAddCupWaterLev->setObjectName(QString::fromUtf8("CupWaterLevel"));
//                gridLayout->addWidget(pAddCupWaterLev,2,0,1,1);

//                pWuhuaTemp = new QLabelLineInput(Form);
//                pWuhuaTemp->setObjectName(QString::fromUtf8("InbTemperature"));
//                gridLayout->addWidget(pWuhuaTemp,3,0,1,1);


//                pBoxwaterLevDetect = new QLabelSwicthInput(Form);
//                pBoxwaterLevDetect->setObjectName(QString::fromUtf8("pBoxwaterLevDetect"));
//        //        connect(pBoxwaterLevDetect,SIGNAL(clicked()),this,SLOT(OnCalibration()));
//                gridLayout->addWidget(pBoxwaterLevDetect,4,0,1,1);




                pBoxwaterTempDetect = new QLabelSwicthInput(Form);
                pBoxwaterTempDetect->setObjectName(QString::fromUtf8("pBoxwaterTempDetect"));
        //        connect(pBoxwaterTempDetect,SIGNAL(clicked()),this,SLOT(OnColorTest()));
                gridLayout->addWidget(pBoxwaterTempDetect,5,0,1,1);

//                pAddCupLevDetect = new QLabelSwicthInput(Form);
//                pAddCupLevDetect->setObjectName(QString::fromUtf8("pAddCupLevDetect"));
//        //        connect(pAddCupLevDetect,SIGNAL(clicked()),this,SLOT(OnColorTest()));
//                gridLayout->addWidget(pAddCupLevDetect,6,0,1,1);

//                pWuhuaLevDetect = new QLabelSwicthInput(Form);
//                pWuhuaLevDetect->setObjectName(QString::fromUtf8("pWuhuaLevDetect"));
//        //        connect(pWuhuaLevDetect,SIGNAL(clicked()),this,SLOT(OnColorTest()));
//                gridLayout->addWidget(pWuhuaLevDetect,7,0,1,1);

                pWuhuaTempDetect = new QLabelSwicthInput(Form);
                pWuhuaTempDetect->setObjectName(QString::fromUtf8("pWuhuaTempDetect"));
        //        connect(pWuhuaTempDetect,SIGNAL(clicked()),this,SLOT(OnColorTest()));
                gridLayout->addWidget(pWuhuaTempDetect,8,0,1,1);


        pHCupDetect = new QLabelSwicthInput(Form);
        pHCupDetect->setObjectName(QString::fromUtf8("pWuhuaTempDetect"));
//        connect(pWuhuaTempDetect,SIGNAL(clicked()),this,SLOT(OnColorTest()));
        gridLayout->addWidget(pHCupDetect,9,0,1,1);



        pDebugOn = new QLabelSwicthInput(Form);
        pDebugOn->setObjectName(QString::fromUtf8("pDebugOn"));
        gridLayout->addWidget(pDebugOn,0,0,1,1);

        m_pA =new QPushButton(Form);
        m_pA->setObjectName("A");
        connect(m_pA,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pA,1,0,1,1);

        m_pB =new QPushButton(Form);
        m_pB->setObjectName("B");
        connect(m_pB,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pB,1,1,1,1);


        m_pC =new QPushButton(Form);
        m_pC->setObjectName("C");
        connect(m_pC,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pC,2,0,1,1);

        m_pD =new QPushButton(Form);
        m_pD->setObjectName("D");
        connect(m_pD,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pD,2,1,1,1);

        m_pE =new QPushButton(Form);
        m_pE->setObjectName("E");
        connect(m_pE,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pE,3,0,1,1);

        m_pF =new QPushButton(Form);
        m_pF->setObjectName("F");
        connect(m_pF,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pF,3,1,1,1);

        m_pG =new QPushButton(Form);
        m_pG->setObjectName("G");
        connect(m_pG,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pG,4,0,1,1);

        m_pH =new QPushButton(Form);
        m_pH->setObjectName("H");
        connect(m_pH,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pH,4,1,1,1);

        m_pI =new QPushButton(Form);
        m_pI->setObjectName("I");
        connect(m_pI,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pI,5,0,1,1);

        m_pJ =new QPushButton(Form);
        m_pJ->setObjectName("J");
        connect(m_pJ,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pJ,5,1,1,1);

        m_pK =new QPushButton(Form);
        m_pK->setObjectName("K");
        connect(m_pK,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pK,6,0,1,1);

        m_pL =new QPushButton(Form);
        m_pL->setObjectName("L");
        connect(m_pL,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pL,6,1,1,1);

        m_pM =new QPushButton(Form);
        m_pM->setObjectName("M");
        connect(m_pM,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pM,7,0,1,1);

        m_pN =new QPushButton(Form);
        m_pN->setObjectName("N");
        connect(m_pN,SIGNAL(clicked()),this,SLOT(ButtonClick()));
        gridLayout->addWidget(m_pN,7,1,1,1);


        //        pBoxwaterlev->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        //        pBoxwatertemp->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        //        pAddCupWaterLev->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        //        pWuhuaTemp->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

const QString EngineerPassWD = "wangjimimale";
const QString EngineerPassWDSERVICE = "wangjimimaleservice";
const QString EngineerPassWDADMIN = "wangjimimaleadmin";
const QString FaHuoPassWD="woyaofahuo";
class QCheckPWDUI : public CMessageNotify
{
    Q_OBJECT
public:
    explicit QCheckPWDUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QCheckPWDUI();

    void    Update(QString param);
    bool    OnConfirm();
    bool    OnPrevious();
    void    retranslateUi(QWidget *form);

private:
    QVBoxLayout *m_pVLayout;
    QLabelLineInput *m_pLbLine;
};

class QUserDebugUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserDebugUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserDebugUI();
    void    Update(QString param);
    bool    OnConfirm();
    bool    OnPrevious();
    void    OnMessage(int, int, quint32, quint32, quint8 *, quint16);
public:
    QHBoxLayout *gridLayout;
    QStackedWidget* stackedWidget;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserDebugUI"));
        gridLayout = new QHBoxLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
            gridLayout->setContentsMargins(0,0,0,0);
        else
            gridLayout->setContentsMargins(0,0, 300, 300);
        stackedWidget = new QStackedWidget(Form);
        gridLayout->addWidget(stackedWidget);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

const QString FORGOT_PWD = QString("wangjimimale");
const QString FORGOT_PWD2 = QString("forgotpassword");
const int EXTEND_LICENSE_DAYS = 7;

const int ReplyTimeOut = 10;

class DownloadPasswordDailog;
class UpgradeProgressWidget;

class QUserAdvanceUI: public CMessageNotify
{
    Q_OBJECT
public:
    enum BrightlightTimeType
    {
        BrightNever = 0,
        BrightSecond = 15,
        BrightSecondOne = 30,
        BrightMinute = 1,
        BrightMinuteOne = 2,
        BrightMinutTwo = 5,
        BrightMinuteThree = 10
    };

    explicit QUserAdvanceUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserAdvanceUI();
    void Update(QString param);
    bool OnConfirm();
    bool OnPrevious();
public slots:
    void btnLanguageClicked();
    void btn_clicked();
    void ShowTimePicker(int type);
    void OnDatetextChanged(QString);
    void OnTimetextChanged(QString);
    void OnTextChanged();
    void StateChange(bool);
    void netwokReplyFinished(QNetworkReply*);
    void btnDownloadClicked();
    void loadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void loadError(QNetworkReply::NetworkError);
    void lookUp(QHostInfo);
    void BlueToothOnChange(bool);
    void brightlightIndexChange(int);
    void OnUpdateTextChanged();
    void onLockScreenClicked();
    void onDownloadVerify(bool flag);
    void refreshDownloadBtn(bool);
    void btn_timeDecrease();
    void btn_timeIncrease();
public:    
    QToolButton* m_pLabel0;
    QPushButton* m_plable1;
    QPushButton* m_plable2;
    QPushButton* m_plable3;
    QPushButton* m_plable4;
    QPushButton* m_plable5;
    QToolButton *toolButton_del;
    QLabel *label;
    QToolButton *toolButton_add;
    QLanguageSelect *m_pLangWidget;
    //time sync,factory default,BT type,refresh leaseinfo
    //    QGridLayout *gridLayout;
    //    QVBoxLayout *m_pMainVLayout;
    //    QHBoxLayout *m_pHLoadLayout;
    //    QHBoxLayout *m_pHBrightLayout;
    QLabel *m_pLbBrightName;
    QComboBox *m_pCbxBright;
    QLabelDateTimeInput* dateEdit;
    QLabelDateTimeInput* timeEdit;
    CKBEdit* aliasEdit;
    CKBEdit* leaseEdit;
    CKBEdit* leaseDate;
    QSwitchMenu* wizardOn;
    QLabelSwicthInput* m_BlueToothOn;
    CKBEdit* m_pLbInputSoftUpdate; //soft update widget
    QToolButton*     applyFacotryDefault;
    QToolButton*     m_pBtnLanguage;
    QToolButton*     m_pBtnLockConf;
    QToolButton*     m_pLeaseOK;
    //    QSpacerItem*     h;
    //    QSpacerItem*     h1;

    QToolButton *m_pBtnDownload; // clicked download
    QNetworkAccessManager *m_pNetManager; //network manager
    QNetworkReply *m_pNetReply;

    DateTimeSelectWidget *m_pCalendarWidget;
    DateTimeSelectWidget *m_pDateTimeWidget;
    DownloadPasswordDailog *m_pDownloadDlg;
    UpgradeProgressWidget *m_pDownloadWgt;

    bool m_iErrorFlag;

    void download();
    void createDownloadUi(QWidget *Form);
    void retranslateUi(QWidget *Form);
    void showError();
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserAdvanceUI"));

        m_pLabel0=new QToolButton(this);
        m_pLabel0->setText(tr("Advance"));
        m_pLabel0->setStyleSheet(CommonParam::m_sStyle10);
        m_pLabel0->move(200,35);
        m_pLabel0->resize(124,49);
        m_plable1= new QPushButton(this);
        m_plable1->resize(124,49);
        m_plable1->move(189,86);
        m_plable1->setText(tr("lease end"));
        m_plable1->setStyleSheet(CommonParam::m_sStyle26);

        m_plable2= new QPushButton(this);
        m_plable2->resize(124,49);
        m_plable2->move(189,145);
        m_plable2->setText(tr("lease code"));
        m_plable2->setStyleSheet(CommonParam::m_sStyle26);

        m_plable3= new QPushButton(this);
        m_plable3->resize(124,49);
        m_plable3->move(189,204);
        m_plable3->setText(tr("update addr"));
        m_plable3->setStyleSheet(CommonParam::m_sStyle26);

        m_plable4= new QPushButton(this);
        m_plable4->hide();
        m_plable4->resize(124,49);
        m_plable4->move(189,262);
        m_plable4->setText(tr("wizard"));
        m_plable4->setStyleSheet(CommonParam::m_sStyle26);

        m_plable5= new QPushButton(this);
        m_plable5->resize(124,49);
        m_plable5->move(189,262);
        m_plable5->setText(tr("yinliang"));
        m_plable5->setStyleSheet(CommonParam::m_sStyle26);


        toolButton_del = new QToolButton(Form);
        label = new QLabel(this);
        toolButton_add = new QToolButton(Form);

        toolButton_del->move(348*CommonParam::m_iWidth/800,262*CommonParam::m_iHeight/480);
        toolButton_del->resize(59*CommonParam::m_iWidth/800,58*CommonParam::m_iHeight/480);
        toolButton_del->setStyleSheet("border-image:url(:/seven/Nimage/jianjian1.png);"
                                      "font: 32px;"
                                      "color: rgb(0, 0, 0);"
                                      "outline: none;"
                                      "border-style:solid;"
                                      "border-width:1px;"
                                      "border-radius:38px;"
                                      //"focus{padding: -1;};"
                                      //                              "padding:-1px;"
                                      );

        label->move(448*CommonParam::m_iWidth/800,262*CommonParam::m_iHeight/480);
        label->resize(128*CommonParam::m_iWidth/800,51*CommonParam::m_iHeight/480);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("border-image:url(:/seven/Nimage/timeshow.png);"
                             "font: 32px;"
                             "color: rgb(0, 0, 0);"
                             "outline: none;"
                             "border-style:solid;"
                             "border-width:1px;"
                             "border-radius:38px;"
                             //"focus{padding: -1;};"
                             //                              "padding:-1px;"
                             );
        label->setText(QString::number(CommonParam::m_iVol));

        toolButton_add->move(618*CommonParam::m_iWidth/800,262*CommonParam::m_iHeight/480);
        toolButton_add->resize(60*CommonParam::m_iWidth/800,60*CommonParam::m_iHeight/480);
        toolButton_add->setObjectName(QString::fromUtf8("toolButton_add"));
        toolButton_add->setStyleSheet("border-image:url(:/seven/Nimage/jiajia1.png);"                                      "font: 32px;"
                                      "color: rgb(0, 0, 0);"
                                      "outline: none;"
                                      "border-style:solid;"
                                      "border-width:1px;"
                                      "border-radius:38px;"
                                      //"focus{padding: -1;};"
                                      //                              "padding:-1px;"
                                      );

//        m_pYinLiang->setStyleSheet(CommonParam::m_sStyle9);


        m_pCalendarWidget = new DateTimeSelectWidget(DateTimeSelectWidget::DateShowType, this);
        m_pCalendarWidget->hide();
        m_pDateTimeWidget = new DateTimeSelectWidget(DateTimeSelectWidget::TimeShowType, this);
        m_pDateTimeWidget->hide();

        //        m_pHBrightLayout = new QHBoxLayout;

        m_pLbBrightName = new QLabel(Form);
        m_pLbBrightName->setObjectName("brightlight-lable");

        m_pCbxBright = new QComboBox(Form);
        m_pCbxBright->setObjectName("brightlight-combox");

        //        m_pHBrightLayout->setMargin(0);
        //        m_pHBrightLayout->setSpacing(0);
        //        m_pHBrightLayout->addWidget(m_pLbBrightName);
        //        m_pHBrightLayout->addWidget(m_pCbxBright);
        m_pCbxBright->hide();
        m_pLbBrightName->hide();

        {
            //            m_pMainVLayout->setContentsMargins(120,15,100,5);
            dateEdit = new QLabelDateTimeInput(QTimeDateSelect::SELECT_DATE,Form);
            dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
            //            m_pMainVLayout->addWidget(dateEdit);

            timeEdit = new QLabelDateTimeInput(QTimeDateSelect::SELECT_TIME,Form);
            timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
            //            m_pMainVLayout->addWidget(timeEdit);

            aliasEdit = new CKBEdit(Form);
            aliasEdit->setObjectName(QString::fromUtf8("aliasEdit"));
            aliasEdit->setProperty("number",1);
            //            m_pMainVLayout->addWidget(aliasEdit);

            leaseDate = new CKBEdit(Form);
            leaseDate->move(348,86);
            leaseDate->resize(388,46);
            leaseDate->setObjectName(QString::fromUtf8("leaseDate"));
            leaseDate->setStyleSheet(CommonParam::m_sStyle16);
            //            leaseDate->lineEdit->setProperty("number",2);
            leaseDate->setEnabled(false);
            //            m_pMainVLayout->addWidget(leaseDate);

            leaseEdit = new CKBEdit(Form);
            leaseEdit->setStyleSheet(CommonParam::m_sStyle16);
            leaseEdit->move(348,144);
            leaseEdit->resize(311,46);
            leaseEdit->setObjectName(QString::fromUtf8("leaseEdit"));
            leaseEdit->setProperty("number",2);
            //            m_pMainVLayout->addWidget(leaseEdit);

            createDownloadUi(Form);

            //            m_pBtnDownload->setFixedSize(100, 45);

            m_BlueToothOn = new QLabelSwicthInput(Form);
            m_BlueToothOn->setObjectName(QString::fromUtf8("BlueTooth"));
            //            m_pMainVLayout->addWidget(m_BlueToothOn);
            m_BlueToothOn->hide();
            wizardOn = new QSwitchMenu(Form);
            wizardOn->hide();
            wizardOn->move(348,265);
            wizardOn->setObjectName(QString::fromUtf8("wizardOn"));

            //            m_pMainVLayout->addWidget(wizardOn);

            m_pBtnLanguage = new QToolButton(Form);
            m_pBtnLanguage->hide();
            m_pBtnLanguage->move(192,329);
            m_pBtnLanguage->resize(176,71);
            m_pBtnLanguage->setStyleSheet(CommonParam::m_sStyle23);
            m_pBtnLanguage->setObjectName(QString::fromUtf8("lang"));
            //            m_pMainVLayout->addWidget(m_pBtnLanguage);

            applyFacotryDefault = new QToolButton(Form);
            applyFacotryDefault->hide();
            applyFacotryDefault->adjustSize();
            applyFacotryDefault->move(377,329);
            applyFacotryDefault->resize(176,71);
            applyFacotryDefault->setStyleSheet(CommonParam::m_sStyle23);
            applyFacotryDefault->setObjectName(QString::fromUtf8("applyFacotryDefault"));

            m_pLeaseOK=new QToolButton(Form);
            m_pLeaseOK->move(669,145);
            m_pLeaseOK->resize(92,47);
            m_pLeaseOK->setText(tr("OK"));
            m_pLeaseOK->setStyleSheet(CommonParam::m_sStyle22);            

            //            m_pMainVLayout->addWidget(applyFacotryDefault);
        }

        aliasEdit->hide();
        if(!CommonParam::m_bTimeAdjustAble)
            dateEdit->hide();
        if(!CommonParam::m_bTimeAdjustAble)
            timeEdit->hide();

        m_pBtnLockConf = new QToolButton(this);
        m_pBtnLockConf->hide();
        m_pBtnLockConf->move(557,329);
        m_pBtnLockConf->resize(176,71);
        m_pBtnLockConf->setStyleSheet(CommonParam::m_sStyle23);
        //        m_pMainVLayout->addWidget(m_pBtnLockConf);

        //        Form->setLayout(m_pMainVLayout);

        retranslateUi(Form);

        //        dateEdit->lineEdit->setDisabled(true);
        //        timeEdit->lineEdit->setDisabled(true);
        connect(dateEdit->lineEdit,SIGNAL(clicked(int)),this,SLOT(ShowTimePicker(int)));
        connect(timeEdit->lineEdit,SIGNAL(clicked(int)),this,SLOT(ShowTimePicker(int)));

        connect(leaseEdit,SIGNAL(textChanged1()),this,SLOT(OnTextChanged()));
        connect(aliasEdit,SIGNAL(textChanged1()),this,SLOT(OnTextChanged()));
        connect(applyFacotryDefault,SIGNAL(clicked()),this,SLOT(btn_clicked()));
        connect(m_BlueToothOn->onoff,SIGNAL(StateChange(bool)),this,SLOT(BlueToothOnChange(bool)));

        connect(wizardOn,SIGNAL(StateChange(bool)),this,SLOT(StateChange(bool)));

        //connect network manager
        connect(m_pNetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(netwokReplyFinished(QNetworkReply*)));
        // connect download clicked
        connect(m_pBtnDownload, SIGNAL(clicked(bool)), this, SLOT(btnDownloadClicked()));
        //language change
        connect(m_pBtnLanguage, SIGNAL(clicked(bool)), this, SLOT(btnLanguageClicked()));

        connect(m_pLbInputSoftUpdate,SIGNAL(textChanged1()),this,SLOT(OnUpdateTextChanged()));
        connect(m_pBtnLockConf, SIGNAL(clicked()), this, SLOT(onLockScreenClicked()));
        connect(toolButton_del,SIGNAL(clicked(bool)),this,SLOT(btn_timeDecrease()));
        connect(toolButton_add,SIGNAL(clicked(bool)),this,SLOT(btn_timeIncrease()));
        QMetaObject::connectSlotsByName(Form);
    }

private:
    void writeLicense(QString license);
    void rentalCodeChange();
};

class QWaterStatusUI:public QWidget
{
    Q_OBJECT
public:
    enum
    {
        TYPE_BOX,
        TYPE_HCUP,
        TYPE_ICUP,
        TYPE_QingShuiCUP
    };
    explicit QWaterStatusUI(int type,QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QWaterStatusUI();
    int nType;
protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const
    {
        return QSize(200,120);
    }
private:
    void drawFrame(QPainter* painter);
    void drawBattery(QPainter* painter);
private:
    bool    m_bReverse;
    qreal   m_headWidth;
    int     m_value;
    int     m_currentValue;
    QRectF  m_batteryRect;
signals:
    void valueChanged(int value);
public slots:
    void setValue(int value);
};

class QWaterIndictorUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QWaterIndictorUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QWaterIndictorUI();
    void OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
public:
    QHBoxLayout* h;
    QWaterStatusUI *box;
    QWaterStatusUI* hcup;
    QWaterStatusUI* icup;
    QWaterStatusUI* m_pQingShuicup;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QWaterIndictorUI"));
        h = new QHBoxLayout(Form);
        h->setObjectName(QString::fromUtf8("h"));
        h->setContentsMargins(0,0,0,0);
        h->setSpacing(6);
        box = new QWaterStatusUI(QWaterStatusUI::TYPE_BOX,Form);
        box->setObjectName(QString::fromUtf8("box"));
        h->addWidget(box);
        hcup = new QWaterStatusUI(QWaterStatusUI::TYPE_HCUP,Form);
        hcup->setObjectName(QString::fromUtf8("hcup"));
        h->addWidget(hcup);
        icup = new QWaterStatusUI(QWaterStatusUI::TYPE_ICUP,Form);
        icup->setObjectName(QString::fromUtf8("icup"));
        h->addWidget(icup);

        m_pQingShuicup = new QWaterStatusUI(QWaterStatusUI::TYPE_QingShuiCUP,Form);
        m_pQingShuicup->setObjectName(QString::fromUtf8("m_pQingShuicup"));
        h->addWidget(m_pQingShuicup);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }
};

class QUserStopCheckUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserStopCheckUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserStopCheckUI();
    void    OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
private slots:
    void timeFatalCheck();
public:
    QHBoxLayout* herror;
    QLabel*      message;
    QTimer*      timer;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        Form->setObjectName(QString::fromUtf8("MainError"));
        herror = new QHBoxLayout(Form);
        herror->setObjectName(QString::fromUtf8("herror"));
        message = new QLabel(Form);
        message->setObjectName(QString::fromUtf8("message"));
        message->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
        message->setStyleSheet(CommonParam::m_sStyle37);
        herror->addWidget(message);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }
};

class QUserErrorUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserErrorUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserErrorUI();
    void    OnMessage(int dest,int ev,quint32 p1,quint32 p2,quint8* buf,quint16 size);
private slots:
    void timeFatalCheck();
public:
//    QVBoxLayout* herror;
//    QRoundProgressBar*   bar;
    QLabel*      message;
    int state;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        Form->setObjectName(QString::fromUtf8("MainError"));
//        herror = new QVBoxLayout(Form);
//        herror->setObjectName(QString::fromUtf8("herror"));
//        bar = new QRoundProgressBar(Form);
//        bar->setObjectName(QString::fromUtf8("bar"));
//        bar->setChangeValue(false);
//        herror->addWidget(bar);
        message = new QLabel(Form);
        message->setObjectName(QString::fromUtf8("message"));
        message->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding));
        message->setFixedSize(404,246);
        message->move(200,122);
        message->hide();
        message->setStyleSheet(CommonParam::m_sStyle37);
//        herror->addWidget(message);
//        herror->setStretch(0,1);
//        herror->setStretch(1,4);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }
};

class QUserStatisUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserStatisUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserStatisUI();
    void Update(QString param);
private slots:
    void OnPreviousPage();
    void OnNextPage(int iValue);
protected:
    void resizeEvent(QResizeEvent *);

private:
    void refreshTableData(TMedUserStatis *user, int size);
    QString dealwithSeparate(QString strSrc);
    QString useTimeToHourMinute(int time);

private:
    int NumOfPages;
public:
    //    QVBoxLayout* m_pVMainLayout;
    //    QVBoxLayout* m_pVRightLayout;
    //    QHBoxLayout* m_pHUserLayout;
    //    QHBoxLayout* m_pHUseLayout;
    //    QHBoxLayout* m_pHTotalLayout;
    //    QHBoxLayout* m_pHMainLayout;
    //    QLabel*      user;
    QLabel*      user_t;
    QLabel*      label_t;
    //    QLabel*      Numbers_t;
    QLabel*      label_h;
    //    QLabel*      Numbers_h;
    QTableWidget* user_table;
    QToolButton* m_pUser;
    QLabel*      label_userinfo;
    //    QToolButton* up;

    QSlider* down;
    quint32      statisStartId;
    quint32      statisStopId;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserStatisUI"));

        //        m_pHUserLayout = new QHBoxLayout();
        //        m_pHUserLayout->setObjectName(QString::fromUtf8("HUserLayout"));

        user_t = new QLabel(Form);
        user_t->move(309,96);
        user_t->setObjectName(QString::fromUtf8("user_t"));
        //        m_pHUserLayout->addWidget(user_t, 0, Qt::AlignLeft);

        //        user = new QLabel(Form);
        //        user->setObjectName(QString::fromUtf8("user"));
        //        m_pHUserLayout->addWidget(user, 0, Qt::AlignLeft);

        //        m_pHUseLayout = new QHBoxLayout();
        //        m_pHUseLayout->setObjectName(QString::fromUtf8("HUseLayout"));

        label_t = new QLabel(Form);
        label_t->resize(300,50);
        label_t->move(309,140);
        label_t->setObjectName(QString::fromUtf8("label_t"));
        //        m_pHUseLayout->addWidget(label_t, 0, Qt::AlignLeft);

        //        Numbers_t = new QLabel(Form);
        //        Numbers_t->setObjectName(QString::fromUtf8("Numbers_t"));
        //        m_pHUseLayout->addWidget(Numbers_t, 0, Qt::AlignLeft);

        //        m_pHTotalLayout = new QHBoxLayout();
        //        m_pHTotalLayout->setObjectName(QString::fromUtf8("HTotalLayout"));

        label_h = new QLabel(Form);
        label_h->move(309,178);
        label_h->resize(300,50);
        label_h->setObjectName(QString::fromUtf8("label_h"));

        label_userinfo=new QLabel(Form);
        label_userinfo->setStyleSheet(CommonParam::m_sStyle11);
        label_userinfo->move(190,235);
        label_userinfo->setText(tr("User status"));
        //        m_pHTotalLayout->addWidget(label_h, 0, Qt::AlignLeft);

        //        Numbers_h = new QLabel(Form);
        //        Numbers_h->setObjectName(QString::fromUtf8("Numbers_h"));
        //        m_pHTotalLayout->addWidget(Numbers_h, 0, Qt::AlignLeft);

        //        m_pHMainLayout = new QHBoxLayout();
        //        m_pHMainLayout->setObjectName(QString::fromUtf8("HMainLayout"));

        user_table = new QTableWidget(Form);
        user_table->move(185,266);
        user_table->resize(546,133);
        //user_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        user_table->setObjectName(QString::fromUtf8("user_table"));
        //        m_pHMainLayout->addWidget(user_table);

        //        m_pVRightLayout = new QVBoxLayout();
        //        m_pVRightLayout->setObjectName(QString::fromUtf8("VRightLayout"));

        //        up = new QToolButton(Form);
        //        up->setObjectName(QString::fromUtf8("toolButton_up"));
        //        m_pVRightLayout->addWidget(up);

        down = new QSlider(Form);
        down->setObjectName(QString::fromUtf8("toolButton_down"));
        down->setOrientation(Qt::Vertical);  // 方向
        down->setStyleSheet("QSlider::groove:vertical {\
                            border: 1px solid #000000;\
                border-image:url(:/seven/Nimage/user7.png);\
width: 30px;\
        border-radius: 15px;\
        padding-left:0px;\
        padding-right:1px;\
        padding-top:0px;\
        padding-bottom:0px;\
        margin-left: 0px;\
        margin-right: 0px;\
        margin-top: 0px;\
        margin-bottom: 0px;\
    }\
    QSlider::sub-page:vertical {\
                          border-image:url(:/seven/Nimage/user4.png);\
    border: 1px solid #4A708B;\
    width: 30px;\
    border-radius: 15px;\
}\
QSlider::add-page:vertical {\
    border-image:url(:/seven/Nimage/user8.png);\
    border: 1px solid #777;\
    width: 30px;\
    border-radius: 15px;\
}\
QSlider::handle:vertical \
{\
    border-image:url(:/seven/Nimage/user7.png);\
    background：transparent;\
    height: 25px;\
    width: 25px;\
    margin-left: 0px;\
    margin-right: 0px;\
    margin-top: 0px;\
    margin-bottom: 0px;\
    border: 1px solid #000000;\
    border-radius: 20px;\
}");
down->resize(27,133);
down->move(760,266);

//设置最小值、最大值
down->setMinimum(0);
down->setMaximum(8);

//设置初始值
down->setValue(0);
down->setPageStep(1);

m_pUser=new QToolButton(Form);
m_pUser->setStyleSheet(CommonParam::m_sStyle10);
m_pUser->setText(tr("User"));
m_pUser->resize(151,47);
m_pUser->move(186,20);
//        m_pVRightLayout->addWidget(down);

//        m_pVMainLayout = new QVBoxLayout(Form);

//        m_pHMainLayout->addLayout(m_pVRightLayout);

//        m_pVMainLayout->addLayout(m_pHUserLayout);
//        m_pVMainLayout->addLayout(m_pHUseLayout);
//        m_pVMainLayout->addLayout(m_pHTotalLayout);
//        m_pVMainLayout->addLayout(m_pHMainLayout);

//        Form->setLayout(m_pVMainLayout);

//        int iHLeft = 100;
//        int iHRight = 100;
//        int iVLeft = 35;
//        int iVTop = 46;
//        int iVRight = 30;
//        switch (currentMachineType())
//        {
//        case MACHINE_TYPE_5INCH_V:
//            iHLeft = 0;
//            iHRight = 30;
//            break;
//        case MACHINE_TYPE_4INCH:
//            iHLeft = 0;
//            iHRight = 30;
//            iVLeft = 10;
//            iVRight = 10;
//            break;
//        default:
//            break;
//        }

//        m_pVMainLayout->setContentsMargins(20, 20, 20, 10);
retranslateUi(Form);
QMetaObject::connectSlotsByName(Form);
}
};

class QUserCleanAboutUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserCleanAboutUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserCleanAboutUI();
    void Update(QString param);
private slots:
    void OnStart();
    void OnStop();
public:
    QHBoxLayout* hm;
    QSpacerItem* hml;
    QSpacerItem* hmr;
    QVBoxLayout* v;
    QSpacerItem* vt;
    QSpacerItem* vb;
    QLabel*      display;
    QLabel*      display_time;
    QHBoxLayout* h;
    QPushButton* confirm;
    QSpacerItem* hs;
    QPushButton* cancel;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserCleanAboutUI"));
        hm = new QHBoxLayout(Form);
        hm->setObjectName(QString::fromUtf8("hm"));
        hm->setContentsMargins(0,0,0,0);
        hm->setSpacing(0);
        hml = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        hm->addItem(hml);

        v = new QVBoxLayout();
        v->setObjectName(QString::fromUtf8("CleanAboutUI_V"));
        v->setContentsMargins(0,0,0,0);
        v->setSpacing(16);
        vt = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
        v->addItem(vt);
        display = new QLabel(Form);
        display->setObjectName(QString::fromUtf8("display"));
        v->addWidget(display);
        display_time = new QLabel(Form);
        display_time->setObjectName(QString::fromUtf8("display_time"));
        v->addWidget(display_time);
        h = new QHBoxLayout();
        h->setObjectName(QString::fromUtf8("h"));
        h->setContentsMargins(0,0,0,0);

        confirm = new QPushButton(Form);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        h->addWidget(confirm);
        hs = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        h->addItem(hs);
        cancel = new QPushButton(Form);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        h->addWidget(cancel);
        v->addLayout(h);
        vb = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
        v->addItem(vb);
        hm->addLayout(v);
        hmr = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        hm->addItem(hmr);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }
};

class QUserCleanUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserCleanUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserCleanUI();
    void Update(QString param);
private slots:
    void BreakUser();
    void timeout();
public:
    QHBoxLayout* hm;
    QSpacerItem* hml;
    QSpacerItem* hmr;
    QVBoxLayout* v;
    QLabel*      display;
    QLabel*      display_time;
    QPushButton* btn_break;
    quint32      calcTimeOut;
    QTimer*      ptTimer;
    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserCleanUI"));
        hm = new QHBoxLayout(Form);
        hm->setObjectName(QString::fromUtf8("hm"));
        hm->setContentsMargins(0,0,0,0);
        hm->setSpacing(0);
        hml = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        hm->addItem(hml);

        v = new QVBoxLayout();
        v->setObjectName(QString::fromUtf8("QUserCleanUI_V"));
        v->setContentsMargins(0,0,0,0);
        v->setSpacing(0);

        display = new QLabel(Form);
        display->setObjectName(QString::fromUtf8("display"));
        v->addWidget(display);

        display_time = new QLabel(Form);
        display_time->setObjectName(QString::fromUtf8("display_time"));
        v->addWidget(display_time);
        btn_break = new QPushButton(Form);
        btn_break->setObjectName(QString::fromUtf8("btn_break"));
        v->addWidget(btn_break);
        v->setStretch(0,4);
        v->setStretch(1,4);
        v->setStretch(2,1);
        hm->addLayout(v);
        hmr = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        hm->addItem(hmr);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }
};

const int RunRollOffsetX = 2;
const int RunRollOffsetY = 2;
const int RunPollTimerTime = 1000*12;//12s

const int AnimationTime = 1000*6;//6s
const int AnimationTimeV = 1000*8;//8s

class QUserRunPoll:public CMessageNotify
{
    Q_OBJECT
public:
    enum
    {
        IDP_POLL_PIXMAP1,
        IDP_POLL_PIXMAP2,
        IDP_POLL_PIXMAP3,
        IDP_POLL_PIXMAP_MAX,
    };
    explicit QUserRunPoll(QWidget *parent = 0, Qt::WindowFlags flags=0);
    virtual ~QUserRunPoll();
    void Hide();
    void retranslateUi(QWidget *Form);
    void OnDraw();
    //    virtual void OnMessage(int, int, quint32, quint32, quint8 *, quint16);

    QString  lastUIName;
    QTimer *m_pTimer;

    //    virtual void OnMessage(int obj, int ev, quint32 p1, quint32 p2, quint8 *buf, quint16 size);

    void showPrevWidget();

public slots:
    void moveTimeout();
    void animationFinished();

protected:
    bool eventFilter(QObject *, QEvent *);
    //    void mousePressEvent(QMouseEvent *ev);
    QPropertyAnimation *createPropertyAnimation(QToolButton *pToolBtn);
    void resetAnimationGroup();

public:
    void CalculateWidthHeight();
    void         StartTimer();
    void         StopTimer();
    int          yPos;
    int          xPos;
    int          m_iBigW;
    int          m_iBigH;
    int          m_iSmallW;
    int          m_iSmallH;
    int          m_iIndex;
    QString      m_strBigSheet;
    QString      m_strSmallSheet;


    QToolButton *m_pFire;
    QToolButton *m_pWind;
    QToolButton *m_pTthunder;
    QSequentialAnimationGroup *m_pParalleGroup;
    QList<QToolButton*> m_listToolButton;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("CRunPoll"));

        m_pFire = new QToolButton(Form);
        m_pFire->setStyleSheet ("color:white;font:40px;");
        m_pFire->setIcon(QIcon(":/seven/images/fire.png"));
        m_pFire->setFocusPolicy(Qt::NoFocus);
        m_pFire->setText(tr(" Use the indoor ban on fireworks "));
        m_pFire->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pFire->installEventFilter(this);

        m_pWind = new QToolButton(Form);
        m_pWind->setStyleSheet ("color:white;font:40px;");
        m_pWind->setFocusPolicy(Qt::NoFocus);
        m_pWind->setIcon(QIcon(":/seven/images/wind.png"));
        m_pWind->setText(tr(" Running in the window ventilation "));
        m_pWind->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pWind->installEventFilter(this);

        m_pTthunder = new QToolButton(Form);
        m_pTthunder->setStyleSheet ("color:white;font:40px;");
        m_pTthunder->setIcon(QIcon(":/seven/images/thunder.png"));
        m_pTthunder->setFocusPolicy(Qt::NoFocus);
        m_pTthunder->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        m_pTthunder->setText(tr(" Avoid all kinds of friction static electricity "));
        m_pTthunder->installEventFilter(this);

        this->installEventFilter(this);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class QUserShutDownDialog:public QDialog
{
    Q_OBJECT
public:
    static QUserShutDownDialog* create(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    static QUserShutDownDialog* get();
    virtual ~QUserShutDownDialog();
private:
    static QUserShutDownDialog* intance;
protected:
    QUserShutDownDialog(QWidget *parent = 0, Qt::WindowFlags flags = 0);
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("QUserShutDownDialog"));
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("ShutDown_label"));
        horizontalLayout->addWidget(label);
        retranslateUi(Dialog);
        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi
    void retranslateUi(QDialog *)
    {
        label->setText(tr(""));
    }//retranslateUi
};

class QUserMessageDialog:public QDialog
{
    Q_OBJECT
public:
    static QUserMessageDialog* create(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    static QUserMessageDialog* get();
    virtual ~QUserMessageDialog();
protected:
    explicit QUserMessageDialog(QWidget *parent = 0, Qt::WindowFlags flags = 0);
private slots:
    void OnConfirm();
    void OnCancel();
private:
    static QUserMessageDialog* intance;
public:
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QSpacerItem* vitem;
    QHBoxLayout *hboxLayout;
    QPushButton* confirm;
    QSpacerItem* middle;
    QPushButton* cancel;
    void retranslateUi(QDialog *Dialog);
    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("QUserMessageDialog"));
        vboxLayout = new QVBoxLayout(Dialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("ShutDown_label"));
        vboxLayout->addWidget(label);
        vitem = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
        vboxLayout->addItem(vitem);
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        confirm = new QPushButton(Dialog);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        hboxLayout->addWidget(confirm);
        middle = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        hboxLayout->addItem(middle);
        cancel = new QPushButton(Dialog);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        hboxLayout->addWidget(cancel);
        vboxLayout->addLayout(hboxLayout);
        vboxLayout->setStretch(0,4);
        vboxLayout->setStretch(1,1);
        retranslateUi(Dialog);
        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi
};


class QUserMachineCodeUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QUserMachineCodeUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserMachineCodeUI();
public:
    QHBoxLayout *h;
    QLabel*      label_c;
    QLabel*      label_r;
    QVBoxLayout *vl;

    QLabel*      label_rc;
    QRWidget*     rccode;
    QVBoxLayout *vrt;
    QVBoxLayout *vr;
    QLabelLineInput* code;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserMachineCodeUI"));
        h = new QHBoxLayout(Form);
        h->setObjectName(QString::fromUtf8("h"));

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
            h->setContentsMargins(0,0,0,0);
        else
            h->setContentsMargins(0, 0, 0, 0);
        vl = new QVBoxLayout();
        vl->setObjectName(QString::fromUtf8("vl"));
        vl->setContentsMargins(0,0,0,0);
        label_c = new QLabel(Form);
        label_c->setObjectName(QString::fromUtf8("label_c"));
        vl->addWidget(label_c);
        label_r = new QLabel(Form);
        label_r->setObjectName(QString::fromUtf8("label_r"));
        vl->addWidget(label_r);
        vl->setStretch(0,1);
        vl->setStretch(1,5);
        vr = new QVBoxLayout();
        vr->setObjectName(QString::fromUtf8("vr"));
        vr->setContentsMargins(0,0,0,0);
        vrt = new QVBoxLayout();
        vrt->setObjectName(QString::fromUtf8("vrt"));
        vrt->setContentsMargins(0,0,0,0);
        label_rc = new QLabel(Form);
        label_rc->setObjectName(QString::fromUtf8("label_rc"));
        vrt->addWidget(label_rc);
        rccode = new QRWidget(Form);
        rccode->setObjectName(QString::fromUtf8("rccode"));
        vrt->addWidget(rccode);
        vrt->setStretch(0,1);
        vrt->setStretch(1,4);
        vr->addLayout(vrt);
        code = new QLabelLineInput(Form);
        code->setObjectName(QString::fromUtf8("code"));
        vr->addWidget(code);

        h->addLayout(vl);
        h->addLayout(vr);
        h->setStretch(0,2);
        h->setStretch(1,1);
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

class MyMessageBox2 : public QDialog
{
    Q_OBJECT
public:
    explicit MyMessageBox2(QWidget *parent = 0, Qt::WindowFlags f = 0)
    {
        v_layout=new QVBoxLayout(this);
        v_layout->addWidget(&m_info);
        h_layout =new QHBoxLayout(this);
        v_layout->addLayout(h_layout);

        m_info.setAlignment(Qt::AlignCenter);
        m_info.setWordWrap(true);
        setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        //        m_pMsglabel->setStandardButtons(0);
        setStyleSheet("QDialog{color: white; background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(244, 243, 241, 255), stop:1 rgba(233, 229, 226, 255)); border: 10px; border-radius: 20px;}"
                      "QLabel{color: black;font: 32px;}"
                      "QPushButton{color: white; border-radius: 15px; width: 80px; border: 0px solid;}"
                      "QPushButton:focus{padding: -1;}");
        m_OK.setStyleSheet(CommonParam::m_sStyle20);
        m_OK.setFixedWidth(100);



        m_Cancle.setStyleSheet(CommonParam::m_sStyle20);
        m_Cancle.setFixedWidth(100);

        m_Yes.setStyleSheet(CommonParam::m_sStyle20);
        m_Yes.setFixedWidth(100);

        m_No.setStyleSheet(CommonParam::m_sStyle20);
        m_No.setFixedWidth(100);

        m_OK.setText(tr("OK"));
        m_Cancle.setText(tr("Cancle"));
        m_Yes.setText(tr("Yes"));
        m_No.setText(tr("No"));

        connect(&m_OK,SIGNAL(clicked()),this,SLOT(BtOK()));
        connect(&m_Cancle,SIGNAL(clicked()),this,SLOT(BtCancle()));
        connect(&m_Yes,SIGNAL(clicked()),this,SLOT(BtYes()));
        connect(&m_No,SIGNAL(clicked()),this,SLOT(BtNo()));

        h_layout->addWidget(&m_OK);
        h_layout->addWidget(&m_Cancle);

        m_eventLoop = new QEventLoop(this);
        this->setWindowModality(Qt::ApplicationModal);
    }
    ~MyMessageBox2()
    {
        delete h_layout;
        delete v_layout;
        delete m_eventLoop;
    }

    void setText(QString str)
    {
        m_info.setText(str);
    }
    int confirm(QString text)
    {
        m_Yes.hide();
        m_No.hide();
        this->show();
        m_info.setText(text);
        m_eventLoop->exec();
        return m_iResult;
    }
public slots:
    void BtOK();
    void BtCancle();
    void BtYes();
    void BtNo();
protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent* event)

    {
        QDialog::showEvent(event);
        setFixedSize(404*CommonParam::m_iWidth/800,245*CommonParam::m_iHeight/480);
    }
    //    void paintEvent(QPaintEvent *event)
    //    {
    ////        m_info.show();
    ////                QPainter paint(this);
    ////                paint.drawText(100,100,40,40,Qt::AlignVCenter|Qt::AlignHCenter,"hello");
    //    }
private:
    QLabel m_info;
    QPushButton m_OK;
    QPushButton m_Cancle;
    QPushButton m_Yes;
    QPushButton m_No;
    QVBoxLayout* v_layout;
    QHBoxLayout* h_layout;
    QEventLoop* m_eventLoop;
    int m_iResult;
};

class MedctrlMsgBox : public QMessageBox
{
    Q_OBJECT
public:
    explicit MedctrlMsgBox(QWidget *parent = 0);
    MedctrlMsgBox(Icon icon, const QString &title, const QString &text,
                  StandardButtons buttons = NoButton, QWidget *parent = 0,
                  Qt::WindowFlags flags = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);


    static MedctrlMsgBox *create(QWidget *parent);
    static MedctrlMsgBox *instance();
    static int info(QWidget *parent, QString text);
    static int Fetal(QWidget *parent, QString text);
    static int confirm(QWidget *parent, QString text);
    static int modifyDeleteUser(QWidget *parent, QString text);
    int info(QString text);
    int Fetal(QString text);
    int confirm(QString text);

    ~MedctrlMsgBox();

private:
    void init();
    void settingStyle();

    static MedctrlMsgBox *m_pInstance;
};

const QString ClinicalPassWD = "passwordreset";
class QClinicalCheckPWDUI : public CMessageNotify
{
    Q_OBJECT
public:
    explicit QClinicalCheckPWDUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~QClinicalCheckPWDUI();

    void    Update(QString param);
    bool    OnConfirm();
    bool    OnPrevious();
    void    retranslateUi(QWidget *form);

private:
    QVBoxLayout *m_pVLayout;
    QLabelLineInput *m_pLbLine;
};

class QClinicalConfigUI:public CMessageNotify
{
    Q_OBJECT
public:
    explicit QClinicalConfigUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QClinicalConfigUI();
    void Update(QString param);
public slots:

    void timesOfDayChange();
    void startTimeChange();
    void endTimeChange();

public:
    QGridLayout *gridLayout;

    QLabelLineInput*    m_pTimesOfDay;
    QLabelLineInput*    m_pStarTime;
    QLabelLineInput*    m_pEndTime;


    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QClinicalConfigUI"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0,0,0,0);
        gridLayout->setSpacing(0);

        m_pTimesOfDay = new QLabelLineInput(Form);
        m_pTimesOfDay->setObjectName(QString::fromUtf8("m_pTimesOfDay"));
        connect(m_pTimesOfDay->lineEdit,SIGNAL(textChanged1()),this,SLOT(timesOfDayChange()));
        gridLayout->addWidget(m_pTimesOfDay,0,0,1,1);

        m_pStarTime = new QLabelLineInput(Form);
        m_pStarTime->setObjectName(QString::fromUtf8("m_pStarTime"));
        connect(m_pStarTime->lineEdit,SIGNAL(textChanged1()),this,SLOT(startTimeChange()));
        gridLayout->addWidget(m_pStarTime,0,1,1,1);

        m_pEndTime = new QLabelLineInput(Form);
        m_pEndTime->setObjectName(QString::fromUtf8("m_pEndTime"));
        connect(m_pEndTime->lineEdit,SIGNAL(textChanged1()),this,SLOT(endTimeChange()));
        gridLayout->addWidget(m_pEndTime,1,0,1,1);

        m_pTimesOfDay->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        m_pStarTime->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);
        m_pEndTime->lineEdit->setKeyBoardType(T9Dialog::KB_INPUT_DIGITAL);

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi
};

#endif

