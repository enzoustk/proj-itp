# Classes

## Contatos
Você precisa desenvolver um sistema simples para gerenciar uma lista de contatos. Cada contato deve armazenar o nome, o telefone e o email da pessoa. O sistema deve permitir adicionar novos contatos, remover contatos existentes e buscar um contato pelo seu nome.

Defina um tipo de dado para representar um contato (`Contato`), contendo os campos mencionados (`nome`, `telefone` e `email`), e um tipo de dado para representar a lista de contatos (`Contatos`), contendo a quantidade de contatos (`quantidade`) e um array com os contatos (`contatos`) de tamanho máximo definido por uma constante `MAX_CONTATOS`.
Em seguida, implemente as seguintes operações sobre a lista de contatos:
- Uma operação para adicionar um contato na lista (`adicionarContato`). Ela deve receber como parâmetro o contato a ser inserido e deve retornar um valor booleano, sendo verdadeiro se o contato foi inserido ou false se a lista já chegou ao sua capacidade máxima (e o contato não pode ser mais inserido).
- Uma operação para remover um contato da lista (`removerContato`). Ela deve receber como parâmetro o nome do contato a ser removido e deve retornar um valor booleano, sendo verdadeiro se o contato foi removido ou false se o contato não foi encontrado.
- Uma operação para buscar um contato pelo nome (`buscarContato`). Ela deve receber como parâmetro o nome do contato a ser buscado e deve retornar um valor booleano, sendo verdadeiro se o contato foi encontrado (e preencher uma variável passada por referência com os dados do contato) ou false se o contato não foi encontrado.

Atente para o que deve ser privado e o que deve ser público na sua implementação.
Se tudo estiver correto, os testes a seguir devem passar (sem alterações).

**Solução**:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
using namespace std;

const int MAX_CONTATOS = 100;

// podemos usar struct aqui, já que todos os membros são públicos
struct Contato {
    string nome;
    string telefone;
    string email;
};

class ListaContatos {
    Contato contatos[MAX_CONTATOS]; // o array tem um tamanho fixo
    int quantidade = 0;

  public:
    // obs: o const & evita criar uma cópia desnecessária do contato
    bool adicionarContato(const Contato &contato) {
        if (quantidade >= MAX_CONTATOS) {
            return false;
        }
        // coloca o novo contato na próxima posição disponível
        contatos[quantidade] = contato;
        quantidade++;
        return true;
    }

    bool removerContato(const string &nome) {
        for (int i = 0; i < quantidade; ++i) {
            if (contatos[i].nome == nome) {
                // como contatos[i] será removido, colocamos o último
                // contato no lugar dele
                contatos[i] = contatos[quantidade - 1];
                // e agora diminuímos a quantidade
                quantidade--;
                return true;
            }
        }
        return false;
    }

    // aqui não usamos o const em contato porque vamos alterá-lo
    bool buscarContato(const string &nome, Contato &contato) {
        for (int i = 0; i < quantidade; ++i) {
            if (contatos[i].nome == nome) {
                contato = contatos[i];
                return true;
            }
        }
        return false;
    }

    int consultaQuantidade() {
        return quantidade;
    }
};

TEST_CASE("Gerenciar contatos") {
    ListaContatos lista;
    Contato c1 = {"Fulano", "1234-5678", "fulano@example.com"};
    Contato c2 = {"Beltrano", "9876-5432", "beltrano@example.com"};
    Contato c3 = {"Sicrano", "5555-5555", "sicrano@example.com"};

    CHECK(lista.adicionarContato(c1) == true);
    CHECK(lista.adicionarContato(c2) == true);
    CHECK(lista.adicionarContato(c3) == true);
    CHECK(lista.consultaQuantidade() == 3);

    CHECK(lista.removerContato("Beltrano") == true);
    CHECK(lista.consultaQuantidade() == 2);

    Contato fulano, beltrano;

    CHECK(lista.buscarContato("Fulano", fulano) == true);
    CHECK(fulano.email == "fulano@example.com");
    CHECK(fulano.telefone == "1234-5678");

    CHECK(lista.buscarContato("Beltrano", beltrano) == false);
    CHECK(lista.removerContato("Beltrano") == false);
}
```

## Elevador
Você foi contratado para desenvolver um sistema de controle de um elevador em um prédio. O elevador deve ser capaz de armazenar informações sobre o andar atual, a capacidade máxima de pessoas, o número atual de pessoas no elevador e o total de andares do prédio. O sistema deve permitir que as pessoas entrem e saiam do elevador, bem como subir e descer entre os andares.

Defina um tipo de dado para representar o elevador (`Elevador`), contendo os campos mencionados (`andarAtual`, `capacidadeMaxima`, `numPessoas` e `totalAndares`).

Crie um construtor para inicializar o elevador com a capacidade máxima e o total de andares do prédio, definindo o andar atual como 0 (térreo) e o número de pessoas como 0. Em seguida, implemente os seguintes métodos  públicos sobre o elevador:

- entra(): para acrescentar uma pessoa no elevador (se ele ainda não atingiu sua capacidade máxima);
- sai(): para remover uma pessoa do elevador (se houver alguém dentro dele);
- sobe(): para subir um andar (se não estiver no último andar);
- desce(): para descer um andar (se não estiver no térreo).
- consulta_andarAtual(): para consultar o andar atual do elevador.
- consulta_numPessoas(): para consultar o número atual de pessoas no elevador.

Novamente, atente para o que deve ser privado e o que deve ser público na sua implementação.
Se tudo estiver correto, os testes a seguir devem passar (sem alterações).

**Solução**:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

class Elevador {
    int andarAtual;
    int capacidadeMaxima;
    int numPessoas;
    int totalAndares;

  public:
    Elevador(int capacidade, int andares):
      capacidadeMaxima(capacidade),
      totalAndares(andares),
      andarAtual(0),
      numPessoas(0) {}

    bool entra() {
        if (numPessoas < capacidadeMaxima) {
            numPessoas++;
            return true;
        }
        return false;
    }

    bool sai() {
        if (numPessoas > 0) {
            numPessoas--;
            return true;
        }
        return false;
    }

    bool sobe() {
        if (andarAtual < totalAndares - 1) {
            andarAtual++;
            return true;
        }
        return false;
    }

    bool desce() {
        if (andarAtual > 0) {
            andarAtual--;
            return true;
        }
        return false;
    }

    int consultaAndarAtual() {
        return andarAtual;
    }

    int consultaNumPessoas() {
        return numPessoas;
    }
};

TEST_CASE("Controle de Elevador") {
    Elevador elevador(3, 4);  // capacidade de 3 pessoas e 4 andares

    CHECK(elevador.consultaAndarAtual() == 0);
    CHECK(elevador.consultaNumPessoas() == 0);

    CHECK(elevador.entra() == true); // uma pessoa entrou
    CHECK(elevador.entra() == true);
    CHECK(elevador.consultaNumPessoas() == 2);
    CHECK(elevador.entra() == true);
    CHECK(elevador.entra() == false); // a capacidade foi atingida
    CHECK(elevador.consultaNumPessoas() == 3);

    CHECK(elevador.sobe() == true);
    CHECK(elevador.consultaAndarAtual() == 1);

    CHECK(elevador.desce() == true);
    CHECK(elevador.consultaAndarAtual() == 0);
    CHECK(elevador.desce() == false); // já está no térreo

    CHECK(elevador.sai() == true);
    CHECK(elevador.consultaNumPessoas() == 2);
    CHECK(elevador.sai() == true);
    CHECK(elevador.sai() == true);
    CHECK(elevador.sai() == false); // não há mais ninguém no elevador
}
```

## Biblioteca
Uma biblioteca está atualizando o seu sistema e pediu sua ajuda. Crie um sistema de gerenciamento de uma biblioteca, definindo as seguintes classes:
- Livro: com atributos como título, autor, ISBN e status de disponibilidade.
- Usuario: com atributos como ID e nome.
- Biblioteca: contendo uma lista de livros e de usuários registrados.

A biblioteca deve permitir o cadastro de novos livros e usuários, bem como a realização de empréstimos e devoluções de livros. O sistema deve garantir que um livro só possa ser emprestado se estiver disponível.

Implemente os métodos necessários (públicos e privados) para realizar essas operações. Você está no comando para dizer como os dados internos dessas classes vão funcionar, desde que os testes a seguir passem sem alterações.

**Solução**:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

class Usuario {
    int id;
    string nome;
  public:
    Usuario() = default; // pede para o compilador gerar o construtor padrão
    Usuario(int i, const string &n): id(i), nome(n) {}
    int getId() const { return id; }
    string getNome() const { return nome; }
};

class Livro {
    string titulo;
    string autor;
    long long isbn;
    int emprestadoPara; // ID do usuário que pegou o livro emprestado

  public:
    Livro() = default; // pede para o compilador gerar o construtor padrão
    Livro(const string &t, const string &a, long long i):
      titulo(t), autor(a), isbn(i), emprestadoPara(-1) {}
      // obs: -1 indica que o livro não está emprestado

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    long long getIsbn() const { return isbn; }
    bool estaDisponivel() const { return emprestadoPara == -1; }
    void pegar(int userId) { emprestadoPara = userId; }
    void devolver() { emprestadoPara = -1; }
    int quemTemPosse() { return emprestadoPara; }
};

const int MAX_LIVROS = 100;
const int MAX_USUARIOS = 100;

class Biblioteca {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    int numLivros;
    int numUsuarios;
  public:
    Biblioteca(): numLivros(0), numUsuarios(0) {}

    bool cadastrarLivro(const Livro &livro) {
        if (numLivros >= MAX_LIVROS) {
            return false;
        }
        livros[numLivros] = livro;
        numLivros++;
        return true;
    }

    bool cadastrarUsuario(const Usuario &usuario) {
        if (numUsuarios >= MAX_USUARIOS) {
            return false;
        }
        usuarios[numUsuarios] = usuario;
        numUsuarios++;
        return true;
    }

    bool emprestarLivro(long long isbn, int userId) {
        for (int i = 0; i < numLivros; ++i) {
            if (livros[i].getIsbn() == isbn && livros[i].estaDisponivel()) {
                livros[i].pegar(userId);
                return true;
            }
        }
        return false;
    }

    bool devolverLivro(long long isbn) {
        for (int i = 0; i < numLivros; ++i) {
            if (livros[i].getIsbn() == isbn && !livros[i].estaDisponivel()) {
                livros[i].devolver();
                return true;
            }
        }
        return false;
    }

    int numLivrosEmprestados(int userId) {
        int count = 0;
        for (int i = 0; i < numLivros; ++i) {
            if (userId == livros[i].quemTemPosse()) {
                count++;
            }
        }
        return count;
    }
};

TEST_CASE("Gerenciamento de Biblioteca") {
    Biblioteca biblioteca;

    // Dados do livro: título, autor, ISBN
    Livro l1("O Senhor dos Anéis", "J.R.R. Tolkien", 9788845292613);
    Livro l2("1984", "George Orwell", 9788547007063);
    Livro l3("A Revolução dos Bichos", "George Orwell", 9788547007064);

    // Dados do usuário: ID e nome
    Usuario fulano(1, "Fulano");
    Usuario beltrano(2, "Beltrano");

    CHECK(biblioteca.cadastrarLivro(l1) == true);
    CHECK(biblioteca.cadastrarLivro(l2) == true);
    CHECK(biblioteca.cadastrarLivro(l3) == true);

    CHECK(biblioteca.cadastrarUsuario(fulano) == true);
    CHECK(biblioteca.cadastrarUsuario(beltrano) == true);

    // Parâmetros do empréstimo: ISBN do livro e ID do usuário, indicando
    // que o usuário do ID solicitou o empréstimo do livro com o ISBN
    CHECK(biblioteca.emprestarLivro(9788845292613, 1) == true);
    CHECK(biblioteca.emprestarLivro(9788547007063, 1) == true);
    CHECK(biblioteca.emprestarLivro(9788547007064, 2) == true);

    // Tentativa de empréstimo de um livro já emprestado
    CHECK(biblioteca.emprestarLivro(9788845292613, 2) == false);

    // Verifica quantos livros um usuário de dado ID pegou emprestado
    CHECK(biblioteca.numLivrosEmprestados(1) == 2);
    CHECK(biblioteca.numLivrosEmprestados(2) == 1);

    CHECK(biblioteca.devolverLivro(9788845292613) == true);
    CHECK(biblioteca.devolverLivro(9788547007063) == true);

    // Agora o livro pode ser emprestado para outro usuário
    CHECK(biblioteca.emprestarLivro(9788845292613, 2) == true);

    CHECK(biblioteca.numLivrosEmprestados(1) == 0);
    CHECK(biblioteca.numLivrosEmprestados(2) == 2);
}
```
