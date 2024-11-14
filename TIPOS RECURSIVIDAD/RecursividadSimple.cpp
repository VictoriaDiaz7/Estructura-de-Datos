/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION: Martes,  12 de noviembre de 2024
 * FECHA MODIFICACION: Martes, 12 de noviembre de 2024
 * Enunciado del problema: Recursividad simple
 * Nivel: TERCERO     NRC: 1992
 *************************/
//Recursividad Simple: Cálculo del factorial
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;  // Caso base: 0! = 1 y 1! = 1
    return n * factorial(n - 1);  // Recursión: n! = n * (n-1)!
}

int main() {
    int numero = 5;
    cout << "Factorial de " << numero << " es " << factorial(numero) << endl;
    return 0;
}

