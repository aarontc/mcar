#include "musiclayouta.h"
#include "ui_musiclayouta.h"

MusicLayoutA::MusicLayoutA(MusicPlayer * musicplayer, QWidget *parent) :
	QWidget(parent),
	m_ui(new Ui::MusicLayoutA),
	m_musicplayer(musicplayer)
{
	m_ui->setupUi(this);
}

MusicLayoutA::~MusicLayoutA() {
	delete m_ui;
}

void MusicLayoutA::changeEvent(QEvent *e)
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

void MusicLayoutA::tick(qint64 time) {
	static Song * n1, * n2, * n3, * n4;

	Song * s = m_musicplayer->playlist.getCurrentItem();
	if (s) {

		m_ui->lblAlbum->setText(s->album());
		m_ui->lblArtist->setText(s->artist());
		m_ui->lblSongTitle->setText(s->title());

	}

	if (m_musicplayer->playlist.getCurrentItem(1) != n1) {
		n1 = m_musicplayer->playlist.getCurrentItem(1);
		n2 = m_musicplayer->playlist.getCurrentItem(2);
		n3 = m_musicplayer->playlist.getCurrentItem(3);
		n4 = m_musicplayer->playlist.getCurrentItem(4);

		if (n1)
			qDebug() << "next song:" << n1->title();
	}
}
