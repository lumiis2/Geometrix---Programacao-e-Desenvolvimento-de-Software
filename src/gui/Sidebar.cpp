#include "Sidebar.hpp"
#include "State.hpp"
#include "UtilsGui.hpp"
#include "ErrorBox.hpp"
#include "File.hpp"
#include "LuaHandler.hpp"

Sidebar::Ptr Sidebar::create() {
    return std::make_shared<Sidebar>();
}

Sidebar::Ptr Sidebar::copy(Sidebar::ConstPtr widget) {
    if (widget) return std::static_pointer_cast<Sidebar>(widget->clone());
    else return nullptr;
}

tgui::Widget::Ptr Sidebar::clone() const {
    return std::make_shared<Sidebar>(*this);
}

Sidebar::Sidebar() {
    getRenderer()->setBackgroundColor(sf::Color(248, 248, 248));
    setWidth("25%");
    setAutoLayout(tgui::AutoLayout::Left);

    setInputArea();
    setOutputArea();

    runButton = tgui::Button::create();
    runButton->setText("RUN");
    runButton->setSize("100%", "10%");
    runButton->setAutoLayout(tgui::AutoLayout::Bottom);
    runButton->getRenderer()->setBackgroundColor(sf::Color::Black);
    runButton->getRenderer()->setBorderColor(tgui::Color::White);
    runButton->getRenderer()->setTextColor(tgui::Color::White);
    runButton->onPress(&Sidebar::runButtonHandler, this);
    UtilsGui::textResponsiviness(runButton, 0.25);
    add(runButton);
}

void Sidebar::setInput(const std::string& input) {
    inputArea->setText(input);
}

std::string Sidebar::getInput() {
    return inputArea->getText().toStdString();
}

void Sidebar::setInputArea() {
    this->inputArea = tgui::TextArea::create();
    this->inputArea->setSize("100%", "50%");
    this->inputArea->setAutoLayout(tgui::AutoLayout::Top);
    
    this->inputArea->getRenderer()->setBackgroundColor(sf::Color(253, 253, 253));
    this->inputArea->getRenderer()->setBorders({2, 2, 2, 2});
    this->inputArea->getRenderer()->setBorderColor(sf::Color(200, 200, 200));
    this->inputArea->getRenderer()->setPadding({5, 5, 5, 5});
    this->inputArea->setDefaultText("Entrada");
    UtilsGui::textResponsiviness(inputArea, 0.05);

    this->add(inputArea);
}

void Sidebar::setOutputArea() {
    outputArea = tgui::Label::create();
    outputArea->setSize("100%", "30%");
    outputArea->setAutoLayout(tgui::AutoLayout::Top);
    
    outputArea->getRenderer()->setBackgroundColor(sf::Color(253, 253, 253));
    outputArea->getRenderer()->setBorders({2, 2, 2, 2});
    outputArea->getRenderer()->setBorderColor(sf::Color(200, 200, 200));
    outputArea->getRenderer()->setPadding({5, 5, 5, 5});
    outputArea->setText("Saída");
    UtilsGui::textResponsiviness(outputArea, 0.08);
 
    this->add(outputArea);
}

void Sidebar::runButtonHandler() {
    try {
        State::getInstance().clear();
        LuaHandler lua;
        std::string input = inputArea->getText().toStdString();
        lua.run(input);
        outputArea->setText(LuaHandler::out);
    } catch (const std::exception& e) {
        auto error = ErrorBox::create(e.what());
        getParentGui()->add(error);
    }
}
