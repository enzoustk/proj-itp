#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    int c[n];
    int sapo = 0, coelho = 0, rato = 0,total = 0; 
    for (int i = 0; i < n;i++){
        char tipo;
        cin >> c[i] >> tipo;
        if (tipo == 'S'){
            sapo += c[i];
            total += c[i];
        }else if (tipo == 'R'){
            rato += c[i];
            total += c[i];
        }else if (tipo == 'C'){
            coelho += c[i];
            total += c[i];
        }
        
    }
    float percen_coelho = (coelho * 100.00)/total;
    float percen_rato = (rato * 100.00)/total;
    float percen_sapo = (sapo * 100.00)/total;
    cout << "Total: " << total << " cobaias" << endl;
    cout << "Total de coelhos: " << coelho << endl;
    cout << "Total de ratos: " << rato << endl;
    cout << "Total de sapos: " << sapo << endl;
    cout << fixed << setprecision(2);
    cout << "Percentual de coelhos: " << percen_coelho << " %" << endl;
    cout << "Percentual de ratos: " << percen_rato << " %" << endl;
    cout << "Percentual de sapos: " << percen_sapo << " %" << endl;
    return 0;
}