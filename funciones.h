#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>

using namespace std;

struct LoteMarcas{
    int codMarca;
    string nombre;

};

struct LoteProductos{
    string codProducto;
    float precioVenta;
    float precioCompra;
    int stockDispo;
    LoteMarcas marca;
};

struct LoteFormasPago{
    string CodPago;
    string nombrePago;
    int porcentaje;
};

struct LoteDeVentas{
    int nroDeCompra;
    LoteProductos loteProductos;
    LoteFormasPago lotePago;
    int cantidadVendida;
    int codCliente;
    int diaVenta;
};

void cargarLoteMarcas(LoteMarcas marcas[]);


#endif // FUNCIONES_H_INCLUDED
