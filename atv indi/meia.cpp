#include <iostream>
using namespace std;

int main(){
    float material;
    int  tempo = 0;
    cin >> material;
    int meia = 0;
    while (material > 0.5){
        tempo += 50;
        material = material/2;
        meia++;
    }
    cout << tempo/60 << " minutos e " << tempo % 60 << " segundos" << meia << endl;
    return 0;
}
    