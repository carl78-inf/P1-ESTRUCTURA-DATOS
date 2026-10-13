#ifndef NODOCOLA_H
#define NODOCOLA_H

#include <Pedido.h>
#include <iostream>

using namespace std;

class NodoCola{
    private:
        NodoCola *siguiente;
        Pedido elemento;
        friend class Cola;
    public:
        NodoCola();
        NodoCola(Pedido pedido, NodoCola *sig = NULL);
        virtual ~NodoCola();
};

#endif // NODOCOLA_H

