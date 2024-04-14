#ifndef COLONNE_H
#define COLONNE_H

#include <stdlib.h>
#include <stdio.h>

struct colonne {
    char* titre;
    int TP;
    int TL;
    int* Data;
};

typedef struct colonne COLONNE;

COLONNE* create_colonne(char* titre);
int insert_value(COLONNE* col, int data);
void delete_column(COLONNE* col);
void print_col(COLONNE * col);
#endif
