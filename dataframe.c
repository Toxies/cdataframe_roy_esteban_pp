//
// Created by esteb on 15/05/2024.
//

#include "dataframe.h"
#include <stdio.h>
#include <stdlib.h>



struct DATAFRAME* create_dataframe(char* titre) {
    struct DATAFRAME* dataframe = malloc(sizeof(DATAFRAME));  // Allocate memory for the column
    if (dataframe != NULL) {
        dataframe->titre = titre;
        dataframe->TL = 0;
        dataframe->TP = 256;
        dataframe->Data = malloc(sizeof(COLONNE) * 256);
        if (dataframe->Data == NULL) {
            // Handle memory allocation failure
            free(dataframe);
            return NULL;
        }
    }
    return dataframe;
}


int insert_column(COLONNE* col, DATAFRAME* Dataframe) {
    if (Dataframe == NULL || col == NULL) {
        printf("Invalid arguments\n");
        return -1;  // Return an error code
    }

    // Insert the column into the dataframe
    Dataframe->Data[Dataframe->TL] = col;
    Dataframe->TL++;

    printf("Success\n");
    return 0;  // Return success code
}



void print_colDataframePos(DATAFRAME * Dataframe, int position){ // can be used in a for loop to get the entire dataframe
    COLONNE * col = Dataframe->Data[position];
    printf("%s \n", Dataframe->titre);
    // Print column titles
    printf("%s\t", (Dataframe->Data[position])->titre);

    printf("\n");
    for (int i = 0; i < col->TL;i++){
        printf("[%d] %d \n", i, *(col->Data + i));
    }
}

void printdataframe(DATAFRAME* Dataframe) { // doesnt work properly
    printf("%s\n", Dataframe->titre);

    // Print column titles
    for (int i = 0; i < Dataframe->TL; i++) {
        printf("%s\t", (Dataframe->Data[i])->titre);
    }
    printf("\n");

    // Print data in columns
    for (int j = 0; j < Dataframe->TL; j++) {
        for (int i = 0; i < Dataframe->TL; i++) {
            if (j < Dataframe->Data[i]->TL) {
                printf("\t%d\t", Dataframe->Data[i]->Data[j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

int verifyExistence(DATAFRAME * Dataframe, int value){
    int Found = 0;
    int i = 0;
    while (Found == 0 && i < Dataframe->TL){
        if (occurence(value, Dataframe->Data[i])){
            Found = 1;
        }
        i++;
    }
    return Found;
}

int replacevalue(DATAFRAME * Dataframe){
    int value, posx, posy;
    printf("Choose the value that will replace the old one ; \n");
    scanf("%d", &value);
    printf("Specify the positons x and y of the value that will be replaced using this format : x/y\n");
    scanf("%d/%d", &posx,&posy);
    if (posx > Dataframe->TL || posx < 0 || posy < 0){
        return -1;
    }
    if (posx > Dataframe->Data[posy]->TL) {
        return -1;
    }
    Dataframe->Data[posy]->Data[posx] = value;
    return 1;
}

void partialdataframeprint(DATAFRAME * Dataframe, int x1, int x2) {
    printf("%s\n", Dataframe->titre);


    for (int i = x1; i < x2; i++) {
        printf("%s\t", (Dataframe->Data[i])->titre);
    }
    printf("\n");

    for (int j = 0; j < Dataframe->TL; j++) {
        for (int i = x1; i < x2; i++) {
            if (j < Dataframe->Data[i]->TL) {
                printf("\t%d\t", Dataframe->Data[i]->Data[j]);
            } else {
                printf("\t");
            }
        }
        printf("\n");
    }
}

void print_all_column_names(DATAFRAME * Dataframe){
    // Print column titles
    for (int i = 0; i < Dataframe->TL; i++) {
        printf("%s\t", (Dataframe->Data[i])->titre);
    }
    printf("\n");
}


void amount_of_columns(DATAFRAME * Dataframe){
    int cpt=0;
    for (int i = 0; i < Dataframe->TL; i++){
        cpt++;
    }
    printf("%d column(s) in the Dataframe\n" ,cpt);
}

int non_null_lines_in_column(COLONNE *col) {
    int cpt = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->Data[i] != -1) {  // -1 represents no data
            cpt++;
        }
    }
    return cpt;
}

void amount_of_lines(DATAFRAME * Dataframe) {
    int max_lines = 0;
    for (int i = 0; Dataframe->Data[i] != NULL; i++) {
        int non_null_lines = non_null_lines_in_column(Dataframe->Data[i]);
        if (non_null_lines > max_lines) {
            max_lines = non_null_lines;
        }
    }
    printf("%d line(s) in the dataframe\n", max_lines);
}

void rename_column(DATAFRAME * Dataframe){
    char new_col_name[20];
    int col_pos = -1;
    while (col_pos <= -1){
        printf("What column do you want to change ?\n");
        scanf("%d", &col_pos);
    }
    printf("What is the new column name ?\n");
    scanf("%s", new_col_name);
    printf("%s",(Dataframe->Data[col_pos])->titre);
    (Dataframe->Data[col_pos])->titre = new_col_name;
    printf(" is now : %s", (Dataframe->Data[col_pos])->titre);
}
