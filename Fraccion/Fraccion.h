/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION: Domingo,  10 de noviembre de 2024
 * FECHA MODIFICACION: Domingo,  10 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa que permita realizar operaciones con fracciones.
 * Nivel: TERCERO     NRC: 1992
 *************************/

#ifndef FRACCION_H
#define FRACCION_H
#include <iostream>
#include <stdio.h>


template <typename T>
class Fraccion {
public:
    // Constructor
    Fraccion(T numerador = 0, T denominador = 1);

    // Getters y Setters
    T getNumerador();
    void setNumerador(T numerador);
    T getDenominador();
    void setDenominador(T denominador);

    // Método para sumar dos fracciones
    Fraccion<T> sumar(Fraccion<T> otraFraccion);
    
    // Método para restar dos fracciones
    Fraccion<T> restar(Fraccion<T> otraFraccion);
    
    // Método para multiplicar dos fracciones
    Fraccion<T> multiplicar(Fraccion<T> otraFraccion);
    
    

private:
    T numerador;
    T denominador;
    

};


#endif

