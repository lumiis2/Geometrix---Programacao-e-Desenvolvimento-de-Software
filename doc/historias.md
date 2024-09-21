- Como **estudante de geometria computacional**, quero **visualizar objetos geométricos** (pontos, segmentos de reta ou polígonos inteiros) **para compreender melhor a estrutura dos problemas estudados**.

    - A aplicação deve ser capaz de identificar os objetos geométricos, sejam eles pontos, segmentos de reta ou polígonos
    - A aplicação deve ser capaz de representar visualmente os objetos geométricos
    - A aplicação deve ser capaz de rotular cada objeto geométrico e destacar sua localização no plano

- Como **usuário do software**, quero ser capaz de **salvar o estado da aplicação** para **abri-lo mais tarde e continuar meu uso**.

    - Salvar o estado em um arquivo de texto
    - O arquivo deve ser human readable
    - Devo poder restaurar o estado do programa importando um arquivo

- Como **usuário do programa**, quero ser capaz de **visualizar em um menu todos os objetos** criados para **gerenciá-los**.

    - Ao criar um objeto ele deve aparecer no menu
    - Devo ser capaz de modificar a lista de objetos
    - Ao modificar um objeto utilizado para computar outro (e.g: um ponto usado na definição de um convex hull), esse outro objeto deve ser recomputado
    - Ao deletar um objeto utilizado para computar outro, esse outro objeto deve ser deletado

- Como **usuário do software**, quero ser capaz de **exportar uma imagem do estado atual do programa** a fim de **visualizar e compartilhar minhas representações geométricas**.

    - A imagem exportada deve conter os objetos visíveis atualmente
    - Devo ser capaz de exportar a imagem em um formato rasterizado (png)
    - Devo ser capaz de exportar a imagem em um formato vetorial (svg)

- Como **aluno da matemática**, quero ser capaz de realizar **cálculos da distância euclidiana** para entender o **comportamento e relações geométrico de objetos**

    - Calcular a distância entre dois pontos no plano
    - Calcular a distância entre polígonos simples no plano
    - Calcular a distância entre retas no plano
    - Calcular a distância entre objetos de distintas categorias no plano

- Como **estudante de matemática de nível médio**, quero ser capaz de **calcular o tamanho do contorno e da superfície de polígonos simples** para me **ajudar com os exercícios do colégio**

    - A aplicação deve ser capaz de calcular a área de um polígono simples convexo
    - A aplicação deve ser capaz de calcular a área de um polígono simples não convexo
    - A aplicação deve ser capaz de calcular o perímetro de um polígono simples convexo
    - A aplicação deve ser capaz de calcular o perímetro de um polígono simples não convexo

- Como **estudante de computação**, quero **calcular a soma de Minkowski de dois polígonos** para **verificar se existe interseção entre eles**.

    - A aplicação deve ser capaz de representar visualmente a soma de Minkowski de dois polígonos
    - A aplicação deve ser capaz de adicionar uma soma de Minkowski como um novo objeto
    - A aplicação deve ser capaz de encontrar a soma de Minkowski em tempo eficiente $\mathcal{O}(n)$

- Como **estudante de computação**, quero ser capaz de **calcular o convex hull de um conjunto de objetos** para **entender o algoritmo de graham scan**

    - O convex hull deve conter todos os objetos
    - O convex hull deve ser o menor polígono convexo possível
    - A aplicação deve ser capaz de encontrar o convex hull em tempo eficiente: $\mathcal{O}(n \log n)$

- Como **cientista da computação**, quero ser capaz de **determinar a bounding box de um conjunto de objetos** para **entender como é a distribuição desses objetos no plano**

    - O bounding box deve conter todos os objetos
    - O bounding box deve ser o menor retângulo de lados paralelos aos eixos possível
    - A aplicação deve ser capaz de encontrar o bounding box em tempo eficiente: $\mathcal{O}(n)$
        
- Como **cientista da computação**, quero ser capaz de **determinar a quantidade de pontos cujas coordenadas são inteiras em um polígono** para **entender o teorema de Pick**

    - Determinar a quantidade de pontos com coordenadas inteiras na superfície de um polígono
    - Determinar a quantidade de pontos com coordenadas inteiras no contorno de um polígono
    - Mostrar o resultado do teorema de Pick para o cálculo da área de polígonos
