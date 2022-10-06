#include <catch2/catch.hpp>
#include "../src/abalonecore/Game.h"
TEST_CASE("Player test", "Player")
{

    SECTION("TEST 14 MARBLE")
    {
        auto game = Game();
        game.initialized(Color::BLACK);
        REQUIRE(game.get_current_player().getAllMarbles().size()==14);
    }

    SECTION("TEST REMOVE MARBLE")
    {
        Game game= Game();
        game.initialized(Color::WHITE);
        Marble marble = Marble(Color::WHITE,{1,5});
        game.get_current_player().remove(marble);
        REQUIRE(game.get_current_player().getAllMarbles().size()==13);
    }
    SECTION("Test if Marble are mine")
    {
        Game game= Game();
        game.initialized(Color::WHITE);
        auto marbles = std::vector<Position>{{1,5},{2,6},{3,9},{2,14}};
        auto mine =game.get_current_player().marble_are_mines(marbles);
        REQUIRE(mine==true);

    }
    SECTION("Test if Marble is mine")
    {
        Game game= Game();
        game.initialized(Color::WHITE);
        auto marbles = std::vector<Position>{{1,5},{2,6},{3,9},{2,14}};
        auto pos = marbles.at(1);
        auto mine =game.get_current_player().marble_is_mine(pos);
        REQUIRE(mine==true);

    }

    SECTION("Test if Marble are not mine")
    {
        Game game= Game();
        game.initialized(Color::WHITE);
        auto marbles = std::vector<Position>{{1,5},{2,6},{3,9},{7,11}};
        auto player=game.get_current_player();
        auto mine = player.marble_are_mines(marbles);
        REQUIRE(mine==false);

    }
}
