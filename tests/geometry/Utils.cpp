#include "doctest.h"
#include "Utils.hpp"

using namespace utils;

TEST_CASE("Igualdade com precisão") {
    CHECK(equal(1.0, 1.000000001));
    CHECK_FALSE(equal(1.0, 2.0));
}

TEST_CASE("Desigualdade com precisão") {
    CHECK(!equal(1.0, 1.1));
}

TEST_CASE("Verificar se pontos são colineares") {
    Point p1(0, 0), p2(1, 1), p3(2, 2);
    CHECK(collinear(p1, p2, p3));
}

TEST_CASE("Verificar se pontos não são colineares") {
    Point p1(0, 0), p2(2, 1), p3(2, 2);
    CHECK(!collinear(p1, p2, p3));
}

TEST_CASE("Verificar pontos no sentido anti-horário") {
    Point p1(0, 0), p2(1, 1), p3(1, 2);
    CHECK(ccw(p1, p2, p3));
}


TEST_CASE("Verificar pontos no sentido anti-horário") {
    Point p1(0, 0), p2(1, -1), p3(0, -2);
    CHECK(!ccw(p1, p2, p3));
}

TEST_CASE("Função Quad 1.0") {
    Point p1(-1, -1);
    CHECK(quad(p1) == 2);
}

TEST_CASE("Função Quad 2.0") {
    Point p2(1, 1);
    CHECK(quad(p2) == 0);
}

TEST_CASE("Interseção positiva de dois segmentos") {
    Segment s1(std::shared_ptr<Point>(new Point(0,0)), std::shared_ptr<Point>(new Point(1,1)));
    Segment s2(std::shared_ptr<Point>(new Point(1,0)), std::shared_ptr<Point>(new Point(0,1)));
    CHECK(intersects(s1, s2));
}

TEST_CASE("Interseção negativa de dois segmentos") {
    Segment s1(std::shared_ptr<Point>(new Point(0,0)), std::shared_ptr<Point>(new Point(1,1)));
    Segment s2(std::shared_ptr<Point>(new Point(1,0)), std::shared_ptr<Point>(new Point(2,1)));
    CHECK(!intersects(s1, s2));
}
