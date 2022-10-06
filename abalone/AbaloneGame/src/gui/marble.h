#ifndef MARBLE_H
#define MARBLE_H
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <QWidget>
#include "QGraphicsPolygonItem"
#include "Color.h"
#include "general_function_gui.hpp"
#include "point.hpp"
#include "memory"
/**
  represent the class of the marble
 * @brief The marble class
 */
class marble : public QGraphicsPolygonItem
{

public:
    /**
      constructor of marble
     * @brief marble
     * @param row
     * @param column
     * @param color
     */
    marble(int row,int column,Color color):QGraphicsPolygonItem(nullptr), _row(row),_column(column),_color(color){createMarble();}
    /**
      draw the marble on the view
     * @brief paint
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);


    protected:
    int _row,_column;
    Color _color;
private:
    /**
      create the marble
     * @brief createMarble
     */
    void createMarble();
};

#endif // MARBLE_H
