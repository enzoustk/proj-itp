#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

struct Cor{
    int r;
    int g;
    int b; 
};

class Paleta{
    int tamanho;
    int capacidade;
    Cor* cores;

    void aumentaCapacidade(){
        capacidade *=2;
        Cor* novo= new Cor[capacidade];
        for (int i =0;i < tamanho;i++){
            novo[i]=cores[i];
        }
        delete[] cores;
        cores=novo; 
    }
public:
    int obterTamanho(){
        return tamanho;
    }

    Cor obterCor(int indice){
        if(indice < 0 || indice >= tamanho){
            return Cor{0,0,0};
        }
        return cores[indice];
    }
    Paleta(int capinicial = 2) : tamanho(0),capacidade(capinicial){
        cores= new Cor[capacidade];
    }

    void adicionarCor(Cor cor){
        if(tamanho >= capacidade){
            aumentaCapacidade();
        }
       cores[tamanho] = cor;
         tamanho++;
    }
     ~Paleta(){
        delete[] cores;}
    
        Paleta(const string& nomeArquivo): tamanho(0),capacidade(2){
        cores = new Cor[capacidade];
        ifstream arquivo(nomeArquivo);
        if(!arquivo.is_open()){
            return;
        }
    
        string linha;
        while(getline(arquivo,linha)){
        if (linha.empty()){
            continue;
        }
        stringstream conversor;
        int r,g,b;
        
        conversor << linha.substr(1,2);
        conversor >> hex >> r;
        conversor.clear();

        conversor << linha.substr(3,2);
        conversor >> hex >> g;
        conversor.clear();

        conversor << linha.substr(5,2);
        conversor >> hex >> b;
        conversor.clear();

        adicionarCor(Cor{r,g,b});
        }
    }
};
