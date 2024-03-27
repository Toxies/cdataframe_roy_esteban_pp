#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"

int main(){
    COLONNE *nouvelle_colonne = create_colonne("Colonne 1");
    printf("%s", nouvelle_colonne->titre);

    return 0;
};