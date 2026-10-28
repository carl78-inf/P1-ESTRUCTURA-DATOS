#include "Pila.h"

//Constructor
Pila::Pila() {
    cima = NULL;
    longitud = 0;
}

//Destructor
Pila::~Pila() {
    while(cima) desapilar();
}

//Comprobar si la pila es vacía
bool Pila::es_vacia() {
    return cima == NULL;
}

//Añadir un pedido en la cima de la pila
void Pila::apilar(Pedido p) {
    NodoPila *nuevo = new NodoPila(p, cima); //Puntero a un nuevo nodo
    cima = nuevo;                            //Asignamos la cima al nuevo nodo
    longitud++;                              //Incrementamos la longitud
}

//Quitar el primer elemento de la cima de la pila
void Pila::desapilar() {
    NodoPila *nodo;
    if(!es_vacia()) {
        nodo = cima;            //Puntero auxiliar apunta a la cima
        cima = nodo->siguiente; //Cima apunta al nodo siguiente
        delete nodo;            //Eliminamos el nodo
        longitud--;             //Decrementamos la longitud
    }
}

//Obtenemos el elemento de la cima de la pila
Pedido Pila::cima_pila() {
    Pedido porDefecto; //Pedido por defecto para evitar errores en el return

    //Si no es vacía, devolvemos el elemento de la cima
    if(!es_vacia()) {
        return cima->elemento;
    }

    //Si es vacía imprimimos "Pila Vacía" y devolvemos el pedido por defecto
    else {
        cout << "Pila Vacia" << endl;
    }
    return porDefecto;
}

//Obtenemos la longitud de la pila
int Pila::get_longitud() {
    return longitud;
}

//Mostramos la pila por pantalla
void Pila::mostrar() {
    //Si no está vacía, imprimimos cada elemento de la pila
    if(!es_vacia()) {
        cout << "(cima)" << endl;
        for (NodoPila* aux = cima; aux != NULL; aux = aux->siguiente) {
            Pedido p = aux->elemento;
            cout << "\t";
            print_pedido_simple(p);
            cout << endl;
        }
        cout << "(fondo)" << endl;
    } else cout << "[]" << endl;
}

//Buscar un pedido por su ID
Pedido Pila::buscar(string id) {
    Pedido p;             //Pedido que vamos a devolver
    NodoPila *act = cima; //Puntero auxiliar que apunta a la cima

    //Recorremos la pila hasta encontrar el id o haberla recorrido por completo
    while(act != NULL && act->elemento.id_pedido != id) {
        act = act->siguiente;
    }

    //Si no lo hemos encontrado, devolvemos un pedido por defecto
    if(act == NULL) {
        return p;
    }

    p = act->elemento; //Pedido = elemento del nodo apuntado por actual
    return p;          //Devolvemos el pedido
}

//Eliminamos un pedido por su ID
bool Pila::eliminar(string id) {
    NodoPila *ant = NULL; //Puntero auxiliar anterior
    NodoPila *act = cima; //Puntero auxiliar actual

    //Recorremos la pila con ambos punteros hasta que act tenga el ID que buscamos
    while(act != NULL && act->elemento.id_pedido != id) {
        ant = act;
        act = act->siguiente;
    }

    //Si no se ha encontrado el ID, devolvemos False
    if(act == NULL) {
        return false;
    }

    //Si es el primer elemento, cima apuntará al siguiente
    if(ant == NULL) {
        cima = act->siguiente;
    }

    //Si no, anterior apuntará al siguiente del siguiente de actual
    else{
        ant->siguiente = act->siguiente;
    }

    delete act; //Eliminamos el nodo
    longitud--; //Decrementamos la longitud
    return true;
}
