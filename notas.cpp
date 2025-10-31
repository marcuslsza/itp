#include "doctest.h"
using namespace std;

const int MAX_NOTAS = 5;

enum Nota {
    DO, DO_SUSTENIDO, RE, RE_SUSTENIDO, MI, FA, FA_SUSTENIDO, SOL, SOL_SUSTENIDO, LA, LA_SUSTENIDO, SI
};

struct Acorde {
    int num_notas;
    Nota notas[MAX_NOTAS];
};

bool isMaior(Acorde acorde) {
    Nota base = acorde.notas[0];
    Nota base_mais_quatro = (Nota) ((acorde.notas[0] + 4)%12);
    Nota base_mais_sete = (Nota) ((acorde.notas[0] + 7)%12);

    if(acorde.num_notas >= 3) return false;

    if(acorde.notas[1] == base_mais_quatro && acorde.notas[2] == base_mais_sete) return true;
    return false;
}
