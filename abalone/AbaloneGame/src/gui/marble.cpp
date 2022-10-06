#include "marble.h"


void marble::createMarble()
{
    g_function_gui::convert_dx_dy(this->_row,this->_column);
    static const double piOver6 = atan(1) * 4 / 6;
    QPolygonF polygon;
    auto&& corners = orbit({this->_row, this->_column},100., 20., piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void marble::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    QPen pen(Qt::blue, 5);
    painter->setPen(pen);

    QBrush brush;
    if(this->_color==BLACK)brush.setColor(Qt::black);
    if(this->_color==WHITE)brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);

    painter->setBrush(brush);
    painter->drawPolygon(polygon());
}



