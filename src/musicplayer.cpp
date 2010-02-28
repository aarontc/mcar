#include "musicplayer.h"

MusicPlayer::MusicPlayer() :
		m_state(Initializing),
		m_state_request(Idle)
{
	//playlist.addItem(new Song(109));
	m_mediaObject = new Phonon::MediaObject(this);
	m_audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
	Phonon::createPath(m_mediaObject, m_audioOutput);

	m_mediaObject->setTickInterval(100);
	connect(m_mediaObject, SIGNAL(tick(qint64)), this, SLOT(mediaObjectTick(qint64)));
	connect(m_mediaObject, SIGNAL(aboutToFinish()), this, SLOT(enqueueNextSource()));

	m_state = MusicPlayer::Idle;
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
				} else if (m_state == Idle || m_state == Stopped) {
					m_state = Playing;
					playlist.restart();
					enqueueNextSource();
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
	if (next != 0)
		m_mediaObject->enqueue(Phonon::MediaSource(next->filePath()));
}

void MusicPlayer::pause() {
	m_state_request = Paused;
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
