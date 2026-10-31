#ifndef COLA_H
#define COLA_H

#include <Nodo.h>

//Definición de la clase Cola
class Cola
{
private:
    Nodo *primero;  //Puntero al primer elemento
    Nodo *ultimo;   //Puntero al último elemento
    int longitud;   //Longitud
public:
    Cola();
    virtual ~Cola();

    void encolar(Pedido); //Añade un Pedido al final de la Cola
    void desencolar();    //Elimina el primer Pedido de la Cola

    bool esVacia();       //Devuelve True si la Cola está vacía

    Pedido valorInicio(); //Devuelve el Pedido del inicio de la Cola
    Pedido valorFin();    //Devuelve el Pedido del final de la Cola

    int getLongitud();    //Devuelve la longitud de la Cola

    void mostrar();       //Muestra la Cola por pantalla en formato tabla
};

#endif // COLA_H
