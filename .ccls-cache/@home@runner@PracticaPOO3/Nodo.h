#ifndef NODO_H
#define NODO_H

#include <string>

class Nodo {
public:
    int datos;
    std::string cientifico;
    Nodo* ptrPasado;
    Nodo* ptrFuturo;

    Nodo(int datos, std::string cientifico);
};

#endif
