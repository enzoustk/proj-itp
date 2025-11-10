#include <iostream>
using namespace std;

int main(){
    int n;
    char c;
    cin >> n >> c;
    int tamanho = n-1;
    if (tamanho < 0){
        return 0;
    }
    for (int i=0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            if((j==i) || (j+i == tamanho-1)){
                cout << c; 
            }else{
                cout << " ";
            }
            
        }
        cout << endl;
    }
    return 0;
}
    





