#include "settings.h"

#include <QMessageBox>
#include <QXmlQuery>
#include <QDebug>

Settings::Settings() {
	m_domdoc = new QDomDocument("mcar");
	loadXMLFile();
}

Settings::~Settings() {
	saveXMLFile();
	delete m_domdoc;
}

bool Settings::saveXMLFile(QString fileName) {

	QDomDocument doc("mcar");
	QDomElement root = doc.createElement("settings");
	doc.appendChild(root);

	QDomElement database = doc.createElement("database");
	database.setAttribute("type", "PSQL");

	QDomElement user = doc.createElement("user");
	QDomNode username = doc.createTextNode("shadow");
	user.appendChild(username);

	database.appendChild(user);
	root.appendChild(database);

	return true;
	/*
	QFile file(fileName);
	if( !file.open( QIODevice::WriteOnly ) )
		return false;

	file.write(doc.toByteArray(4));
	file.close()*/;

}

bool Settings::loadXMLFile(QString fileName) {
	return true;
}

QString Settings::getStringValue(QString value) {
	QXmlQuery query;
	query.setQuery("for $x in doc('file:/etc/mcar/settings.xml')/settings" + value + "\nreturn data($x)");

	QString r;
	query.evaluateTo(&r);

	qDebug() << "Request for value" << value << "resulted: " << r.trimmed();

	return r.trimmed();
}

QString Settings::getAttributeValue(QString value_name, QString attribute_name) {
	QXmlQuery query;
	query.setQuery("for $x in doc('file:/etc/mcar/settings.xml')/settings" + value_name + "\nreturn data($x/@" + attribute_name + ")");

	QString r;
	query.evaluateTo(&r);

	qDebug() << "Request for attribute" << attribute_name << "from value" << value_name << "resulted: " << r.trimmed();

	return r.trimmed();
}


QString Settings::getStyleSheet(QString filename) {
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly)) {
		qDebug() << "Could not open stylesheet";
	} else {
		QTextStream s(&file);
		return s.readAll();
	}
	return QString("");
}
