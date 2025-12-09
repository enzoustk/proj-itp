#include <iostream>
#include <string>
#include "terreno.h" 
#include "../../descricao/etapa_1/paleta.h"
#include "../../descricao/etapa_2/imagem.h"

using namespace std;

int main() {
    string arqPaleta, arqSaida;
    int n;

    cout << "=== Gerador de Terreno (Versao Ajustada) ===" << endl;

    cout << "Digite o nome do arquivo da paleta de cores: ";
    cin >> arqPaleta;

    cout << "Digite o valor de N (tamanho sera 2^N + 1): ";
    cin >> n;

    cout << "Digite o nome do arquivo da imagem PPM a ser salvo: ";
    cin >> arqSaida;

    // 1. Carregar e Validar Paleta
    Paleta paleta(arqPaleta);
    if (paleta.obterTamanho() == 0) {
        cerr << "Erro: A paleta esta vazia ou o arquivo nao existe." << endl;
        return 1;
    }
    cout << "Paleta carregada com " << paleta.obterTamanho() << " cores." << endl;

    // 2. Gerar Terreno Dinâmico
    cout << "Gerando mapa de altitudes..." << endl;
    Terreno terreno;
    
    // PEGANDO O TAMANHO DA PALETA
    double alturaMax = (double)paleta.obterTamanho();
    
    // Passamos 'alturaMax' para garantir que as montanhas usem todas as cores sem estourar
    terreno.gerarAleatorio(n, 0.5, alturaMax); 

    // 3. Gerar Imagem
    cout << "Renderizando imagem com sombreamento..." << endl;
    Imagem img = terreno.gerarImagem(paleta);

    // 4. Salvar
    if (img.salvarPPM(arqSaida)) {
        cout << "Sucesso! Imagem salva em '" << arqSaida << "'" << endl;
        cout << "Resolucao: " << img.obterLargura() << "x" << img.obterAltura() << endl;
    } else {
        cerr << "Erro ao salvar o arquivo de imagem." << endl;
        return 1;
    }

    return 0;
}