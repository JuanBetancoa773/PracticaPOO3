#include "ListaDoblementeEnlazada.h"
#include <iostream>
#include <cstdlib> // Para generar números aleatorios

ListaDoblementeEnlazada::ListaDoblementeEnlazada() {
    primerEvento = nullptr;
    ultimoEvento = nullptr;
    cantidadEventosA = 0;
    cantidadEventosB = 0;
}

ListaDoblementeEnlazada::~ListaDoblementeEnlazada() {
    // Implementa la liberación de memoria de los nodos si es necesario.
}

void ListaDoblementeEnlazada::insertarEvento(int datos, std::string cientifico) {
    // Implementa la inserción de un nuevo evento en la lista.
    Nodo* nuevoEvento = new Nodo(datos, cientifico);

    if (!primerEvento) {
        primerEvento = nuevoEvento;
        ultimoEvento = nuevoEvento;
    } else {
        nuevoEvento->ptrPasado = ultimoEvento;
        ultimoEvento->ptrFuturo = nuevoEvento;
        ultimoEvento = nuevoEvento;
    }

    // Actualiza las cantidades de eventos A y B según las condiciones.
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
    // Implementa la impresión de la lista de eventos.
    Nodo* actual = primerEvento;
    while (actual) {
        std::cout << "Datos: " << actual->datos << ", Cientifico: " << actual->cientifico << std::endl;
        actual = actual->ptrFuturo;
    }
}

void ListaDoblementeEnlazada::mostrarEventosTipoA() {
    // Implementa la búsqueda y muestra de eventos tipo A.
    Nodo* actual = primerEvento;
    while (actual) {
        if (actual->cientifico == "Einstein" && esPrimo(actual->datos)) {
            std::cout << "Datos: " << actual->datos << ", Cientifico: " << actual->cientifico << std::endl;
        }
        actual = actual->ptrFuturo;
    }
}

void ListaDoblementeEnlazada::mostrarEventosTipoB() {
    // Implementa la búsqueda y muestra de eventos tipo B.
    Nodo* actual = primerEvento;
    while (actual) {
        if (actual->cientifico == "Rosen" && cantidadEventosA > 0) {
            std::cout << "Datos: " << actual->datos << ", Cientifico: " << actual->cientifico << std::endl;
        }
        actual = actual->ptrFuturo;
    }
}

void ListaDoblementeEnlazada::encontrarSingularidad() {
    // Implementa la búsqueda y muestra de la secuencia que produce una singularidad.
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
                    std::cout << "Evento C: Datos=" << eventoC->datos << std::endl;
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
