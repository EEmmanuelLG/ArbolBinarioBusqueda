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
	bool EstaVacio(); // Retorna true si el el árbol está vacío
	void Inserta(int dato); // Inserta un nodo con el dato pasado como parámetro en el árbol
	Nodo* Buscar(int dato); // Busca y retorna el nodo que contiene el dato pasado como parámetro
	void MostrarEnPreorden(); // Muestra los nodos en pre-orden
	void MostrarEnOrden(); // Muestra los nodos en orden
	void MostrarEnPostorden(); // Muestra los nodos en post-orden
	void Eliminar(int dato); // Elimina el nodo que tiene el dato pasado como parámetro
};

