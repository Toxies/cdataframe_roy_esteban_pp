//
// Created by esteb on 15/05/2024.
//

#include "colonne.h"
#include <stdio.h>
#include <stdlib.h>


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