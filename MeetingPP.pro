#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T14:42:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MeetingPP
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    detailsviewdialog.cpp \
    mockproject.cpp \
    mockuser.cpp \
    userpreview.cpp \
    userdetailsdialog.cpp \
    mockmeeting.cpp \
    mockmeetingdb.cpp \
    meetingpreview.cpp \
    newmeetingdialog.cpp \
    meetingdetailsview.cpp

HEADERS += \
        mainwindow.h \
    detailsviewdialog.h \
    mockproject.h \
    mockuser.h \
    userpreview.h \
    userdetailsdialog.h \
    mockmeeting.h \
    mockmeetingdb.h \
    meetingpreview.h \
    newmeetingdialog.h \
    meetingdetailsview.h

FORMS += \
        mainwindow.ui \
    detailsviewdialog.ui \
    userpreview.ui \
    userdetailsdialog.ui \
    meetingpreview.ui \
    newmeetingdialog.ui \
    meetingdetailsview.ui

CONFIG += mobility
MOBILITY = 

