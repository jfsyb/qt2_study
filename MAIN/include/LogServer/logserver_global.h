#ifndef LOGSERVER_GLOBAL_H
#define LOGSERVER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LOGSERVER_LIBRARY)
#  define LOGSERVERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LOGSERVERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGSERVER_GLOBAL_H