# -------------------------------------------------
# Project created by QtCreator 2010-02-24T18:45:02
# -------------------------------------------------
QT += network \
    opengl \
    sql \
    script \
    svg \
    webkit \
    xml \
    xmlpatterns \
    phonon \
    testlib \
    dbus
TARGET = mcar
TEMPLATE = app
SOURCES += main.cpp \
    homescreen.cpp \
    musicscreen.cpp \
    musiclayouta.cpp
HEADERS += homescreen.h \
    musicscreen.h \
    musiclayouta.h
FORMS += homescreen.ui \
    musicscreen.ui \
    musiclayouta.ui
RESOURCES += mcar.qrc
