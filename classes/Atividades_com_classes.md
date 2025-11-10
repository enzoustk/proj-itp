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

**Testes**:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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

**Testes**:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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

**Testes**:
```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Gerenciamento de Biblioteca") {
    Biblioteca biblioteca;

    // Dados do livro: título, autor, ISBN
    Livro l1 = {"O Senhor dos Anéis", "J.R.R. Tolkien", 9788845292613}; 
    Livro l2 = {"1984", "George Orwell", 9788547007063};
    Livro l3 = {"A Revolução dos Bichos", "George Orwell", 9788547007064};

    // Dados do usuário: ID e nome
    Usuario fulano = {1, "Fulano"};
    Usuario beltrano = {2, "Beltrano"};

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
    CHECK(biblioteca.quantidadeLivros(1) == 2);
    CHECK(biblioteca.quantidadeLivros(2) == 1);

    CHECK(biblioteca.devolverLivro(9788845292613, 1) == true);
    CHECK(biblioteca.devolverLivro(9788547007063, 1) == true);

    // Agora o livro pode ser emprestado para outro usuário
    CHECK(biblioteca.emprestarLivro(9788845292613, 2) == true);

    CHECK(biblioteca.quantidadeLivros(1) == 0);
    CHECK(biblioteca.quantidadeLivros(2) == 2);
}