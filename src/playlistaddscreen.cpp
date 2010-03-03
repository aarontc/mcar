#include "playlistaddscreen.h"
#include "ui_playlistaddscreen.h"

#include <QDebug>

PlaylistAddScreen::PlaylistAddScreen(QSqlDatabase & db, Playlist * playlist, QString type, QWidget *parent) :
		QWidget(parent),
		m_playlist(playlist),
		m_query(0),
		m_type(type),
		ui(new Ui::PlaylistAddScreen)
{
	ui->setupUi(this);
	ui->lblWidgetTitle->setText("mcar - Playlist - Add " + m_type);

	// get our own instance of database connection
	m_database = QSqlDatabase::cloneDatabase(db, QString("PlaylistAddScreen" + type));
	if (!m_database.open()) {
		qDebug() << QString("Unable to establish a database connection. The last error was:\n"
							"\n" +
							m_database.lastError().text());
		exit(-1);
	} else {
		m_query = new QSqlQuery(m_database);
		m_query->setForwardOnly(true);
		on_txtSearch_textChanged("");
	}

}

PlaylistAddScreen::~PlaylistAddScreen() {
	delete ui;
	delete m_query;
}

void PlaylistAddScreen::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void PlaylistAddScreen::on_btnBack_clicked() {
	emit requestMode(QString("Previous"));

}


void PlaylistAddScreen::vk_pressed(char letter) {
	ui->txtSearch->setText(ui->txtSearch->text().append(letter));
}

void PlaylistAddScreen::on_txtSearch_textChanged(QString text) {
	QString search = "%" + text + "%";

	qDebug() << "Search string:" << search;

	m_query->clear();
	m_query->prepare("SELECT artists.artistid, artists.name AS artist_name, albums.albumid, albums.name AS album_name, songs.songid, songs.title AS song_title FROM songs JOIN artists ON artists.artistid=songs.artistid JOIN albums ON albums.albumid=songs.albumid WHERE LOWER(artists.name) LIKE LOWER(?) OR LOWER(songs.title) LIKE LOWER(?) OR LOWER(albums.name) LIKE LOWER(?) ORDER BY artists.name ASC, albums.name ASC, songs.title ASC");
	m_query->addBindValue(search);
	m_query->addBindValue(search);
	m_query->addBindValue(search);
	//m_query->addBindValue(MaxResults);
	m_query->exec();

	ui->tblResults->clearContents();
	m_query->first();
	m_artistIDs.clear();
	m_albumIDs.clear();
	m_songIDs.clear();
	int row = 0;
	while ( m_query->next() ) {
		m_artistIDs.append(m_query->value(0).toULongLong());
		m_albumIDs.append(m_query->value(2).toULongLong());
		m_songIDs.append(m_query->value(4).toULongLong());

		if (row < 50) {
			ui->tblResults->setRowCount(row+1);
			QTableWidgetItem * newitem = new QTableWidgetItem(m_query->value(1).toString());
			ui->tblResults->setItem(row, 0, newitem);
			newitem = new QTableWidgetItem(m_query->value(3).toString());
			ui->tblResults->setItem(row, 1, newitem);
			newitem = new QTableWidgetItem(m_query->value(5).toString());
			ui->tblResults->setItem(row++, 2, newitem);
		}
	}
	ui->tblResults->setRowCount(row);
	ui->tblResults->resizeColumnsToContents();
}


