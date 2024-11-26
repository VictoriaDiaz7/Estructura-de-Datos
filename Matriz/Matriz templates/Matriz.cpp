/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  C�meron Victoria D�az Caizaluisa
 * FECHA CREACION: Jueves,  14 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 14 de noviembre de 2024
 * Enunciado del problema: Programa que permita realizar la suma de los elementos de una matriz
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include "Matriz.h"
#include <iostream>
#include <vector>

template <typename T>
Matriz<T>::Matriz(int f, int c) : filas(f), columnas(c) {
    matriz.resize(filas, std::vector<T>(columnas, 0));
}

template <typename T>
T Matriz<T>::getValor(int fila, int columna) const {
    return matriz[fila][columna];
}

template <typename T>
void Matriz<T>::setValor(int fila, int columna, T valor) {
    matriz[fila][columna] = valor;
}

template <typename T>
Matriz<T> Matriz<T>::suma(const Matriz<T>& otraMatriz) const {
    if (filas != otraMatriz.filas || columnas != otraMatriz.columnas) {
        std::cerr << "Las matrices no tienen el mismo tama�o para sumar." << std::endl;
        return *this;
    }

    Matriz<T> resultado(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado.setValor(i, j, this->getValor(i, j) + otraMatriz.getValor(i, j));
        }
    }
    return resultado;
}

template <typename T>
void Matriz<T>::imprimir() const {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

