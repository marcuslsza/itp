#include "doctest.h"
using namespace std;

const int MAX_NOTAS = 5;
const int MAX_ACORDES = 10;

enum Nota {
    DO, DO_SUSTENIDO, RE, RE_SUSTENIDO, MI, FA, FA_SUSTENIDO, SOL, SOL_SUSTENIDO, LA, LA_SUSTENIDO, SI
};

struct Acorde {
    int num_notas;
    Nota notas[MAX_NOTAS];
};

struct SequenciaAcordes { 
    int num_acordes;
    Acorde acordes[MAX_ACORDES];
};

void mudarTonalidade(SequenciaAcordes& sequencia, Nota tonalidade) {

    for(int i = 0; i < sequencia.num_acordes;i++) {
        for(int j = 0; j < sequencia.acordes[i].num_notas; j++) {
            sequencia.acordes[i].notas[j] = (Nota) ((sequencia.acordes[i].notas[j] + tonalidade)%12);
        }
    }
}