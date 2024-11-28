/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION:  Lunes,  18 de noviembre de 2024
 * FECHA MODIFICACION: Lunes,  18 de noviembre de 2024
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include "MatrizLambda.h"
#include <iostream>

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
template <typename Operacion>
void Matriz<T>::aplicarOperacion(Operacion operacion) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = operacion(matriz[i][j]);
        }
    }
}

template <typename T>
template <typename Operacion>
Matriz<T> Matriz<T>::combinarCon(const Matriz<T>& otraMatriz, Operacion operacion) const {
    if (filas != otraMatriz.filas || columnas != otraMatriz.columnas) {
        std::cerr << "Error: las matrices no son del mismo tamaño." << std::endl;
        return *this;
    }

    Matriz<T> resultado(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado.setValor(i, j, operacion(this->getValor(i, j), otraMatriz.getValor(i, j)));
        }
    }
    return resultado;
}

template <typename T>
void Matriz<T>::imprimir() const {
    for (const auto& fila : matriz) {
        for (const auto& elem : fila) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

// Necesitamos explícitamente instanciar las plantillas para su uso con tipos concretos.
template class Matriz<int>;
