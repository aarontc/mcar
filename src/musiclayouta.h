#ifndef MUSICLAYOUTA_H
#define MUSICLAYOUTA_H

#include <QtGui/QWidget>
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


private:
	Ui::MusicLayoutA *m_ui;
	MusicPlayer * m_musicplayer;
};

#endif // MUSICLAYOUTA_H
