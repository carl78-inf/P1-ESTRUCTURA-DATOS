#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

//Definición de la clase Pila
class Pila
{
private:
    Nodo *cima;   //Puntero a la cima de la pila
    int longitud; //Longitud
public:
    Pila();
    virtual ~Pila();

    void apilar(Pedido p); //Añade un Pedido en la cima de la Pila
    void desapilar();      //Elimina el Pedido de la cima de la Pila

    bool esVacia();        //Devuelve True si la Pila está vacía
    Pedido valorCima();
    int getLongitud();

    void mostrar();
};

#endif // PILA_H
