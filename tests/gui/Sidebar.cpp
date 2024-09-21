#include "doctest.h"
#include "Sidebar.hpp"

TEST_CASE("Create Sidebar") {
    auto sidebar = Sidebar::create();
    CHECK(sidebar != nullptr);
}

TEST_CASE("Sidebar AutoLayout") {
    auto sidebar = Sidebar::create();
    CHECK(sidebar->getAutoLayout() == tgui::AutoLayout::Left);
}

TEST_CASE("Set Input Area") {
    auto sidebar = Sidebar::create();
    sidebar->setInputArea();
    CHECK(sidebar->getInputArea() != nullptr);
}

TEST_CASE("Set Input") {
    auto sidebar = Sidebar::create();
    sidebar->setInput("Test Input");
    CHECK(sidebar->getInput() == "Test Input");
}

TEST_CASE("Run Button Handler") {
    auto sidebar = Sidebar::create();
    
    SUBCASE("Run Button Handler - Valid Lua Input") {
        sidebar->setInput("p = Point(1, 2)");
        CHECK_NOTHROW(sidebar->runButtonHandler());
    }

    SUBCASE("Run Button Handler - Invalid Lua Input") {
        sidebar->setInput("p = Point(1, 2, 3)");
        CHECK_THROWS_AS(sidebar->runButtonHandler(), std::exception);
    }
}

