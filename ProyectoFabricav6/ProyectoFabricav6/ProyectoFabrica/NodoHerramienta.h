/* NodoHerramienta.h */
#ifndef NODOHERRAMIENTA_H
#define NODOHERRAMIENTA_H
#include "Herramienta.h"

class NodoHerramienta {
public:
    Herramienta herramienta;
    NodoHerramienta* anterior;
    NodoHerramienta* siguiente;
    
    NodoHerramienta(Herramienta h) : herramienta(h), anterior(nullptr), siguiente(nullptr) {}
};

#endif /* NODOHERRAMIENTA_H */