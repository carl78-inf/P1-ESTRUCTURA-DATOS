#ifndef NODOPILA_H
#define NODOPILA_H

#include <Pedido.h>

class NodoPila
{
private:
    NodoPila *siguiente;
    Pedido elemento;
    friend class Pila;
public:
    NodoPila();
    NodoPila(Pedido pedido, NodoPila *sig = NULL);
    virtual ~NodoPila();
};

#endif // NODOPILA_H
