#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 50;

struct Histograma {
    int arr[MAX_SIZE];
    int n_elem; // 10 elem.
};

struct Plateau {
    int indice_final, indice_inicial, valor_freq;
};

Plateau dadosPlateau(Histograma hist) {
    Plateau plato;
    bool templateau = false;

    // 10 20 50 50 50 30 15
    for (int i=0;i<hist.n_elem-1;i++) {
        if(hist.arr[i] == hist.arr[i+1]) {
            plato.indice_inicial = i;
            plato.valor_freq = hist.arr[i];
            templateau = true;
            break;
        } 
    }

    if(templateau) {
        for (int i=plato.indice_inicial;i<hist.n_elem-1;i++) {
            if(hist.arr[i] != hist.arr[i+1]) {
                plato.indice_final = i;
                break;
            }
        }
    }

    //Aqui já temos indice_inicial, indice_final e valor_freq.
    return plato;

}

int main() {
    Histograma histog;
    cin >> histog.n_elem;
    histog.arr[histog.n_elem];

    for (int i=0;i<histog.n_elem;i++) {
        cin >> histog.arr[i];
    }
    
    //Cria se um novo Plateau para armazenar o valor de retorno de dadosPlateau:
    Plateau result = dadosPlateau(histog);
    cout << result.indice_inicial << '\n';
    cout << result.indice_final << '\n';
    cout << result.valor_freq << '\n';
}