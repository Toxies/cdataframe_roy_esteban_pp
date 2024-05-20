#ifndef COLONNE_H
#define COLONNE_H

typedef struct colonne {
    char *titre;
    int *valeurs;
    int taille;
    int capacite;
} COLONNE;

// Fonctions de gestion de colonne
COLONNE *creer_colonne(char *titre);
void ajouter_valeur(COLONNE *col, int valeur);
void supprimer_valeur_a(COLONNE *col, int index);
void afficher_colonne(const COLONNE *col);
void trier_colonne(COLONNE *col);
int obtenir_valeur_a(const COLONNE *col, int index);
int compter_occurrences(const COLONNE *col, int x);
int compter_supÃ©rieures_a(const COLONNE *col, int x);
int compter_inferieures_a(const COLONNE *col, int x);
int compter_egales_a(const COLONNE *col, int x);
void supprimer_colonne(COLONNE **col);
void mettre_a_jour_index(COLONNE *col);
int rechercher_valeur_dans_colonne(COLONNE *col, int val);
void renommer_colonne(COLONNE *col, const char *nouveau_titre);
void remplacer_valeur(COLONNE *col, int index, int nouvelle_valeur);

#endif // COLONNE_H
