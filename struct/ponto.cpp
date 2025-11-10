#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <cmath>

struct Ponto2D{
    int x;
    int y;
};

int distancia(Ponto2D p1, Ponto2D p2){
    int dist = sqrt(pow(p2.x - p1.x,2)+pow(p2.y - p1.y,2));
    return dist;
}

TEST_CASE("Distância entre pontos 2D") {
    CHECK(distancia(Ponto2D{0, 0}, Ponto2D{3, 4}) == 5);
    CHECK(distancia(Ponto2D{3, 3}, Ponto2D{6, 9}) == 6);
    CHECK(distancia(Ponto2D{4, 4}, Ponto2D{8, 12}) == 8);
}