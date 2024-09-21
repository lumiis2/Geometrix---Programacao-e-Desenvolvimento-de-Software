#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Object.hpp"
#include "Point.hpp"
#include "Segment.hpp"

/**
 * @brief Classe para representar um polígono no plano (tipo especializado de Object).
 */
class Polygon : public Object {
    public:

        /**
         * @brief Construtor que inicializa um polígono através de um conjunto de pontos especificado.
         * @param _generatorPoints Vetor de pontos para compor o polígono construído.
         */
        Polygon(std::vector<std::shared_ptr<Point>>& _generatorPoints);

        /**
         * @brief Calcula a área do polígono.
         * @return Área do polígono.
         */
        double area() const;

        /**
         * @brief Calcula o perímetro do polígono.
         * @return Perímetro do polígono.
         */
        double perimeter() const;

        /**
         * @brief Verifica se um ponto pertence ao polígono.
         * @param p Ponto a ser verificada a relação de pertinência.
         * @return Se ponto pertence ao polígono.
         */
        bool has(Point p);

        /**
         * @brief Verifica se o polígono é convexo.
         * @return Se o polígono é convexo.
         */
        bool isConvex() const;

        /**
         * Calcula a soma de Minkowski entre dois polígonos.
         * @brief Sobrecarga do operador de adição para polígonos.
         * @param other Polígono a ser combinado com o polígono atual.
         * @return Polígono resultante da operação de adição de Minkowski. 
         */
        Polygon operator + (const Polygon& other) const;


        /**
         * @brief Obtém o conjunto de pontos (vértices) suficientes para representar o objeto atual.
         * @return Vetor que possui o conjunto de pontos (vértices) que compõem o polígono.
         */
        std::vector<std::shared_ptr<Point>> getVertices() const;

        /**
         * @brief Implementação do método virtual puro da classe base.
         * @return Vetor que possui o conjunto de entidades (pontos) que compõem o polígono.
         */
        std::vector<std::shared_ptr<Object>> getPoints();

        /**
         * @brief Implementação do método virtual puro da classe base. 
         * @param other Entidade geométrica que deseja-se calcular a distância no plano com relação ao polígono.
         * @return Comprimento da distância calculada.
         */
        double distance(const Object& other) const;

        /**
         * @brief Implementação do método virtual puro da classe base.
         * @return Informa que a entidade geométrica é do tipo "Polygon".
         */
        std::string name() const;

        /**
         * @brief Destrutor padrão.
         */
        ~Polygon() = default;
        
    private:

        /**
         * @brief Vetor que armazena o conjunto de pontos (vértices) que compõem o polígono.
         */
        std::vector<std::shared_ptr<Point>> vertices;
};

#endif
