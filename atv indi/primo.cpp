#include <iostream>
#include <cmath> 

using namespace std;

int main(){
    int n,i;
    cin >> n;
    if (n <= 1 || n == 2){
        cout << "O número "<< n << " não é primo";
        return 0;
    }
    for (i = 2;i < n; i++){
        if(n % i == 0){
        cout << "O número "<< n << " não é primo";
        return 0;
        }
        
    }
    cout << "O número "<< n << " é primo";
return 0;
}



#include <iostream>
// cmath não é mais necessário se usarmos i * i <= n
// #include <cmath> 

using namespace std;

// --- A lógica foi movida para uma função limpa e reutilizável ---
bool isPrime(int n) {
    // 1. Corrigido o caso base: números <= 1 não são primos
    if (n <= 1) {
        return false;
    }

    // 2. Laço otimizado para ir até a raiz quadrada de n
    for (int i = 2; i * i <= n; i++) {
        // 3. Se encontrar um divisor, já sabemos que não é primo
        if (n % i == 0) {
            return false;
        }
    }

    // 4. Se o laço terminar sem encontrar divisores, o número é primo.
    return true;
}

int main() {
    int numero;
    cout << "Digite um numero para verificar se eh primo: ";
    cin >> numero;

    // A função main agora é simples: ela chama a função isPrime
    // e imprime o resultado com base na resposta (true ou false).
    if (isPrime(numero)) {
        cout << "O numero " << numero << " é primo." << endl;
    } else {
        cout << "O numero " << numero << " não é primo." << endl;
    }

    return 0;
}