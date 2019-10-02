#ifndef WIFIINFOWIDGET_H
#define WIFIINFOWIDGET_H

#include <QWidget>
#include <QHostInfo>
#include"medkeyboard.h"

class QHBoxLayout;
class QVBoxLayout;
class QLabelSwicthInput;
class QLabelLineInput;
class QLabel;
class QPushButton;

class WifiInfoWidget : public QWidget
{
    Q_OBJECT
public:
    WifiInfoWidget(QWidget *parent = 0);
    ~WifiInfoWidget();

    void updateUI(QString ssid, QString title);
    void SetMyParent(QWidget *parent);
public slots:
    void testBtnClicked();
    void onLookupHost(QHostInfo);
    void reconnectBtnClicked();
    void checkStatus(bool flag);

protected:
    void showEvent(QShowEvent *event);

public:
    QString m_strSSid;
    QString m_strTitle;

//    QHBoxLayout *horizontalLayout;
//    QVBoxLayout *verticalLayout_2;
    QLabelSwicthInput *ifupdown;
    QLabelSwicthInput *dhcp_ip;
    CKBEdit *LineInput_ip;
    CKBEdit *LineInput_mask;
    CKBEdit *LineInput_gw;
    CKBEdit *LineInput_dns;
    QLabel *m_pLbTitle;
    QLabel *m_pLbInfo;
//    QHBoxLayout *m_pHBottomLayout;
    QPushButton *m_pBtnCancel;
    QPushButton *m_pBtnTestNet;
    QPushButton *m_pBtnReconnect;

    QPushButton *m_plabel1;
    QPushButton *m_plabel2;
    QPushButton *m_plabel3;
    QPushButton *m_plabel4;

    void retranslateUi(QWidget *Form);
    void setupUi(QWidget *Form);
    QWidget *m_parent;
};

#endif // WIFIINFOWIDGET_H
