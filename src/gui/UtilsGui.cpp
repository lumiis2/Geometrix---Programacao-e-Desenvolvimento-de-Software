#include "UtilsGui.hpp"
#include "ErrorBox.hpp"
#include "Menu.hpp"

namespace UtilsGui {
    void textResponsiviness(tgui::Widget::Ptr area, float porcentagem) {
        area->onSizeChange([area, porcentagem](sf::Vector2f newSize) {
            unsigned int textSize = static_cast<unsigned int>(newSize.y * porcentagem);
            area->setTextSize(textSize);
        });
    }

    void textResponsiviness(ErrorBox* area, float porcentagem) {
        area->onSizeChange([area, porcentagem](sf::Vector2f newSize) {
            unsigned int textSize = static_cast<unsigned int>(newSize.y * porcentagem);
            area->setTextSize(textSize);
            area->setTitleTextSize(textSize);

        });
    }

    void textResponsiviness(Menu* area, float porcentagem) {
        area->onSizeChange([area, porcentagem](sf::Vector2f newSize) {
            unsigned int textSize = static_cast<unsigned int>(newSize.y * porcentagem);
            area->setTextSize(textSize);
        });
    }
}