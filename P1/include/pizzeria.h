#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <Cola.h>

#define ZONAS 4

class pizzeria{
    private:
        Cola pedidos;
        Cola preparacion_especial;
        Cola cocina;
        Cola expedicion[ZONAS];
    public:
        pizzeria();
        virtual ~pizzeria();
        bool idYaEnPedidos(string id);
        void generarPedidos(int numero);
        void ejecutarPasoEjecucion();
        void mostrar();
};

#endif // PIZZERIA_H
