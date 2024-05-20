#include <stdio.h>
#include <stdlib.h>
#include "dataframe.h"

// Fonction pour créer un nouveau dataframe
DATAFRAME *creer_dataframe() {
    // Alloue de la mémoire pour le dataframe
    DATAFRAME *df = (DATAFRAME *)malloc(sizeof(DATAFRAME));
    // Initialise les pointeurs de tête et de queue à NULL
    df->tete = NULL;
    df->queue = NULL;
    return df; 
}

// Fonction pour ajouter une colonne au dataframe
void ajouter_colonne_dataframe(DATAFRAME *df, COLONNE *col) {
    // Alloue de la mémoire pour un nouveau nœud de colonne
    NOEUD_COLONNE *nouveau_noeud = (NOEUD_COLONNE *)malloc(sizeof(NOEUD_COLONNE));
    // Affecte la colonne donnée au nouveau nœud
    nouveau_noeud->col = col;
    // Initialise les pointeurs suivant et précédent du nouveau nœud
    nouveau_noeud->suivant = NULL;
    nouveau_noeud->precedent = df->queue;

    // Vérifie si la queue du dataframe existe
    if (df->queue) {
        // Si oui, relie le nouveau nœud à la queue existante
        df->queue->suivant = nouveau_noeud;
    } else {
        // Sinon, le nouveau nœud devient la tête du dataframe
        df->tete = nouveau_noeud;
    }
    // Met à jour la queue pour pointer vers le nouveau nœud
    df->queue = nouveau_noeud;
}

// Fonction pour supprimer une colonne du dataframe à un index donné
void supprimer_colonne_a(DATAFRAME *df, int index) {
    // Vérifie si le dataframe est valide et si l'index est positif
    if (!df || index < 0) 
        return;

    // Initialise un pointeur vers le nœud actuel
    NOEUD_COLONNE *actuel = df->tete;
    // Parcourt les nœuds jusqu'à atteindre l'index ou la fin du dataframe
    for (int i = 0; actuel && i < index; i++) {
        actuel = actuel->suivant;
    }
    // Si aucun nœud n'a été trouvé à l'index donné, ou si le dataframe est vide, retourne
    if (!actuel) 
        return;

    // Relie le nœud précédent du nœud actuel avec son nœud suivant
    if (actuel->precedent) {
        actuel->precedent->suivant = actuel->suivant;
    } else {
        df->tete = actuel->suivant;
    }

    // Relie le nœud suivant du nœud actuel avec son nœud précédent
    if (actuel->suivant) {
        actuel->suivant->precedent = actuel->precedent;
    } else {
        df->queue = actuel->precedent;
    }

    // Libère la mémoire occupée par la colonne du nœud actuel
    supprimer_colonne(&(actuel->col));
    // Libère la mémoire occupée par le nœud actuel
    free(actuel);
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
    int max_lignes = nombre_de_lignes(df);

    // Affiche les valeurs
    for (int i = 0; i < max_lignes; i++) {
        actuel = df->tete;
        while (actuel) {
            if (i < actuel->col->taille) {
                printf("%d\t", actuel->col->valeurs[i]);
            } else {
                printf("\t");
            }
            actuel = actuel->suivant;
        }
        printf("\n");
    }
}

// Fonction pour libérer la mémoire occupée par le dataframe
void liberer_dataframe(DATAFRAME **df) {
    // Vérifie si le dataframe existe
    if (*df) {
        // Initialise un pointeur vers le nœud actuel
        NOEUD_COLONNE *actuel = (*df)->tete;
        // Parcourt tous les nœuds du dataframe
        while (actuel) {
            // Garde une référence au prochain nœud
            NOEUD_COLONNE *suivant = actuel->suivant;
            // Libère la mémoire occupée par la colonne du nœud actuel
            supprimer_colonne(&(actuel->col));
            // Libère la mémoire occupée par le nœud actuel
            free(actuel);
            // Passe au prochain nœud
            actuel = suivant;
        }
        // Libère la mémoire occupée par le dataframe lui-même
        free(*df);
        // Affecte NULL au pointeur de dataframe pour éviter les fuites de mémoire
        *df = NULL;
    }
}

// Fonction pour ajouter une ligne de valeurs au dataframe
void ajouter_ligne_dataframe(DATAFRAME *df, int *valeurs) {
    // Vérifie si le dataframe et les valeurs sont valides
    if (!df || !valeurs) 
        return;

    // Initialise un pointeur vers le nœud actuel
    NOEUD_COLONNE *actuel = df->tete;
    int index = 0;
    // Parcourt tous les nœuds du dataframe
    while (actuel) {
        // Ajoute la valeur correspondante à la colonne du nœud actuel
        ajouter_valeur_colonne(actuel->col, valeurs[index++]);
        // Passe au prochain nœud
        actuel = actuel->suivant;
    }
}

// Fonction pour supprimer une ligne de valeurs du dataframe à un index donné
void supprimer_ligne(DATAFRAME *df, int index) {
    // Vérifie si le dataframe est valide
    if (!df) 
        return;

    // Initialise un pointeur vers le nœud actuel
    NOEUD_COLONNE *actuel = df->tete;
    // Parcourt tous les nœuds du dataframe
    while (actuel) {
        // Supprime la valeur à l'index donné de la colonne du nœud actuel
        supprimer_valeur_a_colonne(actuel->col, index);
        // Passe au prochain nœud
        actuel = actuel->suivant;
    }
}

// Fonction pour obtenir la valeur à une position donnée dans le dataframe
int obtenir_valeur(DATAFRAME *df, int ligne, int colonne) {
    // Vérifie si le dataframe est valide
    if (!df) 
        return -1;

    // Initialise un pointeur vers le nœud actuel
    NOEUD_COLONNE *actuel = df->tete;
    // Parcourt les nœuds jusqu'à atteindre la colonne demandée
    for (int i = 0; actuel && i < colonne; i++) {
        actuel = actuel->suivant;
    }
    // Si la colonne demandée n'existe pas, retourne -1
    if (!actuel) 
        return -1;

    // Renvoie la valeur à la position donnée dans la colonne du nœud actuel
    return obtenir_valeur_a_colonne(actuel->col, ligne);
}

// Fonction pour remplacer une valeur à une position donnée dans le dataframe
void remplacer_valeur_df(DATAFRAME *df, int ligne, int colonne, int nouvelle_valeur) {
    // Vérifie si le dataframe est valide
    if (!df) 
        return;

    // Initialise un pointeur vers le nœud actuel
    NOEUD_COLONNE *actuel = df->tete;
    // Parcourt les nœuds jusqu'à atteindre la colonne demandée
    for (int i = 0; actuel && i < colonne; i++) {
        actuel = actuel->suivant;
    }
    // Si la colonne demandée n'existe pas, retourne
    if (!actuel) 
        return;

    // Remplace la valeur à la position donnée dans la colonne du nœud actuel
    remplacer_valeur_colonne(actuel->col, ligne, nouvelle_valeur);
}

// Fonction pour obtenir le nombre de lignes du dataframe
int nombre_de_lignes(const DATAFRAME *df) {
    // Vérifie si le dataframe est valide
    if (!df) 
        return 0;

    // Initialise une variable pour stocker le nombre maximum de lignes
    int max_lignes = 0;
    // Initialise un pointeur vers le nœud actuel
    NOEUD_COLONNE *actuel = df->tete;
    // Parcourt tous les nœuds du dataframe
    while (actuel) {
        // Met à jour le nombre maximum de lignes si nécessaire
        if (actuel->col->taille > max_lignes) {
            max_lignes = actuel->col->taille;
        }
        // Passe au prochain nœud
        actuel = actuel->suivant;
    }
    return max_lignes;
}

// Fonction pour obtenir le nombre de colonnes du dataframe
int nombre_de_colonnes(const DATAFRAME *df) {
    // Vérifie si le dataframe est valide
    if (!df) 
        return 0;

    // Initialise un compteur pour le nombre de colonnes
    int compteur = 0;
    // Initialise un pointeur vers le nœud actuel
    NOEUD_COLONNE *actuel = df->tete;
    // Parcourt tous les nœuds du dataframe
    while (actuel) {
        // Incrémente le compteur de colonnes
        compteur++;
        // Passe au prochain nœud
        actuel = actuel->suivant;
    }
    return compteur;
}

// Fonction pour afficher les noms des colonnes du dataframe
void afficher_noms_colonnes(const DATAFRAME *df) {
    // Vérifie si le dataframe est valide
    if (!df) 
        return;

    // Initialise un pointeur vers le nœud actuel
    NOEUD_COLONNE *actuel = df->tete;
    // Parcourt tous les nœuds du dataframe
    while (actuel) {
        // Affiche le titre de la colonne du nœud actuel
        printf("%s\n", actuel->col->titre);
        // Passe au prochain nœud
        actuel = actuel->suivant;
    }
}

