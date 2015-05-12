#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T17:38:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = plotting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    quadtree.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    node.h \
    quadtree.h

FORMS    += mainwindow.ui
