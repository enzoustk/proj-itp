#include <iomanip>
#include <iostream>
using namespace std;

int main(){
    double tempo1, tempo2, tempo3;
    cin >> tempo1 >> tempo2 >> tempo3;
    // 1 2 3
    if (tempo1 <= tempo2 && tempo2 <=tempo3){ 
        cout << fixed << setprecision(1)<< "1o lugar: Competidor 1 com " << tempo1 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "2o lugar: Competidor 2 com " << tempo2 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "3o lugar: Competidor 3 com " << tempo3 << " segundos" << endl;
    } // 1 3 2
     else if (tempo1 <= tempo3 && tempo3 <= tempo2){
        cout << fixed << setprecision(1)<< "1o lugar: Competidor 1 com " << tempo1 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "2o lugar: Competidor 3 com " << tempo3 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "3o lugar: Competidor 2 com " << tempo2 << " segundos" << endl;
    } // 2 1 3 
     else if (tempo2 <= tempo1 && tempo1 <= tempo3){
        cout << fixed << setprecision(1)<< "1o lugar: Competidor 2 com " << tempo2 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "2o lugar: Competidor 1 com " << tempo1 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "3o lugar: Competidor 3 com " << tempo3 << " segundos" << endl;
    } // 2 3 1 
     else if (tempo2 <= tempo3 && tempo3 <=tempo1){
        cout << fixed << setprecision(1)<< "1o lugar: Competidor 2 com " << tempo2 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "2o lugar: Competidor 3 com " << tempo3 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "3o lugar: Competidor 1 com " << tempo1 << " segundos" << endl;
    }// 3 2 1 
     else if (tempo3 <= tempo1 && tempo1 <=tempo2){
        cout << fixed << setprecision(1)<< "1o lugar: Competidor 3 com " << tempo3 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "2o lugar: Competidor 1 com " << tempo1 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "3o lugar: Competidor 2 com " << tempo2 << " segundos" << endl;
    }
     else if (tempo3 <= tempo2 && tempo2 <= tempo1){
        cout << fixed << setprecision(1)<< "1o lugar: Competidor 3 com " << tempo3 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "2o lugar: Competidor 2 com " << tempo2 << " segundos" << endl;
        cout << fixed << setprecision(1)<< "3o lugar: Competidor 1 com " << tempo1 << " segundos" << endl;
    }// 3 1 2
    
    return 0;
}   