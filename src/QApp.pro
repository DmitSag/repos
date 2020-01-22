#-------------------------------------------------
#
# Project created by QtCreator 2019-11-14T11:51:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QApp
TEMPLATE = app

QMAKE_CXXFLAGS += -Werror

SOURCES += main.cpp\
        mainwindow.cpp \
    widget.cpp

HEADERS  += mainwindow.h \
    widget.h

FORMS    +=

RESOURCES += \
    res.qrc
