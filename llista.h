#ifndef _LISTA_BIORD_H
#define _LISTA_BIORD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    int e;
    struct N *sig;
    struct N *ant;
} Node;

typedef struct {
    Node *pri;
    Node *ult;
    Node *pdi;
} ListaBiOrd;
