#include "sort.h"
#include "column.h"
#include "cdataframe.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    CDATAFRAME* cdf=NULL;
    int answer=0;
    int answer_part1=0;
    int answer_part2 = 0;
    int answer_part3 = 0;
    int answer_part4 = 0;
    char str[32];
    int nb_col,nb_line;
    printf("######################################### \n");
    printf("#           Projet CDataFrame           # \n");
    printf("######################################### \n");
    printf("\n");
    printf("\n");
    printf("Bonjour et bienvenue dans ce programme. Choisissez l option que vous souhaitez. \n");
    printf("1 - Creation d'un Dataframe \n");
    printf("2 - Options d affichage \n");
    printf("3 - Operations usuelles \n");
    printf("4 - Analyses et statistiques \n");
    printf("5 - Arreter le programme \n");
    printf("\n");
    while (answer < 1 || answer > 5){
        printf("Entrez votre choix : \n");
        scanf("%d", &answer);
        printf("\n");
    }
    switch (answer){

        case 1:
            printf("############################# \n");
            printf("#  Creation d un DataFrame  # \n");
            printf("############################# \n");
            printf("\n");
            printf("\n");
            printf("1 - Remplir le DataFrame par vos soins \n");
            printf("2 - Remplir le DataFrame a l aide de valeurs predefinies (entieres) \n");
            printf("3 - Retour au precedent menu \n");
            printf("\n");
            printf("\n");
            while ((answer_part1 < 1) || (answer_part1 > 3)){
                printf("Veuillez votre choix : \n");
                scanf("%d", &answer_part1);
                printf("\n");
            }
            switch (answer_part1){
                case 1:
                    cdf=create_cdf_user();
                    answer = 0; // permet de revenir en toute sécurité au menu précédent (principal)
                    break;
                case 2:
                    cdf=create_cdf_program();
                    answer = 0;
                    break;
                case 3:
                    answer = 0;
                    answer_part1 = 0;
                    break;
            }
            break;

        case 2:
            printf("############################# \n");
            printf("#    Options d affichage    # \n");
            printf("############################# \n");
            printf("\n");
            printf("\n");
            printf("1 - Afficher tout le DataFrame \n");
            printf("2 - Afficher seulement certaine(s) ligne(s) du DataFrame \n");
            printf("3 - Afficher une colonne du dataframe \n");
            printf("4 - Retour au precedent menu \n");
            printf("\n");
            printf("\n");
            while (answer_part2 < 1 || answer_part2 > 4)
            {
                printf("Veuillez entrer votre choix : \n");
                scanf("%d", &answer_part2);
                printf("\n");
            }
            switch(answer_part2){
                case 1:
                    display_dataframe(cdf);
                    answer = 0;
                    answer_part2 = 0;
                    break;
                case 2:
                    display_lines(cdf);
                    answer = 0;
                    answer_part2 = 0;
                    break;
                case 3:
                    display_columns(cdf);
                    answer = 0;
                    answer_part2 = 0;
                    break;
                case 4:
                    answer = 0;
                    answer_part2 = 0;
                    break;
            }
            break;

        case 3:
            printf("############################# \n");
            printf("#    Operations usuelles    # \n");
            printf("############################# \n");
            printf("\n");
            printf("\n");
            printf("1 - Ajouter une ligne de valeurs au DataFrame \n");
            printf("2 - Supprimer une ligne de valeurs au DataFrame \n");
            printf("3 - Ajouter une colonne au DataFrame \n");
            printf("4 - Supprimer une colonne au DataFrame \n");
            printf("5 - Renommer le titre d une colonne dans le DataFrame \n");
            printf("6 - Verifier l existence d une valeur dans le DataFrame \n");
            printf("7 - Remplacer la valeur se trouvant dans une cellule du DataFrame \n");
            printf("8 - Afficher le nom de chaque colonne \n");
            printf("9 - Retour au menu precedent \n");
            printf("\n");
            printf("\n");
            while (answer_part3 < 1 || answer_part3 > 9)
            {
                printf("Veuillez entrer votre choix : \n");
                scanf("%d", &answer_part3);
                printf("\n");
            }
            switch(answer_part3){
                case 1:
                    append_line_dataframe(cdf);
                    answer = 0;
                    answer_part3 = 0;
                    break;
                case 2:
                    delete_cdf_line(cdf);
                    answer = 0;
                    answer_part3 = 0;
                    break;
                case 3:
                    append_column_dataframe(cdf);
                    answer = 0;
                    answer_part3 = 0;
                    break;
                case 4:
                    printf("Entrez le nom de la colonne que vous souhaitez supprimer du DataFrame : \n");
                    scanf(" %s",str);
                    delete_column_cdf(cdf,str);
                    answer = 0;
                    answer_part3 = 0;
                    break;
                case 5:
                    print_col_names(cdf);
                    printf("Entrez le nom de la colonne que vous souhaitez renommer : \n");
                    scanf(" %s",str);
                    rename_col(cdf,str);
                    answer = 0;
                    answer_part3 = 0;
                    break;
                case 6:
                    char val[20];
                    printf("Veuillez entrer la valeur que vous souhaitez rechercher dans le DataFrame : \n");
                    scanf(" %s", val);
                    cellexist_cdataframe(cdf,val);
                    answer = 0;
                    answer_part3 = 0;
                    break;
                case 7:
                    replace_value_cdf(cdf);
                    answer = 0;
                    answer_part3 = 0;
                    break;
                case 8:
                    print_col_names(cdf);
                    answer = 0;
                    answer_part3 = 0;
                    break;
                case 9:
                    answer = 0;
                    answer_part3 = 0;
                    break;
            }
            break;

        case 4:
            printf("############################# \n");
            printf("#  Analyses et statistiques # \n");
            printf("############################# \n");
            printf("\n");
            printf("\n");
            printf("1 - Afficher le nombre de colonnes \n");
            printf("2 - Afficher le nombre de lignes \n");
            printf("3 - Afficher le nombre de cellules egales à une valeur donnee \n");
            printf("4 - Afficher le nombre de cellules superieures à une valeur donnee \n");
            printf("5 - Afficher le nombre de cellules inferieures à une valeur donnee \n");
            printf("6 - Retour au menu precedent \n");
            printf("\n");
            printf("\n");
            while (answer_part4 < 1 || answer_part4 > 6){
                printf("Veuillez entrer votre choix : \n");
                scanf("%d", &answer_part4);
                printf("\n");
            }
            switch (answer_part4){
                case 1:
                    nb_col = column_number(cdf);
                    answer = 0;
                    answer_part4 = 0;
                    break;
                case 2:
                    nb_line = line_number(cdf);
                    answer = 0;
                    answer_part4 = 0;
                    break;
                case 3:
                    printf("Veuillez entrer la valeur dont vous souhaitez connaitre le nombre de cellules "
                           "egales à cette valeur : \n");
                    scanf(" %s", str);
                    cellsequal_cdataframe(cdf,str);
                    answer = 0;
                    answer_part4 = 0;
                    break;
                case 4:
                    printf("Veuillez entrer la valeur dont vous souhaitez connaitre le nombre de cellules "
                           "superieures à cette valeur : \n");
                    scanf(" %s", str);
                    cellssup_cdataframe(cdf,str);
                    answer = 0;
                    answer_part4 = 0;
                    break;
                case 5:
                    printf("Veuillez entrer la valeur dont vous souhaitez connaitre le nombre de cellules "
                           "inferieures à cette valeur : \n");
                    scanf(" %s", str);
                    cellsinf_cdataframe(cdf,str);
                    answer = 0;
                    answer_part4 = 0;
                    break;
                case 6:
                    answer = 0;
                    answer_part4 = 0;
                    break;
            }
            break;
    }
    return 0;
}

