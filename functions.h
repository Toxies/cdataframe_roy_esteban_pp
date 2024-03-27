#ifndef COLONNE_H
#define COLONNE_H

struct colonne{
    char* titre;
    int TP;
    int TL;
    int Data[256];
};

typedef struct colonne COLONNE;

#endif
COLONNE *create_colonne(char* titre);
int *insert_value(COLONNE *col, int Data);