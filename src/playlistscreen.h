#ifndef PLAYLISTSCREEN_H
#define PLAYLISTSCREEN_H

#include <QtGui/QWidget>

namespace Ui {
	class PlaylistScreen;
}

class PlaylistScreen : public QWidget {
	Q_OBJECT
public:
	PlaylistScreen(QWidget *parent = 0);
	~PlaylistScreen();

signals:
	void requestMode(QString mode);

protected:
	void changeEvent(QEvent *e);

private:
	Ui::PlaylistScreen *m_ui;

private slots:
	void on_btnBack_clicked();
};

#endif // PLAYLISTSCREEN_H
