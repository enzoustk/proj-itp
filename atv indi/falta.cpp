#include <iostream>
using namespace std;

int main(){
    int n;
    char matriz [4][4];
    for (int i = 1;i < 4;i++){
        for (int j = 0;j < 4;j++){
            cin >> matriz[i][j];
        }
    }
    cin >> n;
    for (int h = 0;h < n;h++){
        int i,j;
        char letra;
        bool verificador = false;
        cin >> i >> j >> letra;
        if (matriz [i][j] != '.'){
            cout << "Jogada inválida!" << endl;
            continue;
        }
        matriz[i][j] = letra;
        if(matriz [i][1] == letra || matriz[i][2] == letra ||matriz [i][3] == letra){
            cout << "Boa jogada, vai vencer!" << endl;
            verificador = true;
        }
        if(matriz [1][j] == letra && matriz[2][j] == letra && matriz [3][j] == letra){
            cout << "Boa jogada, vai vencer!" << endl;
            verificador = true;
        }
        if(matriz [1][1] == letra && matriz[2][2] == letra  && matriz [3][3] == letra){
            verificador = true;
        }
        if(verificador){
            cout << "Boa jogada, vai vencer!" << endl;
        }else{
            cout << "Continua o jogo." << endl;
        }
        matriz[i][j] = '.';
    }
    return 0;
}