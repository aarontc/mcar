#include "musicscreen.h"

MusicScreen::MusicScreen(QWidget *parent) :
	QWidget(parent)
{

	setMinimumSize(QSize(800,480));
	setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));


	m_musicplayer = new MusicPlayer();
	m_musiclayout = new MusicLayoutA(this);
	m_musiclayout->move(0,0);
	m_musiclayout->show();
	m_musiclayout->raise();
}

MusicScreen::~MusicScreen()
{
	delete m_musicplayer;
}

