#ifndef NODOCOLA_H
#define NODOCOLA_H

#include <iostream>
#include "pizzeria.h"


class NodoCola{
    public:
        NodoCola(Pedido p, NodoCola *sig = NULL);
        ~NodoCola();
    private:
        NodoCola *siguiente;
        Pedido elemento;
        friend class Cola;
};

#endif // NODOCOLA_H
