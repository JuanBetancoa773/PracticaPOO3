#include "Nodo.h"

Nodo::Nodo(int datos, std::string cientifico) {
    this->datos = datos;
    this->cientifico = cientifico;
    this->ptrPasado = nullptr;
    this->ptrFuturo = nullptr;
}
