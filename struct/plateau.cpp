#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

const int MAX_SIZE = 100;

struct Histograma{
    int tamanho;
    int fre[MAX_SIZE];
};

struct Plateau{
    int inicio, fim, valor;
};

Plateau encontrarPlateau(Histograma a){
    Plateau resultado = {-1, -1, -1};
    for (int i = 0; i < a.tamanho;i++){
        if (a.fre[i] == a.fre[i+1]){
            resultado.inicio = i;
            resultado.valor = a.fre[i];
            int h = i+1;
            while(resultado.valor == a.fre[h+1] && h < a.tamanho){
                h++;
            }
            resultado.fim = h;
            return resultado;
        }
    }
    return resultado;
}

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