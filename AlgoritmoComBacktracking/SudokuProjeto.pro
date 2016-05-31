#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T06:14:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SudokuProjeto
TEMPLATE = app

CONFIG+=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    grafo.cpp \
    tabuleiro.cpp

HEADERS  += mainwindow.h \
    grafo.h \
    tabuleiro.h

FORMS    += mainwindow.ui
