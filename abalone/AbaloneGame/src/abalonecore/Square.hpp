/**
 * Project Untitled
 */


#ifndef _SQUARE_H
#define _SQUARE_H
#include "Type.h"
class Square {
public: 
    /**
      getter of type
     * @brief getType
     * @return a type
     */
    inline  Type getType(){
        return this->_type;
    }
    /**
      setter for the square
     * @brief set_square
     * @param type
     */
    void set_square(Type type)
    {
        this->_type=type;
    }
    /**
      constructor of square
     * @brief Square::Square
     * @param _type
     */
    Square(Type _type)
    {
        this->_type = _type;
    }
    Square()= default;
    /**
      return if the marble is on the square or not
     * @brief Square::marbleIsPresent
     * @return true or false
     */
    bool isPresent() {
        return _type == Type::BUSY || _type==EMPTY;
    }
    /**
      check if the square is free or not
     * @brief is_free
     * @return true or false
     */
    bool is_free()
    {
        return this->_type==Type::EMPTY;
    }
    bool is_out_of_bound()
    {
        return this->_type==Type::OUT_OF_BOND;
    }
private: 
    /**
      Attribut of square
     * @brief _type
     */
    Type _type;

};

#endif //_SQUARE_H
