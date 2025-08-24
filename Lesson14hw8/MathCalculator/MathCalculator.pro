QT       -= gui

TARGET = Calculator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += $$PWD/../MathLib

LIBS += -L$$PWD/../MathLib/build/Qt_6_9_1_for_macOS-Debug -lMathLib

