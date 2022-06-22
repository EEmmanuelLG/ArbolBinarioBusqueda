
#include <iostream>
#include "Arbol.h"

int main()
{
    Arbol* arbol = new Arbol();
    int opc = 0;

    while (opc != 7)
    {
        system("cls");
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Mostrar en pre-orden" << endl;
        cout << "4. Mostrar en orden" << endl;
        cout << "5. Mostrar en post-orden" << endl;
        cout << "6. Eliminar" << endl;
        cout << "7. Salir" << endl;

        cout << "Elija una opcion del menu: ";
        cin >> opc;

        system("cls");

        switch (opc)
        {
        case 1:
        {
            int dato = 0;
            cout << "Inserte el dato: ";
            cin >> dato;

            arbol->Inserta(dato);

            break;
        }
        case 2:
        {
            if (arbol->EstaVacio())
                cout << "El arbol esta vacio" << endl;
            else
            {
                int dato = 0;
                cout << "Inserte el dato a buscar: ";
                cin >> dato;

                Nodo* nodo = arbol->Buscar(dato);

                if (nodo == NULL)
                    cout << "Ese nodo no se encuentra en el arbol" << endl;
                else
                {
                    cout << "Nodo " << dato << " encontrado" << endl;
                    cout << "Hijo izquierdo: " << nodo->GetDatoIzq() << endl;
                    cout << "Hijo derecho: " << nodo->GetDatoDer() << endl;
                }
            }
           

            break;
        }
        case 3:
        {
            if (arbol->EstaVacio())
                cout << "El arbol esta vacio" << endl;
            else
                arbol->MostrarEnPreorden();
            
            break;
        }
        case 4:
        {
            if (arbol->EstaVacio())
                cout << "El arbol esta vacio" << endl;
            else
                arbol->MostrarEnOrden();

            break;
        }
        case 5:
        {
            if (arbol->EstaVacio())
                cout << "El arbol esta vacio" << endl;
            else
                arbol->MostrarEnPostorden();

            break;
        }
        case 6:
        {
            if (arbol->EstaVacio())
                cout << "El arbol esta vacio" << endl;
            else
            {
                int dato = 0;
                cout << "Inserte el dato a eliminar: ";
                cin >> dato;

                arbol->Eliminar(dato);
            }

            break;
        }
        }

        cin.get();
        cin.get();
    }
}
