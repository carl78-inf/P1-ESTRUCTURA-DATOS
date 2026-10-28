#include "pizzeria.h"

//Constructor
pizzeria::pizzeria() {
    pedidos_fuera = 0;
    for(int i = 0; i < ZONAS; i++) {
        cajas_enviadas[i] = 0;
    }
}

//Destructor
pizzeria::~pizzeria() {}

//Comprueba si un id existe ya en pedidos
bool pizzeria::idYaEnPedidos(string id) {
    bool yaEnPedidos = false; //Booleano para determinar si el id está ya en pedidos
    Cola aux;                 //Cola auxiliar para no perder los datos

    //Mientras no esté en pedidos y la cola no esté vacía
    while(!yaEnPedidos && !pedidos.es_vacia()) {
        //Si el ID del primer pedido es igual a id, yaEnPedidos = True
        if(pedidos.inicio().id_pedido == id) {
            yaEnPedidos = true;
        }

        //Añadimos a la cola auxiliar y desencolamos de pedidos
        aux.encolar(pedidos.inicio());
        pedidos.desencolar();
    }

    //Restauramos la cola de pedidos
    while(!aux.es_vacia()) {
        pedidos.encolar(aux.inicio());
        aux.desencolar();
    }

    return yaEnPedidos;
}

//Generar N pedidos aleatoriamente
void pizzeria::generarPedidos(int numero) {
    string id; //ID del pedido
    for(int i = 0; i < numero; i++) {
        do {
            id = generarIDRandom(); //Generamos un ID aleatorio
        } while(idYaEnPedidos(id)); //Repetimos si el ID ya existe en pedidos

        //Generamos un pedido aleatorio con ese id y lo añadimos a la cola de pedidos
        Pedido p = generarPedidoRandom(id);
        pedidos.encolar(p);
    }
}

//Ejecutar un paso de la simulación
void pizzeria::ejecutarPasoEjecucion() {
    Pedido p;     //Pedido que se va a manejar
    int contador; //Contador de pasos

    //Fase Expedicion -> Caja
    for(int z = 0; z < ZONAS; z++) {
        contador = 0;
        while(!expedicion[z].es_vacia() && contador < N_PEDIDOS_PASO) {
            p = expedicion[z].inicio();         //Obtenemos el primer pedido de la cola
            p.estado = "Caja";                  //Establecemos el estado a "Caja"
            caja[z].apilar(p);                  //Introducimos el pedido en la caja correspondiente
            expedicion[z].desencolar();         //Y lo eliminamos de la cola de expedicion
            contador++;

            //Si una caja se llena, se envia a reparto y se empieza otra nueva vacia
            if(caja[z].get_longitud() == CAP_CAJA) {
                cajas_enviadas[z]++;            //Aumentamos el contador de cajas enviadas
                pedidos_fuera += CAP_CAJA;      //Aumentamos el contador de pedidos fuera

                //Vaciamos la caja y añadimos los pedidos a la cola de finalizados
                while(!caja[z].es_vacia()) {
                    p = caja[z].cima_pila();    //Obtenemos el primer pedido de la pila
                    p.estado = "Enviado";       //Establecemos el estado a "Enviado"
                    finalizados.encolar(p);     //Introducimos el pedido en la cola de finalizados
                    caja[z].desapilar();        //Y lo eliminamos de la caja
                }
            }
        }
    }

    //Fase Cocina -> Expedición
    contador = 0;
    while(!cocina.es_vacia() && contador < N_PEDIDOS_PASO) {
        p = cocina.inicio();                    //Obtenemos el primer pedido de la cola
        p.estado = "Expedicion";                //Establecemos el estado a "Expedicion"
        //Introducimos el pedido en la cola de expedición correspondiente
        switch(p.zona_reparto) {
            case NORTE:
                expedicion[0].encolar(p);
                break;
            case SUR:
                expedicion[1].encolar(p);
                break;
            case ESTE:
                expedicion[2].encolar(p);
                break;
            case OESTE:
                expedicion[3].encolar(p);
                break;
        }
        cocina.desencolar();                    //Y lo eliminamos de la cola de cocina
        contador++;
    }

    //Fase Preparación Especial -> Cocina
    contador = 0;
    while(!preparacion_especial.es_vacia() && contador < N_PEDIDOS_PASO) {
        p = preparacion_especial.inicio();      //Obtenemos el primer pedido de la cola
        p.estado = "Cocina";                    //Establecemos el estado a "Cocina"
        cocina.encolar(p);                      //Introducimos el pedido en la cola de cocina
        preparacion_especial.desencolar();      //Y lo eliminamos de la cola de preparación especial
        contador++;
    }

    //Fase Pedidos -> Cocina / Preparación Especial
    contador = 0;
    while(!pedidos.es_vacia() && contador < N_PEDIDOS_PASO) {
        p = pedidos.inicio();                   //Obtenemos el primer pedido de la cola
        //Si personalizada = True
        if(p.personalizada) {
            p.estado = "Preparacion especial";  //Establecemos el estado a "Preparacion especial"
            preparacion_especial.encolar(p);    //Introducimos el pedido en la cola de preparación especial
        }
        //Si personalizada = False
        else {
            p.estado = "Cocina";                //Establecemos el estado a "Cocina"
            cocina.encolar(p);                  //Introducimos el pedido en la cola de cocina
        }
        pedidos.desencolar();                   //Y lo eliminamos de la cola de pedidos
        contador++;
    }
}

//Obtener el nombre de la zona a partir de su indice (0=Norte, 1=Sur, 2=Este, 3=Oeste)
string nombreZona(int i) {
    string nombre;
    switch(i) {
        case 0:
            nombre = "Norte";
            break;
        case 1:
            nombre = "Sur";
            break;
        case 2:
            nombre = "Este";
            break;
        case 3:
            nombre = "Oeste";
            break;
        default:
            nombre = "NULL";
    }
    return nombre;
}

//Mostrar el estado del sistema
void pizzeria::mostrar() {
    cout << "\n//////////////////////////////////////////////PEDIDOS///////////////////////////////////////////////" << endl;
    pedidos.mostrar();

    cout << "\n\n///////////////////////////////////////PREPARACION ESPECIAL////////////////////////////////////////" << endl;
    preparacion_especial.mostrar();

    cout << "\n\n//////////////////////////////////////////////COCINA///////////////////////////////////////////////" << endl;
    cocina.mostrar();

    cout << "\n\n////////////////////////////////////////////EXPEDICION/////////////////////////////////////////////" << endl;
    cout << "\n                                               NORTE" << endl;
    expedicion[0].mostrar();
    cout << "\n                                                SUR" << endl;
    expedicion[1].mostrar();
    cout << "\n                                               ESTE" << endl;
    expedicion[2].mostrar();
    cout << "\n                                               OESTE" << endl;
    expedicion[3].mostrar();

    cout << "\n\n--- CAJAS TERMICAS ---" << endl;
    int total_enviadas = 0;
    for(int z = 0; z < ZONAS; z++) {
        cout << "Zona " << nombreZona(z) << " -> activa: "
             << caja[z].get_longitud() << "/" << CAP_CAJA
             << "  enviadas: " << cajas_enviadas[z] << endl;
        total_enviadas += cajas_enviadas[z];
    }
    cout << endl
         << "Total de cajas enviadas: " << total_enviadas << endl
         << "Pedidos enviados o retirados: " << pedidos_fuera << endl;
}

//Obtiene la ocupación de una caja por su índice de zona (0=Norte, 1=Sur, 2=Este, 3=Oeste)
int pizzeria::ocupacionCaja(int zona) {
    return caja[zona - 1].get_longitud();
}

//Muestra la caja activa de una zona
void pizzeria::verCajaActiva(int zona) {
    caja[zona - 1].mostrar();
}

//Retira un pedido de una caja activa por su identificador
void pizzeria::retirarPedido(int zona, string id) {
    Pedido p = caja[zona - 1].buscar(id); //Obtiene el pedido con ese ID o uno por defecto si no existe

    //Al eliminar, si el pedido está en la caja
    if(caja[zona - 1].eliminar(id)) {
        pedidos_fuera++;        //Aumentamos el contador de pedidos fuera
        p.estado = "Retirado";  //Establecemos el estado del pedido a "Retirado"
        finalizados.encolar(p); //Y lo añadimos a la cola de finalizados
        cout << "Pedido " << id << " retirado de la caja de la zona " << nombreZona(zona - 1) << "." << endl;
    }

    //Si no existe en la caja
    else {
        cout << "El pedido " << id << " no esta en la caja activa de la zona " << nombreZona(zona - 1) << "." << endl;
    }
}

//Muestra los pedidos finalizados (enviados y retirados)
void pizzeria::mostrarFinalizados() {
    cout << "\n////////////////////////////////////////////FINALIZADOS////////////////////////////////////////////" << endl;
    finalizados.mostrar();
}
