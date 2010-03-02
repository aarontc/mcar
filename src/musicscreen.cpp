#include "musicscreen.h"

MusicScreen::MusicScreen(MusicPlayer * musicplayer, QWidget *parent) :
	QWidget(parent), m_musicplayer(musicplayer)
{

	setMinimumSize(QSize(800,480));
	setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));



	m_musiclayout = new MusicLayoutA(m_musicplayer, this);
	connect(m_musicplayer, SIGNAL(tick(qint64)), m_musiclayout, SLOT(tick(qint64)));
	connect(m_musiclayout, SIGNAL(previous()), m_musicplayer, SLOT(playPrevious()));
	connect(m_musiclayout, SIGNAL(next()), m_musicplayer, SLOT(playNext()));
	connect(m_musiclayout, SIGNAL(playPause()), m_musicplayer, SLOT(togglePause()));
	connect(m_musiclayout, SIGNAL(requestMode(QString)), this, SLOT(setMode(QString)));

	m_musiclayout->move(0,0);
	m_musiclayout->show();
	m_musiclayout->raise();

	m_musicplayer->playlist.addItem(new Song(109));
	m_musicplayer->playlist.addItem(new Song(108));

}

MusicScreen::~MusicScreen()
{

}

void MusicScreen::setMode(QString mode) {
	emit requestMode(mode);
}
