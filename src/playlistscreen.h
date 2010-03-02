#ifndef PLAYLISTSCREEN_H
#define PLAYLISTSCREEN_H

#include <QtGui/QWidget>

#include "playlist.h"
#include "song.h"

namespace Ui {
	class PlaylistScreen;
}

class PlaylistScreen : public QWidget {
	Q_OBJECT
public:
	PlaylistScreen(Playlist<Song *> * playlist, QWidget *parent = 0);
	~PlaylistScreen();

signals:
	void requestMode(QString mode);

protected:
	void changeEvent(QEvent *e);

private:
	Ui::PlaylistScreen *m_ui;
	Playlist<Song *> * m_playlist;

private slots:
	void on_btnBack_clicked();
};

#endif // PLAYLISTSCREEN_H
