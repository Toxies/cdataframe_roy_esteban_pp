#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colonne.h"

// Ceci est le fichier d'implémentation pour les colonnes
// On implémente ici les fonctions pour gérer une colonne

COLONNE *creer_colonne(const char *titre) {
    COLONNE *col = (COLONNE *)malloc(sizeof(COLONNE)); // On alloue de la mémoire pour la colonne
    col->titre = strdup(titre); // On assigne le titre à la colonne
    col->valeurs = (int *)malloc(sizeof(int) * 10); // On alloue de la mémoire pour les valeurs
    col->taille = 0; // La taille initiale est 0
    col->capacite = 10; // La capacité initiale est 10
    return col; // On retourne la nouvelle colonne
}

void supprimer_colonne(COLONNE **col) {
    if (!col || !*col) return;

    free((*col)->titre); // On libère le titre
    free((*col)->valeurs); // On libère les valeurs
    free(*col); // On libère la colonne
    *col = NULL; // On met le pointeur à NULL
}

void ajouter_valeur_colonne(COLONNE *col, int valeur) {
    if (col->taille == col->capacite) {
        col->capacite *= 2;
        col->valeurs = (int *)realloc(col->valeurs, sizeof(int) * col->capacite);
    }
    col->valeurs[col->taille++] = valeur;
}

int obtenir_valeur_colonne(const COLONNE *col, int index) {
    if (index < 0 || index >= col->taille) {
        return -1; // Valeur par défaut si l'index est hors limites
    }
    return col->valeurs[index];
}

void supprimer_valeur_a_colonne(COLONNE *col, int index) {
    if (index < 0 || index >= col->taille) {
        return;
    }

    for (int i = index; i < col->taille - 1; i++) {
        col->valeurs[i] = col->valeurs[i + 1];
    }
    col->taille--;
}

void renommer_colonne(COLONNE *col, const char *nouveau_titre) {
    if (col) {
        free(col->titre); // On libère l'ancien titre
        col->titre = strdup(nouveau_titre); // On copie le nouveau titre
    }
}

int nombre_valeurs_sup_a_colonne(const COLONNE *col, int x) {
    int compteur = 0;
    for (int i = 0; i < col->taille; i++) {
        if (col->valeurs[i] > x) {
            compteur++;
        }
    }
    return compteur;
}

int nombre_valeurs_inf_a_colonne(const COLONNE *col, int x) {
    int compteur = 0;
    for (int i = 0; i < col->taille; i++) {
        if (col->valeurs[i] < x) {
            compteur++;
        }
    }
    return compteur;
}

int nombre_valeurs_egales_a_colonne(const COLONNE *col, int x) {
    int compteur = 0;
    for (int i = 0; i < col->taille; i++) {
        if (col->valeurs[i] == x) {
            compteur++;
        }
    }
    return compteur;
}
