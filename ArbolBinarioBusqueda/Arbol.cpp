#include "Arbol.h"

Arbol::Arbol()
{
	raiz = NULL;
}

bool Arbol::EstaVacio()
{
	return raiz == NULL;
}

void Arbol::Insertar(int dato)
{
	if (EstaVacio())
		raiz = new Nodo(dato);
	else
		Insertar(raiz, dato);
}

void Arbol::Insertar(Nodo* nodo, int dato)
{
	if (dato < nodo->dato)
	{
		if (nodo->izq == NULL)
			nodo->izq = new Nodo(dato);
		else
			Insertar(nodo->izq, dato);
	}
	else if (dato > nodo->dato)
	{
		if (nodo->der == NULL)
			nodo->der = new Nodo(dato);
		else
			Insertar(nodo->der, dato);
	}
}

void Arbol::MostrarEnPreorden()
{
	MostrarEnPreorden(raiz);
}

void Arbol::MostrarEnPreorden(Nodo* nodo)
{
	if (nodo == NULL)
		return;

	cout << nodo->dato << endl;
	MostrarEnPreorden(nodo->izq);
	MostrarEnPreorden(nodo->der);
}

void Arbol::MostrarEnOrden()
{
	MostrarEnOrden(raiz);
}

void Arbol::MostrarEnOrden(Nodo* nodo)
{
	if (nodo == NULL)
		return;

	MostrarEnOrden(nodo->izq);
	cout << nodo->dato << endl;
	MostrarEnOrden(nodo->der);
}

void Arbol::MostrarEnPostorden()
{
	MostrarEnPostorden(raiz);
}

void Arbol::MostrarEnPostorden(Nodo* nodo)
{
	if (nodo == NULL)
		return;

	MostrarEnPostorden(nodo->izq);
	MostrarEnPostorden(nodo->der);
	cout << nodo->dato << endl;
}

void Arbol::Eliminar(int dato)
{
	Eliminar(raiz, dato);
}

Nodo* Arbol::Eliminar(Nodo* nodo, int dato)
{
	if (nodo == NULL)
	{
		cout << "No se encontró el nodo" << endl;
		return NULL;
	}
	else if (dato < nodo->dato)
		nodo->izq = Eliminar(nodo->izq, dato);
	else if (dato > nodo->dato)
		nodo->der = Eliminar(nodo->der, dato);
	else
	{
		if (nodo->izq == NULL && nodo->der == NULL)
		{
			delete nodo;
			nodo = NULL;
		}
		else if (nodo->izq == NULL)
		{
			Nodo* tmp = nodo;
			nodo = nodo->der;
			delete tmp;
		}
		else if (nodo->der == NULL)
		{
			Nodo* tmp = nodo;
			nodo = nodo->izq;
			delete tmp;
		}
		else
		{
			Nodo* aux = nodo->der;

			while (aux->izq != NULL)
				aux = aux->izq;

			nodo->dato = aux->dato;
			nodo->der = Eliminar(nodo->der, aux->dato);
		}
	}

	return nodo;
}