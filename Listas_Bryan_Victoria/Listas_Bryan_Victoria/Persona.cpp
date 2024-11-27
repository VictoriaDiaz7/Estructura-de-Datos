/*************************
* UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Bryan Alexander Rosero Delgado, Victoria Diaz
 * FECHA CREACION: Jueves,  21 de noviembre de 2024
 * FECHA MODIFICACION: Jueves,  21 de noviembre de 2024
 * Nivel: TERCERO     NRC: 1992
 *************************/
//Persona.cpp
#include "Persona.h"

Persona::Persona() : cedula(""), nombre(""), apellido("") {}

void Persona::set_cedula(const std::string& cedula) {
    this->cedula = cedula;
}

std::string Persona::get_cedula() const {
    return cedula;
}

void Persona::set_nombre(const std::string& nombre) {
    this->nombre = nombre;
}

std::string Persona::get_nombre() const {
    return nombre;
}

void Persona::set_apellido(const std::string& apellido) {
    this->apellido = apellido;
}

std::string Persona::get_apellido() const {
    return apellido;
}

std::ostream& operator<<(std::ostream& os, const Persona& persona) {
    os << "Cédula: " << persona.cedula << "\n"
       << "Nombre: " << persona.nombre << "\n"
       << "Apellido: " << persona.apellido << "\n";
    return os;
}
