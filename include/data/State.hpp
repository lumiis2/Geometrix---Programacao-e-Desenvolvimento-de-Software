#ifndef STATE_HPP
#define STATE_HPP

#include "Object.hpp"

#include <set>
#include <map>
#include <vector>
#include <memory>
#include <utility>

/**
 * @brief Classe que representa o estado do sistema, mantendo objetos e suas relações.
 */
class State {
    public:
        /**
         * @brief Adiciona um novo objeto à listagem do estado atual do programa.
         * @param obj Entidade geométrica a ser adicionada 
         * @param dependencies Dependências relativas ao objeto incluído por índices de entidades já listadas.
         * @return Índice único no estado atual para o objeto adicionado.
         */
        size_t add(std::shared_ptr<Object> obj, std::set<size_t> dependencies);

        /**
         * @brief Apaga um objeto com índice especificado.
         * @param id Índice do objeto na listagem.
         */
        void remove(size_t id);

        /**
         * @brief Limpa todo o estado atual do programa (apaga todos os objetos geométricos da listagem).
         */
        void clear();

        /**
         * @brief Recupera um objeto com índice especificado.
         * @param id Índice do objeto na listagem.
         * @return Objeto recuperado relativo ao id.
         */
        std::shared_ptr<Object> get(size_t id);

        /**
         * @brief Recupera os objetos existentes no estado atual do programa
         * @return Conjunto de objetos atuais, contendo o id e o ponteiro relativos.
         */
        std::vector<std::pair<size_t, std::shared_ptr<Object>>> getObjects();

        /**
         * @brief Implementação do padrão de design Singleton (apenas uma instância da classe no programa).
         * @return Retorna a instância única da classe.
         */
        static State& getInstance();

        State(State const&) = delete;
        
        void operator = (State const&) = delete;

    private:
        /**
         * @brief Construtor padrão (privado, em conformidade ao design Singleton).
         */
        State();

        /**
         * @brief Representa o identificador livre para criação de um novo objeto.
         */
        static size_t nextId;

        /** ??
         * @brief
         * @param id 
         * @param last 
         */
        void remove(size_t id, size_t last);

        /**
         * @brief Armazena os objetos geométricos presentes no estado atual do programa, indexados unicamente.
         */
        std::map<size_t, std::shared_ptr<Object>> objects;

        /**
         * @brief Armazena as dependências entre os objetos por meio de seus índices, na relação acima ou abaixo na hierarquia de dependências.
         */
        std::map<size_t, std::set<size_t>> parents, children;
};

#endif 
