#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"

Nodo* nuevoNodo(int info) {
    struct Nodo *nodo;
    nodo = malloc(sizeof(struct Nodo));
    if (nodo == NULL) {
        printf("No hay memoria suficiente para crear un nodo\n");
        exit(0);
    }
    nodo->sig = NULL;
    nodo->ant = NULL;
    nodo->info = info;
    return nodo;
}

