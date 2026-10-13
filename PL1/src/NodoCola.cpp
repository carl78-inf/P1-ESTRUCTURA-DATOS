#include "NodoCola.h"

NodoCola::NodoCola(Pedido p, NodoCola *sig){
    elemento = p;
    siguiente = sig;
}

NodoCola::~NodoCola(){}
