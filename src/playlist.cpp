#include "playlist.h"

Playlist::Playlist()
		: m_currentitem(-1)
{
}

void Playlist::addItem(Song *item)
{
	m_playlist.append(item);
}

void Playlist::clear()
{
	m_playlist.clear();
	m_currentitem = -1;
}

Song * Playlist::getCurrentItem(int offset) {
	if (m_currentitem + offset >= 0) {
		if (m_currentitem + offset > m_playlist.size()) {
			return 0;
		} else {
			return m_playlist.at(m_currentitem + offset);
		}
	} else {
		return 0;
	}
}

// Returns the next song in the playlist and increments our currentitem count
Song * Playlist::getNextItem() {
	if (m_currentitem + 1 > m_playlist.size()) {
		m_currentitem = -1;
		return 0;
	} else {
		return m_playlist.at(++m_currentitem);
	}
}

void Playlist::shuffle() {
	QVector<Song *> templist;
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
