#include <string>
//include <ifstream>


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
            }
        linha = 0;
        coluna = 0;
    }
    
    void alocar(){
        imagem = new Pixel*[linha];
        for(int i = 0;i < coluna;i++){
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

    Pixel& operator()(int l,int c){
        return imagem[l][c];
    }/////////////////////////////////////

    ~Imagem(){
        desalocar();
    }


    bool lerPPM(const string& nomeArquivo){
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
        int novaLinha,novaColuna;
        arquivo >> novaColuna;
        arquivo >> novaLinha;
        for (int i = 0;i < novaLinha;i++){
            for(int j = 0;j < novaColuna;j++){
                arquivo >> arquivo[i][j].r;
                arquivo >> arquivo[i][j].g; 
                arquivo >> arquivo[i][j].b; 
            }
        }
        return true;
    }
};
