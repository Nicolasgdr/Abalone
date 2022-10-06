/**
 * Project Untitled
 */


#ifndef _POSITION_H
#define _POSITION_H
#include "Direction.h"
#include "vector"
class Position {
public: 
    /**
      getter of row
 * @brief getRow
 * @return row
 */
inline int getRow()
{
    return this->_row;
}
/**
  getter of column
 * @brief getColumn
 * @return column
 */
inline int getColumn()
{
    return this->_column;
}
Position()=default;
/**
  Constructor of position
 * @param int _row
 * @param int _column
 */
Position(int row,  int column) : _row(row), _column(column){}
/**
  compare two positions
 * @param Direction direction
 */
bool equals(Position& other)const{
    return this->_column==other._column && this->_row==other._row;
}

/**
  check the next case with the direction need
 * @brief neighbour
 * @param direction
 * @return position
 */
Position neighbour(Direction& direction)
{
    return Position(this->_row+direction.first,this->_column+direction.second);
}
/**
  *compare two position
  * @param other
  * @return position
  */
 bool operator== (Position other) const
 {
   return this->equals (other);
 }
 /**
  * difference between position
  * @param other
  * @return position
  */
 bool operator!= (Position &other) const
 {
   return !this->equals(other);
 }

 /**
   * soustract 2 positions
   * @param element
   * @return position
   */
  Position operator- (const Position &element) const
  {
    return Position (this->_row - element._row, this->_column - element._column);
  }
  /**
    setter of row
   * @brief set_row
   * @param row
   */
  void set_row (int row)
   {
     _row = row;
   }
  /**
    setter of column
    * @brief set_column
    * @param column
    */
   void set_column (int column)
   {
     _column = column;
   }


private:
   /**
     Attribut of Position
     * @brief _row
     */
    int _row;
    /**
      Attribut of Position
     * @brief _column
     */
    int _column;


};
#endif //_POSITION_H
