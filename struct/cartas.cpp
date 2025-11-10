#include <iostream>
using namespace std;

enum ValorCarta {
    AS = 1, C2, C3, C4, C5, C6, C7, C8, C9, C10, VALETE, DAMA, REI
};

enum NaipeCarta {
    OUROS = 1, COPAS, ESPADAS, PAUS
};

struct Carta {
    ValorCarta valor;
    NaipeCarta naipe;
};

struct Cartas {
    int quantidade;
    Carta cartas[52];
};

bool temJogo(const Cartas &cartas) {
    for (int i = 0; i < cartas.quantidade - 2; i++) {
        Carta c1 = cartas.cartas[i];
        Carta c2 = cartas.cartas[i+1];
        Carta c3 = cartas.cartas[i+2];

        bool mesmoNaipe = c1.naipe == c2.naipe && c2.naipe == c3.naipe;
        bool ehSequencia = c1.valor+1 == c2.valor && c2.valor+1 == c3.valor;

        if (mesmoNaipe && ehSequencia) {
            return true;
        }
    }
    return false;
}

NaipeCarta strToNaipe(string naipe) {
    if (naipe == "OUROS") return OUROS;
    if (naipe == "ESPADAS") return ESPADAS;
    if (naipe == "COPAS") return COPAS;
    if (naipe == "PAUS") return PAUS;
    cerr << "Erro na entrada de dados!!!!!" << endl;
    return OUROS;
}

ValorCarta strToValor(string valor) {
    // ... a completar
    return AS;
}


int main() {
    Cartas mao;

    cin >> mao.quantidade;
    for (int i = 0; i < mao.quantidade; i++) {
        string naipe, valor;
        cin >> naipe >> valor;
        mao.cartas[i].naipe = strToNaipe(naipe);
        mao.cartas[i].valor = strToValor(valor);
    }

    if (temJogo(mao)) {
        cout << "Ganhei" << endl;
    }
    else {
        cout << "Droga!" << endl;
    }

}