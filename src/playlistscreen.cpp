#include "playlistscreen.h"
#include "ui_playlistscreen.h"


PlaylistScreen::PlaylistScreen(Playlist<Song *> * playlist, QWidget *parent) :
	QWidget(parent),
	m_ui(new Ui::PlaylistScreen),
	m_playlist(playlist)
{
	m_ui->setupUi(this);
}

PlaylistScreen::~PlaylistScreen()
{
	delete m_ui;
}

void PlaylistScreen::changeEvent(QEvent *e)
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

void PlaylistScreen::on_btnBack_clicked() {
	emit requestMode(QString("Previous"));
}
