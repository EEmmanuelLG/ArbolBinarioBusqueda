#pragma once
#include "Nodo.h"

using namespace std;

class Arbol
{
	Nodo* raiz;
	void Inserta(int dato, Nodo* nodo);
	Nodo* Buscar(int dato, Nodo* nodo);
	void MostrarEnPreorden(Nodo* nodo);
	void MostrarEnOrden(Nodo* nodo);
	void MostrarEnPostorden(Nodo* nodo);
	void Eliminar(int dato, Nodo* nodo, Nodo* padre);

public:
	Arbol();
	bool EstaVacio(); // Retorna true si el el ?rbol est? vac?o
	void Inserta(int dato); // Inserta un nodo con el dato pasado como par?metro en el ?rbol
	Nodo* Buscar(int dato); // Busca y retorna el nodo que contiene el dato pasado como par?metro
	void MostrarEnPreorden(); // Muestra los nodos en pre-orden
	void MostrarEnOrden(); // Muestra los nodos en orden
	void MostrarEnPostorden(); // Muestra los nodos en post-orden
	void Eliminar(int dato); // Elimina el nodo que tiene el dato pasado como par?metro
};

