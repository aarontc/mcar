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
	musicscreen.cpp \
	musicplayer.cpp \
	settings.cpp \
	libraryscanner.cpp \
	database.cpp \
	screen.cpp
HEADERS += homescreen.h \
	musiclayouta.h \
	song.h \
	playlist.h \
	musicscreen.h \
	musicplayer.h \
	settings.h \
	database.h \
	libraryscanner.h \
	screen.h
FORMS += homescreen.ui \
	musiclayouta.ui
RESOURCES += mcar.qrc
INCLUDEPATH += /usr/include/taglib /usr/include/phonon
LIBS += -ltag
