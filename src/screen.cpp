#include "screen.h"

Screen::Screen(QWidget *parent) :
		QWidget(parent), m_hs(0), m_ms(0)
{
	m_hs = new HomeScreen(this);
	connect(m_hs, SIGNAL(selectedMode(QString)), this, SLOT(selectMode(QString)));
	connect(m_hs, SIGNAL(test(int)), this, SLOT(test(int)));

	m_hs->move(10,10);
	m_hs->show();
}

Screen::~Screen() {
	delete m_hs;
	delete m_ms;
}

void Screen::selectMode(QString mode) {
	qDebug() << "Switching to mode:" << mode;

	if (mode == "Music") {

		if ( m_ms == 0 )
			m_ms = new MusicScreen(this);
		m_hs->hide();
		m_ms->move(0, 0);
		m_ms->show();

	} else if (mode == "Settings" ) {

		m_hs->hide();

	}

}

void Screen::test(int value) {
	qDebug() << "test" << value;
}
