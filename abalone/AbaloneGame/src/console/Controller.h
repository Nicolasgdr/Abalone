#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../src/abalonecore/Game.h"
#include "../src/console/View.h"
class Controller
{
public:
Controller()=default;
/**
  getter of game
 * @brief get_game
 * @return game
 */
Game&get_game()
{
    return game;
}
/**
  getter of view
  return the view of the board
 * @brief get_view
 * @return view
 */
const View&get_view()
{
    return view;
}
/**
  start the game and launch all the different method to play
 * @brief start
 */
void start();

private:
/**
  Attribut of Controller
     * @brief game
     */
    Game game;
    /**
       Attribut of Controller
     * @brief view
     */
    View view;
};

#endif // CONTROLLER_H
