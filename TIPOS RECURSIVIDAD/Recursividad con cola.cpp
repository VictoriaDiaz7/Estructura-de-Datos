/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION: Martes,  12 de noviembre de 2024
 * FECHA MODIFICACION: Martes, 12 de noviembre de 2024
 * Enunciado del problema: Recursividad de cola
 * Nivel: TERCERO     NRC: 1992
 *************************/
//Recursividad con cola: Factorial de cola
#include <iostream>
using namespace std;

// Función recursiva de cola para calcular el factorial
int factorial_cola(int n, int acumulado = 1) {
    // Caso base: cuando n es 0 o 1, devuelve el acumulado
    if (n <= 1) {
        return acumulado;
    } else {
        // Llamada recursiva de cola, pasando el nuevo valor de n-1 y acumulando
        return factorial_cola(n - 1, acumulado * n);
    }
}

int main() {
    int resultado = factorial_cola(5);  // Calcula el factorial de 5
    cout << "El factorial de 5 es: " << resultado << endl;  // Imprime 120
    return 0;
}

