/* GrafoClientes.h */
#ifndef GRAFOCLIENTES_H
#define GRAFOCLIENTES_H
#include "NodoClientes.h"
#include <vector>
#include <string>

class GrafoClientes {
private:
    NodoCliente* Fabrica;
public:
    std::vector<NodoCliente*> nodos;
    GrafoClientes();
    bool insertar(Cliente cliente);
    bool eliminar(std::string criterio);
    NodoCliente* buscar(std::string criterio);
    void mostrar();
    void guardarClientesEnArchivo(const std::string& nombreArchivo) const;
    void cargarClientesDesdeArchivo(const std::string& nombreArchivo);
    bool modificarAtributo(const std::string& criterio, const std::string& atributo, const std::string& nuevoValor);
    void graficarGrafoClientes();
    void graficarRutaOptima(const std::string &clienteObjetivo);
    double calcularRutaOptima(const std::string &clienteObjetivo);
    std::string ClienteAString(const Cliente& cliente);
};

#endif /* GRAFOCLIENTES_H */