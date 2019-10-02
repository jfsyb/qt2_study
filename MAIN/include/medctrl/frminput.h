#ifndef FRMINPUT_H
#define FRMINPUT_H

#include <QWidget>
#include <QMutex>
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
#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QTreeWidgetItem>
#include <QScrollArea>
#include "../medctrl_c/medctrl_c.h"
extern int GetMachineType();
class IconHelper : public QObject
{
private:
    explicit IconHelper(QObject *parent = 0);
    QFont iconFont;
    static IconHelper* _instance;

public:
    static IconHelper* Instance()
    {
        static QMutex mutex;
        if(!_instance)
        {
            QMutexLocker locker(&mutex);
            if(!_instance)
            {
                _instance = new IconHelper;
            }
        }
        return _instance;
    }

    void SetIcon(QLabel* lab, QChar c, int size = 10);
    void SetIcon(QPushButton* btn, QChar c, int size = 10);
};

class frmInput:public QDialog
{
    Q_OBJECT
signals:
    void switchkb();
public:
    void retranslateUi(QWidget *frmInput);
    int  currentType;
    int  currentSubType;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QWidget *widgetTop;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labInfo;
    QLabel *labPY;
    QPushButton *btnPre;
    QPushButton *btnNext;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labCh0;
    QLabel *labCh1;
    QLabel *labCh2;
    QLabel *labCh3;
    QLabel *labCh4;
    QLabel *labCh5;
    QLabel *labCh6;
    QLabel *labCh7;
    QLabel *labCh8;
    QLabel *labCh9;
    QWidget *widgetMain;
    QGridLayout *gridLayout;
    QPushButton *btnOther1;
    QPushButton *btnOther2;
    QPushButton *btnOther3;
    QPushButton *btnOther4;
    QPushButton *btnOther5;
    QPushButton *btnOther6;
    QPushButton *btnOther7;
    QPushButton *btnOther8;
    QPushButton *btnOther9;
    QPushButton *btnOther10;
    QPushButton *btnOther11;
    QPushButton *btnDelete;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btnq;
    QPushButton *btnw;
    QPushButton *btne;
    QPushButton *btnr;
    QPushButton *btnt;
    QPushButton *btny;
    QPushButton *btnu;
    QPushButton *btni;
    QPushButton *btno;
    QPushButton *btnp;
    QPushButton *btnOther12;
    QPushButton *btnOther13;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btna;
    QPushButton *btns;
    QPushButton *btnd;
    QPushButton *btnf;
    QPushButton *btng;
    QPushButton *btnh;
    QPushButton *btnj;
    QPushButton *btnk;
    QPushButton *btnl;
    QPushButton *btnOther14;
    QPushButton *btnOther15;
    QPushButton *btnOther16;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btnz;
    QPushButton *btnx;
    QPushButton *btnc;
    QPushButton *btnv;
    QPushButton *btnb;
    QPushButton *btnn;
    QPushButton *btnm;
    QPushButton *btnOther17;
    QPushButton *btnOther18;
    QPushButton *btnType;
    QPushButton *btn0;
    QPushButton *btnOther19;
    QPushButton *btnDeleteMin;
    QPushButton *btnLanguage;
    QPushButton *Finish;
    QPushButton *kbswitch;

    void setupUi(QWidget *frmInput)
    {
        int MIN_W = 44;
        if (frmInput->objectName().isEmpty())
            frmInput->setObjectName(QString::fromUtf8("frmInput"));
        frmInput->setMinimumSize(800,240);
        if ( GetMachineType() == MACHINE_TYPE_4INCH )
            MIN_W = 32;
        else
            MIN_W = 44;
        frmInput->resize(800,240);
        frmInput->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(frmInput);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(frmInput);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        widgetTop = new QWidget(frmInput);
        widgetTop->setObjectName(QString::fromUtf8("widgetTop"));
        widgetTop->setMinimumSize(QSize(MIN_W, 0));
        verticalLayout = new QVBoxLayout(widgetTop);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, 5, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labInfo = new QLabel(widgetTop);
        labInfo->setObjectName(QString::fromUtf8("labInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labInfo->sizePolicy().hasHeightForWidth());
        labInfo->setSizePolicy(sizePolicy);
        labInfo->setMinimumSize(QSize(30, 25));

        horizontalLayout->addWidget(labInfo);

        labPY = new QLabel(widgetTop);
        labPY->setObjectName(QString::fromUtf8("labPY"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labPY->sizePolicy().hasHeightForWidth());
        labPY->setSizePolicy(sizePolicy1);
        labPY->setMinimumSize(QSize(30, 25));

        horizontalLayout->addWidget(labPY);

        btnPre = new QPushButton(widgetTop);
        btnPre->setObjectName(QString::fromUtf8("btnPre"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnPre->sizePolicy().hasHeightForWidth());
        btnPre->setSizePolicy(sizePolicy2);
        btnPre->setMinimumSize(QSize(MIN_W, 25));
        btnPre->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(btnPre);

        btnNext = new QPushButton(widgetTop);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        sizePolicy2.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy2);
        btnNext->setMinimumSize(QSize(MIN_W, 25));
        btnNext->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(btnNext);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labCh0 = new QLabel(widgetTop);
        labCh0->setObjectName(QString::fromUtf8("labCh0"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labCh0->sizePolicy().hasHeightForWidth());
        labCh0->setSizePolicy(sizePolicy3);
        labCh0->setMinimumSize(QSize(30, 25));
        labCh0->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh0);

        labCh1 = new QLabel(widgetTop);
        labCh1->setObjectName(QString::fromUtf8("labCh1"));
        sizePolicy3.setHeightForWidth(labCh1->sizePolicy().hasHeightForWidth());
        labCh1->setSizePolicy(sizePolicy3);
        labCh1->setMinimumSize(QSize(30, 25));
        labCh1->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh1);

        labCh2 = new QLabel(widgetTop);
        labCh2->setObjectName(QString::fromUtf8("labCh2"));
        sizePolicy3.setHeightForWidth(labCh2->sizePolicy().hasHeightForWidth());
        labCh2->setSizePolicy(sizePolicy3);
        labCh2->setMinimumSize(QSize(30, 25));
        labCh2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh2);

        labCh3 = new QLabel(widgetTop);
        labCh3->setObjectName(QString::fromUtf8("labCh3"));
        sizePolicy3.setHeightForWidth(labCh3->sizePolicy().hasHeightForWidth());
        labCh3->setSizePolicy(sizePolicy3);
        labCh3->setMinimumSize(QSize(30, 25));
        labCh3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh3);

        labCh4 = new QLabel(widgetTop);
        labCh4->setObjectName(QString::fromUtf8("labCh4"));
        sizePolicy3.setHeightForWidth(labCh4->sizePolicy().hasHeightForWidth());
        labCh4->setSizePolicy(sizePolicy3);
        labCh4->setMinimumSize(QSize(30, 25));
        labCh4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh4);

        labCh5 = new QLabel(widgetTop);
        labCh5->setObjectName(QString::fromUtf8("labCh5"));
        sizePolicy3.setHeightForWidth(labCh5->sizePolicy().hasHeightForWidth());
        labCh5->setSizePolicy(sizePolicy3);
        labCh5->setMinimumSize(QSize(30, 25));
        labCh5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh5);

        labCh6 = new QLabel(widgetTop);
        labCh6->setObjectName(QString::fromUtf8("labCh6"));
        sizePolicy3.setHeightForWidth(labCh6->sizePolicy().hasHeightForWidth());
        labCh6->setSizePolicy(sizePolicy3);
        labCh6->setMinimumSize(QSize(30, 25));
        labCh6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh6);

        labCh7 = new QLabel(widgetTop);
        labCh7->setObjectName(QString::fromUtf8("labCh7"));
        sizePolicy3.setHeightForWidth(labCh7->sizePolicy().hasHeightForWidth());
        labCh7->setSizePolicy(sizePolicy3);
        labCh7->setMinimumSize(QSize(30, 25));
        labCh7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh7);

        labCh8 = new QLabel(widgetTop);
        labCh8->setObjectName(QString::fromUtf8("labCh8"));
        sizePolicy3.setHeightForWidth(labCh8->sizePolicy().hasHeightForWidth());
        labCh8->setSizePolicy(sizePolicy3);
        labCh8->setMinimumSize(QSize(30, 25));
        labCh8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh8);

        labCh9 = new QLabel(widgetTop);
        labCh9->setObjectName(QString::fromUtf8("labCh9"));
        sizePolicy3.setHeightForWidth(labCh9->sizePolicy().hasHeightForWidth());
        labCh9->setSizePolicy(sizePolicy3);
        labCh9->setMinimumSize(QSize(30, 25));
        labCh9->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labCh9);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(widgetTop);

        widgetMain = new QWidget(frmInput);
        widgetMain->setObjectName(QString::fromUtf8("widgetMain"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widgetMain->sizePolicy().hasHeightForWidth());
        widgetMain->setSizePolicy(sizePolicy4);
        widgetMain->setMinimumSize(QSize(MIN_W, 0));
        widgetMain->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(widgetMain);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnOther4 = new QPushButton(widgetMain);
        btnOther4->setObjectName(QString::fromUtf8("btnOther4"));
        btnOther4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther4, 0, 7, 1, 3);

        btn1 = new QPushButton(widgetMain);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn1, 0, 35, 1, 1);

        btnOther6 = new QPushButton(widgetMain);
        btnOther6->setObjectName(QString::fromUtf8("btnOther6"));
        btnOther6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther6, 0, 13, 1, 3);

        btnOther7 = new QPushButton(widgetMain);
        btnOther7->setObjectName(QString::fromUtf8("btnOther7"));
        btnOther7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther7, 0, 16, 1, 3);

        btnOther8 = new QPushButton(widgetMain);
        btnOther8->setObjectName(QString::fromUtf8("btnOther8"));
        btnOther8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther8, 0, 19, 1, 3);

        btnOther9 = new QPushButton(widgetMain);
        btnOther9->setObjectName(QString::fromUtf8("btnOther9"));
        btnOther9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther9, 0, 22, 1, 3);

        btnOther10 = new QPushButton(widgetMain);
        btnOther10->setObjectName(QString::fromUtf8("btnOther10"));
        btnOther10->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther10, 0, 25, 1, 3);

        btn2 = new QPushButton(widgetMain);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn2, 0, 36, 1, 1);

        btn3 = new QPushButton(widgetMain);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn3, 0, 37, 1, 1);

        btns = new QPushButton(widgetMain);
        btns->setObjectName(QString::fromUtf8("btns"));
        btns->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btns, 2, 3, 1, 3);

        btnq = new QPushButton(widgetMain);
        btnq->setObjectName(QString::fromUtf8("btnq"));
        btnq->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnq, 1, 0, 1, 2);

        btnw = new QPushButton(widgetMain);
        btnw->setObjectName(QString::fromUtf8("btnw"));
        btnw->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnw, 1, 2, 1, 3);

        btne = new QPushButton(widgetMain);
        btne->setObjectName(QString::fromUtf8("btne"));
        btne->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btne, 1, 5, 1, 3);

        btnr = new QPushButton(widgetMain);
        btnr->setObjectName(QString::fromUtf8("btnr"));
        btnr->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnr, 1, 8, 1, 3);

        btnt = new QPushButton(widgetMain);
        btnt->setObjectName(QString::fromUtf8("btnt"));
        btnt->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnt, 1, 11, 1, 3);

        btny = new QPushButton(widgetMain);
        btny->setObjectName(QString::fromUtf8("btny"));
        btny->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btny, 1, 14, 1, 3);

        btnu = new QPushButton(widgetMain);
        btnu->setObjectName(QString::fromUtf8("btnu"));
        btnu->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnu, 1, 17, 1, 3);

        btni = new QPushButton(widgetMain);
        btni->setObjectName(QString::fromUtf8("btni"));
        btni->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btni, 1, 20, 1, 3);

        btno = new QPushButton(widgetMain);
        btno->setObjectName(QString::fromUtf8("btno"));
        btno->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btno, 1, 23, 1, 3);

        btnp = new QPushButton(widgetMain);
        btnp->setObjectName(QString::fromUtf8("btnp"));
        btnp->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnp, 1, 26, 1, 4);

        btnOther12 = new QPushButton(widgetMain);
        btnOther12->setObjectName(QString::fromUtf8("btnOther12"));
        btnOther12->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther12, 1, 30, 1, 3);

        btnOther13 = new QPushButton(widgetMain);
        btnOther13->setObjectName(QString::fromUtf8("btnOther13"));
        btnOther13->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther13, 1, 33, 1, 2);

        btnOther1 = new QPushButton(widgetMain);
        btnOther1->setObjectName(QString::fromUtf8("btnOther1"));
        btnOther1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther1, 0, 0, 1, 1);

        btnOther2 = new QPushButton(widgetMain);
        btnOther2->setObjectName(QString::fromUtf8("btnOther2"));
        btnOther2->setFocusPolicy(Qt::NoFocus);
        gridLayout->addWidget(btnOther2, 0, 1, 1, 3);

        btnOther3 = new QPushButton(widgetMain);
        btnOther3->setObjectName(QString::fromUtf8("btnOther3"));
        btnOther3->setFocusPolicy(Qt::NoFocus);
        gridLayout->addWidget(btnOther3, 0, 4, 1, 3);

        btnOther5 = new QPushButton(widgetMain);
        btnOther5->setObjectName(QString::fromUtf8("btnOther5"));
        btnOther5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther5, 0, 10, 1, 3);

        btn4 = new QPushButton(widgetMain);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn4, 1, 35, 1, 1);

        btn5 = new QPushButton(widgetMain);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn5, 1, 36, 1, 1);

        btn6 = new QPushButton(widgetMain);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        btn6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn6, 1, 37, 1, 1);

        btna = new QPushButton(widgetMain);
        btna->setObjectName(QString::fromUtf8("btna"));
        btna->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btna, 2, 0, 1, 3);

        btnd = new QPushButton(widgetMain);
        btnd->setObjectName(QString::fromUtf8("btnd"));
        btnd->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnd, 2, 6, 1, 3);

        btnf = new QPushButton(widgetMain);
        btnf->setObjectName(QString::fromUtf8("btnf"));
        btnf->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnf, 2, 9, 1, 3);

        btng = new QPushButton(widgetMain);
        btng->setObjectName(QString::fromUtf8("btng"));
        btng->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btng, 2, 12, 1, 3);

        btnh = new QPushButton(widgetMain);
        btnh->setObjectName(QString::fromUtf8("btnh"));
        btnh->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnh, 2, 15, 1, 3);

        btnj = new QPushButton(widgetMain);
        btnj->setObjectName(QString::fromUtf8("btnj"));
        btnj->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnj, 2, 18, 1, 3);

        btnk = new QPushButton(widgetMain);
        btnk->setObjectName(QString::fromUtf8("btnk"));
        btnk->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnk, 2, 21, 1, 3);

        btnl = new QPushButton(widgetMain);
        btnl->setObjectName(QString::fromUtf8("btnl"));
        btnl->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnl, 2, 24, 1, 3);

        btnOther14 = new QPushButton(widgetMain);
        btnOther14->setObjectName(QString::fromUtf8("btnOther14"));
        btnOther14->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther14, 2, 27, 1, 4);

        btnOther15 = new QPushButton(widgetMain);
        btnOther15->setObjectName(QString::fromUtf8("btnOther15"));
        btnOther15->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther15, 2, 31, 1, 3);

        btnOther16 = new QPushButton(widgetMain);
        btnOther16->setObjectName(QString::fromUtf8("btnOther16"));
        btnOther16->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther16, 2, 34, 1, 1);

        btn7 = new QPushButton(widgetMain);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        btn7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn7, 2, 35, 1, 1);

        btn8 = new QPushButton(widgetMain);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        btn8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn8, 2, 36, 1, 1);

        btn9 = new QPushButton(widgetMain);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        btn9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn9, 2, 37, 1, 1);

        btnType = new QPushButton(widgetMain);
        btnType->setObjectName(QString::fromUtf8("btnType"));
        btnType->setFocusPolicy(Qt::NoFocus);
        gridLayout->addWidget(btnType, 3, 0, 1, 1);

        btnz = new QPushButton(widgetMain);
        btnz->setObjectName(QString::fromUtf8("btnz"));
        btnz->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnz, 3, 1, 1, 3);

        btnx = new QPushButton(widgetMain);
        btnx->setObjectName(QString::fromUtf8("btnx"));
        btnx->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnx, 3, 4, 1, 3);

        btnc = new QPushButton(widgetMain);
        btnc->setObjectName(QString::fromUtf8("btnc"));
        btnc->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnc, 3, 7, 1, 3);

        btnv = new QPushButton(widgetMain);
        btnv->setObjectName(QString::fromUtf8("btnv"));
        btnv->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnv, 3, 10, 1, 3);

        btnb = new QPushButton(widgetMain);
        btnb->setObjectName(QString::fromUtf8("btnb"));
        btnb->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnb, 3, 13, 1, 3);

        btnn = new QPushButton(widgetMain);
        btnn->setObjectName(QString::fromUtf8("btnn"));
        btnn->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnn, 3, 16, 1, 3);

        btnm = new QPushButton(widgetMain);
        btnm->setObjectName(QString::fromUtf8("btnm"));
        btnm->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnm, 3, 19, 1, 3);

        btnOther17 = new QPushButton(widgetMain);
        btnOther17->setObjectName(QString::fromUtf8("btnOther17"));
        btnOther17->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther17, 3, 22, 1, 3);

        btnOther18 = new QPushButton(widgetMain);
        btnOther18->setObjectName(QString::fromUtf8("btnOther18"));
        btnOther18->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther18, 3, 25, 1, 3);

        btn0 = new QPushButton(widgetMain);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        btn0->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btn0, 3, 35, 1, 1);

        btnOther19 = new QPushButton(widgetMain);
        btnOther19->setObjectName(QString::fromUtf8("btnOther19"));
        btnOther19->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther19, 3, 36, 1, 1);

        btnDeleteMin = new QPushButton(widgetMain);
        btnDeleteMin->setObjectName(QString::fromUtf8("btnDeleteMin"));
        btnDeleteMin->setFocusPolicy(Qt::NoFocus);
        gridLayout->addWidget(btnDeleteMin, 3, 37, 1, 1);

        btnOther11 = new QPushButton(widgetMain);
        btnOther11->setObjectName(QString::fromUtf8("btnOther11"));
        btnOther11->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnOther11, 0, 28, 1, 2);

        btnDelete = new QPushButton(widgetMain);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnDelete, 0, 30, 1, 2);

        btnLanguage = new QPushButton(widgetMain);
        btnLanguage->setObjectName(QString::fromUtf8("changed"));
        btnLanguage->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(btnLanguage, 3, 31, 1, 4);

        kbswitch = new QPushButton(widgetMain);
        kbswitch->setObjectName(QString::fromUtf8("switch_kb"));

        gridLayout->addWidget(kbswitch, 3, 28, 1, 3);

        Finish = new QPushButton(widgetMain);
        Finish->setObjectName(QString::fromUtf8("exit"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(kbswitch->sizePolicy().hasHeightForWidth());
        kbswitch->setSizePolicy(sizePolicy11);
        kbswitch->setFocusPolicy(Qt::NoFocus);
        sizePolicy11.setHeightForWidth(btnLanguage->sizePolicy().hasHeightForWidth());
        btnLanguage->setSizePolicy(sizePolicy11);
        btnLanguage->setFocusPolicy(Qt::NoFocus);
        sizePolicy11.setHeightForWidth(btnType->sizePolicy().hasHeightForWidth());
        btnType->setSizePolicy(sizePolicy11);
        sizePolicy11.setHeightForWidth(Finish->sizePolicy().hasHeightForWidth());
        Finish->setSizePolicy(sizePolicy11);
        Finish->setFocusPolicy(Qt::NoFocus);
        gridLayout->addWidget(Finish, 0, 32, 1, 3);


        verticalLayout_2->addWidget(widgetMain);


        retranslateUi(frmInput);

        QMetaObject::connectSlotsByName(frmInput);
    } // setupUi


public:
    explicit frmInput(QWidget *parent = 0);
    virtual ~frmInput();
    static frmInput *Instance() {
        static QMutex mutex;
        if (!_instance) {
            QMutexLocker locker(&mutex);
            if (!_instance) {
                if ( GetMachineType() == MACHINE_TYPE_4INCH ||
                     GetMachineType() == MACHINE_TYPE_5INCH_V )
                {
                    _instance_area_widget = new QWidget;
                    _instance_area_widget->setWindowFlags(Qt::FramelessWindowHint|Qt::Popup);
                    _instance_area_widget->setObjectName(QString::fromUtf8("_instance_area_widget"));
                    _instance_area_Layout = new QVBoxLayout(_instance_area_widget);
                    _instance_area = new QScrollArea(_instance_area_widget);
                    _instance_area->setObjectName(QString::fromUtf8("_instance_area"));
                    _instance_area->setMouseTracking(true);
                    _instance_area_Layout->addWidget(_instance_area);
                    if ( GetMachineType() == MACHINE_TYPE_4INCH )
                    {
                        _instance_area_widget->setGeometry(0,0,272,260);
                        _instance_area_widget->move(0,480-260);
                    }
                    else
                    {
                        _instance_area_widget->setGeometry(0,0,480,260);
                        _instance_area_widget->move(0,800-260);
                    }
                    _instance = new frmInput(_instance_area);
                    _instance_area->setWidget(_instance);
                }
                else
                    _instance = new frmInput;
            }
        }
        return _instance;
    }
    void InstallThis();
    void RemoveThis();
    void Show();
    void Hide();
    QLineEdit *currentLineEdit;     //当前焦点的文本框
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void contextMenuEvent(QContextMenuEvent *);
private slots:
    void focusChanged(QWidget *oldWidget, QWidget *nowWidget);
    void btn_clicked();             //按键处理
    void change_style();            //切换样式处理
private:
    static frmInput *_instance;
    static QScrollArea *_instance_area;
    static QWidget *_instance_area_widget;
    static QVBoxLayout *_instance_area_Layout;
    void InitStyle();               //初始化无边框窗体
    void InitForm();                //初始化窗体数据
    void InitProperty();            //初始化属性
    QMenu *menuStyle;               //样式选择右键菜单
    void changeType(int type);  //改变输入法类型
    void changeLetter(bool isUpper);//改变字母大小写

    QList<QLabel *>labCh;           //汉字标签数组
    QString allPY;                  //所有拼音链表
    QString currentPY;              //当前拼音链表
    int currentPY_index;            //当前拼音索引
    int currentPY_count;            //当前拼音数量
    void selectChinese();           //查询汉字
    void showChinese();             //显示查询到的汉字
    void setChinese(int index);     //设置当前汉字
    void clearChinese();            //清空当前汉字信息
};

#endif // FRMINPUT_H
