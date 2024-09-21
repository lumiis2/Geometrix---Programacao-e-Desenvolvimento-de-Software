#ifndef LUA_HANDLER_H
#define LUA_HANDLER_H

#include <string>

extern "C" {
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

/**
 * @brief Classe concebida para definir padrões de entrada aceitos pelo programa e realizar a interpretação desses padrões.
 */
class LuaHandler {    
    public:
        /**
         * @brief Construtor padrão da classe, inicializa um ambiente Lua, abre as bibliotecas padrão e registra funções Lua personalizadas.
         */
        LuaHandler();

        /**
         * @brief Destrutor padrão da classe.
         */
        ~LuaHandler();

        /**
         * @brief Registra uma função Lua no ambiente Lua. Utilizada no construtor.
         * @param name Nome da função a ser registrada.
         * @param function Função/wrapper definido.
         */
        void registerFunction(std::string name, lua_CFunction function);

        /**
         * @brief Função que utiliza luaL_dostring para executar o código Lua fornecido na string code.
         * @param code O código Lua convertido para uma string C (um ponteiro para caracteres).
         */
        void run(std::string code);

        /**
         * @brief Variável estática usada para armazenar mensagens de saída ou resultado da execução do código Lua.
         */
        static std::string out;

    protected:

        /**
         * @brief Ponteiro que armazena o endereço de uma instância lua_State, representa o estado global do ambiente Lua.
         */
        lua_State* L;
};

#endif

