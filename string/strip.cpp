#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase;
    getline(cin,frase);
    int tamanho = frase.size();
    int inicio = 0;
    int fim = tamanho-1;
    while(inicio < tamanho-1 && frase[inicio] == ' '){
        inicio++;
    }
    while(fim >= 0 && frase[fim] == ' '){
        fim--;
    }
    frase = frase.substr(inicio,fim - inicio + 1);
    cout << frase << endl;
    return 0;
}