#include "Canvas.hpp"
#include <cmath>
#include <utility>
#include "State.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "Polygon.hpp"
using namespace std;

Canvas::Ptr Canvas::create(sf::RenderWindow& window) {
    return std::make_shared<Canvas>(window);
}

Canvas::Ptr Canvas::copy(Canvas::ConstPtr widget) {
    if (widget) return std::static_pointer_cast<Canvas>(widget->clone());
    else return nullptr;
}

tgui::Widget::Ptr Canvas::clone() const {
    return std::make_shared<Canvas>(*this);
}

Canvas::Canvas(sf::RenderWindow& window) : window(window) {
    sfml = tgui::CanvasSFML::create();
    this->add(sfml);
    mouse = false;
}

void Canvas::clear(sf::Color color) {
    sfml->clear(color);
}

void Canvas::handleEvent(sf::Event event) {
    sf::Vector2i position = sf::Mouse::getPosition(window);
    if (event.type == sf::Event::MouseButtonPressed and position.x >= sfml->getPosition().x
    and position.y >= sfml->getPosition().y){
        updateMouse(position.x, position.y); 
        mouse = true;
    }

    if (event.type == sf::Event::MouseButtonReleased || position.x < sfml->getPosition().x || position.y < sfml->getPosition().y)
        mouse = false; 

    if (event.type == sf::Event::MouseWheelScrolled){
        update(event);
    }
    
    if (event.type == sf::Event::MouseMoved and mouse){
        update(event); 
    }
}

Canvas::~Canvas() { }

void Canvas::updateMouse(double x, double y) {
    this->mouseX = x;
    this->mouseY = y;
}

void Canvas::update(sf::Event event){

    sf::Vector2i position = sf::Mouse::getPosition(this->window);
    if(event.type == sf::Event::MouseWheelScrolled and position.x > this->window.getSize().x*0.25) {
        if(this->tipoZoom){
            this->zoomIn += event.mouseWheelScroll.delta/20;
            if(zoomIn<1){ zoomIn=1; this->tipoZoom = false; }
            this->quadrado.setLadoQuadrado(1 + fmod(this->zoomIn, 1));
            this->quadrado.setCoordenada(1.0/pow(2, floor(this->zoomIn-1)));
        } else {
            this->zoomOut -= event.mouseWheelScroll.delta/20;
            if(zoomOut<1){ zoomOut=1; this->tipoZoom = true;}
            this->quadrado.setLadoQuadrado(2 - fmod(this->zoomOut, 1));
            this->quadrado.setCoordenada(pow(2, floor(this->zoomOut)));
        }
        
        position = sf::Mouse::getPosition(this->window);
        position.x -= this->window.getSize().x * 0.25;
        pair<double ,double> pos = this->getCoordenate(position.x, position.y);
        if(event.mouseWheelScroll.delta>0){
            this->centroX += (pos.first-centroX)*0.05;
            this->centroY += (pos.second-centroY)*0.05;
        }else {
            this->centroX -= (pos.first-centroX)*0.05;
            this->centroY -= (pos.second-centroY)*0.05;
        }
    }
    
    if(event.type == sf::Event::MouseMoved and position.x >= this->window.getSize().x*0.25){
        this->centroX += (this->mouseX-event.mouseMove.x)/(this->quadrado.getPixel()*this->quadrado.getLadoQuadrado()/this->quadrado.getCoordenada());
        this->centroY += (event.mouseMove.y-this->mouseY)/(this->quadrado.getPixel()*this->quadrado.getLadoQuadrado()/this->quadrado.getCoordenada());
        this->mouseX=event.mouseMove.x;  
        this->mouseY=event.mouseMove.y;
    }
}

void Canvas::draw(){
    this->drawGraphBackground();
    this->drawObjects();
    this->sfml->display();
}


void Canvas::drawGraphBackground(){
    double max = 50;
    std::pair<double, double> coordenates = this->getPosition(this->centroX - fmod(this->centroX, this->quadrado.getCoordenada()), this->centroY - fmod(this->centroY, this->quadrado.getCoordenada()));
    auto cor = sf::Color(128,128,128);
    
    sf::Font font;
    font.loadFromFile("arial.ttf");
    pair<double, double> cent = this->getPosition(0, 0);

    for(int i = -max; i < max; i++){
        sf::RectangleShape line(sf::Vector2f(1, this->window.getSize().y));
        line.setFillColor(cor);
        line.setPosition(coordenates.first+this->quadrado.getLadoQuadrado()*this->quadrado.getPixel()*i, 0);
        this->sfml->draw(line);

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(10); 
        text.setFillColor(sf::Color::Black);
        text.setPosition(coordenates.first+this->quadrado.getLadoQuadrado()*this->quadrado.getPixel()*i+3, std::min(this->getSize().y-20.0, cent.second+7));

        string temp;
        stringstream outStream;
        pair<double, double> coordenadas = this->getCoordenate(coordenates.first+this->quadrado.getLadoQuadrado()*this->quadrado.getPixel()*i, 0);
        if(std::abs(coordenadas.first) <= 0.00001) coordenadas.first = 0;
        outStream << coordenadas.first;
        temp = outStream.str();
        text.setString(temp);
        
        this->sfml->draw(text);
    }

    for(int i = -max; i < max; i++){
        sf::RectangleShape line(sf::Vector2f(this->window.getSize().x, 1));
        line.setFillColor(cor);
        line.setPosition(0, coordenates.second - this->quadrado.getLadoQuadrado()*this->quadrado.getPixel()*i);
        this->sfml->draw(line);

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(10); 
        text.setFillColor(sf::Color::Black);
        
        text.setPosition(std::max(cent.first+7, 10.0), coordenates.second - this->quadrado.getLadoQuadrado()*this->quadrado.getPixel()*i);

        string temp;
        stringstream outStream;
        pair<double, double> coordenadas = this->getCoordenate(0, coordenates.second - this->quadrado.getLadoQuadrado()*this->quadrado.getPixel()*i);
        outStream << coordenadas.second;
        temp = outStream.str();
        if(abs(coordenadas.second)>0.0001)text.setString(temp);
        
        this->sfml->draw(text);

        pair<double, double> cent = this->getPosition(0, 0);

        sf::RectangleShape lin(sf::Vector2f(this->sfml->getSize().x,2));
        lin.setFillColor(sf::Color::Black);
        lin.setPosition(0 , cent.second);
        this->sfml->draw(lin);

        sf::RectangleShape li(sf::Vector2f(2, this->sfml->getSize().y));
        li.setFillColor(sf::Color::Black);
        li.setPosition(cent.first, 0);
        this->sfml->draw(li);
    }
}

std::pair<double, double> Canvas::getPosition(double x, double y){
    double razao = (this->quadrado.getLadoQuadrado()*this->quadrado.getPixel())/this->quadrado.getCoordenada();
    pair<double, double> ans;
    ans.first = this->sfml->getSize().x/2 - (this->centroX-x)*razao;
    ans.second = this->sfml->getSize().y/2 + (this->centroY-y)*razao;
    return ans;
}

std::pair<double, double> Canvas::getCoordenate(double x, double y){
    double razao = (this->quadrado.getLadoQuadrado()*this->quadrado.getPixel())/this->quadrado.getCoordenada();
    pair<double, double> ans;
    ans.first = (x-this->sfml->getSize().x/2)/razao + this->centroX;
    ans.second = this->centroY - (y-this->sfml->getSize().y/2)/razao;
    return ans;
}

void Canvas::drawObjects(){
    std::vector<std::pair<size_t, std::shared_ptr<Object>>> objects = State::getInstance().getObjects();
    for(int i = 0; i < (int)objects.size(); i++){
        if(objects[i].second->name() == "Segment"){
            std::shared_ptr<Segment> reta = std::dynamic_pointer_cast<Segment>(objects[i].second);
            this->drawLine(reta->getP(), reta->getQ());
        }

        if(objects[i].second->name() == "Point"){
            std::shared_ptr<Point> point = std::dynamic_pointer_cast<Point>(objects[i].second);
            pair<double, double> p = this->getPosition(point->getX(), point->getY());
            double tam;
            tam = 4-std::min(4.0,this->zoomOut);
            sf::CircleShape circle(tam);
            circle.setFillColor(sf::Color::Black);
            circle.setPosition(p.first-tam, p.second-tam);
            this->sfml->draw(circle);
        }

        if(objects[i].second->name() == "Polygon"){
            std::vector<shared_ptr<Object>> points =  objects[i].second->getPoints();
            int tam = (int)points.size();
            for(int i = 0; i < tam; i++){
                std::shared_ptr<Point> p = std::dynamic_pointer_cast<Point>(points.at(i));
                std::shared_ptr<Point> q = std::dynamic_pointer_cast<Point>(points.at((i+1)%tam));
                drawLine(*p.get(), *q.get());
            }
        }

    }
}

void Canvas::drawLine(Point p1, Point p2){
    
    std::pair<double, double> p = this->getPosition(p1.getX(), p1.getY());
    std::pair<double, double> q = this->getPosition(p2.getX(), p2.getY());
    if(p.first > q.first) swap(p, q);
            
    double dist = std::sqrt(std::pow( std::abs(p.first - q.first),2) + std::pow(std::abs(p.second - q.second) ,2));
    sf::RectangleShape li(sf::Vector2f(dist, 2));
    li.setFillColor(sf::Color::Black);
    li.setPosition(p.first, p.second);
    double co = p1.getY() - p2.getY();
    double ca = p1.getX() - p2.getX();
    
    if(p.first == q.first) li.rotate(atan((co/ca)) * (180/M_PI));
    else li.rotate(-atan((co/ca)) * (180/M_PI));
    
    this->sfml->draw(li);
}