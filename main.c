#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"

int main(){
    COLONNE *nouvelle_colonne = create_colonne("Colonne 1");
    printf("%s\n", nouvelle_colonne->titre);
    insert_value(nouvelle_colonne, 90);
    printf("%d", nouvelle_colonne->Data[0]);
    return 0;
};