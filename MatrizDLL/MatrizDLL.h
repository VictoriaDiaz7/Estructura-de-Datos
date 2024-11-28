/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION:  Lunes,  18 de noviembre de 2024
 * FECHA MODIFICACION: Lunes,  18 de noviembre de 2024
 * Nivel: TERCERO     NRC: 1992
 *************************/

#ifndef MATRIZ_DLL_H
#define MATRIZ_DLL_H

#include <vector>

extern "C" {
    __declspec(dllexport) void sumarMatrices(const std::vector<std::vector<int>>& matriz1, 
                                             const std::vector<std::vector<int>>& matriz2, 
                                             std::vector<std::vector<int>>& resultado);
    __declspec(dllexport) void restarMatrices(const std::vector<std::vector<int>>& matriz1, 
                                              const std::vector<std::vector<int>>& matriz2, 
                                              std::vector<std::vector<int>>& resultado);
    __declspec(dllexport) void multiplicarMatrices(const std::vector<std::vector<int>>& matriz1, 
                                                   const std::vector<std::vector<int>>& matriz2, 
                                                   std::vector<std::vector<int>>& resultado);
}

#endif // MATRIZ_DLL_H
