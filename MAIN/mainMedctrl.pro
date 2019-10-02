TEMPLATE = subdirs
contains(DEFINES,arm){
#SUBDIRS  +=\
#LogServer\
medctrl\
#AMServer
}
else{
#SUBDIRS  += \
#LogServer\
#medctrl\
#AMServer
}

CONFIG += ordered

SUBDIRS += \
    medctrl
