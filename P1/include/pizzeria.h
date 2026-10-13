#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <Cola.h>


class pizzeria{
    private:
        Cola pedidos;
        Cola preparacion_especial;
        Cola cocina;
        Cola expedicion_norte;
        Cola expedicion_sur;
        Cola expedicion_este;
        Cola expedicion_oeste;
    public:
        pizzeria();
        virtual ~pizzeria();
        bool idYaEnPedidos(string id);
        void generarPedidos(int numero);
        void mostrar();
};

#endif // PIZZERIA_H
