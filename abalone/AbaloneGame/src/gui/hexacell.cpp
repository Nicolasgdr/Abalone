#include "hexacell.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <iostream>
#include <cmath>
#include "general_function_gui.hpp"
#include "point.hpp"
#include "abalone_gui.h"

double const hexacell::zValMax = 10000;//arbitrary

hexacell::hexacell( int dx, int dy)
    : QGraphicsPolygonItem(nullptr),
      rad(50), dx(dx), dy(dy),
      mouseover(false), selected(false), moved(false)
{
    this->setAcceptHoverEvents(true);
    zval = zValue();

    static const double piOver6 = atan(1) * 4 / 6;
    g_function_gui::convert_dx_dy(dx,dy);
    QPolygonF polygon;
    auto&& corners = orbit({dx, dy}, 6, rad, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void hexacell::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    if(selected)
    {
        QPen pen(Qt::blue, 5);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(mouseover)
    {
        QPen pen(Qt::blue, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else
    {
        QPen pen(Qt::blue, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::darkBlue);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }

    painter->drawPolygon(polygon());
}

void hexacell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = true;
    update();
}

void hexacell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = false;
    update();
}

void hexacell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    event->accept();
    moved = false;
    selected = !selected;
    value= Position(dx,dy);
    emit sendValue(value);
    update();
}

void hexacell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    selected = !selected;
}

void hexacell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moved = true;
}

#pragma GCC diagnostic pop
