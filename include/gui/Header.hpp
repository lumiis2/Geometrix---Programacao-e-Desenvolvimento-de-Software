#ifndef HEADER_H
#define HEADER_H

#include <TGUI/TGUI.hpp>

/**
 * @brief Classe para representar o cabeçalho da interface gráfica
 * 
 * Nesse contexto, a classe Header especializa um widget da biblioteca utilizada (tgui)
 */
class Header : public tgui::Panel {
    public:

        /**
         * @brief Definição de nome alternativo para simplificar o uso de std::shared_ptr<Header>.
         */
        typedef std::shared_ptr<Header> Ptr;
        
        /**
         * @brief Definição de nome alternativo para simplificar o uso de std::shared_ptr<const Header>.
         */
        typedef std::shared_ptr<const Header> ConstPtr;

        /**
         * @brief Função estática utilizada para criar uma instância de Header. 
         * @return Instância de Header criada.
         */
        static Header::Ptr create();

        /**
         * @brief Função estática utilizada para criar uma cópia de Header.
         * @param widget Instância de Header a ser copiada.
         * @return Nova instância de Header criada.
         */
        static Header::Ptr copy(Header::ConstPtr widget);

        /**
         * @brief Construtor para criação do cabeçalho na interface e definição do layout e do título.
         */
        Header();

    protected:

        /** ??
         * @brief  
         * @return
         */
        tgui::Widget::Ptr clone() const override;

    private:
        /**
         * @brief Ponteiro para imagem carregada que representa o título da aplicação.
         */
        tgui::Picture::Ptr titleIcon;
};

#endif