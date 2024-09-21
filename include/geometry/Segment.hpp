#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Object.hpp"
#include "Point.hpp"

/**
 * @brief Classe para representar um segmento no plano (tipo especializado de Object).
 */
class Segment : public Object {
    public:

        /**
         * @brief Construtor que inicializa um segmento através de um par de pontos especificado.
         * @param _p 1º ponto a compor o segmento construído.
         * @param _q 2º ponto a compor o segmento construído.
         */
        Segment(std::shared_ptr<Point> _p, std::shared_ptr<Point> _q);

        /**
         * @brief Verifica se um ponto pertence ao segmento.
         * @param p Ponto a ser verificada a relação de pertinência.
         * @return Se o ponto pertence ao segmento.
         */
        bool has(Point p);

        /**
         * @brief Obtém o 1º ponto que compõe o segmento.
         * @return 1º ponto que compõe o segmento.
         */
        Point getP();

        /**
         * @brief Obtém o 2º ponto que compõe o segmento.
         * @return 2º ponto que compõe o segmento.
         */
        Point getQ();

        /**
         * @brief Calcula a largura do segmento.
         * @return Largura do segmento calculada.
         */
        double width() const;

        /**
         * @brief Implementação do método virtual puro da classe base.
         * @return Vetor que possui o par de entidades (pontos) que compõem o segmento.
         */
        std::vector<std::shared_ptr<Object>> getPoints() override;

        /**
         * @brief Implementação do método virtual puro da classe base. 
         * @param other Entidade geométrica que deseja-se calcular a distância no plano com relação ao segmento.
         * @return Comprimento da distância calculada.
         */
        double distance(const Object& other) const override;

        /**
         * @brief Implementação do método virtual puro da classe base.
         * @return Informa que a entidade geométrica é do tipo "Segment".
         */
        std::string name() const override;

        /**
         * @brief Destrutor padrão.
         */
        ~Segment() = default;
    
    private:

        /**
         * @brief Par de pontos que compõem o polígono.
         */
        std::shared_ptr<Point> p, q;
};

#endif
