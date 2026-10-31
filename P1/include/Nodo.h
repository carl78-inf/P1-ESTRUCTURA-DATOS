#ifndef NODO_H
#define NODO_H

#include <Pedido.h>

//Definición de la clase NodoPila
class Nodo
{
private:
    Nodo *siguiente; //Puntero al nodo siguiente
    Pedido elemento; //Valor que contiene
    friend class Cola;
    friend class Pila;
public:
    Nodo();
    Nodo(Pedido pedido, Nodo *sig = NULL);
    virtual ~Nodo();
};

#endif // NODO_H
