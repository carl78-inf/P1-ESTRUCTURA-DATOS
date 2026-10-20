#include "Pila.h"

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
    longitud++;
}

void Pila::desapilar(){
    NodoPila *nodo;
    if(!es_vacia()){
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
    }
    longitud--;
}

Pedido Pila::cima_pila(){
    if(!es_vacia()){
        return cima->elemento;
    } else{
        cout << "Pila Vacia" << endl;
    }
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
