#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include <string>
using namespace std;

const int MAX_SIZE = 50;

struct Histograma {
    int n_elem; // 10 elem.
    int arr[MAX_SIZE];
};

struct Plateau {
    int inicio, fim, valor;
};

Plateau encontrarPlateau(Histograma hist) {
    Plateau plato;
    bool templateau = false;
    plato.inicio = -1;
    plato.fim = -1;
    plato.valor = -1;

    hist.arr[hist.n_elem];

    // 10 20 50 50 50 30 15
    for (int i=0;i<hist.n_elem-1;i++) {
        if(hist.arr[i] == hist.arr[i+1]) {
            plato.inicio = i;
            plato.valor = hist.arr[i];
            templateau = true;
            break;
        } 
    }

    if(templateau) {
        for (int i=plato.inicio;i<hist.n_elem-1;i++) {
            if(hist.arr[i] != hist.arr[i+1]) {
                plato.fim = i;
                break;
            }
        }
    }

    return plato;

}

TEST_CASE("Encontrar plateau em histograma") {
    Histograma hist1 = {5, {1, 2, 2, 3, 4}};
    Plateau p1 = encontrarPlateau(hist1);
    CHECK(p1.inicio == 1);
    CHECK(p1.fim == 2);
    CHECK(p1.valor == 2);

    Histograma hist2 = {6, {1, 1, 1, 2, 3, 3}};
    Plateau p2 = encontrarPlateau(hist2);
    CHECK(p2.inicio == 0);
    CHECK(p2.fim == 2);
    CHECK(p2.valor == 1);

    Histograma hist3 = {4, {1, 2, 3, 4}};
    Plateau p3 = encontrarPlateau(hist3);
    CHECK(p3.inicio == -1);
    CHECK(p3.fim == -1);
    CHECK(p3.valor == -1);
}
