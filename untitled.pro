QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    registerwindow.cpp \
    tablewindow.cpp

HEADERS += \
    card.h \
    mainwindow.h \
    menuwindow.h \
    registerwindow.h \
    tablewindow.h

FORMS += \
    mainwindow.ui \
    menuwindow.ui \
    registerwindow.ui \
    tablewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    photo/photo.png
