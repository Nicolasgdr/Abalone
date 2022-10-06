/**
 * Project Untitled
 */


#ifndef _MARBLE_H
#define _MARBLE_H
#include "Position.hpp"
#include "Color.h"
class Marble {
public: 
    Marble()= default;
    
    /**
      constructor of marble
     * @brief Marble
     * @param color
     */
    Marble( Color color,    Position position): _color(color), _position(position){}
    /**
      getter of position
     * @brief getPosition
     * @return
     */
    inline  Position getPosition()
    {
        return this->_position;
    }
    
    /**
      change the position
     * @brief setPosition
     * @param Position
     */
    void setPosition(Position& position)
    {
        _position=position;
    }
    /**
      getter of color
     * @brief getColor
     * @return color
     */
     inline Color getColor()
    {
         return this->_color;
    }
     /**
       check if its equals
      * @brief equals
      * @param other
      * @return boolean true or false
      */
     bool  equals(Marble &other){
         return this->_position.equals(other._position) && this->_color==other._color;
     }

private: 
     /**
       Attribut of Marble
     * @brief _color
     */
    Color _color;
    /**
      Attribut of Marble
     * @brief _position
     */
    Position _position;
};


#endif //_MARBLE_H
