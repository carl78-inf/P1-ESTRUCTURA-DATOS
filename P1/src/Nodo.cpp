#include "Nodo.h"

//Constructor vacío
Nodo::Nodo()
{
    Pedido pedido;
    elemento = pedido;
    siguiente = NULL;
}

//Constructor con argumentos
Nodo::Nodo(Pedido p, Nodo *sig)
{
    elemento = p;
    siguiente = sig;
}

//Destructor
Nodo::~Nodo() {}
