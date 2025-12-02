#include <iostream>
#include <random>
#include <cmath>
#include <fstream>

class Terreno{
    private:
    int n;
    int tamanho;
    double** altitude;

    void alocar(){
        altitude = new double*[tamanho];
        for(int i = 0;i < tamanho;i++){
            altitude[i] = new double[tamanho];
            for(int j = 0; j < tamanho;j++){
                altitude[i][j] = 0.0;
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

    void gerarQuatroCantos(double maximo = 100.0){
        std::random_device  semente;
        std::mt19937 gerador(semente());
        std::uniform_real_distribution<double> limite(-maximo,maximo);
        altitude[0][0] = limite(gerador);
        altitude[0][tamanho-1] = limite(gerador);
        altitude[tamanho-1][0] = limite(gerador);
        altitude[tamanho-1][tamanho-1] = limite(gerador);
    }

    void diamond(int x,int y,int ultimoIndice,double maximo,mt19937& gerador){
        uniform_real_distribution<double> dist(-maximo, maximo);
        
        int metade = ultimoIndice / 2;
        double media = (altitude[x][y] + 
                       altitude[x + ultimoIndice][y] + 
                       altitude[x][y + ultimoIndice] + 
                       altitude[x + ultimoIndice][y + ultimoIndice]) / 4.0;

        altitude[x + metade][y + metade] = media + dist(gerador);
    }

    void square(int x,int y,int ultimoIndice,double maximo,mt19937& gerador){
        uniform_real_distribution<double> dist(-maximo, maximo);
        int metade = ultimoIndice / 2; 
        int cx = x + metade;
        int cy = x + metade;
        if(cx < ){
            double media = (altitude[x][y] + 
                           altitude[x + ultimoIndice][y] + 
                           altitude[x][y + ultimoIndice] + 
                           altitude[x + metade][y + metade]) / 4.0;

            altitude[x][y + metade] = media + dist(gerador);
        }
    }
    void diamondSquare(int x,int y,int ultimoIndice,double maximo,mt19937& gerador){
        if (ultimoIndice <= 1){
            return;
        }
        int metade = ultimoIndice / 2;
        double novoMaximo = maximo * rugosidade;
        diamondSquare(x,y,metade,novoMaximo,gerador);
        diamondSquare(x,y+metade,metade,novoMaximo,gerador);
        diamondSquare(x + metade,y,metade,novoMaximo,gerador);
        diamondSquare(x + metade,y + metade,metade,novoMaximo,gerador);

    }
    public:
    void gerarTerreno(int N,double rugosidade){
        gerarQuatroCantos(maximo);

        
    }
    
    int obterLargura(){
        return tamanho;
    }

    int obterProfundidade(){
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