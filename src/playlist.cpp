#include "playlist.h"

#include <QDebug>

Playlist::Playlist()
		: m_currentitem(-1),
		m_repeat(false)
{
}

void Playlist::addItem(Song *item) {
	qDebug() << "Playlist::addItem: entered";
	QMutexLocker lock(&m_mutex);
	qDebug() << "Playlist::addItem: locked";

	m_playlist.append(item);
	emit changed();
}

void Playlist::clear() {
	qDebug() << "Playlist::clear: entered";
	QMutexLocker lock(&m_mutex);
	qDebug() << "Playlist::clear: locked";

	m_playlist.clear();
	m_currentitem = -1;
	lock.mutex()->unlock();
	emit changed();
}

Song * Playlist::getCurrentItem(int offset) {
	qDebug() << "Playlist::getCurrentItem(" << offset << "): entered";
	Song * result(0);
	//QMutexLocker lock(&m_mutex);
	qDebug() << "Playlist::getCurrentItem(" << offset << "): locked";

	if ((m_currentitem + offset >= 0) && (m_currentitem + offset < m_playlist.size())) {
		result = m_playlist.at(m_currentitem + offset);
	}

	return result;
}

// Returns the next song in the playlist and increments our currentitem count
Song * Playlist::getNextItem() {
	Song * result(0);
	QMutexLocker lock(&m_mutex);

	if (m_currentitem + 1 >= m_playlist.size()) {
		restart();
	} else {
		result = m_playlist.at(++m_currentitem);
		emit changed();
	}

	return result;
}

Song * Playlist::getPreviousItem() {
	Song * result(0);
	QMutexLocker lock(&m_mutex);

	if (m_currentitem - 1 < 0) {
		restart();
	} else {
		result = m_playlist.at(--m_currentitem);
		emit changed();
	}

	return result;
}

void Playlist::restart() {
	QMutexLocker lock(&m_mutex);

	m_currentitem = -1;
	emit changed();
}


void Playlist::shuffle() {
	QVector<Song *> templist;
	QMutexLocker lock(&m_mutex);

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

QVector<Song *> Playlist::asVector() {
	QMutexLocker lock(&m_mutex);

	return m_playlist;
}

void Playlist::setRepeat(bool r) {
	QMutexLocker lock(&m_mutex);

	m_repeat = r;
}
