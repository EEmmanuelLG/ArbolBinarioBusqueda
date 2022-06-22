#include "Nodo.h"

Nodo::Nodo(int _dato)
{
	dato = _dato;
	izq = NULL;
	der = NULL;
}

int Nodo::GetDatoIzq()
{
	return izq == NULL ? NULL : izq->dato;
}

int Nodo::GetDatoDer()
{
	return der == NULL ? NULL : der->dato;
}