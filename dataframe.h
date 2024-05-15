//
// Created by esteb on 15/05/2024.
//

#ifndef CDATAFRAME_ROY_ESTEBAN_PP_DATAFRAME_H
#define CDATAFRAME_ROY_ESTEBAN_PP_DATAFRAME_H
#include "colonne.h"

struct DATAFRAME{
    char* titre;
    int TP;
    int TL;
    COLONNE** Data;  // Pointer to an array of COLONNE structures
};

typedef struct DATAFRAME DATAFRAME;

typedef struct lnode_ {
    void *data; // Pointer to a column
    struct lnode_ *prev;
    struct lnode_ *next;
} LNODE;

typedef struct list_ {
    LNODE *head;
    LNODE *tail;
} LIST;
typedef LIST CDATAFRAME;

struct DATAFRAME* create_dataframe(char* titre);
int insert_column(COLONNE* col, DATAFRAME* Dataframe);
void print_colDataframePos(DATAFRAME * Dataframe, int position);
void printdataframe(DATAFRAME * Dataframe);
int verifyExistence(DATAFRAME * Dataframe, int value);
int replacevalue(DATAFRAME * Dataframe, int value, int posx,int posy);
void partialdataframeprint(DATAFRAME * Dataframe, int x1,int x2);
void printdataframe2(DATAFRAME* Dataframe);

#endif //CDATAFRAME_ROY_ESTEBAN_PP_DATAFRAME_H
