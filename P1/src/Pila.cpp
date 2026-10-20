#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila(){
    cima = NULL;
    longitud = 0;
}

Pila::~Pila(){
    while(cima) desapilar();
}

bool Pila::es_vacia(){
    return cima == NULL;
}

void Pila::apilar(Pedido p){
    NodoPila *nuevo = new NodoPila(p, cima);
    cima = nuevo;
    longitud++;
}

void Pila::desapilar(){
    NodoPila *nodo;
    if(cima){
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
        longitud--;
    }
}

Pedido Pila::cima_pila(){
    Pedido porDefecto;
    if(!es_vacia()){
        return cima->elemento;
    } else{
        cout << "Pila Vacia" << endl;
    }
    return porDefecto;
}

int Pila::get_longitud(){
    return longitud;
}

void Pila::mostrar(){
    if(!es_vacia()){
        cout << "(cima)" << endl;
        for (NodoPila* aux = cima; aux != NULL; aux = aux->siguiente) {
            Pedido p = aux->elemento;
            cout << "\t";
            print_pedido_simple(p); cout << endl;
        }
        cout << "(fondo)" << endl;

    } else cout << "[]" << endl;
}

// Busca un pedido por su ID dentro de la pila y lo elimina.
// Devuelve true si lo encontro (la pila no expone sus nodos al exterior).
bool Pila::eliminar(string id){
    NodoPila *ant = NULL;
    NodoPila *act = cima;
    while(act != NULL && act->elemento.id_pedido != id){
        ant = act;
        act = act->siguiente;
    }
    if(act == NULL) return false;

    if(ant == NULL) cima = act->siguiente;  // era la cima
    else ant->siguiente = act->siguiente;

    delete act;
    longitud--;
    return true;
}
