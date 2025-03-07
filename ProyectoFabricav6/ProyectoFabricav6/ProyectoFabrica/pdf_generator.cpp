#include "pdf_generator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void createPDF(const std::string &inputFile) {
    std::ifstream archivo(inputFile);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << inputFile << " para lectura.\n";
        return;
    }

    std::string outputFile = inputFile.substr(0, inputFile.find_last_of('.')) + ".pdf";
    std::ofstream pdf(outputFile);
    if (!pdf) {
        std::cerr << "Error al crear el archivo PDF " << outputFile << ".\n";
        return;
    }

    pdf << "%PDF-1.4\n";
    pdf << "1 0 obj\n";
    pdf << "<< /Type /Catalog /Pages 2 0 R >>\n";
    pdf << "endobj\n";
    pdf << "2 0 obj\n";
    pdf << "<< /Type /Pages /Kids [3 0 R] /Count 1 >>\n";
    pdf << "endobj\n";
    pdf << "3 0 obj\n";
    pdf << "<< /Type /Page /Parent 2 0 R /MediaBox [0 0 612 792] /Contents 4 0 R /Resources << /Font << /F1 5 0 R >> >> >>\n";
    pdf << "endobj\n";
    pdf << "4 0 obj\n";
    pdf << "<< /Length 44 >>\n";
    pdf << "stream\n";
    pdf << "BT /F1 12 Tf 50 750 Td (Contenido del archivo " << inputFile << ":) Tj ET\n";

    std::string linea;
    int y = 730;
    while (getline(archivo, linea)) {
        pdf << "BT /F1 12 Tf 50 " << y << " Td (" << linea << ") Tj ET\n";
        y -= 20;
    }

    pdf << "endstream\n";
    pdf << "endobj\n";
    pdf << "5 0 obj\n";
    pdf << "<< /Type /Font /Subtype /Type1 /BaseFont /Helvetica >>\n";
    pdf << "endobj\n";
    pdf << "xref\n";
    pdf << "0 6\n";
    pdf << "0000000000 65535 f \n";
    pdf << "0000000010 00000 n \n";
    pdf << "0000000079 00000 n \n";
    pdf << "0000000178 00000 n \n";
    pdf << "0000000371 00000 n \n";
    pdf << "0000000450 00000 n \n";
    pdf << "trailer\n";
    pdf << "<< /Size 6 /Root 1 0 R >>\n";
    pdf << "startxref\n";
    pdf << "519\n";
    pdf << "%%EOF\n";

    archivo.close();
    pdf.close();

    std::cout << "Archivo PDF creado exitosamente: " << outputFile << std::endl;
}

void createClientsPDF(const GrafoClientes &clientes, const std::string &outputFile) {
    std::ofstream pdf(outputFile);
    if (!pdf) {
        std::cerr << "Error al crear el archivo PDF " << outputFile << ".\n";
        return;
    }

    pdf << "%PDF-1.4\n";
    pdf << "1 0 obj\n";
    pdf << "<< /Type /Catalog /Pages 2 0 R >>\n";
    pdf << "endobj\n";
    pdf << "2 0 obj\n";
    pdf << "<< /Type /Pages /Kids [3 0 R] /Count 1 >>\n";
    pdf << "endobj\n";
    pdf << "3 0 obj\n";
    pdf << "<< /Type /Page /Parent 2 0 R /MediaBox [0 0 612 792] /Contents 4 0 R /Resources << /Font << /F1 5 0 R >> >> >>\n";
    pdf << "endobj\n";
    pdf << "4 0 obj\n";
    pdf << "<< /Length 44 >>\n";
    pdf << "stream\n";
    pdf << "BT /F1 12 Tf 50 750 Td (Lista de clientes:) Tj ET\n";

    int y = 730;
    for (const auto& nodo : clientes.nodos) {
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Cliente: " << nodo->cliente.nombre << " (RUC: " << nodo->cliente.RUC << ")) Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Referencia 1: " << nodo->cliente.Ref1 << ") Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Referencia 2: " << nodo->cliente.Ref2 << ") Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Distancia total: " << nodo->cliente.distancia << " km) Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Distancia a Ref1: " << nodo->cliente.dis1 << " km) Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Distancia a Ref2: " << nodo->cliente.dis2 << " km) Tj ET\n";
        y -= 40;
    }

    pdf << "endstream\n";
    pdf << "endobj\n";
    pdf << "5 0 obj\n";
    pdf << "<< /Type /Font /Subtype /Type1 /BaseFont /Helvetica >>\n";
    pdf << "endobj\n";
    pdf << "xref\n";
    pdf << "0 6\n";
    pdf << "0000000000 65535 f \n";
    pdf << "0000000010 00000 n \n";
    pdf << "0000000079 00000 n \n";
    pdf << "0000000178 00000 n \n";
    pdf << "0000000371 00000 n \n";
    pdf << "0000000450 00000 n \n";
    pdf << "trailer\n";
    pdf << "<< /Size 6 /Root 1 0 R >>\n";
    pdf << "startxref\n";
    pdf << "519\n";
    pdf << "%%EOF\n";

    pdf.close();
    std::cout << "Archivo PDF de clientes creado exitosamente: " << outputFile << std::endl;
}

void createToolsPDF(const ListaHerramientas &herramientas, const std::string &outputFile) {
    std::ofstream pdf(outputFile);
    if (!pdf) {
        std::cerr << "Error al crear el archivo PDF " << outputFile << ".\n";
        return;
    }

    pdf << "%PDF-1.4\n";
    pdf << "1 0 obj\n";
    pdf << "<< /Type /Catalog /Pages 2 0 R >>\n";
    pdf << "endobj\n";
    pdf << "2 0 obj\n";
    pdf << "<< /Type /Pages /Kids [3 0 R] /Count 1 >>\n";
    pdf << "endobj\n";
    pdf << "3 0 obj\n";
    pdf << "<< /Type /Page /Parent 2 0 R /MediaBox [0 0 612 792] /Contents 4 0 R /Resources << /Font << /F1 5 0 R >> >> >>\n";
    pdf << "endobj\n";
    pdf << "4 0 obj\n";
    pdf << "<< /Length 44 >>\n";
    pdf << "stream\n";
    pdf << "BT /F1 12 Tf 50 750 Td (Lista de herramientas:) Tj ET\n";

    int y = 730;
    NodoHerramienta* temp = herramientas.getCabeza();
    while (temp) {
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Herramienta: " << temp->herramienta.nombre << " (ID: " << temp->herramienta.ID << ")) Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Peso: " << temp->herramienta.peso << " kg) Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Precio: $" << temp->herramienta.precio << ") Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Cantidad en stock: " << temp->herramienta.cantidad << ") Tj ET\n";
        y -= 40;
        temp = temp->siguiente;
    }

    pdf << "endstream\n";
    pdf << "endobj\n";
    pdf << "5 0 obj\n";
    pdf << "<< /Type /Font /Subtype /Type1 /BaseFont /Helvetica >>\n";
    pdf << "endobj\n";
    pdf << "xref\n";
    pdf << "0 6\n";
    pdf << "0000000000 65535 f \n";
    pdf << "0000000010 00000 n \n";
    pdf << "0000000079 00000 n \n";
    pdf << "0000000178 00000 n \n";
    pdf << "0000000371 00000 n \n";
    pdf << "0000000450 00000 n \n";
    pdf << "trailer\n";
    pdf << "<< /Size 6 /Root 1 0 R >>\n";
    pdf << "startxref\n";
    pdf << "519\n";
    pdf << "%%EOF\n";

    pdf.close();
    std::cout << "Archivo PDF de herramientas creado exitosamente: " << outputFile << std::endl;
}


void createOrdersPDF(const ListaPedidos &pedidos, const std::string &outputFile) {
    std::ofstream pdf(outputFile);
    if (!pdf) {
        std::cerr << "Error al crear el archivo PDF " << outputFile << ".\n";
        return;
    }

    // Cabecera del PDF
    pdf << "%PDF-1.4\n";
    pdf << "1 0 obj\n";
    pdf << "<< /Type /Catalog /Pages 2 0 R >>\n";
    pdf << "endobj\n";
    pdf << "2 0 obj\n";
    pdf << "<< /Type /Pages /Kids [3 0 R] /Count 1 >>\n";
    pdf << "endobj\n";
    pdf << "3 0 obj\n";
    pdf << "<< /Type /Page /Parent 2 0 R /MediaBox [0 0 612 792] /Contents 4 0 R /Resources << /Font << /F1 5 0 R >> >> >>\n";
    pdf << "endobj\n";
    pdf << "4 0 obj\n";
    pdf << "<< /Length 55 >>\n";
    pdf << "stream\n";

    // Comienza el contenido del PDF con texto "Lista de pedidos"
    pdf << "BT /F1 12 Tf 50 750 Td (Lista de pedidos:) Tj ET\n";

    int y = 730;
    NodoPedido* temp = pedidos.getCabeza();
    
    // Itera sobre todos los pedidos
    while (temp) {
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Pedido No: " << temp->pedido.NoPedido << ") Tj ET\n";
        y -= 20;

        pdf << "BT /F1 12 Tf 50 " << y << " Td (Destinatario: " << temp->pedido.destinatario << ") Tj ET\n";
        y -= 20;
        
        // Formateo de fechas
        std::tm* fechaPedido = std::localtime(&temp->pedido.fechaPedido);

        pdf << "BT /F1 12 Tf 50 " << y << " Td (Fecha de Pedido: " << std::put_time(fechaPedido, "%Y-%m-%d %H:%M:%S") << ") Tj ET\n";
        y -= 20;

        std::tm* fechaEntrega = std::localtime(&temp->pedido.fechaEntrega);

        pdf << "BT /F1 12 Tf 50 " << y << " Td (Fecha de Entrega: " << std::put_time(fechaEntrega, "%Y-%m-%d %H:%M:%S") << ") Tj ET\n";
        y -= 20;

        pdf << "BT /F1 12 Tf 50 " << y << " Td (Estado: " << temp->pedido.estado;
        if (temp->pedido.estado == "cancelado") {
            pdf << " (Causa: " << temp->pedido.causa << ") ";
        }
        pdf << ") Tj ET\n";
        y -= 20;

        pdf << "BT /F1 12 Tf 50 " << y << " Td (Costo Herramientas: $" << temp->pedido.costoHerramientas << ") Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Costo Envío: $" << temp->pedido.costoEnvio << ") Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Costo Total: $" << temp->pedido.costoTotal << ") Tj ET\n";
        y -= 20;
        pdf << "BT /F1 12 Tf 50 " << y << " Td (Peso Total: " << temp->pedido.pesoTotal << " kg) Tj ET\n";
        y -= 20;

        pdf << "BT /F1 12 Tf 50 " << y << " Td (Herramientas incluidas:) Tj ET\n";
        y -= 20;

        for (const auto& herramienta : temp->pedido.herramientas) {
            pdf << "BT /F1 12 Tf 50 " << y << " Td (  - " << herramienta.first.nombre << " (ID: " << herramienta.first.ID 
                << "), Cantidad: " << herramienta.second 
                << ", Peso: " << herramienta.first.peso << " kg) Tj ET\n";
            y -= 20;
        }

        y -= 20;
        temp = temp->siguiente;
    }

    // Fin de la secuencia de contenido
    pdf << "endstream\n";
    pdf << "endobj\n";

    // Definición de la fuente
    pdf << "5 0 obj\n";
    pdf << "<< /Type /Font /Subtype /Type1 /BaseFont /Helvetica >>\n";
    pdf << "endobj\n";

    // Xref y Trailer
    pdf << "xref\n";
    pdf << "0 6\n";
    pdf << "0000000000 65535 f \n";
    pdf << "0000000010 00000 n \n";
    pdf << "0000000079 00000 n \n";
    pdf << "0000000178 00000 n \n";
    pdf << "0000000371 00000 n \n";
    pdf << "0000000450 00000 n \n";
    pdf << "trailer\n";
    pdf << "<< /Size 6 /Root 1 0 R >>\n";
    pdf << "startxref\n";
    pdf << "519\n";
    pdf << "%%EOF\n";

    pdf.close();
    std::cout << "Archivo PDF de pedidos creado exitosamente: " << outputFile << std::endl;
}
