#include "playlistscreen.h"
#include "ui_playlistscreen.h"


PlaylistScreen::PlaylistScreen(Playlist * playlist, QWidget *parent) :
	QWidget(parent),
	m_ui(new Ui::PlaylistScreen),
	m_playlist(playlist)
{
	m_ui->setupUi(this);
	connect(m_playlist, SIGNAL(changed()), this, SLOT(playlistChanged()));
	connect(m_ui->btnClear, SIGNAL(clicked()), m_playlist, SLOT(clear()));
	connect(m_ui->btnShuffle, SIGNAL(clicked()), m_playlist, SLOT(shuffle()));
	connect(m_ui->btnShuffle, SIGNAL(toggled(bool)), m_playlist, SLOT(setRepeat(bool)));
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

	m_playlist->addItem(new Song(6834));
	m_playlist->addItem(new Song(6835));

}

void PlaylistScreen::playlistChanged() {
	QVector<Song *> p = m_playlist->asVector();

	// clear playlist table
	// add all playlist elements to table

	// Future: instead of clearing, work through table looking for differences. maybe only the current item changed

	m_ui->tblSongs->clearContents();
	m_ui->tblSongs->setRowCount(0);
	int row;
	for (row = 0; row < p.count(); ++row) {
		m_ui->tblSongs->setRowCount(row+1);
		QTableWidgetItem * newitem = new QTableWidgetItem(p.at(row)->artist());
		m_ui->tblSongs->setItem(row, 0, newitem);
		newitem = new QTableWidgetItem(p.at(row)->album());
		m_ui->tblSongs->setItem(row, 1, newitem);
		newitem = new QTableWidgetItem(p.at(row)->title());
		m_ui->tblSongs->setItem(row, 2, newitem);
	}
	m_ui->tblSongs->resizeColumnsToContents();

}
