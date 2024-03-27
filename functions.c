#include <stdio.h>
#include "functions.h"

COLONNE *create_colonne(char* titre){
    COLONNE *column = NULL;
    column->titre = titre;
    return column;
}
