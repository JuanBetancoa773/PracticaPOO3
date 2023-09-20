#include "ListaDoblementeEnlazada.h"
#include <iostream>
#include <cstdlib>

ListaDoblementeEnlazada::ListaDoblementeEnlazada() {
    primerEvento = nullptr;
    ultimoEvento = nullptr;
    cantidadEventosA = 0;
    cantidadEventosB = 0;
}

ListaDoblementeEnlazada::~ListaDoblementeEnlazada() {

}

void ListaDoblementeEnlazada::insertarEvento(int datos, std::string cientifico) {
    Nodo* nuevoEvento = new Nodo(datos, cientifico);

    if (!primerEvento) {
        primerEvento = nuevoEvento;
        ultimoEvento = nuevoEvento;
    } else {
        nuevoEvento->ptrPasado = ultimoEvento;
        ultimoEvento->ptrFuturo = nuevoEvento;
        ultimoEvento = nuevoEvento;
    }


    if (cientifico == "Einstein") {
        if (esPrimo(datos)) {
            cantidadEventosA++;
        }
    } else if (cientifico == "Rosen") {
        if (cantidadEventosA > 0) {
            cantidadEventosB++;
        }
    }
}

void ListaDoblementeEnlazada::imprimirLista() {

    Nodo* actual = primerEvento;
    while (actual) {
        std::cout << "Datos: " << actual->datos << ", Cientifico: " << actual->cientifico << std::endl;
        actual = actual->ptrFuturo;
    }
}

void ListaDoblementeEnlazada::mostrarEventosTipoA() {

    Nodo* actual = primerEvento;
    while (actual) {
        if (actual->cientifico == "Einstein" && esPrimo(actual->datos)) {
            std::cout << "Datos: " << actual->datos << ", Cientifico: " << actual->cientifico << std::endl;
        }
        actual = actual->ptrFuturo;
    }
}

void ListaDoblementeEnlazada::mostrarEventosTipoB() {

    Nodo* actual = primerEvento;
    while (actual) {
        if (actual->cientifico == "Rosen" && cantidadEventosA > 0) {
            std::cout << "Datos: " << actual->datos << ", Cientifico: " << actual->cientifico << std::endl;
        }
        actual = actual->ptrFuturo;
    }
}

void ListaDoblementeEnlazada::encontrarSingularidad() {

    Nodo* actual = primerEvento;
    while (actual) {
        if (actual->cientifico == "Einstein" && esPrimo(actual->datos)) {
            Nodo* eventoB = actual->ptrFuturo;
            if (eventoB && eventoB->cientifico == "Rosen") {
                Nodo* eventoC = eventoB->ptrFuturo;
                if (eventoC && esPrimo(eventoC->datos)) {
                    std::cout << "Secuencia de eventos que produce una singularidad:" << std::endl;
                    std::cout << "Evento A: Datos=" << actual->datos << ", Cientifico=" << actual->cientifico << std::endl;
                    std::cout << "Evento B: Datos=" << eventoB->datos << ", Cientifico=" << eventoB->cientifico << std::endl;
                    
                }
            }
        }
        actual = actual->ptrFuturo;
    }
}

bool ListaDoblementeEnlazada::esPrimo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
