#include <QtGui/QApplication>
#include "homescreen.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	homescreen w;
	//w.showFullScreen();
	w.showNormal();

	return a.exec();
}
