QT += core gui
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit.c \
    deposit.c \
    graph.c \
    input.c \
    main.cpp \
    mainwindow.cpp \
    polish.c \
    polish_to_rez.c \
    qcustomplot.cpp \
    stack.c

HEADERS += \
    credit.h \
    deposit.h \
    input.h \
    mainwindow.h \
    polish.h \
    polish_to_rez.h \
    qcustomplot.h \
    stack.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
