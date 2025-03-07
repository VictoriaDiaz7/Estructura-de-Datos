/* ListaHerramientas.h */
#ifndef LISTAHERRAMIENTAS_H
#define LISTAHERRAMIENTAS_H
#include "NodoHerramienta.h"
#include <vector>

class ListaHerramientas {
private:
    NodoHerramienta* cabeza;
public:
    NodoHerramienta* getCabeza() const { return cabeza; }
    ListaHerramientas();
    bool insertar(Herramienta herramienta);
    bool eliminar(std::string id);
    NodoHerramienta* buscar(std::string criterio);
    void mostrar();
    void guardarHerramientasEnArchivo(const std::string& nombreArchivo) const;
    void cargarHerramientasDesdeArchivo(const std::string& nombreArchivo);

    // New methods
    bool cambiarStock(std::string id, int nuevoStock);
    bool modificarAtributo(std::string criterio, const std::string& atributo, const std::string& nuevoValor);
};

#endif /* LISTAHERRAMIENTAS_H */