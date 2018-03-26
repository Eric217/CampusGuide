#include "DrawLabel.h"
#include <qpainter.h>
//#include <QPoint>



typedef QPoint qp;

DrawLabel::DrawLabel(QWidget *parent):QLabel(parent)
{

}

void DrawLabel::drawPath(const QList<QPoint> & list) {
    paths = list;
    repaint();
}


void DrawLabel::paintEvent(QPaintEvent * e) {
    Q_UNUSED(e);
    if (paths.empty())
        return;

    //init pen property
    QPainter painter(this);
    QPen p = painter.pen();
    p.setWidth(5);
    p.setColor(QColor(97, 198, 250));
    painter.setPen(p);

    //paint paths

    while (!paths.empty()) {

        qp p = paths.front();

        if (p == qp(1, 12) || p == qp(12, 1)) {


        }





        paths.pop_front();

    }


}
