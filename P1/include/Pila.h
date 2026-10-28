#ifndef PILA_H
#define PILA_H

#include "NodoPila.h"

//Definición de la clase Cola
class Pila {
    private:
        NodoPila *cima; //Puntero a la cima de la pila
        int longitud;   //Longitud
    public:
        Pila();
        virtual ~Pila();
        bool es_vacia();
        void apilar(Pedido p);
        void desapilar();
        Pedido cima_pila();
        int get_longitud();
        void mostrar();
        Pedido buscar(string id);
        bool eliminar(string id);
};

#endif // PILA_H
