#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QVector>

#include "song.h"

class Playlist : public QObject
{
public:
	Playlist();

	void addItem(Song * item);
	void clear();
	Song * getCurrentItem(int offset=0);
	Song * getNextItem();
	void restart();
	void shuffle();


private:
	QVector<Song *> m_playlist;
	int m_currentitem; // item in the playlist we are currently playing

};

#endif // PLAYLIST_H
