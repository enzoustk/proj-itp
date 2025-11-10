#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int v[n];

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n - 1; i++){
        if(v[i] <= v[i+1]){
            continue; 
        } else {
            cout << i+2; // +1 elemento futuro e +1 da ordem. 
            return 0;         
        }
    }
    cout << "0"

    return 0;
}