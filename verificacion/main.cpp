/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Verificaciones                      *
 * Autor:                          Cámeron Victoria Díaz Caizaluisa    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          08/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include "Verificaciones.cpp"
#include <iostream>

int main()
{
    
    int ch;
    
    std::cout << "Ingrese un numero entero" << std::endl;
    int num = verificacion::leerInt();
    std::cout << "El numero entero ingresado es: " << num << std::endl;

    std::cout << "Ingrese un flotante" << std::endl;
    float flt = verificacion::leerFloat();
    std::cout << "El flotante de precision simple ingresado es: " << flt << std::endl;

    std::cout << "Ingrese un flotante" << std::endl;
    double dbl = verificacion::leerDouble();
    std::cout << "El flotante de precision doble ingresado es: " << dbl << std::endl;
}
