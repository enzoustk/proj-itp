#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

struct Livro{
    string titulo;
    string autor;
    int ano;
    int paginas;
    bool aluguel;
};

struct Livros{
    int quantidade;
    Livro biblioteca[MAX_SIZE];
};

enum TipoBusca{
    AUTOR, 
    TITULO
};

bool verificaLivro(Livro l,TipoBusca tipo,String alvo){
    if (tipo == AUTOR){
        return l.autor.find(alvo) >= 0
    }else {
        return l.titulo.find(alvo) >= 0
    }
}

Livros buscarLivros(Livros bi, TipoBusca tipo, string alvo){
    Livros resultado = {0}
    for(int i = 0; i < bi.quantidade;i++){
        Livro atual = bi.biblioteca[i];
        if(atual.aluguel){
            if (verificalivro(bi.biblioteca[i],tipo,alvo)){
                resultado.livros[resultado.quantidade] = atual;
                resultado.quantidade++;
            }
         }
    }
}



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
    CHECK(resultado.Livros[0].autor == "J.R.R. Tolkien");
}