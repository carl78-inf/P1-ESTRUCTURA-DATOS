#include "pizzeria.h"

pizzeria::pizzeria(){}

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

void pizzeria::mostrar(){
    cout << "------------------------------------------------------Pedidos-----------------------------------------------------" << endl;
    pedidos.mostrar(); cout << endl;
    cout << "-----------------------------------------------Preparacion-Especial-----------------------------------------------" << endl;
    preparacion_especial.mostrar(); cout << endl;
    cout << "------------------------------------------------------Cocina------------------------------------------------------" << endl;
    cocina.mostrar(); cout << endl;
    cout << "-------------------------------------------------Expedicion-Norte-------------------------------------------------" << endl;
    expedicion_norte.mostrar(); cout << endl;
    cout << "--------------------------------------------------Expedicion-Sur--------------------------------------------------" << endl;
    expedicion_sur.mostrar(); cout << endl;
    cout << "--------------------------------------------------Expedicion-Este-------------------------------------------------" << endl;
    expedicion_este.mostrar(); cout << endl;
    cout << "-------------------------------------------------Expedicion-Oeste-------------------------------------------------" << endl;
    expedicion_oeste.mostrar(); cout << endl;
}

/*#include "pizzeria.h"
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
