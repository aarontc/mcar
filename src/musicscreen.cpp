#include "musicscreen.h"
#include "ui_musicscreen.h"

MusicScreen::MusicScreen(QWidget *parent) :
	QWidget(parent),
	m_ui(new Ui::MusicScreen)
{
	m_ui->setupUi(this);
}

MusicScreen::~MusicScreen()
{
	delete m_ui;
}

void MusicScreen::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		m_ui->retranslateUi(this);
		break;
	default:
		break;
	}
}
