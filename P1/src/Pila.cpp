#include "Pila.h"
#include <iostream>

using namespace std;

Pila::Pila(){
    cima = NULL;
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
}

void Pila::desapilar(){
    NodoPila *nodo;
    if(cima){
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
    }
}

Pedido Pila::cima_pila(){
    if(!es_vacia()){
        return cima->elemento;
    } else{
        cout << "Pila Vacia" << endl;
    }
}

void Pila::mostrar(){
    if(!es_vacia()){
        cout << "[";
        for (NodoPila* aux = cima; aux != NULL; aux = aux->siguiente) {
            Pedido p = aux->elemento;
            print_pedido(p);
            if(aux->siguiente != NULL) cout << endl;
        }
        cout << "]" << endl;

    } else cout << "[]" << endl;
}
