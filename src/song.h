#ifndef SONG_H
#define SONG_H



#include <QObject>

#include <QString>
#include <QSqlQuery>
#include <QVariant>




class Song : public QObject
{

public:
	Song(quint64 songID);

	QString artist();
	QString album();
	QString title();
	QString filePath();

	quint64 artistID();
	quint64 albumID();
	quint64 songID();
	quint64 fileID();

private:
	QString m_artist;
	QString m_album;
	QString m_title;
	QString m_filePath;

	quint64 m_artistID;
	quint64 m_albumID;
	quint64 m_songID;
	quint64 m_fileID;

};

#endif // SONG_H
