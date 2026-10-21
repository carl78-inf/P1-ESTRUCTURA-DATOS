#ifndef PEDIDO_H
#define PEDIDO_H

#define PROB_PERSONALIZACION 20

#include <string>

using namespace std;

enum TipoPizza {MARGARITA, BARBACOA, VEGETAL, HAWAIANA, ROMANA, CUATRO_QUESOS};
enum Tamano {MEDIANA, GRANDE};
enum ZonaReparto {NORTE, SUR, ESTE, OESTE};

struct Pedido {
    string id_pedido = "P00000";
    int id_cliente = 100;
    TipoPizza tipo_pizza = BARBACOA;
    Tamano tamano = MEDIANA;
    ZonaReparto zona_reparto = ESTE;
    bool personalizada = false;
    string estado = "Recibido";
};

string generarIDRandom();

Pedido generarPedidoRandom();

bool mismoID(Pedido p1, Pedido p2);

void print_pedido(Pedido p);

void print_pedido_simple(Pedido p);

void print_pedido_tabla(Pedido p);

#endif // PEDIDO_H
