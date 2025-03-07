/* Herramienta.h */
#ifndef HERRAMIENTA_H
#define HERRAMIENTA_H
#include <string>

class Herramienta {
public:
    std::string ID;
    std::string nombre;
    double peso;
    double precio;
    int cantidad;

    // Constructor por defecto necesario para std::vector
    Herramienta() : ID(""), nombre(""), peso(0), precio(0), cantidad(0) {}

    // Constructor con parámetros
    Herramienta(std::string id, std::string nom, double p, double pre, int cant)
        : ID(id), nombre(nom), peso(p), precio(pre), cantidad(cant) {}

    // Sobrecarga de operador de comparación (para evitar duplicados en std::vector)
    bool operator==(const Herramienta& otra) const {
        return ID == otra.ID; 
    }
};

#endif /* HERRAMIENTA_H */
