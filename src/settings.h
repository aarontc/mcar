#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QDomDocument>
#include <QFile>


class Settings : public QObject
{
public:
	Settings();
	~Settings();

	bool saveXMLFile(QString fileName = "/etc/mcar/settings.xml");
	bool loadXMLFile(QString fileName = "/etc/mcar/settings.xml");
	QString getStringValue(QString value_name);
	QString getAttributeValue(QString value_name, QString attribute_name);

	private:
	QDomDocument * m_domdoc;
};

#endif // SETTINGS_H
