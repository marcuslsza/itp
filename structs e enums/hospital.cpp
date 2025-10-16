#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>

const int MAX_SIZE = 10;

struct Paciente {
    std::string nome;
    float peso;
};


struct Clinica {
    int n_pacientes;
    Paciente listaDePacientes[MAX_SIZE];
};

float calcularMediaPesos(Clinica clinica) {
    float total = 0;
    clinica.listaDePacientes[clinica.n_pacientes];
    
    for (int i=0;i<clinica.n_pacientes;i++) {
        total += clinica.listaDePacientes[i].peso;
    }
    
    return total/clinica.n_pacientes;
}


TEST_CASE("Calcular média dos pesos dos clientes") {
    Clinica clinica = {
      3,
      {{"Fulano", 60.5}, {"Beltrano", 75.0}, {"Sicrano", 82.3}}
    };
    float media = calcularMediaPesos(clinica);
    CHECK(media == doctest::Approx(72.6).epsilon(0.1));
}