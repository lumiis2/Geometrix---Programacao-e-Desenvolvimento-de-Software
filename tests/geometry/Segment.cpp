#include "doctest.h"
#include "Segment.hpp"
#include "Point.hpp"
#include "Utils.hpp"
#include "Polygon.hpp"

TEST_CASE("teste da primeira coordenada do segment") {
    std::shared_ptr<Point> p = std::shared_ptr<Point>(new Point(1, 2));
    std::shared_ptr<Point> q = std::shared_ptr<Point>(new Point(2, 2));
    Segment *s = new Segment(p, q);
    bool teste = s->getP().getX() == p->getX() and s->getP().getY() == p->getY();
    CHECK(teste);
}

TEST_CASE("Teste da segunda coordenada do segment") {
    std::shared_ptr<Point> p = std::shared_ptr<Point>(new Point(5, 9));
    std::shared_ptr<Point> q = std::shared_ptr<Point>(new Point(1, 0));
    Segment *s = new Segment(p, q);
    bool teste = s->getQ().getX() == q->getX() and s->getQ().getY() == q->getY();
    CHECK(teste);
}

TEST_CASE("Decomposição em pontos") {
    std::shared_ptr<Point> p = std::shared_ptr<Point>(new Point(10, 16.5));
    std::shared_ptr<Point> q = std::shared_ptr<Point>(new Point(13, 19.5));
    Segment *s = new Segment(p, q);
    std::vector<std::shared_ptr<Object>> pts = s->getPoints();
    bool teste = std::dynamic_pointer_cast<Point>(pts[0]) == p and std::dynamic_pointer_cast<Point>(pts[1]) == q;
    CHECK(teste);
}


TEST_CASE("Teste de nome do segmento") {
    std::shared_ptr<Point> p = std::shared_ptr<Point>(new Point(0, 0));
    std::shared_ptr<Point> q = std::shared_ptr<Point>(new Point(7, 7));
    Segment *s = new Segment(p, q);
    CHECK(s->name() == "Segment");
}

TEST_CASE("Teste de comprimento do segmento") {
    std::shared_ptr<Point> p = std::shared_ptr<Point>(new Point(0, 0));
    std::shared_ptr<Point> q = std::shared_ptr<Point>(new Point(3, 4));
    Segment *s = new Segment(p, q);
    CHECK((s->width()-5) <= utils::eps);
}

TEST_CASE("Polígono Degenerado") {
    std::vector<std::shared_ptr<Point>> _vertices;
    std::shared_ptr<Point> p = std::make_shared<Point>(1, 2);
    std::shared_ptr<Point> q = std::make_shared<Point>(2, 3);

    _vertices.push_back(p);
    _vertices.push_back(q);

    CHECK_THROWS_AS(Polygon(_vertices), std::runtime_error);
}