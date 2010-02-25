#ifndef MUSICSCREEN_H
#define MUSICSCREEN_H

#include <QtGui/QWidget>

namespace Ui {
    class musicscreen;
}

class musicscreen : public QWidget {
    Q_OBJECT
public:
    musicscreen(QWidget *parent = 0);
    ~musicscreen();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::musicscreen *m_ui;
};

#endif // MUSICSCREEN_H
