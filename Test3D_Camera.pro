TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lGL -lGLU -lglut -lopenal -lalut -lX11

SOURCES += main.cpp \
    loadtexturetga.cpp \
    camera.cpp \
    vector3d.cpp \
    point2d.cpp

HEADERS += \
    loadtexturetga.h \
    camera.h \
    vector3d.h \
    point2d.h \
    defines.h

