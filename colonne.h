#ifndef COLONNE_H
#define COLONNE_H

// Ceci est le fichier d'en-tête pour les colonnes
// On y définit la structure et les fonctions pour gérer une colonne

typedef struct {
    char *titre;
    int *valeurs;
    int taille;
    int capacite;
} COLONNE;

COLONNE *creer_colonne(const char *titre); // Fonction pour créer une colonne
void supprimer_colonne(COLONNE **col); // Fonction pour supprimer une colonne
void ajouter_valeur_colonne(COLONNE *col, int valeur); // Fonction pour ajouter une valeur à une colonne
int obtenir_valeur_colonne(const COLONNE *col, int index); // Fonction pour obtenir une valeur à un index donné
void supprimer_valeur_a_colonne(COLONNE *col, int index); // Fonction pour supprimer une valeur à un index donné
void renommer_colonne(COLONNE *col, const char *nouveau_titre); // Fonction pour renommer la colonne
int nombre_valeurs_sup_a_colonne(const COLONNE *col, int x); // Fonction pour compter les valeurs supérieures à x dans une colonne
int nombre_valeurs_inf_a_colonne(const COLONNE *col, int x); // Fonction pour compter les valeurs inférieures à x dans une colonne
int nombre_valeurs_egales_a_colonne(const COLONNE *col, int x); // Fonction pour compter les valeurs égales à x dans une colonne

#endif // COLONNE_H
