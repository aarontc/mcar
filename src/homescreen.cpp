#include "homescreen.h"
#include "ui_homescreen.h"

homescreen::homescreen(QWidget *parent)
	: QWidget(parent), ui(new Ui::homescreen)
{
	ui->setupUi(this);

	ui->btnMusic->icon().addFile(":/images/Musical_notes.svg");


}

homescreen::~homescreen()
{
	delete ui;
}
