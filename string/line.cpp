#include <iostream>
#include <string>
using namespace std;


void lower(string &frase){
    for (char &c : frase){
        c = tolower(c);
    }
}

int cont(string &frase, string palavra){
    int pos = frase.find(palavra);
    int contador = 0;
    while(pos != -1){
        contador++;
        pos = frase.find(palavra,pos+1);
    }
    return contador;
}

int main(){
    string frase,palavra;
    getline(cin,frase);
    cin >> palavra;
    lower(frase);
    lower(palavra);
    cout << cont(frase,palavra) << endl;
    return 0;
}