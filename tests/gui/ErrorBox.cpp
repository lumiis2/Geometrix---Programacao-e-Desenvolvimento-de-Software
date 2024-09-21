#include "doctest.h"
#include "ErrorBox.hpp"

TEST_CASE("ErrorBox with choosen error message") {
    std::string errorMessage = "Test error message";
    auto errorBox = ErrorBox::create(errorMessage);

    REQUIRE(errorBox != nullptr);
    REQUIRE(errorBox->getErrorMessage() == errorMessage);
}

TEST_CASE("ErrorBox with no error message") {
    auto errorBox = ErrorBox::create("");

    REQUIRE(errorBox != nullptr);
    REQUIRE(errorBox->getErrorMessage() == "");
}

