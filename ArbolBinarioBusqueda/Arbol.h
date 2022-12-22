#pragma once
#include "Nodo.h"

using namespace std;

class Arbol
{
	Nodo* raiz;
	void Insertar(Nodo* nodo, int dato);
	void MostrarEnPreorden(Nodo* nodo);
	void MostrarEnOrden(Nodo* nodo);
	void MostrarEnPostorden(Nodo* nodo);
	Nodo* Eliminar(Nodo* nodo, int dato);

public:
	Arbol();
	bool EstaVacio();
	void Insertar(int dato);
	void MostrarEnPreorden();
	void MostrarEnOrden();
	void MostrarEnPostorden();
	void Eliminar(int dato);
};

