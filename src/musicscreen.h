#ifndef MUSICSCREEN_H
#define MUSICSCREEN_H

#include <QtGui/QWidget>
#include "musicplayer.h"
#include "musiclayouta.h"

class MusicScreen : public QWidget {
	Q_OBJECT
public:
	MusicScreen(MusicPlayer * musicplayer, QWidget *parent = 0);
	~MusicScreen();

signals:
	void requestMode(QString mode);

public slots:
	void setMode(QString mode);

protected:

private:

	MusicPlayer * m_musicplayer;
	QWidget * m_musiclayout;
};

#endif // MUSICSCREEN_H
