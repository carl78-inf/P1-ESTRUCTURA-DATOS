#ifndef COLA_H
#define COLA_H
#include "pizzeria.h"
#include "NodoCola.h"


class Cola{
    public:
        Cola();
        ~Cola();
        void encolar(Pedido);
        Pedido inicio();
        Pedido fin();
        Pedido desencolar();
        bool es_vacia();
        void mostrar();
        int get_longitud();
    private:
        NodoCola *primero;
        NodoCola *ultimo;
        int longitud;
};

#endif // COLA_H
