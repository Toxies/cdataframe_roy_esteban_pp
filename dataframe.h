#ifndef DATAFRAME_H
#define DATAFRAME_H

#include "colonne.h"

// Ceci est le fichier d'en-tête pour les dataframes
// On y définit la structure et les fonctions pour gérer un dataframe

typedef struct noeud_colonne {
    COLONNE *col;
    struct noeud_colonne *suivant;
    struct noeud_colonne *precedent;
} NOEUD_COLONNE;

typedef struct dataframe {
    NOEUD_COLONNE *tete;
    NOEUD_COLONNE *queue;
} DATAFRAME;

DATAFRAME *creer_dataframe(); // Fonction pour créer un dataframe
void ajouter_colonne_dataframe(DATAFRAME *df, COLONNE *col); // Fonction pour ajouter une colonne au dataframe
void supprimer_colonne_a_dataframe(DATAFRAME *df, int index); // Fonction pour supprimer une colonne du dataframe
void afficher_dataframe(const DATAFRAME *df); // Fonction pour afficher le dataframe
void liberer_dataframe(DATAFRAME **df); // Fonction pour libérer la mémoire du dataframe
void ajouter_ligne_dataframe(DATAFRAME *df, int *valeurs); // Fonction pour ajouter une ligne au dataframe
void supprimer_ligne_dataframe(DATAFRAME *df, int index); // Fonction pour supprimer une ligne du dataframe
int obtenir_valeur_dataframe(DATAFRAME *df, int ligne, int colonne); // Fonction pour obtenir la valeur à une position donnée
void remplacer_valeur_dataframe(DATAFRAME *df, int ligne, int colonne, int nouvelle_valeur); // Fonction pour remplacer la valeur à une position donnée
int nombre_de_lignes_dataframe(const DATAFRAME *df); // Fonction pour obtenir le nombre de lignes du dataframe
int nombre_de_colonnes_dataframe(const DATAFRAME *df); // Fonction pour obtenir le nombre de colonnes du dataframe
void afficher_noms_colonnes_dataframe(const DATAFRAME *df); // Fonction pour afficher les noms des colonnes du dataframe
void afficher_lignes_limite_dataframe(const DATAFRAME *df, int limite); // Fonction pour afficher les lignes avec une limite
void afficher_colonnes_limite_dataframe(const DATAFRAME *df, int limite); // Fonction pour afficher les colonnes avec une limite
int nombre_valeurs_sup_a_x(const DATAFRAME *df, int x); // Fonction pour compter les valeurs supérieures à x
int nombre_valeurs_inf_a_x(const DATAFRAME *df, int x); // Fonction pour compter les valeurs inférieures à x
int nombre_valeurs_egales_a_x(const DATAFRAME *df, int x); // Fonction pour compter les valeurs égales à x

#endif // DATAFRAME_H
