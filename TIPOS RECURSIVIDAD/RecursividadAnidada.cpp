/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION: Martes,  12 de noviembre de 2024
 * FECHA MODIFICACION: Martes, 12 de noviembre de 2024
 * Enunciado del problema: Recursividad Anidada
 * Nivel: TERCERO     NRC: 1992
 *************************/
//Recursividad Anidada
#include <iostream>
using namespace std;

int funcionAnidada(int n) {
    if (n <= 1) return 1;  // Caso base: retorna 1 si n es menor o igual a 1
    // Recursión anidada: la función se llama dentro de una llamada recursiva adicional
    return funcionAnidada(funcionAnidada(n - 1));
}

int main() {
    int n = 3;
    cout << "Resultado de la funcion anidada para n = " << n << " es: " << funcionAnidada(n) << endl;
    return 0;
}

