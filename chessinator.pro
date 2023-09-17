TEMPLATE = app
TARGET = chessinator

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += \
    chessscene.cpp \
    main.cpp \
    window.cpp

HEADERS += \
    chessscene.h \
    constants.h \
    window.h
