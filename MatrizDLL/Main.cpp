/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION:  Lunes,  18 de noviembre de 2024
 * FECHA MODIFICACION: Lunes,  18 de noviembre de 2024
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include "matrizLambda.h"
#include "MatrizDLL.h"
#include <iostream>

int main() {
    // Crear matrices de 3x3
    Matriz<int> matriz1(3, 3);
    Matriz<int> matriz2(3, 3);

    // Pedir al usuario que ingrese los valores de las matrices
    std::cout << "Ingrese los valores para la primera matriz (3x3):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int valor;
            std::cout << "Elemento [" << i << "][" << j << "]: ";
            std::cin >> valor;
            matriz1.setValor(i, j, valor);
        }
    }

    std::cout << "Ingrese los valores para la segunda matriz (3x3):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int valor;
            std::cout << "Elemento [" << i << "][" << j << "]: ";
            std::cin >> valor;
            matriz2.setValor(i, j, valor);
        }
    }

    // Mostrar las matrices
    std::cout << "\nMatriz 1:\n";
    matriz1.imprimir();
    std::cout << "\nMatriz 2:\n";
    matriz2.imprimir();

    // Resultados de las operaciones
    std::vector<std::vector<int>> resultado;

    // Usar getMatriz() para obtener acceso a las matrices internas
    sumarMatrices(matriz1.getMatriz(), matriz2.getMatriz(), resultado);
    std::cout << "\nResultado de la suma:\n";
    for (const auto& fila : resultado) {
        for (int val : fila) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Resta
    resultado.clear();
    restarMatrices(matriz1.getMatriz(), matriz2.getMatriz(), resultado);
    std::cout << "\nResultado de la resta:\n";
    for (const auto& fila : resultado) {
        for (int val : fila) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Multiplicación
    resultado.clear();
    multiplicarMatrices(matriz1.getMatriz(), matriz2.getMatriz(), resultado);
    std::cout << "\nResultado de la multiplicacion:\n";
    for (const auto& fila : resultado) {
        for (int val : fila) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
