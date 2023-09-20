#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ListaDoblementeEnlazada.h"

int main() {
    std::srand(std::time(nullptr));
    ListaDoblementeEnlazada lista;

    for (int i = 3; i < 22; i++) {
        int datos = std::rand() % 100 + 1;
        int cientificoNum = std::rand() % 2 + 1;
        std::string cientifico = (cientificoNum == 1) ? "Einstein" : "Rosen";
        lista.insertarEvento(datos, cientifico);
    }

    std::cout << "Lista de Eventos:" << std::endl;
    lista.imprimirLista();

    std::cout << "\nEventos de Tipo A:" << std::endl;
    lista.mostrarEventosTipoA();

    std::cout << "\nEventos de Tipo B:" << std::endl;
    lista.mostrarEventosTipoB();

   std::cout << "\nEventos de Tipo C:" << std::endl;
    lista.mostrarEventosTipoC();

    std::cout << "\nPosibles Singularidades:" << std::endl;
    lista.encontrarSingularidad();

    return 0;
}
