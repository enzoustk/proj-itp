# Funções - problemas

## Amigos para sempre!

A empresa "Amigos para Sempre" está desenvolvendo um software para recomendar amizades entre pessoas. A ideia é que pessoas são potenciais amigas se seus números preferidos são também amigos (😨).

A empresa contratou você para desenvolver esse software e pediram para implementar uma função que verifique, dentre uma lista de números, se há dois "números amigos". Se houver, a função deve retornar `true` e alterar dois parâmetros de referência para armazenar esses números.

Lembre-se que dois números são considerados amigos se a soma dos divisores próprios (excluindo o próprio número) de cada número for igual ao outro número. Por exemplo, 220 e 284 são números amigos porque:
- Os divisores próprios de 220 são: 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110, e a soma desses divisores é 284.
- Os divisores próprios de 284 são: 1, 2, 4, 71, 142, e a soma desses divisores é 220.

Como você já é um/a programador/a experiente, sabe como quebrar esse problema em partes menores. Então, você decide primeiro implementar uma função que verifica se dois números são amigos. Mas, para isso, você precisa de uma função auxiliar que calcule a soma dos divisores próprios de um número.

Então, serão necessárias três funções:

1. `somaDivisores`: que calcula a soma dos divisores próprios de um número.
2. `saoAmigos`: que verifica se dois números são amigos (usa `somaDivisores`).
3. `encontrarNumerosAmigos`: que percorre a lista de números e encontra um par de números amigos (usa `saoAmigos`).

```cpp
int somaDivisores(int n);
bool saoAmigos(int a, int b);
bool encontrarNumerosAmigos(int arr[], int tamanho, int &num1, int &num2);
```

Escreva um programa que leia da entrada de dados uma lista de números inteiros e utilize a função `encontrarNumerosAmigos` para verificar se há algum par de números amigos na lista. Se houver, o programa deve imprimir esses números; caso contrário, deve informar que não há números amigos na lista.

Crie seus testes de entrada e saída para o problema acima antes de começar a programar a solução. Depois dos testes elaboradores, desenvolva e valide sua solução.