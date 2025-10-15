#include <iostream>
#include <string>
using namespace std;

struct Book {
    string autores, titulo;
    int ano, paginas;
    bool disponivel;
};

Book finder(Book livro) {

    

}

int main() {
    int n_livros;
    cin >> n_livros;
    //Array de n_livros Books.
    Book a[n_livros];

    //Pega os dados de cada livro do array.
    for (int i=0;i<n_livros;i++) {
        getline(cin, a[i].titulo);
        getline(cin, a[i].autores);
        cin >> a[i].ano;
        cin >> a[i].paginas;
        cin >> a[i].disponivel;
        cout << "\n";
    }
}