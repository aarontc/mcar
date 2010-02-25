#include "homescreen.h"
#include "ui_homescreen.h"

#include <QDateTime>

homescreen::homescreen(QWidget *parent)
	: QWidget(parent), ui(new Ui::homescreen)
{
	ui->setupUi(this);
	ui->lblTime->setText("");
	connect(&tmrUpdateClock, SIGNAL(timeout()), this, SLOT(updateClock()));
	tmrUpdateClock.start(100);

}

homescreen::~homescreen()
{
	delete ui;
}

void homescreen::updateClock(){
	ui->lblTime->setText(QDateTime::currentDateTime().toString("ddd MMM d, yyyy   hh:mm:ss"));
}
