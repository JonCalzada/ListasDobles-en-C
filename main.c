#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "lista.h"

void imprimeNodo(Nodo* nodo);
void imprimeLista(Lista *lista);

int main() {
    Nodo *nodo;
    int k,valor;
    Lista *listaSinRepetidos = nuevaLista(noAceptaRepetidos);
    Lista *listaConRepetidos = nuevaLista(aceptaRepetidos);

    srand(time(NULL));
    printf("agregando valores: ");
    for (k=0; k<15; k++) {
        valor = k;
        printf("[%d] ",valor);
        nodo = nuevoNodo(valor);
        agregarFinal(nodo,listaSinRepetidos);
        nodo = nuevoNodo(valor);
        agregarFinal(nodo,listaConRepetidos);
    }

    imprimeLista(listaConRepetidos);
    imprimeListaInversa(listaConRepetidos);
    imprimeLista(listaSinRepetidos);
    imprimeListaInversa(listaSinRepetidos);
    return 0;
}

void imprimeNodo(Nodo* nodo) {
    printf("[%d]->",nodo->info);
    if (nodo->sig==NULL)
        printf("Tierra\n");
}

void imprimeNodoInverso(Nodo* nodo) {
    printf("[%d]->",nodo->info);
    if (nodo->ant==NULL)
        printf("Tierra\n");
}

void imprimeListaInversa(Lista *lista) {
    printf("\n\n");
    if (lista->repetidos == noAceptaRepetidos)
        printf("Lista sin valores repetidos");
    else
        printf("Lista con valores repetidos");
    iterarInverso(lista,&imprimeNodoInverso);

}

void imprimeLista(Lista *lista) {
    printf("\n\n");
    if (lista->repetidos == noAceptaRepetidos)
        printf("Lista sin valores repetidos");
    else
        printf("Lista con valores repetidos");
    iterar(lista,&imprimeNodo);

}

