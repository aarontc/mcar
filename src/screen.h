#ifndef SCREEN_H
#define SCREEN_H

#include <QtGui/QWidget>
#include <QDebug>


#include "homescreen.h"
#include "musicscreen.h"


class Screen : public QWidget {
	Q_OBJECT

public:
	Screen(QWidget *parent = 0);
	~Screen();

public slots:
	void selectMode(QString mode);


private:
	HomeScreen * m_homescreen;
	MusicScreen * m_musicscreen;

};

#endif // SCREEN_H
