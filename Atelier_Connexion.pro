#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT += core gui charts
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer serialport
QT += svg
QT += serialport
QT       += core gui sql serialport
 QT+= sql
QT += printsupport
QT += quick qml multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    DuMesengerConnectionDialog.cpp \
    QrCode.cpp \
    arduino.cpp \
    benevole.cpp \
    donnateur.cpp \
    dons.cpp \
    emailsender.cpp \
    exportexcelobject.cpp \
    login.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    maman.cpp \
    menu.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    video.cpp \
    widget.cpp \

HEADERS += \
    DuMesengerConnectionDialog.h \
    QrCode.h \
    arduino.h \
    benevole.h \
    donnateur.h \
    dons.h \
    emailsender.h \
    exportexcelobject.h \
    login.h \
        mainwindow.h \
    connection.h \
    maman.h \
    menu.h \
    qcustomplot.h \
    smtp.h \
    video.h \
    widget.h \

FORMS += \
        DuMesengerConnectionDialog.ui \
        login.ui \
        mainwindow.ui \
        menu.ui \
    video.ui \
        widget.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    add me to your project so mail works/libeay32.dll \
    add me to your project so mail works/ssleay32.dll \
    icons/control_pause.png \
    icons/control_play.png \
    icons/control_stop.png \
    icons/folder_page_white.png \
    samples/m84_1.mpg \
    samples/rakahProjectHawSikan.mpg \
    samples/videoplayback.avi

RESOURCES += \
    icons.qrc
