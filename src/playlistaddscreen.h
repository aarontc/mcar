#ifndef PLAYLISTADDSCREEN_H
#define PLAYLISTADDSCREEN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include "playlist.h"
#include "song.h"

namespace Ui {
	class PlaylistAddScreen;
}

class PlaylistAddScreen : public QWidget {
	Q_OBJECT

public:
	PlaylistAddScreen(QSqlDatabase & db, Playlist * playlist, QString type, QWidget *parent = 0);
	~PlaylistAddScreen();

signals:
	void requestMode(QString mode);

protected:
	void changeEvent(QEvent *e);

private:
	QSqlDatabase m_database;
	Playlist * m_playlist;
	QSqlQuery * m_query;
	QString m_type;
	Ui::PlaylistAddScreen *ui;
	QVector<quint64> m_artistIDs, m_albumIDs, m_songIDs;

private slots:
	void on_txtSearch_textChanged(QString );
	void on_btnBack_clicked();
	void vk_pressed(char);
};

#endif // PLAYLISTADDSCREEN_H
