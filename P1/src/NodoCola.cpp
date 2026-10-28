#include "NodoCola.h"

//Constructor vacío
NodoCola::NodoCola() {
    Pedido pedido;
    elemento = pedido;
    siguiente = NULL;
}

//Constructor con argumentos
NodoCola::NodoCola(Pedido p, NodoCola *sig) {
    elemento = p;
    siguiente = sig;
}

//Destructor
NodoCola::~NodoCola() {}
