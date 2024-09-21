#include "../doctest.h"
#include "../../include/geometry/Polygon.hpp"
#include "../../include/geometry/Utils.hpp"

TEST_CASE("Polígono Degenerado") {
    std::vector<std::shared_ptr<Point>> _vertices;
    std::shared_ptr<Point> p = std::make_shared<Point>(1, 2);
    std::shared_ptr<Point> q = std::make_shared<Point>(2, 3);

    _vertices.push_back(p);
    _vertices.push_back(q);

    CHECK_THROWS_AS(Polygon a = Polygon(_vertices), std::runtime_error);
}

TEST_CASE("Polígono Degenerado") {
    std::vector<std::shared_ptr<Point>> _vertices;
    std::shared_ptr<Point> p = std::make_shared<Point>(1, 1);
    std::shared_ptr<Point> q = std::make_shared<Point>(2, 2);
    std::shared_ptr<Point> r = std::make_shared<Point>(1, 2);

    _vertices.push_back(p);
    _vertices.push_back(q);
     _vertices.push_back(r);
    Polygon s = Polygon(_vertices);

    CHECK((s.area() - 0.5) <= utils::eps);
}

TEST_CASE("Área de Poligono") {
    std::vector<std::shared_ptr<Point>> _vertices;
    std::shared_ptr<Point> p = std::make_shared<Point>(1, 1);
    std::shared_ptr<Point> q = std::make_shared<Point>(2, 2);
    std::shared_ptr<Point> r = std::make_shared<Point>(1, 2);

    _vertices.push_back(p);
    _vertices.push_back(q);
     _vertices.push_back(r);
    Polygon s = Polygon(_vertices);

    CHECK((s.area() - 0.5) <= utils::eps);
}

TEST_CASE("Perímetro de poligono") {
    std::vector<std::shared_ptr<Point>> _vertices;
    std::shared_ptr<Point> p = std::make_shared<Point>(1, 1);
    std::shared_ptr<Point> q = std::make_shared<Point>(2, 2);
    std::shared_ptr<Point> r = std::make_shared<Point>(1, 2);

    _vertices.push_back(p);
    _vertices.push_back(q);
     _vertices.push_back(r);
    Polygon s = Polygon(_vertices);

    CHECK((s.perimeter() - (2+std::sqrt(2))) <= utils::eps);
}

TEST_CASE("Nome do poligono") {
    std::vector<std::shared_ptr<Point>> _vertices;
    std::shared_ptr<Point> p = std::make_shared<Point>(1, 1);
    std::shared_ptr<Point> q = std::make_shared<Point>(2, 2);
    std::shared_ptr<Point> r = std::make_shared<Point>(1, 2);
    _vertices.push_back(p);
    _vertices.push_back(q);
     _vertices.push_back(r);
    Polygon s = Polygon(_vertices);

    CHECK(s.name() == "Polygon");
}

TEST_CASE("Retorno de vértices") {
    std::vector<std::shared_ptr<Point>> _vertices;
    std::shared_ptr<Point> p = std::make_shared<Point>(1, 1);
    std::shared_ptr<Point> q = std::make_shared<Point>(2, 2);
    std::shared_ptr<Point> r = std::make_shared<Point>(1, 2);
    _vertices.push_back(p);
    _vertices.push_back(q);
     _vertices.push_back(r);
    Polygon s = Polygon(_vertices);
    std::vector<std::shared_ptr<Point>> v = s.getVertices();
    bool teste = (p == v[0] and q == v[1] and r == v[2]);
    CHECK(teste);
}

TEST_CASE("Teste de ponto contido em um poligono") {
    std::vector<std::shared_ptr<Point>> _vertices;
    std::shared_ptr<Point> p = std::make_shared<Point>(1, 1);
    std::shared_ptr<Point> q = std::make_shared<Point>(2, 2);
    std::shared_ptr<Point> r = std::make_shared<Point>(1, 2);
    _vertices.push_back(p);
    _vertices.push_back(q);
     _vertices.push_back(r);
    Polygon s = Polygon(_vertices);
    bool teste = (s.has(Point(1.5, 1.5)));
    CHECK(teste);
}

