#include "llista.h"

ListaBiOrd LISTABIORD_crea(){
    ListaBiOrd l;

    l.pri = NULL;
    l.pri = (Node*)malloc(sizeof(Node));
    if (l.pri == NULL){
        printf("Error al reservar memoria.\n")
    }
    else {
        l.ult = NULL;
        l.ult = (Node*)malloc(sizeof(Node));
        if (l.ult == NULL){
            printf ("Error al reservar memoria.\n");
        }
        else{
            l.pri->sig = l.ult;
            l.pri->ant = NULL;

            l.ult->sig = NULL;
            l.ult->ant = l.pri;

            l.pdi = l.pri;
        }
    }

    return l;
}

void LISTABIORD_afegirOrdenat(ListaBiOrd l, int e){

    Node *aux;
    aux = l->ant;
    int trobat = 0;
    int e_consulta;

    LISTABIORD_vesInici(l);
    while (!LISTABIORD_fi(l) && !trobat) {
        LISTABIORD_consulta(l, e_consulta);
        if (e < e_consulta) {
            trobat = 1;
        }
        else {
            LISTABIORD_avanca(l);
        }
    }
    Node *aux_2 = (Node*)malloc(sizeof(Nodoe));
    if (aux_2 == NULL) {
        printf("Error al reservar memoria.\n");
    }
    else {
        aux_2->e = e;
        aux_2->sig = l->ant->sig;
        l->ant->sig = aux;
        l->ant = l->ant->sig;
    }
}