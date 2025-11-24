#include "funciones.h"

int main()
{

    const int TAM_VEC_MARCAS = 10;
    LoteMarcas marcas[TAM_VEC_MARCAS];
    bool seguirProceso = true;
    while(seguirProceso) {
        int opcionElegida;
        cout << "Menu - Elija una opcion" << endl;
        cout << "------------------------------------" << endl;
        cout << "1. Cargar lote de marcas" << endl;
        cout << "2. Cargar lote de productos" << endl;
        cout << "3. Cargar lote de formas de pago" << endl;
        cout << "4. Cargar lote de ventas" << endl;
        cout << "5. Mostrar reportes" << endl;
        cout << "6. Salir"<< endl;
        cin >> opcionElegida;
        switch(opcionElegida){
            case 1:
                system("cls");
                cargarLoteMarcas(marcas);
                break;
            case 2:
                system("cls");
                cout << "Proximamente..." << endl;
                break;
            case 3:
                system("cls");
                cout << "Proximamente..." << endl;
                break;
            case 4:
                system("cls");
               cout << "Proximamente..." << endl;
                break;
            case 5:
                system("cls");
                cout << "Proximamente..." << endl;
                break;
            case 6:
                cout << "Proceso finalizado exitosamente" << endl;
                seguirProceso = false;
                break;
            default:
                system("cls");
                cout << "Opcion incorrecta" << endl;
                break;
        }
    }
    return 0;
}
