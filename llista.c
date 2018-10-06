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
