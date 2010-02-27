#include <QtGui/QApplication>
#include "homescreen.h"
#include "settings.h"
#include "database.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	Settings s;
	db_createConnection
			( s.getAttributeValue("/database", "type"),
			  s.getStringValue("/database/host"),
			  s.getStringValue("/database/database"),
			  s.getStringValue("/database/user"),
			  s.getStringValue("/database/password"),
			  s.getStringValue("/database/options")
			  );

	HomeScreen w;
	w.showFullScreen();
	//w.showNormal();

	return a.exec();
}
