#include "Cola.h"

//Constructor
Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

//Destructor
Cola::~Cola() {}

//Añadir un pedido al final de la cola
void Cola::encolar(Pedido p)
{
    Nodo *nuevo = new Nodo(p); //Puntero a un nuevo nodo

    //Si está vacía, los dos punteros apuntan al nuevo nodo
    if(esVacia())
    {
        primero = nuevo;
        ultimo = nuevo;
    }

    //Si no, el último nodo apuntará al nuevo, y el puntero último también
    else
    {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }

    longitud++; //Incrementamos la longitud
}

//Quitar el primer elemento de la cola
void Cola::desencolar()
{
    if(!esVacia())
    {
        Pedido elemento = primero->elemento; //elemento = pedido del inicio de la cola
        Nodo *aux = primero;                 //Puntero auxiliar que apunta al primer nodo

        //Si solo hay un elemento, ponemos todos los punteros a null y lo eliminamos
        if((primero == ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }

        //Si no, eliminaremos el primer elemento Y primero apuntará al siguiente nodo
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }

        longitud--; //Decrementamos la longitud
    }
}

//Comprobar si la cola es vacía
bool Cola::esVacia()
{
    return (primero == NULL) && (ultimo == NULL);
}

//Obtenemos el primer elemento de la cola
Pedido Cola::valorInicio()
{
    Pedido porDefecto; //Pedido por defecto para evitar errores en el return

    //Si no es vacía, devolvemos el primer elemento
    if(!esVacia())
    {
        return primero->elemento;
    }

    //Si es vacía imprimimos "Cola Vacía" y devolvemos el pedido por defecto
    else
    {
        cout << "Cola Vacia" << endl;
    }
    return porDefecto;
}

//Obtenemos el último elemento de la cola
Pedido Cola::valorFin()
{
    Pedido porDefecto; //Pedido por defecto para evitar errores en el return

    //Si no es vacía, devolvemos el último elemento
    if(!esVacia())
    {
        return ultimo->elemento;
    }

    //Si es vacía imprimimos "Cola Vacía" y devolvemos el pedido por defecto
    else
    {
        cout << "Cola Vacia" << endl;
    }
    return porDefecto;
}

//Obtenemos la longitud de la cola
int Cola::getLongitud()
{
    return longitud;
}

//Mostramos la cola en formato de tabla
void Cola::mostrar()
{
    //Imprimimos la cabecera de la tabla
    cout << "+--------------------------------------------------------------------------------------------------+" << endl
         << "| Pedido | Cliente | Tipo de Pizza | Tamaño  | Zona  | Preparacion Especial | Estado               |" << endl
         << "+--------------------------------------------------------------------------------------------------+" << endl;

    //Si no está vacía, imprimimos cada elemento de la cola
    if(!esVacia())
    {
        for (Nodo* aux = primero; aux != NULL; aux = aux->siguiente)
        {
            Pedido p = aux->elemento;
            printPedidoCola(p);
            cout << endl; //Imprimimos cada elemento
        }

    }
    else cout << "|        |         |               |         |       |                      |                      |" << endl;

    //Imprimimos el final de la tabla
    cout << "+--------------------------------------------------------------------------------------------------+" << endl;
}
