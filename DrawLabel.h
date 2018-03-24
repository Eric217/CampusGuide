#ifndef DRAWLABEL_H
#define DRAWLABEL_H
#include <QLabel>
#include "MyButton.h"

#define ShortestPath QString("最短路径")
#define Selecting QString("取消选择")
#define AllPaths QString("全部路径")
#define MultiPoints QString("多个点生成树")


class DrawLabel : public QLabel
{
    Q_OBJECT

    QList<QList<QPoint>> paths;

public:

    MyButton ** buttons;
    DrawLabel(QWidget * parent);

    void paintEvent(QPaintEvent *);
    void drawPath(const QList<QList<QPoint>> &);
};

#endif // DRAWLABEL_H
