#ifndef MUSICSCREEN_H
#define MUSICSCREEN_H

#include <QtGui/QWidget>
#include "musicplayer.h"

class MusicScreen : public QWidget {
	Q_OBJECT
public:
	MusicScreen(QWidget *parent = 0);
	~MusicScreen();

protected:

private:

	MusicPlayer * m_musicplayer;
};

#endif // MUSICSCREEN_H
