#include "Cola.h"
#include <iostream>

using namespace std;

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
    if(es_vacia() == false){
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
    if(es_vacia() == false){
        return primero->elemento;
    }
}

Pedido Cola::fin(){
    if(es_vacia() == false){
        return ultimo->elemento;
    }
}

int Cola::get_longitud(){
    return longitud;
}

void Cola::mostrar(){
    for (NodoCola* aux = primero; aux != NULL; aux = aux->siguiente) {
        Pedido p = aux->elemento;
        cout << "ID: " << p.id_pedido
             << " | Cliente: " << p.id_cliente
             << " | Pizza: " << nombreTipo(p.tipo_pizza)
             << " | Tamaño: " << nombreTamano(p.tamano)
             << " | Zona: " << nombreZona(p.zona_reparto)
             << " | Personalizada: " << (p.personalizada ? "Sí" : "No")
             << " | Estado: " << p.estado << endl;
    }
}
