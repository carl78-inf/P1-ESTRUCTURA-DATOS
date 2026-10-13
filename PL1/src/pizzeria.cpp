#include "pizzeria.h"
#include "Cola.h"
#include <stdlib.h>
#include <string.h>

int contadorPedidos = 10000;   // Así sabemos que hay IDs únicos en esta ejecución

Pedido generarPedido() {
    Pedido p;

    int n = contadorPedidos;

    p.id_pedido[0] = 'P';
    p.id_pedido[5] = '0' + n % 10;   // unidades
    n = n / 10;
    p.id_pedido[4] = '0' + n % 10;   // decenas
    n = n / 10;
    p.id_pedido[3] = '0' + n % 10;   // centenas
    n = n / 10;
    p.id_pedido[2] = '0' + n % 10;   // millares
    n = n / 10;
    p.id_pedido[1] = '0' + n % 10;   // decenas de millar
    p.id_pedido[6] = '\0';           // fin de la cadena

    contadorPedidos++;

    p.id_cliente = rand() % 900 + 100;

    p.tipo_pizza   = (TipoPizza) (rand() % 6);
    p.tamano       = (Tamano) (rand() % 2);
    p.zona_reparto = (ZonaReparto) (rand() % 4);

    p.personalizada = (rand() % 100 < PROB_PERSONALIZACION);

    strcpy(p.estado, "Recibido");

    return p;
}

void generarPedidos(Cola& recibidos, int n) {
    for (int i = 0; i < n; i++)
        recibidos.encolar(generarPedido());
}

const char* nombreTipo(TipoPizza t) {
    const char* nombres[] = {"Margarita", "Barbacoa", "Vegetal",
                             "Hawaiana", "Romana", "Cuatro quesos"};
    return nombres[t];
}

const char* nombreTamano(Tamano t) {
    const char* nombres[] = {"Mediana", "Grande"};
    return nombres[t];
}

const char* nombreZona(ZonaReparto z) {
    const char* nombres[] = {"Norte", "Sur", "Este", "Oeste"};
    return nombres[z];
}
