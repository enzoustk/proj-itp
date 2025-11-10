#include <iostream>
using namespace std;

int main(){
    int tamanho = 4;
    int atual, proximo, i;
    cin >> atual;
    for (i = 0; i < 3;i++){
        cin >> proximo;
        if (proximo >= atual){
            atual = proximo;
        }
    }
    cout << "Maior: " << atual;
    return 0;
 
}
#include <iostream>

int main() {
    const int tamanho = 4;
    int numeros[tamanho]; // 1. Cria um array para 4 inteiros

    // 2. Laço para ler e preencher o array
    for (int i = 0; i < tamanho; i++) {
        std::cin >> numeros[i];
    }

    // 3. Assume que o primeiro elemento é o maior
    int maior = numeros[0];

    // 4. Laço para percorrer o resto do array (a partir do índice 1)
    for (int i = 1; i < tamanho; i++) {
        // 5. Compara e atualiza se necessário
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }

    // 6. Imprime o resultado final
    std::cout << "Maior: " << maior << std::endl;

    return 0;
}

#include <iostream>
#include <algorithm>

int main() {
    const int tamanho = 6;
    int numeros[tamanho] = {5, 2, 8, 1, 9, 4};

    // Ordenando um array em ordem crescente
    std::sort(numeros, numeros + tamanho);

    std::cout << "Array ordenado: ";
    for (int i = 0; i < tamanho; i++) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}