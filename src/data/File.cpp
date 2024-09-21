#include "File.hpp"
#include <iostream>
#include <fstream>

void file::writeLua(const std::string& filename, const std::string& lua) {
    if(lua.empty())
        throw std::runtime_error("Código vazio!");

    std::ofstream arquivo(filename);
    if (!arquivo.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");

    arquivo << lua;
    arquivo.close();
}

std::string file::readLua(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Erro ao abrir o arquivo.");

    std::string lua, line;
    while(std::getline(file, line)) {
        lua += line;
        if(!file.eof()){
            lua += '\n';
        }
    }
    file.close();

    return lua;
}


