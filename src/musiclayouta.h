#ifndef MUSICLAYOUTA_H
#define MUSICLAYOUTA_H

#include <QtGui/QWidget>

namespace Ui {
    class MusicLayoutA;
}

class MusicLayoutA : public QWidget {
    Q_OBJECT
public:
    MusicLayoutA(QWidget *parent = 0);
    ~MusicLayoutA();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MusicLayoutA *m_ui;
};

#endif // MUSICLAYOUTA_H
