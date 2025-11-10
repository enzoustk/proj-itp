#include <iostream>
using namespace std;

int main(){
    int n,m;
    int fatorialn = 1, fatorialm = 1;
    int soma = 0;
    while(true){
        cin >> m >> n;
        if(n == 0 && m == 0){
            break;
        }
        for(int i = 2;i <= n; i++){
            fatorialn *= i;
        }
        for(int i = 2;i <= m; i++){
            fatorialm *= i;
        }
        soma = fatorialn + fatorialm;
        cout << soma;
    }
    return 0;
}