/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION: Domingo,  10 de noviembre de 2024
 * FECHA MODIFICACION: Domingo,  10 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa que permita realizar operaciones con fracciones.
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include <iostream>
#include "Fraccion.h"
#include <stdio.h>
using namespace std;

// Constructor
template <typename T>
Fraccion<T>::Fraccion(T num, T den) : numerador(num), denominador(den) {
}

// Getters
template <typename T>
T Fraccion<T>::getNumerador() {
    return numerador;
}

template <typename T>
T Fraccion<T>::getDenominador() {
    return denominador;
}

// Setters
template <typename T>
void Fraccion<T>::setNumerador(T num) {
    numerador = num; 
}

template <typename T>
void Fraccion<T>::setDenominador(T den) {
    denominador = den; 
}

// Método para sumar dos fracciones
template <typename T>
Fraccion<T> Fraccion<T>::sumar(Fraccion<T> otraFraccion) {
    T nuevoNumerador = numerador * otraFraccion.denominador + otraFraccion.numerador * denominador;
    T nuevoDenominador = denominador * otraFraccion.denominador;
    return Fraccion<T>(nuevoNumerador, nuevoDenominador);
}
// Método para restar dos fracciones
template <typename T>
Fraccion<T> Fraccion<T>::restar(Fraccion<T> otraFraccion) {
    T nuevoNumerador = numerador * otraFraccion.denominador - otraFraccion.numerador * denominador;
    T nuevoDenominador = denominador * otraFraccion.denominador;
    return Fraccion<T>(nuevoNumerador, nuevoDenominador);
}

//Método para multiplicar dos fracciones
template <typename T>
Fraccion<T> Fraccion<T>::multiplicar(Fraccion<T> otraFraccion) {
    T nuevoNumerador = numerador * otraFraccion.numerador;
    T nuevoDenominador = denominador * otraFraccion.denominador;
    return Fraccion<T>(nuevoNumerador, nuevoDenominador);
}








