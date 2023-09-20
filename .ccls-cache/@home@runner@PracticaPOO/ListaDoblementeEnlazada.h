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
private:
    Nodo* primerEvento;
    Nodo* ultimoEvento;
    int cantidadEventosA;
    int cantidadEventosB;
    bool esPrimo(int num); 
};

#endif
