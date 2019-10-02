#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QtWidgets/QLabel>
 #include <QMouseEvent>
#include <QPushButton>
#include <QToolButton>

namespace Ui {
class mainForm;
}

class ActivityLabel : public QLabel
{
    Q_OBJECT
public:
    ActivityLabel(QWidget * parent = 0);
    ~ActivityLabel(void);

protected:
    void mouseReleaseEvent(QMouseEvent * ev);

Q_SIGNALS:
    void clicked();
};

class mainForm : public QWidget
{
    Q_OBJECT

public:
    explicit mainForm(QWidget *parent = 0);
    ~mainForm();

private:
    Ui::mainForm *ui;

    ActivityLabel *alb_ta;
    ActivityLabel *alb_td;


    QPushButton *btnNormal_;
         QPushButton *btnCheck_;
         QPushButton *btnMenu_;
         QPushButton *btnFlat_;
    QToolButton *toolBtn;


public slots:
    void timeAdd_tick();
    void timeDel_tick();

};

#endif // MAINFORM_H
