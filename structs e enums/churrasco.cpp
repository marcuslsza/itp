#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>

const int MAX_ITENS = 100;

struct Item {
    std::string nome;
    float valor;
    int quantidade;
};

struct ListaItens {
    int quantidade;
    Item itens[MAX_ITENS];
};

bool inserirItem(ListaItens &lista, Item item) {
    //lista.itens[lista.quantidade];
    
    if(lista.quantidade < MAX_ITENS) {
        lista.itens[lista.quantidade] = item;
        lista.quantidade++;
        return true;
    }
    return false;
}

float calcularDivisao(ListaItens lista, int qtdPessoas) {
    float total = 0;
    //lista.itens[lista.quantidade];
    for (int i=0;i<lista.quantidade;i++) {
        total += lista.itens[i].valor * lista.itens[i].quantidade;
    }
    
    return total/qtdPessoas;
}



TEST_CASE("Inserir item na lista") {
    ListaItens lista = {0};
    Item item = {"Carvão", 20.0, 2};
    CHECK(inserirItem(lista, item) == true);
    CHECK(lista.quantidade == 1);
    CHECK(lista.itens[0].nome == "Carvão");

    lista.quantidade = MAX_ITENS; // Simula lista cheia
    Item outroItem = {"Cerveja", 5.0, 10};
    CHECK(inserirItem(lista, outroItem) == false);
}

TEST_CASE("Calcular divisão dos gastos") {
    ListaItens lista = {3, {
        {"Carvão", 20.0, 2},
        {"Linguiça", 15.0, 3},
        {"Pão de Alho", 10.0, 5}
    }};
    CHECK(calcularDivisao(lista, 5) == doctest::Approx(27.0).epsilon(0.1));
}
