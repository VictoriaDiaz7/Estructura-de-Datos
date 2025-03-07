#include "Interface.cpp"
#include "pdf_generator.cpp"
#include "pdf_generator.h"
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

void menuPrincipal();
void gestionarClientes();
void gestionarPedidos();
void gestionarHerramientas();
void mostrarAyuda();

Interfaz interfaz;

int main() {
    // Cargar datos desde archivos
    clientes.cargarClientesDesdeArchivo("clientes.txt");
    herramientas.cargarHerramientasDesdeArchivo("herramientas.txt");
    pedidos.cargarPedidoDesdeArchivo("pedidos.txt");
   
    menuPrincipal();
    
    return 0;
}

void menuPrincipal() {
    int opcion = 0;
    const int totalOpciones = 3;
    char tecla;
    do {
        system("cls");
        cout << "===== MENU PRINCIPAL =====\n";
        cout << (opcion == 0 ? "--> " : "    ") << "1. Gestionar Clientes\n";
        cout << (opcion == 1 ? "--> " : "    ") << "2. Gestionar Pedidos\n";
        cout << (opcion == 2 ? "--> " : "    ") << "3. Gestionar Herramientas\n";
        cout << "Presione Enter para seleccionar, Esc para salir, F2 para ayuda.\n";
        
        tecla = _getch();
        
        if (tecla == 72) { // Flecha arriba
            opcion = (opcion - 1 + totalOpciones) % totalOpciones;
        } else if (tecla == 80) { // Flecha abajo
            opcion = (opcion + 1) % totalOpciones;
        } else if (tecla == 13) { // Enter
            switch (opcion) {
                case 0: gestionarClientes(); break;
                case 1: gestionarPedidos(); break;
                case 2: gestionarHerramientas(); break;
            }
        } else if (tecla == 60) { // F2 para ayuda
            mostrarAyuda();
        }
    } while (tecla != 27);
}

void gestionarClientes() {
    int opcion = 0;
    const int totalOpciones = 8;
    char tecla;
    do {
        cout << "===== GESTIONAR CLIENTES =====\n";
        cout << (opcion == 0 ? "--> " : "    ") << "1. Insertar Cliente\n";
        cout << (opcion == 1 ? "--> " : "    ") << "2. Buscar Cliente\n";
        cout << (opcion == 2 ? "--> " : "    ") << "3. Mostrar Clientes\n";
        cout << (opcion == 3 ? "--> " : "    ") << "4. Modificar Cliente\n";
        cout << (opcion == 4 ? "--> " : "    ") << "5. Eliminar Cliente\n";
        cout << (opcion == 5 ? "--> " : "    ") << "6. Mostrar Mapa General\n";
        cout << (opcion == 6 ? "--> " : "    ") << "7. Mostrar Ruta Mas Optima\n";
        cout << (opcion == 7 ? "--> " : "    ") << "8. Convertir Clientes a PDF\n";
        cout << "Presione Enter para seleccionar, Esc para volver, F2 para ayuda.\n";
        tecla = _getch();
        system("cls");
        if (tecla == 72) { // Flecha arriba
            opcion = (opcion - 1 + totalOpciones) % totalOpciones;
            system("cls");
        } else if (tecla == 80) { // Flecha abajo
            opcion = (opcion + 1) % totalOpciones;
            system("cls");
        } else if (tecla == 13) { // Enter
            switch (opcion) {
                case 0: interfaz.insertarclientes(); break;
                case 1: interfaz.buscarclientes(); break;
                case 2: interfaz.mostrarclientes(); break;
                case 3: interfaz.modificarclientes(); break;
                case 4: interfaz.eliminarclientes(); break;
                case 5: interfaz.graficarGrafoClientes(); break;
                case 6: interfaz.graficarRutaOptima(); break;
                case 7: createClientsPDF(clientes, "clientes.pdf"); break;
            }
        } else if (tecla == 60) { // F2 para ayuda
            mostrarAyuda();
        }
    } while (tecla != 27);
}

void gestionarPedidos() {
    string cliente_actual;
    cliente_actual=interfaz.obtenerCliente();

    if(cliente_actual==""){
        return;
    }

    int opcion = 0;
    const int totalOpciones = 8;
    char tecla;

    do {
        cout << "===== GESTIONAR PEDIDOS =====\n";
        cout << (opcion == 0 ? "--> " : "    ") << "1. Crear Nuevo Pedido\n";
        cout << (opcion == 1 ? "--> " : "    ") << "2. Confirmar Estado\n";
        cout << (opcion == 2 ? "--> " : "    ") << "3. Buscar Pedido\n";
        cout << (opcion == 3 ? "--> " : "    ") << "4. Historial de Pedidos\n";
        cout << (opcion == 4 ? "--> " : "    ") << "5. Eliminar Pedido\n";
        cout << (opcion == 5 ? "--> " : "    ") << "6. Crear BackUp nuevo\n";
        cout << (opcion == 6 ? "--> " : "    ") << "7. Restaurar BackUp anterior\n";
        cout << (opcion == 7 ? "--> " : "    ") << "8. Convertir Pedidos a PDF\n";
        cout << "Presione Enter para seleccionar, Esc para volver, F2 para ayuda.\n";
        tecla = _getch();
        if (tecla == 72) { // Flecha arriba
            opcion = (opcion - 1 + totalOpciones) % totalOpciones;
            system("cls");
        } else if (tecla == 80) { // Flecha abajo
            opcion = (opcion + 1) % totalOpciones;
            system("cls");
        } else if (tecla == 13) { // Enter
            switch (opcion) {
                case 0: interfaz.insertapedidos(cliente_actual); break;
                case 1: interfaz.confirmarEstadopedidos(cliente_actual); break;
                case 2: interfaz.buscarpedidos(); break;
                case 3: interfaz.mostrarpedidos(); break;
                case 4: interfaz.eliminarpedidos(); break;
                case 5: interfaz.guardarRespaldo(); break;
                case 6: interfaz.restaurarRespaldo(); break;
                case 7: createOrdersPDF(pedidos, "pedidos.pdf"); break;
            }
        } else if (tecla == 60) { // F2 para ayuda
            mostrarAyuda();
        }
    } while (tecla != 27);
}

void gestionarHerramientas() {
    int opcion = 0;
    const int totalOpciones = 7;
    char tecla;
    do {
        cout << "===== GESTIONAR HERRAMIENTAS =====\n";
        cout << (opcion == 0 ? "--> " : "    ") << "1. Ingresar Herramienta Nueva\n";
        cout << (opcion == 1 ? "--> " : "    ") << "2. Cambiar Stock\n";
        cout << (opcion == 2 ? "--> " : "    ") << "3. Buscar Herramienta\n";
        cout << (opcion == 3 ? "--> " : "    ") << "4. Mostrar Herramientas\n";
        cout << (opcion == 4 ? "--> " : "    ") << "5. Modificar Herramienta\n";
        cout << (opcion == 5 ? "--> " : "    ") << "6. Eliminar Herramienta\n";
        cout << (opcion == 6 ? "--> " : "    ") << "7. Convertir Herramientas a PDF\n";
        cout << "Presione Enter para seleccionar, Esc para volver, F2 para ayuda.\n";
        tecla = _getch();
        if (tecla == 72) { // Flecha arriba
            opcion = (opcion - 1 + totalOpciones) % totalOpciones;
            system("cls");
        } else if (tecla == 80) { // Flecha abajo
            opcion = (opcion + 1) % totalOpciones;
            system("cls");
        } else if (tecla == 13) { // Enter
            switch (opcion) {
                case 0: interfaz.insertarherramientas(); break;
                case 1: interfaz.cambiarStockherramientas(); break;
                case 2: interfaz.buscarherramientas(); break;
                case 3: interfaz.mostrarherramientas(); break;
                case 4: interfaz.modificarherramientas(); break;
                case 5: interfaz.eliminarherramientas(); break;
                case 6: createToolsPDF(herramientas, "herramientas.pdf"); break;
            }
        } else if (tecla == 60) { // F2 para ayuda
            mostrarAyuda();
        }
    } while (tecla != 27);
}

void mostrarAyuda() {
     system("start file:/C:/Users/IDC/Desktop/ProyectoFabricav6/ayuda.html");
}
