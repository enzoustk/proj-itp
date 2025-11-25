#include <string>
#include <fstream>
#include <iostream>
using namespace std;


struct Pixel{
    int r;
    int g;
    int b;
};

class Imagem{
    int linha; // ALTURA
    int coluna; // LARGURA
    Pixel** imagem;

    void desalocar(){
        if(imagem != nullptr){
            for(int i = 0;i < linha;i++){
                delete[] imagem[i];
                }
                delete[] imagem;
                imagem = nullptr;
            }
        linha = 0;
        coluna = 0;
    }
    
    void alocar(){
        imagem = new Pixel*[linha];
        for(int i = 0;i < linha;i++){
            imagem[i] = new Pixel[coluna];
        }
    }

    public:
    Imagem() : linha(0), coluna(0),imagem(nullptr){}

    int obterAltura(){
    return linha;
    }

    int obterLargura(){
        return coluna;
    }

    Imagem(int largura,int altura) : linha(altura),coluna(largura),imagem(nullptr){
        alocar();
    }

    Pixel& operator()(int x,int y){
        return imagem[y][x];
    }

    const Pixel& operator()(int x, int y) const {
    return imagem[y][x]; 
    }

    ~Imagem(){
        desalocar();
    }


    bool lerPPM(const string& nomeArquivo){
        desalocar();
        ifstream arquivo(nomeArquivo);
        if(!arquivo.is_open()){
            return false;
        }
        string magic;
        arquivo >> magic; // IGNORA WHITE SPACE E PEGA A PRIMEIRA COISA DO ARQUIVO ATE OUTRO WHITESPACE
        if (magic != "P3"){
            arquivo.close();
            return false;
        }
        int novaLinha,novaColuna,numeroMaximo;
        arquivo >> novaColuna;
        arquivo >> novaLinha;
        linha = novaLinha;
        coluna = novaColuna;
        alocar();
        arquivo >> numeroMaximo;
        for (int i = 0;i < linha;i++){
            for(int j = 0;j < coluna;j++){
                arquivo >> imagem[i][j].r;
                arquivo >> imagem[i][j].g; 
                arquivo >> imagem[i][j].b; 
            }
        }
        arquivo.close();
        return true;
    }

    bool salvarPPM(const string& nomeArquivo){
        ofstream arquivo(nomeArquivo);
        if(!arquivo.is_open()){
            return false;
        }
        arquivo << "P3" << endl;
        arquivo << coluna << " " << linha << endl;
        int maiorValor = 0;
        for (int i = 0;i < linha;i++){
            for(int j = 0;j < coluna;j++){
                if (imagem[i][j].r > maiorValor){
                    maiorValor = imagem[i][j].r;
                }
                if (imagem[i][j].g > maiorValor){
                    maiorValor = imagem[i][j].g;
                }
                if (imagem[i][j].b > maiorValor){
                    maiorValor = imagem[i][j].b;
                }
            }
        }
        arquivo << maiorValor << endl;
        for (int i = 0;i < linha;i++){
            for(int j = 0;j < coluna;j++){
                arquivo << imagem[i][j].r << " " << imagem[i][j].g << " " << imagem[i][j].b << endl;
            }
        }
        arquivo.close();
        return true;
    }
};
