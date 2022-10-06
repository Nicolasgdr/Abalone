#include <catch2/catch.hpp>
#include"Game.h"
#include "../src/console/View.h"
TEST_CASE("Test Game"){
    SECTION("TEST CONVERT"){
        auto game = Game();
        game.initialized(Color::WHITE);
        auto abapro = std::vector<AbaPro>{AbaPro('A',1),AbaPro('C',1),AbaPro('D',3)};
        auto conversion = game.convert(abapro);
        REQUIRE(conversion.size()==3);
        REQUIRE(conversion.at(0)==Position(9,5));
        REQUIRE(conversion.at(1)==Position(7,3));
        REQUIRE(conversion.at(2)==Position(6,6));
    }
    SECTION("TEST CONVERT 2"){
        auto game = Game();
        game.initialized(Color::WHITE);
        auto abapro = std::vector<AbaPro>{AbaPro('I',8),AbaPro('H',7)};
        auto conversion = game.convert(abapro);
        REQUIRE(conversion.size()==2);
        REQUIRE(conversion.at(0)==Position(1,11));
        REQUIRE(conversion.at(1)==Position(2,10));
    }
    SECTION("TEST  MOVE 1 MARBLE"){
        Game game = Game();
        game.initialized(Color::WHITE);
        auto position = std::vector<Position>{Position{2,6},Position{3,5}};
        game.move(position);
        REQUIRE(game.get_board().getsquareAt(Position(2,6)).getType()==Type::EMPTY);
        REQUIRE(game.get_board().getsquareAt(Position(3,5)).getType()==Type::BUSY);
    }
    SECTION("TEST  MOVE 1 MARBLE OCCUPATE"){
        Game game = Game();
        game.initialized(Color::WHITE);
        auto position = std::vector<Position>{Position{1,5},Position{2,4}};
        game.move(position);
        REQUIRE(game.get_board().getsquareAt(Position(1,5)).getType()==Type::EMPTY);
        REQUIRE(game.get_board().getsquareAt(Position(2,4)).getType()==Type::BUSY);
        REQUIRE(game.get_board().getsquareAt(Position(3,3)).getType()==Type::BUSY);
    }
    SECTION("TEST  MOVE GROUP MARBLE LATERAL BLACK"){
        Game game = Game();
        game.initialized(Color::BLACK);
        auto position = std::vector<Position>{Position{7,7},Position{7,11},Position(6,6)};
        game.move(position);
        REQUIRE(game.get_board().getsquareAt(Position(6,6)).getType()==Type::BUSY);
        REQUIRE(game.get_board().getsquareAt(Position(6,8)).getType()==Type::BUSY);
        REQUIRE(game.get_board().getsquareAt(Position(6,10)).getType()==Type::BUSY);
    }
    SECTION("TEST  MOVE GROUP MARBLE LATERAL WHITE"){
        Game game = Game();
        game.initialized(Color::WHITE);
        auto position = std::vector<Position>{Position{3,7},Position{3,11},Position(4,6)};
        game.move(position);
        REQUIRE(game.get_board().getsquareAt(Position(3,7)).getType()==Type::EMPTY);
        REQUIRE(game.get_board().getsquareAt(Position(4,6)).getType()==Type::BUSY);
        REQUIRE(game.get_board().getsquareAt(Position(4,8)).getType()==Type::BUSY);
        REQUIRE(game.get_board().getsquareAt(Position(4,10)).getType()==Type::BUSY);
    }

    SECTION("TEST  MOVE GROUP MARBLE LINE WHITE"){
        Game game = Game();
        game.initialized(Color::WHITE);
        auto position = std::vector<Position>{Position{1,9},Position{3,7},Position(4,6)};
        game.move(position);
        REQUIRE(game.get_board().getsquareAt(Position(1,9)).getType()==Type::EMPTY);
        REQUIRE(game.get_board().getsquareAt(Position(2,8)).getType()==Type::BUSY);
        REQUIRE(game.get_board().getsquareAt(Position(3,7)).getType()==Type::BUSY);
        REQUIRE(game.get_board().getsquareAt(Position(4,6)).getType()==Type::BUSY);
    }

}

