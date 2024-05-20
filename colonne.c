#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colonne.h"

#define CAPACITE_INITIALE 10

COLONNE *creer_colonne(char *titre) {
    COLONNE *col = (COLONNE *)malloc(sizeof(COLONNE));
    col->titre = strdup(titre);
    col->valeurs = (int *)malloc(CAPACITE_INITIALE * sizeof(int));
    col->taille = 0;
    col->capacite = CAPACITE_INITIALE;
    return col;
}

void ajouter_valeur(COLONNE *col, int valeur) {
    if (col->taille == col->capacite) {
        col->capacite *= 2;
        col->valeurs = (int *)realloc(col->valeurs, col->capacite * sizeof(int));
    }
    col->valeurs[col->taille++] = valeur;
}

void supprimer_valeur_a(COLONNE *col, int index) {
    if (index < 0 || index >= col->taille) return;
    for (int i = index; i < col->taille - 1; i++) {
        col->valeurs[i] = col->valeurs[i + 1];
    }
    col->taille--;
}

void afficher_colonne(const COLONNE *col) {
    if (!col) return;
    printf("Titre de la colonne : %s\n", col->titre);
    for (int i = 0; i < col->taille; i++) {
        printf("%d ", col->valeurs[i]);
    }
    printf("\n");
}

int obtenir_valeur_a(const COLONNE *col, int index) {
    if (index < 0 || index >= col->taille) return -1; // Retourne -1 si l'index est hors limites
    return col->valeurs[index];
}

int compter_occurrences(const COLONNE *col, int x) {
    int compteur = 0;
    for (int i = 0; i < col->taille; i++) {
        if (col->valeurs[i] == x) compteur++;
    }
    return compteur;
}

int compter_superieures_a(const COLONNE *col, int x) {
    int compteur = 0;
    for (int i = 0; i < col->taille; i++) {
        if (col->valeurs[i] > x) compteur++;
    }
    return compteur;
}

int compter_inferieures_a(const COLONNE *col, int x) {
    int compteur = 0;
    for (int i = 0; i < col->taille; i++) {
        if (col->valeurs[i] < x) compteur++;
    }
    return compteur;
}

int compter_egales_a(const COLONNE *col, int x) {
    return compter_occurrences(col, x);
}

void trier_colonne(COLONNE *col) {
    if (!col || col->taille < 2) return;
    for (int i = 0; i < col->taille - 1; i++) {
        for (int j = 0; j < col->taille - i - 1; j++) {
            if (col->valeurs[j] > col->valeurs[j + 1]) {
                int temp = col->valeurs[j];
                col->valeurs[j] = col->valeurs[j + 1];
                col->valeurs[j + 1] = temp;
            }
        }
    }
}

void mettre_a_jour_index(COLONNE *col) {
    trier_colonne(col);
}

int rechercher_valeur_dans_colonne(COLONNE *col, int val) {
    if (!col || col->taille == 0) return 0;
    trier_colonne(col);
    int debut = 0, fin = col->taille - 1;
    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;
        if (col->valeurs[milieu] == val) {
            return 1; // Valeur trouvée
        } else if (col->valeurs[milieu] < val) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }
    return 0; // Valeur non trouvée
}

void supprimer_colonne(COLONNE **col) {
    if (*col) {
        free((*col)->titre);
        free((*col)->valeurs);
        free(*col);
        *col = NULL;
    }
}

void renommer_colonne(COLONNE *col, const char *nouveau_titre) {
    if (col) {
        free(col->titre);
        col->titre = strdup(nouveau_titre);
    }
}

void remplacer_valeur(COLONNE *col, int index, int nouvelle_valeur) {
    if (index < 0 || index >= col->taille) return;
    col->valeurs[index] = nouvelle_valeur;
}
