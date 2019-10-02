#ifndef MEDCTRLAPPLICATION_H
#define MEDCTRLAPPLICATION_H

#include <QApplication>

class MedctrlApplication : public QApplication
{
    Q_OBJECT

public:
    explicit MedctrlApplication(int &argc, char **argv, int = ApplicationFlags);

    virtual ~MedctrlApplication();

private:
    int checkVolume();

protected:
    bool notify(QObject *object, QEvent *event);
};

#endif // MEDCTRLAPPLICATION_H
