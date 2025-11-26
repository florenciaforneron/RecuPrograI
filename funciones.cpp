#include "funciones.h"

// Funciones auxiliares
bool vectorMarcaLleno(LoteMarcas marcas[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(marcas[i].codMarca==0) return false;
    }
    return true;
}

bool esConsecutivo(int num)
{
    string numString = to_string(num);
    for(int i = 1; i < numString.length(); i++)
    {
        int numAnt = (int)numString[i-1];
        int numAct = (int)numString[i];
        if(numAct != numAnt+1)
        {
            return false;
        }
    }
    return true;
}
// busca la marca y si encuentra, por referencia asigna el indice
bool existeMarca(LoteMarcas marcas[], int tam, int valor, int &indice)
{
    for(int i = 0; i < tam; i++)
    {
        if(marcas[i].codMarca == valor)
        {
            indice = i;
            return true;
        }
    }
    return false;
}

// busca la forma de pago y si encuentra, por referencia asigna el indice
bool existeFP(LoteFormasPago fp[], int tam, string valor, int &indice)
{
    for(int i = 0; i < tam; i++)
    {
        if(fp[i].codPago == valor)
        {
            indice = i;
            return true;
        }
    }
    return false;
}
// busca el producto y si encuentra, por referencia asigna el indice
bool existeProducto(LoteProductos productos[], int tam, int valor, int &indice)
{
    for(int i = 0; i < tam; i++)
    {
        if(productos[i].codProducto == valor)
        {
            indice = i;
            return true;
        }
    }
    return false;
}

float calcularPorcentaje(float num, int porcentaje)
{
    // cout << "Calculando porcentaje (" << num <<","<<porcentaje<<")"<< endl;
    float total = num * ((float)porcentaje/100+1);
    // cout << "Total porcentaje: " << total << endl;
    return total;
}

// reportes
void vaciarReportes(LoteProductos productos[], LoteFormasPago formasPago[], LoteMarcas marcas[], Cliente clientes[])
{
    for(int i = 0; i<20; i++)
    {
        productos[i].cantidadVendida = 0;
        productos[i].totalRecaudado = 0;
        productos[i].stockRestante = productos[i].stockDispo;
    }
    for(int i = 0; i < 5; i++)
    {
        formasPago[i].cantidadVendida = 0;
    }
    for(int i=0; i < 10; i++)
    {
        marcas[i].cantEF = 0;
        marcas[i].cantMP = 0;
        marcas[i].cantTR = 0;
        marcas[i].cantTC = 0;
        marcas[i].cantCT = 0;
    }
    for(int i = 0; i < 50; i++)
    {
        clientes[i].codCliente = i+1;
        clientes[i].cantidadCompras = 0;
    }
}
int generarNumeroRandom(int desde, int hasta)
{
    return rand() % hasta + desde;
}

// Carga de lotes
void cargarLoteMarcas(LoteMarcas marcas[])
{
    cout << "Menu carga de lote de Marcas"<<endl;
    cout << "------------------------------------"<<endl;

    for(int i = 0; i<10; i++)
    {
        int codMarca = 0;
        string nombreMarca;
        bool entradaValida;

        cout << "--- Ingrese datos del producto nro. " << i+1 << " ---" << endl;

        entradaValida = false;
        while (!entradaValida)
        {
            cout << "Codigo (1 a 10): ";
            cin >> codMarca;
            if( codMarca < 1 || codMarca > 10)
            {
                cout << "Error: El codigo debe ser un numero entero entre 1 y 10." << endl;
                continue;
            }
            entradaValida = true;
        }
        entradaValida = false;
        while (!entradaValida)
        {
            cout << "Nombre: ";
            cin >> nombreMarca;
            if (nombreMarca.length() == 0)
            {
                cout << "Error: El nombre no debe estar vacio. Intente de nuevo." << endl;
                continue;
            }
            entradaValida = true;
        }
        cout << "------------------------------------"<<endl;
        marcas[i].codMarca = codMarca;
        marcas[i].nombre = nombreMarca;

        // reporte 3
        marcas[i].cantEF = 0;
        marcas[i].cantMP = 0;
        marcas[i].cantTR = 0;
        marcas[i].cantTC = 0;
        marcas[i].cantCT = 0;
    }
    system("cls");
    cout << "------------------------------------"<<endl;
    cout << "Carga del Lote de Marcas finalizada." << endl;
    cout << "------------------------------------"<<endl;
}

void cargarLoteProductos(LoteProductos productos[], LoteMarcas marcas[])
{
    if(!vectorMarcaLleno(marcas, 10))
    {
        system("cls");
        cout << "Es necesario cargar el lote de marcas para usar este menu" << endl;
        return;
    }
    cout << "Menu carga de lote de Productos"<<endl;
    cout << "------------------------------------"<<endl;
    for(int i = 0; i<20; i++)
    {
        int cod, stock, codMarca;
        float precioVenta, precioCompra;
        string nombre;
        cout << "Ingrese datos del producto nro. " << i+1 <<endl;
        cout << "Codigo: ";
        cin >> cod;
        if(cod == 0)
        {
            system("cls");
            cout << "El codigo no debe estar vacio" << endl;
            return;
        }
        if(cod < 100 || cod > 999)
        {
            system("cls");
            cout << "El codigo debe tener 3 digitos" << endl;
            return;
        }
        if(esConsecutivo(cod))
        {
            system("cls");
            cout << "El codigo no debe ser consecutivo" << endl;
            return;
        }

        cout << "Nombre: ";
        cin >> nombre;
        if(nombre.length() == 0)
        {
            system("cls");
            cout << "El nombre no debe estar vacio" << endl;
            return;
        }

        cout << "Precio venta: ";
        cin >> precioVenta;
        if(precioVenta == 0)
        {
            system("cls");
            cout << "El precio de venta no debe estar vacio" << endl;
            return;
        }

        cout << "Precio compra: ";
        cin >> precioCompra;
        if(precioCompra == 0)
        {
            system("cls");
            cout << "El precio de compra no debe estar vacio" << endl;
            return;
        }

        cout << "Stock disponible: ";
        cin >> stock;
        if(stock == 0)
        {
            system("cls");
            cout << "El stock no debe estar vacio" << endl;
            return;
        }

        cout << "Codigo de Marca: ";
        cin >> codMarca;
        if(codMarca == 0)
        {
            system("cls");
            cout << "El codigo de marca no debe estar vacio" << endl;
            return;
        }
        int indiceMarca;
        if(!existeMarca(marcas, 10, codMarca, indiceMarca))
        {
            system("cls");
            cout << "El codigo ingresado no existe" << endl;
            return;
        }
        cout << "------------------------------------"<<endl;

        productos[i].codProducto = cod;
        productos[i].nombre = nombre;
        productos[i].precioVenta = precioVenta;
        productos[i].precioCompra = precioCompra;
        productos[i].stockDispo = stock;
        productos[i].marca = marcas[indiceMarca];

        // reporte 1
        productos[i].cantidadVendida = 0;
        productos[i].totalRecaudado = 0;
    }
    system("cls");
    cout << "------------------------------------"<<endl;
    cout << "Carga del Lote de Productos finalizada." << endl;
    cout << "------------------------------------"<<endl;
}

void cargarLoteFP(LoteFormasPago formasPago[])
{
    cout << "Menu carga de lote de Formas de Pago"<<endl;
    cout << "------------------------------------"<<endl;

    for(int i = 0; i < 5; i++)
    {
        string codFP, nomFP;
        int porcFP;
        bool entradaValida;

        cout << "--- Ingrese datos de la Forma de Pago nro. " << i + 1 << " ---" << endl;

        entradaValida = false;
        while (!entradaValida)
        {
            cout << "Codigo (EF, MP, TR, TC, CT): ";
            cin >> codFP;
            if (codFP != "EF" && codFP != "MP" && codFP != "TR" && codFP != "TC" && codFP != "CT")
            {
                cout << "Error: El codigo debe ser uno de los permitidos (EF, MP, TR, TC, CT)." << endl;
                continue;
            }
            int _;
            if(existeFP(formasPago, 5, codFP, _))
            {
                cout << "Error: El codigo '" << codFP << "' ya fue ingresado. Intente con otro." << endl;
                continue;
            }
            entradaValida = true;
        }

        entradaValida = false;
        while (!entradaValida)
        {
            cout << "Nombre: ";
            cin >> nomFP;

            if (nomFP.length() == 0)
            {
                cout << "Error: El nombre no debe estar vacio." << endl;
                continue;
            }
            entradaValida = true;
        }

        cout << "Porcentaje (interes + / descuento -): ";
        cin >> porcFP;


        formasPago[i].codPago = codFP;
        formasPago[i].nombre = nomFP;
        formasPago[i].porcentaje = porcFP;
        // reporte 2
        formasPago[i].cantidadVendida = 0;
        cout << "------------------------------------"<<endl;
    }
    system("cls");
    cout << "------------------------------------"<<endl;
    cout << "Carga del Lote de Formas de Pago finalizada." << endl;
    cout << "------------------------------------"<<endl;
}

void cargarLoteVentas(LoteProductos productos[], LoteFormasPago formasPago[], LoteMarcas marcas[], Cliente clientes[])
{
    cout << "Menu carga y procesamiento de Lote de Ventas"<<endl;
    cout << "------------------------------------"<<endl;
    // se vacian reportes anteriores en caso de que existan
    vaciarReportes(productos, formasPago, marcas, clientes);
    LoteVentas ventaActual;
    cout << "Ingrese Nro de Compra (0 para finalizar): ";
    cin >> ventaActual.nroDeCompra;
    while(ventaActual.nroDeCompra != 0)
    {
        int codProd;
        int indiceProducto, indiceMarca, indiceFP;

        string codFP;

        bool entradaValida = false;
        while (!entradaValida)
        {
            cout << "Codigo de producto:";
            cin >> codProd;
            if(!existeProducto(productos, 20, codProd, indiceProducto))
            {
                cout << "Error: El producto no existe." << endl;
                continue;
            }
            ventaActual.producto = productos[indiceProducto];
            entradaValida = true;
        }

        entradaValida = false;
        while (!entradaValida)
        {
            cout << "Forma de pago:";
            cin >> codFP;
            if(!existeFP(formasPago, 5, codFP, indiceFP))
            {
                cout << "Error: la forma de pago no existe." << endl;
                continue;
            }
            ventaActual.formaPago = formasPago[indiceFP];
            entradaValida = true;
        }

        entradaValida = false;
        while (!entradaValida)
        {
            cout << "Cantidad vendida:";
            cin >> ventaActual.cantidadVendida;
            if(ventaActual.cantidadVendida == 0)
            {
                cout << "Error: La cantidad vendida debe ser mayor a 0." << endl;
                continue;
            }
            entradaValida = true;
        }

        entradaValida = false;
        while (!entradaValida)
        {
            cout << "Codigo de cliente:";
            cin >> ventaActual.codCliente;
            if(ventaActual.codCliente < 1 || ventaActual.codCliente > 50)
            {
                cout << "Error: El codigo de cliente debe ser entre 1 y 50." << endl;
                continue;
            }
            entradaValida = true;
        }

        entradaValida = false;
        while (!entradaValida)
        {
            cout << "Dia de venta:";
            cin >> ventaActual.diaVenta;
            if(ventaActual.diaVenta < 1 || ventaActual.diaVenta > 30)
            {
                cout << "Error: El dia de venta debe ser entre 1 y 30." << endl;
                continue;
            }
            entradaValida = true;
        }
        // calculo totales
        float subtotal = ventaActual.producto.precioVenta * ventaActual.cantidadVendida;
        // cout << "SUBTOTAL: " << subtotal << endl;
        // cout << "FP: " << ventaActual.formaPago.nombre << " - " << ventaActual.formaPago.porcentaje << endl;
        float total = calcularPorcentaje(subtotal, ventaActual.formaPago.porcentaje);
        // cout << "TOTAL: " << total << endl;

        // reporte 1
        productos[indiceProducto].stockRestante -= ventaActual.cantidadVendida;
        productos[indiceProducto].cantidadVendida += ventaActual.cantidadVendida;
        productos[indiceProducto].totalRecaudado += + total;

        // reporte 2
        formasPago[indiceFP].cantidadVendida += ventaActual.cantidadVendida;
        cout << "Ingrese Nro de Compra (0 para finalizar): ";
        cin >> ventaActual.nroDeCompra;

        // reporte3
        // obtengo el indice de la marca de la venta actual
        existeMarca(marcas, 10, ventaActual.producto.marca.codMarca, indiceMarca);
        if(ventaActual.formaPago.codPago == "EF")
        {
            marcas[indiceMarca].cantEF += ventaActual.cantidadVendida;
        }
        else if(ventaActual.formaPago.codPago == "MP")
        {
            marcas[indiceMarca].cantMP += ventaActual.cantidadVendida;
        }
        else if(ventaActual.formaPago.codPago == "TR")
        {
            marcas[indiceMarca].cantTR += ventaActual.cantidadVendida;
        }
        else if(ventaActual.formaPago.codPago == "TC")
        {
            marcas[indiceMarca].cantTC += ventaActual.cantidadVendida;
        }
        else
        {
            marcas[indiceMarca].cantCT += ventaActual.cantidadVendida;
        };

        // reporte 5
        clientes[ventaActual.codCliente - 1].cantidadCompras += ventaActual.cantidadVendida;
    }
    system("cls");
    cout << "------------------------------------"<<endl;
    cout << "Carga del Lote de Ventas finalizada." << endl;
    cout << "------------------------------------"<<endl;
}

// Menu reportes

void mostrarReporte1(LoteProductos productos[])
{
    cout << "========================================================================" << endl;
    cout << "|| REPORTE 1: RECAUDACION POR PRODUCTO (Ordenado por Cantidad Vendida) ||" << endl;
    cout << "========================================================================" << endl;

    cout << "CODIGO DE PRODUCTO | NOMBRE DEL PRODUCTO | CANTIDAD VENDIDA | TOTAL RECAUDADO | STOCK REMANENTE |" << endl;
    cout << "------------------------------------------------------------------------------------------------|" << endl;

    // ordenando productos por cantidad de ventas  de mayor a menor con método búrbuja
    for(int j = 0 ; j < 20; j++)
    {
        for(int i = 0; i < 19; i++)
        {
            if(productos[i].cantidadVendida < productos[i + 1].cantidadVendida)
            {
                LoteProductos aux = productos[i + 1];
                productos[i + 1] =  productos[i];
                productos[i] = aux;
            }
        }
    }
    // salida
    for(int i = 0; i<20; i++)
    {
        cout << setw(19) << left << productos[i].codProducto << "|";
        cout << " " << setw(20) << left << productos[i].nombre << "|";
        cout << " " << setw(17) << left << productos[i].cantidadVendida << "|";
        cout << " " << setw(16) << left << productos[i].totalRecaudado << "|";
        cout << " " << setw(16) << left << productos[i].stockRestante << "|";
        cout << endl;
    }
}

void mostrarReporte2(LoteFormasPago formasPago[])
{
    cout << "=======================================================" << endl;
    cout << "|| REPORTE 2: PORCENTAJE DE VENTAS POR FORMA DE PAGO ||" << endl;
    cout << "=======================================================" << endl;

    cout << "FORMA DE PAGO      | PORCENTAJE DE VENTAS |" << endl;
    cout << "------------------------------------------|" << endl;
    // calculando totales
    int totalVendido = 0;
    for (int i = 0; i < 5; i++)
    {
        totalVendido += formasPago[i].cantidadVendida;
    }
    // salida
    for(int i = 0; i < 5; i++)
    {
        cout << setw(19) << left << formasPago[i].nombre << "|";
        cout << " " << setw(21) << left << ((double)formasPago[i].cantidadVendida / (double) totalVendido)*100  << "|";
        cout << endl;
    }
}

void mostrarReporte3(LoteMarcas marcas[])
{
    cout << "=================================================" << endl;
    cout << "|| REPORTE 3: VENTAS POR MARCA Y FORMA DE PAGO ||" << endl;
    cout << "=================================================" << endl;

    cout << "MARCA           | EF | MP | TR | TC | CT |" << endl;
    cout << "-----------------------------------------|" << endl;

    // carga de datos
    for(int i = 0; i < 10; i++)
    {
        cout << setw(16) << left << marcas[i].nombre << "|";
        cout << " " << setw(3) << left << marcas[i].cantEF  << "|";
        cout << " " << setw(3) << left << marcas[i].cantMP  << "|";
        cout << " " << setw(3) << left << marcas[i].cantTR  << "|";
        cout << " " << setw(3) << left << marcas[i].cantTC  << "|";
        cout << " " << setw(3) << left << marcas[i].cantCT  << "|";
        cout << endl;
    }

}


void mostrarReporte4(LoteProductos productos[])
{
    cout << "=====================================" << endl;
    cout << "|| REPORTE 4: PRODUCTOS SIN VENTAS ||" << endl;
    cout << "=====================================" << endl;

    cout << "CODIGO DE PRODUCTO | NOMBRE DEL PRODUCTO |" << endl;
    cout << "-----------------------------------------|" << endl;

    // salida
    for(int i = 0; i<20; i++)
    {
        if(productos[i].cantidadVendida > 0) continue;
        cout << setw(19) << left << productos[i].codProducto << "|";
        cout << " " << setw(20) << left << productos[i].nombre << "|";
        cout << endl;
    }
}

void mostrarReporte5(Cliente clientes[])
{
    cout << "====================================================" << endl;
    cout << "|| REPORTE 5: TOP 10 CLIENTES + SORTEO DE CUPONES ||" << endl;
    cout << "====================================================" << endl;

    cout << "TOP | CODIGO DE CLIENTE | CANTIDAD DE COMPRAS |" << endl;
    cout << "----------------------------------------------|" << endl;

    // ordenando clientes por cantidad de compras de mayor a menor con método búrbuja
    for(int j = 0 ; j < 50; j++)
    {
        for(int i = 0; i < 49; i++)
        {
            if(clientes[i].cantidadCompras < clientes[i + 1].cantidadCompras)
            {
                Cliente aux = clientes[i + 1];
                clientes[i + 1] =  clientes[i];
                clientes[i] = aux;
            }
        }
    }

    // salida
    for(int i = 0; i<10; i++)
    {
        cout << setw(4) << left << i + 1 << "|";
        cout << " " << setw(18) << left << clientes[i].codCliente << "|";
        cout << " " << setw(20) << left << clientes[i].cantidadCompras << "|";
        cout << endl;
    }

    cout << "=================================================" << endl;
    cout << "|| GANADORES DEL SORTEO DE CUPONES DE DESCUENTO||" << endl;
    cout << "=================================================" << endl;

    cout << "CODIGO DE CLIENTE | CANTIDAD DE COMPRAS | CUPON       |" << endl;
    cout << "------------------------------------------------------|" << endl;


    // numeros random
    int indicesRandom[3]= {};
    for(int i = 0; i < 3; i++)
    {
        int indiceRandom = generarNumeroRandom(1, 10);
        // chequeo si el indice generado ya existe en el vector
        bool yaExiste = false;
        for(int j = 0; j < 3; j++)
        {
            if(indicesRandom[j] == indiceRandom)
            {
                yaExiste = true;
                break;
            }
        }
        if(yaExiste)
        {
            i--;
            continue;
        }
        indicesRandom[i] = indiceRandom;
        cout << setw(18) << left << clientes[indiceRandom-1].codCliente << "|";
        cout << " " << setw(20) << left << clientes[indiceRandom-1].cantidadCompras << "|";
        cout << " COMPRA20OFF |";
        cout << endl;
    }
}

void mostrarMenuReportes(LoteProductos productos[], LoteFormasPago formasPago[], LoteMarcas marcas[], Cliente clientes[])
{
    int opcionElegida;
    do
    {
        cout << "Menu repotes - Elija una opcion"<<endl;
        cout << "------------------------------------"<<endl;
        cout << "1. Recaudacion por producto" << endl;
        cout << "2. Porcentaje de ventas por forma de pago" << endl;
        cout << "3. Ventas por marca y forma de pago" << endl;
        cout << "4. Productos sin ventas" << endl;
        cout << "5. Top 10 clientes + sorteo de cupones" << endl;
        cout << "0. Volver al menu principal"<< endl;
        cin >> opcionElegida;
        switch(opcionElegida)
        {
        case 1:
            system("cls");
            mostrarReporte1(productos);
            break;
        case 2:
            system("cls");
            mostrarReporte2(formasPago);
            break;
        case 3:
            system("cls");
            mostrarReporte3(marcas);
            break;
        case 4:
            system("cls");
            mostrarReporte4(productos);
            break;
        case 5:
            system("cls");
            mostrarReporte5(clientes);
            break;
        case 6:
            system("cls");
            break;
        default:
            system("cls");
            cout << "Opcion incorrecta" << endl;
            break;
        }
        if(opcionElegida != 0)
        {
            cout << "Presione ENTER para volver al menu de reportes...";
            cin.ignore();
            cin.get();
        }
        system("cls");
    }
    while(opcionElegida != 0);
}
