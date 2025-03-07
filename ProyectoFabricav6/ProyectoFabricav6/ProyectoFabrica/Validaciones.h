#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include "GrafoCliente.cpp"
#include "ListaHerramientas.cpp"
#include "ListaPedidos.cpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <conio.h>

class Validaciones {
public:
    std::string ingresar_RUC();
    std::string ingresar_ID();
    std::string ingresar_NoPedido();
    std::string ingresar_NombreCliente();
    std::string ingresar_NombreHerramienta();
    std::string ingresar_Referencias();
    int ingresar_entero(char numero);//limitado para menus de opciones
    std::string ingresar_StringNumeros(int cantidad);
    std::string ingresar_StringLetras();
    double ingresar_Double();
    int ingresar_entero2();//entero ilimitado
    double referenciasIngresada1(std::string cliente, std::string referencia);
    double referenciasIngresada2(std::string cliente, std::string referencia);
    void devolverHerramientasAlStock(Pedido pedido);
    void disminuirStockEnProceso(Pedido pedido);
    std::tm obtenerFechaActual();
    std::time_t calcularFechaEntrega(std::time_t fechaCompra, double pesoTotal, double distanciaOptima);
    double calcularCostoEnvio(time_t fechaPedido, time_t fechaEntrega, double distancia, double peso);
};

#endif // VALIDACIONES_H
