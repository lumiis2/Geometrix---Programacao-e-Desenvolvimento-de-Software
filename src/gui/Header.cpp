#include "Header.hpp"

Header::Ptr Header::create() {
    return std::make_shared<Header>();
}

Header::Ptr Header::copy(Header::ConstPtr widget) {
    if (widget) 
        return std::static_pointer_cast<Header>(widget->clone());
    else 
        return nullptr;
}

tgui::Widget::Ptr Header::clone() const {
    return std::make_shared<Header>(*this);
}

Header::Header() {
    this->setAutoLayout(tgui::AutoLayout::Top);
    this->setSize("100%", "10%");
    this->getRenderer()->setBackgroundColor(sf::Color(240, 240, 240));
    this->titleIcon = tgui::Picture::create("assets/TextIcon.png");
    this->titleIcon->setPosition(0, 4);
    this->titleIcon->setSize({"25%", "100%"});
    this->add(this->titleIcon);
}