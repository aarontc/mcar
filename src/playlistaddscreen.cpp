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

	// setup table correctly based on type
	if (type == "Artist") {
		ui->tblResults->setColumnCount(1);
		ui->tblResults->setHorizontalHeaderLabels(QStringList("Artist"));
	}

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
	QTableWidgetItem * newitem;
	QString search = "%" + text + "%";
	int row = 0;

	qDebug() << "Search string:" << search;

	m_query->clear();

	if (m_type == "Artist") {
		m_query->prepare("SELECT artists.artistid, artists.name FROM artists WHERE LOWER(artists.name) LIKE LOWER(?) ORDER BY artists.name ASC");
		m_query->addBindValue(search);
	} else {
		m_query->prepare("SELECT artists.artistid, artists.name AS artist_name, albums.albumid, albums.name AS album_name, songs.songid, songs.title AS song_title FROM songs JOIN artists ON artists.artistid=songs.artistid JOIN albums ON albums.albumid=songs.albumid WHERE LOWER(artists.name) LIKE LOWER(?) OR LOWER(songs.title) LIKE LOWER(?) OR LOWER(albums.name) LIKE LOWER(?) ORDER BY artists.name ASC, albums.name ASC, songs.title ASC");
		m_query->addBindValue(search);
		m_query->addBindValue(search);
		m_query->addBindValue(search);
		//m_query->addBindValue(MaxResults);
	}
	m_query->exec();

	ui->tblResults->clearContents();
	m_artistIDs.clear();
	m_albumIDs.clear();
	m_songIDs.clear();
	if (m_query->size() > 0) {
		m_query->first();
		do {

			if (row < 50) ui->tblResults->setRowCount(row+1);

			if (m_type == "Artist") {
				m_artistIDs.append(m_query->value(0).toULongLong());
				if (row < 50) {
					newitem = new QTableWidgetItem(m_query->value(1).toString());
					ui->tblResults->setItem(row++, 0, newitem);
				}
			} else {
				m_artistIDs.append(m_query->value(0).toULongLong());
				m_albumIDs.append(m_query->value(2).toULongLong());
				m_songIDs.append(m_query->value(4).toULongLong());
				if (row < 50) {
					newitem = new QTableWidgetItem(m_query->value(1).toString());
					ui->tblResults->setItem(row, 0, newitem);
					newitem = new QTableWidgetItem(m_query->value(3).toString());
					ui->tblResults->setItem(row, 1, newitem);
					newitem = new QTableWidgetItem(m_query->value(5).toString());
					ui->tblResults->setItem(row++, 2, newitem);
				}
			}


		} while (m_query->next());
	}
	ui->tblResults->setRowCount(row);
	ui->tblResults->resizeColumnsToContents();
}



void PlaylistAddScreen::on_btnAddAll_clicked() {
	QVector<Song *> temp;
	if (m_type == "Artist") {

		while (m_artistIDs.count() > 0) {
			m_query->clear();
			m_query->prepare("SELECT songs.songid FROM songs JOIN artists ON songs.artistid=artists.artistid WHERE artists.artistid=? ORDER BY songs.albumid ASC, songs.title ASC");
			m_query->addBindValue(QVariant(m_artistIDs.front()));
			if (m_query->exec()) {
				if (m_query->size()>0) {
					m_query->first();
					do {
						temp.append(new Song(m_query->value(0).toULongLong()));
					} while (m_query->next());
				}
			}
			m_artistIDs.pop_front();
		}
		m_playlist->addVector(temp);


	}

	else {

		//		qDebug() << "accept happened";
		//		switch (m_curCol) {
		//			case 0: // artist
		//				qDebug() << "Selected artist ID" << m_artistIDs[m_curRow];
		//				emit selected_artistid(m_artistIDs[m_curRow]);
		//				break;
		//			case 1: // album
		//				qDebug() << "Selected album ID" << m_albumIDs[m_curRow];
		//				emit selected_albumid(m_albumIDs[m_curRow]);
		//				break;
		//			case 2: // song
		//				qDebug() << "Selected song ID" << m_songIDs[m_curRow];
		//				emit selected_songid(m_songIDs[m_curRow]);
		//				break;
		//			}
		//
	}

	emit requestMode("Previous");
}
