#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include "playlist.h"

class MusicPlayer : public QObject
{

public:
	MusicPlayer();

	Playlist playlist;

	enum State {
		Initializing,
		Idle,
		Playing,
		Paused,
		Stopped
	};

	void clearPlaylist();
	void shufflePlaylist();
	void play();
	void pause();
	void stop();

	private:
	enum State m_state;

};

#endif // MUSICPLAYER_H
