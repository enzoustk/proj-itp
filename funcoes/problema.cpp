#include <iostream>
#include <string> 
#include <iomanip>
using namespace std;

int somaDivisores(int n){
    int soma = 0;
    for(int i = 1;i < n;i++){
        if (n % i == 0){
            soma += i;
        }
    }
    return soma;
}
bool saoAmigos(int a,int b){
    if (somaDivisores(a) == b && somaDivisores(b) == a){
        return true;
    }
    return false;
}
bool encontrarNumerosAmigos(int arr[], int tamanho, int &num1, int &num2){
    for (int i = 0;i < tamanho;i++){
        for (int h = i+1;h < tamanho;h++){
            if (saoAmigos(arr[i],arr[h])){
                num1 = arr[i];
                num2 = arr[h];
                return true;
            }
        }
    }
    return false;
} 




int main(){
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0;i < a;i++){
        cin >> arr[i];
    }
    int num1,num2;
    if(encontrarNumerosAmigos(arr,a,num1,num2)){
        cout << num1 << " " << num2 << endl;
    }else{
        cout << "não há números amigos na lista." << endl;
    }
    return 0;
}