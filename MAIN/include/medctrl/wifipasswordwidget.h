#ifndef WIFIPASSWORDWIDGET_H
#define WIFIPASSWORDWIDGET_H

#include <QWidget>
#include <QLabel>
#include "medkeyboard.h"
class WifiConnectThread;
class QVBoxLayout;
class QHBoxLayout;
class QLabelLineInput;
class QPushButton;

class WifiPasswordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WifiPasswordWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~WifiPasswordWidget();

    inline void setSSid(QString ssid){ m_strSSid.clear(); m_strSSid = ssid;}
    inline void setTitle(QString title){m_pLbTitle->setText(title);}
    inline void setConnectThread(WifiConnectThread *thread){m_pThread = thread;}

protected:
    void showEvent(QShowEvent *);

public slots:
    void connectClicked();

private:
    void killWifiDHCP();
    void wifiConfig();

private:
    WifiConnectThread *m_pThread;

//    QVBoxLayout *m_pVLayout;
//    QHBoxLayout *m_pHLayout;

    QLabel *m_pLbTitle;

    CKBEdit *m_pLbLine;
    QPushButton *m_plabel;

    QPushButton *m_pBtnCancel;
    QPushButton *m_pBtnConnect;

    QString m_strSSid;
};

#endif // WIFIPASSWORDWIDGET_H
