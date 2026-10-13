#include <iostream>

#include "pizzeria.h"
#include "Cola.h"

using namespace std;


/*int main()
{
    cout << "Hola" << endl;
    Cola recibidos;             // cola de pedidos recibidos
    int option;
    int n;

    cout << "--- Simulación del sistema de pedidos de una pizzería ---" << endl;

    do {
        cout << endl;
        cout << "|Menú de selección|" << endl;
        cout << "-------------------" << endl;
        cout << "1. Generar N pedidos" << endl;
        cout << "2. Mostrar pedidos recibidos" << endl;
        cout << "0. Salir" << endl;
        cout << "Selección(0,1,2): ";

        cin >> option;

        switch (option) {
            case 1:
                cout << "¿Cuántos pedidos quieres generar? ";
                cin >> n;
                if (n > 0) {
                    generarPedidos(recibidos, n);
                    cout << n << " pedidos generados." << endl;
                } else {
                    cout << "El número debe ser mayor que 0" << endl;
                }
                break;

            case 2:
                if (recibidos.es_vacia())
                    cout << "No hay pedidos recibidos." << endl;
                else
                    recibidos.mostrar();
                break;

            case 0:
                cout << "Saliendo" << endl;
                break;

            default:
                cout << "Opción no válida." << endl;
        }

    } while (option != 0);
    return 0;
}*/


int main() {
    cout << "Hola mundo" << endl;
    cin.get();
    return 0;
}
