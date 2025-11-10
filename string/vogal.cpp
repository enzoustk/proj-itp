#include <iostream>
#include <string>
using namespace std;

void lower(string& palavra){
    for (char &c : palavra){
        c = tolower(c);
    }
}
int cont(string& palavra){
    int contador = 0;
    for (char &c : palavra) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            contador++;
        }
    }
    return contador;
}
int main() {
    string palavra;
    cin >> palavra;
    lower(palavra);
    
    cout << cont(palavra) << endl;
    return 0;
}