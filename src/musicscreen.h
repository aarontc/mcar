#ifndef MUSICSCREEN_H
#define MUSICSCREEN_H

#include <QtGui/QWidget>
#include "musicplayer.h"
#include "musiclayouta.h"

class MusicScreen : public QWidget {
	Q_OBJECT
public:
	MusicScreen(QWidget *parent = 0);
	~MusicScreen();


protected:

private:

	MusicPlayer * m_musicplayer;
	QWidget * m_musiclayout;
};

#endif // MUSICSCREEN_H
