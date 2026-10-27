#include "NodoCola.h"

NodoCola::NodoCola()
{
    Pedido pedido;
    elemento = pedido;
    siguiente = NULL;
}

NodoCola::NodoCola(Pedido p, NodoCola *sig)
{
    elemento = p;
    siguiente = sig;
}

NodoCola::~NodoCola() {}
