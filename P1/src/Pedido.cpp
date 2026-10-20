#include "Pedido.h"

#include <iostream>
#include <string.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

string generarIDRandom(){
    string id = "P";
    for (int i = 0; i < 5; i++) {
        id += ('0' + (rand() % 10));
    }
    return id;
}

Pedido generarPedidoRandom(){
    Pedido p;

    p.id_pedido = generarIDRandom();

    int DESDE = 100, HASTA = 999;
    p.id_cliente = rand() % (HASTA - DESDE + 1) + DESDE;

    TipoPizza tipo[] = {MARGARITA, ROMANA, CUATRO_QUESOS, VEGETAL, HAWAIANA, BARBACOA};
    p.tipo_pizza = tipo[rand() % (6)];

    ZonaReparto zona[] = {ESTE, NORTE, SUR, OESTE};
    p.zona_reparto = zona[rand() % (4)];

    Tamano tamano[] = {GRANDE, MEDIANA};
    p.tamano = tamano[rand() % (2)];

    p.personalizada = (rand() % 100) < 20;

    p.estado = "Recibido";

    return p;
}

bool mismoID(Pedido p1, Pedido p2){
    return p1.id_pedido == p2.id_pedido;
}

void print_pedido(Pedido p){
    cout << "[ID: " << p.id_pedido
         << ", Cliente: " << p.id_cliente
         << ", Pizza: ";
    switch(p.tipo_pizza){
        case BARBACOA:
            cout << "Barbacoa";
            break;
        case MARGARITA:
            cout << "Margarita";
            break;
        case HAWAIANA:
            cout << "Hawaiana";
            break;
        case CUATRO_QUESOS:
            cout << "Cuatro Quesos";
            break;
        case VEGETAL:
            cout << "Vegetal";
            break;
        case ROMANA:
            cout << "Romana";
            break;
        defautl:
            cout << "NULL";
    }
    cout << ", Tamano: " << (p.tamano == MEDIANA? "Mediana" : "Grande")
         << ", Zona: ";
    switch(p.zona_reparto){
        case ESTE:
            cout << "Este";
            break;
        case NORTE:
            cout << "Norte";
            break;
        case SUR:
            cout << "Sur";
            break;
        case OESTE:
            cout << "Oeste";
            break;
    }
    cout << ", Personalizada: " << (p.personalizada ? "Si" : "No")
         << ", Estado: " << p.estado << "]";
}

void print_pedido_simple(Pedido p){
    cout << p.id_pedido << " - ";
    switch(p.tipo_pizza){
        case BARBACOA:
            cout << "Barbacoa";
            break;
        case MARGARITA:
            cout << "Margarita";
            break;
        case HAWAIANA:
            cout << "Hawaiana";
            break;
        case CUATRO_QUESOS:
            cout << "Cuatro Quesos";
            break;
        case VEGETAL:
            cout << "Vegetal";
            break;
        case ROMANA:
            cout << "Romana";
            break;
        defautl:
            cout << "NULL";
    }
}
