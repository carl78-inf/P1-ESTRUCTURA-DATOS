#include "Cola.h"

Cola::Cola(){
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola(){}

bool Cola::es_vacia(){
    return (primero == NULL) && (ultimo == NULL);
}

void Cola::encolar(Pedido p){
    NodoCola *nuevo = new NodoCola(p);
    if(es_vacia()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    longitud++;
}

Pedido Cola::desencolar(){
    if(!es_vacia()){
        Pedido elemento = primero->elemento;
        NodoCola *aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL)){
           primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else{
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;
        return elemento;
    }
}

Pedido Cola::inicio(){
    if(!es_vacia()){
        return primero->elemento;
    }
}

Pedido Cola::fin(){
    if(!es_vacia()){
        return ultimo->elemento;
    }
}

int Cola::get_longitud(){
    return longitud;
}

void Cola::mostrar(){
    if(!es_vacia()){
        cout << "[";
        for (NodoCola* aux = primero; aux != NULL; aux = aux->siguiente) {
            Pedido p = aux->elemento;
            print_pedido(p);
            if(aux->siguiente != NULL) cout << endl;
        }
        cout << "]" << endl;

    } else cout << "[]" << endl;
}
