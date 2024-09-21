#include "Utils.hpp"

namespace utils {

      bool equal(long double a, long double b) {
            return fabs(a - b) <= eps;
      }

      long double sarea(Point p, Point q, Point r) {
            return ((q-p) ^ (r-q)) / 2;
      }

      bool collinear(Point p, Point q, Point r) {
            return equal(sarea(p, q, r), 0);
      }

      bool ccw(Point p, Point q, Point r) {
            return sarea(p, q, r) > eps;
      }

      int quad(Point p) {
            return (p.getX() < 0) ^ 3 * (p.getY() < 0);
      };

      std::vector<std::shared_ptr<Point>> decomposeObjects(std::vector<std::shared_ptr<Object>>& objects) {
            std::vector<std::shared_ptr<Point>> points;

            for (auto obj : objects) {
                std::vector<std::shared_ptr<Object>> objPoints = obj->getPoints();
                for (auto p : objPoints) {
                      points.push_back(std::dynamic_pointer_cast<Point>(p));
                }
            }

            return points;
      }

      std::shared_ptr<Polygon> convexHull(std::vector<std::shared_ptr<Object>>& objects) {

            std::vector<std::shared_ptr<Point>> points = decomposeObjects(objects);

            std::sort(begin(points), end(points), [](const std::shared_ptr<Point> a, const std::shared_ptr<Point> b) {
                    return (*a) < (*b);
            });
            
            points.erase(unique(begin(points), end(points)), end(points));
          
            std::vector<std::shared_ptr<Point>> lowerHull, upperHull;

            for (int i = 0; i < (int) points.size(); ++i) {
                  while (lowerHull.size() > 1 and !ccw(*lowerHull.end()[-2], *lowerHull.end()[-1], *points[i]))
                        lowerHull.pop_back();
                  lowerHull.push_back(points[i]);
            }
            
            for (int i = (int) points.size() - 1; i >= 0; --i) {
                  while (upperHull.size() > 1 and !ccw(*upperHull.end()[-2], *upperHull.end()[-1], *points[i]))
                        upperHull.pop_back();
                  upperHull.push_back(points[i]);
            }

            lowerHull.pop_back(), upperHull.pop_back();
             
            for (auto pt : upperHull) lowerHull.push_back(pt);

            if (lowerHull.size() < 3)
                throw std::runtime_error("Fecho convexo com menos de 3 vértices");

            return std::shared_ptr<Polygon>(new Polygon(lowerHull));
      }

      std::shared_ptr<Polygon> boundingBox(std::vector<std::shared_ptr<Object>>& objects) {
            std::vector<std::shared_ptr<Point>> points = decomposeObjects(objects);

            // points pode ser vazio?
            double minX = points[0]->getX(), minY = points[0]->getY(), maxX = minX, maxY = minY;
            
            for (auto pt : points) {
                  double x = pt->getX(), y = pt->getY();
                  minX = std::min(minX, x), maxX = std::max(maxX, x);
                  minY = std::min(minY, y), maxY = std::max(maxY, y);
            }

            std::vector<std::shared_ptr<Point>> box;

            box.push_back(std::shared_ptr<Point>(new Point(minX, minY)));
            box.push_back(std::shared_ptr<Point>(new Point(minX, maxY)));
            box.push_back(std::shared_ptr<Point>(new Point(maxX, maxY)));
            box.push_back(std::shared_ptr<Point>(new Point(maxX, minY)));

            // TO DO
            // tratar o caso quando minx = maxx ou miny = maxy (bounding box vai ser segmento de reta ou ponto)
            return std::shared_ptr<Polygon>(new Polygon(box));
      }

      bool intersects(Segment s, Segment t) {
            if (t.has(s.getP()) or t.has(s.getQ()) or s.has(t.getP()) or s.has(t.getQ())) return true;

            return utils::ccw(t.getP(), t.getQ(), s.getP()) != utils::ccw(t.getP(), t.getQ(), s.getQ());
      }

      bool polyIntersect(const Polygon& p1, const Polygon& p2) {
            return p1.distance(p2) == 0;
      }

}
