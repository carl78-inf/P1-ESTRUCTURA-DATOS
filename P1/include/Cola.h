#ifndef COLA_H
#define COLA_H

#include <Nodo.h>

//Definición de la clase Cola
class Cola {
    private:
        Nodo *primero;  //Puntero al primer elemento
        Nodo *ultimo;   //Puntero al último elemento
        int longitud;       //Longitud
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
