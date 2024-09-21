#include "Unit.hpp"

double Unit::getCoordenada(){
    return this->coordenadaQuadrado;
}

void Unit::setCoordenada(double x){
    this->coordenadaQuadrado = x;
}

double Unit::getLadoQuadrado(){
    return this->ladoQuadrado;
}

void Unit::setLadoQuadrado(double x){
    this->ladoQuadrado = x;
}

double Unit::getPixel(){
    return this->pixelQuadrado;
}
