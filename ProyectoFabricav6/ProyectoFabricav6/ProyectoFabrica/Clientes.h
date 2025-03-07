/* Clientes.h */
#ifndef CLIENTES_H
#define CLIENTES_H
#include <string>

class Cliente {
public:
    std::string RUC;
    std::string nombre;
    std::string Ref1;
    std::string Ref2;
    double distancia;
    double dis1;
    double dis2;
    
    Cliente(std::string ruc, std::string nom, std::string ref1, std::string ref2, double dist, double d1, double d2)
        : RUC(ruc), nombre(nom), Ref1(ref1), Ref2(ref2), distancia(dist), dis1(d1), dis2(d2) {}
};
#endif /* CLIENTES_H */