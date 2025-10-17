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
    //Parametros: biblioteca (quantidade = 3; livros[0] = {"Senhor dos Anéis ... "}, ...), AUTOR (tipoBusca == 0), "Orwell")
    Livros resultado;
    resultado.quantidade = 0;
    
    //Delimitando o tamanho do array de livros 
    biblioteca.livros[biblioteca.quantidade];
    int iRes = 0;

    if (tipoBusca == AUTOR) {
        for (int i=0; i<biblioteca.quantidade;i++) {
            //O método find() retorna a string "npos" se a string procurada não existir na string completa.
            if (biblioteca.livros[i].autor.find(palavra) != string::npos) {
                //biblioteca.livros[0].autor = "J.R.R Tolkien"
                //indice de resultado != indice de biblioteca
                if (biblioteca.livros[i].disponivel) {
                    resultado.quantidade++;
                    resultado.livros[iRes] = biblioteca.livros[i];
                    iRes++;
                }
            }
        }
        return resultado;
    }
    
    
    
    else {
        for (int i=0; i<biblioteca.quantidade;i++) {
            //O método find() retorna a string "npos" se a string procurada não existir na string completa.
            if (biblioteca.livros[i].titulo.find(palavra) != string::npos) {
                if (biblioteca.livros[i].disponivel) {
                    resultado.quantidade++;
                    resultado.livros[iRes] = biblioteca.livros[i];
                    iRes++;
                }
            }
        }
        return resultado;
    }
}


TEST_CASE("Buscar livros por autor") {
    Livros biblioteca = {3, {
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 1216, true},
        {"1984", "George Orwell", 1949, 328, true},
        {"A Revolução dos Bichos", "George Orwell", 1945, 112, false}
    }};
    Livros resultado = buscarLivros(biblioteca, AUTOR, "Orwell");
    CHECK(resultado.quantidade == 1);
    CHECK(resultado.livros[0].titulo == "1984");
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
