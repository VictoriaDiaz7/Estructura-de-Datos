/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION: Martes,  12 de noviembre de 2024
 * FECHA MODIFICACION: Martes, 12 de noviembre de 2024
 * Enunciado del problema: Recursividad Múltiple
 * Nivel: TERCERO     NRC: 1992
 *************************/
//Recursividad Multiple: Secuencia de Fibonacci
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;  // Caso base: F(0) = 0, F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursión múltiple
}

int main() {
    int numero = 6;
    cout << "Fibonacci de " << numero << " es " << fibonacci(numero) << endl;
    return 0;
}

