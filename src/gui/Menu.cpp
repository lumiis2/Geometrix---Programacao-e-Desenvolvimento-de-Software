#include "Menu.hpp"
#include "File.hpp"
#include "UtilsGui.hpp"
#include "Sidebar.hpp"
#include "ErrorBox.hpp"

Menu::Ptr Menu::create() {
    return std::make_shared<Menu>();
}

Menu::Ptr Menu::copy(Menu::ConstPtr widget) {
    if (widget) return std::static_pointer_cast<Menu>(widget->clone());
    else return nullptr;
}

tgui::Widget::Ptr Menu::clone() const {
    return std::make_shared<Menu>(*this);
}

Menu::Menu() {
    this->setSize("100%", "3%");
    this->setAutoLayout(tgui::AutoLayout::Top);
    this->addMenu("File");
    this->addMenuItem("Load");
    this->addMenuItem("Save");
    this->addMenu("Help");
    this->addMenuItem("About");
    UtilsGui::textResponsiviness(this, 0.7);

    connectMenuItem({"File", "Load"}, [&]{
        auto gui = getParentGui();
        auto sidebar = gui->get<Sidebar>("Sidebar");
        auto dialog =  tgui::FileDialog::create("Open file", "Open");
        dialog->setKeepInParent(true);
        dialog->setPositionLocked(false);
        dialog->setMultiSelect(false);
        dialog->setFileTypeFilters({{"Lua", {"*.lua"}}});
        gui->add(dialog);
        
        dialog->onFileSelect([=](tgui::Filesystem::Path path) {
            std::string filename = path.asNativeString();
            std::string lua = file::readLua(filename);
            sidebar->setInput(lua);
        });
    });
    
    connectMenuItem({"File", "Save"}, [&]{
        auto gui = getParentGui();
        auto sidebar = gui->get<Sidebar>("Sidebar");
        auto dialog =  tgui::FileDialog::create("Save File", "Save");
        dialog->setPositionLocked(false);
        dialog->setMultiSelect(false);
        dialog->setFileMustExist(false);
        dialog->setFileTypeFilters({{"Lua", {"*.lua"}}});
        gui->add(dialog);
        
        dialog->onFileSelect([=](tgui::Filesystem::Path path) {
            std::string filename = path.asNativeString();
            try {
                file::writeLua(filename, sidebar->getInput());
            } catch (const std::runtime_error& e) {
                auto error = ErrorBox::create(e.what());
                getParentGui()->add(error);
            }
        });
    });
}