#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QtGui/QWidget>
#include <QtGui/QImage>

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

private:
	Ui::homescreen *ui;
	QImage imgMusic;
	QImage imgSettings;

};

#endif // HOMESCREEN_H
