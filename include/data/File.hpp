#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <string>
#include <iostream>
#include <fstream>

/**
 * @namespace file
 * @brief Namespace contendo funções para manipulação de arquivos
 */
namespace file {

    /**
     * @brief Armazena o script-lua atual do programa em arquivo para salvar o estado da aplicação e poder recuperá-lo.
     * @param filename Nome do arquivo a ser aberto e salvo.
     * @param lua Script-lua a ser armazenado no arquivo.
     */
    void writeLua(const std::string& filename, const std::string& lua);

    /**
     * @brief Recupera o script-lua armazenado como conteúdo em um arquivo salvo outrora.
     * @param filename Nome do arquivo a ser aberto e lido.
     * @return Script-lua recuperado do arquivo.
     */
    std::string readLua(const std::string& filename);
};

#endif 
