//
// Created by esteb on 15/05/2024.
//

#ifndef CDATAFRAME_ROY_ESTEBAN_PP_COLONNE_H
#define CDATAFRAME_ROY_ESTEBAN_PP_COLONNE_H

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
int occurence(int x,COLONNE * col);
int valeurenposition(int x,COLONNE * col);
int valeursupérieur(int x,COLONNE * col);
int valeurinférieur(int x,COLONNE * col);
int valeurégale(int x,COLONNE * col);
int insert_value_user_input(COLONNE* col);

#endif //CDATAFRAME_ROY_ESTEBAN_PP_COLONNE_H
