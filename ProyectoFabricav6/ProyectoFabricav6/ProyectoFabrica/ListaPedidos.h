/* ListaPedidos.h */
#ifndef LISTAPEDIDOS_H
#define LISTAPEDIDOS_H
#include "NodoPedidos.h"
#include <vector>

class ListaPedidos {
private:
    NodoPedido* cabeza;
public:
    NodoPedido* getCabeza() const { return cabeza; }
    ListaPedidos();
    bool insertar(Pedido pedido);
    bool eliminar(std::string noPedido);    
    std::vector<NodoPedido*> buscar(std::string criterio);
    void mostrar();
    void guardarPedidoEnArchivo(const std::string& nombreArchivo);
    void cargarPedidoDesdeArchivo(const std::string& nombreArchivo);
    void guardarRespaldo();
    void restaurarRespaldo();
    bool cambiarEstado(std::string noPedido, const std::string& nuevoEstado , const std::string& causa) ;
};

#endif /* LISTAPEDIDOS_H */
