#include <iostream>
#include <string> // Necessário para usar o tipo 'string'

using namespace std;

int main() {
    float peso,h;
    string nova_leitura;
    int magreza = 0,normal = 0,sobrepeso = 0,obesidade = 0,total = 0;
    do{
        cin >> peso >> h >> nova_leitura;
        float imc = peso/(h*h);
        if (imc < 20){
            magreza++;
            total++;
            cout << "Magreza";
        }else if(imc >= 20 && imc < 25){
            normal++;
            cout << "Normal";
            total++;
        }else if(imc >= 25 && imc < 30){
            sobrepeso++;
            cout << "Sobrepeso";
            total++;
        }else if(imc >= 30 && imc < 35){
            obesidade++;
            cout << "Obesidade";
            total++;
        }
    }while(nova_leitura == "sim");
    if (magreza != 0){
        cout << "percentual de magreza: " << (magreza*100)/total << "%";
    }
    if (normal != 0){
        cout << "percentual de normal: " << (normal*100)/total << "%";
    }
    if (sobrepeso != 0){
        cout << "percentual de sobrepeso: " << (sobrepeso*100)/total << "%";
    }
    if (obesidade != 0){
        
    cout << "percentual de obesidade: " << (obesidade*100)/total << "%";
    }

    return 0;
}