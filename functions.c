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

