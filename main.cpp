#include <iostream>
#include <fstream>
#include "ListasSimLig.h"
#include "Productos.h"

using namespace std;

void CargarLista(Producto &ObjProd,Lista<Producto> &ListaProds, fstream &ArchivoProductoSalida)
{
    ArchivoProductoSalida.seekg(0);
    ArchivoProductoSalida.read(reinterpret_cast <char*>(&ObjProd),sizeof(Producto));

    while(!ArchivoProductoSalida.eof())
    {
        if(ObjProd.RegresaClave() != 0)
        {
            ListaProds.InsertaOrdenCrec(ObjProd);
        }
        ArchivoProductoSalida.read(reinterpret_cast <char*>(&ObjProd),sizeof(Producto));
    }
}

void EliminarElemento(Producto &ObjProd,Lista<Producto> &ListaProds, fstream &ArchivoProductoSalida)
{
    int Clave=0,Res=0;

    cout<<"\n\nIngrese La Clave Del Producto A Eliminar: ";
    cin>>Clave;

    ArchivoProductoSalida.seekp((Clave - 1 ) * sizeof(Producto));
    ArchivoProductoSalida.read(reinterpret_cast <char *>(&ObjProd),sizeof(Producto));

    if(ObjProd.RegresaClave() != 0){
        Producto ProdBlac;

        cout<<"\nSe Encontro La Clave: '"<<Clave<<"'"<<endl;

        ArchivoProductoSalida.seekp((Clave - 1) * sizeof(Producto));
        ArchivoProductoSalida.write(reinterpret_cast < const char *>(&ProdBlac),sizeof(Producto));
    }
    Producto Produc(Clave,"","", 0);
    Res= ListaProds.EliminaUnNodo(Produc);
    switch (Res)
    {
    case 1:
        cout<<"\n\nEl Producto Ha Hizo Eliminado.\n";
        break;
    case 0:
        cout<<"\n\nEse Producto No Se Encuentra Registrado.\n";
        break;
    case -1:
        cout<<"\n\nNo Hay Productos Registrados.\n";

    }
}

void Escribir(Producto &ObjProd,Lista<Producto> &ListaProds,fstream &ArchivoProductoSalida)
{
    cout<<"\n\nIngrese Datos Del Producto A Registrar:";
    cin>>ObjProd;

    if(ListaProds.BuscaOrdenada(ObjProd)== nullptr)
    {
        ListaProds.InsertaOrdenCrec(ObjProd);
    }
    else
    {
        cout << "\n\nClave Ya Registrada" << endl;
    }
    ArchivoProductoSalida.seekp((ObjProd.RegresaClave() - 1) * sizeof(Producto));
    ArchivoProductoSalida.write(reinterpret_cast < const char*>(&ObjProd),sizeof(Producto));
}

int Menu()
{
    int Opc;
    cout<<"\n\nBienvenido Al Sistema De Registro De Productos.";
    cout<<"\n(1) Insertar al inicio.";
    cout<<"\n(2) Eliminar al inicio.";
    cout<<"\n(3) Guardar (archivo)";
    cout<<"\n(4) Recuperar (archivo)";
    cout<<"\n(5) Salir.";

    cout<<"\n\nIngrese Opcion De Trabajo: ";
    cin>>Opc;
    return Opc;
}

int main()
{
    fstream ArchivoProductoSalida;
    ArchivoProductoSalida.open("prod_electronicos.dat",ios::in | ios::out | ios::binary);

    Lista<Producto> ListaProds;
    Producto ObjProd;
    NodoLista<Producto> *Apunt;
    int Opc, Res, Clave;


    Opc= Menu();

    CargarLista(ObjProd,ListaProds,ArchivoProductoSalida);

    while (Opc >= 1 && Opc <= 4)
    {
        ArchivoProductoSalida.clear();
        switch (Opc)
        {
        case 1:
        {
            Escribir(ObjProd,ListaProds,ArchivoProductoSalida);
            break;
        }
        case 2:
        {
            EliminarElemento(ObjProd,ListaProds,ArchivoProductoSalida);
        }
        break;
        case 3:

            ListaProds.ImprimeIterativo();


        break;
        case 4:
            ListaProds.ImprimeIterativo();
            break;
        }
        Opc= Menu();
    }
    ArchivoProductoSalida.close();
    return 0;
}
