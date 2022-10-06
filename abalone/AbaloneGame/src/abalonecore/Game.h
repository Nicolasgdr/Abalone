/**
 * Project Untitled
 */


#ifndef _GAME_H
#define _GAME_H
#include "Position.hpp"
#include "Direction.h"
#include "AbaPro.hpp"
#include "Board.h"
#include "Player.hpp"
/**
  game class that apply or define rules for the game
 * @brief The Game class
 */
class Game {
public: 
    Game()=default;
    
    void initialized(Color);

    /**
      Method for move the different marble in the game
 * @param Position position
 * @param Direction direction
 */
    void move(std::vector<Position>&);
    
    /**
      Check if the player win or not
     * @brief checkWin
     * @return boolean true or false
     */
    bool checkWin();

    /**
      change the state of the player
      WIN if the player had win
      FAIL if the player loose
      NEUTRAL during all the time
     * @brief setPlayerState
     */
    void setPlayerState();

    inline Player &get_current_player()
    {
        return this->_currentPlayer;
    }
    inline Player& get_opponent_player()
    {
        return this->_opponentPlayer;
    }
    inline Board &get_board()
    {
        return this->_board;
    }
    
    /**
      Attribut of the game
 * @param PosAbaPro abaProInput...
 */
    std::vector<Position>convert(std::vector<AbaPro>&positions);
    /**
      Change who play
     * @brief switchPlayer
     */
    void switchPlayer();

    /**
       *Check if a marble is present in a square need
       * @return true or false
       */
    bool marble_is_present_at (Position &);
    /**
       * Getter of marble at
       * @return Marble
       */
    Marble get_marble_at (Position &);
   std::string get_winner_name();
private:
    /**
        Method for move the marble on line
     * @brief moveLine
     */
    void moveLine(std::vector<Position>&);
    /**
      Method for move the marble on lateral
     * @brief moveLateral
     */
    void moveLateral(std::vector<Position>&);
    /**
      Create the group with multiple marble
     * @brief creategroup
     * @param start
     * @param end
     * @param final
     * @return vector of position
     */
    std::vector<Position> creategroup(Position &start,Position& end,Direction& final);
    /**
      Create the group with 1 marble inside
     * @brief creategroupOneSize
     * @param start
     * @return vector of position
     */
    std::vector<Position> creategroupOneSize(Position &start,Direction);
    /**
      Attribut of game
     * @brief _board
     */
    Board _board;
    /**
      Attribut of game
     * @brief _currentPlayer
     */
    Player _currentPlayer;
    /**
      Attribut of game
     * @brief _opponentPlayer
     */
    Player _opponentPlayer;
    /**
      create a Marble
     * @brief create_marble
     */
    void create_marble();
    /**
      create the board for the game
     * @brief create_board
     */
    void create_board();
    /**
      check if the group can move or not
    * @brief verif_group
    * @return integer
    */
    int verif_group(std::vector<Position>&,std::vector<Position>&);
    /**
     Make the different possible direction the marble can do
     * @brief get_direction_at
     * @param position
     * @return
     */
    Direction get_direction_at( Position &position) {
        Direction direction;
        if (position == Position(-1, 1) ||(position.getRow()<0 && position.getColumn()>=0)) {
            direction = _direction::RIGHT_DOWN;
        }
        if (position == Position(1, 1)||(position.getRow()>=0 && position.getColumn()>=0)) {
            direction = _direction::RIGHT_UP;
        }
        if (position == Position(-1, -1)||(position.getRow()<0 && position.getColumn()<0)) {
            direction = _direction::LEFT_DOWN;
        }
        if (position == Position(1, -1)||(position.getRow()>=0 && position.getColumn()<0)) {
            direction = _direction::LEFT_UP;
        }
        if(position.getRow()==0 &&position.getColumn()>=0)
        {
            direction = _direction::RIGHT_LATERAL;
        }
        if(position.getRow()==0 &&position.getColumn()<0)
        {
            direction = _direction::LEFT_LATERAL;
        }



        return direction;
    }
    /**
      return correct position
     * @brief get_accurate_position
     * @param row
     * @param column
     * @return position
     */
    Position get_accurate_position (char &row, int &column)
    {
        auto rows = row_equivalence (row);
        auto position = Position ();
        switch (column)
        {
        case 1:
            return Position (rows, rows - 4);
        case 2:
            return Position (rows, rows - 2);
        case 3:
            return Position (rows, rows);
        case 4:
            return Position (rows, rows + 2);
        case 5:
            return Position (rows, rows + 4);
        case 6:
            return Position (rows, rows + 6);
        case 7:
            return Position (rows, rows + 8);
        case 8:
            return Position (rows, rows + 10);
        case 9:
            return Position (rows, rows + 12);
        default:;

        }

        return position;
    }
    /**
      move the marble and group them
     * @brief Deplacement
     * @param direction
     */
    void move(std::vector<Position>&,Direction direction, bool isLateral);
    /**
      Apply all the movement
     * @brief apply_move
     * @param direction
     * @param verfi
     */
    void apply_move(std::vector<Position>&,Direction, int);
    /**
      check if position is lateral
     * @brief isLateral
     * @return true or false
     */
    bool isLateral(Position&);
    /**
     equivalence between row and value
      * @brief row_equivalence
      * @param row
      * @return Integer
      */
    int row_equivalence (char &row)
    {
        switch (row)
        {
        case 'A':
            return 9;
        case 'B':
            return 8;
        case 'C':
            return 7;
        case 'D':
            return 6;
        case 'E':
            return 5;
        case 'F':
            return 4;
        case 'G':
            return 3;
        case 'H':
            return 2;
        case 'I':
            return 1;
        default:;
        }
        return 0;
    }
    /**
     * @brief createLateralGroup
     */
    void createLateralGroup(std::vector<Position>&,Direction,std::vector<Position>&);
    /**
     * @brief createNormalGroup
     */
    void createNormalGroup(std::vector<Position>&,Position&,Direction);
};

#endif //_GAME_H
