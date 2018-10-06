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

ListaBiOrd LISTABIORD_crea ();
void LISTABIORD_afegirOrdenat(ListaBiOrd l, int e);
ListaBiOrd LISTABIORD_elimina (ListaBiOrd l);
int LISTABIORD_consulta (ListaBiOrd l);
int LISTABIORD_buida (ListaBiOrd l);
int LISTABIORD_fi (ListaBiOrd l);
int LISTABIORD_inici (ListaBiOrd l);
ListaBiOrd LISTABIORD_vesInici (ListaBiOrd l);
ListaBiOrd LISTABIORD_vesFi (ListaBiOrd l);
ListaBiOrd LISTABIORD_avanca (ListaBiOrd l);
ListaBiOrd LISTABIORD_retrocedeix (ListaBiOrd l);
ListaBiOrd LISTABIORD_destrueix (ListaBiOrd l);

#endif