#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo {
    int info;
    struct Nodo *sig;
    struct Nodo *ant;
};

typedef struct Nodo Nodo;

Nodo* nuevoNodo(int info);

#endif // NODO_H_INCLUDED
