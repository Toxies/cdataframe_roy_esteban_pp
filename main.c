#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"

int main(){
    COLONNE *nouvelle_colonne = create_colonne("Colonne 1");
    printf("%s\n", nouvelle_colonne->titre);
    insert_value(nouvelle_colonne, 90);
    printf("%d \n", nouvelle_colonne->Data[0]);
    insert_value(nouvelle_colonne, 2);
    printf("%d \n", nouvelle_colonne->Data[1]);
    print_col(nouvelle_colonne);
    return 0;
};