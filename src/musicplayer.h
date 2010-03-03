#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QThread>
#include <QObject>
#include "playlist.h"
#include "song.h"

// phonon
#include <audiooutput.h>
#include <mediaobject.h>

class MusicPlayer : public QThread {
	Q_OBJECT

public:
	MusicPlayer();
	~MusicPlayer();

	Playlist playlist;

	enum State {
		Initializing,
		Idle,
		Playing,
		Paused,
		Stopped
	};

	enum State getState();

signals:
	void tick(qint64 time);

public slots:
	void clearPlaylist();
	void playNext();
	void pause();
	void playPrevious();
	void play();
	void shufflePlaylist();
	void stop();
	void togglePause();

protected:
	void run();

private:
	enum State m_state;
	enum State m_state_request;
	Phonon::MediaObject * m_mediaObject;
	Phonon::AudioOutput * m_audioOutput;

private slots:
	void mediaObjectTick(qint64 time);
	void enqueueNextSource();

};

#endif // MUSICPLAYER_H
