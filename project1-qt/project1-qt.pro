QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminwidget.cpp \
    aloginwidget.cpp \
    buyerwidget.cpp \
    commodity.cpp \
    main.cpp \
    mdfcommowidget.cpp \
    mdfuserwidget.cpp \
    mythread.cpp \
    order.cpp \
    regiwidget.cpp \
    rlscommowidget.cpp \
    sellerwidget.cpp \
    uloginwidget.cpp \
    user.cpp \
    userinfowidget.cpp \
    userwidget.cpp \
    widget.cpp

HEADERS += \
    admin.h \
    adminwidget.h \
    aloginwidget.h \
    buyerwidget.h \
    commodity.h \
    mdfcommowidget.h \
    mdfuserwidget.h \
    mythread.h \
    order.h \
    regiwidget.h \
    rlscommowidget.h \
    sellerwidget.h \
    uloginwidget.h \
    user.h \
    userinfowidget.h \
    userwidget.h \
    widget.h

FORMS += \
    adminwidget.ui \
    aloginwidget.ui \
    buyerwidget.ui \
    mdfcommowidget.ui \
    mdfuserwidget.ui \
    regiwidget.ui \
    rlscommowidget.ui \
    sellerwidget.ui \
    uloginwidget.ui \
    userinfowidget.ui \
    userwidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
