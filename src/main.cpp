#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include "Sidebar.hpp"
#include "Menu.hpp"
#include "Canvas.hpp"
#include "Header.hpp"

int main() {
    sf::RenderWindow window{{800, 600}, "Geometrix"};
    tgui::Gui gui{window};

    gui.add(Menu::create(), "Menu");
    gui.add(Header::create(), "Header");
    gui.add(Sidebar::create(), "Sidebar");

    Canvas::Ptr canvas = Canvas::create(window);
    canvas->setAutoLayout(tgui::AutoLayout::Fill);
    gui.add(canvas);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            gui.handleEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
            canvas->handleEvent(event);
        }
        window.clear();
        canvas->clear(sf::Color::White);
        canvas->draw();
        gui.draw();
        window.display();
    }
}
