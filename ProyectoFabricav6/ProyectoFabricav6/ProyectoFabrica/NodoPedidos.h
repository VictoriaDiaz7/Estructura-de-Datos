/* NodoPedido.h */
#ifndef NODOPEDIDO_H
#define NODOPEDIDO_H
#include "Pedidos.h"

class NodoPedido {
public:
    Pedido pedido;
    NodoPedido* anterior;
    NodoPedido* siguiente;
    
    NodoPedido(Pedido p) : pedido(p), anterior(nullptr), siguiente(nullptr) {}
};

#endif /* NODOPEDIDO_H */