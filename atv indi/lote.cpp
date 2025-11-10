#include <iostream>
using namespace std;

int main(){
    int n,temp;
    cin >> n;
    int v[n];
    int contador = 0;
    for (int i = 0; i < n;i++){
        cin >> v[i];
        if((v[i]) == 2){
             temp = i;
        }
    }   
    for (int i=(temp-1);i >= 0;i--){
        if(v[i] == 0){
            contador++;
        }else{break;}
    }
    for (int i=(temp + 1);i <= n-1;i++){
        if(v[i] == 0){
            contador++;
        }else{break;}
    }
    cout << contador << endl;
    return 0;
}