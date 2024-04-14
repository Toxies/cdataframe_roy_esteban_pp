#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

COLONNE* create_colonne(char* titre) {
    COLONNE* column = malloc(sizeof(COLONNE));  // Allocate memory for the column
    if (column != NULL) {
        column->titre = titre;
        column->TL = 0;
        column->TP = 256;
        column->Data = malloc(sizeof(int) * 256);
        if (column->Data == NULL) {
            // Handle memory allocation failure
            free(column);
            return NULL;
        }
    }
    return column;
}

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
    if (Dataframe == NULL || Dataframe->Data == NULL) {
        // Invalid column or memory not allocated
        return -1;  // Return an error code
    }

    if (Dataframe->TL == Dataframe->TP) {
        printf("Dataframe is full\n");
        return -1;  // Return an error code
    }

    Dataframe->Data[Dataframe->TL] = col;
    Dataframe->TL++;
    printf("Success\n");
    return 0;  // Return success code
}

int insert_value(COLONNE* col, int data) {
    if (col == NULL || col->Data == NULL) {
        // Invalid column or memory not allocated
        return -1;  // Return an error code
    }

    if (col->TL == col->TP) {
        printf("Column is full\n");
        return -1;  // Return an error code
    }

    col->Data[col->TL] = data;
    col->TL++;
    printf("Success\n");
    return 0;  // Return success code
}

void delete_column(COLONNE* col) {
    if (col != NULL) {
        free(col->Data);
        free(col);
    }
}

void print_col(COLONNE * col){
    for (int i = 0; i < col->TL;i++){
        printf("[%d] %d \n", i, *(col->Data + i));
    }
}

int occurence(int x,COLONNE * col) {
    int Occurence = 0;
    for (int i = 0; i < col->TL; i++) {
        if ((*(col->Data + i)) == x){
            Occurence++;
        }
    }
    return Occurence;
}

int valeurenposition(int x, COLONNE* col) {
    if (x >= 0 && x < col->TL) {
        return col->Data[x];
    } else {
        printf("Position invalide\n");
        return -1;
    }
}

int valeursupérieur(int x,COLONNE * col){
    int valeurssupérieur = 0;
    for (int i = 0; i < col->TL; i++) {
        if ((*(col->Data + i)) > x){
            valeurssupérieur++;
        }
    }
    return valeurssupérieur;
}

int valeurinférieur(int x,COLONNE * col){
    int valeurinférieur = 0;
    for (int i = 0; i < col->TL; i++) {
        if ((*(col->Data + i)) < x){
            valeurinférieur++;
        }
    }
    return valeurinférieur;
}

int valeurégale(int x,COLONNE * col){
    int valeuregale = 0;
    for (int i = 0; i < col->TL; i++) {
        if ((*(col->Data + i)) == x){
            valeuregale++;
        }
    }
    return valeuregale;
}


