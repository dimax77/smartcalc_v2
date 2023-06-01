QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    view/credit_window.cpp \
    view/graph_window.cpp \
    view/mainwindow.cpp

HEADERS += \
    controller/controller.h \
    model/base_calculator.h \
    model/base_parser.h \
    model/credit_calculator.h \
    model/model.h \
    view/credit_window.h \
    view/graph_window.h \
    view/mainwindow.h

FORMS += \
    view/credit_window.ui \
    view/graph_window.ui \
    view/mainwindow.ui

INCLUDEPATH += /libs/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
