#ifndef COLA_H
#define COLA_H
#include <NodoCola.h>

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

        void print_cola();
        void mostrar();
};

#endif // COLA_H
