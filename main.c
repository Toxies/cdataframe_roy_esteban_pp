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
    int a = valeurenposition(10, nouvelle_colonne);
    printf("%d", a);
    DATAFRAME *dataframe = create_dataframe("Dataframe");
    COLONNE  *nouvelle_colonne2 = create_colonne("Colonne 2");
    insert_value(nouvelle_colonne2, 3);
    insert_column(nouvelle_colonne, dataframe);
    insert_column(nouvelle_colonne2, dataframe);
    printdataframe(dataframe);
    insert_value(&dataframe->Data[1], 920);
    printdataframe(dataframe);
    return 0;
};