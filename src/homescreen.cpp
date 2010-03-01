#include "homescreen.h"
#include "ui_homescreen.h"

#include "musicscreen.h"

#include <QDateTime>
#include <QDebug>

HomeScreen::HomeScreen(QWidget *parent)
	: QWidget(parent), ui(new Ui::HomeScreen)
{
	ui->setupUi(this);
	ui->lblTime->setText("");
	connect(&tmrUpdateClock, SIGNAL(timeout()), this, SLOT(updateClock()));
	tmrUpdateClock.start(100);

}

HomeScreen::~HomeScreen() {
	delete ui;
}

void HomeScreen::updateClock(){
	ui->lblTime->setText(QDateTime::currentDateTime().toString("ddd MMM d, yyyy   hh:mm:ss"));
}

void HomeScreen::on_btnMusic_clicked() {
	emit requestMode(QString("Music"));
}
