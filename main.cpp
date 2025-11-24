#include "funciones.h"

int main()
{

    const int TAM_VEC_MARCAS = 10;
    LoteMarcas marcas[TAM_VEC_MARCAS];

    const int TAMANIO_VEC_PRODUCTOS = 20;
    LoteProductos productos[TAMANIO_VEC_PRODUCTOS];

    const int TAMANIO_VEC_FORMASPAGO = 5;
    LoteFormasPago formasPago[TAMANIO_VEC_FORMASPAGO];

    int opcionElegida;
    do
    {
        cout << "Menu - Elija una opcion" << endl;
        cout << "------------------------------------" << endl;

        cout << "1. Cargar lote de marcas" << endl;
        cout << "2. Cargar lote de productos" << endl;
        cout << "3. Cargar lote de formas de pago" << endl;
        cout << "4. Cargar lote de ventas" << endl;
        cout << "5. Mostrar reportes" << endl;
        cout << "0. Salir"<< endl;
        cin >> opcionElegida;
        switch(opcionElegida)
        {
        case 1:
            system("cls");
            cargarLoteMarcas(marcas);
            break;
        case 2:
            system("cls");
            cargarLoteProductos(productos, marcas);
            break;
        case 3:
            system("cls");
            cargarLoteFP(formasPago);
            break;
        case 4:
            system("cls");
            cargarLoteVentas(productos, formasPago);
            break;
        case 5:
            system("cls");
            mostrarMenuReportes(productos);
            break;
        case 0:
            cout << "Proceso finalizado exitosamente" << endl;
            break;
        default:
            system("cls");
            cout << "Opcion incorrecta" << endl;
            break;
        }
    }
    while(opcionElegida != 0);
    return 0;
}
