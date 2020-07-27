QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = magic-tower

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
    app/app.cpp \
    app/gamepart.cpp \
    model/database.cpp \
    view/magicmap.cpp \
    common/gamemap.cpp \
    model/gamemodel.cpp \
    main.cpp \
    view/magicmenu.cpp \
    view/mainwindow.cpp \
    common/player.cpp \
    viewModel/gameviewmodel.cpp

HEADERS += \
    app/app.h \
    app/gamepart.h \
    common/common.h \
    model/database.h \
    common/item.h \
    view/magicmap.h \
    common/gamemap.h \
    model/gamemodel.h \
    view/magicmenu.h \
    view/mainwindow.h \
    common/player.h \
    viewModel/gameviewmodel.h

FORMS += \
    view/magicmap.ui \
    view/magicmenu.ui \
    view/mainwindow.ui

TRANSLATIONS += \
    magic-tower_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    magic-tower.qrc

QMAKE_INCDIR += view

DESTDIR = $$absolute_path($${_PRO_FILE_PWD_}/bin/)
