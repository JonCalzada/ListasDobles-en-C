#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

enum repeticion {aceptaRepetidos, noAceptaRepetidos};
typedef enum repeticion repeticion;

struct Lista {
    Nodo *h;
    Nodo *t;
    repeticion repetidos;
};

typedef struct Lista Lista;


Lista *nuevaLista(repeticion repetidos);
int listaVacia(Lista *lista);

void agregarFinal(Nodo *nodo,Lista *lista);
void agregarInicio(Nodo *m, Lista *lista);
int agregarDespuesDe(Nodo *nodo, int clave, Lista *lista);

Nodo *retirarInicio(Lista *lista);
Nodo *retirarFinal(Lista *lista);
Nodo *retirar(Lista *lista, int clave);

Nodo *buscar(Lista *lista, int clave);
Nodo *buscarSiguiente(Nodo *nodo, int clave);

void iterar(Lista *lista,void iterador(Nodo *nodo));
void iterarInverso(Lista *lista,void iterador(Nodo *nodo));

#endif // LISTA_H_INCLUDED
