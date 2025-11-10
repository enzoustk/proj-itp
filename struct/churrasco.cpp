#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ITENS = 100;

struct Item{
    string nome;
    float preco;
    float quantidade;
};

struct ListaItens{
    int quantidade;
    Item itens[MAX_ITENS];
};

bool inserirItem(ListaItens &lista,Item item){
    if (lista.quantidade == MAX_ITENS){
        return false;
    }else{
        lista.itens[lista.quantidade] = item;
        lista.quantidade++;
        return true;
    }
}

float calcularDivisao(ListaItens lista,float p){
    float soma = 0.0;
    for (int i = 0; i < lista.quantidade;i++){
        float valor = lista.itens[i].preco * lista.itens[i].quantidade;
        soma += valor; 
    }
    float divisao = soma/p;
    return divisao;
}

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
    CHECK(calcularDivisao(lista, 5) == doctest::Approx(27.0));
}