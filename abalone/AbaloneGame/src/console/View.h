#ifndef VIEW_H
#define VIEW_H
#include "string"
#include "../abalonecore/Game.h"
#include "../abalonecore/AbaPro.hpp"
#include "../src/abalonecore/Color.h"
#include "vector"
#include "iostream"
#include "regex"
/**
  class that display the board of he game
 * @brief The View class
 */
class View
{
public:
    View()= default;
    /**
      display the board
     * @brief displayBoard
     */
    void displayBoard(Game&);
    /**
      Attribut of view
     * @brief playerInput
     * @return player input
     */
    std::string &playerInput();
    /**
      Attribut of view
     * @brief tabInput
     * @return tab of input
     */
    std::vector<AbaPro>tabInput(std::string&);
    /**
      print a message for the player
     * @brief print_msg
     * @param message
     */
    void print_msg (const std::string message);
    /**
      Attribut of view
     * @brief player_color
     * @return color
     */
    Color player_color ();
    /**
      print the marble of the player
     * @brief printPlayer
     * @param currentP
     */
    void printPlayer(Player currentP);
private:
    /**
      check if the input is valid or not
     * @brief valid_input
     * @param color
     * @return boolean
     */
    bool valid_input (char &color);
    /**
      return the index with abapro structur
     * @brief displayIndex
     * @param row
     * @return
     */
    char get_abapro_row(int row);
    /**
      display the first part of the board
     * @brief displayFirstPart
     * @param row
     * @param pos
     */
    void displayFirstPart(char row,Position pos, Game&);
    /**
      display the second part of the board
     * @brief displaySndPart
     * @param row
     * @param col
     * @param pos
     */
    void displaySndPart(char row,int col,Position pos, Game&);
    /**
      return the colmun of the board using abapro structur
     * @brief displayIndex2
     * @param row
     * @return
     */
    int get_abapro_col(Position&);
};

#endif // VIEW_H
