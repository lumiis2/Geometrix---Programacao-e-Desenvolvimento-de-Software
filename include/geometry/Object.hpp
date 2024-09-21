#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <limits>
#include <memory>
#include <algorithm>
#include <vector>
#include <set>

/**
 * @brief Interface concebida para definir operações padrões para as entidades geométricas.
 */
class Object {
    public:

      /**
       * @brief Obtém o conjunto de outras entidades geométricas suficientes para representar o objeto atual.
       * @return Vetor de entidades geométricas que compõem o objeto atual.
       */
      virtual std::vector<std::shared_ptr<Object>> getPoints() = 0;

      /**
       * @brief Calcula a distância euclidiana entre o objeto atual e outra entidade geométrica.
       * @param other Entidade geométrica que deseja-se calcular a distância no plano com relação ao objeto atual.
       * @return Comprimento da distância calculada.
       */
      virtual double distance(const Object& other) const = 0;

      /**
       * @brief Revela qual estrutura geométrica o objeto atual representa.
       * @return Tipo da entidade geométrica ("Point", "Segment", "Polygon").
       */
      virtual std::string name() const = 0;

      /**
       * @brief Destrutor virtual para garantir destruição adequada em classes derivadas.
       */
      virtual ~Object() = default;
};

#endif
