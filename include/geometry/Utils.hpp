#ifndef UTILS_HPP
#define UTILS_HPP

#include "Object.hpp"
#include "Point.hpp"
#include "Polygon.hpp"
#include <vector>
#include <algorithm>


/**
 * @namespace utils
 * @brief Namespace contendo funções utilitárias de geometria computacional
 */
namespace utils {

    /**
     * @brief Constante epsilon para estabelecer um limite de tolerância ao comparar números de ponto flutuante (intervalo de erro aceitável).
     */
    const long double eps = 1e-4;

    /**
     * @brief Verifica se dois números de ponto flutuante são iguais dado o limite de tolerância.
     * @param a Número de ponto flutuante a ser comparado.
     * @param b Número de ponto flutuante a ser comparado.
     * @return Se os números são equivalentes.
     */
    bool equal(long double a, long double b);

    /**
     * @brief
     * @param p 
     * @param q 
     * @param r 
     * @return  
     */
    long double sarea(Point p, Point q, Point r);

    /**
     * @brief Verifica se três pontos são colineares entre si.
     * @param p Ponto a ser verificado.
     * @param q Ponto a ser verificado.
     * @param r Ponto a ser verificado.
     * @return Se os três pontos pertencem a mesma linha.
     */
    bool collinear(Point p, Point q, Point r);

    /**
     * @brief Verifica se a orientação de três pontos no plano está no sentido anti-horário 
     * @param p Ponto a ser verificado.
     * @param q Ponto a ser verificado.
     * @param r Ponto a ser verificado.
     * @return Se os pontos estão dispostos no sentido anti-horário.
     */
    bool ccw(Point p, Point q, Point r);

    /**
     * @brief 
     * 
     * @param p 
     * @return 
     */
    int quad(Point p);

    /**
     * @brief Decompõe um conjunto de entidades geométricas em um conjunto de pontos suficientes para representá-las.
     * @param objects Conjunto de entidades geométricas a ser decomposta.
     * @return Conjunto de pontos resultante da decomposição.
     */
    std::vector<std::shared_ptr<Point>> decomposeObjects(std::vector<std::shared_ptr<Object>>& objects);

    /**
     * @brief Calcula a convex hull de um conjunto de entidades geométricas.
     * @param objects Conjunto de entidades geométricas a se calcular a convex hull.
     * @return Polígono que representa a convex hull calculada.
     */
    std::shared_ptr<Polygon> convexHull(std::vector<std::shared_ptr<Object>>& objects);

    /**
     * @brief Calcula a bounding box de um conjunto de entidades geométricas.
     * @param objects Conjunto de entidades geométricas a se calcular a bounding box.
     * @return Polígono que representa a bounding box calculada.
     */
    std::shared_ptr<Polygon> boundingBox(std::vector<std::shared_ptr<Object>>& objects);

    /**
     * @brief Verifica se dois segmentos se interceptam em um ponto.
     * @param s Segmento a ser verificado.
     * @param T Segmento a ser verificado.
     * @return Se ambos os segmentos possuem interseção não vazia entre si.
     */
    bool intersects(Segment s, Segment T);

    /**
     * @brief Verifica se dois polígonos se interceptam em um ponto.
     * @param p1 Polígono a ser verificado.
     * @param p2 Polígono a ser verificado.
     * @return Se ambos os polígonos possuem interseção não vazia entre si.
     */
    bool polyIntersect(const Polygon& p1, const Polygon& p2);
};

#endif
