#include <iostream>
using namespace std;

int main(){
    int t;
    bool av1 , av2;
    cin >> t;
    if ((t >= 0) && (t < 5)){
        cout << "iniciante";
    }
    else if ((t >= 5) && (t < 20)){
        cin >> av1;
        if(av1 == true){
            cout << "Intermediario";
        }
         else{
            cout << "Iniciante";
        }
    }
    else if(t >= 20){
        cin >> av2;
        if(av2 == true){
            cout << "Avancado";
        }
        else{
            cout << "Intermediario";
        }
    }
return 0;
}
