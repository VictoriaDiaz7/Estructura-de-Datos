#include "Validaciones.h"
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//identificadores repetidos
bool esRUCRepetido(const std::string& ruc, GrafoClientes& clientes) {
    NodoCliente* cliente = clientes.buscar(ruc);
    return cliente != nullptr;
}

bool esIDRepetido(int id, ListaHerramientas& herramientas) {
    NodoHerramienta* herramienta = herramientas.buscar(std::to_string(id));
    return herramienta != nullptr;
}

bool esNoPedidoRepetido(int noPedido, ListaPedidos& pedidos) {
    std::vector<NodoPedido*> pedidosEncontrados = pedidos.buscar(std::to_string(noPedido));
    return !pedidosEncontrados.empty();
}


//||verificar que los identificadores no se repitan
std::string Validaciones::ingresar_RUC() {
    std::string entrada;
    char c;
    entrada.clear(); 
    GrafoClientes clientes;
    clientes.cargarClientesDesdeArchivo("clientes.txt");

    while (true) {
        c = getch(); // Leer un carácter
        if (c >= '0' && c <= '9') { 
            if (entrada.size() < 13) { // valida que no se ingrese más de 13 dígitos
                std::cout << c; 
                entrada += c; 
            }
        } else if (c == 8 && !entrada.empty()) { // permite retroceder
            std::cout << "\b \b"; 
            entrada.pop_back();   
        } else if (c == 13 && entrada.size() == 13) { // valida que no se ingrese menos de 13 dígitos
            if (esRUCRepetido(entrada, clientes)) {
                std::cout << "\nError: El RUC ya está registrado. Intente nuevamente:\n";
                entrada.clear();
            } else {
                std::cout << std::endl;
                break; 
            }
        }
    }
    return entrada;
}

std::string Validaciones::ingresar_ID() {
    srand(time(0)); 
    int randomID;
    ListaHerramientas herramientas;
    herramientas.cargarHerramientasDesdeArchivo("herramientas.txt");
    do {
        randomID = rand() % 900000 + 100000;
    } while (esIDRepetido(randomID, herramientas));

    return std::to_string(randomID);
}

std::string Validaciones::ingresar_NoPedido() {
    srand(time(0)); 
    int randomNo;
    ListaPedidos pedidos;
    pedidos.cargarPedidoDesdeArchivo("pedidos.txt");
    do {
        randomNo = rand() % 90000000 + 10000000;
    } while (esNoPedidoRepetido(randomNo, pedidos));

    return std::to_string(randomNo);
}

//||verificar que los nombres no se repitan
std::string Validaciones::ingresar_NombreCliente() {
    std::string dato;
    char c; 
    dato.clear();
    GrafoClientes clientes;
    clientes.cargarClientesDesdeArchivo("clientes.txt");

    while (true) {
        c = getch();
        if (isalpha(c) || c == ' ') {
            std::cout << c; 
            dato += c;  
        } else if (c == 8 && !dato.empty()) {
            std::cout << "\b \b";
            dato.pop_back();  
        } else if (c == 13) {  // Enter
            if (!dato.empty()) {
                dato[0] = toupper(dato[0]);
                if (clientes.buscar(dato)!=nullptr) {
                    std::cout << "\nError: El nombre del cliente ya está registrado. Intente nuevamente:\n";
                    dato.clear();
                } else {
                    std::cout << std::endl;
                    break;
                }
            }
        }
    }
    return dato;

}


std::string Validaciones::ingresar_NombreHerramienta() {
    std::string dato;
    char c; 
    dato.clear();
    ListaHerramientas herramientas;
    herramientas.cargarHerramientasDesdeArchivo("herramientas.txt");

    while (true) {
        c = getch();
        if (isalpha(c) || c == ' ') {
            std::cout << c; 
            dato += c;  
        } else if (c == 8 && !dato.empty()) { // Manejar Backspace
            std::cout << "\b \b";
            dato.pop_back();  
        } else if (c == 13) { // Detectar Enter
            if (!dato.empty()) {
                dato[0] = toupper(dato[0]);
                if (herramientas.buscar(dato)!=nullptr) {
                    std::cout << "\nError: El nombre de la herramienta ya está registrado. Intente nuevamente:\n";
                    dato.clear();
                } else {
                    std::cout << std::endl;
                    break; // Salir del bucle si hay contenido
                }
            }
        }
    }
    return dato;

}

//||verificar que las referencias esten en la base de datos
std::string Validaciones::ingresar_Referencias() { 
    std::string dato;
    char c; 
    dato.clear();
    GrafoClientes clientes;
    clientes.cargarClientesDesdeArchivo("clientes.txt");

    while (true) {
        c = getch();

        if (isalnum(c) || c == ' ') {  // Permitir letras, números y espacios
            std::cout << c; 
            dato += c;  
        } else if (c == 8 && !dato.empty()) { // Manejar Backspace
            std::cout << "\b \b";
            dato.pop_back();  
        } else if (c == 13) { // Detectar Enter
            if (dato.empty()) {
                return "null"; // Permitir entrada vacía
            } 
            if (clientes.buscar(dato) == nullptr) {
                std::cout << "\nError: Esta referencia no se encuentra en la base de datos. Intente nuevamente:\n";
                dato.clear();
            } else {
                std::cout << std::endl;
                return dato; // Salir del bucle si la referencia es válida
            }
        }
    }
}



//selector de opciones
int Validaciones::ingresar_entero(char numero){
    char c;
    while (true) {
        c = getch(); 
        
        if (c >= '1' && c <= numero) {
            std::cout << c << std::endl; // Mostrar el número
            return c - '0'; // Convertir de char a int y retornar
        } 
        else if (c == 13) {
        }
    }
}

//||ingreso generico de strings con numeros
std::string Validaciones::ingresar_StringNumeros(int cantidad){ 
    std::string entrada;
    char c;
    entrada.clear(); 

    while (true) {
        c = getch(); // Leer un carácter
        if (c >= '0' && c <= '9') { 
            if (entrada.size() < cantidad) { // valida q no se ingrese mas de # digitos
                std::cout << c; 
                entrada += c; 
            }
        } else if (c == 8 && !entrada.empty()) { //permite retroceder
            std::cout << "\b \b"; 
            entrada.pop_back();   
        } else if (c == 13 && entrada.size() == cantidad) { // valida q no se ingrese menos de # digitos
            std::cout << std::endl;
            break; 
        }
    }
    return entrada;
}

//||ingreso generico de strings con letras
std::string Validaciones::ingresar_StringLetras(){
    std::string dato;
    char c; 
    dato.clear();

    while (true) {
        c = getch();
        if (isalpha(c)) {
            std::cout << c; 
            dato += c;  
        } else if (c == 8 && !dato.empty()) { // Manejar Backspace
            std::cout << "\b \b";
            dato.pop_back();  
        } else if (c == 13) { // Detectar Enter
            if (!dato.empty()) {
                std::cout << std::endl;
                break; // Salir del bucle si hay contenido
            }
        }
    }

    // Convertir la primera letra a mayúscula
    if (!dato.empty()) {
        dato[0] = toupper(dato[0]);
    }

    return dato;
}

//||ingreso generico de doubles
double Validaciones::ingresar_Double() {
    std::string dato;
    char c;
    bool punto = false;  // Para rastrear si ya se ingresó un punto decimal

    dato.clear();

    while (true) {
        c = getch();

        // Si es un dígito, lo agrega
        if (isdigit(c)) {
            std::cout << c;
            dato += c;
        } 
        // Si es un punto decimal y aún no se ha ingresado, lo agrega
        else if (c == '.' && !punto && !dato.empty()) {
            std::cout << c;
            dato += c;
            punto = true; // Marca que ya hay un punto
        } 
        // Si el usuario presiona "Backspace" y hay algo escrito
        else if (c == 8 && !dato.empty()) {
            // Si se borra un punto, se reinicia el flag
            if (dato.back() == '.') {
                punto = false;
            }
            std::cout << "\b \b";
            dato.pop_back();
        } 
        // Si presiona "Enter" y hay al menos un número válido
        else if (c == 13 && !dato.empty() && dato != ".") {
            std::cout << std::endl;
            break;
        }
    }
    return stod(dato);
}

int Validaciones::ingresar_entero2() {
    std::string numero;
    char c;

    while (true) {
        c = getch(); // Captura un carácter sin mostrarlo en pantalla

        // Si es un dígito (0-9), se agrega al string y se muestra en pantalla
        if (c >= '0' && c <= '9') {
            numero += c;
            std::cout << c;
        } 
        // Si es Backspace (8), borra el último dígito ingresado
        else if (c == 8 && !numero.empty()) {
            std::cout << "\b \b"; // Borra el carácter en pantalla
            numero.pop_back();    // Elimina el último carácter del string
        }
        // Si es Enter (13), convierte y retorna el número
        else if (c == 13 && !numero.empty()) {
            std::cout << std::endl;
            return std::stoi(numero);
        }
    }
}

double Validaciones::referenciasIngresada1(std::string cliente, std::string referencia) {
    GrafoClientes clientes;
    clientes.cargarClientesDesdeArchivo("clientes.txt");

    NodoCliente* nodo = clientes.buscar(cliente); // NodoCliente*, no Cliente*
    if (nodo != nullptr && nodo->cliente.Ref1 == referencia) { 
        return nodo->cliente.dis1;
    }
    return -1; // Retorna -1 si la referencia no existe
}

double Validaciones::referenciasIngresada2(std::string cliente, std::string referencia) {
    GrafoClientes clientes;
    clientes.cargarClientesDesdeArchivo("clientes.txt");

    NodoCliente* nodo = clientes.buscar(cliente); // NodoCliente*, no Cliente*
    if (nodo != nullptr && nodo->cliente.Ref2 == referencia) { 
        return nodo->cliente.dis2;
    }
    return -1; // Retorna -1 si la referencia no existe
}


void Validaciones::devolverHerramientasAlStock(Pedido pedido) {
    // Verificar si el estado del pedido es "cancelado"
    ListaHerramientas listaHerramientas;
    listaHerramientas.cargarHerramientasDesdeArchivo("herramientas.txt");

    if (pedido.estado == "cancelado") {
        // Recorrer las herramientas del pedido
        for (const auto& herramientaCantidad : pedido.herramientas) {
            const Herramienta& herramienta = herramientaCantidad.first;
            int cantidad = herramientaCantidad.second;

            // Buscar la herramienta en la lista enlazada de herramientas
            NodoHerramienta* temp = listaHerramientas.getCabeza(); // Suponiendo que tienes un método getCabeza() que devuelve el primer nodo
            while (temp) {
                if (temp->herramienta.ID == herramienta.ID) {
                    temp->herramienta.cantidad += cantidad;  // Devolver la cantidad al stock
                    std::cout << "Herramienta " << herramienta.nombre << " devuelta al stock.\n";
                    break;
                }
                temp = temp->siguiente;
            }
        }
    }
}


void Validaciones::disminuirStockEnProceso(Pedido pedido) {
    // Verificar si el estado del pedido es "En-proceso"
    ListaHerramientas listaHerramientas;
    listaHerramientas.cargarHerramientasDesdeArchivo("herramientas.txt");
    
    if (pedido.estado == "En-proceso") {
        // Recorrer las herramientas del pedido
        for (const auto& herramientaCantidad : pedido.herramientas) {
            const Herramienta& herramienta = herramientaCantidad.first;
            int cantidad = herramientaCantidad.second;

            // Buscar la herramienta en la lista enlazada de herramientas
            NodoHerramienta* temp = listaHerramientas.getCabeza(); // Suponiendo que tienes un método getCabeza() que devuelve el primer nodo
            while (temp) {
                if (temp->herramienta.ID == herramienta.ID) {
                    if (temp->herramienta.cantidad >= cantidad) {
                        temp->herramienta.cantidad -= cantidad;  // Disminuir el stock
                        std::cout << "Herramienta " << herramienta.nombre << " retirada del stock.\n";
                    } else {
                        std::cout << "No hay suficiente stock de " << herramienta.nombre << " para este pedido.\n";
                    }
                    break;
                }
                temp = temp->siguiente;
            }
        }
    }
}


std::tm Validaciones::obtenerFechaActual() {
    std::time_t tiempoActual = std::time(nullptr);
    std::tm tiempoEstructurado;
    std::tm* tiempoPtr = std::localtime(&tiempoActual);
    tiempoEstructurado = *tiempoPtr;
    return tiempoEstructurado;
}


std::time_t Validaciones::calcularFechaEntrega(std::time_t fechaCompra, double pesoTotal, double distanciaOptima) {
    int diasEntrega = 2; // Tiempo mínimo de procesamiento

    // Se agrega un día por cada 100 km recorridos
    diasEntrega += static_cast<int>(distanciaOptima / 100);

    // Si el peso supera 1000 kg, se agregan 2 días más
    if (pesoTotal > 1000) {
        diasEntrega += 2;
    }

    // Sumar los días en segundos
    fechaCompra += diasEntrega * 24 * 60 * 60; 

    return fechaCompra; // Retorna el tiempo en formato time_t
}

double Validaciones::calcularCostoEnvio(time_t fechaPedido, time_t fechaEntrega, double distancia, double peso) {
    // Definición de tarifas
    const double TARIFA_BASE = 5.0;
    const double COSTO_POR_KM = 0.50;
    const double COSTO_POR_KG = 0.20;

    // Cálculo del costo total
    double costoTotal = TARIFA_BASE + (COSTO_POR_KM * distancia) + (COSTO_POR_KG * peso);
    
    // Validación si el tiempo de entrega es menor que el pedido (caso inválido)
    if (fechaEntrega < fechaPedido) {
        return -1.0; // Código de error para indicar inconsistencia en fechas
    }

    return costoTotal;
}
