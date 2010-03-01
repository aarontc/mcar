#ifndef SCREEN_H
#define SCREEN_H

#include <QtGui/QWidget>
#include <QVector>
#include <QDebug>


#include "homescreen.h"
#include "musicscreen.h"
#include "playlistscreen.h"


class Screen : public QWidget {
	Q_OBJECT

public:
	Screen(QWidget *parent = 0);
	~Screen();

public slots:
	void setMode(QString mode);



private:
	HomeScreen * m_homescreen;
	MusicScreen * m_musicscreen;
	PlaylistScreen * m_playlistscreen;

	QVector<QString> m_modehistory;

};

#endif // SCREEN_H
