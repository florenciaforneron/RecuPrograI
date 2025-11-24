#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iomanip>
#include <iostream>

using namespace std;

struct LoteMarcas
{
    int codMarca;
    string nombre;
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
    float totalRecaudado;
    int cantidadVendida;
};

struct LoteFormasPago
{
    string codPago;
    string nombre;
    int porcentaje;
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

void cargarLoteMarcas(LoteMarcas marcas[]);
void cargarLoteProductos(LoteProductos productos[], LoteMarcas marcas[]);
void cargarLoteFP(LoteFormasPago formasPago[]);
void cargarLoteVentas(LoteProductos productos[], LoteFormasPago formasPago[]);
void mostrarMenuReportes(LoteProductos productos[]);


#endif // FUNCIONES_H_INCLUDED
