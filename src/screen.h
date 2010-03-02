#ifndef SCREEN_H
#define SCREEN_H

#include <QtGui/QWidget>
#include <QVector>
#include <QDebug>

#include "musicplayer.h"
#include "settings.h"

#include "homescreen.h"
#include "musicscreen.h"
#include "playlistscreen.h"


class Screen : public QWidget {
	Q_OBJECT

public:
	Screen(Settings * s, MusicPlayer * m, QWidget *parent = 0);
	~Screen();

public slots:
	void setMode(QString mode);



private:
	Settings * m_settings;
	MusicPlayer * m_musicplayer;

	HomeScreen * m_homescreen;
	MusicScreen * m_musicscreen;
	PlaylistScreen * m_playlistscreen;

	QVector<QString> m_modehistory;

};

#endif // SCREEN_H
