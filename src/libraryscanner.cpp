#include "libraryscanner.h"




// FIXME: store this in settings

const QString LibraryPath ( "/opt/music" );

//using namespace std;

LibraryScanner::LibraryScanner(QSqlDatabase & db) {
	qDebug() << "Instantiated LibraryScanner";


	// get our own instance of database connection
	m_database = QSqlDatabase::cloneDatabase(db, "LibraryScannerDB");
	if (!m_database.open()) {
		qDebug() << QString("Unable to establish a database connection. The last error was:\n"
							"\n" +
							m_database.lastError().text());
		exit(-1);
	} else {
		m_query = QSqlQuery(m_database);
		m_query.setForwardOnly(true);
	}


}

LibraryScanner::~LibraryScanner() {
}

void LibraryScanner::run () {

	qDebug() << "LibraryScanner: running";
	scan ();

}

void LibraryScanner::scan ( const QString & directory ) {
	QString path = directory;
	if ( path == NULL )
		path = LibraryPath;

	qDebug() << "LibraryScanner::scan(path=\"" + path + "\")";

	QDirIterator library ( path, QDirIterator::Subdirectories );

	// FIXME: Handle symlinks recursively
	while ( library.hasNext() ) {
		QString file(library.next());
		qDebug() << file;

		QFileInfo info(file);
		if ( info.isSymLink() ) {
			file = info.symLinkTarget();
			qDebug() << "symlink";
		}
		QFileInfo realinfo(file);
		if ( realinfo.isDir() ) {
			qDebug() << "Directory, ignoring";
		} else {
			qDebug() << "Attempting to process";
			readtags ( file );
		}

	}
}

void LibraryScanner::readtags ( const QString & file ) {
	QFileInfo info(file);

	//	cout << "******************** \"" << file.toLatin1().data() << "\" ********************" << endl;

	TagLib::FileRef f(file.toLatin1().data());

	if(!f.isNull() && f.tag()) {

		TagLib::Tag *tag = f.tag();

		//		cout << "-- TAG --" << endl;
		//		cout << "title   - \"" << tag->title()   << "\"" << endl;
		//		cout << "artist  - \"" << tag->artist()  << "\"" << endl;
		//		cout << "album   - \"" << tag->album()   << "\"" << endl;
		//		cout << "year    - \"" << tag->year()    << "\"" << endl;
		//		cout << "comment - \"" << tag->comment() << "\"" << endl;
		//		cout << "track   - \"" << tag->track()   << "\"" << endl;
		//		cout << "genre   - \"" << tag->genre()   << "\"" << endl;


		// See if the artist exists
		quint64 artistid;
		m_query.prepare ( "SELECT artistid FROM artists WHERE name=?" );
		m_query.addBindValue( tag->artist().toCString(true) );
		if(!m_query.exec()) {
			qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
		}

		if ( m_query.size() > 0 ) {
			m_query.first();
			artistid = m_query.value(0).toULongLong();
		} else {
			m_query.clear();
			m_query.prepare( "INSERT INTO artists (name) VALUES (?)" );
			m_query.addBindValue( tag->artist().toCString(true) );
			if(!m_query.exec()) {
				qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
			}
			m_query.clear();
			if(!m_query.exec("SELECT currval('artists_artistid_seq')")) {
				qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
			}
			m_query.first();
			artistid = m_query.value(0).toULongLong();
		}

		qDebug() << "artistid for \"" << tag->artist().toCString(true) << "\"=" << artistid;




		// See if the album exists
		quint64 albumid;
		m_query.prepare ( "SELECT albumid FROM albums WHERE name=?" );
		m_query.addBindValue( tag->album().toCString(true) );
		if(!m_query.exec()) {
			qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
		}

		if ( m_query.size() > 0 ) {
			m_query.first();
			albumid = m_query.value(0).toULongLong();
		} else {
			m_query.clear();
			m_query.prepare( "INSERT INTO albums (name) VALUES (?)" );
			m_query.addBindValue( tag->album().toCString(true) );
			if(!m_query.exec()) {
				qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
			}
			m_query.clear();
			m_query.exec( "SELECT currval('albums_albumid_seq')" );
			m_query.first();
			artistid = m_query.value(0).toULongLong();
		}

		qDebug() << "albumid for \"" << tag->album().toCString(true) << "\"=" << albumid;




		// Get song ID if it exists
		quint64 songid;
		m_query.clear();
		m_query.prepare( "SELECT songid FROM songs WHERE title=? AND artistid=? AND albumid=?" );
		m_query.addBindValue( tag->title().toCString(true) );
		m_query.addBindValue( artistid );
		m_query.addBindValue(albumid);

		if(!m_query.exec()) {
			qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
		}

		if ( m_query.size() > 0 ) {
			m_query.first();
			songid = m_query.value(0).toULongLong();
		} else {
			m_query.clear();
			m_query.prepare( "INSERT INTO songs (artistid, albumid, title) VALUES (?, ?, ?)" );
			m_query.addBindValue( artistid );
			m_query.addBindValue(albumid);
			m_query.addBindValue( tag->title() .toCString(true) );
			if(!m_query.exec()) {
				qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
			}
			m_query.clear();

			if(!m_query.exec("SELECT currval('songs_songid_seq')")) {
				qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
			}
			m_query.first();
			songid = m_query.value(0).toULongLong();
		}

		// Get file ID if it exists
		m_query.clear();
		m_query.prepare( "SELECT fileid FROM files WHERE songid=? AND path=?" );
		m_query.addBindValue( songid );
		m_query.addBindValue( file );
		if(!m_query.exec()) {
			qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
		}

		if ( m_query.size() > 0 ) {
			qDebug() << "FILE EXISTS IN DB!";
		} else {
			m_query.clear();
			m_query.prepare ( "INSERT INTO files (path, size, ctime, mtime, songid) VALUES (?, ?, ?, ?, ?)" );
			m_query.addBindValue( file );
			m_query.addBindValue( info.size() );
			m_query.addBindValue( info.created() );
			m_query.addBindValue( info.lastModified() );
			m_query.addBindValue( songid );
			if(!m_query.exec()) {
				qDebug() << QString("The query\n\n" + m_query.lastQuery() + "\n\nfailed with error:\n\n" + m_query.lastError().text());
			}
		}

	}

	//	if(!f.isNull() && f.audioProperties()) {
	//
	//		TagLib::AudioProperties *properties = f.audioProperties();
	//
	//		int seconds = properties->length() % 60;
	//		int minutes = (properties->length() - seconds) / 60;
	//
	//		cout << "-- AUDIO --" << endl;
	//		cout << "bitrate     - " << properties->bitrate() << endl;
	//		cout << "sample rate - " << properties->sampleRate() << endl;
	//		cout << "channels    - " << properties->channels() << endl;
	//		cout << "length      - " << minutes << ":" << seconds << endl;
	//	}
}


