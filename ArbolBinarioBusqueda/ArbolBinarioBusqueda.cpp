#include <iostream>
#include "Arbol.h"

int main()
{
    Arbol* a = new Arbol();
    int opc = 0;

    while (opc != 6)
    {
        system("cls");
        cout << "1. Insertar" << endl;
        cout << "2. Mostrar en pre orden" << endl;
        cout << "3. Mostrar en orden" << endl;
        cout << "4. Mostrar en post orden" << endl;
        cout << "5. Eliminar" << endl;
        cout << "6. Salir" << endl;

        cout << "Elija una opcion: ";
        cin >> opc;

        system("cls");

        switch (opc)
        {
        case 1:
        {
            int dato = 0;
            cout << "Inserte el dato: ";
            cin >> dato;

            a->Insertar(dato);

            break;
        }
        case 2:
        {
            cout << "Mostrar en pre orden: " << endl;
            a->MostrarEnPreorden();
            break;
        }
        case 3:
        {
            cout << "Mostrar en orden: " << endl;
            a->MostrarEnOrden();
            break;
        }
        case 4:
        {
            cout << "Mostrar en post orden: " << endl;
            a->MostrarEnPostorden();
            break;
        }
        case 5:
        {
            int dato = 0;
            cout << "Inserte el dato: ";
            cin >> dato;

            a->Eliminar(dato);

            break;
        }
        }

        cin.get();
        cin.get();
    }
}
