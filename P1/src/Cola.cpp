#include "Cola.h"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() {}

bool Cola::es_vacia()
{
    return (primero == NULL) && (ultimo == NULL);
}

void Cola::encolar(Pedido p)
{
    NodoCola *nuevo = new NodoCola(p);
    if(es_vacia())
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    longitud++;
}

Pedido Cola::desencolar()
{
    Pedido porDefecto;
    if(!es_vacia())
    {
        Pedido elemento = primero->elemento;
        NodoCola *aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;
        return elemento;
    }
    return porDefecto;
}

Pedido Cola::inicio()
{
    Pedido porDefecto;
    if(!es_vacia())
    {
        return primero->elemento;
    }
    else
    {
        cout << "Cola Vacia" << endl;
    }
    return porDefecto;
}

Pedido Cola::fin()
{
    Pedido porDefecto;
    if(!es_vacia())
    {
        return ultimo->elemento;
    }
    else
    {
        cout << "Cola Vacia" << endl;
    }
    return porDefecto;
}

int Cola::get_longitud()
{
    return longitud;
}

void Cola::mostrar()
{
    if(!es_vacia())
    {
        for (NodoCola* aux = primero; aux != NULL; aux = aux->siguiente)
        {
            Pedido p = aux->elemento;
            print_pedido_tabla(p);
            if(aux->siguiente != NULL) cout << endl;
        }

    }
    else cout << "|        |         |               |         |       |                      |                      |";
}
