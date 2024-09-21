#include "ErrorBox.hpp"
#include "UtilsGui.hpp"

ErrorBox::Ptr ErrorBox::create(const std::string& errorMessage) {
    return std::make_shared<ErrorBox>(errorMessage);
}

ErrorBox::Ptr ErrorBox::copy(ErrorBox::ConstPtr widget) {
    if (widget) 
        return std::static_pointer_cast<ErrorBox>(widget->clone());
    else 
        return nullptr;
}

tgui::Widget::Ptr ErrorBox::clone() const {
    return std::make_shared<ErrorBox>(*this);
}

ErrorBox::ErrorBox(const std::string& errorMessage) {
    this->setSize("35%", "15%"); 
    this->setKeepInParent(false);
    this->setPositionLocked(false);
    this->setTitle("Erro!");
    this->msg = tgui::Label::create();
    this->msg->setText(errorMessage);
    this->add(msg);
    UtilsGui::textResponsiviness(this, 0.15);
}

std::string ErrorBox::getErrorMessage() const{
    return this->msg->getText().toStdString();
}

