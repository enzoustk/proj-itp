#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double soma = 0.0;
    int valores[10];
    double soma_h = 0.0;
    double soma_g = 1.0;
    for(int i = 0; i < 10;i++){
        cin >> valores[i];
        soma += valores[i];
        soma_h += (1.0/valores[i]);
        soma_g *= valores[i];
    }
    double media_a = soma/10.0;
    double media_h = 10.0/soma_h;
    double media_g = pow(soma_g,1.0/10.0);
    double erro_harmonico = (media_h - media_a) / media_a;
    double erro_geometrico = (media_g - media_a) / media_a;
    double erro_medio = (erro_harmonico + erro_geometrico) / 2.0;
    double erro_medio_percentual = erro_medio * 100.0;
    
    cout << fixed << setprecision(2);
    cout << "Média aritmética é " << media_a << endl;
    cout << "Média harmônica é " << media_h << endl;
    cout << "Média geométrica é " << media_g << endl;
    cout << "Erro médio é " << erro_medio_percentual << " %" << endl;

return 0;
}