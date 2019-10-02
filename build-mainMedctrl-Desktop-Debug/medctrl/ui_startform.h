/********************************************************************************
** Form generated from reading UI file 'startform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTFORM_H
#define UI_STARTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartForm
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *StartForm)
    {
        if (StartForm->objectName().isEmpty())
            StartForm->setObjectName(QStringLiteral("StartForm"));
        StartForm->resize(800, 480);
        StartForm->setAutoFillBackground(true);
        horizontalLayoutWidget = new QWidget(StartForm);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(290, 210, 471, 131));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/seven/imgs/cup-i.png")));

        horizontalLayout->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/seven/imgs/cup-h.png")));

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/seven/imgs/cupii.png")));

        horizontalLayout->addWidget(label_3);

        pushButton = new QPushButton(StartForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(480, 390, 178, 54));
        pushButton->setMinimumSize(QSize(178, 54));
        pushButton->setMaximumSize(QSize(178, 56));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/logr.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(178, 54));
        pushButton->setAutoDefault(false);

        retranslateUi(StartForm);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(StartForm);
    } // setupUi

    void retranslateUi(QWidget *StartForm)
    {
        StartForm->setWindowTitle(QApplication::translate("StartForm", "Form", Q_NULLPTR));
        label_2->setText(QString());
        label->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartForm: public Ui_StartForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTFORM_H
