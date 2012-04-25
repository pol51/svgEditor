TEMPLATE = app
TARGET = svgEditor
DEPENDPATH += . src
INCLUDEPATH += . src
QT += svg xml
LIBS += -lqscintilla2

# Input
HEADERS += src/view.h
SOURCES += src/main.cpp src/view.cpp
