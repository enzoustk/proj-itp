#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int soma = 0;
    for (int i = 1; i < n; i++){
        if(n % i == 0){
            soma += i;
        }
    }
    if(soma == n){
        cout << "é perfeito" << endl;
    }else{
        cout << "não é perfeito" << endl;
    }

}