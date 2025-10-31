#include "doctest.h"
#include <string>
using namespace std;

const int MAX_NOTAS = 5;
const int MAX_ACORDES = 10;

const SequenciaAcordes GrauAcordes = {7, {
    {3, {DO, MI, SOL}},
    {3, {RE, FA, LA}},
    {3, {MI, SOL, SI}},
    {3, {FA, LA, DO}},
    {3, {SOL, SI, RE}},
    {3, {LA, DO, MI}},
    {3, {SI, RE, FA}}
 }
};

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

SequenciaAcordes gerarProgressao(string prog, Nota tom) {
    // prog := "1-2-4-6" ; '1' - 49 = 0
    
    int graus[4] = {prog[0] - 49, prog[2] - 49, prog[4] - 49, prog[6] - 49};
    
    SequenciaAcordes resultado;
    
    for (int i=0; i<4; i++) {
        resultado = {4, {GrauAcordes.acordes[graus[i]]}};
    }

    mudarTonalidade(resultado, tom);
    return resultado;
}

