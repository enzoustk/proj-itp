#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>

const int MAX_SIZE = 10;

struct Pessoa{
    std::string name;
    float peso;
};

struct Clinica{
    int quantidade;
    Pessoa clientes[MAX_SIZE];
};

float calcularMediaPesos(Clinica lista){
    if (lista.quantidade == 0){
        return 0;
    }
    float soma = 0.0;
    for(int i = 0;i < lista.quantidade;i++){
        soma += lista.clientes[i].peso;
    }
    float media = soma/lista.quantidade;
    return media;
}

TEST_CASE("Calcular média dos pesos dos clientes") {
    Clinica clinica = {
      3,
      {{"Fulano", 60.5}, {"Beltrano", 75.0}, {"Sicrano", 82.3}}
    };
    float media = calcularMediaPesos(clinica);
    CHECK(media == doctest::Approx(72.6).epsilon(0.1));
}