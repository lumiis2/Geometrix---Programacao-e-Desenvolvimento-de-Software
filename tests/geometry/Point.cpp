#include "doctest.h"
#include "Point.hpp"
#include <iostream>

TEST_CASE("Soma de Dois Pontos") {
    Point p(1,-1);
    Point q(1,1);
    Point r = p+q;
    CHECK((r.getX() == 2 and r.getY() == 0));
}

TEST_CASE("Diferença de Dois Pontos") {
    Point p(1,-1);
    Point q(1,1);
    Point r = p-q;
    CHECK((r.getX() == 0 and r.getY() == -2));
}

TEST_CASE("Multiplicação por Escalar") {
    Point p(5,-2);
    Point q = p*10;
    CHECK((q.getX() == 50 and q.getY() == -20));
}

TEST_CASE("Produto interno 1x vetor") {
    Point p(3,2);
    CHECK((p*p) == 13);
}

TEST_CASE("Produto interno 2x vetores") {
    Point p(1,-1);
    Point q(5,0);
    CHECK((p*q) == 5);
}

TEST_CASE("Operator ^") {
    Point p(5,2);
    Point q(3,1);
    CHECK((p^q) == -1);
}

TEST_CASE("Comparação entre dois pontos, p menor") {
    Point p(0,0);
    Point q(1,0);
    CHECK((p<q) == true);
}

TEST_CASE("Comparação entre dois pontos, p maior") {
    Point p(0,0);
    Point q(-2,0);
    CHECK((p<q) == false);
}

TEST_CASE("Comparação entre dois pontos, p menor pela segunda coordenada") {
    Point p(0,0);
    Point q(0,5);
    CHECK((p<q) == true);
}

TEST_CASE("Comparação entre dois pontos, p maior pela segunda coordenada") {
    Point p(0,0);
    Point q(0,-3);
    CHECK((p<q) == false);
}

TEST_CASE("Comparação entre dois pontos iguais") {
    Point p;
    Point q;
    CHECK((p<q) == false);
}

TEST_CASE("Comparação de igualdade verdadeira") {
    Point p;
    Point q;
    CHECK((p == q) == true);
}

TEST_CASE("Comparação de igualdade falsa") {
    Point p(1,0);
    Point q(3,2);
    CHECK((p == q) == false);
}

TEST_CASE("Comparação de igualdade falsa, pela segunda coordenada") {
    Point p(1,0);
    Point q(1,-1);
    CHECK((p == q) == false);
}

TEST_CASE("Retorno correto da função de nome") {
    Point p = Point();
    CHECK(p.name() == "Point");
}

TEST_CASE("Distância entre dois pontos") {
    Point p = Point();
    Point q(10,0);
    CHECK(p.distance(q) == 10.0);
}

TEST_CASE("Verificar se produto interno equivale ao quadrado do módulo do vetor") {
    Point p = Point();
    Point q(1,2);
    CHECK((p.distance(q) * p.distance(q)) - (q*q) <= 1e-4);
}

TEST_CASE("Verificar recebimento do tipo da entidade geométrica representativa") {
    Point *p = new Point(3,3);
    auto ans = p->getPoints();
    CHECK(ans[0]->name() == "Point");
}