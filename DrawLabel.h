#ifndef DRAWLABEL_H
#define DRAWLABEL_H
#include <QLabel>
#include "mybutton.h"

class DrawLabel : public QLabel
{
    Q_OBJECT

    QList<QPoint> paths;

public:

    MyButton ** buttons;
    DrawLabel(QWidget * parent);

    void paintEvent(QPaintEvent *);
    void drawPath(const QList<QPoint> &);
};

#endif // DRAWLABEL_H
