#ifndef COLA_H
#define COLA_H

#include <NodoCola.h>
#include <iostream>

using namespace std;

class Cola{
    private:
        NodoCola *primero;
        NodoCola *ultimo;
        int longitud;
    public:
        Cola();
        virtual ~Cola();
        bool es_vacia();
        void encolar(Pedido);
        Pedido desencolar();
        Pedido inicio();
        Pedido fin();
        int get_longitud();

        void mostrar();
};

#endif // COLA_H
