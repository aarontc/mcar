#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QVector>

#include "song.h"

class Playlist : public QObject
{
public:
	Playlist();

	void equeueSong();
	void getSong();
	void shuffle();
	void clear();






private:
	QVector<Song *> m_playlist;
	int m_currentsong; // item in the playlist we are currently playing

};

#endif // PLAYLIST_H
