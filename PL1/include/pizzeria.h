#ifndef PIZZERIA_H
#define PIZZERIA_H

const int PROB_PERSONALIZACION = 20;

enum TipoPizza   { MARGARITA, BARBACOA, VEGETAL, HAWAIANA, ROMANA, CUATRO_QUESOS };
enum Tamano      { MEDIANA, GRANDE };
enum ZonaReparto { NORTE, SUR, ESTE, OESTE };

struct Pedido {
    char        id_pedido[7];   // P + 5 cifras + '\0'
    int         id_cliente;     // 100..999
    TipoPizza   tipo_pizza;
    Tamano      tamano;
    ZonaReparto zona_reparto;
    bool        personalizada;
    char        estado[9];      // "Recibido"
};

class Cola;   // declaración anticipada: aquí solo se usa una referencia

Pedido generarPedido();
void   generarPedidos(Cola& recibidos, int n);

const char* nombreTipo(TipoPizza t);
const char* nombreTamano(Tamano t);
const char* nombreZona(ZonaReparto z);

#endif // PIZZERIA_H
