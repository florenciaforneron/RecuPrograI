#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct LoteMarcas
{
    int codMarca;
    string nombre;

    // reporte 3
    int cantEF;
    int cantMP;
    int cantTR;
    int cantTC;
    int cantCT;
};

struct LoteProductos
{
    int codProducto;
    string nombre;
    float precioVenta;
    float precioCompra;
    int stockDispo;
    LoteMarcas marca;

    // informe1
    int cantidadVendida;
    float totalRecaudado;
    int stockRestante;
};

struct LoteFormasPago
{
    string codPago;
    string nombre;
    int porcentaje;

    // informe2
    int cantidadVendida;
};

struct LoteVentas
{
    int nroDeCompra;
    LoteProductos producto;
    LoteFormasPago formaPago;
    int cantidadVendida;
    int codCliente;
    int diaVenta;
};

//informe5
struct Cliente
{
    int codCliente;
    int cantidadCompras;
};

void cargarLoteMarcas(LoteMarcas marcas[]);
void cargarLoteProductos(LoteProductos productos[], LoteMarcas marcas[]);
void cargarLoteFP(LoteFormasPago formasPago[]);
void cargarLoteVentas(LoteProductos productos[], LoteFormasPago formasPago[], LoteMarcas marcas[], Cliente clientes[]);
void mostrarMenuReportes(LoteProductos productos[], LoteFormasPago formasPago[], LoteMarcas marcas[], Cliente clientes[]);


#endif // FUNCIONES_H_INCLUDED
