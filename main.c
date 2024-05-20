#include <stdio.h>
#include <stdlib.h>
#include "dataframe.h"

int main() {
    DATAFRAME *df = creer_dataframe();

    COLONNE *col1 = creer_colonne("Colonne 1");
    ajouter_valeur_colonne(col1, 5);
    ajouter_valeur_colonne(col1, 10);
    ajouter_valeur_colonne(col1, 15);

    COLONNE *col2 = creer_colonne("Colonne 2");
    ajouter_valeur_colonne(col2, 3);
    ajouter_valeur_colonne(col2, 6);
    ajouter_valeur_colonne(col2, 9);

    COLONNE *col3 = creer_colonne("Colonne 3");
    ajouter_valeur_colonne(col3, 1);
    ajouter_valeur_colonne(col3, 2);

    ajouter_colonne_dataframe(df, col1);
    ajouter_colonne_dataframe(df, col2);
    ajouter_colonne_dataframe(df, col3);

    printf("Dataframe initial:\n");
    afficher_dataframe(df);

    printf("Ajout d'une ligne de valeurs:\n");
    int valeurs_ligne[] = {20, 21, 22};
    ajouter_ligne_dataframe(df, valeurs_ligne);
    afficher_dataframe(df);

    printf("Suppression de la ligne 2:\n");
    supprimer_ligne(df, 1);
    afficher_dataframe(df);

    printf("Nombre de lignes: %d\n", nombre_de_lignes(df));
    printf("Nombre de colonnes: %d\n", nombre_de_colonnes(df));

    printf("Suppression de la colonne 1:\n");
    supprimer_colonne_a(df, 0);
    afficher_dataframe(df);

    printf("Renommage de la colonne 2:\n");
    renommer_colonne(col2, "Nouvelle Colonne 2");
    afficher_dataframe(df);

    printf("Remplacement de la valeur en (0,0):\n");
    remplacer_valeur_df(df, 0, 0, 42);
    afficher_dataframe(df);

    printf("Nombre de valeurs egales a 42 : %d\n", nombre_valeurs_egales_a(col2, 42)+nombre_valeurs_egales_a(col3, 42));
    printf("Nombre de valeurs superieures a 5 : %d\n", nombre_valeurs_sup_a(col2, 5)+nombre_valeurs_sup_a(col2, 5));
    printf("Nombre de valeurs inferieures a 10 : %d\n", nombre_valeurs_inf_a(col2, 10)+nombre_valeurs_inf_a(col2, 10));

    liberer_dataframe(&df);

    return 0;
}
