#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

/** Prepara la nueva lista */

Lista *nuevaLista(repeticion repetidos) {
    Lista *nueva;
    if ((repetidos != aceptaRepetidos) && (repetidos != noAceptaRepetidos)) {
        printf("nuevaLista(): No se ha definido correctamente si la lista acepta o no elementos repetidos\n");
        exit(0);
    }
    nueva = malloc(sizeof(Lista));
    if (nueva == NULL) {
        printf("nuevaLista(): No hay memoria suficiente para crear una lista\n");
        exit(0);
    }
    nueva->h = NULL;
    nueva->t = NULL;
    nueva->repetidos = repetidos;
    return nueva;
}

/** Funcion para identificar si una lista está vacia */
int listaVacia(Lista *lista) {
    if (lista->h==NULL)
        return 1;
    return 0;
}

/** FUNCIONES PARA AGREGAR UN NODO */

void agregarInicio(Nodo *nodo,Lista *lista) {
    Nodo *primero;
    if (nodo == NULL) {
        printf("agregarInicio(): El nodo no puede ser NULL");
        return;
    }
    if (listaVacia(lista)) {
        lista->h = nodo;
        lista->t = nodo;
        return;
    }
    if ( (lista->repetidos == noAceptaRepetidos) && (buscar(lista,nodo->info)!=NULL) ) {
        return;
    }
    primero = lista->h;
    nodo->sig = primero;
    primero->ant=nodo;
    lista->h = nodo;
}

void agregarFinal(Nodo *nodo,Lista *lista) {
    Nodo *ultimo;
    if (nodo == NULL) {
        printf("agregarFinal(): El nodo no puede ser NULL");
        return;
    }
    if (listaVacia(lista)) {
        lista->h = nodo;
        lista->t = nodo;
        return;
    }
    if ( (lista->repetidos == noAceptaRepetidos) && (buscar(lista,nodo->info)!=NULL) ) {
        return;
    }
    ultimo = lista->t;
    ultimo->sig = nodo;
    nodo->ant=ultimo;
    lista->t = nodo;
}

int agregarDespuesDe(Nodo *nodo, int clave, Lista *lista) {
    Nodo *p;
    if (nodo == NULL) {
        printf("agregarDespuesDe(): El nodo no puede ser NULL");
        return 0;
    }
    if (listaVacia(lista))
        return 0;
    p = buscar(lista,clave);
    if (p==NULL)
        return 0;
    if ( (lista->repetidos == noAceptaRepetidos) && (buscar(lista,nodo->info)!=NULL) )
        return 0;
    if (p==lista->t) {
        agregarFinal(nodo,lista);
        return 1;
    }
    nodo->sig = p->sig;
    p->sig->ant=nodo;
    p->sig = nodo;
    nodo->ant=p;
    return 1;
}

/** FUNCIONES PARA RETIRAR UN NODO */

Nodo *retirarInicio(Lista *lista) {
    Nodo *nodo;
    if (listaVacia(lista))
        return NULL;
    if (lista->h == lista->t) {
        nodo = lista->h;
        lista->h = NULL;
        lista->t = NULL;
        return nodo;
    }
    nodo = lista->h;
    lista->h = (lista->h)->sig;
    nodo->sig = NULL;
    lista->h->ant=NULL;
    return nodo;
}

Nodo *retirarFinal(Lista *lista) {
    Nodo *nodo, *p;
    if (listaVacia(lista))
        return NULL;
    if (lista->h == lista->t) {
        nodo = lista->h;
        lista->h = NULL;
        lista->t = NULL;
        return nodo;
    }
    p = lista->h;
    while (p->sig != lista->t)
        p=p->sig;
    nodo = lista->t;
    p->sig = NULL;
    nodo->ant=NULL;
    lista->t = p;
    return nodo;
}

Nodo *retirar(Lista *lista, int clave) {
    Nodo *nodo, *nodoAnt;
    if (listaVacia(lista))
        return NULL;
    if (lista->h->info == clave) {
        return retirarInicio(lista);
    }
    if (lista->t->info == clave) {
        return retirarFinal(lista);
    }
    nodoAnt = NULL;
    nodo = lista->h;
    while ((nodo!=NULL) && (nodo->info!=clave)) {
        nodoAnt = nodo;
        nodo = nodo->sig;
    }
    if (nodo == NULL)
        return NULL;

    nodoAnt->sig = nodo->sig;
    nodo->sig->ant=nodoAnt;
    nodo->sig = NULL;
    nodo->ant=NULL;

    return nodo;
};

/** FUNCIONES PARA BUSCAR UN NODO */

Nodo *buscar(Lista *lista, int clave) {
    Nodo *nodo;
    if (listaVacia(lista))
        return NULL;
    nodo = lista->h;
    while ((nodo!=NULL) && (nodo->info!=clave))
        nodo = nodo->sig;
    return nodo;
};

Nodo *buscarSiguiente(Nodo *nodo, int clave) {
    if (nodo==NULL)
        return NULL;
    while ((nodo!=NULL) && (nodo->info!=clave))
        nodo = nodo->sig;
    return nodo;
}

/** Funciones para iterar sobre todos los elementos de la lista */

void iterar(Lista *lista,void iterador(Nodo *nodo)) {
    Nodo *nodo;
    nodo = lista->h;
    while (nodo!=NULL) {
        iterador(nodo);
        nodo = nodo->sig;
    }
}

void iterarInverso(Lista *lista,void iterador(Nodo *nodo)) {
    Nodo *nodo;
    nodo = lista->t;
    while (nodo!=NULL) {
        iterador(nodo);
        nodo = nodo->ant;
    }
}

