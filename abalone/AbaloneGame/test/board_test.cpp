#include "catch2/catch.hpp"
#include"../src/abalonecore/Board.h"
#include"../src/abalonecore/Game.h"
TEST_CASE("Board test", "Board") {
    SECTION("Test setsquare"){
        Game game = Game();
        game.initialized(Color::WHITE);
        auto pos = Position(4,8);
        auto type = Type::BUSY;
        game.get_board().setSquareType(pos,type);
        REQUIRE(game.get_board().getsquareAt(pos).getType()==Type::BUSY);
    }
    SECTION("square is empty"){
        Game game = Game();
        game.initialized(Color::WHITE);
        Position pos = Position(5,7);
        bool free=game.get_board().square_is_free(pos);
        REQUIRE(free==true);
           }
    SECTION("square is busy"){
        Game game = Game();
        game.initialized(Color::WHITE);
        Position pos = Position{1,5};
        bool busy = game.get_board().square_is_free(pos);
        REQUIRE(busy==false);
    }
}
