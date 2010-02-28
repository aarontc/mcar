#ifndef LIBRARYSCANNER_H
#define LIBRARYSCANNER_H

#include <QThread>
#include <QString>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


#include <QDebug>
#include <QDirIterator>
#include <QFile>
#include <QFileInfo>
#include <QVariant>
#include <QDateTime>

#include <iostream>
#include <stdio.h>
#include <tag.h>
#include <fileref.h>

class LibraryScanner : public QThread
{
public:
	LibraryScanner(QSqlDatabase & db);
	~LibraryScanner();

protected:
	void run();
	void scan ( const QString & directory = NULL );
	void readtags ( const QString & file );

private:
	QSqlDatabase m_database;
	QSqlQuery m_query;

};

#endif // LIBRARYSCANNER_H
