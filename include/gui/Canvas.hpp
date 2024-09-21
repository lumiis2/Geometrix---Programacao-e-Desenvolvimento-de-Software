#ifndef CANVAS_H
#define CANVAS_H

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "Unit.hpp"
#include "Segment.hpp"

class Canvas : public tgui::Panel {
    public:
        typedef std::shared_ptr<Canvas> Ptr;
        typedef std::shared_ptr<const Canvas> ConstPtr;
        static Canvas::Ptr create(sf::RenderWindow& window);
        static Canvas::Ptr copy(Canvas::ConstPtr widget);
        /**
         * @brief Construtor padrão.
         * @param window Instancia do objecto que representa a janela geral.
         */
        Canvas(sf::RenderWindow& window);
        /**
         * @brief Destrutor padrão.
         * 
         */
        ~Canvas();
        /**
         * @brief Desenha o grid e seus objetos, a partir do estado atual do programa.
         * 
         */
        void draw();
        /**
         * @brief Atualiza as coordenadas do mouse.
         * 
         * @param x Nova coordenada do mouse no eixo x.
         * @param y Nova coordenada do mouse no eixo y.
         */
        void updateMouse(double x, double y);
        /**
         * @brief Atualiza o estado atual do grid, de acordo com as interações do usuário.
         * 
         * @param event Evento que guarda qual foi a interação do usuário, para que ele possa ser computado.
         */
        void update(sf::Event event);

        /**
         * @brief Faz o processamento do evento, para que o grid possa ser atualizado.
         * 
         * @param event Evento que guarda qual foi a interação do usuário, para que ele possa ser computado.
         */
        void handleEvent(sf::Event event);
        /**
         * @brief Responsável por limpar a tela com determinada cor.
         * 
         * @param color Nova cor utilizada para limpar a tela.
         */
        void clear(sf::Color color);
        /**
         * @brief Computa qual é o pixel da tela que corresponde as coordenadas do grid informadas.
         * 
         * @param x Coordenada do grid no eixo x.
         * @param y Coordenada do grid no eixo y.
         * @return Coordenadas dos pixels da tela correspondentes as coordenadas do grid.
         */
        std::pair<double, double> getPosition(double x, double y);
        /**
         * @brief Computa qual a coordenada do grid, em relação ao pixel informado.
         * 
         * @param x Coordenada x da tela em pixels.
         * @param y Coordenada y da tela em pixels.
         * @return Coordenadas do grid correspondentes as coordenadas da tela fornecidas.
         */
        std::pair<double, double> getCoordenate(double x, double y);

        /**
         * @brief Desenha todos os objetos do grid que estão visiveis na tela do usuário.
         * 
         */
        void drawObjects();
        
    protected:
        tgui::Widget::Ptr clone() const override;
    private:
        /**
         * @brief Coordenada x do mouse na tela, em pixels.
         */
        double mouseX;
        /**
         * @brief Coordenada y do mouse na tela, em pixels.
         */
        double mouseY;
        /**
         * @brief Controle sobre o botão esquerdo do mouse estar ou não clicado.
         */
        bool mouse;
        /**
         * @brief Abstração de uma janela sfml, local de desenho do grid. 
         */
        tgui::CanvasSFML::Ptr sfml;
        /**
         * @brief Representação da janela toda, incluindo itens fora do grid.
         */
        sf::RenderWindow& window;
        /**
         * @brief Controle sobre o Zoom In do Mouse.
         */
        double zoomIn = 1;
        /**
         * @brief Controle sobre o Zoom out do usuário.
         */
        double zoomOut = 1;
        /**
         * @brief Controle sobre o tipo de zoom atual.
         */
        bool tipoZoom=true;
        /**
         * @brief Controle da unidade de medida do grid.
         */
        Unit quadrado;
        /**
         * @brief Coordenada do eixo x do centro da tela no grid.
         */
        double centroX = 0;
        /**
         * @brief Coordenadas do eixo y do centro da tela no grid.
         */
        double centroY = 0;
        /**
         * @brief Desenha uma reta no grid a partir dos pontos fornecidos.
         * 
         * @param p1 Ponto inicial da reta.
         * @param p2 Ponto final da reta.
         */
        void drawLine(Point p1, Point p2);
        /**
         * @brief Desenha o background do grid, assim como as coordenadas.
         * 
         */
        void drawGraphBackground();
};

#endif