#ifndef NODOCOLA_H
#define NODOCOLA_H

#include <Pedido.h>

//Definición de la clase NodoCola
class NodoCola {
    private:
        NodoCola *siguiente; //Puntero al nodo siguiente
        Pedido elemento;     //Valor que contiene
        friend class Cola;
    public:
        NodoCola();
        NodoCola(Pedido pedido, NodoCola *sig = NULL);
        virtual ~NodoCola();
};

#endif // NODOCOLA_H

