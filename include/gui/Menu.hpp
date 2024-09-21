#ifndef MENU_H
#define MENU_H

#include <TGUI/TGUI.hpp>

/**
 * @brief Classe para representar o menu superior da interface gráfica
 * 
 * Nesse contexto, a classe Menu especializa um widget da biblioteca utilizada (tgui)
 */
class Menu : public tgui::MenuBar {
    public:

        /**
         * @brief Definição de nome alternativo para simplificar o uso de std::shared_ptr<Menu>.
         */
        typedef std::shared_ptr<Menu> Ptr;
        
        /**
         * @brief Definição de nome alternativo para simplificar o uso de std::shared_ptr<const Menu>.
         */
        typedef std::shared_ptr<const Menu> ConstPtr;

        /**
         * @brief Função estática utilizada para criar uma instância de Menu. 
         * @return Instância de Menu criada.
         */
        static Menu::Ptr create();

        /**
         * @brief Função estática utilizada para criar uma cópia de Menu.
         * @param widget Instância de Menu a ser copiada.
         * @return Nova instância de Menu criada.
         */
        static Menu::Ptr copy(Menu::ConstPtr widget);

        /**
         * @brief Construtor para criação do menu superior na interface e definição do layout e dos itens clicáveis.
         */
        Menu();

    protected:

        /** ??
         * @brief  
         * @return 
         */
        tgui::Widget::Ptr clone() const override;
};

#endif
