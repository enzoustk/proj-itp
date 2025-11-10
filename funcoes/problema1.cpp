#include <iostream>
#include <vector>
#include <numeric> // Usado para otimizar o loop de leitura, mas não é estritamente necessário
using namespace std;

/**
 * @brief Calcula a soma dos divisores próprios de um número.
 * Divisores próprios são todos os divisores de um número, exceto o próprio número.
 * @param n O número para o qual a soma dos divisores será calculada.
 * @return A soma dos divisores próprios de n.
 */
int somaDivisores(int n) {
    if (n <= 1) {
        return 0;
    }
    int soma = 1; // 1 é divisor próprio de qualquer número > 1
    // Itera até n/2, pois não há divisores maiores que a metade do número
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}

/**
 * @brief Verifica se dois números são amigos.
 * Dois números são amigos se a soma dos divisores próprios de um é igual ao outro, e vice-versa.
 * @param a O primeiro número.
 * @param b O segundo número.
 * @return true se os números forem amigos, false caso contrário.
 */
bool saoAmigos(int a, int b) {
    // Um número não pode ser amigo dele mesmo
    if (a == b) {
        return false;
    }
    // A verificação usa a função somaDivisores, conforme solicitado
    return (somaDivisores(a) == b && somaDivisores(b) == a);
}

/**
 * @brief Percorre uma lista de números e encontra o primeiro par de números amigos.
 * @param numeros Um vetor de inteiros contendo a lista a ser verificada.
 * @return true se um par foi encontrado (e impresso), false caso contrário.
 */
bool encontrarNumerosAmigos(const std::vector<int>& numeros) {
    // Percorre a lista de números para encontrar um par
    for (size_t i = 0; i < numeros.size(); ++i) {
        // O segundo loop começa de 'i + 1' para evitar comparar um número com ele mesmo
        // e para não verificar o mesmo par duas vezes (ex: 220, 284 e 284, 220)
        for (size_t j = i + 1; j < numeros.size(); ++j) {
            // Usa a função saoAmigos para verificar
            if (saoAmigos(numeros[i], numeros[j])) {
                // Imprime os números amigos se encontrados
                std::cout << numeros[i] << " " << numeros[j] << std::endl;
                return true; // Encontrou um par, pode parar a busca
            }
        }
    }
    return false; // Não encontrou nenhum par
}

int main() {
    std::vector<int> listaDeNumeros;
    int tamanho;
    cin >> tamanho;


    // Lê os números da entrada até o final da entrada (Ctrl+D no Linux/macOS, Ctrl+Z no Windows)
    for(int i=0; i < tamanho;i++){
        int numero;
        cin >> numero;

        listaDeNumeros.push_back(numero);
    }

    // Chama a função principal para encontrar os números na lista
    bool parEncontrado = encontrarNumerosAmigos(listaDeNumeros);

    // Se a função retornar false, informa que não há números amigos na lista
    if (!parEncontrado) {
        std::cout << "Nao ha numeros amigos na lista." << std::endl;
    }

    return 0;
}