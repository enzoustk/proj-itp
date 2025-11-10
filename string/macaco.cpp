#include <iostream>
#include <string>
using namespace std;
bool avaliarPlaca(string placa){

    if (placa.size() != 8){
        return false;
    }
    for (int i = 0;i < 3;i++){
        if (!isupper(placa[i])){
            return false;
        }
    }
    if (placa[3] != '-'){
        return false;
    }
    for (int i = 4; i < 8;i++){
        if (!isdigit(placa[i])){
            return false;
        }
    }
    
    return true;
}

int main(){
    string placa;
    getline(cin,placa);
    if(avaliarPlaca(placa)){
        cout << "sim" << endl;
    }else{
        cout << "não" << endl;
    }
    return 0;
}