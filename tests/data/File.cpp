#include "doctest.h"
#include "File.hpp"

TEST_CASE("Abertura inválida de arquivo") {
    CHECK_THROWS_AS(file::writeLua("", "Hello World"), std::runtime_error);
}

TEST_CASE("Script-lua vazio para salvar") {
    CHECK_THROWS_AS(file::writeLua("arquivo.lua", ""), std::runtime_error);
}

TEST_CASE("Funcionalidade de leitura e escrita") {
    file::writeLua("arquivo.lua", "Hello World");
    std::cout << file::readLua("arquivo.lua");
    CHECK(file::readLua("arquivo.lua") == "Hello World");
}

TEST_CASE("Leitura e escrita de arquivo maior") {
    file::writeLua("arquivo.lua", "G\nE\nO\nM\nE\nT\nR\nI\nA\n");
    std::cout << file::readLua("arquivo.lua");
    CHECK(file::readLua("arquivo.lua") == "G\nE\nO\nM\nE\nT\nR\nI\nA\n");
}

TEST_CASE("Abrir arquivo inexistente para leitura") {
    CHECK_THROWS_AS(file::readLua("empty.lua"), std::runtime_error);
}

TEST_CASE("Sobrescrita de arquivo") {
    file::writeLua("arquivo.lua", "Point\n");
    file::writeLua("arquivo.lua", "Segment\n");
    CHECK(file::readLua("arquivo.lua") == "Segment\n");
}

