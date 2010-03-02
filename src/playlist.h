#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QVector>

#include "song.h"

class Playlist : public QObject {
	Q_OBJECT

public:
	Playlist();

	void addItem(Song * item);
	QVector<Song *> asVector();
	Song * getCurrentItem(int offset=0);
	Song * getNextItem();
	Song * getPreviousItem();

signals:
	void changed();

public slots:
	void clear();
	void restart();
	void shuffle();
	void setRepeat(bool repeat);

private:
	int m_currentitem; // item in the playlist we are currently playing
	QVector<Song *> m_playlist;
	bool m_repeat;

};

#endif // PLAYLIST_H
