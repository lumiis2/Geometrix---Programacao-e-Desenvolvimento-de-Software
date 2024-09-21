#include "Polygon.hpp"
#include "Utils.hpp"

Polygon::Polygon(std::vector<std::shared_ptr<Point>>& _vertices): vertices(_vertices) {
      if (_vertices.size() <= 2) throw std::runtime_error("Tentativa de criar poligono degenerado!");
}

double Polygon::area() const {
      double polArea = 0;
      for (int i = 0; i < (int)vertices.size(); i++) {
            polArea += utils::sarea(Point(0, 0), *vertices[i], *vertices[(i + 1) % vertices.size()]);
      }
      return fabs(polArea);
}

double Polygon::perimeter() const {
      double p = 0;

      for (int i = 0; i < (int) vertices.size(); ++i) {
            p += vertices[i]->distance(*vertices[(i+1) % ((int) vertices.size())]);
      }

      return p;
}

bool Polygon::has(Point p) {
    // TODO
    return true;
}

bool Polygon::isConvex() const {
    // TODO
    return true;
}

Polygon Polygon::operator + (const Polygon& other) const {

      std::vector<std::shared_ptr<Point>> v1 = vertices, v2 = other.getVertices();

      if (!isConvex() or !other.isConvex()) throw std::runtime_error("Tentativa de somar poligonos nao convexos");
      
      auto fix = [] (std::vector<std::shared_ptr<Point>>& P) {
            rotate(begin(P), std::min_element(begin(P), end(P)), end(P));
            P.push_back(P[0]), P.push_back(P[1]);
      };

      fix(v1), fix(v2);

      std::vector<std::shared_ptr<Point>> minkowskiSum;

      int i = 0, j = 0;

      while (i < (int)v1.size() - 2 or j < (int)v2.size() - 2) {
            Point sum = *v1[i] + *v2[j];
            minkowskiSum.push_back(std::shared_ptr<Point>(new Point(sum.getX(), sum.getY())));
            auto c = ((*v1[i+1] - *v1[i]) ^ (*v2[j+1] - *v2[j]));
            if (c >= 0) i = std::min<int>(i + 1, v1.size() - 2);
            if (c <= 0) j = std::min<int>(j + 1, v2.size() - 2);
      }

      return Polygon(minkowskiSum);
}

std::vector<std::shared_ptr<Point>> Polygon::getVertices() const {
      return vertices;
}

std::vector<std::shared_ptr<Object>> Polygon::getPoints() {
    std::vector<std::shared_ptr<Object>> points;
    for (auto point : vertices) {
        points.push_back(std::static_pointer_cast<Object>(point));
    }
    return points;
}

double Polygon::distance(const Object& other) const {
      std::string otherType = other.name();

      double dist = std::numeric_limits<double>::max();

      if (otherType == "Point") {

            Point *pt = (Point *) &other;

            int tot = 0;

            for (int i = 0; i < (int)vertices.size(); i++) {

                  if (*pt == *vertices[i]) dist = 0;

                  int j = (i + 1) % ((int) vertices.size());

                  Segment edge(vertices[i], vertices[j]);

                  if (pt->getY() == vertices[i]->getY() and pt->getY() == vertices[j]->getY()) {
                        if ((*vertices[i] - *pt) * (*vertices[j] - *pt) < utils::eps) return 0;
                        continue;
                  }

                  bool under = vertices[i]->getY() < pt->getY();

                  if (under == (vertices[j]->getY() < pt->getY())) continue;

                  double t = (*pt - *vertices[i]) ^ (*vertices[j] - *vertices[i]);
                  
                  if (utils::equal(t, 0)) return 0;

                  if (under == (t > 0)) tot += under ? 1 : -1;

                  dist = std::min(dist, edge.distance(*pt));
            }

            if (tot == 0) dist = 0;
      }
      else if (otherType == "Segment") {

            Segment *s = (Segment *) &other;

            for (int i = 0; i < (int) vertices.size(); i++) {
                  Segment t(vertices[i], vertices[(i+1) % ((int) vertices.size())]);
                  dist = std::min(dist, s->distance(t));
            }
      } else {
            
            assert(otherType == "Polygon");

            Polygon *poly = (Polygon *) &other;

            std::vector<std::shared_ptr<Point>> otherVertices = poly->getVertices();
            
            int n = vertices.size(), m = otherVertices.size();

            for (int i = 0; i < n; i++) {
                  for (int j = 0; j < m; j++) {
                        Segment s1(vertices[i], vertices[(i + 1) % n]), s2(otherVertices[j], otherVertices[(j + 1) % m]);
                        dist = std::min(dist, s2.distance(s2));
                  }
            }
      }

      return dist;
}

std::string Polygon::name() const {
    return "Polygon";
}