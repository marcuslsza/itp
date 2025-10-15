#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
using namespace std;

const int MAX_LIVROS = 10;


struct Livro {
    string titulo, autor; 
    int ano, paginas;
    bool disponivel;
};

struct Livros {
    int quantidade;
    Livro livros[MAX_LIVROS];
};

enum TipoBusca {
    AUTOR, TITULO
};

Livros buscarLivros(Livros biblioteca, TipoBusca tipoBusca, string palavra) {
    biblioteca.livros
}


TEST_CASE("Buscar livros por autor") {
    Livros biblioteca = {3, {
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 1216, true},
        {"1984", "George Orwell", 1949, 328, true},
        {"A Revolução dos Bichos", "George Orwell", 1945, 112, false}
    }};
    Livros resultado = buscarLivros(biblioteca, AUTOR, "Orwell");
    CHECK(resultado.quantidade == 2);
    CHECK(resultado.livros[0].titulo == "1984");
    CHECK(resultado.livros[1].titulo == "A Revolução dos Bichos");
}
TEST_CASE("Buscar livros por título") {
    Livros biblioteca = {3, {
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 1216, true},
        {"1984", "George Orwell", 1949, 328, true},
        {"A Revolução dos Bichos", "George Orwell", 1945, 112, false}
    }};
    Livros resultado = buscarLivros(biblioteca, TITULO, "Senhor");
    CHECK(resultado.quantidade == 1);
    CHECK(resultado.livros[0].autor == "J.R.R. Tolkien");
}
