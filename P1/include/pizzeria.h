#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <Cola.h>
#include <Pila.h>

#define N_PEDIDOS_PASO 10
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
    Cola finalizados;
public:
    pizzeria();
    virtual ~pizzeria();

    bool idYaEnPedidos(string id);
    int ocupacionCaja(int zona);
    void Quitar_pedido_pila(Pila& pila, string);

    void Generar_pedidos(int numero);
    void Dar_paso_simulacion();
    void Mostrar_estado_sistema();
    void Ver_contenido_caja();
    void Retirar_pedido_caja();
    void Mostrar_finalizados();
};

#endif // PIZZERIA_H
