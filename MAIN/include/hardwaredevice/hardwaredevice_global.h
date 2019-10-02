#ifndef HARDWAREDEVICE_GLOBAL_H
#define HARDWAREDEVICE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HARDWAREDEVICE_LIBRARY)
#  define HARDWAREDEVICESHARED_EXPORT Q_DECL_EXPORT
#else
#  define HARDWAREDEVICESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HARDWAREDEVICE_GLOBAL_H
