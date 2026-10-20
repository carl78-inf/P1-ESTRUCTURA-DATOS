#include "NodoPila.h"

NodoPila::NodoPila(){
    Pedido pedido;
    elemento = pedido;
    siguiente = NULL;
}

NodoPila::NodoPila(Pedido p, NodoPila *sig){
    elemento = p;
    siguiente = sig;
}

NodoPila::~NodoPila(){}
