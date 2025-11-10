#include <iostream>
#include <string>
using namespace std;

int main(){
    int n = 0,s = 0;
    string nat[10];
    string surf[10];
    for (int i = 0; i < 10; i++){
        int t;
        string nome;
        cin >> t >> nome;
        if(t == 1){
            nat [n] = nome;
            n++;
        }else if(t == 2){
            surf [s] = nome;
            s++;
        }
    }
    cout << "Natação: ";
    for (int i = 0;i < n;i++){
        cout << nat[i];
         if (i != n-1){
            cout << ',';
         }
    }
    cout << endl << "Surf: ";
    for (int i = 0;i < s;i++){
         cout << surf[i] ;
         if (i != s-1){
            cout << ',';
         }
    }
    return 0;

}