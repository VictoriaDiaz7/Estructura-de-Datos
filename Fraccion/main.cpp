/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:  Cámeron Victoria Díaz Caizaluisa
 * FECHA CREACION: Domingo,  10 de noviembre de 2024
 * FECHA MODIFICACION: Domingo,  10 de noviembre de 2024
 * Enunciado del problema: Mediante el uso de plantillas crear un programa que permita realizar operaciones con fracciones.
 * Nivel: TERCERO     NRC: 1992
 *************************/

#include <iostream>
#include "Fraccion.cpp"  
int main() {
    int num1, den1, num2, den2;

    
    do {
        std::cout << "Ingrese el numerador de la primera fraccion: ";
        std::cin >> num1;

        std::cout << "Ingrese el denominador de la primera fraccion: ";
        std::cin >> den1;

        if (den1 == 0) {
            std::cout << "El denominador no puede ser cero. Intente nuevamente.\n";
        }
    } while (den1 == 0);  

   
    Fraccion<int> f1(num1, den1);

    do {
        std::cout << "Ingrese el numerador de la segunda fraccion: ";
        std::cin >> num2;

        std::cout << "Ingrese el denominador de la segunda fraccion: ";
        std::cin >> den2;

        if (den2 == 0) {
            std::cout << "El denominador no puede ser cero. Intente nuevamente.\n";
        }
    } while (den2 == 0);  

    
    Fraccion<int> f2(num2, den2);

    // Sumar las fracciones
    Fraccion<int> resultado = f1.sumar(f2);
    // Restar las fracciones
    Fraccion<int> resultResta=f1.restar(f2);
    // Multiplicar las fracciones
    Fraccion<int> resultMult=f1.multiplicar(f2);
    
    std::cout << "Resultado de la suma: "
              << resultado.getNumerador() << "/"
              << resultado.getDenominador() << std::endl;
              
    
    std::cout << "Resultado de la resta: "
              << resultResta.getNumerador() << "/"
              << resultResta.getDenominador() << std::endl;
              
    
    std::cout << "Resultado de la multiplicacion: "
              << resultMult.getNumerador() << "/"
              << resultMult.getDenominador() << std::endl;
 

    return 0;
}
