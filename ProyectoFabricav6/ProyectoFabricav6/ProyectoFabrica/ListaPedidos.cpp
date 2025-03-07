/* ListaPedidos.cpp */
#include "ListaPedidos.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <sys/stat.h>
#include <dirent.h>
#include <iomanip> // Para std::put_time

ListaPedidos::ListaPedidos() {
    cabeza = nullptr;
}

bool ListaPedidos::insertar(Pedido pedido) {
    NodoPedido* nuevo = new NodoPedido(pedido);
    if (!cabeza) {
        cabeza = nuevo;
        return true;
    }
    NodoPedido* temp = cabeza;
    while (temp) {
        if (temp->pedido.NoPedido == pedido.NoPedido) {
            std::cout << "Error: Número de pedido ya existe." << std::endl;
            delete nuevo;
            return false;
        }
        if (!temp->siguiente) break;
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
    nuevo->anterior = temp;
    return true;
}

bool ListaPedidos::eliminar(std::string noPedido) {
    NodoPedido* temp = cabeza;
    while (temp) {
        if (temp->pedido.NoPedido == noPedido) {
            if (temp->anterior) temp->anterior->siguiente = temp->siguiente;
            if (temp->siguiente) temp->siguiente->anterior = temp->anterior;
            if (temp == cabeza) cabeza = temp->siguiente;
            delete temp;
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

std::vector<NodoPedido*> ListaPedidos::buscar(std::string criterio) {
    std::vector<NodoPedido*> resultados;
    NodoPedido* temp = cabeza;
    while (temp) {
        if (temp->pedido.NoPedido == criterio || temp->pedido.destinatario == criterio) {
            resultados.push_back(temp);
        }
        temp = temp->siguiente;
    }
    return resultados;
}

#include <iomanip> // Para std::put_time

void ListaPedidos::mostrar() {
    if (!cabeza) {
        std::cout << "No hay pedidos registrados en la lista." << std::endl;
        return;
    }

    std::cout << "Lista de pedidos:\n";
    NodoPedido* temp = cabeza;
    while (temp) {
        std::cout << "--------------------------------------\n";
        std::cout << "Pedido No: " << temp->pedido.NoPedido << "\n";
        std::cout << "Destinatario: " << temp->pedido.destinatario << "\n";
        
        std::time_t fechaPedido = temp->pedido.fechaPedido;
        std::time_t fechaEntrega = temp->pedido.fechaEntrega;
        
        std::tm* fechaPedido_tm = std::localtime(&fechaPedido);
        std::cout << "Fecha de Pedido: " << std::put_time(fechaPedido_tm, "%d/%m/%Y") << "\n";
        std::tm* fechaEntrega_tm = std::localtime(&fechaEntrega);
        std::cout << "Fecha de Entrega: " << std::put_time(fechaEntrega_tm, "%d/%m/%Y") << "\n";

        std::cout << "Estado: " << temp->pedido.estado;
        if (temp->pedido.estado == "cancelado") {
            std::cout << " (Causa: " << temp->pedido.causa << ")";
        }
        std::cout << "\n";

        std::cout << "Costo Herramientas: $" << temp->pedido.costoHerramientas << "\n";
        std::cout << "Costo Envío: $" << temp->pedido.costoEnvio << "\n";
        std::cout << "Costo Total: $" << temp->pedido.costoTotal << "\n";
        std::cout << "Peso Total: " << temp->pedido.pesoTotal << " kg\n";

        // Listar herramientas en el pedido
        std::cout << "Herramientas incluidas:\n";
        for (const auto& herramientaCantidad : temp->pedido.herramientas) {
            const Herramienta& herramienta = herramientaCantidad.first;
            int cantidad = herramientaCantidad.second;

            std::cout << "  - " << herramienta.nombre << " (ID: " << herramienta.ID 
                      << "), Cantidad: " << cantidad 
                      << ", Peso: " << herramienta.peso << " kg\n";
        }

        temp = temp->siguiente;
    }
    std::cout << "--------------------------------------\n";
}



void ListaPedidos::guardarPedidoEnArchivo(const std::string& nombreArchivo){
    std::ofstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para guardar los pedidos." << std::endl;
        return;
    }
    
    NodoPedido* temp = cabeza;
    while (temp) {
        Pedido p = temp->pedido;
        archivo << p.NoPedido << "|" << p.destinatario << "|" << p.fechaPedido << "|" 
                << p.fechaEntrega << "|" << p.estado << "|" << p.causa << "|" 
                << p.costoHerramientas << "|" << p.costoEnvio << "|" << p.costoTotal << "|" 
                << p.pesoTotal << "|";
        
        // Guardar herramientas
        for (size_t i = 0; i < p.herramientas.size(); ++i) {
            archivo << p.herramientas[i].first.ID << "," << p.herramientas[i].first.nombre << ","
                    << p.herramientas[i].first.peso << "," << p.herramientas[i].first.precio << ","
                    << p.herramientas[i].second; // Cantidad
            if (i < p.herramientas.size() - 1) archivo << ";";
        }
        
        archivo << "\n";
        temp = temp->siguiente;
    }
    archivo.close();
}

void ListaPedidos::cargarPedidoDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para cargar los pedidos." << std::endl;
        return;
    }
    
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string noPedido, destinatario, estado, causa, herramientasStr;
        std::time_t fechaPedido, fechaEntrega;
        double costoHerr, costoEnv, costoTotal, pesoTotal;
        
        std::getline(ss, noPedido, '|');
        std::getline(ss, destinatario, '|');
        ss >> fechaPedido; ss.ignore();
        ss >> fechaEntrega; ss.ignore();
        std::getline(ss, estado, '|');
        std::getline(ss, causa, '|');
        ss >> costoHerr; ss.ignore();
        ss >> costoEnv; ss.ignore();
        ss >> costoTotal; ss.ignore();
        ss >> pesoTotal; ss.ignore();
        
        std::vector<std::pair<Herramienta, int>> herramientas;
        while (std::getline(ss, herramientasStr, ';')) {
            std::stringstream ssHerr(herramientasStr);
            std::string id, nombre;
            double peso, precio;
            int cantidad;
            
            std::getline(ssHerr, id, ',');
            std::getline(ssHerr, nombre, ',');
            ssHerr >> peso; ssHerr.ignore();
            ssHerr >> precio; ssHerr.ignore();
            ssHerr >> cantidad;
            
            herramientas.emplace_back(Herramienta(id, nombre, peso, precio, cantidad), cantidad);
        }
        
        Pedido nuevoPedido(noPedido, destinatario, herramientas, fechaPedido, fechaEntrega, 
                           estado, causa, costoHerr, costoEnv, costoTotal, pesoTotal);
        insertar(nuevoPedido);
    }
    archivo.close();
}


void ListaPedidos::guardarRespaldo(){
    struct stat info;
    if (stat("respaldos", &info) != 0) {
        mkdir("respaldos");
    }

    std::time_t tiempo = std::time(nullptr);
    std::tm* fecha_local = std::localtime(&tiempo);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M", fecha_local);

    std::string nombreArchivo = "respaldos/respaldo_" + std::string(buffer) + ".txt";

    guardarPedidoEnArchivo(nombreArchivo);
    std::cout << "Respaldo guardado como: " << nombreArchivo << std::endl;
}

void ListaPedidos::restaurarRespaldo() {
    std::vector<std::string> archivos;
    DIR* dir;
    struct dirent* entry;

    dir = opendir("respaldos");
    if (!dir) {
        std::cout << "La carpeta 'respaldos' no existe. No hay respaldos disponibles." << std::endl;
        return;
    }

    while ((entry = readdir(dir)) != nullptr) {
        std::string filename = entry->d_name;
        if (filename != "." && filename != "..") {
            archivos.push_back("respaldos/" + filename);
        }
    }
    closedir(dir);

    if (archivos.empty()) {
        std::cout << "No hay respaldos disponibles en la carpeta 'respaldos'." << std::endl;
        return;
    }

    std::cout << "Archivos de respaldo disponibles:" << std::endl;
    for (size_t i = 0; i < archivos.size(); ++i) {
        std::cout << i + 1 << ". " << archivos[i] << std::endl;
    }

    int seleccion;
    std::cout << "Seleccione el número del archivo de respaldo que desea restaurar: ";
    std::cin >> seleccion;

    if (seleccion < 1 || static_cast<size_t>(seleccion) > archivos.size()) {
        std::cerr << "Selección no válida." << std::endl;
        return;
    }

    cargarPedidoDesdeArchivo(archivos[seleccion - 1]);
    guardarPedidoEnArchivo("pedidos.txt");
    std::cout << "Respaldo restaurado desde: " << archivos[seleccion - 1] << std::endl;
}

bool ListaPedidos::cambiarEstado(std::string noPedido, const std::string& nuevoEstado , const std::string& causa) {
    NodoPedido* temp = cabeza;
    while (temp) {
        if (temp->pedido.NoPedido == noPedido) {
            temp->pedido.estado = nuevoEstado;
            temp->pedido.causa =causa;
            return true;
        }
        temp = temp->siguiente;
    }
    std::cerr << "Error: Pedido no encontrado." << std::endl;
    return false;
}

