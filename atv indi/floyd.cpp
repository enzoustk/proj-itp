#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    int a = 1;
    cin >> n;
    if (n <= 0){
        cout << "Você entrou com "<< n << ", tente de novo na próxima";
    }
    for (int i = 1; i <= n;i++){
        for(int j = 1; j <= i;j++){
            cout << setw(2)<< a << " ";
            a++;
        }
        
        cout << endl;
    }
    return 0;
}