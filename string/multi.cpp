#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase1,frase2;
    string saida = "";
    getline(cin,frase1);
    getline(cin,frase2);
    int tamanho1 = frase1.size();
    int tamanho2 = frase2.size();
    int menortamanho = tamanho1 < tamanho2 ? tamanho1 : tamanho2;
    for(int i = 0,h = 0;i < menortamanho;i++,h++){
        saida += frase1[i];
        saida += frase2[h];
    }
    if(tamanho1 > menortamanho){
        saida += frase1.substr(menortamanho);
    }else{
        saida += frase2.substr(menortamanho);
    }
    cout << saida << endl;
    return 0;
}