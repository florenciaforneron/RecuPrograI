#include "funciones.h"

void cargarLoteMarcas(LoteMarcas marcas[]){

    cout << "Menu carga de lote de Marcas"<<endl;
    cout << "-------------------------------"<<endl;
    for(int x=0; x<10; x++){
                cout << "Codigo (1 a 10): ";
                cout << "Ingrese el numero de articulo: ";
                cin >> marcas[x].codMarca;
                cout << "Ingrese nombre de marca: ";
                cin >> marcas[x].nombre;
    }

/*
    for(int x=0; x<10; x++){

        cout << "--- Ingrese datos del producto nro. " << x+1 << " ---" << endl;

        bool entradaValida;
        entradaValida = false;
        int codMarca = marcas[x].codMarca;
        while (!entradaValida) {
                if (cin >> codMarca) {
                if (codMarca >= 1 && codMarca <= 10) {
                    entradaValida = true;
                } else {
                    cout << "Error: El codigo debe ser un numero entero entre 1 y 10." << endl;
                }
            } else {
                cout << "Error: Debe ingresar un numero entero valido." << endl;
            }


        }
        entradaValida = false;
        string nombreMarca = marcas[x].nombre;
        while (!entradaValida) {
            //cout << "Nombre: ";
            //getline(cin, nombreMarca);
            if (cin >> nombreMarca) {
                if (nombreMarca.length() > 0) {
                    entradaValida = true;
                } else {
                    cout << "Error: El nombre no debe estar vacio. Intente de nuevo." << endl;
                }
            }else {
                    cout << "Error: Debe ingresar un nombre entero valido." << endl;
            }
        }
    }
*/
    cout << "-------------Finalizo lote de carga de marcas---------" << endl;

};
