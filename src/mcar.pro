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
    musiclayouta.cpp \
    song.cpp \
    playlist.cpp \
    musicscreen.cpp
HEADERS += homescreen.h \
    musiclayouta.h \
    song.h \
    playlist.h \
    musicscreen.h
FORMS += homescreen.ui \
    musiclayouta.ui \
    musicscreen.ui
RESOURCES += mcar.qrc
