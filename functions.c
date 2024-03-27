#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

COLONNE *create_colonne(char* titre){
    COLONNE column1;
    COLONNE * column = &column1;
    column->titre = titre;
    return column;
}

int *insertValue(COLONNE *col, int data){
    if (col->TL == 256){
        printf("No");
    }
    col->Data[col->TL + 1] = data;
    col->TL++;
}