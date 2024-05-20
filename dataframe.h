#ifndef DATAFRAME_H
#define DATAFRAME_H

#include "colonne.h"

typedef struct noeud_colonne {
    COLONNE *col;
    struct noeud_colonne *precedent;
    struct noeud_colonne *suivant;
} NOEUD_COLONNE;

typedef struct dataframe {
    NOEUD_COLONNE *tete;
    NOEUD_COLONNE *queue;
} DATAFRAME;

// Fonctions de gestion de dataframe
DATAFRAME *creer_dataframe();
void ajouter_colonne(DATAFRAME *df, COLONNE *col);
void supprimer_colonne_a(DATAFRAME *df, int index);
void afficher_dataframe(const DATAFRAME *df);
void liberer_dataframe(DATAFRAME **df);
void ajouter_ligne(DATAFRAME *df, int *valeurs);
void supprimer_ligne(DATAFRAME *df, int index);
int obtenir_valeur(DATAFRAME *df, int ligne, int colonne);
void remplacer_valeur_df(DATAFRAME *df, int ligne, int colonne, int nouvelle_valeur);
int nombre_de_lignes(const DATAFRAME *df);
int nombre_de_colonnes(const DATAFRAME *df);
void afficher_noms_colonnes(const DATAFRAME *df);

#endif // DATAFRAME_H
