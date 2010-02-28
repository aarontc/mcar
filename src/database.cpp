#include "database.h"


QSqlDatabase db_createConnection(QString driver, QString hostname, QString database, QString user, QString password, QString opts) {

	// Setup database connection
	QSqlDatabase db = QSqlDatabase::addDatabase(driver);
	db.setHostName(hostname);
	db.setDatabaseName(database);
	db.setUserName(user);
	db.setPassword(password);
	db.setConnectOptions(opts);
	if ( ! db.open () ) {
		QMessageBox::critical ( 0, "mcar: Cannot open database",
			QString("Unable to establish a database connection. The last error was:\n"
					 "\n" +
					 db.lastError().text() +
					 "\n\n"
					 "Click Cancel to exit."), QMessageBox::Cancel);
		exit(-1);
	}

	return db;
}

