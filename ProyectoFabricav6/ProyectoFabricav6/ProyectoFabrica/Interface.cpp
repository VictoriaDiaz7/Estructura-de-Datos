#include "Interface.h"
#include "Validaciones.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <limits>
#include <cmath>
#include <vector>

GrafoClientes clientes;
ListaHerramientas herramientas;
ListaPedidos pedidos;
Validaciones validaciones;

// |||| manejo de clientes||||
void Interfaz::insertarclientes() {
    std::string ruc, nombre, ref1, ref2;
    double distancia, dis1, dis2;
    std::cout << "Ingrese RUC: ";
    ruc = validaciones.ingresar_RUC();
    std::cout << "Ingrese nombre: ";
    nombre = validaciones.ingresar_NombreCliente();
    std::cout << "Ingrese referencia 1 (otro cliente cercano al cliente actual): ";
    ref1=validaciones.ingresar_Referencias();
    std::cout << "Ingrese referencia 2 (otro cliente cercano al cliente actual):";
    ref2=validaciones.ingresar_Referencias();
    std::cout << "Ingrese distancia a la fabrica: ";
    distancia=validaciones.ingresar_Double();
    if(ref1=="null"){
        dis1=0;
    }else{
        dis1=validaciones.referenciasIngresada1(ref1,nombre);
        if(dis1==-1){
            std::cout << "Ingrese distancia a referencia 1: ";
            dis1=validaciones.ingresar_Double();
        }
    }

    if(ref2=="null"){
        dis2=0;
    }else{
        dis2=validaciones.referenciasIngresada1(ref2,nombre);
        if(dis2==-1){
            std::cout << "Ingrese distancia a referencia 2: ";
            dis2=validaciones.ingresar_Double();
        }
    }

    //creacion del cliente
    Cliente cliente(ruc, nombre, ref1, ref2, distancia, dis1, dis2);
    if (clientes.insertar(cliente))
    {
        std::cout << "Cliente insertado correctamente." << std::endl;
        clientes.guardarClientesEnArchivo("clientes.txt");
    } else {
        std::cout << "Error al insertar cliente." << std::endl;
    }
}

void Interfaz::buscarclientes() {
    std::string criterio;
    int opcion;
    std::cout << "seleccione el criterio de busqueda: \n";
    std::cout << "1. RUC\n";
    std::cout << "2. Nombre\n";
    opcion=validaciones.ingresar_entero('2');

    if (opcion == 1) {
        std::cout << "Ingrese RUC: ";
        criterio=validaciones.ingresar_StringNumeros(13);
    } else if (opcion == 2) {
        std::cout << "Ingrese nombre: ";
        criterio=validaciones.ingresar_StringLetras();
    }

    NodoCliente* cliente = clientes.buscar(criterio);
    if (cliente) {
        std::cout << "Cliente encontrado: " <<std::endl;
        std::cout << "Cliente: " << cliente->cliente.nombre << " (RUC: " << cliente->cliente.RUC << ")\n";
        std::cout << "  Referencia 1: " << cliente->cliente.Ref1 << "\n";
        std::cout << "  Referencia 2: " << cliente->cliente.Ref2 << "\n";
        std::cout << "  Distancia total: " << cliente->cliente.distancia << " km\n";
        std::cout << "  Distancia a Ref1: " << cliente->cliente.dis1 << " km\n";
        std::cout << "  Distancia a Ref2: " << cliente->cliente.dis2 << " km\n";
        std::cout << "--------------------------------------\n";
    } else {
        std::cout << "Cliente no encontrado." << std::endl;
    }
}

void Interfaz::mostrarclientes() {
    clientes.mostrar();
}

void Interfaz::modificarclientes() {
    std::string criterio, nuevoValor;
    int opcion, atributoOpcion;
    std::cout << "seleccione el criterio de busqueda: \n";
    std::cout << "1. RUC\n";
    std::cout << "2. Nombre\n";
    opcion=validaciones.ingresar_entero('2');

    if (opcion == 1) {
        std::cout << "Ingrese RUC: ";
        criterio=validaciones.ingresar_StringNumeros(13);
    } else if (opcion == 2) {
        std::cout << "Ingrese nombre: ";
        criterio=validaciones.ingresar_StringLetras();
    }

    std::cout << "Seleccione el atributo a modificar: "<<std::endl;
    std::cout << "1. RUC\n";
    std::cout << "2. Nombre\n";
    std::cout << "3. Referencia 1\n";
    std::cout << "4. Referencia 2\n";
    std::cout << "5. Distancia a la fabrica\n";
    std::cout << "6. Distancia a la referencia 1\n";
    std::cout << "7. Distancia a la referencia 2\n";
    atributoOpcion=validaciones.ingresar_entero('7');

    std::string atributo;
    switch (atributoOpcion) {
        case 1: atributo = "RUC"; break;
        case 2: atributo = "nombre"; break;
        case 3: atributo = "ref1"; break;
        case 4: atributo = "ref2"; break;
        case 5: atributo = "distancia"; break;
        case 6: atributo = "dis1"; break;
        case 7: atributo = "dis2"; break;
        default: std::cout << "Opción no válida." << std::endl; return;
    }

    std::cout << "Ingrese nuevo valor: ";
    if(atributoOpcion==1){
        nuevoValor=validaciones.ingresar_RUC();
    }else if(atributoOpcion==2){
        nuevoValor=validaciones.ingresar_NombreCliente();
    }else if(atributoOpcion==3 || atributoOpcion==4){
        nuevoValor=validaciones.ingresar_Referencias();
    }else if(atributoOpcion==5 || atributoOpcion==6 || atributoOpcion==7){
        nuevoValor=std::to_string(validaciones.ingresar_Double());
    }

    if (clientes.modificarAtributo(criterio, atributo, nuevoValor)) {
        std::cout << "Cliente modificado correctamente." << std::endl;
        clientes.guardarClientesEnArchivo("clientes.txt");
    } else {
        std::cout << "Error al modificar cliente." << std::endl;
    }
}

void Interfaz::eliminarclientes() {
    std::string criterio;
    int opcion;
    std::cout << "seleccione el criterio de busqueda: \n";
    std::cout << "1. RUC\n";
    std::cout << "2. Nombre\n";
    opcion=validaciones.ingresar_entero('2');

    if (opcion == 1) {
        std::cout << "Ingrese RUC: ";
        criterio=validaciones.ingresar_StringNumeros(13);
    } else if (opcion == 2) {
        std::cout << "Ingrese nombre: ";
        criterio=validaciones.ingresar_StringLetras();
    }
    if (clientes.eliminar(criterio)) {
        std::cout << "Cliente eliminado correctamente." << std::endl;
        clientes.guardarClientesEnArchivo("clientes.txt");
    } else {
        std::cout << "Error al eliminar cliente." << std::endl;
    }
}


void Interfaz::graficarGrafoClientes() {
    clientes.graficarGrafoClientes();  // Ahora llama a la función en GrafoClientes
}

void Interfaz::graficarRutaOptima() {
    std::string cliente;
    std::cout << "Ingrese el nombre del cliente objetivo: ";
    cliente=validaciones.ingresar_StringLetras();
    clientes.graficarRutaOptima(cliente);
    clientes.calcularRutaOptima(cliente);
}

//|||| manejo de pedidos ||||
std::string Interfaz::obtenerCliente(){
    std::string criterio;
    std::string identificador;
    int opcion=0;
    const int totalOpciones = 2;
    char c;
    do{ 
    std::cout << "Ingrese uno de estos datos para iniciar: \n";
    std::cout << "Seleccione: \n";
    std::cout << (opcion == 0 ? "--> " : "    ") << "1. RUC\n"; 
    std::cout << (opcion == 1 ? "--> " : "    ") << "2. Nombre\n";
    c = _getch();

        if (c == 72) { // Flecha arriba
            opcion = (opcion - 1 + totalOpciones) % totalOpciones;
            system("cls");
        } else if (c == 80) { // Flecha abajo
            opcion = (opcion + 1) % totalOpciones;
            system("cls");
        } else if (c == 13) { // Enter
            if (opcion == 0) {
                std::cout << "Ingrese RUC: ";
                criterio=validaciones.ingresar_StringNumeros(13);
            } else if (opcion == 1) {
                std::cout << "Ingrese nombre: ";
                criterio=validaciones.ingresar_StringLetras();
            }

            // validar que solo un cliente especifico pueda ingresar
            while(criterio!="Carlos" && criterio!="1234567890123"){
                std::cout <<"Ingreso incorrecto, intente nuevamente: "<<std::endl;
                if (opcion == 0) {
                    std::cout << "Ingrese RUC: ";
                    criterio=validaciones.ingresar_StringNumeros(13);
                } else if (opcion == 1) {
                    std::cout << "Ingrese nombre: ";
                    criterio=validaciones.ingresar_StringLetras();
                }
            
            }

            NodoCliente* cliente = clientes.buscar(criterio);
            if (cliente) {
                std::cout << "Cliente autorizado: " <<std::endl;
                std::cout << "Cliente: " << cliente->cliente.nombre << " (RUC: " << cliente->cliente.RUC << ")\n";
                return identificador=cliente->cliente.nombre;
            } else {
                std::cout << "no tiene acceso al manejo de pedidos" << std::endl;
                return "";
            }

        }
    } while (c != 27);// escape

    return criterio;
}


struct Valoraciones {
    double costoTotal = 0;
    double pesoTotal = 0;
    std::vector<std::pair<Herramienta, int>> herramientasSeleccionadas;
};

Valoraciones seleccionarHerramientas(ListaHerramientas& herramientas) {
    Valoraciones resultado;
    std::vector<std::pair<Herramienta, int>> seleccionadas;
    std::vector<NodoHerramienta*> herramientasDisponibles;

    NodoHerramienta* actual = herramientas.getCabeza();
    if (!actual) {
        std::cout << "No hay herramientas disponibles.\n";
        return resultado;
    }

    std::cout << "------------------------------------------------------------------------\n";
    std::cout << "Lista de herramientas disponibles:\n";
    int indice = 1;

    while (actual) {
        herramientasDisponibles.push_back(actual);
        std::cout << indice << ") " << actual->herramienta.nombre << " (ID: " << actual->herramienta.ID << ")"
                  << " - Peso: " << actual->herramienta.peso << "kg"
                  << " - Precio: $" << actual->herramienta.precio
                  << " - Stock: " << actual->herramienta.cantidad << "\n";
        actual = actual->siguiente;
        indice++;
    }

    while (true) {
        int seleccion, cantidad;

        std::cout << "Seleccione el número de la herramienta que desea agregar (o 0 para terminar): ";
        std::cin >> seleccion;

        if (seleccion == 0) break;

        if (seleccion < 1 || seleccion > herramientasDisponibles.size()) {
            std::cout << "Seleccion invalida. Intente de nuevo.\n";
            continue;
        }

        NodoHerramienta* herramientaNodo = herramientasDisponibles[seleccion - 1];
        Herramienta& herramientaSeleccionada = herramientaNodo->herramienta; // Referencia para modificar el stock real

        if (herramientaSeleccionada.cantidad == 0) {
            std::cout << " La herramienta seleccionada no tiene stock disponible.\n";
            continue;
        }

        while (true) {
            std::cout << "Ingrese la cantidad (Stock disponible: " << herramientaSeleccionada.cantidad << "): ";
            std::cin >> cantidad;

            if (cantidad <= 0) {
                std::cout << " La cantidad debe ser mayor a 0. Intente de nuevo.\n";
                continue;
            }

            if (cantidad > herramientaSeleccionada.cantidad) {
                std::cout << " Stock insuficiente. Solo hay " << herramientaSeleccionada.cantidad << " unidades disponibles.\n";
                continue;
            }

            break;
        }

        herramientaSeleccionada.cantidad -= cantidad;  // Restar del stock real
        seleccionadas.push_back(std::make_pair(herramientaSeleccionada, cantidad));

        resultado.pesoTotal += herramientaSeleccionada.peso * cantidad;
        resultado.costoTotal += herramientaSeleccionada.precio * cantidad;

        if (resultado.pesoTotal > 2000) {
            std::cout << " ERROR: Ha superado el limite de 2000 kg. Debe eliminar herramientas.\n";

            while (resultado.pesoTotal > 2000) {
                std::cout << "Lista de herramientas seleccionadas:\n";
                for (size_t i = 0; i < seleccionadas.size(); i++) {
                    std::cout << i + 1 << ") " << seleccionadas[i].first.nombre
                              << " - Cantidad: " << seleccionadas[i].second
                              << " - Peso Total: " << seleccionadas[i].first.peso * seleccionadas[i].second << " kg\n";
                }

                int eliminar;
                std::cout << "Ingrese el numero de la herramienta a eliminar: ";
                std::cin >> eliminar;

                if (eliminar < 1 || eliminar > seleccionadas.size()) {
                    std::cout << "Número invalido. Intente de nuevo.\n";
                    continue;
                }

                // Restaurar stock al eliminar
                Herramienta& herramientaEliminada = seleccionadas[eliminar - 1].first;
                int cantidadEliminada = seleccionadas[eliminar - 1].second;
                herramientaEliminada.cantidad += cantidadEliminada;  // Devolver al stock

                // Restar peso y costo antes de eliminar
                resultado.pesoTotal -= herramientaEliminada.peso * cantidadEliminada;
                resultado.costoTotal -= herramientaEliminada.precio * cantidadEliminada;

                // Eliminar herramienta
                seleccionadas.erase(seleccionadas.begin() + eliminar - 1);

                std::cout << "Herramienta eliminada. Nuevo peso total: " << resultado.pesoTotal << " kg\n";
            }
        } else {
            std::cout << "Herramienta agregada. Costo total actualizado: $" << resultado.costoTotal << "\n";
        }
    }

    resultado.herramientasSeleccionadas = seleccionadas;
    return resultado;
}

//|||| manejo de pedidos ||||
void Interfaz::insertapedidos(std::string cliente_actual) {
    std::string noPedido;
    std::string destinatario, estado, causa;
    std::time_t fechaPedido, fechaEntrega,fechaMostrar;
    Valoraciones valoraciones;
    std::vector<std::pair<Herramienta, int>> herramientasSeleccionadas;
    
    double costoHerramientas, costoEnvio, costoTotal, pesoTotal, distancia;
    
     // Validar que el usuario ingrese herramientas con costo y peso
     do {
        valoraciones = seleccionarHerramientas(herramientas);
        costoHerramientas = valoraciones.costoTotal;
        pesoTotal = valoraciones.pesoTotal;
        
        if (costoHerramientas == 0 || pesoTotal == 0) {
            std::cout << "Error: Debe seleccionar al menos una herramienta con costo y peso mayor a 0." << std::endl;
        }
    } while (costoHerramientas == 0 || pesoTotal == 0);



    std::cout << "------------------------------------------------------------------------" <<std::endl;
    // Ingresar número de pedido
    noPedido = validaciones.ingresar_NoPedido();
    std::cout << "Numero de pedido asignado: " << noPedido << std::endl;

    // Buscar cliente
    NodoCliente* cliente = clientes.buscar(cliente_actual);
    destinatario = cliente->cliente.nombre;
    std::cout << "Destinatario: " << destinatario << std::endl;

    // Obtener fecha actual
    std::tm tmFechaPedido = validaciones.obtenerFechaActual();
    fechaPedido = std::mktime(&tmFechaPedido);

    // Obtener peso total antes de calcular la fecha de entrega
    pesoTotal = valoraciones.pesoTotal;
    
    // Calcular ruta y fecha de entrega
    distancia = clientes.calcularRutaOptima(cliente_actual);
    std::cout<<"Ruta optima desde Carlos hasta la fabrica en km: "<< distancia <<std::endl;

    fechaEntrega = validaciones.calcularFechaEntrega(fechaPedido, pesoTotal, distancia);
    fechaMostrar=fechaEntrega;
    std::tm* tmFechaMostrar =std::localtime(&fechaMostrar);
    std::cout << "Fecha de entrega estimada: "<< std::put_time(tmFechaMostrar, "%d/%m/%Y") << std::endl;

    // Definir estado y causa por defecto
    estado = "En-proceso";
    causa = "null";
    std::cout << "------------------------------------------------------------------------" <<std::endl;
    // Calcular costos
    costoHerramientas = valoraciones.costoTotal;
    std::cout << "Costo de herramientas: $" << costoHerramientas << std::endl;

    std::cout << "Peso total: " << pesoTotal << " kg" << std::endl;

    costoEnvio = round(validaciones.calcularCostoEnvio(fechaPedido, fechaEntrega, pesoTotal, distancia) * 100) / 100;
    std::cout << "Costo de envio: $" << costoEnvio << std::endl;

    costoTotal = round((costoHerramientas + costoEnvio) * 100) / 100;
    std::cout << "Costo total del pedido: $" << costoTotal << std::endl;
    std::cout << "------------------------------------------------------------------------" <<std::endl;
    // Crear objeto Pedido
    herramientasSeleccionadas = valoraciones.herramientasSeleccionadas;
    Pedido pedido(noPedido, destinatario, herramientasSeleccionadas, fechaPedido, fechaEntrega, 
                  estado, causa, costoHerramientas, costoEnvio, costoTotal, pesoTotal);

    // Insertar pedido y guardar en archivo
    if (pedidos.insertar(pedido)) {
        std::cout << "Pedido insertado correctamente." << std::endl;
        pedidos.guardarPedidoEnArchivo("pedidos.txt");
        validaciones.disminuirStockEnProceso(pedido);

    } else {
        std::cout << "Error al insertar pedido." << std::endl;
    }
    
    
}


void Interfaz::confirmarEstadopedidos(std::string cliente_actual) {
    std::string noPedido;
    std::string nuevoEstado;
    std::string causa;
    
    std::cout << "Ingrese numero de pedido: ";
    noPedido = validaciones.ingresar_StringNumeros(8);
    
    // Buscar el pedido
    std::vector<NodoPedido*> pedidosEncontrados = pedidos.buscar(noPedido);
    if (pedidosEncontrados.empty()) {
        std::cout << "ERROR: No se encontro un pedido con ese numero." << std::endl;
        return;
    }
    NodoPedido* pedido = pedidosEncontrados[0]; // Assuming you want the first match
    
    std::cout << "Ingrese una opcion: " << std::endl;
    std::cout << "1. Desea confirmar la entrega del pedido? \n";
    std::cout << "2. Desea cancelar su pedido? \n";
    
    int opcion = validaciones.ingresar_entero('2');
    
    switch (opcion) {
        case 1:
            nuevoEstado = "Entregado";
            causa="null";
            break;
    
        case 2: 
            // Validar si el pedido ya fue entregado
            if (pedido->pedido.estado == "Entregado") {
                std::cout << "ERROR: No puede cancelar este pedido, ya fue entregado." << std::endl;
                return;
            }
    
            // Validar si han pasado más de 24 horas
            if (std::difftime(pedido->pedido.fechaEntrega, pedido->pedido.fechaPedido) > 86400) {
                std::cout << "Lo sentimos, su pedido no puede ser cancelado después de 24 horas." << std::endl;
                return;
            }

            std::cout<<""<<std::endl;
            std::getline(std::cin, causa);

            nuevoEstado = "Cancelado"; // Enviar alerta de cancelación a la fábrica

            break;
    
        default:
            std::cout << "Opción no válida." << std::endl;
            return;
    }
    
    // Intentar cambiar el estado del pedido
    if (pedidos.cambiarEstado(noPedido, nuevoEstado,causa)) {
        std::cout << "Estado cambiado correctamente a '" << nuevoEstado << "'." << std::endl;
        pedidos.guardarPedidoEnArchivo("pedidos.txt");
        NodoPedido* buscado = pedidos.buscar(noPedido).empty() ? nullptr : pedidos.buscar(noPedido)[0];
        validaciones.devolverHerramientasAlStock(buscado->pedido);

    } else {
        std::cout << "Error al cambiar estado." << std::endl;        
    }
    
    
}

void Interfaz::buscarpedidos() {
    std::string criterio;
    std::cout << "Ingrese número de pedido: ";
    criterio = validaciones.ingresar_StringNumeros(8);

    std::vector<NodoPedido*> nodos = pedidos.buscar(criterio);
    if (nodos.empty()) {
        std::cout << "No se encontró ningún pedido con el número ingresado.\n";
        return;
    }
    NodoPedido* nodo = nodos[0]; // Assuming you want the first match

    if (!nodo) {
        std::cout << "No se encontró ningún pedido con el número ingresado.\n";
        return;
    }

    std::cout << "--------------------------------------\n";
    std::cout << "Pedido No: " << nodo->pedido.NoPedido << "\n";
    std::cout << "Destinatario: " << nodo->pedido.destinatario << "\n";
    
    // Formatear fechas
    std::time_t fechaPedido = nodo->pedido.fechaPedido;
    std::time_t fechaEntrega = nodo->pedido.fechaEntrega;
    
    std::tm* fechaPedido_tm = std::localtime(&fechaPedido);
    std::cout << "Fecha de Pedido: " << std::put_time(fechaPedido_tm, "%d/%m/%Y") << "\n";
    std::tm* fechaEntrega_tm = std::localtime(&fechaEntrega);
    std::cout << "Fecha de Entrega: " << std::put_time(fechaEntrega_tm, "%d/%m/%Y") << "\n";

    std::cout << "Estado: " << nodo->pedido.estado;
    if (nodo->pedido.estado == "cancelado") {
        std::cout << " (Causa: " << nodo->pedido.causa << ")";
    }
    std::cout << "\n";

    std::cout << "Costo Herramientas: $" << nodo->pedido.costoHerramientas << "\n";
    std::cout << "Costo Envío: $" << nodo->pedido.costoEnvio << "\n";
    std::cout << "Costo Total: $" << nodo->pedido.costoTotal << "\n";
    std::cout << "Peso Total: " << nodo->pedido.pesoTotal << " kg\n";

    // Listar herramientas en el pedido
    std::cout << "Herramientas incluidas:\n";
    for (const auto& herramientaCantidad : nodo->pedido.herramientas) {
        const Herramienta& herramienta = herramientaCantidad.first;
        int cantidad = herramientaCantidad.second;

        std::cout << "  - " << herramienta.nombre << " (ID: " << herramienta.ID 
                  << "), Cantidad: " << cantidad 
                  << ", Peso: " << herramienta.peso << " kg\n";
    }

    std::cout << "--------------------------------------\n";
}


void Interfaz::mostrarpedidos() {
    pedidos.mostrar();
}

void Interfaz::eliminarpedidos() {
    std::string noPedido;
    std::cout << "Ingrese número de pedido a eliminar: ";
    noPedido=validaciones.ingresar_StringNumeros(8);
    if(pedidos.eliminar(noPedido)){
        std::cout << "Pedido eliminado correctamente." << std::endl;
        pedidos.guardarPedidoEnArchivo("pedidos.txt");
    } else {
        std::cout << "Error al eliminar pedido." << std::endl;
    }
}

void Interfaz::guardarRespaldo() {
    pedidos.guardarRespaldo();
}

void Interfaz::restaurarRespaldo() {
    pedidos.restaurarRespaldo();
}

// |||| manejo de herramientas ||||
void Interfaz::insertarherramientas() {
    std::string id, nombre;
    int cantidad;
    double peso, precio;
    std::cout << "ID: ";
    id=validaciones.ingresar_ID();
    std::cout << id << std::endl;
    std::cout << "Ingrese nombre: ";
    nombre=validaciones.ingresar_NombreHerramienta();
    std::cout << "Ingrese peso: ";
    peso=validaciones.ingresar_Double();
    std::cout << "Ingrese precio: ";
    precio=validaciones.ingresar_Double();
    std::cout << "Ingrese cantidad para el inventario: ";
    cantidad = validaciones.ingresar_entero2();
    Herramienta herramienta(id, nombre, peso, precio, cantidad);

    if (herramientas.insertar(herramienta)) {
        std::cout << "Herramienta insertada correctamente." << std::endl;
        herramientas.guardarHerramientasEnArchivo("herramientas.txt");
    } else {
        std::cout << "Error al insertar herramienta." << std::endl;
    }
    

}

void Interfaz::cambiarStockherramientas() {
    std::string criterio;
    int nuevoStock;
    int opcion;
    std::cout << "seleccione el criterio de busqueda: \n";
    std::cout << "1. ID\n";
    std::cout << "2. Nombre\n";
    opcion=validaciones.ingresar_entero('2');

    if (opcion == 1) {
        std::cout << "Ingrese ID: ";
        criterio=validaciones.ingresar_StringNumeros(6);
    } else if (opcion == 2) {
        std::cout << "Ingrese nombre: ";
        criterio=validaciones.ingresar_StringLetras();
    }
    std::cout << "Ingrese nuevo stock: ";
    nuevoStock=validaciones.ingresar_entero2();
    if(herramientas.cambiarStock(criterio, nuevoStock)){
        std::cout << "Stock cambiado correctamente." << std::endl;
        herramientas.guardarHerramientasEnArchivo("herramientas.txt");
    }else{
        std::cout << "Error al cambiar stock." << std::endl;
    }
}

void Interfaz::buscarherramientas() {
    std::string criterio;
    int opcion;
    std::cout << "seleccione el criterio de busqueda: \n";
    std::cout << "1. ID\n";
    std::cout << "2. Nombre\n";
    opcion=validaciones.ingresar_entero('2');

    if (opcion == 1) {
        std::cout << "Ingrese ID: ";
        criterio=validaciones.ingresar_StringNumeros(6);
    } else if (opcion == 2) {
        std::cout << "Ingrese nombre: ";
        criterio=validaciones.ingresar_StringLetras();
    }
    NodoHerramienta* herramienta = herramientas.buscar(criterio);
    if (herramienta) {
        std::cout << "Herramienta: " << herramienta->herramienta.nombre << " (ID: " << herramienta->herramienta.ID << ")\n";
        std::cout << "  Peso: " << herramienta->herramienta.peso << " kg\n";
        std::cout << "  Precio: $" << herramienta->herramienta.precio << "\n";
        std::cout << "  Cantidad en stock: " << herramienta->herramienta.cantidad << "\n";
    } else {
        std::cout << "Herramienta no encontrada." << std::endl;
    }
}

void Interfaz::mostrarherramientas() {
    herramientas.mostrar();
}

void Interfaz::modificarherramientas() {
    std::string criterio, nuevoValor;
    int opcion, atributoOpcion;
    std::cout << "seleccione el criterio de busqueda: \n";
    std::cout << "1. ID\n";
    std::cout << "2. Nombre\n";
    opcion=validaciones.ingresar_entero('2');

    if (opcion == 1) {
        std::cout << "Ingrese ID: ";
        criterio=validaciones.ingresar_StringNumeros(6);
    } else if (opcion == 2) {
        std::cout << "Ingrese nombre: ";
        criterio=validaciones.ingresar_StringLetras();
    }

    std::cout << "Seleccione el atributo a modificar: "<<std::endl;
    std::cout << "1. Nombre\n";
    std::cout << "2. Peso\n";
    std::cout << "3. Precio\n";
    std::cout << "4. Cantidad\n";
    atributoOpcion=validaciones.ingresar_entero('4');

    std::string atributo;
    switch (atributoOpcion) {
        case 1: atributo = "nombre"; break;
        case 2: atributo = "peso"; break;
        case 3: atributo = "precio"; break;
        case 4: atributo = "cantidad"; break;
        default: std::cout << "Opción no válida." << std::endl; return;
    }

    if (atributoOpcion == 1) {
        std::cout << "Ingrese nuevo nombre: ";
        nuevoValor=validaciones.ingresar_NombreHerramienta();
    } else if (atributoOpcion == 2 || atributoOpcion == 3) {
        std::cout << "Ingrese nuevo valor: ";
        nuevoValor=std::to_string(validaciones.ingresar_Double());
    } else if (atributoOpcion == 4) {
        std::cout << "Ingrese nuevo valor: ";
        nuevoValor=std::to_string(validaciones.ingresar_entero2());
    }

    if (herramientas.modificarAtributo(criterio, atributo, nuevoValor)) {
        std::cout << "herramienta modificada correctamente." << std::endl;
        herramientas.guardarHerramientasEnArchivo("herramientas.txt");
    } else {
        std::cout << "Error al modificar atributo." << std::endl;
    }
}

void Interfaz::eliminarherramientas() {
    std::string criterio;
    int opcion;
    std::cout << "seleccione el criterio de busqueda: \n";
    std::cout << "1. ID\n";
    std::cout << "2. Nombre\n";
    opcion=validaciones.ingresar_entero('2');

    if (opcion == 1) {
        std::cout << "Ingrese ID: ";
        criterio=validaciones.ingresar_StringNumeros(6);
    } else if (opcion == 2) {
        std::cout << "Ingrese nombre: ";
        criterio=validaciones.ingresar_StringLetras();
    }
    if(herramientas.eliminar(criterio)){ 
        std::cout << "Herramienta eliminada correctamente." << std::endl;
        herramientas.guardarHerramientasEnArchivo("herramientas.txt");
    } else {
        std::cout << "Error al eliminar herramienta." << std::endl;
    }
}
