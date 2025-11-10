#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

struct Fracao{
    int numerador;
    int denominador;
};

Fracao multiplicar(Fracao a,Fracao b){
    Fracao resultado;
    resultado.numerador = a.numerador * b.numerador;
    resultado.denominador= a.denominador * b.denominador;
    return resultado;
}


TEST_CASE("Multiplicação de frações") {
    Fracao f1 = {2, 3};
    Fracao f2 = {4, 5};
    Fracao resultado = multiplicar(f1, f2);
    CHECK(resultado.numerador == 8);
    CHECK(resultado.denominador == 15);

}