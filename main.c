#include <stdio.h>
#include <stdlib.h>
#include "dataframe.h"
#include "colonne.h"

int main(){
    DATAFRAME *dataframe = create_dataframe("Dataframe");
    COLONNE *nouvelle_colonne = create_colonne("Colonne 1");
    insert_value(nouvelle_colonne, 90);
    //insert_value(nouvelle_colonne, 2);
    COLONNE  *nouvelle_colonne2 = create_colonne("Colonne 2");
    insert_value(nouvelle_colonne2, 3);
    insert_value(nouvelle_colonne2, 4);
    insert_value(nouvelle_colonne2, 5);
    insert_column(nouvelle_colonne, dataframe);
    insert_column(nouvelle_colonne2, dataframe);
    // insert_value(dataframe->Data[0], 50);
    printdataframe(dataframe);
    return 0;
};