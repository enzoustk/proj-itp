#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase;
    getline(cin,frase);
    string texto = "";
    for(char c : frase){
        bool alta = isupper(c);
        if (texto == ""){
            texto += c;
        }else{
            if(alta){
                texto += ' ';
                c = tolower(c);
            }
            texto += c;
        }
    }
    cout << texto << endl;
    return 0;
}