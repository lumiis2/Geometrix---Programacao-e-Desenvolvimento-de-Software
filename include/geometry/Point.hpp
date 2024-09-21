#ifndef POINT_HPP
#define POINT_HPP

#include "Object.hpp"

/**
 * @brief Classe para representar um ponto no plano (tipo especializado de Object).
 */
class Point : public Object {
    public:

        /**
         * @brief Construtor padrão que inicializa um ponto na origem.
         */
        Point();

        /**
         * @brief Construtor que inicializa um ponto com coordenadas especificadas.
         * @param x Coordenada x do ponto.
         * @param y Coordenada y do ponto.
         */
        Point(double x, double y);

        /**
         * Realiza a adição de dois pontos, através da soma vetorial entre suas coordenadas x e y.
         * @brief Sobrecarga do operador de adição para pontos.
         * @param other Ponto a ser somado com o ponto atual.
         * @return Ponto resultante da operação de soma.
         */
        Point operator + (const Point& other) const;

        /**
         * Realiza a subtração de dois pontos, através da diferença vetorial entre suas coordenadas x e y.
         * @brief Sobrecarga do operador de subtração para pontos.
         * @param other Ponto a ser descontado do ponto atual.
         * @return Ponto resultante da operação de diferença.
         */
        Point operator - (const Point& other) const;

        /**
         * Realiza o produto entre um escalar e as coordenadas x e y do ponto atual.
         * @brief Sobrecarga do operador de multiplicação para ponto e escalar.
         * @param c Escalar a ser multiplicado pelo ponto atual.
         * @return Ponto resultante da operação de multiplicação por escalar.
         */
        Point operator * (const double c) const;

        /**
         * Realiza o produto interno entre dois pontos (vetores).
         * @brief Sobrecarga do operador de multiplicação para pontos.
         * @param other Ponto a ser calculado o produto interno com o ponto atual.
         * @return Escalar resultante da operação de produto interno entre dois vetores.
         */
        double operator * (const Point& other) const;

        /** ??
         * @brief 
         * @param other 
         * @return double 
         */
        double operator ^ (const Point& other) const;

        /**
         * Compara dois pontos e determina se um é menor que o outro com base em suas coordenadas x e y.
         * @brief Sobrecarga do operador de "menor que" para pontos.
         * @param other Ponto a ser comparado com o ponto atual.
         * @return Se o ponto atual é menor que o ponto comparado.
         */
        bool operator < (const Point& other) const;

        /**
         * Compara dois pontos e determina se são iguais com base em suas coordenadas x e y.
         * @brief Sobrecarga do operador de equivalência para pontos.
         * @param other Ponto a ser comparado com o ponto atual.
         * @return Se os pontos comparados são iguais.
         */
        bool operator == (const Point& other) const;

        /**
         * @brief Obtém a coordenada x do ponto.
         * @return Coordenada x do ponto.
         */
        double getX() const;

        /**
         * @brief Obtém a coordenada y do ponto.
         * @return Coordenada y do ponto.
         */
        double getY() const;
        
        /**
         * @brief Implementação do método virtual puro da classe base.
         * @return Vetor que possui a entidade (ponto) que representa o objeto atual.
         */
        std::vector<std::shared_ptr<Object>> getPoints() override;

        /**
         * @brief Implementação do método virtual puro da classe base. 
         * @param other Entidade geométrica que deseja-se calcular a distância no plano com relação ao ponto.
         * @return Comprimento da distância calculada.
         */
        double distance(const Object& other) const override;

        /**
         * @brief Implementação do método virtual puro da classe base.
         * @return Informa que a entidade geométrica é do tipo "Point".
         */
        std::string name() const override;
        
        /**
         * @brief Destrutor padrão.
         */
        ~Point() = default;
        
    private:

        /**
         * @brief Coordenadas x e y que representam o ponto no plano.
         */
        double x, y;
};

#endif