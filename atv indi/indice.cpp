#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double soma = 0.0;
    int validos_encontrados = 0;
    int anos;
    cin >> anos;
    double valores[anos];
    
    for(int i=0; i < anos; i++){
        cin >> valores[i];
    }
    for(int n = 0; n < anos; n++){
        if (valores[n] != -1){
            soma += valores[n];
            validos_encontrados++;
        }
    }

    if(validos_encontrados == 0){
        cout << "A competicao nao possui dados historicos!";
    }
    else {
        double media = (soma/validos_encontrados);
        cout << fixed << setprecision(2) << media;
    }


return 0;
}