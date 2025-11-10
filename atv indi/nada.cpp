#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double tempo_minimo;
    int apto = 0;
    cin >> tempo_minimo;
    double tempo_participante;

    while(true){
        cin >> tempo_participante;
        if (tempo_participante == -1){
            break;
        }
        else if (tempo_participante <= tempo_minimo){
            apto++;
        }
    }
    double serie = (apto / 8.00);
    serie = ceil(serie);
    cout << apto << " " << serie;
    return 0;
}