#include <iostream>
using namespace std;

int main(){
    int equipes;
    int corrida = 0;
    int salto = 0;
    int lanca = 0;

    cin >> equipes;
    
    for (int i = 0; i < equipes;i++){
        char tipo;

        while (true){
            cin >> tipo;
            if (tipo == 'F'){
                break;
            }
            if (tipo == 'C'){
                corrida++;
            }
            else if(tipo == 'S'){
                salto++;
            }
            else if(tipo == 'L'){
                lanca++;
            }

        
        }
        
    }
    int total = lanca + corrida + salto;
    cout << corrida << " " << salto << " " << lanca << " " << total;
    return 0;
}