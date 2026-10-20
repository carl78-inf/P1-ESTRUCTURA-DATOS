#include "pizzeria.h"

#define N_PEDIDOS_PASO 10

// Nombre de la zona a partir de su indice (0=Norte, 1=Sur, 2=Este, 3=Oeste)
static string nombreZona(int i){
    switch(i){
        case 0: return "Norte";
        case 1: return "Sur";
        case 2: return "Este";
        case 3: return "Oeste";
    }
    return "?";
}

// La zona del menu es 1=Norte, 2=Sur, 3=Este, 4=Oeste. Devuelve -1 si no es valida.
static int indiceZona(int zona){
    if(zona >= 1 && zona <= ZONAS) return zona - 1;
    return -1;
}

pizzeria::pizzeria(){
    pedidos_fuera = 0;
    for(int i = 0; i < ZONAS; i++){
        cajas_enviadas[i] = 0;
    }
}

pizzeria::~pizzeria(){}

bool pizzeria::idYaEnPedidos(string id){
    bool yaEnPedidos = false;
    Cola aux;
    while(!yaEnPedidos && !pedidos.es_vacia()){
        if(pedidos.inicio().id_pedido == id){
            yaEnPedidos = true;
        }
        aux.encolar(pedidos.inicio());
        pedidos.desencolar();
    }
    while(!aux.es_vacia()){
        pedidos.encolar(aux.inicio());
        aux.desencolar();
    }
    return yaEnPedidos;
}

void pizzeria::generarPedidos(int numero){
    string id;
    for(int i = 0; i < numero; i++){
        do{
            id = generarIDRandom();
        } while(idYaEnPedidos(id));
        Pedido p = generarPedidoRandom();
        p.id_pedido = id;
        pedidos.encolar(p);
    }
}

void pizzeria::ejecutarPasoEjecucion(){
    Pedido p;
    int contador = 0;

    // Fase Expedicion -> Caja (solo una fase por ejecucion)
    for(int z = 0; z < ZONAS; z++){
        contador = 0;
        while(!expedicion[z].es_vacia() && contador < N_PEDIDOS_PASO){
            p = expedicion[z].inicio();
            p.estado = "Caja";
            caja[z].apilar(p);
            expedicion[z].desencolar();
            contador++;

            // Caja llena: se envia a reparto y se empieza otra nueva vacia
            if(caja[z].get_longitud() == CAP_CAJA){
                cajas_enviadas[z]++;
                pedidos_fuera += CAP_CAJA;
                while(!caja[z].es_vacia()){
                    caja[z].desapilar();
                }
            }
        }
    }

    contador = 0;
    while(!cocina.es_vacia() && contador < N_PEDIDOS_PASO){
        p = cocina.inicio();
        p.estado = "Expedicion";
        switch(p.zona_reparto){
            case NORTE:
                expedicion[0].encolar(p);
                break;
            case SUR:
                expedicion[1].encolar(p);
                break;
            case ESTE:
                expedicion[2].encolar(p);
                break;
            case OESTE:
                expedicion[3].encolar(p);
                break;
        }
        cocina.desencolar();
        contador++;
    }

    contador = 0;
    while(!preparacion_especial.es_vacia() && contador < N_PEDIDOS_PASO){
        p = preparacion_especial.inicio();
        p.estado = "Cocina";
        cocina.encolar(p);
        preparacion_especial.desencolar();
        contador++;
    }

    contador = 0;
    while(!pedidos.es_vacia() && contador < N_PEDIDOS_PASO){
        p = pedidos.inicio();
        if(p.personalizada){
            p.estado = "Preparacion especial";
            preparacion_especial.encolar(p);
        } else{
            p.estado = "Cocina";
            cocina.encolar(p);
        }
        pedidos.desencolar();
        contador++;
    }
}

void pizzeria::mostrar(){
    cout << "------------------------------------------------------Pedidos-----------------------------------------------------" << endl;
    pedidos.mostrar(); cout << endl;
    cout << "-----------------------------------------------Preparacion-Especial-----------------------------------------------" << endl;
    preparacion_especial.mostrar(); cout << endl;
    cout << "------------------------------------------------------Cocina------------------------------------------------------" << endl;
    cocina.mostrar(); cout << endl;
    cout << "----------------------------------------------------Expedicion----------------------------------------------------" << endl;
    cout << "NORTE: " << endl;
    expedicion[0].mostrar(); cout << endl;
    cout << "SUR: " << endl;
    expedicion[1].mostrar(); cout << endl;
    cout << "ESTE: " << endl;
    expedicion[2].mostrar(); cout << endl;
    cout << "OESTE: " << endl;
    expedicion[3].mostrar(); cout << endl;

    cout << "=== CAJAS TERMICAS ===" << endl;
    int total_enviadas = 0;
    for(int z = 0; z < ZONAS; z++){
        cout << "Zona " << nombreZona(z) << " -> activa: "
             << caja[z].get_longitud() << "/" << CAP_CAJA
             << "  enviadas: " << cajas_enviadas[z] << endl;
        total_enviadas += cajas_enviadas[z];
    }
    cout << endl;
    cout << "Total de cajas enviadas: " << total_enviadas << endl;
    cout << "Pedidos enviados o retirados: " << pedidos_fuera << endl;
}

void pizzeria::verCajaActiva(int zona){
    int z = indiceZona(zona);
    if(z == -1){
        cout << "Zona no valida." << endl;
        return;
    }
    cout << "--- CAJA ACTIVA: ZONA " << nombreZona(z) << " ---" << endl;
    caja[z].mostrar();
}

void pizzeria::retirarPedido(int zona, string id){
    int z = indiceZona(zona);
    if(z == -1){
        cout << "Zona no valida." << endl;
        return;
    }
    if(caja[z].eliminar(id)){
        pedidos_fuera++;
        cout << "Pedido " << id << " retirado de la caja de la zona " << nombreZona(z) << "." << endl;
    } else{
        cout << "El pedido " << id << " no esta en la caja activa de la zona " << nombreZona(z) << "." << endl;
    }
}

/*  Pruebas de colas

#include "pizzeria.h"
#include <string.h>

#include <iostream>

#include <ctime>
#include <stdlib.h>

using namespace std;

Pizzeria::Pizzeria(){}

Pizzeria::~Pizzeria(){}

void Pizzeria::generarPedidos(Cola& pedidos, int n){
    for(int i = 1; i <= n; i++){
        Pedido p;
        p.id_pedido[1] = '0' + (rand() % 10);
        p.id_pedido[2] = '0' + (rand() % 10);
        p.id_pedido[3] = '0' + (rand() % 10);
        p.id_pedido[4] = '0' + (rand() % 10);
        p.id_pedido[5] = '0' + (rand() % 10);
        p.id_pedido[6] = '\0';
        int DESDE = 100, HASTA = 999;
        p.id_cliente = rand() % (DESDE - HASTA + 1) + DESDE;
        TipoPizza tipo[] = {MARGARITA, ROMANA, CUATRO_QUESOS, VEGETAL, HAWAIANA, BARBACOA};
        p.tipo_pizza = tipo[rand() % (6)];
        ZonaReparto zona[] = {ESTE, NORTE, SUR, OESTE};
        p.zona_reparto = zona[rand() % (4)];
        Tamano tamano[] = {GRANDE, MEDIANA};
        p.tamano = tamano[rand() % (2)];
        p.personalizada = (rand() % 100) < 20;
        strcpy(p.estado, "Recibido");
        pedidos.encolar(p);
    }
}

void Pizzeria::mostrarPedidos(Cola& pedidos){
}

*/
