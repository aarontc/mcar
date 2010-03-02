#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <QVector>


template <class X>
class Playlist : public QObject {
	Q_OBJECT

public:
	Playlist();

	void addItem(X item);
	void clear();
	X getCurrentItem(int offset=0);
	X getNextItem();
	X getPreviousItem();
	void restart();
	void shuffle();

signals:
	void changed();

private:
	QVector<X> m_playlist;
	int m_currentitem; // item in the playlist we are currently playing

};



template <class T>
Playlist<T>::Playlist()
		: m_currentitem(-1)
{
}

template <class T>
void Playlist<T>::addItem(T item) {
	m_playlist.append(item);
}

template <class T>
void Playlist<T>::clear() {
	m_playlist.clear();
	m_currentitem = -1;
}

template <class T>
T Playlist<T>::getCurrentItem(int offset) {
	if (m_currentitem + offset >= 0) {
		if (m_currentitem + offset >= m_playlist.size()) {
			return 0;
		} else {
			return m_playlist.at(m_currentitem + offset);
		}
	} else {
		return 0;
	}
}

// Returns the next song in the playlist and increments our currentitem count
template <class T>
T Playlist<T>::getNextItem() {
	if (m_currentitem + 1 >= m_playlist.size()) {
		restart();
		return 0;
	} else {
		return m_playlist.at(++m_currentitem);
	}
}

template <class T>
T Playlist<T>::getPreviousItem() {
	if (m_currentitem - 1 < 0) {
		restart();
		return 0;
	} else {
		return m_playlist.at(--m_currentitem);
	}
}

template <class T>
void Playlist<T>::restart() {
	m_currentitem = -1;
}

template <class T>
void Playlist<T>::shuffle() {
	QVector<T> templist;
	int x = m_playlist.size();

	while ( x > 0 ) {
		int y = rand() % x;

		templist.append(m_playlist.at(y));
		m_playlist.remove(y);

		x = m_playlist.size();
	}

	clear();
	m_playlist = templist;
}


#endif // PLAYLIST_H
