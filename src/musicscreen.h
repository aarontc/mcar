#ifndef MUSICSCREEN_H
#define MUSICSCREEN_H

#include <QtGui/QWidget>

namespace Ui {
    class MusicScreen;
}

class MusicScreen : public QWidget {
    Q_OBJECT
public:
    MusicScreen(QWidget *parent = 0);
    ~MusicScreen();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MusicScreen *m_ui;
};

#endif // MUSICSCREEN_H
