#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

COLONNE *create_colonne(char* titre){
    COLONNE column1;
    COLONNE * column = &column1;
    column->titre = titre;
    column->TL=0;
    column->TP=256;
    return column;
}

int *insert_value(COLONNE *col, int data) {
    if (col->TL == 256) {
        printf("No");
    }
    else {
        col->Data[col->TL] = data;
        col->TL++;
        printf("Success\n");
    }
}