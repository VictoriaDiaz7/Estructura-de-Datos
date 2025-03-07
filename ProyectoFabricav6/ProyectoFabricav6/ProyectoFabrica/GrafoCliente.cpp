/* GrafoClientes.cpp */
#include "GrafoCliente.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm> // Incluir para usar std::reverse
#include <map>
#include <cstdlib>
#include <sstream>


GrafoClientes::GrafoClientes() {
    Fabrica = new NodoCliente(Cliente("0296537341001", "Fabrica", "", "", 0.0, 0.0, 0.0));
    nodos.push_back(Fabrica);
}

bool GrafoClientes::insertar(Cliente cliente) {
    for (auto nodo : nodos) {
        if (nodo->cliente.RUC == cliente.RUC || nodo->cliente.nombre == cliente.nombre) {
            std::cout << "Error: Cliente con el mismo RUC o nombre ya existe." << std::endl;
            return false;
        }
    }
    NodoCliente* nuevo = new NodoCliente(cliente);
    nodos.push_back(nuevo);
    return true;
}

bool GrafoClientes::eliminar(std::string criterio) {
    for (auto it = nodos.begin(); it != nodos.end(); ++it) {
        if ((*it)->cliente.RUC == criterio || (*it)->cliente.nombre == criterio) {
            delete *it;
            nodos.erase(it);
            return true;
        }
    }
    return false;
}

NodoCliente* GrafoClientes::buscar(std::string criterio) {
    for (auto nodo : nodos) {
        if (nodo->cliente.RUC == criterio || nodo->cliente.nombre == criterio) {
            return nodo;
        }
    }
    return nullptr;
}

void GrafoClientes::mostrar() {
    if (nodos.empty()) {
        std::cout << "No hay clientes registrados en el grafo." << std::endl;
        return;
    }

    std::cout << "Lista de clientes en el grafo:\n";
    for (const auto& nodo : nodos) {
        std::cout << "Cliente: " << nodo->cliente.nombre << " (RUC: " << nodo->cliente.RUC << ")\n";
        std::cout << "  Referencia 1: " << nodo->cliente.Ref1 << "\n";
        std::cout << "  Referencia 2: " << nodo->cliente.Ref2 << "\n";
        std::cout << "  Distancia total: " << nodo->cliente.distancia << " km\n";
        std::cout << "  Distancia a Ref1: " << nodo->cliente.dis1 << " km\n";
        std::cout << "  Distancia a Ref2: " << nodo->cliente.dis2 << " km\n";
        std::cout << "--------------------------------------\n";
    }
}

void GrafoClientes::guardarClientesEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo, std::ios::out);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para escritura.\n";
        return;
    }
    for (auto nodo : nodos) {
        archivo << nodo->cliente.RUC << " " << nodo->cliente.nombre << " " << nodo->cliente.Ref1 << " " << nodo->cliente.Ref2 << " " << nodo->cliente.distancia << " " << nodo->cliente.dis1 << " " << nodo->cliente.dis2 << "\n";
    }
    archivo.close();
}

void GrafoClientes::cargarClientesDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo, std::ios::in);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << " para lectura.\n";
        return;
    }
    nodos.clear();
    std::string RUC, nombre, ref1, ref2;
    double distancia, dis1, dis2;
    while (archivo >> RUC >> nombre >> ref1 >> ref2 >> distancia >> dis1 >> dis2) {
        Cliente cliente(RUC, nombre, ref1, ref2, distancia, dis1, dis2);
        insertar(cliente);
    }
    archivo.close();
}

bool GrafoClientes::modificarAtributo(const std::string& criterio, const std::string& atributo, const std::string& nuevoValor) {
    NodoCliente* nodo = buscar(criterio);
    if (!nodo) {
        std::cerr << "Error: Cliente no encontrado." << std::endl;
        return false;
    }

    if (atributo == "RUC") {
        nodo->cliente.RUC = nuevoValor;
    } else if (atributo == "nombre") {
        nodo->cliente.nombre = nuevoValor;
    } else if (atributo == "ref1") {
        nodo->cliente.Ref1 = nuevoValor;
    } else if (atributo == "ref2") {
        nodo->cliente.Ref2 = nuevoValor;
    } else if (atributo == "distancia") {
        nodo->cliente.distancia = std::stod(nuevoValor);
    } else if (atributo == "dis1") {
        nodo->cliente.dis1 = std::stod(nuevoValor);
    } else if (atributo == "dis2") {
        nodo->cliente.dis2 = std::stod(nuevoValor);
    } else {
        std::cerr << "Error: Atributo no válido." << std::endl;
        return false;
    }

    return true;
}

void GrafoClientes::graficarGrafoClientes() {
    std::ofstream archivoPython("graficar_grafo.py");
    if (!archivoPython) {
        std::cerr << "Error al crear el archivo Python para graficar.\n";
        return;
    }

    archivoPython << "import matplotlib.pyplot as plt\n";
    archivoPython << "import networkx as nx\n\n";
    archivoPython << "G = nx.Graph()\n\n";
    archivoPython << "G.add_node('Fabrica')\n";

    for (auto nodo : nodos) {
        if (nodo->cliente.nombre != "Fabrica") {
            archivoPython << "G.add_node('" << nodo->cliente.nombre << "')\n";
            archivoPython << "G.add_edge('Fabrica', '" << nodo->cliente.nombre << "', weight=" << nodo->cliente.distancia << ")\n";
            if (nodo->cliente.Ref1 != "null") {
                archivoPython << "G.add_edge('" << nodo->cliente.nombre << "', '" << nodo->cliente.Ref1 << "', weight=" << nodo->cliente.dis1 << ")\n";
            }
            if (nodo->cliente.Ref2 != "null") {
                archivoPython << "G.add_edge('" << nodo->cliente.nombre << "', '" << nodo->cliente.Ref2 << "', weight=" << nodo->cliente.dis2 << ")\n";
            }
        }
    }

    archivoPython << "pos = nx.spring_layout(G, weight='weight', scale=10, k=2)\n";
    archivoPython << "edges = G.edges(data=True)\n";
    archivoPython << "weights = [edge[2]['weight'] for edge in edges]\n";
    archivoPython << "colors = ['red' if node == 'Fabrica' else 'skyblue' for node in G.nodes()]\n";
    archivoPython << "nx.draw(G, pos, with_labels=True, node_size=700, node_color=colors, font_size=10, font_weight='bold')\n";
    archivoPython << "nx.draw_networkx_edges(G, pos, width=1.0)\n";
    archivoPython << "nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): d['weight'] for u, v, d in edges})\n";
    archivoPython << "plt.show()\n";

    archivoPython.close();
    std::system("python graficar_grafo.py");
}

void GrafoClientes::graficarRutaOptima(const std::string &clienteObjetivo) {
    std::ofstream archivoPython("graficar_ruta_optima.py");
    if (!archivoPython) {
        std::cerr << "Error al crear el archivo Python para graficar.\n";
        return;
    }

    archivoPython << "import matplotlib.pyplot as plt\n";
    archivoPython << "import networkx as nx\n";
    archivoPython << "import heapq\n";
    archivoPython << "from matplotlib.patches import FancyArrowPatch\n\n";

    archivoPython << "G = nx.DiGraph()\n\n";
    archivoPython << "G.add_node('Fabrica')\n";

    for (auto nodo : nodos) {
        if (nodo->cliente.nombre != "Fabrica") {
            archivoPython << "G.add_node('" << nodo->cliente.nombre << "')\n";
            archivoPython << "G.add_edge('Fabrica', '" << nodo->cliente.nombre << "', weight=" << nodo->cliente.distancia << ")\n";
            if (nodo->cliente.Ref1 != "null") {
                archivoPython << "G.add_edge('" << nodo->cliente.nombre << "', '" << nodo->cliente.Ref1 << "', weight=" << nodo->cliente.dis1 << ")\n";
            }
            if (nodo->cliente.Ref2 != "null") {
                archivoPython << "G.add_edge('" << nodo->cliente.nombre << "', '" << nodo->cliente.Ref2 << "', weight=" << nodo->cliente.dis2 << ")\n";
            }
        }
    }

    archivoPython << "def dijkstra(graph, start, target):\n";
    archivoPython << "    queue = [(0, start, [])]\n";
    archivoPython << "    visited = set()\n";
    archivoPython << "    while queue:\n";
    archivoPython << "        (cost, node, path) = heapq.heappop(queue)\n";
    archivoPython << "        if node in visited:\n";
    archivoPython << "            continue\n";
    archivoPython << "        path = path + [node]\n";
    archivoPython << "        if node == target:\n";
    archivoPython << "            return path\n";
    archivoPython << "        visited.add(node)\n";
    archivoPython << "        for neighbor, data in graph[node].items():\n";
    archivoPython << "            heapq.heappush(queue, (cost + data['weight'], neighbor, path))\n";
    archivoPython << "    return []\n\n";

    archivoPython << "ruta_optima = dijkstra(G, 'Fabrica', '" << clienteObjetivo << "')\n";
    archivoPython << "edges = G.edges(data=True)\n";
    archivoPython << "weights = [edge[2]['weight'] for edge in edges]\n";
    archivoPython << "colors = ['red' if node == 'Fabrica' else 'skyblue' for node in G.nodes()]\n";
    archivoPython << "pos = nx.spring_layout(G, weight='weight', scale=10, k=2)\n";

    archivoPython << "nx.draw(G, pos, with_labels=True, node_size=700, node_color=colors, font_size=10, font_weight='bold')\n";
    archivoPython << "nx.draw_networkx_edges(G, pos, width=1.0)\n";
    archivoPython << "nx.draw_networkx_edge_labels(G, pos, edge_labels={(u, v): d['weight'] for u, v, d in edges})\n";

    archivoPython << "ruta_edges = [(ruta_optima[i], ruta_optima[i+1]) for i in range(len(ruta_optima)-1)]\n";
    archivoPython << "nx.draw_networkx_edges(G, pos, edgelist=ruta_edges, edge_color='green', style='dashed', width=2.5)\n";

    archivoPython << "for u, v in ruta_edges:\n";
    archivoPython << "    arrow = FancyArrowPatch(pos[u], pos[v], arrowstyle='->', color='green', linewidth=2.5, mutation_scale=15)\n";
    archivoPython << "    plt.gca().add_patch(arrow)\n";

    archivoPython << "plt.show()\n";

    archivoPython.close();
    std::system("python graficar_ruta_optima.py");
}

double GrafoClientes::calcularRutaOptima(const std::string &clienteObjetivo) {
    // 1. Crear el archivo Python para calcular la ruta
    std::ofstream archivoPython("calcular_ruta_optima.py");
    if (!archivoPython) {
        std::cerr << "Error al crear el archivo Python.\n";
        return -1;
    }

    archivoPython << "import networkx as nx\n";
    archivoPython << "import heapq\n\n";
    
    archivoPython << "G = nx.DiGraph()\n";
    archivoPython << "G.add_node('Fabrica')\n";

    for (auto nodo : nodos) {
        if (nodo->cliente.nombre != "Fabrica") {
            archivoPython << "G.add_node('" << nodo->cliente.nombre << "')\n";
            archivoPython << "G.add_edge('Fabrica', '" << nodo->cliente.nombre << "', weight=" << nodo->cliente.distancia << ")\n";
            if (nodo->cliente.Ref1 != "null") {
                archivoPython << "G.add_edge('" << nodo->cliente.nombre << "', '" << nodo->cliente.Ref1 << "', weight=" << nodo->cliente.dis1 << ")\n";
            }
            if (nodo->cliente.Ref2 != "null") {
                archivoPython << "G.add_edge('" << nodo->cliente.nombre << "', '" << nodo->cliente.Ref2 << "', weight=" << nodo->cliente.dis2 << ")\n";
            }
        }
    }

    // Algoritmo de Dijkstra
    archivoPython << "def dijkstra(graph, start, target):\n";
    archivoPython << "    queue = [(0, start)]\n";
    archivoPython << "    visited = {}\n";
    archivoPython << "    while queue:\n";
    archivoPython << "        cost, node = heapq.heappop(queue)\n";
    archivoPython << "        if node in visited:\n";
    archivoPython << "            continue\n";
    archivoPython << "        visited[node] = cost\n";
    archivoPython << "        if node == target:\n";
    archivoPython << "            return cost\n";
    archivoPython << "        for neighbor, data in graph[node].items():\n";
    archivoPython << "            heapq.heappush(queue, (cost + data['weight'], neighbor))\n";
    archivoPython << "    return float('inf')\n\n";

    archivoPython << "distancia_optima = dijkstra(G, 'Fabrica', '" << clienteObjetivo << "')\n";

    // Guardar el resultado en un archivo de texto
    archivoPython << "with open('ruta_optima.txt', 'w') as f:\n";
    archivoPython << "    f.write(str(distancia_optima))\n";

    archivoPython.close();
    
    // 2. Ejecutar el script en Python
    std::system("python calcular_ruta_optima.py");

    // 3. Leer el archivo generado por Python
    std::ifstream archivoTexto("ruta_optima.txt");
    if (!archivoTexto) {
        std::cerr << "Error al leer el archivo de resultados.\n";
        return -1;
    }

    double distanciaOptima;
    archivoTexto >> distanciaOptima;
    archivoTexto.close();

    return distanciaOptima;
}

std::string GrafoClientes::ClienteAString(const Cliente& cliente) {
    std::ostringstream ss;
    ss << cliente.RUC << " "
       << cliente.nombre << " "
       << cliente.Ref1 << " "
       << cliente.Ref2 << " "
       << cliente.distancia << " "
       << cliente.dis1 << " "
       << cliente.dis2;
    return ss.str();
}
