#ifndef PDF_GENERATOR_H
#define PDF_GENERATOR_H

#include <string>
#include "GrafoCliente.h"
#include "ListaHerramientas.h"
#include "ListaPedidos.h"

// Función para crear el PDF a partir de un archivo .txt
void createPDF(const std::string &inputFile);

// Función para crear el PDF de clientes
void createClientsPDF(const GrafoClientes &clientes, const std::string &outputFile);

// Función para crear el PDF de herramientas
void createToolsPDF(const ListaHerramientas &herramientas, const std::string &outputFile);

// Función para crear el PDF de pedidos
void createOrdersPDF(const ListaPedidos &pedidos, const std::string &outputFile);

#endif // PDF_GENERATOR_H
