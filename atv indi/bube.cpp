#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    bool troca = true;
    while(troca){
        troca = false;
        for(int i = 0;i < n-1;i++){
            int temp;
            if(a[i] > a[i+1]){
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                troca = true;
            }
        }
        if(troca){
            for(int k=0;k < n;k++){
                    cout << a[k] << " ";
                 }
                    cout << endl;
        }
    }
    return 0;
}

//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main(){
//    int n;
//    cin >> n;
//    int a[n];
//    for (int i = 0; i < n;i++){
//        cin >> a[i];
//    }
//    bool troca = true;
//    while(troca){
//        int trocadas = 0;
//        for(int i = 1;i < n-1;i++){
//            int temp;
//            if(a[i] > a[i+1]){
//                a[i+1] = temp;
//                a[i] = a[i+1];
//                temp = a[i];
//                trocadas++;
//            }
//            for(int i=0;i < n;i++){
//                cout << a[i] << " " << endl;
//            }
//        }
//        if(trocadas == 0){
//            break;
//        }
//    }
//    return 0;
//}
//