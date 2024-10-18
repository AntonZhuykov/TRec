QT       += core gui
QT      += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TRecADC.cpp \
    TRecADCChParam.cpp \
    TRecADCChParamWidgets.cpp \
    TRecADCParam.cpp \
    TRecFolderSelector.cpp \
    TRecIPEditBox.cpp \
    TRecMeasLoopParamDlg.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    TRecADC.h \
    TRecADCChParam.h \
    TRecADCChParamWidgets.h \
    TRecADCParam.h \
    TRecFolderSelector.h \
    TRecIPEditBox.h \
    TRecMeasLoopParamDlg.h \
    mainwindow.h

FORMS += \
    TRecMeasLoopParamDlg.ui \
    mainwindow.ui

TRANSLATIONS += \
    TRec_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Res/StartButtonIcon.svg
