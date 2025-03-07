/* Pedidos.h */
#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <string>
#include <vector>
#include "Herramienta.h"
#include <ctime>

class Pedido {
public:
    std::string NoPedido;
    std::string destinatario;
    std::vector<std::pair<Herramienta, int>> herramientas;
    std::time_t fechaPedido;
    std::time_t fechaEntrega;
    std::string estado; //en proceso, entregado, cancelado
    std::string causa;//causa de cancelacion
    double costoHerramientas;
    double costoEnvio; //dependera del peso y la distancia
    double costoTotal; //costo de herraminetas + costo de envio
    double pesoTotal; //maximo 2000kg

    Pedido(std::string noPedido, 
        std::string dest, 
        std::vector<std::pair<Herramienta, int>> herramientasSeleccionadas,
        std::time_t fPedido, 
        std::time_t fEntrega, 
        std::string est, 
        std::string cau, 
        double cHerr, 
        double cEnv, 
        double cTotal, 
        double pTotal)
    : NoPedido(noPedido), destinatario(dest), herramientas(herramientasSeleccionadas), 
    fechaPedido(fPedido), fechaEntrega(fEntrega), estado(est), causa(cau), costoHerramientas(cHerr), 
    costoEnvio(cEnv), costoTotal(cTotal), pesoTotal(pTotal) {}

};

#endif /* PEDIDOS_H */
