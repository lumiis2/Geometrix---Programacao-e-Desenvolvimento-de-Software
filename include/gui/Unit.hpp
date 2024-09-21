#ifndef UNIDADE_HPP
#define UNIDADE_HPP


/**
 * @brief Representa a unidade do grid, é a representação computacional dos quadrados que definem o grid.
 */
class Unit {
    public:
        /**
         * @brief Obtém quantas coordenadas uma unidade do grid representa.
         * 
         * @return Quantidade, em coordenadas, que uma únidade do grid representa.
         */
        double getCoordenada();
        /**
         * @brief Atualiza quantas coordenadas representam uma unidade.
         * 
         * @param x Nova coordenada para a únidade.
         */
        void setCoordenada(double x);
        /**
         * @brief Obtém o fator multiplicativo que define o tamanho da unidade.
         * 
         * @return fator multiplicativo da unidade.
         */
        double getLadoQuadrado();
        /**
         * @brief Atualiza o fator multiplicativo da unidade.
         * 
         * @param x O novo fator multiplicativo da unidade.
         */
        void setLadoQuadrado(double x);
        /**
         * @brief Obtém quantos pixels da tela uma unidade tem.
         * 
         * @return Quantidade de pixels representada por um quadrado, com o menor fator multiplicativo.
         */
        double getPixel();

    private:
        /**
         * @brief Quantidade de coordenadas representada por uma unidade.
         * 
         */
        double coordenadaQuadrado = 1;
        /**
         * @brief Fator multiplicativo para definir o tamanho do quadrado.
         * 
         */
        double ladoQuadrado = 1;
        /**
         * @brief Quantidade de pixels que um quadrado representa, com o menor fator multiplicativo.
         * 
         */
        double pixelQuadrado = 40;
    
};

#endif 