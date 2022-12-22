#pragma once
#include <iostream>

class Nodo
{
	int dato;
	Nodo* izq;
	Nodo* der;

	friend class Arbol;

public:
	Nodo(int _dato);
};

