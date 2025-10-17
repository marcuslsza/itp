#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>

const int MAX_CONTATOS = 50;

class Contato {
    std::string nome, telefone, email;
};


class ListaContatos {
    int quantidade;
    Contato contatos[MAX_CONTATOS];
    public:
        ListaContatos() {
            quantidade = 0;
        }

        bool adicionarContato(Contato contato) {
            if (quantidade >= MAX_CONTATOS) {
                return false;
            }
            return true;
        }
};






TEST_CASE("Gerenciar contatos") {
    ListaContatos lista;
    Contato c1 = {"Fulano", "1234-5678", "fulano@example.com"};
    Contato c2 = {"Beltrano", "9876-5432", "beltrano@example.com"};
    Contato c3 = {"Sicrano", "5555-5555", "sicrano@example.com"};

    CHECK(lista.adicionarContato(c1) == true);
    CHECK(lista.adicionarContato(c2) == true);
    CHECK(lista.adicionarContato(c3) == true);
    CHECK(lista.quantidade == 3);

    CHECK(lista.removerContato("Beltrano") == true);
    CHECK(lista.contatos.quantidade() == 2);

    Contato fulano, beltrano;

    CHECK(lista.buscarContato("Fulano", fulano) == true);
    CHECK(fulano.email == "fulano@example.com");
    CHECK(fulano.telefone == "1234-5678");

    CHECK(lista.buscarContato("Beltrano", beltrano) == false);
    CHECK(lista.removerContato("Beltrano") == false);
}
