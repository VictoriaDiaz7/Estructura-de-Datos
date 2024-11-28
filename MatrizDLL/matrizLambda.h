/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION:  Lunes,  18 de noviembre de 2024
 * FECHA MODIFICACION: Lunes,  18 de noviembre de 2024
 * Nivel: TERCERO     NRC: 1992
 *************************/
#ifndef MATRIZ_LAMBDA_H
#define MATRIZ_LAMBDA_H

#include <vector>
#include <functional>  // Necesario para std::function

template <typename T>
class Matriz {
private:
    std::vector<std::vector<T>> matriz;
    int filas;
    int columnas;

public:
    // Constructor
    Matriz(int f, int c);

    // Métodos de acceso/modificación
    T getValor(int fila, int columna) const;
    void setValor(int fila, int columna, T valor);

    // Método para obtener la matriz interna
    const std::vector<std::vector<T>>& getMatriz() const { return matriz; }

    // Métodos para operaciones con lambda
    template <typename Operacion>
    void aplicarOperacion(Operacion operacion);

    template <typename Operacion>
    Matriz<T> combinarCon(const Matriz<T>& otraMatriz, Operacion operacion) const;

    // Método para imprimir la matriz
    void imprimir() const;
};

#endif // MATRIZ_LAMBDA_H
