TEMPLATE = app
TARGET = chessinator

QT = core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets


SOURCES += \
    action_widget.cpp \
    chesspiece.cpp \
    chessscene.cpp \
    main.cpp \
    pawn.cpp \
    rook.cpp \
    window.cpp

HEADERS += \
    action_widget.h \
    chesspiece.h \
    chessscene.h \
    constants.h \
    pawn.h \
    rook.h \
    window.h

OTHER_FILES *= \
    assets/*
