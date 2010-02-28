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
	void test(int value);


private:
	HomeScreen * m_hs;
	MusicScreen * m_ms;

};

#endif // SCREEN_H
