#include <stdio.h>
#include "functions.h"

COLONNE *create_colonne(char* titre){
    COLONNE column1;
    COLONNE * column = &column1;
    column->titre = titre;
    return column;
}
