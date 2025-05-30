QT += core gui widgets

TARGET = OnlineStoreProjectQtFull
TEMPLATE = app



SOURCES += main.cpp \
    loginwindow.cpp \
    adminwindow.cpp \
    customerwindow.cpp

HEADERS += \
    loginwindow.h \
    adminwindow.h \
    customerwindow.h
    Product.h

INCLUDEPATH += /opt/homebrew/opt/qt/include
LIBS += -L/opt/homebrew/opt/qt/lib
