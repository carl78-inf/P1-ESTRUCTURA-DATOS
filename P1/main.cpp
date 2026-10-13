#include <iostream>

#include <pizzeria.h>

using namespace std;

int main(){
    srand(time(NULL));

    pizzeria p;
    int option;
    int n;

    cout << "--- Simulación del sistema de pedidos de una pizzería ---" << endl;

    do {
        cout << endl;
        cout << "|Menu de seleccion|" << endl;
        cout << "-------------------" << endl;
        cout << "1. Generar N pedidos" << endl;
        cout << "2. Ejecutar un paso de simulacion" << endl;
        cout << "3. Mostrar el estado del sistema" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccion(0,1,2,3): ";

        cin >> option;

        switch (option) {
            case 1:
                cout << "Introduce el numero de pedidos a generar: ";
                cin >> n;
                if (n > 0) {
                    p.generarPedidos(n);
                    cout << n << " pedidos generados." << endl;
                } else {
                    cout << "El numero debe ser mayor que 0" << endl;
                }
                break;

            case 2:
                //cambiar esto y poner lo de pasos en la simulación
                break;

            case 3:
                p.mostrar();
                break;

            case 0:
                cout << "Saliendo" << endl;
                break;

            default:
                cout << "Opción no válida." << endl;
        }

    } while (option != 0);

    return 0;
}





/*Pedido p = generarPedidoRandom();
    Pedido p2 = generarPedidoRandom();
    print_pedido(p); cout << endl;
    print_pedido(p2); cout << endl;
    cout << "Mismo ID: " << (mismoID(p, p2) ? "Si" : "No") << endl;*/

/*//Cola de Pedidos
    Cola c = Cola();
    Pedido p;
    c.encolar(p);
    strcpy(p.id_pedido, "P11111");
    p.id_cliente = 111;
    p.tipo_pizza = MARGARITA;
    p.zona_reparto = NORTE;
    p.tamano = GRANDE;
    p.personalizada = false;
    strcpy(p.estado, "Recibido");
    c.encolar(p);

    c.print_pedido(c.inicio());
    c.print_pedido(c.fin());
    c.encolar(p);
    c.desencolar();
    c.print_cola();
    cout << (c.es_vacia()? "Vacia":"No vacia") << endl;
    c.desencolar();
    c.desencolar();
    c.print_cola();
    cout << (c.es_vacia()? "Vacia":"No vacia") << endl;



    srand(time(NULL));
    //Práctica
    cout << "--- Simulacion del sistema de pedidos de una pizzeria ---" << endl;
    Cola pedidos = Cola();
    Pizzeria pizzeria;
    char option;
    do {
        cout << endl;
        cout << "|Menu de seleccion|" << endl;
        cout << "-------------------" << endl;
        cout << "1. Generar N pedidos" << endl;
        cout << "2. Mostrar pedidos recibidos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccion(0,1,2): ";

        cin >> option;

        switch (option) {
            case '1':
                int n;
                cout << "Introduce el numero de pedidos a generar:  ";
                cin >> n;
                if (n > 0) {
                    pizzeria.generarPedidos(pedidos, n);
                    cout << n << " pedidos generados." << endl;
                } else {
                    cout << "El número debe ser mayor que 0" << endl;
                }
                break;

            case '2':
                if (pedidos.es_vacia())
                    cout << "No hay pedidos recibidos." << endl;
                else
                    pedidos.mostrar();
                break;

            case '0':
                cout << "Saliendo" << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (option != '0');*/
