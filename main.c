#include <stdio.h>
#include "dataframe.h"

int main() {
    // Creation d'un dataframe vide
    DATAFRAME *df = creer_dataframe();

    // Remplissage de la premiere colonne
    COLONNE *col1 = creer_colonne("Colonne 1");
    ajouter_valeur_colonne(col1, 5);
    ajouter_valeur_colonne(col1, 10);
    ajouter_valeur_colonne(col1, 15);

    // Remplissage de la deuxieme colonne
    COLONNE *col2 = creer_colonne("Colonne 2");
    ajouter_valeur_colonne(col2, 3);
    ajouter_valeur_colonne(col2, 6);
    ajouter_valeur_colonne(col2, 9);

    // Remplissage de la deuxieme colonne
    COLONNE *col3 = creer_colonne("Colonne 3");
    ajouter_valeur_colonne(col3, 1);
    ajouter_valeur_colonne(col3, 2);

    // Ajout des colonnes au dataframe
    ajouter_colonne_dataframe(df, col1);
    ajouter_colonne_dataframe(df, col2);
    ajouter_colonne_dataframe(df, col3);

    // Affichage initial du dataframe
    printf("Dataframe initial:\n");
    afficher_dataframe(df);

    // Saisie utilisateur d'une valeur dans la colonne 3
    int val;
    printf("Ajouter une valeur a la colonne 3 :\n");
    scanf("%d", &val);
    ajouter_valeur_colonne(col3, val);
    afficher_dataframe(df);

    // Affichage limité des lignes
    printf("\nAfficher les deux premieres lignes:\n");
    afficher_lignes_limite_dataframe(df, 2);

    // Affichage limité des colonnes
    printf("\nAfficher les deux premieres colonnes:\n");
    afficher_colonnes_limite_dataframe(df, 2);

    // Ajout d'une ligne de valeurs
    printf("Ajout d'une ligne de valeurs:\n");
    int valeurs_ligne[] = {20, 21, 22};
    ajouter_ligne_dataframe(df, valeurs_ligne);
    afficher_dataframe(df);

    // Suppression de la deuxieme ligne
    printf("Suppression de la ligne 2:\n");
    supprimer_ligne_dataframe(df, 1);
    afficher_dataframe(df);

    // Affichage du nombre de lignes et de colonnes
    printf("Nombre de lignes: %d\n", nombre_de_lignes_dataframe(df));
    printf("Nombre de colonnes: %d\n", nombre_de_colonnes_dataframe(df));

    // Suppression de la colonne 1
    printf("Suppression de la colonne 1:\n");
    supprimer_colonne_a_dataframe(df, 0);
    afficher_dataframe(df);

    // Changement de nom de la deuxieme colonne
    printf("Renommage de la colonne 2:\n");
    renommer_colonne(col2, "Nouvelle Colonne 2");
    afficher_dataframe(df);

    // Changement de valeur du dataframe a la case (0,0)
    printf("Remplacement de la valeur en (0,0):\n");
    remplacer_valeur_dataframe(df, 0, 0, 42);
    afficher_dataframe(df);

    // Statistiques sur des valeurs donnees, superieur / inferieur / egale
    printf("Nombre de valeurs egales a 42 : %d\n", nombre_valeurs_egales_a_x(df, 42));
    printf("Nombre de valeurs superieures a 5 : %d\n", nombre_valeurs_sup_a_x(df, 5));
    printf("Nombre de valeurs inferieures a 10 : %d\n", nombre_valeurs_inf_a_x(df, 10));

    printf("Voici la valeur dans la cellule (x = 0 , y = 0) : %d ", obtenir_valeur_dataframe(df, 0,0));

    liberer_dataframe(&df);

    return 0;
}