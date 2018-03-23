#ifndef DRAWLABEL_H
#define DRAWLABEL_H
#include <QLabel>

class DrawLabel : public QLabel
{
    Q_OBJECT
public:

    DrawLabel(QWidget * parent);
    void paintEvent(QPaintEvent *);
};

#endif // DRAWLABEL_H
