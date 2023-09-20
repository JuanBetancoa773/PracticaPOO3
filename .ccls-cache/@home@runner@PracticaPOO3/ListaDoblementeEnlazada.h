#ifndef LISTADOBLEMENTEENLAZADA_H
#define LISTADOBLEMENTEENLAZADA_H

#include "Nodo.h"

class ListaDoblementeEnlazada {
public:
    ListaDoblementeEnlazada();
    ~ListaDoblementeEnlazada();
    void insertarEvento(int datos, std::string cientifico);
    void imprimirLista();
    void mostrarEventosTipoA();
    void mostrarEventosTipoB();
    void encontrarSingularidad();
    void mostrarEventosTipoC();
    int contarEventosTipoC();
private:
    Nodo* primerEvento;
    Nodo* ultimoEvento;
    int cantidadEventosA;
    int cantidadEventosB;
    int cantidadEventosC;
    bool esPrimo(int num);
    bool esCoprimo(int a, int b);
};

#endif
