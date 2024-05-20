#include <stdio.h>
#include "dataframe.h"

// Ceci est le fichier principal pour tester les fonctionnalités du dataframe

int main() {
    // Création du dataframe
    DATAFRAME *df = creer_dataframe();

    // Ajout des colonnes
    COLONNE *col1 = creer_colonne("Colonne1");
    COLONNE *col2 = creer_colonne("Colonne2");
    ajouter_colonne_dataframe(df, col1);
    ajouter_colonne_dataframe(df, col2);

    // Ajout des lignes
    int ligne1[] = {1, 2};
    int ligne2[] = {3, 4};
    ajouter_ligne_dataframe(df, ligne1);
    ajouter_ligne_dataframe(df, ligne2);

    // Affichage du dataframe
    printf("Dataframe initial:\n");
    afficher_dataframe(df);

    // Affichage limité des lignes
    printf("\nAfficher les deux premières lignes:\n");
    afficher_lignes_limite_dataframe(df, 2);

    // Affichage limité des colonnes
    printf("\nAfficher les deux premières colonnes:\n");
    afficher_colonnes_limite_dataframe(df, 2);

    // Test des fonctions pour les valeurs supérieures, inférieures ou égales à 2
    int x = 2;
    printf("\nNombre de valeurs supérieures à %d : %d\n", x, nombre_valeurs_sup_a_x(df, x));
    printf("Nombre de valeurs inférieures à %d : %d\n", x, nombre_valeurs_inf_a_x(df, x));
    printf("Nombre de valeurs égales à %d : %d\n", x, nombre_valeurs_egales_a_x(df, x));

    // Libération de la mémoire
    liberer_dataframe(&df);

    return 0;
}
