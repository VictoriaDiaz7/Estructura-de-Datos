/* NodoCliente.h */
#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H
#include "Clientes.h"

class NodoCliente {
public:
    Cliente cliente;
    NodoCliente* fabrica;
    NodoCliente* ref1;
    NodoCliente* ref2;
    
    NodoCliente(Cliente c) : cliente(c), fabrica(nullptr), ref1(nullptr), ref2(nullptr) {}
};

#endif /* NODOCLIENTE_H */