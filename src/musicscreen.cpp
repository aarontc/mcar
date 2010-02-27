#include "musicscreen.h"

MusicScreen::MusicScreen(QWidget *parent) :
	QWidget(parent)
{
	m_musicplayer = new MusicPlayer();
}

MusicScreen::~MusicScreen()
{
	delete m_musicplayer;
}

