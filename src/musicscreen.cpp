#include "musicscreen.h"

MusicScreen::MusicScreen(QWidget *parent) :
	QWidget(parent)
{

	setMinimumSize(QSize(800,480));
	setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));


	m_musicplayer = new MusicPlayer();
	m_musicplayer->start();

	m_musicplayer->playlist.addItem(new Song(109));
	m_musicplayer->play();
	m_musicplayer->playlist.addItem(new Song(67));

	m_musiclayout = new MusicLayoutA(m_musicplayer, this);
	connect(m_musicplayer, SIGNAL(tick(qint64)), m_musiclayout, SLOT(tick(qint64)));
	m_musiclayout->move(0,0);
	m_musiclayout->show();
	m_musiclayout->raise();
}

MusicScreen::~MusicScreen()
{
	delete m_musicplayer;
}

