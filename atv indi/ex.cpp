#include <iostream>
using namespace std;

int main(){
    int n,temp;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 0;i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0; i < n-1;i++){
        bool troca = false;
        for (int j=i+1; j < n;j++){
            
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                troca = true;
           }
        }
       if (troca){
            for(int f =0; f< n;f++){
                cout << a[f] << " ";
            }
            cout << endl;
           }
    }
    return 0;
}




#include <iostream>
using namespace std;

int main(){
    int n,temp;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 0;i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0; i <= n-2;i++){
        for (int j=i+1; j <= n-1;j++){
            bool troca = false;
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                troca = true;
           }
           if (troca){
            for(int f =0; f< n;f++){
                cout << a[f] << " ";
            }
            cout << endl;
           }
        }
    }
    return 0;
}