#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colonne.h"

// Ceci est le fichier d'implémentation pour les colonnes dans un dataframe
// On implémente ici les fonctions pour gérer une colonne

COLONNE *creer_colonne(const char *titre) {
    COLONNE *col = (COLONNE *)malloc(sizeof(COLONNE)); // On alloue de la mémoire pour la colonne
    col->titre = strdup(titre); // On copie le titre de la colonne
    col->valeurs = NULL; // On initialise les valeurs à NULL
    col->taille = 0; // On initialise la taille à 0
    return col; // On retourne la nouvelle colonne
}

void supprimer_colonne(COLONNE **col) {
    if (*col) {
        free((*col)->titre); // On libère la mémoire du titre
        free((*col)->valeurs); // On libère la mémoire des valeurs
        free(*col); // On libère la mémoire de la colonne
        *col = NULL; // On met le pointeur de colonne à NULL
    }
}

void ajouter_valeur_colonne(COLONNE *col, int valeur) {
    col->valeurs = (int *)realloc(col->valeurs, (col->taille + 1) * sizeof(int)); // On réalloue la mémoire pour ajouter une nouvelle valeur
    col->valeurs[col->taille] = valeur; // On ajoute la nouvelle valeur
    col->taille++; // On incrémente la taille de la colonne
}

void supprimer_valeur_a_colonne(COLONNE *col, int index) {
    if (col && index >= 0 && index < col->taille) {
        for (int i = index; i < col->taille - 1; i++) {
            col->valeurs[i] = col->valeurs[i + 1]; // On décale les valeurs pour supprimer celle à l'index donné
        }
        col->valeurs = (int *)realloc(col->valeurs, (col->taille - 1) * sizeof(int)); // On réalloue la mémoire pour supprimer une valeur
        col->taille--; // On décrémente la taille de la colonne
    }
}

void trier_colonne(COLONNE *col) {
    if (col) {
        for (int i = 0; i < col->taille - 1; i++) {
            for (int j = i + 1; j < col->taille; j++) {
                if (col->valeurs[i] > col->valeurs[j]) {
                    int temp = col->valeurs[i]; // On fait un échange pour trier les valeurs
                    col->valeurs[i] = col->valeurs[j];
                    col->valeurs[j] = temp;
                }
            }
        }
    }
}

void renommer_colonne(COLONNE *col, const char *nouveau_titre) {
    if (col) {
        free(col->titre); // On libère l'ancien titre
        col->titre = strdup(nouveau_titre); // On copie le nouveau titre
    }
}

void remplacer_valeur_colonne(COLONNE *col, int index, int nouvelle_valeur) {
    if (col && index >= 0 && index < col->taille) {
        col->valeurs[index] = nouvelle_valeur; // On remplace la valeur à l'index donné
    }
}

int obtenir_valeur_a_colonne(COLONNE *col, int index) {
    if (col && index >= 0 && index < col->taille) {
        return col->valeurs[index]; // On retourne la valeur à l'index donné
    }
    return -1; // On retourne -1 si l'index est invalide
}

int nombre_occurrences_valeur(COLONNE *col, int valeur) {
    int count = 0;
    if (col) {
        for (int i = 0; i < col->taille; i++) {
            if (col->valeurs[i] == valeur) {
                count++; // On compte le nombre d'occurrences de la valeur
            }
        }
    }
    return count; // On retourne le nombre d'occurrences
}

int nombre_valeurs_sup_a(COLONNE *col, int valeur) {
    int count = 0;
    if (col) {
        for (int i = 0; i < col->taille; i++) {
            if (col->valeurs[i] > valeur) {
                count++; // On compte le nombre de valeurs supérieures à la valeur donnée
            }
        }
    }
    return count; // On retourne le nombre de valeurs supérieures
}

int nombre_valeurs_inf_a(COLONNE *col, int valeur) {
    int count = 0;
    if (col) {
        for (int i = 0; i < col->taille; i++) {
            if (col->valeurs[i] < valeur) {
                count++; // On compte le nombre de valeurs inférieures à la valeur donnée
            }
        }
    }
    return count; // On retourne le nombre de valeurs inférieures
}

int nombre_valeurs_egales_a(COLONNE *col, int valeur) {
    int count = 0;
    if (col) {
        for (int i = 0; i < col->taille; i++) {
            if (col->valeurs[i] == valeur) {
                count++; // On compte le nombre de valeurs égales à la valeur donnée
            }
        }
    }
    return count; // On retourne le nombre de valeurs égales
}
