#include <iostream>
using namespace std;

int mdc(int a,int b){
    int resultado = 1;
    if(a == 0 || b == 0){
        return 1;
    }
    for (int i = 1;i <= a;i++){
        if ((a % i == 0) && (b % i == 0)){
            resultado = i;
        }
    }
    return resultado;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << mdc(a,b) << endl;
}