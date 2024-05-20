#ifndef DATAFRAME_H
#define DATAFRAME_H

#include "colonne.h"

// Structure représentant un nœud de colonne dans le dataframe
typedef struct noeud_colonne {
    COLONNE *col;
    struct noeud_colonne *precedent;
    struct noeud_colonne *suivant;
} NOEUD_COLONNE;

// Structure représentant un dataframe
typedef struct dataframe {
    NOEUD_COLONNE *tete;   // Pointeur vers le premier premier maillon de la premiere colonne
    NOEUD_COLONNE *queue;  // Pointeur vers le dernier dernier maillon de la dernieres colonne
} DATAFRAME;

// Fonctions de gestion de dataframe
DATAFRAME *creer_dataframe();                               // Crée un nouveau dataframe
void ajouter_colonne(DATAFRAME *df, COLONNE *col);           // Ajoute une colonne au dataframe
void supprimer_colonne_a(DATAFRAME *df, int index);          // Supprime une colonne du dataframe à un index donné
void afficher_dataframe(const DATAFRAME *df);                // Affiche les valeurs du dataframe
void liberer_dataframe(DATAFRAME **df);                      // Libère la mémoire occupée par le dataframe
void ajouter_ligne(DATAFRAME *df, int *valeurs);             // Ajoute une ligne de valeurs au dataframe
void supprimer_ligne(DATAFRAME *df, int index);              // Supprime une ligne du dataframe à un index donné
int obtenir_valeur(DATAFRAME *df, int ligne, int colonne);   // Obtient la valeur à une position donnée dans le dataframe
void remplacer_valeur_df(DATAFRAME *df, int ligne, int colonne, int nouvelle_valeur); // Remplace une valeur dans le dataframe
int nombre_de_lignes(const DATAFRAME *df);                   // Renvoie le nombre de lignes du dataframe
int nombre_de_colonnes(const DATAFRAME *df);                 // Renvoie le nombre de colonnes du dataframe
void afficher_noms_colonnes(const DATAFRAME *df);            // Affiche les noms des colonnes du dataframe

#endif // DATAFRAME_H
