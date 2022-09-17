#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;

class Producto
{
private:
    int Clave;
    char origen[64];
    char destino[64];
    double peso;
public:
    Producto();
    Producto(int, char[], char[], double);
    int RegresaClave();
    double RegresaPrecio();
    int operator == (Producto);
    int operator != (Producto);
    int operator > (Producto);
    int operator < (Producto);
    friend istream &operator>> (istream &, Producto &);
    friend ostream &operator<< (ostream &, Producto &);
};

Producto::Producto():Clave(0), origen(""), destino(""), peso(0.0)
{}

Producto::Producto(int Cla, char NomP[], char NomD[], double Pre)
{
    Clave= Cla;
    strcpy(origen, NomP);
    strcpy(destino, NomD);
    peso= Pre;
}

double Producto::RegresaPrecio()
{
    return peso;
}

int Producto::RegresaClave()
{
    return Clave;
}

int Producto::operator == (Producto Prod)
{
    int Resp=0;
    if (Clave == Prod.Clave)
        Resp= 1;
    return Resp;
}

int Producto::operator != (Producto Prod)
{
    int Resp=0;
    if (Clave != Prod.Clave)
        Resp= 1;
    return Resp;
}

int Producto::operator > (Producto Prod)
{
    int Resp=0;
    if (Clave > Prod.Clave)
        Resp= 1;
    return Resp;
}

int Producto::operator < (Producto Prod)
{
    int Resp=0;
    if (Clave < Prod.Clave)
        Resp= 1;
    return Resp;
}

istream &operator>>(istream &Lee, Producto &ObjProd)
{
    cout<<"\n\nIngrese Clave Del Producto: ";
    Lee>>ObjProd.Clave;
    fflush(stdin);

    cout<<"\nIngrese Nombre De origen: ";
    Lee>>ObjProd.origen;
    fflush(stdin);

    cout<<"\nIngrese Nombre De destino: ";
    Lee>>ObjProd.destino;
    fflush(stdin);


    cout<<"\nIngrese peso: ";
    Lee>>ObjProd.peso;
    fflush(stdin);

    return Lee;
}

ostream &operator<< (ostream &Escribe, Producto &ObjProd)
{
    Escribe<<"\n\nDatos Del Producto: \n";
    Escribe<<"\nClave:  "<<ObjProd.Clave;
    Escribe<<"\nOrigen: "<<ObjProd.origen;
    Escribe<<"\nDestino: "<<ObjProd.destino;
    Escribe<<"\nPrecio: "<<ObjProd.peso<<"\n";
    return Escribe;
}
#endif // PRODUCTOS_H_INCLUDED
