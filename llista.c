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

ListaBiOrd LISTABIORD_elimina (ListaBiOrd l) {

    Node *aux;

    if (l.pdi == l.pri || l.pdi == l.ult) {
        printf("Error, s'esta apuntant a un fantasma.\n");
    }
    else {
        aux = l.pdi;

        l.pdi->ant->sig = l.pdi->sig;
        l.pdi->sig->ant = l.pdi->ant;
        l.pdi = l.pdi->sig;

        free(aux);
    }

    return l;
}

int LISTABIORD_consulta (ListaBiOrd l) {

    int e = -1;

    if (l.pdi == l.pri || l.pdi == l.ult) {
        printf("Error, s'esta apuntant a un fantasma.\n ");
    }
    else {
        e = l.pdi->e;
    }

    return e;
}

int LISTABIORD_buida (ListaBiOrd l) {
    return l.pri->sig == l.ult;
}

int LISTABIORD_fi (ListaBiOrd l) {
    return l.pdi == l.ult;
}

int LISTABIORD_inici (ListaBiOrd l) {
    return l.pdi == l.pri;
}

ListaBiOrd LISTABIORD_vesInici (ListaBiOrd l) {
    l.pdi = l.pri->sig;

    return l;
}

ListaBiOrd LISTABIORD_vesFi (ListaBiOrd l) {
    l.pdi = l.ult->ant;

    return l;
}

ListaBiOrd LISTABIORD_avanca (ListaBiOrd l) {

    if (l.pdi->sig == NULL) {
        printf("Error, estic en el ultim fantasma.\n");
    }
    else {
        l.pdi = l.pdi->sig;
    }

    return l;
}

ListaBiOrd LISTABIORD_retrocedeix (ListaBiOrd l) {
    if (l.pdi->ant == NULL) {
        printf("Error, estic en el primer fantsma.\n");
    }
    else {
        l.pdi = l.pdi->ant;
    }

    return l;
}

ListaBiOrd LISTABIORD_destrueix (ListaBid l) {
    Node *aux;

    while (l.pri != NULL) {
        aux = l.pri;
        l.pri = l.pri->sig;
        free(aux);
    }

    l.pri = NULL;
    l.ult = NULL;
    l.pdi = NULL;

    return l;
}