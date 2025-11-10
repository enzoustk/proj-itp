#include <iostream>
using namespace std;

int main(){
    int n1,n2;
    cin >> n1 >> n2;

    if (n1 > n2){
        for (int i = n1; i >= n2; i--){
            cout << i << " ";
        }
    }
    else if (n2 > n1){
        for(int i = n1; i <= n2; i++){
            cout << i << " ";
        }
    }
    else if (n2 == n1){
        cout << n2;
    }

    return 0;
}