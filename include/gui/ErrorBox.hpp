#ifndef ERROR_BOX_HPP
#define ERROR_BOX_HPP

#include <TGUI/TGUI.hpp>

/**
 * @brief Classe para representar um pop-up de exceção.
 * 
 * Nesse contexto, a classe ErrorBox especializa um widget da biblioteca utilizada (tgui)
 */
class ErrorBox : public tgui::ChildWindow {
    public:

        /**
         * @brief Definição de nome alternativo para simplificar o uso de std::shared_ptr<ErrorBox>.
         */
        typedef std::shared_ptr<ErrorBox> Ptr;

        /**
         * @brief Definição de nome alternativo para simplificar o uso de std::shared_ptr<const ErrorBox>.
         */
        typedef std::shared_ptr<const ErrorBox> ConstPtr;

        /**
         * @brief Função estática utilizada para criar uma instância de ErrorBox. 
         * @return Instância de ErrorBox criada.
         */
        static ErrorBox::Ptr create(const std::string& errorMessage);

        /**
         * @brief Função estática utilizada para criar uma cópia de ErrorBox.
         * @param widget Instância de ErrorBox a ser copiada.
         * @return Nova instância de ErrorBox criada.
         */
        static ErrorBox::Ptr copy(ErrorBox::ConstPtr widget);

        /**
         * @brief Construtor para criação pop-up de exceção e definição do layout.
         */
        ErrorBox(const std::string& errorMessage);
        std::string getErrorMessage() const;

    protected:

        /** ??
         * @brief  
         * @return
         */
        tgui::Widget::Ptr clone() const override;
        tgui::Label::Ptr msg;
};

#endif
