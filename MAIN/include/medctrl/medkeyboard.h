#ifndef MEDCTRL_KEYBOARD_H
#define MEDCTRL_KEYBOARD_H

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
#include <QStandardItemModel>
#include "../medctrl_c/medctrl_c.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QInputContext>
#include"commondefine.h"
//extern int  currentMachineType();
class CKBEdit:public QLineEdit
{
    Q_OBJECT
public:
    CKBEdit(QWidget* parent = 0);
    ~CKBEdit();
    void SetText(QString str)
    {
        bool bSend = false;
        if ( text() != str )
            bSend = true;
        setText(str);
        if ( bSend )
            emit textChanged1();
    }

    void setKeyBoardType(int type){m_iKBType = type;}

Q_SIGNALS:
    void textChanged1();
protected:
    void contextMenuEvent(QContextMenuEvent *);
    void mousePressEvent(QMouseEvent*event);

private:
    int m_iKBType;
};

class CDateTimeEdit:public QLineEdit
{
    Q_OBJECT
public:
    CDateTimeEdit(int type = 0,QWidget* parent = 0):QLineEdit(parent),m_nType(type)
    {
    }
    ~CDateTimeEdit()
    {
    }
signals:
    void clicked(int type);
protected:
    void contextMenuEvent(QContextMenuEvent *)
    {
    }
    void mousePressEvent(QMouseEvent*)
    {
        emit clicked(m_nType);
    }
private:
    int m_nType;
};

typedef struct
{
    const char *T9;
    const char *PY;
    const unsigned char *MB;
    u_int16_t len;
}TInputIndex;

#define MAX_INDEX_NUM_SIZE 16
extern TInputIndex *pn[MAX_INDEX_NUM_SIZE];
extern u_int8_t get_matched_pymb1(int lang,u_int8_t *strin,TInputIndex **matchlist);

class QUserDig: public QWidget
{
    Q_OBJECT
public:
    explicit QUserDig(QWidget *parent = 0, Qt::WFlags flags = 0);
    virtual ~QUserDig();
public:
    QGridLayout *gridLayout;
    QPushButton* u1;
    QPushButton* u2;
    QPushButton* u3;
    QPushButton* u4;
    QPushButton* u5;
    QPushButton* u6;
    QPushButton* u7;
    QPushButton* u8;
    QPushButton* u9;
    QPushButton* u10;
    QPushButton* u11;
    QPushButton* u12;    
    QPushButton *s_delone;
    QPushButton *s_confirm;
    QPushButton* uRe;
    QPushButton* u13;
    QPushButton *s_en;
    QPushButton *s_chn;
    QPushButton *s_jp;
    QPushButton *s_sym;
    QHBoxLayout *m_hBoxLayOut1;
    QHBoxLayout *m_hBoxLayOut2;
    QHBoxLayout *m_hBoxLayOut3;
    QHBoxLayout *m_hBoxLayOut4;
    void setupUi(QWidget *Form)
    {
        s_en = new QPushButton(Form);
        s_en->setObjectName(QString::fromUtf8("s_en"));
        s_chn = new QPushButton(Form);
        s_chn->setObjectName(QString::fromUtf8("s_chn"));
        s_jp = new QPushButton(Form);
        s_jp->setObjectName(QString::fromUtf8("s_jp"));
        s_sym = new QPushButton(Form);
        s_sym->setObjectName(QString::fromUtf8("s_sym"));

        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserDig"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0,0,0,0);
        gridLayout->setSpacing(10);
        m_hBoxLayOut1=new QHBoxLayout(Form);
        m_hBoxLayOut1->setContentsMargins(20,0,20,0);
        m_hBoxLayOut1->setSpacing(50);
        gridLayout->addLayout(m_hBoxLayOut1,0,0,1,3);

        m_hBoxLayOut2=new QHBoxLayout(Form);
        m_hBoxLayOut2->setContentsMargins(20,0,20,0);
        m_hBoxLayOut2->setSpacing(50);
        gridLayout->addLayout(m_hBoxLayOut2,1,0,1,3);

        m_hBoxLayOut3=new QHBoxLayout(Form);
        m_hBoxLayOut3->setContentsMargins(20,0,20,0);
        m_hBoxLayOut3->setSpacing(50);
        gridLayout->addLayout(m_hBoxLayOut3,2,0,1,3);

        m_hBoxLayOut4=new QHBoxLayout(Form);
        if(CommonParam::machineType == MACHINE_TYPE_7INCH)
        {
        m_hBoxLayOut4->setContentsMargins(20,0,20,0);
        m_hBoxLayOut4->setSpacing(50);
        }
        else
        {
            m_hBoxLayOut4->setContentsMargins(185,0,0,0);
            m_hBoxLayOut4->setSpacing(80);
        }
        gridLayout->addLayout(m_hBoxLayOut4,3,0,1,3);

        m_hBoxLayOut1->addWidget(s_en);
        m_hBoxLayOut2->addWidget(s_chn);
        m_hBoxLayOut3->addWidget(s_jp);
        m_hBoxLayOut4->addWidget(s_sym);
        s_en->setText(tr("En"));
        s_chn->setText(tr("Cn"));
        s_jp->setText(tr("Jp"));
        s_sym->setText(tr("Symbol"));

        u1 = new QPushButton(Form);
        u1->setObjectName(QString::fromUtf8("u1"));
        u1->setText("1");
        m_hBoxLayOut1->addWidget(u1);
        u2 = new QPushButton(Form);
        u2->setObjectName(QString::fromUtf8("u2"));
        m_hBoxLayOut1->addWidget(u2);
        u2->setText("2");
        u3 = new QPushButton(Form);
        u3->setObjectName(QString::fromUtf8("u3"));
        m_hBoxLayOut1->addWidget(u3);
        u3->setText("3");
        s_delone = new QPushButton(Form);
        s_delone->setObjectName(QString::fromUtf8("s_delone"));
        s_delone->setText("  ");
//        s_delone->setFixedWidth(150);
        m_hBoxLayOut1->addWidget(s_delone);


        u4 = new QPushButton(Form);
        u4->setObjectName(QString::fromUtf8("u4"));
        u4->setText("4");
        m_hBoxLayOut2->addWidget(u4);
        u5 = new QPushButton(Form);
        u5->setObjectName(QString::fromUtf8("u5"));
        m_hBoxLayOut2->addWidget(u5);
        u5->setText("5");
        u6 = new QPushButton(Form);
        u6->setObjectName(QString::fromUtf8("u6"));
        m_hBoxLayOut2->addWidget(u6);
        u6->setText("6");
        u11 = new QPushButton(Form);
        u11->setObjectName(QString::fromUtf8("u11"));
        m_hBoxLayOut2->addWidget(u11);
        u11->setText(".");
//        u11->setFixedWidth(120);

        u7 = new QPushButton(Form);
        u7->setObjectName(QString::fromUtf8("u7"));
        u7->setText("7");
        m_hBoxLayOut3->addWidget(u7);
        u8 = new QPushButton(Form);
        u8->setObjectName(QString::fromUtf8("u8"));
        m_hBoxLayOut3->addWidget(u8);
        u8->setText("8");
        u9 = new QPushButton(Form);
        u9->setObjectName(QString::fromUtf8("u9"));
        m_hBoxLayOut3->addWidget(u9);
        u9->setText("9");

        u12 = new QPushButton(Form);
        u12->setObjectName(QString::fromUtf8("u12"));
        m_hBoxLayOut3->addWidget(u12);
        u12->setText("#");
//        u12->setFixedWidth(120);

        uRe = new QPushButton(Form);
        uRe->setObjectName(QString::fromUtf8("uRe"));
        m_hBoxLayOut4->addWidget(uRe);
        uRe->setText(tr("Return"));

        u10 = new QPushButton(Form);
        u10->setObjectName(QString::fromUtf8("u10"));
        u10->setText("0");
//        if(CommonParam::machineType == MACHINE_TYPE_7INCH)
//        u10->setFixedWidth(200);
//            else
//            u10->setFixedWidth(170);
        m_hBoxLayOut4->addWidget(u10);

        u13= new QPushButton(Form);
        u13->setObjectName(QString::fromUtf8("u13"));
        m_hBoxLayOut4->addWidget(u13);

        u13->setText(" ");

        s_confirm = new QPushButton(Form);
        s_confirm->setObjectName(QString::fromUtf8("s_confirm"));
//        s_confirm->setFixedWidth(200);
        m_hBoxLayOut4->addWidget(s_confirm);
        s_confirm->setText(tr("Finish"));
//        s_confirm->setFixedWidth(300);


        for(int i=0;i<m_hBoxLayOut1->count();++i)
            qobject_cast<QPushButton*>(m_hBoxLayOut1->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);
        for(int i=0;i<m_hBoxLayOut2->count();++i)
            qobject_cast<QPushButton*>(m_hBoxLayOut2->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);
        for(int i=0;i<m_hBoxLayOut3->count();++i)
            qobject_cast<QPushButton*>(m_hBoxLayOut3->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);
        for(int i=0;i<m_hBoxLayOut4->count();++i)
            qobject_cast<QPushButton*>(m_hBoxLayOut4->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);

        s_delone->setStyleSheet(CommonParam::m_sStyle34);
        u13->setStyleSheet(CommonParam::m_sStyle40);
        s_confirm->setStyleSheet(CommonParam::m_sStyle35);

        s_en->setStyleSheet(CommonParam::m_sStyle32);
        s_chn->setStyleSheet(CommonParam::m_sStyle32);
        s_jp->setStyleSheet(CommonParam::m_sStyle32);
        s_sym->setStyleSheet(CommonParam::m_sStyle32);

        uRe->setStyleSheet(CommonParam::m_sStyle33);
        u11->setStyleSheet(CommonParam::m_sStyle32);
        u12->setStyleSheet(CommonParam::m_sStyle32);
        QMetaObject::connectSlotsByName(Form);
    }
};

class QUserEnglish: public QWidget
{
    Q_OBJECT
public:
    explicit QUserEnglish(QWidget *parent = 0,int type = 0, Qt::WFlags flags = 0);
    virtual ~QUserEnglish();
public:
    int nType;
    QGridLayout *gridLayout;

    QHBoxLayout *m_hBoxLayOut1;
    QHBoxLayout *m_hBoxLayOut2;
    QHBoxLayout *m_hBoxLayOut3;
    QPushButton* u1;
    QPushButton* u2;
    QPushButton* u3;
    QPushButton* u4;
    QPushButton* u5;
    QPushButton* u6;
    QPushButton* u7;
    QPushButton* u8;
    QPushButton* u9;
    QPushButton* u10;
    QPushButton* u11;
    QPushButton* u12;
    QPushButton* u13;
    QPushButton* u14;
    QPushButton* u15;
    QPushButton* u16;
    QPushButton* u17;
    QPushButton* u18;
    QPushButton* u19;
    QPushButton* u20;
    QPushButton* u21;
    QPushButton* u22;
    QPushButton* u23;
    QPushButton* u24;
    QPushButton* u25;
    QPushButton* u26;
    QPushButton* u27;
    QPushButton *s_delone;
//    QPushButton *s_confirm;
    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserEnglish"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        if ( (CommonParam::currentMachineType() == MACHINE_TYPE_4INCH) ||
             (CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V))
        {
            if(CommonParam::m_bTestMode)
                gridLayout->setContentsMargins(0,150,0,0);
            else
                gridLayout->setContentsMargins(0,150+320,0,0);
        }
        else
        {
            gridLayout->setContentsMargins(0,50,0,0);
        }
        gridLayout->setSpacing(0);


        m_hBoxLayOut1=new QHBoxLayout(Form);

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
        {
            m_hBoxLayOut1->setContentsMargins(0,10,0,15);
            m_hBoxLayOut1->setSpacing(10);
        }
        else
            m_hBoxLayOut1->setContentsMargins(0,0,0,50);
        gridLayout->addLayout(m_hBoxLayOut1,5,0,1,3);

        m_hBoxLayOut2=new QHBoxLayout(Form);

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
            m_hBoxLayOut2->setContentsMargins(50,5,50,15);
        else
            m_hBoxLayOut2->setContentsMargins(10,0,0,50);
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
            m_hBoxLayOut2->setSpacing(10);
        gridLayout->addLayout(m_hBoxLayOut2,6,0,1,3);

        m_hBoxLayOut3=new QHBoxLayout(Form);
        m_hBoxLayOut3->setContentsMargins(0,0,0,20);
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
            m_hBoxLayOut3->setSpacing(10);
        gridLayout->addLayout(m_hBoxLayOut3,7,0,1,3);

//        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
//             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
             u1 = new QPushButton(Form);
             u1->setObjectName(QString::fromUtf8("u1"));
             u1->setText("q");
             m_hBoxLayOut1->addWidget(u1);
             u2 = new QPushButton(Form);
             u2->setObjectName(QString::fromUtf8("u2"));
             m_hBoxLayOut1->addWidget(u2);
             u2->setText("w");
             u3 = new QPushButton(Form);
             u3->setObjectName(QString::fromUtf8("u3"));
             m_hBoxLayOut1->addWidget(u3);
             u3->setText("e");
             u4 = new QPushButton(Form);
             u4->setObjectName(QString::fromUtf8("u4"));
             u4->setText("r");
             m_hBoxLayOut1->addWidget(u4);
             u5 = new QPushButton(Form);
             u5->setObjectName(QString::fromUtf8("u5"));
             m_hBoxLayOut1->addWidget(u5);
             u5->setText("t");
             u6 = new QPushButton(Form);
             u6->setObjectName(QString::fromUtf8("u6"));
             m_hBoxLayOut1->addWidget(u6);
             u6->setText("y");

             u7 = new QPushButton(Form);
             u7->setObjectName(QString::fromUtf8("u7"));
             u7->setText("u");
             m_hBoxLayOut1->addWidget(u7);
             u8 = new QPushButton(Form);
             u8->setObjectName(QString::fromUtf8("u8"));
             m_hBoxLayOut1->addWidget(u8);
             u8->setText("i");
             u9 = new QPushButton(Form);
             u9->setObjectName(QString::fromUtf8("u9"));
             m_hBoxLayOut1->addWidget(u9);
             u9->setText("o");
             u10 = new QPushButton(Form);
             u10->setObjectName(QString::fromUtf8("u10"));
             u10->setText("p");
             m_hBoxLayOut1->addWidget(u10);


             u11 = new QPushButton(Form);
             u11->setObjectName(QString::fromUtf8("u11"));
//             gridLayout->setSpacing(20);
             m_hBoxLayOut2->addWidget(u11);
             u11->setText("a");
             u12 = new QPushButton(Form);
             u12->setObjectName(QString::fromUtf8("u12"));
             m_hBoxLayOut2->addWidget(u12);
             u12->setText("s");

             u13 = new QPushButton(Form);
             u13->setObjectName(QString::fromUtf8("u13"));
             u13->setText("d");
             m_hBoxLayOut2->addWidget(u13);
             u14 = new QPushButton(Form);
             u14->setObjectName(QString::fromUtf8("u14"));
             m_hBoxLayOut2->addWidget(u14);
             u14->setText("f");
             u15 = new QPushButton(Form);
             u15->setObjectName(QString::fromUtf8("u15"));
             m_hBoxLayOut2->addWidget(u15);
             u15->setText("g");
             u16 = new QPushButton(Form);
             u16->setObjectName(QString::fromUtf8("u16"));
             u16->setText("h");
             m_hBoxLayOut2->addWidget(u16);
             u17 = new QPushButton(Form);
             u17->setObjectName(QString::fromUtf8("u17"));
             m_hBoxLayOut2->addWidget(u17);
             u17->setText("j");
             u18 = new QPushButton(Form);
             u18->setObjectName(QString::fromUtf8("u18"));
             m_hBoxLayOut2->addWidget(u18);
             u18->setText("k");

             u19 = new QPushButton(Form);
             u19->setObjectName(QString::fromUtf8("u19"));
             u19->setText("l");
             m_hBoxLayOut2->addWidget(u19);

             s_delone = new QPushButton(Form);
             s_delone->setObjectName(QString::fromUtf8("s_delone"));
             s_delone->setText("  ");
             s_delone->setFixedWidth(100);

             u27 = new QPushButton(Form);
             u27->setObjectName(QString::fromUtf8("Caped"));
             if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
                u27->setFixedWidth(100);
             else
                 u27->setFixedWidth(150);
             m_hBoxLayOut3->addWidget(u27);
             QString sTemp("   ");
             //                 sTemp=sTemp+"Aa";
             u27->setText(sTemp);

             u20 = new QPushButton(Form);
             u20->setObjectName(QString::fromUtf8("u20"));
             m_hBoxLayOut3->addWidget(u20);
             u20->setText("z");
             u21 = new QPushButton(Form);
             u21->setObjectName(QString::fromUtf8("u21"));
             m_hBoxLayOut3->addWidget(u21);
             u21->setText("x");
             u22 = new QPushButton(Form);
             u22->setObjectName(QString::fromUtf8("u22"));
             u22->setText("c");
             m_hBoxLayOut3->addWidget(u22);
             u23 = new QPushButton(Form);
             u23->setObjectName(QString::fromUtf8("u23"));
             m_hBoxLayOut3->addWidget(u23);
             u23->setText("v");
             u24 = new QPushButton(Form);
             u24->setObjectName(QString::fromUtf8("u24"));
             m_hBoxLayOut3->addWidget(u24);
             u24->setText("b");

//             if ( nType == 0 )
//             {
//                 u27 = new QPushButton(Form);
//                 u27->setObjectName(QString::fromUtf8("Caped"));
//                 gridLayout->addWidget(u27,6,0,1,1);
//                 QString sTemp("↑Aa");
////                 sTemp=sTemp+"Aa";
//                 u27->setText(sTemp);
//             }

             u25 = new QPushButton(Form);
             u25->setObjectName(QString::fromUtf8("u25"));
             m_hBoxLayOut3->addWidget(u25);
             u25->setText("n");
             u26 = new QPushButton(Form);
             u26->setObjectName(QString::fromUtf8("u26"));
             m_hBoxLayOut3->addWidget(u26);
             u26->setText("m");

             m_hBoxLayOut3->addWidget(s_delone);

//             s_confirm = new QPushButton(Form);
//             s_confirm->setObjectName(QString::fromUtf8("s_confirm"));

//             if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
//             s_confirm->setFixedWidth(200);
//             else
//                 s_confirm->setFixedWidth(150);
//             m_hBoxLayOut3->addWidget(s_confirm);
//             s_confirm->setText(tr("Finish"));

             for(int i=0;i<m_hBoxLayOut1->count();++i)
                 qobject_cast<QPushButton*>(m_hBoxLayOut1->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);

             for(int i=0;i<m_hBoxLayOut2->count();++i)
                 qobject_cast<QPushButton*>(m_hBoxLayOut2->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);


             for(int i=0;i<m_hBoxLayOut3->count();++i)
                 qobject_cast<QPushButton*>(m_hBoxLayOut3->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);


             s_delone->setStyleSheet(CommonParam::m_sStyle34);
//             s_confirm->setStyleSheet(CommonParam::m_sStyle35);
             u27->setStyleSheet(CommonParam::m_sStyle36);
        }
//        else
//        {
//             u1 = new QPushButton(Form);
//            u1->setObjectName(QString::fromUtf8("u1"));
//            u1->setText("a");
//            gridLayout->addWidget(u1,0,0,1,1);
//            u2 = new QPushButton(Form);
//            u2->setObjectName(QString::fromUtf8("u2"));
//            gridLayout->addWidget(u2,0,1,1,1);
//            u2->setText("b");
//            u3 = new QPushButton(Form);
//            u3->setObjectName(QString::fromUtf8("u3"));
//            gridLayout->addWidget(u3,0,2,1,1);
//            u3->setText("c");
//            u4 = new QPushButton(Form);
//            u4->setObjectName(QString::fromUtf8("u4"));
//            u4->setText("d");
//            gridLayout->addWidget(u4,0,3,1,1);
//            u5 = new QPushButton(Form);
//            u5->setObjectName(QString::fromUtf8("u5"));
//            gridLayout->addWidget(u5,0,4,1,1);
//            u5->setText("e");
//            u6 = new QPushButton(Form);
//            u6->setObjectName(QString::fromUtf8("u6"));
//            gridLayout->addWidget(u6,0,5,1,1);
//            u6->setText("f");

//            u7 = new QPushButton(Form);
//            u7->setObjectName(QString::fromUtf8("u7"));
//            u7->setText("g");
//            gridLayout->addWidget(u7,1,0,1,1);
//            u8 = new QPushButton(Form);
//            u8->setObjectName(QString::fromUtf8("u8"));
//            gridLayout->addWidget(u8,1,1,1,1);
//            u8->setText("h");
//            u9 = new QPushButton(Form);
//            u9->setObjectName(QString::fromUtf8("u9"));
//            gridLayout->addWidget(u9,1,2,1,1);
//            u9->setText("i");
//            u10 = new QPushButton(Form);
//            u10->setObjectName(QString::fromUtf8("u10"));
//            u10->setText("j");
//            gridLayout->addWidget(u10,1,3,1,1);
//            u11 = new QPushButton(Form);
//            u11->setObjectName(QString::fromUtf8("u11"));
//            gridLayout->addWidget(u11,1,4,1,1);
//            u11->setText("k");
//            u12 = new QPushButton(Form);
//            u12->setObjectName(QString::fromUtf8("u12"));
//            gridLayout->addWidget(u12,1,5,1,1);
//            u12->setText("l");

//            u13 = new QPushButton(Form);
//            u13->setObjectName(QString::fromUtf8("u13"));
//            u13->setText("m");
//            gridLayout->addWidget(u13,2,0,1,1);
//            u14 = new QPushButton(Form);
//            u14->setObjectName(QString::fromUtf8("u14"));
//            gridLayout->addWidget(u14,2,1,1,1);
//            u14->setText("n");
//            u15 = new QPushButton(Form);
//            u15->setObjectName(QString::fromUtf8("u15"));
//            gridLayout->addWidget(u15,2,2,1,1);
//            u15->setText("o");
//            u16 = new QPushButton(Form);
//            u16->setObjectName(QString::fromUtf8("u16"));
//            u16->setText("p");
//            gridLayout->addWidget(u16,2,3,1,1);
//            u17 = new QPushButton(Form);
//            u17->setObjectName(QString::fromUtf8("u17"));
//            gridLayout->addWidget(u17,2,4,1,1);
//            u17->setText("q");
//            u18 = new QPushButton(Form);
//            u18->setObjectName(QString::fromUtf8("u18"));
//            gridLayout->addWidget(u18,2,5,1,1);
//            u18->setText("r");

//            u19 = new QPushButton(Form);
//            u19->setObjectName(QString::fromUtf8("u19"));
//            u19->setText("s");
//            gridLayout->addWidget(u19,3,0,1,1);
//            u20 = new QPushButton(Form);
//            u20->setObjectName(QString::fromUtf8("u20"));
//            gridLayout->addWidget(u20,3,1,1,1);
//            u20->setText("t");
//            u21 = new QPushButton(Form);
//            u21->setObjectName(QString::fromUtf8("u21"));
//            gridLayout->addWidget(u21,3,2,1,1);
//            u21->setText("u");
//            u22 = new QPushButton(Form);
//            u22->setObjectName(QString::fromUtf8("u22"));
//            u22->setText("v");
//            gridLayout->addWidget(u22,3,3,1,1);
//            u23 = new QPushButton(Form);
//            u23->setObjectName(QString::fromUtf8("u23"));
//            gridLayout->addWidget(u23,3,4,1,1);
//            u23->setText("w");
//            u24 = new QPushButton(Form);
//            u24->setObjectName(QString::fromUtf8("u24"));
//            gridLayout->addWidget(u24,3,5,1,1);
//            u24->setText("x");

//            if ( nType == 0 )
//            {
//                u27 = new QPushButton(Form);
//                u27->setObjectName(QString::fromUtf8("Caped"));
//                gridLayout->addWidget(u27,4,0,1,1);
//                QString sTemp("↑Aa");
////                sTemp=sTemp+"Aa";
//                u27->setText(sTemp);
//            }
//            u25 = new QPushButton(Form);
//            u25->setObjectName(QString::fromUtf8("u25"));
//            gridLayout->addWidget(u25,4,1,1,1);
//            u25->setText("y");
//            u26 = new QPushButton(Form);
//            u26->setObjectName(QString::fromUtf8("u26"));
//            gridLayout->addWidget(u26,4,2,1,1);
//            u26->setText("z");
//        }

        //for(int i=0;i<gridLayout->count();++i)
          //  qobject_cast<QPushButton*>(gridLayout->layout()->itemAt(i)->widget())->setStyleSheet("font-size : 56px");

        QMetaObject::connectSlotsByName(Form);
    }
};

class QUserSym: public QWidget
{
    Q_OBJECT
public:
    explicit QUserSym(QWidget *parent = 0,Qt::WFlags flags = 0);
    virtual ~QUserSym();
public:
    int nType;
    QGridLayout *gridLayout;
    QHBoxLayout *m_hBoxLayOut1;
    QHBoxLayout *m_hBoxLayOut2;
    QHBoxLayout *m_hBoxLayOut3;
    QPushButton* u1;
    QPushButton* u2;
    QPushButton* u3;
    QPushButton* u4;
    QPushButton* u5;
    QPushButton* u6;
    QPushButton* u7;
    QPushButton* u8;
    QPushButton* u9;
    QPushButton* u10;
    QPushButton* u11;
    QPushButton* u12;
    QPushButton* u13;
    QPushButton* u14;
    QPushButton* u15;
    QPushButton* u16;
    QPushButton* u17;
    QPushButton* u18;
    QPushButton* u19;
    QPushButton* u20;
    QPushButton* u21;
    QPushButton* u22;
    QPushButton* u23;
    QPushButton* u24;
    QPushButton* u25;
    QPushButton* u26;
    QPushButton* u27;
    QPushButton* u28;
    QPushButton* u29;
    QPushButton* u30;
    QPushButton* u31;
    QPushButton* u32;
    QPushButton* u33;
    QPushButton *s_delone;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("QUserSym"));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        if ( (CommonParam::currentMachineType() == MACHINE_TYPE_4INCH) ||
             (CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V))
        {
            if(CommonParam::m_bTestMode)
                gridLayout->setContentsMargins(0,150,0,0);
            else
                gridLayout->setContentsMargins(0,150+320,0,0);
        }
        else
        {
            gridLayout->setContentsMargins(0,50,0,0);
        }
        gridLayout->setSpacing(0);


        m_hBoxLayOut1=new QHBoxLayout(Form);

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
        {
            m_hBoxLayOut1->setContentsMargins(0,10,0,15);
            m_hBoxLayOut1->setSpacing(10);
        }
        else
            m_hBoxLayOut1->setContentsMargins(0,0,0,50);
        gridLayout->addLayout(m_hBoxLayOut1,5,0,1,3);

        m_hBoxLayOut2=new QHBoxLayout(Form);

        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
            m_hBoxLayOut2->setContentsMargins(35,5,35,15);
        else
            m_hBoxLayOut2->setContentsMargins(10,0,0,50);
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
            m_hBoxLayOut2->setSpacing(10);
        gridLayout->addLayout(m_hBoxLayOut2,6,0,1,3);

        m_hBoxLayOut3=new QHBoxLayout(Form);
        m_hBoxLayOut3->setContentsMargins(50,0,0,20);
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_7INCH)
            m_hBoxLayOut3->setSpacing(5);
        gridLayout->addLayout(m_hBoxLayOut3,7,0,1,3);

        u1 = new QPushButton(Form);        
        u1->setObjectName(QString::fromUtf8("u1"));
        u1->setText("!");
        m_hBoxLayOut1->addWidget(u1);
        u2 = new QPushButton(Form);
        u2->setObjectName(QString::fromUtf8("u2"));
        m_hBoxLayOut1->addWidget(u2);
        u2->setText("@");
        u3 = new QPushButton(Form);
        u3->setObjectName(QString::fromUtf8("u3"));
        m_hBoxLayOut1->addWidget(u3);
        u3->setText("#");
        u4 = new QPushButton(Form);
        u4->setObjectName(QString::fromUtf8("u4"));
        u4->setText("$");
        m_hBoxLayOut1->addWidget(u4);
        u5 = new QPushButton(Form);
        u5->setObjectName(QString::fromUtf8("u5"));
        m_hBoxLayOut1->addWidget(u5);
        u5->setText("%");

        s_delone = new QPushButton(Form);
        s_delone->setObjectName(QString::fromUtf8("s_delone"));
        s_delone->setText("  ");
        if(CommonParam::machineType == MACHINE_TYPE_7INCH)
        s_delone->setFixedWidth(100);
        else
            s_delone->setFixedWidth(150);

        u6 = new QPushButton(Form);
        u6->setObjectName(QString::fromUtf8("u6"));
        m_hBoxLayOut1->addWidget(u6);
        u6->setText("^");



        u7 = new QPushButton(Form);
        u7->setObjectName(QString::fromUtf8("btnSpecial"));
        u7->setText("&&");
        m_hBoxLayOut1->addWidget(u7);
        u8 = new QPushButton(Form);
        u8->setObjectName(QString::fromUtf8("u8"));
        m_hBoxLayOut1->addWidget(u8);
        u8->setText("*");


        u9 = new QPushButton(Form);
        u9->setObjectName(QString::fromUtf8("u9"));
        m_hBoxLayOut1->addWidget(u9);
        u9->setText("[");


        u32 = new QPushButton(Form);
        u32->setObjectName(QString::fromUtf8("u9"));
        m_hBoxLayOut1->addWidget(u32);
        u32->setText("+");
        u10 = new QPushButton(Form);
        u10->setObjectName(QString::fromUtf8("u10"));
        u10->setText("]");
        m_hBoxLayOut1->addWidget(u10);
        u11 = new QPushButton(Form);
        u11->setObjectName(QString::fromUtf8("u11"));
        m_hBoxLayOut2->addWidget(u11);
        u11->setText("{");
        u12 = new QPushButton(Form);
        u12->setObjectName(QString::fromUtf8("u12"));
        m_hBoxLayOut2->addWidget(u12);
        u12->setText("}");
        u13 = new QPushButton(Form);
        u13->setObjectName(QString::fromUtf8("u13"));
        u13->setText("|");
        m_hBoxLayOut2->addWidget(u13);
        u14 = new QPushButton(Form);
        u14->setObjectName(QString::fromUtf8("u14"));
        m_hBoxLayOut2->addWidget(u14);
        u14->setText("\\");
        u15 = new QPushButton(Form);
        u15->setObjectName(QString::fromUtf8("u15"));
        m_hBoxLayOut2->addWidget(u15);
        u15->setText(":");
        u16 = new QPushButton(Form);
        u16->setObjectName(QString::fromUtf8("u16"));
        u16->setText(";");
        m_hBoxLayOut2->addWidget(u16);
        u17 = new QPushButton(Form);
        u17->setObjectName(QString::fromUtf8("u17"));
        m_hBoxLayOut2->addWidget(u17);
        u17->setText("\"");
        u18 = new QPushButton(Form);
        u18->setObjectName(QString::fromUtf8("u18"));
        m_hBoxLayOut2->addWidget(u18);
        u18->setText("'");

        u19 = new QPushButton(Form);
        u19->setObjectName(QString::fromUtf8("u19"));
        u19->setText("<");
        m_hBoxLayOut2->addWidget(u19);
        u20 = new QPushButton(Form);
        u20->setObjectName(QString::fromUtf8("u20"));
        m_hBoxLayOut2->addWidget(u20);
        u20->setText(">");
        u21 = new QPushButton(Form);
        u21->setObjectName(QString::fromUtf8("u21"));
        m_hBoxLayOut3->addWidget(u21);
        u21->setText(",");
        u22 = new QPushButton(Form);
        u22->setObjectName(QString::fromUtf8("u22"));
        u22->setText(".");
        m_hBoxLayOut3->addWidget(u22);
        u23 = new QPushButton(Form);
        u23->setObjectName(QString::fromUtf8("u23"));
        m_hBoxLayOut3->addWidget(u23);
        u23->setText("?");
        u24 = new QPushButton(Form);
        u24->setObjectName(QString::fromUtf8("u24"));
        m_hBoxLayOut3->addWidget(u24);
        u24->setText("/");

        u29 = new QPushButton(Form);
        u29->setObjectName(QString::fromUtf8("u29"));
        u29->setText(" ");
        u29->setFixedWidth(110);
        m_hBoxLayOut3->addWidget(u29);

        u25 = new QPushButton(Form);
        u25->setObjectName(QString::fromUtf8("u25"));
        m_hBoxLayOut3->addWidget(u25);
        u25->setText("-");
        u26 = new QPushButton(Form);
        u26->setObjectName(QString::fromUtf8("u26"));
        m_hBoxLayOut3->addWidget(u26);
        u26->setText("=");

        u27 = new QPushButton(Form);
        u27->setObjectName(QString::fromUtf8("u27"));
        m_hBoxLayOut3->addWidget(u27);
        u27->setText("~");
        u28 = new QPushButton(Form);
        u28->setObjectName(QString::fromUtf8("u28"));
        u28->setText("`");
        m_hBoxLayOut3->addWidget(u28);


        m_hBoxLayOut3->addWidget(s_delone);

        for(int i=0;i<m_hBoxLayOut1->count();++i)
            qobject_cast<QPushButton*>(m_hBoxLayOut1->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);

        for(int i=0;i<m_hBoxLayOut2->count();++i)
            qobject_cast<QPushButton*>(m_hBoxLayOut2->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);


        for(int i=0;i<m_hBoxLayOut3->count();++i)
            qobject_cast<QPushButton*>(m_hBoxLayOut3->layout()->itemAt(i)->widget())->setStyleSheet(CommonParam::m_sStyle31);

        s_delone->setStyleSheet(CommonParam::m_sStyle34);
        u29->setStyleSheet(CommonParam::m_sStyle40);
        QMetaObject::connectSlotsByName(Form);
    }
};


class T9Dialog:public QDialog
{
    Q_OBJECT
public:
    static T9Dialog* createNew(QWidget* parent,Qt::WindowFlags flag,int machineType);
    static T9Dialog* get();
    T9Dialog(QWidget* parent=0,Qt::WindowFlags flag=0);
    virtual ~T9Dialog();
    enum KeyBoardType
    {
        KB_INPUT_CHN,
        KB_INPUT_CHN_TW,
        KB_INPUT_ENG,
        KB_INPUT_JP,
        KB_INPUT_DIGITAL,
        KB_INPUT_SYMBL,
    };
    void changeType(int type);  //改变输入法类型
    void changeLetter(bool isUpper);//改变字母大小写
    void selectChinese();           //查询备选
    void showChinese();            //显示查询到的备选
    void setChinese(int index);    //设置备选汉字
    virtual void clearChinese();            //清空当前备选信息

protected:
    void showEvent(QShowEvent *);

    void showChineseSelectButton(bool show = true);

public:
    virtual void showPanel()
    {
#if defined __arm__
            this->setGeometry(0,0, QApplication::desktop()->width(), QApplication::desktop()->height());
#else
        if ( (CommonParam::currentMachineType() == MACHINE_TYPE_4INCH) ||
             (CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V))
        {
            if(CommonParam::m_bTestMode)
                setGeometry(0,0,720,960);
            else
                setGeometry(0,0,720,1280);
        }
        else if ( CommonParam::currentMachineType() == MACHINE_TYPE_12INCH )
            setGeometry(0,0,800,600);
        else
            setGeometry(0,0,800,480);
#endif
            show();
            text_input->end(false);
//            changeType(KB_INPUT_DIGITAL);
            exec();
    }
    virtual void hidePanel()
    {
        if ( inputContext )
        {
            inputContext->SetText(text_input->text());
            inputContext = NULL;
        }
        done(0);
    }
    virtual void setInputContext(CKBEdit* widget)
    {
        if ( widget == NULL )
            return;
        inputContext = widget;
        if ( inputContext->validator() )
            text_input->setValidator(inputContext->validator());
        text_input->setEchoMode(inputContext->echoMode());
        text_input->setText(inputContext->text());
    }
public slots:
    void btn_clicked();
    void showThis()
    {
        showPanel();
    }
protected:
    QFont            m_oldFont;
    QVBoxLayout*     mainLayout;
    QHBoxLayout*     top_input;
    QLabel*          top_lang;
    QLabel*          text_lang;
    QLineEdit*       text_input;

    QWidget*      candicateView;
    QHBoxLayout*  candicate;
    QPushButton *candicate1;
    QPushButton *candicate2;
    QPushButton *candicate3;
    QPushButton *candicate4;
    QPushButton *candicate5;
    QPushButton *candicate_next;
    QList<QPushButton*> candicateBtns;

    QHBoxLayout*  keylayout;
    QVBoxLayout*  ctrlLayout;
//    QHBoxLayout*  ctrlLayout_h;
//    QPushButton *s_delone;
//    QPushButton *s_delall;
//    QPushButton *s_confirm;
    QStackedWidget*  stackedWidget;

    QHBoxLayout*  switchlayout;
    QPushButton *s_dig;
    QPushButton *s_en;
    QPushButton *s_chn;
    QPushButton *s_tw;
    QPushButton *s_jp;
    QPushButton *s_sym;
    QPushButton *s_confirm;

    static T9Dialog* keyboard;
    int              currentSubType;
    CKBEdit*         inputContext;
    QString          allPY;                  //所有拼音链表
    QString          currentPY;              //当前拼音链表
    int              currentPY_index;            //当前拼音索引
    int              currentPY_count;            //当前拼音数量
    void setupUI(QWidget* Form)
    {
        mainLayout = new QVBoxLayout(Form);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(0);
        top_input = new QHBoxLayout();
        top_input->setObjectName(QString::fromUtf8("top_input"));
        top_input->setSpacing(0);
        top_lang = new QLabel(Form);
        top_lang->setObjectName(QString::fromUtf8("top_lang"));

        top_input->addWidget(top_lang);
        text_lang = new QLabel(Form);
        text_lang->setObjectName(QString::fromUtf8("text_lang"));
        top_input->addWidget(text_lang);
        text_input = new QLineEdit(Form);
        text_input->setObjectName(QString::fromUtf8("text_input"));
        top_input->addWidget(text_input);

        //input edit
//        for(int i=0;i<top_input->count();++i)
//            top_input->layout()->itemAt(i)->widget()->setStyleSheet(CommonParam::m_sStyle32);


        mainLayout->addLayout(top_input);
        candicateView = new QWidget(Form);
        candicateView->setObjectName(QString::fromUtf8("candicateView"));
        mainLayout->addWidget(candicateView);
        candicate = new QHBoxLayout(candicateView);
        candicate->setSpacing(0);
        candicate->setObjectName(QString::fromUtf8("candicate"));
        candicate1 = new QPushButton(Form);
        candicate1->setObjectName(QString::fromUtf8("candicate1"));
        candicate->addWidget(candicate1);
        candicate2 = new QPushButton(Form);
        candicate2->setObjectName(QString::fromUtf8("candicate2"));
        candicate->addWidget(candicate2);
        candicate3 = new QPushButton(Form);
        candicate3->setObjectName(QString::fromUtf8("candicate3"));
        candicate->addWidget(candicate3);
        candicate4 = new QPushButton(Form);
        candicate4->setObjectName(QString::fromUtf8("candicate4"));
        candicate->addWidget(candicate4);
        candicate5 = new QPushButton(Form);
        candicate5->setObjectName(QString::fromUtf8("candicate5"));
        candicate->addWidget(candicate5);
        candicate_next = new QPushButton(Form);
        candicate_next->setObjectName(QString::fromUtf8("candicate_next"));
        candicate->addWidget(candicate_next);

        for(int i=0;i<candicate->count();++i)
            candicate->layout()->itemAt(i)->widget()->setStyleSheet(CommonParam::m_sStyle31);

        keylayout = new QHBoxLayout();
        keylayout->setObjectName(QString::fromUtf8("keylayout"));
        keylayout->setSpacing(0);
        stackedWidget = new QStackedWidget(Form);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        keylayout->addWidget(stackedWidget);
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
//            ctrlLayout_h = new QHBoxLayout();
//            ctrlLayout_h->setObjectName(QString::fromUtf8("ctrlLayout"));
//            s_delone = new QPushButton(Form);
//            s_delone->setObjectName(QString::fromUtf8("s_delone"));
//            ctrlLayout_h->addWidget(s_delone);
//            s_delall = new QPushButton(Form);
//            s_delall->setObjectName(QString::fromUtf8("s_delall"));
//            ctrlLayout_h->addWidget(s_delall);
//            s_confirm = new QPushButton(Form);
//            s_confirm->setObjectName(QString::fromUtf8("s_confirm"));
//            ctrlLayout_h->addWidget(s_confirm);

//            for(int i=0;i<ctrlLayout_h->count();++i)
//                ctrlLayout_h->layout()->itemAt(i)->widget()->setStyleSheet("font-size : 56px");


            mainLayout->addLayout(keylayout);
//            mainLayout->addLayout(ctrlLayout_h);
        }
        else
        {
            ctrlLayout = new QVBoxLayout();
            ctrlLayout->setObjectName(QString::fromUtf8("ctrlLayout"));
//            s_delone = new QPushButton(Form);
//            s_delone->setObjectName(QString::fromUtf8("s_delone"));
//            ctrlLayout->addWidget(s_delone);
//            s_delall = new QPushButton(Form);
//            s_delall->setObjectName(QString::fromUtf8("s_delall"));
//            ctrlLayout->addWidget(s_delall);
//            s_confirm = new QPushButton(Form);
//            s_confirm->setObjectName(QString::fromUtf8("s_confirm"));
//            ctrlLayout->addWidget(s_confirm);

            for(int i=0;i<ctrlLayout->count();++i)
                ctrlLayout->layout()->itemAt(i)->widget()->setStyleSheet(CommonParam::m_sStyle32);

            keylayout->addLayout(ctrlLayout);
//            keylayout->setStretch(0,7);
//            keylayout->setStretch(1,1);
            mainLayout->addLayout(keylayout);
        }
        switchlayout = new QHBoxLayout();
        switchlayout->setSpacing(10);
        switchlayout->setObjectName(QString::fromUtf8("switchlayout"));
        s_sym = new QPushButton(Form);
        s_sym->setObjectName(QString::fromUtf8("s_sym"));
        switchlayout->addWidget(s_sym);

        s_dig = new QPushButton(Form);
        s_dig->setObjectName(QString::fromUtf8("s_dig"));
        switchlayout->addWidget(s_dig);

        s_chn = new QPushButton(Form);
        s_chn->setObjectName(QString::fromUtf8("s_chn"));
        switchlayout->addWidget(s_chn);

        s_tw = new QPushButton(Form);
        s_tw->setObjectName(QString::fromUtf8("s_tw"));
        switchlayout->addWidget(s_tw);

        s_en = new QPushButton(Form);
        s_en->setObjectName(QString::fromUtf8("s_en"));
        switchlayout->addWidget(s_en);

        s_jp = new QPushButton(Form);
        s_jp->setObjectName(QString::fromUtf8("s_jp"));
        switchlayout->addWidget(s_jp);


        s_confirm = new QPushButton(Form);
        s_confirm->setObjectName(QString::fromUtf8("s_confirm"));
        if(CommonParam::machineType == MACHINE_TYPE_7INCH)
            s_confirm->setFixedWidth(150);
        else
            s_confirm->setFixedWidth(150);
        switchlayout->addWidget(s_confirm);
        s_confirm->setText(tr("Finish"));

        s_dig->setStyleSheet(CommonParam::m_sStyle32);
        s_en->setStyleSheet(CommonParam::m_sStyle32);
        s_chn->setStyleSheet(CommonParam::m_sStyle32);
        s_tw->setStyleSheet(CommonParam::m_sStyle32);
        s_jp->setStyleSheet(CommonParam::m_sStyle32);
        s_sym->setStyleSheet(CommonParam::m_sStyle32);


        for(int i=0;i<switchlayout->count();++i)
            switchlayout->layout()->itemAt(i)->widget()->setStyleSheet(CommonParam::m_sStyle32);
        s_confirm->setStyleSheet(CommonParam::m_sStyle35);

        mainLayout->addLayout(switchlayout);
        if ( CommonParam::currentMachineType() == MACHINE_TYPE_4INCH ||
             CommonParam::currentMachineType() == MACHINE_TYPE_5INCH_V )
        {
            mainLayout->setStretch(0,1);
            mainLayout->setStretch(1,1);
            mainLayout->setStretch(2,5);
            mainLayout->setStretch(3,1);
            mainLayout->setStretch(4,1);
        }
        else
        {
            mainLayout->setStretch(0,1);
            mainLayout->setStretch(1,1);
            mainLayout->setStretch(2,5);
            mainLayout->setStretch(3,1);
        }
        candicateBtns.append(candicate1);
        candicateBtns.append(candicate2);
        candicateBtns.append(candicate3);
        candicateBtns.append(candicate4);
        candicateBtns.append(candicate5);
        retranslateUi(Form);
    }
    void retranslateUi(QWidget* Form);
};

class QInputPanelContext : public QInputContext
{
    Q_OBJECT
public:
    explicit QInputPanelContext(QObject* parent = 0);
    virtual ~QInputPanelContext();
    bool filterEvent(const QEvent* event);
    QString identifierName();
    QString language();
    bool isComposing() const;
    void reset();
private:
    T9Dialog *inputPanel;
};

#endif
