#ifndef LOGSERVER_H
#define LOGSERVER_H

#include "logserver_global.h"

#include <QtCore/qtextstream.h>
#include <QtCore/qcontiguouscache.h>
#include <QtCore/QFile>
#include <QtCore/QDateTime>
#include <QtCore/QStringList>
#include <QtCore/QMutex>
#include <stdint.h>
#include <unistd.h>

#define LOG_FILE            ("/AM/log/medctrl.log")
#define LOG_FILE_BAK        ("/AM/log/medctrl.log.bak")
#define FILE_NAME_LEN       (32)
#define FILE_LINE_LEN       (5)

#define LOG_SIZE            (1024*1024*20) //20M

enum MedMsgType { DebugMsg, WarningMsg, CriticalMsg, FatalMsg, SystemMsg = QtCriticalMsg};

class  LOGSERVERSHARED_EXPORT MedctrlDebug
{
    struct Stream {
        Stream(QIODevice *device) : ts(device), ref(1), type(DebugMsg), space(true), message_output(false) {}
        Stream(QString *string) : ts(string, QIODevice::WriteOnly), ref(1), type(DebugMsg), space(true), message_output(false) {}
        Stream(MedMsgType t, QIODevice *io) : ts(io), ref(1), type(t), space(true), message_output(true) {}
        Stream(MedMsgType t) : ts(&buffer, QIODevice::WriteOnly), ref(1), type(t), space(true), message_output(true) {}
        QTextStream ts;
        QString buffer;
        int ref;
        MedMsgType type;
        bool space;
        bool message_output;
    } *stream;
public:

    QFile logFile;
    QMutex mutex;

    /****
     *
     * file log mode : true output to the file,
     *                 false output to the console
     *                 default is ture
     *
     * ***/

//    bool m_iFileFlag=true;

//    void setFileFlag(bool flag) { m_iFileFlag = flag;}

    inline MedctrlDebug(QIODevice *device) : stream(new Stream(device)) {}
    inline MedctrlDebug(QString *string) : stream(new Stream(string)) {}
    inline MedctrlDebug(MedMsgType type, const char* file, int line) : logFile(LOG_FILE)
    {
        static int iProcessID=0;

        if(0==iProcessID)
        {
            iProcessID= (int)getpid();
//            system("mkdir -p /AM/log");
        }
        int64_t iThreadID=pthread_self();

        static bool m_iFileFlag=true;
        if (m_iFileFlag)
        {
            if (!logFile.open(QIODevice::WriteOnly | QIODevice::Append))
            {
                return;
            }

            mutex.lock();
            if (LOG_SIZE < logFile.size())
            {
                remove("/AM/log/medctrl.log.bak");
                logFile.copy(LOG_FILE_BAK);
                logFile.resize(0);
            }

            stream = new Stream(type, &logFile);            
        }
        else
        {
            stream = new Stream(type);
        }

        QString text = QString("[%1] ").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz"));
        switch(type)
        {
        case DebugMsg:
            text += QString("[Debug:    ]");
            break;

        case WarningMsg:
            text += QString("[Warning:  ]");
            break;

        case CriticalMsg:
            text += QString("[Info:     ]");
            break;

        case FatalMsg:
            text += QString("[Error:    ]");
            break;
        default:
            text += QString("[Sys:      ]");
            break;
        }

        QString strName = QString("%1").arg(file);
        QStringList nameList = strName.split("/");
        strName.clear();

        strName = nameList.last();

        text+=QString::number(iProcessID,10)+":"+QString::number(iThreadID,10);
        text += QString(" [%1] [%2] ").arg(strName, FILE_NAME_LEN).arg(line, FILE_LINE_LEN);

        stream->ts << text;
    }
    inline MedctrlDebug(const MedctrlDebug &o):stream(o.stream) {++stream->ref; }
    inline MedctrlDebug &operator=(const MedctrlDebug &other);
    inline ~MedctrlDebug() {
        if (!--stream->ref) {
            if(stream->message_output) {
                QT_TRY {
                    qt_message_output((QtMsgType)stream->type, stream->buffer.toLocal8Bit().data());
                } QT_CATCH(std::bad_alloc&) { /* We're out of memory - give up. */ }
            }

            mutex.unlock();
            stream->ts << endl;
            if (logFile.isOpen())
            {
                logFile.flush();
                logFile.close();
            }

            delete stream;

        }
    }
    inline MedctrlDebug &space() { stream->space = true; stream->ts << ' '; return *this; }
    inline MedctrlDebug &nospace() { stream->space = false; return *this; }
    inline MedctrlDebug &maybeSpace() { if (stream->space) stream->ts << ' '; return *this; }

    inline MedctrlDebug &operator<<(QChar t) { stream->ts << '\'' << t << '\''; return maybeSpace(); }
    inline MedctrlDebug &operator<<(QBool t) { stream->ts << (bool(t != 0) ? "true" : "false"); return maybeSpace(); }
    inline MedctrlDebug &operator<<(bool t) { stream->ts << (t ? "true" : "false"); return maybeSpace(); }
    inline MedctrlDebug &operator<<(char t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(signed short t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(unsigned short t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(signed int t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(unsigned int t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(signed long t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(unsigned long t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(qint64 t)
        { stream->ts << QString::number(t); return maybeSpace(); }
    inline MedctrlDebug &operator<<(quint64 t)
        { stream->ts << QString::number(t); return maybeSpace(); }
    inline MedctrlDebug &operator<<(float t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(double t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(const char* t) { stream->ts << QString::fromAscii(t); return maybeSpace(); }
    inline MedctrlDebug &operator<<(const QString & t) { stream->ts << '\"' << t  << '\"'; return maybeSpace(); }
    inline MedctrlDebug &operator<<(const QStringRef & t) { return operator<<(t.toString()); }
    inline MedctrlDebug &operator<<(const QLatin1String &t) { stream->ts << '\"'  << t.latin1() << '\"'; return maybeSpace(); }
    inline MedctrlDebug &operator<<(const QByteArray & t) { stream->ts  << '\"' << t << '\"'; return maybeSpace(); }
    inline MedctrlDebug &operator<<(const void * t) { stream->ts << t; return maybeSpace(); }
    inline MedctrlDebug &operator<<(QTextStreamFunction f) {
        stream->ts << f;
        return *this;
    }

    inline MedctrlDebug &operator<<(QTextStreamManipulator m)
    { stream->ts << m; return *this; }
};
#define LOG_DEBUG MedctrlDebug(DebugMsg, __FILE__, __LINE__)
#define LOG_INFO MedctrlDebug(CriticalMsg, __FILE__, __LINE__)
#define LOG_WARNING MedctrlDebug(WarningMsg, __FILE__, __LINE__)
//#define LOG_ERROR MedctrlDebug(FatalMsg, __FILE__, __LINE__)
#define LOG_SYSTEM MedctrlDebug(SystemMsg, __FILE__, __LINE__)

class LOGSERVERSHARED_EXPORT CLogServer
{

public:
    CLogServer();
};

#endif // LOGSERVER_H
