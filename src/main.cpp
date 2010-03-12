#include <QtGui/QApplication>
#include "screen.h"
#include "settings.h"
#include "database.h"
#include "libraryscanner.h"
#include "musicplayer.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	app.setApplicationName("mcar");
	app.setApplicationVersion("0.01");


	Settings s;
	QSqlDatabase db(db_createConnection
			( s.getAttributeValue("/database", "type"),
			  s.getStringValue("/database/host"),
			  s.getStringValue("/database/database"),
			  s.getStringValue("/database/user"),
			  s.getStringValue("/database/password"),
			  s.getStringValue("/database/options")
			  ));

	app.setStyleSheet(s.getStyleSheet());

	LibraryScanner libscanner(db);
	libscanner.start();

	MusicPlayer mp;
	mp.start();

	Screen w(db, &s, &mp);
	w.showNormal();

	return app.exec();
}
