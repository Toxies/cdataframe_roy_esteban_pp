#ifndef COLONNE_H
#define COLONNE_H

// Ceci est le fichier d'en-tête pour les colonnes dans un dataframe
// On déclare ici les structures et les fonctions pour gérer une colonne

typedef struct colonne {
    char *titre;       // Le nom de la colonne
    int *valeurs;      // Les valeurs dans la colonne
    int taille;        // Le nombre d'éléments dans la colonne
} COLONNE;

COLONNE *creer_colonne(const char *titre); // Fonction pour créer une nouvelle colonne
void supprimer_colonne(COLONNE **col); // Fonction pour supprimer une colonne
void ajouter_valeur_colonne(COLONNE *col, int valeur); // Fonction pour ajouter une valeur à la colonne
void supprimer_valeur_a_colonne(COLONNE *col, int index); // Fonction pour supprimer une valeur à un index donné
void trier_colonne(COLONNE *col); // Fonction pour trier les valeurs de la colonne
void renommer_colonne(COLONNE *col, const char *nouveau_titre); // Fonction pour renommer la colonne
void remplacer_valeur_colonne(COLONNE *col, int index, int nouvelle_valeur); // Fonction pour remplacer une valeur à un index donné
int obtenir_valeur_a_colonne(COLONNE *col, int index); // Fonction pour obtenir une valeur à un index donné
int nombre_occurrences_valeur(COLONNE *col, int valeur); // Fonction pour compter le nombre d'occurrences d'une valeur
int nombre_valeurs_sup_a(COLONNE *col, int valeur); // Fonction pour compter le nombre de valeurs supérieures à une valeur donnée
int nombre_valeurs_inf_a(COLONNE *col, int valeur); // Fonction pour compter le nombre de valeurs inférieures à une valeur donnée
int nombre_valeurs_egales_a(COLONNE *col, int valeur); // Fonction pour compter le nombre de valeurs égales à une valeur donnée

#endif // COLONNE_H
