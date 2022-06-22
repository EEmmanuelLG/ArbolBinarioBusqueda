#include "Arbol.h"

Arbol::Arbol()
{
	raiz = NULL;
}

bool Arbol::EstaVacio()
{
	return raiz == NULL;
}

void Arbol::Inserta(int dato)
{
	if (EstaVacio())
		raiz = new Nodo(dato);
	else
		Inserta(dato, raiz);
}

void Arbol::Inserta(int dato, Nodo* nodo)
{
	if (dato < nodo->dato)
	{
		if (nodo->izq == NULL)
			nodo->izq = new Nodo(dato);
		else
			Inserta(dato, nodo->izq);
	}
	else
	{
		if (nodo->der == NULL)
			nodo->der = new Nodo(dato);
		else
			Inserta(dato, nodo->der);
	}
}

Nodo* Arbol::Buscar(int dato)
{
	return Buscar(dato, raiz);
}

Nodo* Arbol::Buscar(int dato, Nodo* nodo)
{
	if (nodo == NULL)
		return NULL;

	if (dato == nodo->dato)
		return nodo;

	if (dato < nodo->dato)
		return Buscar(dato, nodo->izq);
	else
		return Buscar(dato, nodo->der);
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
	Eliminar(dato, raiz, NULL);
}

void Arbol::Eliminar(int dato, Nodo* nodo, Nodo* padre)
{
	if (nodo == NULL)
	{
		cout << "El nodo especificado no existe" << endl;
		return;
	}

	if (dato < nodo->dato)
		return Eliminar(dato, nodo->izq, nodo);
	else if (dato > nodo->dato)
		return Eliminar(dato, nodo->der, nodo);

	if (nodo->izq == NULL && nodo->der == NULL)
	{
		if (nodo == raiz)
			raiz = NULL;
		else
		{
			if (padre->izq == nodo)
				padre->izq = NULL;
			else
				padre->der = NULL;
		}
		
		delete(nodo);
	}
	else if (nodo->izq != NULL && nodo->der != NULL)
	{
		Nodo* aux = nodo->der;
		Nodo* padreAux = nodo;

		while (aux->izq != NULL)
		{
			padreAux = aux;
			aux = aux->izq;
		}

		nodo->dato = aux->dato;

		if (aux->der)
			padreAux->izq = aux->der;
		
		if (padreAux->izq == aux)
			padreAux->izq = NULL;
		else
			padreAux->der = NULL;

		delete(aux);
	}
	else if (nodo->izq != NULL)
	{
		if (nodo == raiz)
			raiz = nodo->izq;
		else
		{
			if (padre->izq == nodo)
				padre->izq = nodo->izq;
			else
				padre->der = nodo->izq;
		}

		delete(nodo);
	}
	else if (nodo->der != NULL)
	{
		if (nodo == raiz)
			raiz = nodo->der;
		else
		{
			if (padre->izq == nodo)
				padre->izq = nodo->der;
			else
				padre->der = nodo->der;
		}

		delete(nodo);
	}
}