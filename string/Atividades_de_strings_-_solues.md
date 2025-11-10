### Vogais
Escreva um programa que leia uma palavra (string sem espaço) e envie para a saída a quantidade de vogais (nessa atividade, entende-se por vogal as letras `a`, `e`, `i`, `o`, `u` e `y`).

**Exemplos de entrada e saída:**

| Entrada   | Saída |
| --------- | ----- |
| caramba!  | 3     |
| Piauiense | 6     |
| BETERRaba | 4     |

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string palavra;
    cin >> palavra;

    // converte todos os caracteres para minúsculas e conta as vogais
    int contador = 0;
    for (char c : palavra) {
        c = tolower(c); // `tolower()` retorna o caractere na sua versão minúscula
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            contador++;
        }
    }

    cout << contador << endl;
    return 0;
}
```


## Quantidade de repetições
Escreva um programa que leia um texto (linha podendo ter espaços em branco), seguido de uma  palavra (string sem espaços). Em seguida, envie para a saída quantas vezes a palavra apareceu no texto. Desconsidere se os caracteres estão em maiúscula ou minúscula.

**Exemplos de entrada e saída:**

| Entrada                                                                              | Saída |
| ------------------------------------------------------------------------------------ | ----- |
| De tudo, ao meu amor serei atento. Antes, e com tal zelo, e sempre, e tanto.<br>Amor | 1     |
| Que mesmo em face do maior encanto. Dele se encante mais meu pensamento.<br>enca     | 2     |

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto, palavra;

    getline(cin, texto);  // lê a linha inteira (até o '\n')
    cin >> palavra;       // lê uma única palavra

    // transforma o texto e a palavra em minúsculas
    string textoMinusculo, palavraMinuscula;
    for (char c : texto) {
        textoMinusculo += tolower(c);
    }
    for (char c : palavra) {
        palavraMinuscula += tolower(c);
    }

    // encontra a primeira ocorrência de palavraMinuscula em textoMinusculo
    // `find` retorna a posição da primeira ocorrência ou -1 (string::npos) se não encontrar
    int pos = textoMinusculo.find(palavraMinuscula);

    // conta as ocorrências
    int contador = 0;
    // entra nesse loop enquanto encontrar a palavra
    while (pos != -1)  // ou string::npos
        contador++;
        // procura a próxima ocorrência, começando a busca logo após a posição atual
        pos = textoMinusculo.find(palavraMinuscula, pos + 1);
    }

    cout << contador << endl;
    return 0;
}
```

## Strip
Strip é uma operação comum em tratamento de entrada de dados e refere-se a uma operação para descartar os espaços em branco antes e depois de um texto. É útil quando, por exemplo, um usuário digita espaços em branco antes e/ou depois do texto que realmente deve ser considerado. Nesse caso, antes de processar o "texto útil", limpamos os caracteres em branco (normalmente inúteis).
Escreva um programa que realiza essa operação, ele deve ler da entrada padrão uma única linha de texto, podendo ter espaços em branco no início, no fim e entre palavras, e enviar para a saída padrão a versão enxuta desse texto, ou seja sem espaços em branco no início e no fim.
Nos exemplos de entrada e saída, os caracteres ` `  está sendo para representar o texto, incluindo os espaços em branco.


**Exemplos de entrada e saída:**

| Entrada               | Saída              |
| --------------------- | ------------------ |
| `rua prof. xavier`    | `rua prof. xavier` |
| `   fulano de tal   ` | `fulano de tal`    |
| `   30   anos`        | `30   anos`        |
| `59000-000    `       | `59000-000`        |

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto;
    getline(cin, texto);

    // índice para o primeiro caractere que não é espaço em branco.
    // vamos começar do início (0).
    int inicio = 0;
    // enquanto o índice `inicio` não chegar no final do texto e o caractere na
    // sua posição for espaço em branco, avança o índice
    while (inicio < texto.size() && texto[inicio] == ' ') {
        inicio++;
    }

    // faz agora o mesmo para o final do texto.
    // encontra o índice do último caractere que não é espaço em branco
    int fim = texto.size() - 1;
    while (fim >= 0 && texto[fim] == ' ') {
        fim--;
    }

    // agora que sabemos onde começa e termina, podemos extrair o texto útil
    string textoUtil = texto.substr(inicio, fim - inicio + 1);
    cout << textoUtil << endl;

    return 0;
}
```

A classe `string` tem muitos métodos... e alguns podem ajudar no desenvolvimento. Porém, como já mencionei antes, não é objetivo da nossa disciplina explorar todos os recursos do C++. É importante entender a lógica por trás do código. Porém, a título de informação, a classe `string` tem um método chamado `find_first_not_of`, que pode ser usado para encontrar o índice do primeiro caractere que não é um espaço em branco. De forma semelhante, há o método `find_last_not_of`, que encontra o índice do último caractere que não é um espaço em branco. Usando esses métodos, a solução para essa atividade pode ficar assim:

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
    string texto;
    getline(cin, texto);

    // encontra o índice do primeiro e do último caractere que não é
    // espaço em branco
    int inicio = texto.find_first_not_of(' ');
    int fim = texto.find_last_not_of(' ');

    // extrai o texto útil
    string textoUtil = texto.substr(inicio, fim - inicio + 1);
    cout << textoUtil << endl;

    return 0;
}
```


## Texto para CamelCase
Escreva um programa que leia um texto com espaços em branco e envie para a saída um identificador no formato camelCase, no qual não há espaços em branco, as letras iniciais de cada palavra do texto estão em maiúscula e as demais em minúscula. A letra inicial deve seguir o mesmo padrão do texto original. Considere que não espaços em branco no início e no final do texto, porém pode haver mais de um espaço em branco entre as palavras.

**Exemplos de entrada e saída:**

| Entrada              | Saída              |
| -------------------- | ------------------ |
| contador de palavras | contadorDePalavras |
| ZIG    ZAG           | ZigZag             |

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  string texto;
  getline(cin, texto);

  string camelCase;
  bool primeiraPalavra = true;  // indica se é a primeira palavra
  bool novaPalavra =
      true;  // indica se o próximo caractere é o início de uma nova palavra

  for (char c : texto) {
    // se for um espaço em branco, então a próxima letra "pode ser" o início
    // de uma nova palavra
    if (c == ' ') {
      novaPalavra = true;
    }
    // se não for um espaço em branco, então o caractere vai entrar em camelCase
    else {
      // se for o 1º caractere de uma nova palavra
      if (novaPalavra) {
        if (primeiraPalavra) {
          // se for a 1ª palavra, mantém o mesmo padrão (maiúscula ou minúscula)
          camelCase += c;
          primeiraPalavra = false; // e marca para não entrar mais nessa condição
        } else {
          // mas se não for, então passa a ser maiúscula
          camelCase += toupper(c);
        }
        novaPalavra = false;  // agora não é mais o início de uma nova palavra
      }
      // se não for o início de uma nova palavra, então converte para minúscula
      else {
        camelCase += tolower(c);
      }
    }
  }

  cout << camelCase << endl;
  return 0;
}
```

## CamelCase para texto
Escreva um programa que leia uma palavra no formato camelCase e envie para a saída o texto com espaços em branco correspondente. A letra inicial deve seguir o mesmo padrão do texto original, porém as demais devem ser minúsculas.

**Exemplos de entrada e saída:**

| Entrada            | Saída                |
| ------------------ | -------------------- |
| contadorDePalavras | contador de palavras |
| ZigZag             | Zig zag              |

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  string camelCase;
  getline(cin, camelCase);

  string texto = ""; // começa com texto vazio

  // percorre os caracteres de camelCase
  for (char c : camelCase) {
    // se o texto estiver vazio é porque é a primeira letra
    if (texto == "") {
      texto += c; // mantém a primeira letra como está (maiúscula ou minúscula)
    }
    else {
      // se for letra maiúscula, então precisa de um espaço antes
      if (c >= 'A' && c <= 'Z') {
        texto += ' ';
      }
      texto += tolower(c);
    }
  }

  cout << texto << endl;
  return 0;
}
```

## Placas de carro
Escreva um programa que leia uma string e envie para a saída se essa string representa uma placa de carro válida ( “sim” ou “não” ). Uma placa é válida se tiver 8 caracteres sendo os 3 primeiros letras maiúsculas, seguidos de um hífen e 4 dígitos numéricos.

**Exemplos de entrada e saída:**

| Entrada   | Saída |
| --------- | ----- |
| UEW-9384  | sim   |
| OYLQ-2345 | não   |
| PQW-283   | não   |
| QOI 9124  | não   |
| MLZ-0000  | sim   |

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  string placa;
  getline(cin, placa);

  bool ehPlacaValida = true;

  // verifica se a placa tem 8 caracteres
  if (placa.length() != 8) {
    ehPlacaValida = false;
  }

  // verifica se os 3 primeiros caracteres são letras maiúsculas
  for (int i = 0; i < 3; i++) {
    if (placa[i] < 'A' || placa[i] > 'Z') {
      ehPlacaValida = false;
    }
  }

  // verifica se o 4º caractere é um hífen
  if (placa[3] != '-') {
    ehPlacaValida = false;
  }

  // verifica se os 4 últimos caracteres são dígitos
  for (int i = 4; i < 8; i++) {
    if (placa[i] < '0' || placa[i] > '9') {
      ehPlacaValida = false;
    }
  }

  // se passou por todas as verificações, a placa é válida
  if (ehPlacaValida) {
    cout << "sim" << endl;
  } else {
    cout << "não" << endl;
  }
  return 0;
}
```

## Multiplexador
Um multiplexador é dispositivo que combina as sinais de múltiplas fontes em um único canal de saída. Crie um programa que simula um multiplexador para dois canais de entrada, representados, cada um, por uma string.
 A saída do multiplexador será os caracteres alternados dos dois canais: o 1º caractere de um, seguido do 1º caractere do outro, depois o 2º de um, seguido do 2º do outro, depois o 3º... e assim por diante, até o término de um dos canais. Quando um dos canais terminar (não tiver mais caractere a processar), o canal de saída será ocupado pelos dados do canal remanescente (os caracteres finais do outro texto serão enviados).

**Exemplos de entrada e saída:**

| Entrada             | Saída            |
| ------------------- | ---------------- |
| LSJDUQ<br>PAO       | LPSAJODUQ        |
| aujdhj<br>slfg      | asuljfdghj       |
| aaaAA<br>BBBbbbCCCC | aBaBaBAbAbAbCCCC |

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  string canal1, canal2; // canais de entrada
  string saida = ""; // canal de saída começa vazio

  // lê os dois canais de entrada
  getline(cin, canal1);
  getline(cin, canal2);
  
  // acha o menor tamanho entre os dois canais para percorrer todos
  // os caracteres até esse tamanho.
  int tamanhoCanal1 = canal1.size();
  int tamanhoCanal2 = canal2.size();
  int menorTamanho = tamanhoCanal1 < tamanhoCanal2 ? tamanhoCanal1 : tamanhoCanal2;

  // intercala os caracteres dos dois canais até o menor tamanho
  for (int i = 0; i < menorTamanho; i++) {
    saida += canal1[i];
    saida += canal2[i];
  }

  // agora, só falta adicionar o restante do canal cujos caracteres ainda não
  // foram enviados para a saída.
  // se o tamanho do canal 1 for maior, então adiciona o restante do canal 1
  if (tamanhoCanal1 > menorTamanho) {
    saida += canal1.substr(menorTamanho);
  }
  // senão, é o canal 2 que tem caracteres restantes.
  else {
    saida += canal2.substr(menorTamanho);
  }

  cout << saida << endl;
  return 0;
}
```

## Cifra de César
Cifra de César é uma técnica simples criptografia, na qual os caracteres são substituídos por outros a partir de um deslocamento (saiba mais em https://pt.wikipedia.org/wiki/Cifra_de_C%C3%A9sar).
Escreva um programa que leia um valor inteiro e um texto, e envie para a saída o texto codificado pela cifra de César (com deslocamento dado pelo valor inteiro).
Considere que o texto de entrada só contém letras minúsculas (a-z) e maiúsculas (A-Z). O deslocamento deve ser feito de forma circular, ou seja, se o deslocamento passar do 'z', ele deve continuar a partir do 'a'. O mesmo vale para as letras maiúsculas.
    
**Exemplos de entrada e saída:**

| Entrada             | Saída            |
| ------------------- | ---------------- |
| 3<br>xyz            | abc              |
| 1<br>XYZ            | YZA              |
| 4<br>beleza         | fipmeb           |
| -1<br>abcxyz        | zabwxy           |

**Solução**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
  int deslocamento;
  string texto;

  cin >> deslocamento;
  cin >> texto;

  string textoCodificado = "";

  for (char c : texto) {
    // se for minúscula, aplica o deslocamento circular para letras minúsculas
    if (c >= 'a' && c <= 'z') {
      // encontra a posição atual da letra no alfabeto (0 a 25)
      int posicaoAtual = c - 'a';

      // calcula a nova posição com o deslocamento
      int novaPosicao = posicaoAtual + deslocamento;

      // faz o ajuste para ficar dentro do intervalo [0, 25]
      if (novaPosicao < 0) { // se for negativo, soma 26
        novaPosicao += 26;
      }
      else if (novaPosicao >= 26) { // se for maior ou igual a 26, subtrai 26
        novaPosicao -= 26;
      }

      // calcula a nova letra em função da nova posição
      char novaLetra = 'a' + novaPosicao;

      textoCodificado += novaLetra;
    }
    // faz o mesmo para letras maiúsculas
    else if (c >= 'A' && c <= 'Z') {
      // porém, podemos simplificar o cálculo usando o operador % para que os
      // valores fiquem sempre dentro do intervalo [0, 25].
      // Mas veja que, quando o deslocamento for negativo, % pode retornar um
      // valor negativo. Para evitar isso, somamos 26 antes de aplicar o %.
      // Por exemplo, se c = 'C' e deslocamento = -5, então
      // novaLetra = (('C' - 'A') + (-5) + 26) % 26 + 'A'
      //           = (2 - 5 + 26) % 26 + 'A'
      //           = 23 % 26 + 'A'
      //           = 23 + 'A'
      //           = 'X'
      // Assim, o cálculo funciona para deslocamentos positivos ou negativos.
      char novaLetra = (c - 'A' + deslocamento + 26) % 26 + 'A';
      textoCodificado += novaLetra;
    }
  }

  cout << textoCodificado << endl;
  return 0;
}
```
