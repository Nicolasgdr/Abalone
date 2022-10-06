#ifndef HEXACELL_H
#define HEXACELL_H

#include <QWidget>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>
#include "abalone_gui.h"
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;
#include "memory"
/**
  source : abs,pbt
  represent the class of hexacel
 * @brief The hexacell class
 */
class hexacell : public QObject, public QGraphicsPolygonItem
{

     Q_OBJECT
    static const double zValMax; //z-val of selected items
    double zval; //z-val at instanciation

protected:
    double rad, dx, dy;//hexagon radius, coordinate (x,y) of center
    bool mouseover, selected, moved;//mouse interaction booleans
    Position value;



public:
    /**
      hexacel constructor
     * @brief hexacell
     * @param dx
     * @param dy
     */
    hexacell(int dx = 0,int dy = 0);
    /**
      fonction use to draw the hexacel
     * @brief paint
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    /**
      getter for dx
     * @brief get_dx
     * @return
     */
    inline double get_dx()
    {
        return dx;
    }
    /**
      getter for dy
     * @brief get_dy
     * @return
     */
    inline  double get_dy()
    {
        return dy;
    }


protected:
    /**
      event for mouse when entering the hexacel
     * @brief hoverEnterEvent
     * @param event
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    /**
      event for the mouse when leaving the hexacel
     * @brief hoverLeaveEvent
     * @param event
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    /**
      event for the mouse when pressing the hexacel
     * @brief mousePressEvent
     * @param event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    /**
      event for mouse when the right click is realised
     * @brief mouseReleaseEvent
     * @param event
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    /**
      event for the mouse when move all over the hexacel
     * @brief mouseMoveEvent
     * @param event
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);

signals:
    /**
      signal send to abalone gui
     * @brief sendValue
     */
    void sendValue(Position&);


};

#endif // HEXACELL_H
