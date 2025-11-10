### Vogais
Escreva um programa que leia uma palavra (string sem espaço) e envie para a saída a quantidade de vogais (nessa atividade, entende-se por vogal as letras `a`, `e`, `i`, `o`, `u` e `y`).

**Exemplos de entrada e saída:**

| Entrada   | Saída |
| --------- | ----- |
| caramba!  | 3     |
| Piauiense | 6     |
| BETERRaba | 4     |

## Quantidade de repetições
Escreva um programa que leia um texto (linha podendo ter espaços em branco), seguido de uma  palavra (string sem espaços). Em seguida, envie para a saída quantas vezes a palavra apareceu no texto. Desconsidere se os caracteres estão em maiúscula ou minúscula.

**Exemplos de entrada e saída:**

| Entrada                                                                              | Saída |
| ------------------------------------------------------------------------------------ | ----- |
| De tudo, ao meu amor serei atento. Antes, e com tal zelo, e sempre, e tanto.<br>Amor | 1     |
| Que mesmo em face do maior encanto. Dele se encante mais meu pensamento.<br>enca     | 2     |

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


## Texto para CamelCase
Escreva um programa que leia um texto com espaços em branco e envie para a saída um identificador no formato camelCase, no qual não há espaços em branco, as letras iniciais de cada palavra do texto estão em maiúscula e as demais em minúscula. A letra inicial deve seguir o mesmo padrão do texto original. Considere que não espaços em branco no início e no final do texto, porém pode haver mais de um espaço em branco entre as palavras.

**Exemplos de entrada e saída:**

| Entrada              | Saída              |
| -------------------- | ------------------ |
| contador de palavras | contadorDePalavras |
| ZIG    ZAG           | ZigZag             |

## CamelCase para texto
Escreva um programa que leia uma palavra no formato camelCase e envie para a saída o texto com espaços em branco correspondente. A letra inicial deve seguir o mesmo padrão do texto original, porém as demais devem ser minúsculas.

**Exemplos de entrada e saída:**

| Entrada            | Saída                |
| ------------------ | -------------------- |
| contadorDePalavras | contador de palavras |
| ZigZag             | Zig zag              |

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

## Multiplexador
Um multiplexador é dispositivo que combina as sinais de múltiplas fontes em um único canal de saída. Crie um programa que simula um multiplexador para dois canais de entrada, representados, cada um, por uma string.
 A saída do multiplexador será os caracteres alternados dos dois canais: o 1º caractere de um, seguido do 1º caractere do outro, depois o 2º de um, seguido do 2º do outro, depois o 3º... e assim por diante, até o término de um dos canais. Quando um dos canais terminar (não tiver mais caractere a processar), o canal de saída será ocupado pelos dados do canal remanescente (os caracteres finais do outro texto serão enviados).

**Exemplos de entrada e saída:**

| Entrada             | Saída            |
| ------------------- | ---------------- |
| LSJDUQ<br>PAO       | LPSAJODUQ        |
| aujdhj<br>slfg      | asuljfdghj       |
| aaaAA<br>BBBbbbCCCC | aBaBaBAbAbAbCCCC |



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

