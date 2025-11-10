#include <iostream>
using namespace std;

int main(){
    int herois, classe, monster;
    cin >> herois >> classe >> monster;
    bool vitoria = false;
    if(herois <= 0){
        cout << "Melhor chamar Saitama!" << endl;
        return 0;
    }
    switch(monster){
        case 1:{
            if((classe >= 2) ||(classe == 1 && herois >= 3)){
            vitoria = true;
            break;
        }
        }
        case 2:{
             if((classe >= 3) || (classe == 2 && herois >= 3)){
            vitoria = true;
            break;
        }
             }
        case 3:{
             if((classe >= 4) || (classe == 3 && herois >= 3)){
            vitoria = true;
            break;
             }
            }
        case 4:{
            if((classe == 5) || (classe == 4 && herois >= 3)){
            vitoria = true;
            break;
            }
        }
        case 5:{
            if (classe == 5){
            vitoria = true;
            break;
            }
        }
    }
    if (vitoria)
    cout << "Heróis vencerão!" << endl;
    else 
    cout << "Melhor chamar Saitama!" << endl;

    return 0;
}
