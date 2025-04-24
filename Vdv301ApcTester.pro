QT += core gui
QT += httpserver
QT += network
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


DEFINES+= QZEROCONF_STATIC
include(VDV301subscriber/QtZeroConf/qtzeroconf.pri)



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    VDV301subscriber/devmgmtpublisherstruct.cpp \
    VDV301subscriber/devmgmtsubscriber.cpp \
    VDV301subscriber/httpserversubscriber.cpp \
    VDV301subscriber/ibisipsubscriber.cpp \
    VDV301subscriber/ibisipsubscribermultiplepublishers.cpp \
    VDV301subscriber/ibisipsubscriberonepublisher.cpp \
    VDV301subscriber/publisherstruct.cpp \
    VDV301subscriber/xmlgeneratorsubscriber.cpp \
    VDV301subscriber/xmlparsersubscriber.cpp \
    VDV301subscriber/pcspublisherstruct.cpp \
    VDV301subscriber/pcssubscriber.cpp \
    VDV301subscriber/vdv301pcsalldata.cpp \
    VDV301subscriber/xmlgeneratorsubscriberpcs.cpp \
    VDV301subscriber/xmlparserpcs.cpp \
    itxptsubscriber.cpp \
    itxptxmlgeneratorsubscriber.cpp \
    main.cpp \
    mainwindow.cpp


HEADERS += \
    VDV301subscriber/devmgmtpublisherstruct.h \
    VDV301subscriber/devmgmtsubscriber.h \
    VDV301subscriber/httpserversubscriber.h \
    VDV301subscriber/ibisipsubscriber.h \
    VDV301subscriber/ibisipsubscribermultiplepublishers.h \
    VDV301subscriber/ibisipsubscriberonepublisher.h \
    VDV301subscriber/publisherstruct.h \
    VDV301subscriber/xmlgeneratorsubscriber.h \
    VDV301subscriber/xmlparsersubscriber.h \
    VDV301subscriber/pcspublisherstruct.h \
    VDV301subscriber/pcssubscriber.h \
    VDV301subscriber/vdv301countingobject.h \
    VDV301subscriber/xmlgeneratorsubscriberpcs.h \
    VDV301subscriber/xmlparserpcs.h \
    itxptsubscriber.h \
    itxptxmlgeneratorsubscriber.h \
    mainwindow.h


FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Vdv301ApcTester_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
