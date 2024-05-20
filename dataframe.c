#include <stdio.h>
#include <stdlib.h>
#include "dataframe.h"

// Ceci est le fichier d'implémentation pour les dataframes
// On implémente ici les fonctions pour gérer un dataframe

DATAFRAME *creer_dataframe() {
    DATAFRAME *df = (DATAFRAME *)malloc(sizeof(DATAFRAME)); // On alloue de la mémoire pour le dataframe
    df->tete = NULL; // On initialise la tête à NULL
    df->queue = NULL; // On initialise la queue à NULL
    return df; // On retourne le nouveau dataframe
}

void ajouter_colonne_dataframe(DATAFRAME *df, COLONNE *col) {
    NOEUD_COLONNE *nouveau_noeud = (NOEUD_COLONNE *)malloc(sizeof(NOEUD_COLONNE)); // On alloue de la mémoire pour un nouveau noeud
    nouveau_noeud->col = col; // On assigne la colonne au noeud
    nouveau_noeud->suivant = NULL; // Le noeud suivant est NULL
    nouveau_noeud->precedent = df->queue; // Le noeud précédent est la queue actuelle

    if (df->queue) {
        df->queue->suivant = nouveau_noeud; // Si la queue existe, on lie le noeud actuel à la queue
    } else {
        df->tete = nouveau_noeud; // Sinon, la tête devient le nouveau noeud
    }
    df->queue = nouveau_noeud; // La queue est mise à jour au nouveau noeud
}

void supprimer_colonne_a_dataframe(DATAFRAME *df, int index) {
    if (!df || index < 0) return;

    NOEUD_COLONNE *actuel = df->tete;
    int compteur = 0;
    while (actuel && compteur < index) {
        actuel = actuel->suivant;
        compteur++;
    }

    if (actuel) {
        if (actuel->precedent) {
            actuel->precedent->suivant = actuel->suivant; // On lie le noeud précédent au suivant
        } else {
            df->tete = actuel->suivant; // Sinon, la tête est mise à jour
        }

        if (actuel->suivant) {
            actuel->suivant->precedent = actuel->precedent; // On lie le noeud suivant au précédent
        } else {
            df->queue = actuel->precedent; // Sinon, la queue est mise à jour
        }

        supprimer_colonne(&actuel->col); // On supprime la colonne
        free(actuel); // On libère le noeud
    }
}

// Fonction pour afficher les valeurs du dataframe
void afficher_dataframe(const DATAFRAME *df) {
    // Vérifie si le dataframe est valide
    if (!df)
        return;

    // Affiche les titres des colonnes
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        printf("%s\t", actuel->col->titre);
        actuel = actuel->suivant;
    }
    printf("\n");

    // Trouve le nombre maximum de lignes
    int max_lignes = nombre_de_lignes_dataframe(df);

    // Affiche les valeurs
    for (int i = 0; i < max_lignes; i++) {
        actuel = df->tete;
        while (actuel) {
            if (i < actuel->col->taille) {
                printf("\t%d\t", actuel->col->valeurs[i]);
            } else {
                printf("\t");
            }
            actuel = actuel->suivant;
        }
        printf("\n");
    }
}

void liberer_dataframe(DATAFRAME **df) {
    if (!df || !*df) return;

    NOEUD_COLONNE *actuel = (*df)->tete;
    while (actuel) {
        NOEUD_COLONNE *suivant = actuel->suivant;
        supprimer_colonne(&actuel->col); // On supprime la colonne
        free(actuel); // On libère le noeud
        actuel = suivant;
    }

    free(*df); // On libère le dataframe
    *df = NULL; // On met le pointeur à NULL
}

void ajouter_ligne_dataframe(DATAFRAME *df, int *valeurs) {
    NOEUD_COLONNE *actuel = df->tete;
    int index = 0;
    while (actuel) {
        ajouter_valeur_colonne(actuel->col, valeurs[index++]);
        actuel = actuel->suivant;
    }
}

void supprimer_ligne_dataframe(DATAFRAME *df, int index) {
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        supprimer_valeur_a_colonne(actuel->col, index);
        actuel = actuel->suivant;
    }
}

int obtenir_valeur_dataframe(DATAFRAME *df, int ligne, int colonne) {
    NOEUD_COLONNE *actuel = df->tete;
    int index = 0;
    while (actuel && index < colonne) {
        actuel = actuel->suivant;
        index++;
    }

    if (actuel) {
        return obtenir_valeur_colonne(actuel->col, ligne);
    }

    return -1; // Valeur par défaut si la colonne n'existe pas
}

void remplacer_valeur_dataframe(DATAFRAME *df, int ligne, int colonne, int nouvelle_valeur) {
    NOEUD_COLONNE *actuel = df->tete;
    int index = 0;
    while (actuel && index < colonne) {
        actuel = actuel->suivant;
        index++;
    }

    if (actuel) {
        actuel->col->valeurs[ligne] = nouvelle_valeur;
    }
}

int nombre_de_lignes_dataframe(const DATAFRAME *df) {
    if (!df || !df->tete) return 0;
    return df->tete->col->taille;
}

int nombre_de_colonnes_dataframe(const DATAFRAME *df) {
    if (!df) return 0;

    int compteur = 0;
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        compteur++;
        actuel = actuel->suivant;
    }
    return compteur;
}

void afficher_noms_colonnes_dataframe(const DATAFRAME *df) {
    if (!df) return;

    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        printf("%s\t", actuel->col->titre);
        actuel = actuel->suivant;
    }
    printf("\n");
}

void afficher_lignes_limite_dataframe(const DATAFRAME *df, int limite) {
    if (!df) return;

    int lignes = nombre_de_lignes_dataframe(df);
    limite = (limite > lignes) ? lignes : limite;

    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        printf("%s\t", actuel->col->titre);
        actuel = actuel->suivant;
    }
    printf("\n");

    for (int i = 0; i < limite; i++) {
        actuel = df->tete;
        while (actuel) {
            printf("\t%d\t", obtenir_valeur_colonne(actuel->col, i));
            actuel = actuel->suivant;
        }
        printf("\n");
    }
}

void afficher_colonnes_limite_dataframe(const DATAFRAME *df, int limite) {
    if (!df) return;

    int colonnes = nombre_de_colonnes_dataframe(df);
    limite = (limite > colonnes) ? colonnes : limite;

    NOEUD_COLONNE *actuel = df->tete;
    for (int i = 0; i < limite && actuel; i++) {
        printf("%s\t", actuel->col->titre);
        actuel = actuel->suivant;
    }
    printf("\n");

    int lignes = nombre_de_lignes_dataframe(df);
    for (int i = 0; i < lignes; i++) {
        actuel = df->tete;
        for (int j = 0; j < limite && actuel; j++) {
            printf("\t%d\t", obtenir_valeur_colonne(actuel->col, i));
            actuel = actuel->suivant;
        }
        printf("\n");
    }
}

int nombre_valeurs_sup_a_x(const DATAFRAME *df, int x) {
    if (!df) return 0;

    int compteur = 0;
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        compteur += nombre_valeurs_sup_a_colonne(actuel->col, x);
        actuel = actuel->suivant;
    }
    return compteur;
}

int nombre_valeurs_inf_a_x(const DATAFRAME *df, int x) {
    if (!df) return 0;

    int compteur = 0;
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        compteur += nombre_valeurs_inf_a_colonne(actuel->col, x);
        actuel = actuel->suivant;
    }
    return compteur;
}

int nombre_valeurs_egales_a_x(const DATAFRAME *df, int x) {
    if (!df) return 0;

    int compteur = 0;
    NOEUD_COLONNE *actuel = df->tete;
    while (actuel) {
        compteur += nombre_valeurs_egales_a_colonne(actuel->col, x);
        actuel = actuel->suivant;
    }
    return compteur;
}
