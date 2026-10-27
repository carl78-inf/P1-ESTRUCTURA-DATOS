#include "Pila.h"

Pila::Pila()
{
    cima = NULL;
    longitud = 0;
}

Pila::~Pila()
{
    while(cima) desapilar();
}

bool Pila::es_vacia()
{
    return cima == NULL;
}

void Pila::apilar(Pedido p)
{
    NodoPila *nuevo = new NodoPila(p, cima);
    cima = nuevo;
    longitud++;
}

void Pila::desapilar()
{
    NodoPila *nodo;
    if(!es_vacia())
    {
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
        longitud--;
    }
}

Pedido Pila::cima_pila()
{
    Pedido porDefecto;
    if(!es_vacia())
    {
        return cima->elemento;
    }
    else
    {
        cout << "Pila Vacia" << endl;
    }
    return porDefecto;
}

int Pila::get_longitud()
{
    return longitud;
}

void Pila::mostrar()
{
    if(!es_vacia())
    {
        cout << "(cima)" << endl;
        for (NodoPila* aux = cima; aux != NULL; aux = aux->siguiente)
        {
            Pedido p = aux->elemento;
            cout << "\t";
            print_pedido_simple(p);
            cout << endl;
        }
        cout << "(fondo)" << endl;

    }
    else cout << "[]" << endl;
}

bool Pila::eliminar(string id)
{
    NodoPila *ant = NULL;
    NodoPila *act = cima;
    while(act != NULL && act->elemento.id_pedido != id)
    {
        ant = act;
        act = act->siguiente;
    }
    if(act == NULL)
    {
        return false;
    }

    if(ant == NULL)
    {
        cima = act->siguiente;
    }
    else
    {
        ant->siguiente = act->siguiente;
    }

    delete act;
    longitud--;
    return true;
}
