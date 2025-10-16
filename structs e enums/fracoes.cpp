#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
using namespace std;

struct Fracao {
    int numerador, denominador;
};

Fracao multiplicar(Fracao frac1, Fracao frac2) {
    Fracao resultado;
    
    resultado.numerador = frac1.numerador*frac2.numerador;
    resultado.denominador = frac1.denominador*frac2.denominador;
    
    return resultado;
}

TEST_CASE("Multiplicação de frações") {
    Fracao f1 = {2, 3};
    Fracao f2 = {4, 5};
    Fracao resultado = multiplicar(f1, f2);
    CHECK(resultado.numerador == 8);
    CHECK(resultado.denominador == 15);
}
