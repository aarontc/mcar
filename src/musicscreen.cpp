#include "musicscreen.h"
#include "ui_musicscreen.h"

musicscreen::musicscreen(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::musicscreen)
{
    m_ui->setupUi(this);
}

musicscreen::~musicscreen()
{
    delete m_ui;
}

void musicscreen::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
