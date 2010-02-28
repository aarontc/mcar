#ifndef MUSICLAYOUTA_H
#define MUSICLAYOUTA_H

#include <QtGui/QWidget>
#include <QAction>
#include <QTimer>
#include "musicplayer.h"

namespace Ui {
	class MusicLayoutA;
}

class MusicLayoutA : public QWidget {
	Q_OBJECT

public:
	MusicLayoutA(MusicPlayer * musicplayer, QWidget *parent = 0);
	~MusicLayoutA();

protected:
	void changeEvent(QEvent *e);

public slots:
	void tick(qint64);

signals:
	void next();
	void previous();
	void playPause();



private:
	Ui::MusicLayoutA *m_ui;
	MusicPlayer * m_musicplayer;
	void updateUI(qint64 time=-1);
	QAction m_action_play;
	QAction m_action_pause;
	QTimer * m_uitimer;

private slots:
	void uitimer();

private slots:
	void on_btnPrevious_clicked();
	void on_btnPlayPause_clicked();
	void on_btnNext_clicked();
};

#endif // MUSICLAYOUTA_H
