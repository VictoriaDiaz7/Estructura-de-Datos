#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>

class Interfaz {
public:
    void insertarclientes();
    void buscarclientes();
    void mostrarclientes();
    void modificarclientes();
    void eliminarclientes();
    void graficarGrafoClientes();
    void graficarRutaOptima();
    
    std::string obtenerCliente();
    void insertapedidos(std::string cliente_actual);
    void confirmarEstadopedidos(std::string cliente_actual);
    void buscarpedidos();
    void mostrarpedidos();
    void eliminarpedidos();
    void guardarRespaldo();
    void restaurarRespaldo();

    void insertarherramientas();
    void cambiarStockherramientas();
    void buscarherramientas();
    void mostrarherramientas();
    void modificarherramientas();
    void eliminarherramientas();
};

#endif // INTERFAZ_H
