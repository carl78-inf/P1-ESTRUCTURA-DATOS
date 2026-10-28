#ifndef NODOPILA_H
#define NODOPILA_H

#include <Pedido.h>

//Definición de la clase NodoPila
class NodoPila {
    private:
        NodoPila *siguiente; //Puntero al nodo siguiente (anterior)
        Pedido elemento;     //Valor que contiene
        friend class Pila;
    public:
        NodoPila();
        NodoPila(Pedido pedido, NodoPila *sig = NULL);
        virtual ~NodoPila();
};

#endif // NODOPILA_H
