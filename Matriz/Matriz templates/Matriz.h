/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  C�meron Victoria D�az Caizaluisa
 * FECHA CREACION: Jueves,  14 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 14 de noviembre de 2024
 * Enunciado del problema: Programa que permita realizar la suma de los elementos de una matriz
 * Nivel: TERCERO     NRC: 1992
 *************************/

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <vector>

template <typename T>
class Matriz {
private:
    std::vector<std::vector<T>> matriz;
    int filas;
    int columnas;

public:
    // Constructor
    Matriz(int f, int c);

    // M�todos de acceso/modificaci�n
    T getValor(int fila, int columna) const;
    void setValor(int fila, int columna, T valor);

    // M�todos para sumar matrices
    Matriz<T> suma(const Matriz<T>& otraMatriz) const;

    // M�todo para imprimir la matriz
    void imprimir() const;
};

#endif // MATRIZ_H
