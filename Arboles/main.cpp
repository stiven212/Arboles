#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *derecho;
    Nodo *izquierdo;

};

// NODOS LISTOS PARA SER INSERTADOS EN EL ARBOL
Nodo *crearNodoPadresHijos(int n);


// ARBOL LISTO PARA SER USADO
Nodo *arbolbinario = NULL;





void insertarNodosEnArbolBinario(Nodo *&arbolbinario, int n);


void mostrarArbolBinario(Nodo*&arbolbinario, int separador);

// R-I-D
void preOrden(Nodo *&arbolbinario);
//
void inOrden(Nodo *&arbolbinario);

void posOrden(Nodo *&arbolbinario);

int main()
{
    int n;
    for(int i=0; i<7; i++)
    {
        cout <<"INSERTAR NODOS ";
        cin >> n;
        insertarNodosEnArbolBinario(arbolbinario,n);
    }
    mostrarArbolBinario(arbolbinario,0);
    cout << "RECORRIDOS"<< endl;
    cout << "PreOrden"<< endl;
    preOrden(arbolbinario);
    cout << endl;
    cout << "InOrden"<< endl;
    inOrden(arbolbinario);
    cout << endl;
    cout << "PosOrden"<< endl;
    posOrden(arbolbinario);
    return 0;
}

Nodo *crearNodoPadresHijos(int n)
{
    // Inicializar el arbol con los nodos
    Nodo *nuevo = new Nodo();
    //Asignar los valores al nodo creado
    nuevo->dato=n;
    nuevo->derecho= NULL;
    nuevo->izquierdo=NULL;

    return nuevo;

}

void insertarNodosEnArbolBinario(Nodo *&arbolbinario, int n)
{
if(arbolbinario==NULL)
    {
        Nodo *nuevo= crearNodoPadresHijos(n);
        arbolbinario= nuevo;
    }
    else
    {
        int datoRaiz = arbolbinario->dato;
        if(n<datoRaiz)
        {
            insertarNodosEnArbolBinario(arbolbinario->izquierdo,n);
        }
        else
        {
            insertarNodosEnArbolBinario(arbolbinario->derecho,n);
        }
    }
}

void mostrarArbolBinario(Nodo*&arbolbinario, int separador)
{
        if(arbolbinario==NULL)
        {
            return;
        }
        else
        {
                mostrarArbolBinario(arbolbinario->derecho, separador+1);
                for(int i=0; i<separador; i++)
                {
                    cout << "  ";
                }
                cout << arbolbinario->dato<< endl;
                mostrarArbolBinario(arbolbinario->izquierdo,separador+1);
        }
}

void preOrden(Nodo *&arbolbinario)
{
    if(arbolbinario== NULL)
    {
        return;
    }
    else
    {
        cout << arbolbinario->dato<<"-";
        preOrden(arbolbinario->izquierdo);
        preOrden(arbolbinario->derecho);

    }
}

void inOrden(Nodo *&arbolbinario)
{
 if(arbolbinario== NULL)
    {
        return;
    }
    else
    {
        preOrden(arbolbinario->izquierdo);
        cout << arbolbinario->dato<<"-";
        preOrden(arbolbinario->derecho);

    }



}

void posOrden(Nodo *&arbolbinario)
{
     if(arbolbinario== NULL)
    {
        return;
    }
    else
    {
       preOrden(arbolbinario->izquierdo);
        preOrden(arbolbinario->derecho);
        cout << arbolbinario->dato<<"-";

    }

}
