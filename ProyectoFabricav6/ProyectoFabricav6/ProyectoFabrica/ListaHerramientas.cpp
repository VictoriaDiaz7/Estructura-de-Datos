/* ListaHerramientas.cpp */
#include "ListaHerramientas.h"
#include <iostream>
#include <fstream>

ListaHerramientas::ListaHerramientas() {
    cabeza = nullptr;
}


bool ListaHerramientas::insertar(Herramienta herramienta) {
    NodoHerramienta* nuevo = new NodoHerramienta(herramienta);
    if (!cabeza) {
        cabeza = nuevo;
        return true;
    }
    NodoHerramienta* temp = cabeza;
    while (temp) {
        if (temp->herramienta.ID == herramienta.ID || temp->herramienta.nombre == herramienta.nombre) {
            std::cout << "Error: Herramienta con el mismo ID o nombre ya existe." << std::endl;
            delete nuevo;
            return false;
        }
        if (!temp->siguiente) break;
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
    nuevo->anterior = temp;
    return true;
}

bool ListaHerramientas::eliminar(std::string id) {
    NodoHerramienta* temp = cabeza;
    while (temp) {
        if (temp->herramienta.ID == id) {
            if (temp->anterior) temp->anterior->siguiente = temp->siguiente;
            if (temp->siguiente) temp->siguiente->anterior = temp->anterior;
            if (temp == cabeza) cabeza = temp->siguiente;
            delete temp;
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

NodoHerramienta* ListaHerramientas::buscar(std::string criterio) {
    NodoHerramienta* temp = cabeza;
    while (temp) {
        if (temp->herramienta.ID == criterio || temp->herramienta.nombre == criterio) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

void ListaHerramientas::mostrar() {
    if (!cabeza) {
        std::cout << "No hay herramientas registradas en la lista." << std::endl;
        return;
    }

    std::cout << "Lista de herramientas disponibles:\n";
    NodoHerramienta* temp = cabeza;
    while (temp) {
        std::cout << "--------------------------------------\n";
        std::cout << "Herramienta: " << temp->herramienta.nombre << " (ID: " << temp->herramienta.ID << ")\n";
        std::cout << "  Peso: " << temp->herramienta.peso << " kg\n";
        std::cout << "  Precio: $" << temp->herramienta.precio << "\n";
        std::cout << "  Cantidad en stock: " << temp->herramienta.cantidad << "\n";
        temp = temp->siguiente;
    }
    std::cout << "--------------------------------------\n";
}


void ListaHerramientas::guardarHerramientasEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo, std::ios::out);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura.\n";
        return;
    }
    NodoHerramienta* actual = cabeza;
    while (actual) {
        archivo << actual->herramienta.ID << " " << actual->herramienta.nombre <<" "<< 
        actual->herramienta.peso << " "<<actual->herramienta.precio <<" "<< actual->herramienta.cantidad << "\n";
        actual = actual->siguiente;
    }
    archivo.close();
}

void ListaHerramientas::cargarHerramientasDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::in);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura.\n";
        return;
    }
    cabeza = nullptr;
    std::string id, nombre;
    int cantidad;
    double peso, precio;
    while (archivo >> id >> nombre >> peso >> precio>> cantidad) {
        Herramienta herramienta(id, nombre, peso, precio, cantidad);
        insertar(herramienta);
    }
    archivo.close();
}

bool ListaHerramientas::cambiarStock(std::string criterio, int nuevoStock) {
    NodoHerramienta* herramienta = buscar(criterio);
    if (herramienta) {
        herramienta->herramienta.cantidad = nuevoStock;
        return true;
    }
    std::cerr << "Error: Herramienta no encontrada." << std::endl;
    return false;
}

bool ListaHerramientas::modificarAtributo(std::string criterio, const std::string& atributo, const std::string& nuevoValor) {
    NodoHerramienta* herramienta = buscar(criterio);
    if (!herramienta) {
        herramienta = buscar(atributo);
    }
    if (!herramienta) {
        std::cerr << "Error: Herramienta no encontrada." << std::endl;
        return false;
    }

    if (atributo == "nombre") {
        herramienta->herramienta.nombre = nuevoValor;
    } else if (atributo == "peso") {
        herramienta->herramienta.peso = std::stod(nuevoValor);
    } else if (atributo == "precio") {
        herramienta->herramienta.precio = std::stod(nuevoValor);
    } else if (atributo == "cantidad") {
        herramienta->herramienta.cantidad = std::stoi(nuevoValor);
    } else {
        std::cerr << "Error: Atributo no válido." << std::endl;
        return false;
    }

    return true;
}
