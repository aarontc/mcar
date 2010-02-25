#include "musiclayouta.h"
#include "ui_musiclayouta.h"

MusicLayoutA::MusicLayoutA(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::MusicLayoutA)
{
    m_ui->setupUi(this);
}

MusicLayoutA::~MusicLayoutA()
{
    delete m_ui;
}

void MusicLayoutA::changeEvent(QEvent *e)
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
