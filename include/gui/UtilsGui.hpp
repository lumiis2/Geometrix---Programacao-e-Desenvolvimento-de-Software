#ifndef UTILSGUI_HPP
#define UTILSGUI_HPP

#include <TGUI/TGUI.hpp> 
#include "ErrorBox.hpp"
#include "Menu.hpp"

/**
 * @brief Classe concebida para definir a responsividade dos textos das classes GUI.
 */
namespace UtilsGui {
    /**
     * @brief Função para definir a responsividade de um widget instanciado qualquer.
     * @param area Ponteiro compartilhado para o widget cujo texto será tornar responsivo.
     * @param porcentagem Valor que determina a porcentagem do tamanho original do widget a ser usado para o tamanho do texto.
     */
    void textResponsiviness(tgui::Widget::Ptr area, float porcentagem);

    /**
     * @brief Função sobrecarregada para definir a responsividade de um widget do tipo ErrorBox.
     * @param area Ponteiro para a instância de ErrorBox cujo texto será tornar responsivo.
     * @param porcentagem Valor que determina a porcentagem do tamanho original do widget a ser usado para o tamanho do texto.
     */
    void textResponsiviness(ErrorBox* area, float porcentagem);

    /**
     * @brief Função sobrecarregada para definir a responsividade de um widget do tipo Menu.
     * @param area Ponteiro para a instância de Menu cujo texto será tornar responsivo.
     * @param porcentagem Valor que determina a porcentagem do tamanho original do widget a ser usado para o tamanho do texto.
     */
    void textResponsiviness(Menu* area, float porcentagem);
}

#endif