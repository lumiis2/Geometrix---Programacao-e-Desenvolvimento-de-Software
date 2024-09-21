#include "doctest.h"
#include "LuaHandler.hpp"
#include "doctest.h"
#include "LuaHandler.hpp"

TEST_CASE("Lua Wrapper - pointWrapper") {
    SUBCASE("Incorrect Number of Arguments") {
        LuaHandler lua;
        CHECK_THROWS_AS(lua.run("Point(1)"), std::runtime_error);
        CHECK_THROWS_AS(lua.run("Point(1, 2, 3)"), std::runtime_error);
    }

    SUBCASE("Valid Input") {
        LuaHandler lua;
        lua.run("p = Point(1, 2)");
        CHECK_NOTHROW(lua.run("print(p)"));
    }
}

TEST_CASE("Lua Wrapper - segmentWrapper") {
    SUBCASE("Incorrect Number of Arguments") {
        LuaHandler lua;

        CHECK_THROWS_AS(lua.run("Segment('a', 2)"), std::runtime_error);
        CHECK_THROWS_AS(lua.run("Segment(1, 'b')"), std::runtime_error);

        CHECK_THROWS_AS(lua.run("Segment(1)"), std::runtime_error);
        CHECK_THROWS_AS(lua.run("Segment(1, 2, 2)"), std::runtime_error);
    }

    SUBCASE("Valid Result") {
        LuaHandler lua;

        lua.run("p = Point(1, 2)");
        lua.run("q = Point(3, 4)");
        lua.run("s = Segment(p, q)");
        CHECK_NOTHROW(lua.run("print(s)"));
    }

    SUBCASE("Invalid Argument Types") {
        LuaHandler lua;

        lua.run("p = Point(1, 2)");
        CHECK_THROWS_AS(lua.run("Segment(p, 'invalid')"), std::runtime_error);
    }
}

TEST_CASE("Lua Wrapper - polygonWrapper") {
    SUBCASE("Incorrect Number of Arguments") {
        LuaHandler lua;

        CHECK_THROWS_AS(lua.run("Polygon(1)"), std::runtime_error);
        CHECK_THROWS_AS(lua.run("Polygon(1, 2, 3)"), std::runtime_error);
    }

    SUBCASE("Valid Result") {
        LuaHandler lua;

        lua.run("p1 = Point(1, 2)");
        lua.run("p2 = Point(3, 4)");
        lua.run("p3 = Point(5, 6)");
        
        lua.run("poly = Polygon(p1, p2, p3)");
        
        CHECK_NOTHROW(lua.run("print(poly)"));

    }

    SUBCASE("Invalid Argument Types") {
        LuaHandler lua;

        lua.run("p = Point(1, 2)");
        
        CHECK_THROWS_AS(lua.run("Polygon(p, 'invalid')"), std::runtime_error);
    }
}

TEST_CASE("Lua Wrapper - areaWrapper") {
    SUBCASE("Incorrect Number of Arguments") {
        LuaHandler lua;

        CHECK_THROWS_AS(lua.run("Area()"), std::runtime_error);
        CHECK_THROWS_AS(lua.run("Area(1, 2)"), std::runtime_error);
    }

    SUBCASE("Valid Result") {
        LuaHandler lua;

        lua.run("p1 = Point(0, 0)");
        lua.run("p2 = Point(0, 5)");
        lua.run("p3 = Point(5, 5)");
        lua.run("poly = Polygon(p1, p2, p3)");

        lua.run("area = Area(poly)");

        CHECK_NOTHROW(lua.run("print(area)"));

    }

    SUBCASE("Invalid Argument Type") {
        LuaHandler lua;

        lua.run("p = Point(1, 2)");

        CHECK_THROWS_AS(lua.run("Area(p)"), std::runtime_error);
    }

    SUBCASE("Invalid Polygon") {
        LuaHandler lua;

        lua.run("p = Point(1, 2)");

        CHECK_THROWS_AS(lua.run("Area(p)"), std::runtime_error);
    }
}