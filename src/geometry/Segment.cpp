#include "Segment.hpp"
#include "Utils.hpp"

Segment::Segment(std::shared_ptr<Point> _p, std::shared_ptr<Point> _q) : p(_p), q(_q) {}

std::vector<std::shared_ptr<Object>> Segment::getPoints() {
    std::vector<std::shared_ptr<Object>> points;
    points.push_back(std::static_pointer_cast<Object>(p));
    points.push_back(std::static_pointer_cast<Object>(q));
    return points;
}

Point Segment::getP() {
    return *p;
}

Point Segment::getQ() {
    return *q;
}

bool Segment::has(Point pt) {
    Point a = *p - pt, b = *q - pt;
    return utils::equal((a ^ b), 0) and utils::equal(a * b, 0);
}

std::string Segment::name() const {
    return "Segment";
}

double Segment::width() const {
    Point P = *p, Q = *q;
    return P.distance(Q);
}

double Segment::distance(const Object& other) const {

    std::string otherType = other.name();

    double dist = std::numeric_limits<double>::max();

    if (otherType == "Point") {
        
        Point *pt = (Point *) &other;

        Point P = *p, Q = *q;

        if ((Q - P) * (*(pt) - P) < 0) return pt->distance(P);
        if ((P - Q) * (*(pt) - Q) < 0) return pt->distance(Q);

        dist = 2 * abs(utils::sarea(*(pt), P, Q)) / width();
        
        delete pt;
    } 
    else if (otherType == "Segment") {
        
        Segment *s = (Segment *) &other;

        Point P = *p, Q = *q, A = s->getP(), B = s->getQ();

        dist = std::min({distance(A), distance(B), s->distance(P), s->distance(Q)});
        
    } else {

        assert(otherType == "Polygon");

        dist = other.distance(*this);
    }

    return dist;

}