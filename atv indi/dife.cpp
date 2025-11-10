#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    int u[100];
    int contador = 0;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 0;i < m;i++){
        cin >> b[i];
    }
    for (int i = 0; i < n; i++){
        bool repete = false; 
        for(int k = 0;k < m;k++){
            if(a[i] == b[k]){
              repete = true;   
            }
        }
        if (!repete){
            u[contador] = a[i];
            contador++;
        }
    }
    for (int i = 0; i < m; i++){
        bool repete = false; 
        for(int k = 0;k < n;k++){
            if(b[i] == a[k]){
              repete = true;   
            }
        }
        if (!repete){
            u[contador] = b[i];
            contador++;
        }
    }
    bool troca = true;
    while(troca){
        troca = false;
        for(int i = 0;i < contador -1;i++){
             int temp;
                if(u[i] > u[i+1]){
                temp = u[i+1];
                u[i+1] = u[i];
                u[i] = temp;
                troca = true;
            }
        }
    }
    for(int c=0;c < contador;c++){
        cout << u[c] << ' ';
    }
    return 0;
}
