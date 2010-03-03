#ifndef SCREEN_H
#define SCREEN_H

#include <QtGui/QWidget>
#include <QVector>
#include <QDebug>
#include <QSqlDatabase>

#include "musicplayer.h"
#include "settings.h"

#include "homescreen.h"
#include "musicscreen.h"
#include "playlistscreen.h"
#include "playlistaddscreen.h"

class Screen : public QWidget {
	Q_OBJECT

public:
	Screen(QSqlDatabase & db, Settings * s, MusicPlayer * m, QWidget *parent = 0);
	~Screen();

public slots:
	void setMode(QString mode);



private:
	QSqlDatabase m_database;
	Settings * m_settings;
	MusicPlayer * m_musicplayer;

	HomeScreen * m_homescreen;
	MusicScreen * m_musicscreen;
	PlaylistScreen * m_playlistscreen;

	PlaylistAddScreen * m_playlistaddscreen_artist;
	PlaylistAddScreen * m_playlistaddscreen_album;
	PlaylistAddScreen * m_playlistaddscreen_other;

	QVector<QString> m_modehistory;

};

#endif // SCREEN_H
