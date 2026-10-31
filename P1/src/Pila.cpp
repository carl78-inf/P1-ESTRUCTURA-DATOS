#include "Pila.h"

//Constructor
Pila::Pila()
{
    cima = NULL;
    longitud = 0;
}

//Destructor
Pila::~Pila()
{
    while(cima) desapilar();
}

//Comprobar si la pila es vacía
bool Pila::esVacia()
{
    return cima == NULL;
}

//Añadir un pedido en la cima de la pila
void Pila::apilar(Pedido p)
{
    Nodo *nuevo = new Nodo(p, cima); //Puntero a un nuevo nodo
    cima = nuevo;                            //Asignamos la cima al nuevo nodo
    longitud++;                              //Incrementamos la longitud
}

//Quitar el primer elemento de la cima de la pila
void Pila::desapilar()
{
    Nodo *nodo;
    if(!esVacia())
    {
        nodo = cima;            //Puntero auxiliar apunta a la cima
        cima = nodo->siguiente; //Cima apunta al nodo siguiente
        delete nodo;            //Eliminamos el nodo
        longitud--;             //Decrementamos la longitud
    }
}

//Obtenemos el elemento de la cima de la pila
Pedido Pila::valorCima()
{
    Pedido porDefecto; //Pedido por defecto para evitar errores en el return

    //Si no es vacía, devolvemos el elemento de la cima
    if(!esVacia())
    {
        return cima->elemento;
    }

    //Si es vacía imprimimos "Pila Vacía" y devolvemos el pedido por defecto
    else
    {
        cout << "Pila Vacia" << endl;
    }
    return porDefecto;
}

//Obtenemos la longitud de la pila
int Pila::getLongitud()
{
    return longitud;
}

//Mostramos la pila por pantalla
void Pila::mostrar()
{
    //Si no está vacía, imprimimos cada elemento de la pila
    if(!esVacia())
    {
        cout << "(cima)" << endl;
        for (Nodo* aux = cima; aux != NULL; aux = aux->siguiente)
        {
            Pedido p = aux->elemento;
            cout << "\t";
            printPedidoPila(p);
            cout << endl;
        }
        cout << "(fondo)" << endl;
    }
    else cout << "[]" << endl;
}
