#include "screen.h"

Screen::Screen(QWidget *parent) :
		QWidget(parent), m_homescreen(0), m_musicscreen(0)
{
	m_homescreen = new HomeScreen(this);
	connect(m_homescreen, SIGNAL(selectedMode(QString)), this, SLOT(selectMode(QString)));

	m_homescreen->move(0, 0);
	m_homescreen->show();

	QString style("background: #AAAAAA;");

	this->setStyleSheet(style);
}

Screen::~Screen() {
	delete m_homescreen;
	delete m_musicscreen;
}

void Screen::selectMode(QString mode) {
	qDebug() << "Switching to mode:" << mode;


	if (mode == "Home") {

		m_musicscreen->hide();
		m_homescreen->show();

	} else 	if (mode == "Music") {

		if ( m_musicscreen == 0 )
			m_musicscreen = new MusicScreen(this);
		m_homescreen->hide();
		m_musicscreen->move(0, 0);
		m_musicscreen->show();

	} else if (mode == "Settings" ) {

		m_homescreen->hide();

	}

}
