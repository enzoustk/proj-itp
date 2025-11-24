#include <string>
#include <fstream>
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
    }/////////////////////////////////////

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
        return true;
    }

    bool salvarPPM(const string& nomeArquivo) const {
    // Verifica se há imagem válida
    if (imagem == nullptr || linha == 0 || coluna == 0) {
        return false;
    }

    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        return false;
    }

    // Cabeçalho PPM (P3)
    arquivo << "P3\n";
    arquivo << coluna << " " << linha << "\n";
    arquivo << 255 << "\n";

    // Pixels
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            // Garante que os valores estão no intervalo 0..255
            int r = imagem[i][j].r;
            int g = imagem[i][j].g;
            int b = imagem[i][j].b;

            if (r < 0) r = 0; if (r > 255) r = 255;
            if (g < 0) g = 0; if (g > 255) g = 255;
            if (b < 0) b = 0; if (b > 255) b = 255;

            arquivo << r << " " << g << " " << b << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();
    return true;
    }
};
