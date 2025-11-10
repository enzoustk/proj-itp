#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    float v[n];
    bool dobra = true;
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    for (int i = 0; i < (n/2);i++){
        if(v[i] != v[n-i-1]){
            dobra = false;
            break;
        }
    }
    if (dobra){
        cout << "Vetor de dobra";
    }else{
        cout << "Vetor comum";
    }
    return 0; 
    }



// para olhar o se o primeiro elemento eh igual ao  ultimo pega o total da array tira -1 (da ordem) e o numero do elemento na ordem.
// for (i = 0,j = n-1; i < n/2;i++,j--){
// if (v[i] != v[j]) dobra = false