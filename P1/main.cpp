#include <iostream>

#include <pizzeria.h>

using namespace std;

int main()
{
    srand(time(NULL)); //Una vez en todo el programa para que funcione rand()

    pizzeria p; //Objeto pizzeria que incluye todos los atributos y métodos de nuestra simulación
    int option; //Opción elegida
    int n;      //Entero para la opción de Generar N pedidos
    string id;  //Identificador de un pedido para la opción de Retirar un pedido de una caja activa

    do
    {
        cout << endl;
        cout << "+--------------------------------------------------+" << endl;
        cout << "|          SIMULACION DE UNA PIZZERIA              |" << endl;
        cout << "|               Sistema de pedidos                 |" << endl;
        cout << "+--------------------------------------------------+" << endl;
        cout << "|  1. Generar N pedidos                            |" << endl;
        cout << "|  2. Ejecutar un paso de simulacion               |" << endl;
        cout << "|  3. Mostrar el estado del sistema                |" << endl;
        cout << "|  4. Ver la caja activa de una zona               |" << endl;
        cout << "|  5. Retirar un pedido de una caja activa         |" << endl;
        cout << "|  6. Mostrar pedidos finalizados                  |" << endl;
        cout << "|  0. Salir                                        |" << endl;
        cout << "+--------------------------------------------------+" << endl;
        cout << "Seleccion > ";

        cin >> option;

        switch (option)
        {

        //Generar N pedidos
        case 1:
            cout << "Introduce el numero de pedidos a generar: ";
            cin >> n;
            if (n > 0)
            {
                p.Generar_pedidos(n);
                cout << n << " pedidos generados." << endl;
            }
            else
            {
                cout << "El numero debe ser mayor que 0" << endl;
            }
            break;

        //Ejecutar un paso de la simulación
        case 2:
            p.Dar_paso_simulacion();
            break;

        //Mostrar estado del sistema
        case 3:
            p.Mostrar_estado_sistema();
            break;

        //Ver caja activa de la zona
        case 4:
            p.Ver_contenido_caja();
            break;

        //Retirar un pedido de una caja activa
        case 5:
            p.Retirar_pedido_caja();
            break;

        //Mostrar pedidos finalizados
        case 6:
            p.Mostrar_finalizados();
            break;

        //Salir
        case 0:
            cout << "Saliendo" << endl;
            break;

        //Caso base para opción no válida
        default:
            cout << "Opcion no valida." << endl;
        }

    }
    while (option != 0);

    return 0;
}
