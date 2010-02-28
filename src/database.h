#ifndef DATABASE_H
#define DATABASE_H


#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>


QSqlDatabase db_createConnection(QString driver, QString hostname, QString database, QString user, QString password, QString opts);


#endif // DATABASE_H
