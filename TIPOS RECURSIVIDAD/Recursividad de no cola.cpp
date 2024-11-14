/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION: Martes,  12 de noviembre de 2024
 * FECHA MODIFICACION: Martes, 12 de noviembre de 2024
 * Enunciado del problema: Recursividad de No cola
 * Nivel: TERCERO     NRC: 1992
 *************************/
//Recursividad de No cola: Factorial de no cola
#include <iostream>
using namespace std;

// Función para calcular el factorial de un número
int factorial(int n) {
    if (n <= 1) {
        return 1;  // Caso base
    } else {
        // Llamada recursiva y operación después de la llamada
        return n * factorial(n - 1);
    }
}

int main() {
    int numero;
    cout << "Ingresa un número para calcular su factorial: ";
    cin >> numero;

    cout << "El factorial de " << numero << " es: " << factorial(numero) << endl;
    return 0;
}

