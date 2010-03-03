#include "playlist.h"

#include <QDebug>

Playlist::Playlist()
		: m_currentitem(-1),
		m_repeat(false)
{
}

void Playlist::addItem(Song *item) {
	QMutexLocker lock(&m_mutex);
	m_playlist.append(item);
	lock.mutex()->unlock();
	emit changed();
}

void Playlist::addVector(QVector<Song *> item) {
	QMutexLocker lock(&m_mutex);
	m_playlist += item;
	lock.mutex()->unlock();
	emit changed();
}


void Playlist::clear() {
	QMutexLocker lock(&m_mutex);
	m_playlist.clear();
	m_currentitem = -1;
	lock.mutex()->unlock();
	emit changed();
}

Song * Playlist::getCurrentItem(int offset) {
	QMutexLocker lock(&m_mutex);
	Song * result(0);
	if ((m_currentitem + offset >= 0) && (m_currentitem + offset < m_playlist.size())) {
		result = m_playlist.at(m_currentitem + offset);
	}
	return result;
}

// Returns the next song in the playlist and increments our currentitem count
Song * Playlist::getNextItem() {
	QMutexLocker lock(&m_mutex);
	Song * result(0);

	if (m_currentitem + 1 >= m_playlist.size()) {
		m_currentitem = -1;//restart();
	} else {
		result = m_playlist.at(++m_currentitem);
	}

	return result;
}

Song * Playlist::getPreviousItem() {
	QMutexLocker lock(&m_mutex);
	Song * result(0);

	if (m_currentitem - 1 < 0) {
		m_currentitem = -1;//restart();
	} else {
		result = m_playlist.at(--m_currentitem);
	}

	return result;
}

void Playlist::restart() {
	QMutexLocker lock(&m_mutex);
	m_currentitem = -1;
	lock.mutex()->unlock();
	emit changed();
}


void Playlist::shuffle() {
	QMutexLocker lock(&m_mutex);
	QVector<Song *> templist;

	int x = m_playlist.size();

	while ( x > 0 ) {
		int y = rand() % x;

		templist.append(m_playlist.at(y));
		m_playlist.remove(y);

		x = m_playlist.size();
	}

	m_currentitem = -1;
	m_playlist = templist;
	lock.mutex()->unlock();
	emit changed();

}

QVector<Song *> Playlist::asVector() {
	QVector<Song *> plcopy;
	QMutexLocker lock(&m_mutex);
	plcopy = m_playlist;
	lock.mutex()->unlock();
	return plcopy;
}

void Playlist::setRepeat(bool r) {
	m_repeat = r;
}
