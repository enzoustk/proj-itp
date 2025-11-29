#include <iostream>
#include <ramdom>
#include <cmath>
#include <fstream>

class Terreno{
    private:
    int n;
    int tamanho;
    int** altitude;

    void alocar(){
        altitude = new int*[tamanho];
        for(int i = 0;i < tamanho;i++){
            altitude[i] = new int[tamanho];
            for(int j = 0; j < tamanho;j++){
                altitude[i][j] = 0;
            }    
        }
    }
    
    void desalocar(){
        for(int i = 0;i < tamanho;i++){
            delete[] altitude[i];
        }
        delete[] altitude;
        altitude = nullptr;
        tamanho = 0;
        n = 0;
    }

    void diamond(int x,int y){}

    void square(){}

    public:
    int obterLargura{
        return tamanho;
    }

    int obterProfundidade{
        return tamanho;
    }

    Terreno() : n(0), tamanho(0), altitude(nullptr){}

    Terreno(int numero) : n(numero), altitude(nullptr){
        tamanho = pow(2,n) + 1;
        alocar();
    }
    
    ~Terreno(){
        desalocar();
    }
};