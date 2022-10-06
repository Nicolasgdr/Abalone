/**
 * Project Untitled
 */


#ifndef _BOARD_H
#define _BOARD_H
#include "Square.hpp"
#include "Position.hpp"
#include "vector"
#include "general_function.hpp"
/**
  Board of the game
 * @brief The Board class
getter of a vector square
 */
class Board {
public: 
    std::vector<std::vector<Square>> getSquare()
    {
        return this->_grille;
    }
    /**
     *  initialized the limit of the board  with the limit of column and row
     * @brief Board
     */
    Board()
    {
        _grille = std::vector<std::vector<Square>>(12, std::vector<Square>(19));
    }
    
    /**
      check if the square are in the board or not
 * @param Position Position
 */
    bool isInside( Position position)
    {
        return _grille.at(position.getRow()).at(position.getColumn()).isPresent();
    }
    bool is_out_of_bount(Position position)
    {
        return _grille.at(position.getRow()).at(position.getColumn()).is_out_of_bound();
    }
    /**
      getter of row
     * @brief getRow
     * @return _grille.size
     */
    inline int getRow()
    {
        return this->_grille.size();
    }
    /**
      getter or colmun
     * @brief getColumn
     * @return _grille.at.size
     */
    inline int getColumn()
    {
        return this->_grille.at(0).size();
    }
    /**
      get the square at the position need
     * @brief getsquareAt
     * @param position
     * @return square
     */
    Square getsquareAt(Position position);
    /**
      check if the square are free or not
     * @brief square_is_free
     * @return bolean true or false
     */
    bool square_is_free(Position&);
    /**
      create the board
     * @brief createBoard
     */

    void createBoard();
    
    /**
      change the squaretype with the type need
 * @param Position potion
 */
    void setSquareType( Position, Type &);
private: 
    /**
      board attribut
     * @brief _grille
     */
    std::vector<std::vector<Square>>_grille;

    /**
      check if the square are busy or not
     * @brief square_is_busy
     * @param arrays
     * @param position
     * @return boolean true or false
     */
    bool square_is_busy(std::vector<Position>&arrays, Position& position)
    {
        for(Position p: arrays) {
            if(p.equals(position))
            {
                return true;
            }
        }
        return false;
    }

};

#endif //_BOARD_H
