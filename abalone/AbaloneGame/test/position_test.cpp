#include "catch2/catch.hpp"
#include "../src/abalonecore/Position.hpp"
TEST_CASE("Position case ", "Position")
{
    SECTION("TEST NEIGBOUR LEFT")
    {
        auto position =Position(0,0);
        auto dir = _direction::LEFT_LATERAL;
        auto next = position.neighbour(dir);
        REQUIRE(next==Position(0,-2));
    }
    SECTION("TEST NEIGBOUR RIGHT")
    {
        auto position =Position(0,0);
        auto dir = _direction::RIGHT_LATERAL;
        auto next = position.neighbour(dir);
        REQUIRE(next==Position(0,2));
    }
    SECTION("TEST NEIGBOUR  RIGHT UP")
    {
        auto position =Position(0,0);
        auto dir = _direction::RIGHT_UP;
        auto next = position.neighbour(dir);
        REQUIRE(next==Position(1,1));
    }

    SECTION("TEST NEIGBOUR RIGHT DOWN")
    {
        auto position =Position(0,0);
        auto dir = _direction::RIGHT_DOWN;
        auto next = position.neighbour(dir);
        REQUIRE(next==Position(-1,1));
    }
    SECTION("TEST NEIGBOUR LEFT UP")
    {
        auto position =Position(0,0);
        auto dir = _direction::LEFT_UP;
        auto next = position.neighbour(dir);
        REQUIRE(next==Position(1,-1));
    }
    SECTION("TEST NEIGBOUR LEFT DOWN")
    {
        auto position =Position(0,0);
        auto dir = _direction::LEFT_DOWN;
        auto next = position.neighbour(dir);
        REQUIRE(next==Position(-1,-1));
    }
}

