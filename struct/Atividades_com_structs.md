# struct e enum - atividades

## Frações
Defina um tipo de dado para representar um número fracionário (numerador/denominador) e implemente uma função que recebe dois números fracionários e retorna a multiplicação deles, também como número fracionário.

Testes:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Multiplicação de frações") {
    Fracao f1 = {2, 3};
    Fracao f2 = {4, 5};
    Fracao resultado = multiplicar(f1, f2);
    CHECK(resultado.numerador == 8);
    CHECK(resultado.denominador == 15);
}
```

## Ponto 2D
Defina um tipo de dado para representar um ponto em um plano 2D (com valores inteiros para as coordenadas x e y) e implemente uma função que calcula a distância entre dois pontos. O valor retornado também deve ser do tipo inteiro.

Testes:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cmath>

TEST_CASE("Distância entre pontos 2D") {
    CHECK(distancia(Ponto2D{0, 0}, Ponto2D{3, 4}) == 5);
    CHECK(distancia(Ponto2D{3, 3}, Ponto2D{6, 9}) == 6);
    CHECK(distancia(Ponto2D{4, 4}, Ponto2D{8, 12}) == 8);
}
```

## Plateau
Um histograma é um tipo de gráfico que representa a distribuição de frequências de dados. Quando um intervalo contínuo desta distribuição possui o mesmo valor, dizemos que é um plateau.

Defina:
- Uma constante chamada MAX_SIZE com o tamanho máximo de qualquer histograma.
- Um tipo de dado para representar um histograma, contendo: 1) a quantidade de frequências e 2) um array com seus valores.
- Um tipo de dado para representar os dados de um plateau, contendo índice do array onde o plateau começa, índice do array onde o plateau termina e valor da frequência nesse intervalo.

Em seguida, implemente uma função que recebe um histograma como parâmetro e retorna os dados do primeiro plateau que encontrar (maior intervalo que possua pelo menos 2 valores consecutivos iguais). Caso não encontre nenhum plateau, retorne um plateau com valores negativos (por Testes, -1).

Testes:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Encontrar plateau em histograma") {
    Histograma hist1 = {5, {1, 2, 2, 3, 4}};
    Plateau p1 = encontrarPlateau(hist1);
    CHECK(p1.inicio == 1);
    CHECK(p1.fim == 2);
    CHECK(p1.valor == 2);

    Histograma hist2 = {6, {1, 1, 1, 2, 3, 3}};
    Plateau p2 = encontrarPlateau(hist2);
    CHECK(p2.inicio == 0);
    CHECK(p2.fim == 2);
    CHECK(p2.valor == 1);

    Histograma hist3 = {4, {1, 2, 3, 4}};
    Plateau p3 = encontrarPlateau(hist3);
    CHECK(p3.inicio == -1);
    CHECK(p3.fim == -1);
    CHECK(p3.valor == -1);
}
```

## Nutrição
Você está trabalhando em um projeto para uma clínica de nutrição que deseja coletar dados sobre o peso dos pacientes. Sua missão é desenvolver um programa que facilite essa coleta de dados. O software deve ser capaz de registrar o nome e o peso de cada paciente que visitar a clínica. No final do dia, o programa deve calcular a média dos pesos de todos os pacientes atendidos, para que a equipe possa ter uma visão geral do perfil de saúde dos seus clientes naquele dia.

Defina um tipo de dado para representar uma pessoa, contendo seu nome e peso, e um tipo de dado para representar os clientes da clínica (várias pessoas). Este tipo deve conter a quantidade de pessoas e um array com as pessoas cadastradas (defina uma constante MAX_CLIENTES com o tamanho máximo do array).

Em seguida, implemente uma função que recebe uma variáveis contendo os clientes e retorna a média dos pesos. Considere a função correta se o valor retornado estiver com uma margem de erro de 0.1 em relação ao valor esperado.

Testes:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Calcular média dos pesos dos clientes") {
    Clinica clinica = {
      3,
      {{"Fulano", 60.5}, {"Beltrano", 75.0}, {"Sicrano", 82.3}}
    };
    float media = calcularMediaPesos(clinica);
    CHECK(media == doctest::Approx(72.6).epsilon(0.1));
}
```

## Biblioteca
Uma biblioteca está atualizando o seu sistema cadastrando todos os seus livros indicando o título, o autor, o ano de publicação, a quantidade de páginas e um indicador se o livro está disponível para empréstimo. O sistema precisa realizar buscas por autor ou por título, retornando todos os livros que satisfaçam a consulta e que estejam disponíveis para empréstimo.

Defina um tipo de dado para representar um livro, contendo os campos mencionados, e um tipo de dados para representar um conjunto de livros, contendo a quantidade de livros e um array com os livros do conjunto (de tamanho máximo definido por uma constante MAX_LIVROS). Defina também um tipo para representar o tipo de busca (por autor ou título).

Em seguida, escreva uma função que recebe um conjunto de livros, um tipo de busca e um texto a ser procurado. A função deve retornar um conjunto de livros contendo todos os livros que satisfaçam a consulta (o texto passado se encontra no autor ou no título, conforme o tipo de busca) e que estejam disponíveis para empréstimo. Se não houver livros que satisfaçam a consulta, retorne um conjunto vazio (quantidade igual a zero).

Testes:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Buscar livros por autor") {
    Livros biblioteca = {3, {
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 1216, true},
        {"1984", "George Orwell", 1949, 328, true},
        {"A Revolução dos Bichos", "George Orwell", 1945, 112, false}
    }};
    Livros resultado = buscarLivros(biblioteca, AUTOR, "Orwell");
    CHECK(resultado.quantidade == 1);
    CHECK(resultado.livros[0].titulo == "1984");
}
TEST_CASE("Buscar livros por título") {
    Livros biblioteca = {3, {
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 1216, true},
        {"1984", "George Orwell", 1949, 328, true},
        {"A Revolução dos Bichos", "George Orwell", 1945, 112, false}
    }};
    Livros resultado = buscarLivros(biblioteca, TITULO, "Senhor");
    CHECK(resultado.quantidade == 1);
    CHECK(resultado.livros[0].autor == "J.R.R. Tolkien");
}
```

## Churrasco
Vocês estão organizando um churrasco para a turma, mas estão com dificuldade de dividir os gastos de forma correta para todos os participantes. Vocês pensaram então em escrever um programa para calcular os gastos e divisão.

Para começar, defina um tipo de dado para representar um item do churrasco, contendo o nome do item, o preço unitário e a quantidade. Depois, defina outro tipo de dado para representar uma lista de itens. Essa lista deve conter a quantidade de itens e um array com de tamanho máximo constante predefinido (capacidade máxima do array).

Em seguida, defina duas funções:
- A primeira função é para inserir um item em uma lista. A função deve receber como parâmetro a lista de itens a ser alterada e o item a ser inserido, e deve retornar um valor booleano, sendo verdadeiro se o item foi inserido ou false se a lista já chegou ao sua capacidade máxima e o item não pode ser mais inserido.
- A segunda função é para calcular a divisão dos gastos por pessoa. A função deve receber como parâmetro a lista de itens e a quantidade de pessoas, e deve retornar um valor float com o valor que cada pessoa deve pagar para comprar todos os itens da lista. Considere a função correta se o valor retornado estiver com uma margem de erro de 0.1 em relação ao valor esperado.

Testes:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

const int MAX_ITENS = 100;

TEST_CASE("Inserir item na lista") {
    ListaItens lista = {0};
    Item item = {"Carvão", 20.0, 2};
    CHECK(inserirItem(lista, item) == true);
    CHECK(lista.quantidade == 1);
    CHECK(lista.itens[0].nome == "Carvão");

    lista.quantidade = MAX_ITENS; // Simula lista cheia
    Item outroItem = {"Cerveja", 5.0, 10};
    CHECK(inserirItem(lista, outroItem) == false);
}

TEST_CASE("Calcular divisão dos gastos") {
    ListaItens lista = {3, {
        {"Carvão", 20.0, 2},
        {"Linguiça", 15.0, 3},
        {"Pão de Alho", 10.0, 5}
    }};
    CHECK(calcularDivisao(lista, 5) == doctest::Approx(27.0).epsilon(0.1));
}
```
