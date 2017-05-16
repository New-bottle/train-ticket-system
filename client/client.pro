#-------------------------------------------------
#
# Project created by QtCreator 2017-05-16T01:38:17
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=\
    UI/adminadd.cpp \
    UI/admindelete.cpp \
    UI/adminlogin.cpp \
    UI/adminmainwindow.cpp \
    UI/adminregister.cpp \
    UI/adminsearch.cpp \
    UI/beginwindow.cpp \
    UI/chooseseat.cpp \
    UI/main.cpp \
    UI/mainwindow.cpp \
    UI/search.cpp \
    UI/userbuy.cpp \
    UI/userhistory.cpp \
    UI/userlogin.cpp \
    UI/usermainwindow.cpp \
    UI/userregister.cpp \
    UI/userreturn.cpp \
    UI/userticket.cpp \
    query.cpp \
    UI/adminaddtrain.cpp \
    UI/admincheckuser.cpp \
    UI/adminstartend.cpp \
    UI/searchbyline.cpp \
    UI/userchangepwd.cpp

HEADERS  += \
    UI/adminadd.h \
    UI/admindelete.h \
    UI/adminlogin.h \
    UI/adminmainwindow.h \
    UI/adminregister.h \
    UI/adminsearch.h \
    UI/beginwindow.h \
    UI/chooseseat.h \
    UI/mainwindow.h \
    UI/search.h \
    UI/userbuy.h \
    UI/userhistory.h \
    UI/userlogin.h \
    UI/usermainwindow.h \
    UI/userregister.h \
    UI/userreturn.h \
    UI/userticket.h \
    query.h \
    UI/adminaddtrain.h \
    UI/admincheckuser.h \
    UI/adminstartend.h \
    UI/searchbyline.h \
    UI/userchangepwd.h

FORMS    += mainwindow.ui \
    UI/adminadd.ui \
    UI/admindelete.ui \
    UI/adminlogin.ui \
    UI/adminmainwindow.ui \
    UI/adminregister.ui \
    UI/adminsearch.ui \
    UI/beginwindow.ui \
    UI/chooseseat.ui \
    UI/mainwindow.ui \
    UI/old.ui \
    UI/search.ui \
    UI/userbuy.ui \
    UI/userhistory.ui \
    UI/userlogin.ui \
    UI/usermainwindow.ui \
    UI/userregister.ui \
    UI/userreturn.ui \
    UI/userticket.ui \
    UI/adminaddtrain.ui \
    UI/admincheckuser.ui \
    UI/adminstartend.ui \
    UI/searchbyline.ui \
    UI/userchangepwd.ui

SUBDIRS += \
    UI/ticket3.pro \
    UI/ticket3.pro
