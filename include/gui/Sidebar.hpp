#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "File.hpp"
#include <TGUI/TGUI.hpp>

/**
 * @brief Classe para representar a barra lateral da interface gráfica
 * 
 * Nesse contexto, a classe Sidebar especializa um widget da biblioteca utilizada (tgui)
 */
class Sidebar : public tgui::Panel {
    public:

        /**
         * @brief Definição de nome alternativo para simplificar o uso de std::shared_ptr<Sidebar>.
         */
        typedef std::shared_ptr<Sidebar> Ptr;

        /**
         * @brief Definição de nome alternativo para simplificar o uso de std::shared_ptr<const Sidebar>.
         */
        typedef std::shared_ptr<const Sidebar> ConstPtr;

        /**
         * @brief Função estática utilizada para criar uma instância de Sidebar. 
         * @return Instância de Sidebar criada.
         */
        static Sidebar::Ptr create();

        /**
         * @brief Função estática utilizada para criar uma cópia de Sidebar.
         * @param widget Instância de Sidebar a ser copiada.
         * @return Nova instância de Sidebar.
         */
        static Sidebar::Ptr copy(Sidebar::ConstPtr widget);

        /**
         * @brief Modifica o Script-lua na aba de input do usuário.
         * @param input Novo Script-lua a ser inserido na aba de input.
         */
        void setInput(const std::string& input);

        /**
         * @brief Recupera o Script-lua atual na aba de input do usuário.
         * @return Script-lua recuperado da aba de input.
         */
        std::string getInput();

        /**
         * @brief Construtor para criação da barra lateral na interface e definição do layout.
         */
        Sidebar();

    protected:

        /** ??
         * @brief  
         * @return
         */
        tgui::Widget::Ptr clone() const override;
        

    private:

        /**
         * @brief Widget que representa a aba de input do usuário.
         */
        tgui::TextArea::Ptr inputArea;

        /**
         * @brief Widget que representa a aba de output do sistema.
         */
        tgui::Label::Ptr outputArea;

        /**
         * @brief Widget que representa o botão de execução do Script-lua.
         */
        tgui::Button::Ptr runButton;

        /**
         * @brief Criação e definição do layout da aba de input do usuário.
         */
        void setInputArea();

        /**
         * @brief Criação e definição do layout da aba de output do sistema.
         */
        void setOutputArea();

        /**
         * @brief Criação e definição do layout do botão de execução do Script-lua.
         */
        void runButtonHandler();
};

#endif
