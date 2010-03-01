#include "screen.h"

Screen::Screen(QWidget *parent) :
		QWidget(parent), m_homescreen(0), m_musicscreen(0), m_playlistscreen(0)
{
	m_homescreen = new HomeScreen(this);
	connect(m_homescreen, SIGNAL(requestMode(QString)), this, SLOT(setMode(QString)));

	m_homescreen->move(0, 0);
	m_homescreen->show();

	QString style("background: #AAAAAA;");

	this->setStyleSheet(style);
}

Screen::~Screen() {
	delete m_homescreen;
	delete m_musicscreen;
	delete m_playlistscreen;
}

// note: special screen mode "Previous" will return to previous screen
void Screen::setMode(QString modereq) {
	QString mode;
	qDebug() << "Mode requested:" << modereq;


	if (modereq == "Previous") {
		if (m_modehistory.count() > 1) {
			m_modehistory.pop_front();
			mode = m_modehistory.first();
		} else {
			mode = "Home";
		}
	} else {
		mode = modereq;
		m_modehistory.push_front(mode);
	}

	// prevent history from growing unbounded
	while (m_modehistory.count() > 1000)
		m_modehistory.pop_back();


	qDebug() << "Switching to mode:" << mode;
	if (mode == "Home") {

		m_musicscreen->hide();
		m_homescreen->show();

	} else 	if (mode == "Music") {

		if ( m_musicscreen == 0 ) {
			m_musicscreen = new MusicScreen(this);
			connect(m_musicscreen, SIGNAL(requestMode(QString)), this, SLOT(setMode(QString)));
			m_musicscreen->move(0, 0);
		}
		if (m_homescreen) m_homescreen->hide();
		if (m_playlistscreen) m_playlistscreen->hide();
		m_musicscreen->show();

	} else if (mode == "Playlist") {

		if (m_playlistscreen == 0) {
			m_playlistscreen = new PlaylistScreen(this);
			connect(m_playlistscreen, SIGNAL(requestMode(QString)), this, SLOT(setMode(QString)));
			m_playlistscreen->move(0, 0);
		}

		if (m_homescreen) m_homescreen->hide();
		if (m_musicscreen) m_musicscreen->hide();
		m_playlistscreen->show();

	} else if (mode == "Settings" ) {

		m_homescreen->hide();

	}

}