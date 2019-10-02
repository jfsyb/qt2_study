/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *ql_setTime;
    QLabel *ql_whl;
    QLabel *ql_cql;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;

    void setupUi(QWidget *mainForm)
    {
        if (mainForm->objectName().isEmpty())
            mainForm->setObjectName(QStringLiteral("mainForm"));
        mainForm->setWindowModality(Qt::WindowModal);
        mainForm->resize(800, 480);
        mainForm->setAutoFillBackground(true);
        verticalLayoutWidget = new QWidget(mainForm);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 40, 169, 224));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ql_setTime = new QLabel(verticalLayoutWidget);
        ql_setTime->setObjectName(QStringLiteral("ql_setTime"));
        ql_setTime->setMinimumSize(QSize(167, 70));
        ql_setTime->setMaximumSize(QSize(167, 70));
        QFont font;
        font.setFamily(QStringLiteral("aakar"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        ql_setTime->setFont(font);
        ql_setTime->setAutoFillBackground(true);

        verticalLayout->addWidget(ql_setTime);

        ql_whl = new QLabel(verticalLayoutWidget);
        ql_whl->setObjectName(QStringLiteral("ql_whl"));
        ql_whl->setMinimumSize(QSize(167, 70));
        ql_whl->setMaximumSize(QSize(167, 70));
        ql_whl->setFont(font);
        ql_whl->setAutoFillBackground(true);

        verticalLayout->addWidget(ql_whl);

        ql_cql = new QLabel(verticalLayoutWidget);
        ql_cql->setObjectName(QStringLiteral("ql_cql"));
        ql_cql->setMinimumSize(QSize(167, 70));
        ql_cql->setMaximumSize(QSize(167, 70));
        ql_cql->setFont(font);
        ql_cql->setAutoFillBackground(true);

        verticalLayout->addWidget(ql_cql);

        horizontalLayoutWidget = new QWidget(mainForm);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(390, 30, 311, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(mainForm);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(540, 150, 210, 210));
        toolButton->setMinimumSize(QSize(210, 210));
        toolButton->setMaximumSize(QSize(30, 30));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{  \n"
"	font: 75 9pt \"Noto Naskh Arabic UI\";\n"
"   min-width:30px;  \n"
"   min-height:30px;  \n"
"}  \n"
"QToolButton{  \n"
"color:rgb(255, 0, 0);  \n"
"min-height:30;  \n"
"border-style:solid;  \n"
"border-top-left-radius:30px;  \n"
"border-top-right-radius:30px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(255,0,0),   \n"
"                            stop: 0.3 rgb(0,255,0),  \n"
"                              stop: 1 rgb(0,0,255));  \n"
"border:30px;  \n"
"border-radius:30px;padding:90px 90px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/  \n"
"}  \n"
"QToolButton:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/  \n"
"color:rgb(0, 255, 0);  \n"
"min-height:30;  \n"
"border-style:solid;  \n"
"border-top-left-radius:30px;  \n"
"border-top-right-radius:30px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(128,0,0),   \n"
"                            stop: 0.3 rgb(0,128,0),  \n"
""
                        "                              stop: 1 rgb(0,0,120));  \n"
"border:30px;  \n"
"border-radius:30px;padding:90px 90px;  \n"
"}  \n"
"QToolButton:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/  \n"
"color:rgb(0, 0, 255);  \n"
"min-height:30;  \n"
"border-style:solid;  \n"
"border-top-left-radius:30px;  \n"
"border-top-right-radius:30px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"                              stop: 1 rgb(160,160,160));  \n"
"border:30px;  \n"
"border-radius:30px;padding:30px 30px;  \n"
"}  \n"
"QToolButton:checked{    /*\351\200\211\344\270\255\345\220\216*/  \n"
"color:rgb(255, 255, 255);  \n"
"min-height:30;  \n"
"border-style:solid;  \n"
"border-top-left-radius:30px;  \n"
"border-top-right-radius:30px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),   \n"
"                            stop: 0.3 rgb(190,190,190),  \n"
"  "
                        "                            stop: 1 rgb(160,160,160));  \n"
"border:30px;  \n"
"border-radius:30px;padding:30px 30px;  \n"
"}  "));
        toolButton_2 = new QToolButton(mainForm);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(310, 190, 90, 90));
        toolButton_2->setMinimumSize(QSize(0, 0));
        toolButton_2->setMaximumSize(QSize(90, 90));
        toolButton_2->setAutoFillBackground(false);
        toolButton_2->setStyleSheet(QString::fromUtf8("\n"
"QToolButton{  \n"
"color:rgb(255, 0, 0);  \n"
"border-style:solid;  \n"
"border-top-left-radius:45px;  \n"
"border-top-right-radius:45px;  \n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(255,0,0),   \n"
"                            stop: 0.3 rgb(0,255,0),  \n"
"                              stop: 1 rgb(0,0,255));  \n"
"border-radius:45px;padding:90px 90px;/*border-radius\346\216\247\345\210\266\345\234\206\350\247\222\345\244\247\345\260\217*/  \n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/seven/imgs/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon);
        toolButton_2->setIconSize(QSize(90, 90));

        retranslateUi(mainForm);

        QMetaObject::connectSlotsByName(mainForm);
    } // setupUi

    void retranslateUi(QWidget *mainForm)
    {
        mainForm->setWindowTitle(QApplication::translate("mainForm", "Form", Q_NULLPTR));
        ql_setTime->setText(QApplication::translate("mainForm", "  \346\227\266   \351\227\264", Q_NULLPTR));
        ql_whl->setText(QApplication::translate("mainForm", "  \351\233\276 \345\214\226 \351\207\217", Q_NULLPTR));
        ql_cql->setText(QApplication::translate("mainForm", "  \344\272\247 \346\260\224 \351\207\217", Q_NULLPTR));
        toolButton->setText(QApplication::translate("mainForm", "\344\275\240\345\245\275", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("mainForm", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainForm: public Ui_mainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
