#include "Pedido.h"

#include <iostream>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//Genera un ID de pedido aleatorio
string generarIDRandom() {
    string id = "P";
    for (int i = 0; i < 5; i++) {
        id += ('0' + (rand() % 10)); //Genera un cáracter aleatorio entre '0' y '9'
    }
    return id;
}

//Genera un pedido aleatorio
Pedido generarPedidoRandom(string id) {
    Pedido p; //Pedido a devolver

    if(id == "") {
        p.id_pedido = generarIDRandom(); //Generamos id aleatorio
    } else {
        p.id_pedido = id; //Si le pasamos un id, se lo asignamos al pedido
    }

    int DESDE = 100, HASTA = 999;
    p.id_cliente = rand() % (HASTA - DESDE + 1) + DESDE; //ID de cliente aleatorio

    TipoPizza tipo[] = {MARGARITA, ROMANA, CUATRO_QUESOS, VEGETAL, HAWAIANA, BARBACOA};
    p.tipo_pizza = tipo[rand() % (6)]; //Tipo de pizza aleatorio

    ZonaReparto zona[] = {ESTE, NORTE, SUR, OESTE};
    p.zona_reparto = zona[rand() % (4)]; //Zona de reparto aleatoria

    Tamano tamano[] = {GRANDE, MEDIANA};
    p.tamano = tamano[rand() % (2)]; //Tamaño aleatorio

    p.personalizada = (rand() % 100) < PROB_PERSONALIZACION; //Preparación especial establecido con probabilidad

    p.estado = "Recibido"; //Un pedido siempre comienza con el estado "Recibido"

    return p;
}

//Compara el ID de dos pedidos y devuelve True si son iguales
bool mismoID(Pedido p1, Pedido p2) {
    return p1.id_pedido == p2.id_pedido;
}

//Pasa el tipo enumerado TipoPizza a string
string tipoPizzaToString(TipoPizza tipo){
    string resultado;
    switch(tipo) {
        case BARBACOA:
            resultado = "Barbacoa";
            break;
        case MARGARITA:
            resultado = "Margarita";
            break;
        case HAWAIANA:
            resultado = "Hawaiana";
            break;
        case CUATRO_QUESOS:
            resultado = "Cuatro Quesos";
            break;
        case VEGETAL:
            resultado = "Vegetal";
            break;
        case ROMANA:
            resultado = "Romana";
            break;
        defautl:
            resultado = "NULL";
    }
    return resultado;
}

//Pasa el tipo enumerado Tamano a string
string tamanoToString(Tamano tamano){
    string resultado;
    switch(tamano) {
        case MEDIANA:
            resultado = "Mediana";
            break;
        case GRANDE:
            resultado = "Grande";
            break;
        defautl:
            resultado = "NULL";
    }
    return resultado;
}

//Pasa el tipo enumerado Tamano a string
string zonaRepartoToString(ZonaReparto zona){
    string resultado;
    switch(zona) {
        case ESTE:
            resultado = "Este";
            break;
        case NORTE:
            resultado = "Norte";
            break;
        case SUR:
            resultado = "Sur";
            break;
        case OESTE:
            resultado = "Oeste";
            break;
        defautl:
            resultado = "NULL";
    }
    return resultado;
}

//Imprime el pedido en modo simple --> id y tipo_pizza
void print_pedido_simple(Pedido p) {
    cout << "| " << p.id_pedido << " - "     //ID del pedido
         << tipoPizzaToString(p.tipo_pizza); //Tipo de pizza
}

//Imprime el pedido en formato de fila de una tabla
void print_pedido_tabla(Pedido p) {
    cout << left << "| " << p.id_pedido                             //ID del pedido
         << " | " << setw(7) << p.id_cliente                        //ID del cliente
         << " | " << setw(13) << tipoPizzaToString(p.tipo_pizza)    //Tipo de pizza
         << " | " << setw(7) << tamanoToString(p.tamano)            //Tamaño
         << " | " << setw(5) << zonaRepartoToString(p.zona_reparto) //Zona de reparto
         << " | " << setw(20) << (p.personalizada ? "Si" : "No")    //Preparación especial
         << " | " << setw(20) << p.estado                           //Estado del pedido
         << " |";
}
