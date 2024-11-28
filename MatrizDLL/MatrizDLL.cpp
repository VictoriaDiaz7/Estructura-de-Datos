/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION:  Lunes,  18 de noviembre de 2024
 * FECHA MODIFICACION: Lunes,  18 de noviembre de 2024
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include "MatrizDLL.h"

void sumarMatrices(const std::vector<std::vector<int>>& matriz1, 
                   const std::vector<std::vector<int>>& matriz2, 
                   std::vector<std::vector<int>>& resultado) {
    int filas = matriz1.size();
    int columnas = matriz1[0].size();

    resultado.resize(filas, std::vector<int>(columnas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void restarMatrices(const std::vector<std::vector<int>>& matriz1, 
                    const std::vector<std::vector<int>>& matriz2, 
                    std::vector<std::vector<int>>& resultado) {
    int filas = matriz1.size();
    int columnas = matriz1[0].size();

    resultado.resize(filas, std::vector<int>(columnas));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void multiplicarMatrices(const std::vector<std::vector<int>>& matriz1, 
                          const std::vector<std::vector<int>>& matriz2, 
                          std::vector<std::vector<int>>& resultado) {
    int filas = matriz1.size();
    int columnas = matriz2[0].size();
    int intermedia = matriz2.size();

    resultado.resize(filas, std::vector<int>(columnas, 0));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            for (int k = 0; k < intermedia; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}
