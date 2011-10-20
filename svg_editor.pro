TEMPLATE = app
TARGET = svgEditor
DEPENDPATH += . src
INCLUDEPATH += . src
QT += svg xml

# Input
HEADERS += src/view.h src/editor.h
SOURCES += src/main.cpp src/view.cpp src/editor.cpp
