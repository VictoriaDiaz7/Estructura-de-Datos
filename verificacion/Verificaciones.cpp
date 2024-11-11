/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Verificaciones                      *
 * Autor:                          Cámeron Victoria Díaz Caizaluisa    *
 * Fecha de creacion:              06/11/2024                          *
 * Fecha de modificacion:          08/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include "verificacion.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int verificacion::leerInt()
{
    const int INT_TAM = 12;
    char ingreso[INT_TAM] = "";
    char c;
    
    int pos = 0;
    do
    {
        c = getch();
        if (pos != INT_TAM - 1)
        {
            if (('0' <= c && c <= '9') || (c == '-' && pos == 0))
            {
                putchar(c); //
                ingreso[pos] = c;
                ingreso[++pos] = '\0';
            }
        }

        if ((c == '\b' || c == 127) && pos != 0) {
            putchar('\b');
            putchar(' ');
            putchar('\b');
            ingreso[--pos] = '\0';
        }
    } while (c != '\n' && c != '\r');

    putchar('\n');
    return atoi(ingreso);
}

float verificacion::leerFloat()
{
    const int FLOAT_TAM = 42;
    char ingreso[FLOAT_TAM] = "";
    char c;
    bool tienePunto;
    
    int pos = 0;
    do
    {
        c = getch();
        if (pos != FLOAT_TAM - 1)
        {
            if (('0' <= c && c <= '9') || (c == '-' && pos == 0))
            {
                putchar(c); //
                ingreso[pos] = c;
                ingreso[++pos] = '\0';
            }

            if (!tienePunto && (c == '.' || c == ',')) {
                c = '.';
                putchar(c); // 1
                ingreso[pos] = c;
                ingreso[++pos] = '\0';

                tienePunto = true;
            }
        }

        if ((c == '\b' || c == 127) && pos != 0) {
            putchar('\b');
            putchar(' ');
            putchar('\b');

            if (ingreso[--pos] == '.')
                tienePunto = false;
            ingreso[pos] = '\0';
        }
    } while (c != '\n' && c != '\r');

    putchar('\n');
    return atof(ingreso);
}

double verificacion::leerDouble()
{
    const int DOUBLE_TAM = 42;
    char ingreso[DOUBLE_TAM] = "";
    char c;
    bool tienePunto;

    int pos = 0;
    do
    {
        c = getch();
        if (pos != DOUBLE_TAM - 1)
        {
            if (('0' <= c && c <= '9') || (c == '-' && pos == 0))
            {
                putchar(c); //
                ingreso[pos] = c;
                ingreso[++pos] = '\0';
            }

            if (!tienePunto && (c == '.' || c == ',')) {
                c = '.';
                putchar(c); // 1
                ingreso[pos] = c;
                ingreso[++pos] = '\0';

                tienePunto = true;
            }
        }

        if ((c == '\b' || c == 127) && pos != 0) {
            putchar('\b');
            putchar(' ');
            putchar('\b');

            if (ingreso[--pos] == '.')
                tienePunto = false;
            ingreso[pos] = '\0';
        }
    } while (c != '\n' && c != '\r');

    putchar('\n');
    return atof(ingreso);
}
