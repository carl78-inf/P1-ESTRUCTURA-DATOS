#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <iostream>
#include <string.h>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

#define PROB_PERSONALIZACION 20

using namespace std;

//Definición de los tipos enumerados que utilizará Pedido
enum TipoPizza {MARGARITA, BARBACOA, VEGETAL, HAWAIANA, ROMANA, CUATRO_QUESOS};
enum Tamano {MEDIANA, GRANDE};
enum ZonaReparto {NORTE, SUR, ESTE, OESTE};

//Definición del tipo Pedido
struct Pedido
{
    string id_pedido;           //P + cinco dígitos 0-9
    int id_cliente;             //Entero entre 100 y 999
    TipoPizza tipo_pizza;       //Tipo de pizza (una pizza por pedido)
    Tamano tamano;              //Tamaño de la pizza
    ZonaReparto zona_reparto;   //Zona de reparto
    bool personalizada;         //True si preparación especial
    string estado;              //Estado en el que se encuentra el pedido
};

string generarIDRandom();                     //Genera un ID de pedido aleatorio

Pedido generarPedidoRandom(string id = "");   //Genera un pedido aleatorio

bool mismoID(Pedido p1, Pedido p2);           //Compara el ID de dos pedidos y devuelve True si son iguales

void printPedidoPila(Pedido p);               //Imprime el pedido en modo simple para la Pila --> id y tipo_pizza

void printPedidoCola(Pedido p);            //Imprime el pedido en formato de fila de una tabla para la Cola

#endif // PEDIDO_H
