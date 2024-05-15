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



void print_colDataframePos(DATAFRAME * Dataframe, int position){
    COLONNE * col = Dataframe->Data[position];
    printf("%s \n", Dataframe->titre);
    for (int i = 0; i < col->TL;i++){
        printf("[%d] %d \n", i, *(col->Data + i));
    }
}

void printdataframe(DATAFRAME* Dataframe) {
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

int replacevalue(DATAFRAME * Dataframe, int value, int posx,int posy){
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


void printdataframe1(DATAFRAME* Dataframe) {
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

void printdataframe2(DATAFRAME* Dataframe) {

    // Print Dataframe title
    printf("\t %s", Dataframe->titre);
    printf("\n");

    // Print Column title
    for (int num_col = 0; num_col < Dataframe->TL; num_col++) {
        printf("%s\t", (Dataframe->Data[num_col])->titre);
    }
    printf("\n");

    // Print Column data
    for (int i = 0; i < Dataframe->TL; i++) {
        for (int j = 0; j < Dataframe->TL; j++) {
            /*if (pointer has no value){
                printf("\t\t");
            }
            else {
                printf("%d\t\t", (Dataframe->Data[j])->Data[i]);
            }*/
        }
        printf("\n");
    }
}