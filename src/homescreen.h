#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QtGui/QWidget>
#include <QTimer>

namespace Ui
{
	class HomeScreen;
}

class HomeScreen : public QWidget {
	Q_OBJECT

public:
	HomeScreen(QWidget *parent = 0);
	~HomeScreen();


signals:
	void selectedMode(QString mode);

private slots:
	void on_btnMusic_clicked();
	void updateClock();


private:
	Ui::HomeScreen *ui;
	QTimer tmrUpdateClock;

};

#endif // HOMESCREEN_H
