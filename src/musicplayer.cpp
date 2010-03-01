#include "musicplayer.h"

MusicPlayer::MusicPlayer() :
		m_state(Initializing),
		m_state_request(Idle)
{
	m_mediaObject = new Phonon::MediaObject(this);
	m_audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
	Phonon::createPath(m_mediaObject, m_audioOutput);

	m_mediaObject->setTickInterval(100);
	connect(m_mediaObject, SIGNAL(tick(qint64)), this, SLOT(mediaObjectTick(qint64)));
	connect(m_mediaObject, SIGNAL(aboutToFinish()), this, SLOT(enqueueNextSource()));


	m_state = MusicPlayer::Idle;
}

MusicPlayer::~MusicPlayer() {
	delete m_audioOutput;
	delete m_mediaObject;
}

void MusicPlayer::run() {
	// wake up once per second and check what we should do
	while (true) {

		// Don't do anything until finished initializing
		if (m_state == Initializing)
			continue;

		// m_state_request == Idle until a real request comes in
		if (m_state_request != m_state) {
			switch (m_state_request) {
			case Playing:
				if (m_state == Paused) {
					m_state = Playing;
					m_mediaObject->play();
				} else if (m_state == Idle) {
					Song * n = playlist.getNextItem();
					if (n) {
						m_state = Playing;
						m_mediaObject->setCurrentSource(Phonon::MediaSource(n->filePath()));
						m_mediaObject->play();
					}
				} else if (m_state == Stopped) {
					enqueueNextSource();
					m_state = Playing;
					m_mediaObject->play();
				}
				break;

			case Paused:
				if (m_state == Playing) {
					m_state = Paused;
					m_mediaObject->pause();
				}
				break;

			case Stopped:
				if (m_state == Playing || m_state == Paused) {
					m_state = Stopped;
					m_mediaObject->stop();
				}
				break;

			default:
				qDebug() << "Invalid state requested from MusicPlayer:" << m_state_request;

			}
		}

		msleep(100);
	}
}

void MusicPlayer::clearPlaylist() {
	playlist.clear();
}

void MusicPlayer::enqueueNextSource() {
	Song * next = playlist.getNextItem();
	if (next) {
		m_mediaObject->enqueue(Phonon::MediaSource(next->filePath()));
	} else {
		m_mediaObject->setQueue(QList<Phonon::MediaSource>());
		m_state_request = Idle;
		m_state = Idle;
	}
}

enum MusicPlayer::State MusicPlayer::getState() {
	return m_state;
}

void MusicPlayer::pause() {
	m_state_request = Paused;
}

void MusicPlayer::togglePause() {
	if (m_state == Playing) {
		pause();
	} else if (m_state == Paused || m_state == Idle || m_state == Stopped) {
		play();
	}
}

void MusicPlayer::playPrevious() {
	Song * previous = playlist.getCurrentItem(-1);
	if (previous) {
		m_mediaObject->setCurrentSource(Phonon::MediaSource(playlist.getPreviousItem()->filePath()));
		m_mediaObject->play();
	}
}

void MusicPlayer::playNext() {
	Song * next = playlist.getCurrentItem(1);
	if (next) {
		m_mediaObject->setCurrentSource(Phonon::MediaSource(playlist.getNextItem()->filePath()));
		m_mediaObject->play();
	}
}

void MusicPlayer::play() {
	m_state_request = Playing;
}

void MusicPlayer::stop() {
	m_state_request = Stopped;
}

void MusicPlayer::shufflePlaylist() {
	playlist.shuffle();
}

void MusicPlayer::mediaObjectTick(qint64 time) {
	emit tick(time);
}
