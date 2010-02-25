#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QtGui/QWidget>
#include <QTimer>

namespace Ui
{
	class homescreen;
}

class homescreen : public QWidget
{
	Q_OBJECT

public:
	homescreen(QWidget *parent = 0);
	~homescreen();

	private slots:
	void updateClock();

private:
	Ui::homescreen *ui;
	QTimer tmrUpdateClock;

};

#endif // HOMESCREEN_H
