#include "doctest.h"
#include "Menu.hpp"

TEST_CASE("Create Menu") {
    auto menu = Menu::create();
    CHECK(menu != nullptr);
}

TEST_CASE("Menu Size and AutoLayout") {
    auto menu = Menu::create();
    CHECK(menu->getSize() == tgui::Vector2f(menu->getSize().x, 3.0f));
    CHECK(menu->getAutoLayout() == tgui::AutoLayout::Top);
}