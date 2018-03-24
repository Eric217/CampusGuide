#include "DrawLabel.h"
#include <qpainter.h>

#define p1 QPoint(245, 120)
#define p2 QPoint(270, 158)
#define p3 QPoint(289, 191)
#define p4 QPoint(350, 110)
#define p5 QPoint(345, 280)
#define p6 QPoint(357, 460)
#define p7 QPoint(522, 307)
#define p8 QPoint(512, 251)
#define p9 QPoint(660, 310)
#define p10 QPoint(639, 228)

#define rd QPoint(20, 20)
#define px QPoint(20, 0)
#define py QPoint(0, 20)

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
               painter.drawLine(buttons[1]->pos()+rd, p2);
               painter.drawLine(p2, p4);
               painter.drawLine(p4, buttons[12]->pos());
           } else if (p == qp(1, 21) || p == qp(21, 1)) {
               painter.drawLine(buttons[1]->pos()+rd, p1);
               painter.drawLine(buttons[21]->pos()+rd, p1);
           } else if (p == qp(1, 20) || p == qp(20, 1)) {
               painter.drawLine(buttons[1]->pos()+rd, p3);
               painter.drawLine(buttons[20]->pos()+px, p3);
           } else if (p == qp(1, 3) || p == qp(3, 1)) {
               painter.drawLine(buttons[1]->pos()+rd, p3);
               painter.drawLine(buttons[3]->pos()+py, p3);
           } else if (p == qp(1, 22) || p == qp(22, 1)) {
               painter.drawLine(buttons[1]->pos()+rd, buttons[22]->pos()+py);
           } else if (p == qp(22, 21) || p == qp(21, 22)) {
               painter.drawLine(buttons[21]->pos()+rd, p1);
               painter.drawLine(buttons[22]->pos()+py, p1);
           } else if (p == qp(17, 21) || p == qp(21, 17)) {
               painter.drawLine(buttons[21]->pos()+rd, buttons[17]->pos());
           } else if (p == qp(12, 21) || p == qp(21, 12)) {
               painter.drawLine(buttons[21]->pos()+rd, p1);
               painter.drawLine(p2, p1);
               painter.drawLine(p2, p4);
               painter.drawLine(buttons[12]->pos(), p4);
           } else if (p == qp(20, 21) || p == qp(21, 20)) {
               painter.drawLine(p3, p1);
               painter.drawLine(buttons[21]->pos()+rd, p1);
               painter.drawLine(p3, buttons[20]->pos()+px);
           } else if (p == qp(3, 21) || p == qp(21, 3)) {
               painter.drawLine(p3, p1);
               painter.drawLine(buttons[21]->pos()+rd, p1);
               painter.drawLine(p3, buttons[3]->pos()+py);
           } else if (p == qp(10, 17) || p == qp(17, 10)) {
               painter.drawLine(buttons[17]->pos(), buttons[10]->pos()+px);
           } else if (p == qp(10, 20) || p == qp(20, 10)) {
               painter.drawLine(buttons[20]->pos()+py, buttons[10]->pos()+px);

           } else if (p == qp(9, 10) || p == qp(10, 9)) {
               painter.drawLine(buttons[9]->pos()+px, buttons[10]->pos()+px);

           } else if (p == qp(20, 22) || p == qp(22, 20)) {
               painter.drawLine(buttons[20]->pos()+px, p3);
               painter.drawLine(buttons[22]->pos()+py, p3);
           } else if (p == qp(3, 20) || p == qp(20, 3)) {
               painter.drawLine(buttons[20]->pos()+px, p3);
               painter.drawLine(buttons[3]->pos()+py, p3);
           } else if (p == qp(12, 20) || p == qp(20, 12)) {
               painter.drawLine(buttons[20]->pos()+px, p3);
               painter.drawLine(p2, p3);
               painter.drawLine(p2, p4);
               painter.drawLine(p4, buttons[12]->pos());
           } else if (p == qp(9, 22) || p == qp(22, 9)) {
               painter.drawLine(p5, buttons[22]->pos()+py);
               painter.drawLine(p5, buttons[9]->pos()+px);
           } else if (p == qp(19, 22) || p == qp(22, 19)) {
               painter.drawLine(buttons[19]->pos()+px, buttons[22]->pos()+py);

           } else if (p == qp(7, 22) || p == qp(22, 7)) {
                painter.drawLine(p5, buttons[22]->pos()+py);
                 painter.drawLine(p5, buttons[7]->pos());
           } else if (p == qp(3, 22) || p == qp(22, 3)) {
               painter.drawLine(buttons[22]->pos()+py, p3);
               painter.drawLine(buttons[3]->pos()+py, p3);
           } else if (p == qp(12, 22) || p == qp(22, 12)) {

                painter.drawLine(buttons[22]->pos()+py, p2);
                painter.drawLine(p2, p4);
                painter.drawLine(p4, buttons[12]->pos());
           } else if (p == qp(9, 8) || p == qp(8, 9)) {
               painter.drawLine(buttons[9]->pos()+px, p6);
               painter.drawLine(buttons[8]->pos()+rd, p6);

           } else if (p == qp(9, 7) || p == qp(7, 9)) {
               painter.drawLine(buttons[9]->pos()+px, p5);
               painter.drawLine(p5, buttons[7]->pos());
           } else if (p == qp(9, 19) || p == qp(19, 9)) {
               painter.drawLine(buttons[9]->pos()+px, p5);
               painter.drawLine(buttons[19]->pos()+px, p5);
           } else if (p == qp(19, 8) || p == qp(8, 19)) {
               painter.drawLine(buttons[19]->pos()+px, buttons[8]->pos()+rd);
           } else if (p == qp(13, 8) || p == qp(8, 13)) {
               painter.drawLine(buttons[13]->pos()+py, buttons[8]->pos()+rd);
           } else if (p == qp(19, 7) || p == qp(7, 19)) {
               painter.drawLine(buttons[19]->pos()+px, p5);
               painter.drawLine(p5, buttons[7]->pos());
           } else if (p == qp(19, 11) || p == qp(11, 19)) {
               painter.drawLine(buttons[19]->pos()+px, buttons[11]->pos()+py);
           } else if (p == qp(7, 6) || p == qp(6, 7)) {
               painter.drawLine(buttons[7]->pos(), buttons[6]->pos()+py);
           } else if (p == qp(6, 5) || p == qp(5, 6)) {
               painter.drawLine(buttons[6]->pos()+py, buttons[5]->pos()+py);
           } else if (p == qp(4, 5) || p == qp(5, 4)) {
               painter.drawLine(buttons[4]->pos()+py, buttons[5]->pos()+py);
           } else if (p == qp(3, 4) || p == qp(4, 3)) {
               painter.drawLine(buttons[4]->pos()+py, buttons[3]->pos()+py);
           } else if (p == qp(12, 3) || p == qp(3, 12)) {
               painter.drawLine(buttons[3]->pos()+py, p3);
               painter.drawLine(p2, p3);
               painter.drawLine(p2, p4);
               painter.drawLine(buttons[12]->pos(), p4);
           } else if (p == qp(12, 15) || p == qp(15, 12)) {
               painter.drawLine(buttons[12]->pos(), buttons[15]->pos()+rd);

           } else if (p == qp(15, 2) || p == qp(2, 15)) {
               painter.drawLine(buttons[2]->pos()+py, buttons[15]->pos()+rd);

           } else if (p == qp(16, 2) || p == qp(2, 16)) {
               painter.drawLine(buttons[2]->pos()+py, buttons[16]->pos()+py);

           } else if (p == qp(11, 13) || p == qp(13, 11)) {
                painter.drawLine(buttons[13]->pos()+py, p7);
               painter.drawLine(p7, buttons[11]->pos()+py);

           } else if (p == qp(12, 11) || p == qp(11, 12)) {
               painter.drawLine(buttons[12]->pos(), buttons[11]->pos()+py);

           } else if (p == qp(14, 13) || p == qp(13, 14)) {
               painter.drawLine(buttons[13]->pos()+py, p8);
               painter.drawLine(buttons[14]->pos(), p8);

           } else if (p == qp(18, 13) || p == qp(13, 18)) {
               painter.drawLine(buttons[13]->pos()+py, p9);
               painter.drawLine(buttons[18]->pos()+rd, p9);

           } else if (p == qp(18, 14) || p == qp(14, 18)) {
               painter.drawLine(buttons[14]->pos()+px, p10);
                painter.drawLine(p10, buttons[18]->pos());
           }

           paths.pop_front();
       }



}
