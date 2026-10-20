#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

class Pila{
    private:
        NodoPila *cima;
        int longitud;
    public:
        Pila();
        virtual ~Pila();
        bool es_vacia();
        void apilar(Pedido p);
        void desapilar();
        Pedido cima_pila();
        int get_longitud();
        void mostrar();
};

#endif // PILA_H
