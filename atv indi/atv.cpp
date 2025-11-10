#include <iostream>
using namespace std;

int main(){
  int values[4];
  for (int i = 0; i < 4; i++) {
  cin >> values[i];
  }
  for (int v: values) {
  cout << v;
  }
 return 0;
}

    int i;
    bool vip , ban;
    cin >> i >> vip >> ban;
    if (ban == true){
        cout << "Acesso negado";
        return 0;
    }
    if (i > 18){
       cout << "Acesso permitido";
       return 0;
    }
    if (i <= 18 & vip == true){
       cout << "Acesso permitido";
       return 0;
    }
    if (i <= 18){
       cout << "Acesso negado";
    }
