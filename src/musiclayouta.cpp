#include "musiclayouta.h"
#include "ui_musiclayouta.h"

#include <QTime>

#include "musicplayer.h"

MusicLayoutA::MusicLayoutA(MusicPlayer * musicplayer, QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::MusicLayoutA),
		m_musicplayer(musicplayer),
		m_action_play(QIcon(":/images/button_play.png"), QString("Play"), this),
		m_action_pause(QIcon(":/images/button_pause.png"), QString("Pause"), this),
		m_uitimer(new QTimer(this))
{
	m_ui->setupUi(this);
	connect(m_uitimer, SIGNAL(timeout()), this, SLOT(uitimer()));
	m_uitimer->start(100);
}

MusicLayoutA::~MusicLayoutA() {
	delete m_uitimer;
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

void MusicLayoutA::updateUI(qint64 time) {
	static Song * n1, * n2, * n3;
	static enum MusicPlayer::State state;
	Song * s = m_musicplayer->playlist.getCurrentItem();

	QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);


	//if (m_musicplayer->getState() != state) {
	state = m_musicplayer->getState();
	switch(state) {
	case MusicPlayer::Initializing:
		m_ui->lblAlbum->setText("");
		m_ui->lblAlbumArt->setPixmap(QPixmap(QString(":/images/resources/images/CD_icon.svg")));
		m_ui->lblArtist->setText("");
		m_ui->lblBitrate->setText("Bitrate:");
		m_ui->lblFormat->setText("Format:");
		m_ui->lblSongTitle->setText("<Initializing>");
		m_ui->lcdTime->display("-:--");

		m_ui->btnPlayPause->setDefaultAction(&m_action_play);
		break;
	case MusicPlayer::Paused:
		m_ui->lblAlbum->setText((s ? s->album() : ""));
		m_ui->lblAlbumArt->setPixmap(QPixmap(QString(":/images/resources/images/CD_icon.svg")));
		m_ui->lblArtist->setText((s ? s->artist() : ""));
		m_ui->lblBitrate->setText("Bitrate:");
		m_ui->lblFormat->setText("Format:");
		m_ui->lblSongTitle->setText((s ? s->title() : "<No song>"));
		if (time>0)
			m_ui->lcdTime->display(displayTime.toString("m:ss"));

		m_ui->btnPlayPause->setDefaultAction(&m_action_play);
		break;
	case MusicPlayer::Playing:
		m_ui->lblAlbum->setText((s ? s->album() : ""));
		m_ui->lblAlbumArt->setPixmap(QPixmap(QString(":/images/resources/images/CD_icon.svg")));
		m_ui->lblArtist->setText((s ? s->artist() : ""));
		m_ui->lblBitrate->setText("Bitrate:");
		m_ui->lblFormat->setText("Format:");
		m_ui->lblSongTitle->setText((s ? s->title() : "<No song>"));
		if (time>0)
			m_ui->lcdTime->display(displayTime.toString("m:ss"));



		m_ui->btnPlayPause->setDefaultAction(&m_action_pause);
		break;
	case MusicPlayer::Idle:
		m_ui->lblAlbum->setText("");
		m_ui->lblAlbumArt->setPixmap(QPixmap(QString(":/images/resources/images/CD_icon.svg")));
		m_ui->lblArtist->setText("");
		m_ui->lblBitrate->setText("Bitrate:");
		m_ui->lblFormat->setText("Format:");
		m_ui->lblSongTitle->setText("<Idle>");
		m_ui->lcdTime->display("-:--");

		m_ui->btnPlayPause->setDefaultAction(&m_action_play);
		break;
	case MusicPlayer::Stopped:
		m_ui->lblAlbum->setText("");
		m_ui->lblAlbumArt->setPixmap(QPixmap(QString(":/images/resources/images/CD_icon.svg")));
		m_ui->lblArtist->setText("");
		m_ui->lblBitrate->setText("Bitrate:");
		m_ui->lblFormat->setText("Format:");
		m_ui->lblSongTitle->setText("<Stopped>");
		m_ui->lcdTime->display("-:--");

		m_ui->btnPlayPause->setDefaultAction(&m_action_play);
		break;

		//}
	}


	n1 = m_musicplayer->playlist.getCurrentItem(1);
	n2 = m_musicplayer->playlist.getCurrentItem(2);
	n3 = m_musicplayer->playlist.getCurrentItem(3);

	if (n1)
		m_ui->lblUpcoming0->setText(QString(n1->artist() + " - " + n1->title()));
	else
		m_ui->lblUpcoming0->setText("");

	if (n2)
		m_ui->lblUpcoming1->setText(QString(n2->artist() + " - " + n2->title()));
	else
		m_ui->lblUpcoming1->setText("");


	if (n3)
		m_ui->lblUpcoming2->setText(QString(n3->artist() + " - " + n3->title()));
	else
		m_ui->lblUpcoming2->setText("");


}

void MusicLayoutA::tick(qint64 time) {
	updateUI(time);
}

void MusicLayoutA::uitimer() {
	updateUI();
}

void MusicLayoutA::on_btnNext_clicked() {
	emit next();
}

void MusicLayoutA::on_btnPlayPause_clicked() {
	emit playPause();
}

void MusicLayoutA::on_btnPrevious_clicked() {
	emit previous();
}

void MusicLayoutA::on_btnBack_clicked() {
	emit requestMode(QString("Previous"));
}

void MusicLayoutA::on_btnPlaylist_clicked() {
	emit requestMode(QString("Playlist"));
}
