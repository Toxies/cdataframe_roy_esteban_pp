#include <stdio.h>
#include <stdlib.h>
#include "dataframe.h"

DATAFRAME *creer_dataframe() {
    DATAFRAME *df = (DATAFRAME *)malloc(sizeof(DATAFRAME));
    df->tete = NULL;
    df->queue = NULL;
    return df;
}

void ajouter_colonne(DATAFRAME *df, COLONNE *col) {
    NOEUD_COLONNE *nouveau_noeud = (NOEUD_COLONNE *)malloc(sizeof(NOEUD_COLONNE));
    nouveau_noeud->col = col;
    nouveau_noeud->suivant = NULL;
    nouveau_noeud->precedent = df->queue;

    if (df->queue) {
        df->queue->suivant = nouveau_noeud;
    } else {
        df->tete = nouveau_noeud;
    }

    df->queue = nouveau_noeud;
}

void supprimer_colonne_a(DATAFRAME *df, int index) {
    if (!df->tete) return;

    NOEUD_COLONNE *actuel = df->tete;

    for (int i = 0; actuel != NULL && i < index; i++) {
        actuel = actuel->suivant;
    }

    if (!actuel) return; // Index hors limites

    if (actuel->precedent) {
        actuel->precedent->suivant = actuel->suivant;
    } else {
        df->tete = actuel->suivant;
    }

    if (actuel->suivant) {
        actuel->suivant->precedent = actuel->precedent;
    } else {
        df->queue = actuel->precedent;
    }

    supprimer_colonne(&(actuel->col));
    free(actuel);
}

void afficher_dataframe(const DATAFRAME *df) {
    if (!df) return;

    // Afficher les titres des colonnes
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        printf("%s\t", actuel->col->titre);
        actuel = actuel->suivant;
    }
    printf("\n");

    // Trouver le nombre maximum de lignes
    int max_lignes = 0;
    actuel = df->tete;
    while (actuel) {
        if (actuel->col->taille > max_lignes) {
            max_lignes = actuel->col->taille;
        }
        actuel = actuel->suivant;
    }

    // Afficher les valeurs
    for (int i = 0; i < max_lignes; i++) {
        actuel = df->tete;
        while (actuel) {
            if (i < actuel->col->taille) {
                printf("\t%d\t", actuel->col->valeurs[i]);
            } else {
                printf("\t \t");
            }
            actuel = actuel->suivant;
        }
        printf("\n");
    }
}

void liberer_dataframe(DATAFRAME **df) {
    if (*df) {
        NOEUD_COLONNE *actuel = (*df)->tete;
        while (actuel) {
            NOEUD_COLONNE *suivant = actuel->suivant;
            supprimer_colonne(&(actuel->col));
            free(actuel);
            actuel = suivant;
        }
        free(*df);
        *df = NULL;
    }
}

void ajouter_ligne(DATAFRAME *df, int *valeurs) {
    if (!df || !valeurs) return;

    NOEUD_COLONNE *actuel = df->tete;
    int index = 0;
    while (actuel) {
        ajouter_valeur(actuel->col, valeurs[index++]);
        actuel = actuel->suivant;
    }
}

void supprimer_ligne(DATAFRAME *df, int index) {
    if (!df) return;

    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        supprimer_valeur_a(actuel->col, index);
        actuel = actuel->suivant;
    }
}

int obtenir_valeur(DATAFRAME *df, int ligne, int colonne) {
    if (!df) return -1;

    NOEUD_COLONNE *actuel = df->tete;
    for (int i = 0; actuel && i < colonne; i++) {
        actuel = actuel->suivant;
    }
    if (!actuel) return -1; // Colonne hors limites

    return obtenir_valeur_a(actuel->col, ligne);
}

void remplacer_valeur_df(DATAFRAME *df, int ligne, int colonne, int nouvelle_valeur) {
    if (!df) return;

    NOEUD_COLONNE *actuel = df->tete;
    for (int i = 0; actuel && i < colonne; i++) {
        actuel = actuel->suivant;
    }
    if (!actuel) return; // Colonne hors limites

    remplacer_valeur(actuel->col, ligne, nouvelle_valeur);
}

int nombre_de_lignes(const DATAFRAME *df) {
    if (!df) return 0;

    int max_lignes = 0;
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        if (actuel->col->taille > max_lignes) {
            max_lignes = actuel->col->taille;
        }
        actuel = actuel->suivant;
    }
    return max_lignes;
}

int nombre_de_colonnes(const DATAFRAME *df) {
    if (!df) return 0;

    int compteur = 0;
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        compteur++;
        actuel = actuel->suivant;
    }
    return compteur;
}

void afficher_noms_colonnes(const DATAFRAME *df) {
    if (!df) return;

    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        printf("%s\t", actuel->col->titre);
        actuel = actuel->suivant;
    }
    printf("\n");
}
