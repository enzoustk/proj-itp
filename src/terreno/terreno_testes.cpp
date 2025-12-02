#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "terreno.h"

TEST_CASE("Testa a criação de um terreno de uma única célula") {
    Terreno terreno(0); // 2^0 + 1 = 1
    CHECK(terreno.obterLargura() == 1);
    CHECK(terreno.obterProfundidade() == 1);
}

TEST_CASE("Testa a geração aleatória de altitudes") {
    Terreno terreno(2);
    CHECK(terreno.obterLargura() == 5);
    CHECK(terreno.obterProfundidade() == 5);
}

TEST_CASE("Teste 1: Criar mapa 5x5 com valores default (0.0)") {
    Terreno t(2);  // 2^2 + 1 = 5
    CHECK(t.obterLargura() == 5);
    CHECK(t.obterProfundidade() == 5);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            CHECK(t.consultarAltitude(i, j) == 0.0);
        }
    }
}

TEST_CASE("Teste 2: Salvar mapa 5x5 em arquivo") {
    Terreno t(2);  // 5x5
    t.salvarArquivo("terreno_5x5.txt");
    
    // Verifica se o arquivo foi criado
    std::ifstream arquivo("terreno_5x5.txt");
    CHECK(arquivo.is_open());
    
    int n;
    arquivo >> n;
    CHECK(n == 2);  // Deveria ter salvo n, não tamanho
    
    arquivo.close();
}

TEST_CASE("Teste 3: Ler mapa 3x3 de um arquivo") {
    // Cria e salva um mapa 3x3 com valores conhecidos
    {
        Terreno t(1);  // 2^1 + 1 = 3
        CHECK(t.obterLargura() == 3);
        CHECK(t.obterProfundidade() == 3);
        
        t.salvarArquivo("terreno_3x3.txt");
    }
    
    // Lê o mapa criado
    Terreno t2(0);
    t2.lerArquivo("terreno_3x3.txt");
    CHECK(t2.obterLargura() == 3);
    CHECK(t2.obterProfundidade() == 3);
}

TEST_CASE("Teste 4: Diamond-Square com rugosidade baixa") {
    Terreno t(2);  // 5x5
    t.gerarAleatorio(2, 0.5);
    
    CHECK(t.obterLargura() == 5);
    CHECK(t.obterProfundidade() == 5);
    CHECK(t.obterN() == 2);
}

TEST_CASE("Teste 5: Diamond-Square gera valores diferentes do padrão") {
    Terreno t(3);  // 9x9
    t.gerarAleatorio(3, 0.5);
    
    CHECK(t.obterLargura() == 9);
    CHECK(t.obterProfundidade() == 9);
    
    // Verifica que nem todos os valores são 0.0
    bool temValorDiferente = false;
    for (int i = 0; i < 9 && !temValorDiferente; i++) {
        for (int j = 0; j < 9 && !temValorDiferente; j++) {
            if (t.consultarAltitude(i, j) != 0.0) {
                temValorDiferente = true;
            }
        }
    }
    CHECK(temValorDiferente);
}

TEST_CASE("Teste 6: Salvar e ler terreno gerado") {
    {
        Terreno t(2);
        t.gerarAleatorio(2, 0.5);
        t.salvarArquivo("terreno_gerado.txt");
    }
    
    Terreno t2(0);
    t2.lerArquivo("terreno_gerado.txt");
    CHECK(t2.obterLargura() == 5);
    CHECK(t2.obterProfundidade() == 5);
}

TEST_CASE("Teste 7: Consultar altitude em posição válida") {
    Terreno t(2);
    t.gerarAleatorio(2, 0.5);
    
    double alt = t.consultarAltitude(2, 2);
    CHECK(alt != -1.0);  // Não deve retornar erro
}

TEST_CASE("Teste 8: Consultar altitude em posição inválida") {
    Terreno t(2);
    double alt = t.consultarAltitude(10, 10);
    CHECK(alt == -1.0);  // Deve retornar erro
}