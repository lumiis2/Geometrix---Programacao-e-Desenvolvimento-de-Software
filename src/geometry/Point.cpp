#include "Point.hpp"
#include "Utils.hpp"

Point::Point() : x(0), y(0) {};

Point::Point(double x, double y) : x(x), y(y) {};

Point Point::operator + (const Point& p) const {
    return Point(x+p.x, y+p.y);
}

Point Point::operator - (const Point& p) const {
    return Point(x-p.x, y-p.y);
}

Point Point::operator * (const double c) const {
    return Point(x*c, y*c);
}

double Point::operator * (const Point& p) const {
    return x*p.x + y*p.y;
}

double Point::operator ^ (const Point& p) const {
    return x*p.y - y*p.x;
}

bool Point::operator < (const Point& other) const {
    if (!utils::equal(x, other.getX())) return x < other.getX();
    if (!utils::equal(y, other.getY())) return y < other.getY();
    return 0;
}

bool Point::operator == (const Point& other) const {
    return x == other.getX() && y == other.getY();
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

std::vector<std::shared_ptr<Object>> Point::getPoints() {
    return std::vector<std::shared_ptr<Object>>(1, std::shared_ptr<Object>(this));
}

double Point::distance(const Object& other) const {
    std::string otherType = other.name();

    double dist;

    if (otherType == "Point") {
        Point *p = (Point *) &other;

        double ox = p->getX(), oy = p->getY();
        double dx = x - ox, dy = y - oy;

        dist = sqrt(dx * dx + dy * dy);
    } 
    else if (otherType == "Segment") {
        
        dist = other.distance(*this);
    }
    else {

        assert(otherType == "Polygon");

        dist = other.distance(*this);
    }

    return dist;
}

std::string Point::name() const {
    return "Point";
}
