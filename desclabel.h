#ifndef DESCLABEL_H
#define DESCLABEL_H
#include "qwidget.h"
#include "QMouseEvent"


class DescLabel : public QWidget
{

protected:
    void mouseReleaseEvent(QMouseEvent *);

public:
    DescLabel(QWidget *parent = 0);

};

#endif // DESCLABEL_H
