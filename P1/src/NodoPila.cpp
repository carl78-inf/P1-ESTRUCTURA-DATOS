#include "NodoPila.h"

//Constructor vacío
NodoPila::NodoPila() {
    Pedido pedido;
    elemento = pedido;
    siguiente = NULL;
}

//Constructor con argumentos
NodoPila::NodoPila(Pedido p, NodoPila *sig) {
    elemento = p;
    siguiente = sig;
}

//Destructor
NodoPila::~NodoPila() {}
