#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <Cola.h>
#include <Pila.h>

#define ZONAS 4
#define CAP_CAJA 6

class pizzeria
{
private:
    Cola pedidos;
    Cola preparacion_especial;
    Cola cocina;
    Cola expedicion[ZONAS];
    Pila caja[ZONAS];
    int cajas_enviadas[ZONAS];
    int pedidos_fuera;
public:
    pizzeria();
    virtual ~pizzeria();
    bool idYaEnPedidos(string id);
    void generarPedidos(int numero);
    void ejecutarPasoEjecucion();
    void mostrar();
    void verCajaActiva(int zona);
    void retirarPedido(int zona, string id);
    int ocupacionCaja(int zona);
};

#endif // PIZZERIA_H
