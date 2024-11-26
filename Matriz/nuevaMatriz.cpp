/*************************
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * ALUMNO:Cámeron Victoria Diaz Caizaluisa
 * FECHA CREACION: Jueves,  14 de noviembre de 2024
 * FECHA MODIFICACION: Jueves, 14 de noviembre de 2024
 * Enunciado del problema: Programa que permita realizar la suma de los elementos de una matriz y devuelva una matriz resultante
 * Nivel: TERCERO     NRC: 1992
 *************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MAX 3

using namespace std;

void sumaRecursivaMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int f, int c)
{
    // Base de la recursion: si estamos en la primera celda
    result[f][c] = mat1[f][c] + mat2[f][c];
    if (f == 0 && c == 0)
        return;

    // Movimiento a la siguiente celda
    if (c > 0)
        sumaRecursivaMatrices(mat1, mat2, result, f, c - 1); // Mover a la izquierda en la misma fila
    else
        sumaRecursivaMatrices(mat1, mat2, result, f - 1, MAX - 1); // Mover a la ultima columna de la fila anterior
}

int main()
{
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    srand(time(0));

    // Inicializacion de las matrices con valores aleatorios entre 0 y 999
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            mat1[i][j] = rand() % 1000;
            mat2[i][j] = rand() % 1000;
        }
    }

    // Imprimir la primera matriz
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    // Imprimir la segunda matriz
    cout << "Matriz 2:" << endl;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << mat2[i][j] << "\t";
        }
        cout << endl;
    }

    // Llamada a la funcion recursiva para llenar la matriz resultante
    sumaRecursivaMatrices(mat1, mat2, result, MAX - 1, MAX - 1);

    // Imprimir la matriz resultante
    cout << "\nMatriz Resultante (Suma):" << endl;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
