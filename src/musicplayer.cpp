#include "musicplayer.h"

MusicPlayer::MusicPlayer()
		: m_state(Initializing)
{
	playlist.addItem(new Song(109));
}
