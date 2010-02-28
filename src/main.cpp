#include <QtGui/QApplication>
#include "screen.h"
#include "settings.h"
#include "database.h"
#include "libraryscanner.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	Settings s;
	QSqlDatabase db(db_createConnection
			( s.getAttributeValue("/database", "type"),
			  s.getStringValue("/database/host"),
			  s.getStringValue("/database/database"),
			  s.getStringValue("/database/user"),
			  s.getStringValue("/database/password"),
			  s.getStringValue("/database/options")
			  ));


	LibraryScanner libscanner(db);
	libscanner.start();

	Screen w;
	//w.showFullScreen();
	w.showNormal();

	return app.exec();
}
