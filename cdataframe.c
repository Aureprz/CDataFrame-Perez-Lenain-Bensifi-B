#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

#define MAX_SIZE 32

// 1. Alimentation

CDATAFRAME *create_empty_cdataframe(ENUM_TYPE *cdftype,unsigned int size){
    CDATAFRAME  *cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    cdf->list = lst_create_list();
    cdf->list_type =  cdftype;
    cdf->size = size;
    return cdf;
}


CDATAFRAME* create_cdf_user(){
    int size = 0;
    int value = 0;
    int i;
    char* title[MAX_SIZE];
    CDATAFRAME* cdf;
    COLUMN* col = NULL;
    lnode* newnode = NULL;
    do{
        printf("Veuillez saisir le nombre de colonnes du CDataFrame : \n");
        scanf("%d", &size);
    }while(size <= 0);
    ENUM_TYPE list_type[size];
    for( i=0; i < size; i++){
        printf("============ Colonne [%d] ============\n",i+1);
        do {
            printf("Veuillez saisir le type de la colonne %d : \n", i+1);
            printf("UINT[1], INT[2], CHAR[3], FLOAT[4], DOUBLE[5], STRING[6], STRUCTURE[7]\n");
            scanf(" %d", &value);
        } while ((value <=0) || (value>=8));
        list_type[i] = value+1; // because NULLVAL isn't that useful
    }
    cdf = create_empty_cdataframe(list_type, size);
    for ( i = 0 ; i < size ; i++){
        printf("Choisissez un titre pour la colonne %d : \n",i+1);
        scanf(" %s", *title);
        col = create_column(*cdf->list_type,*title);
        newnode = lst_create_lnode(col);
        lst_insert_tail(cdf->list, newnode);
    }
    return cdf;
}


int cellexist_cdataframe(CDATAFRAME* dataframe, void* value){
    int cpt = 0;
    if ((dataframe == NULL) || (dataframe->size == 0)){
        return cpt;
    }
    lnode* current = dataframe->list->head;

    while (current->next != NULL){
        cpt += exist_col(current->data, value);
        if (cpt> 0){
            return cpt;
        }
        current = get_next_node(dataframe->list, current);
    }
    cpt += exist_col(current->data, value);
    return cpt;
}


int cellsequal_cdataframe(CDATAFRAME* dataframe, void* value){
    int cpt = 0;
    if ((dataframe == NULL) || (dataframe->size == 0)){
        return cpt;
    }
    lnode* current = dataframe->list->head;

    while (current->next != NULL){
        cpt += cellsequal_col(current->data, value);
        current = get_next_node(dataframe->list, current);
    }
    cpt += cellsequal_col(current->data, value);
    return cpt;
}



void rename_col(CDATAFRAME* cdf, char* title_replaced) {
    lnode *current = cdf->list->head;
    COLUMN *col = NULL;
    int i;
    char *str = (char *) malloc(sizeof(char));
    printf("Choisissez un nouveau nom de colonne : \n");
    scanf(" %s", str);
    for (i = 0; i < cdf->size; i++) {
        col = current->data;
        if (strcmp(col->title, title_replaced) == 0) { // Compare les 2 chaînes de caractères
            col->title = str;
        }
    }
}


int cellsinf_cdataframe(CDATAFRAME* dataframe, void* value) {
    int cpt = 0;
    if ((dataframe == NULL) || (dataframe->size == 0)) {
        return cpt;
    }
    lnode *current = get_first_node(dataframe->list);
    if (current == NULL) {
        return cpt;
    }
    while (current->next != NULL) {
        cpt += cellsinf_col(current->data, value);
        current = get_next_node(dataframe->list, current);

    }
}

void print_col_names(CDATAFRAME* cdf){
    lnode* current = cdf->list->head;
    int i;
    COLUMN* col;
    while (current->next != NULL){
        col = current->data;
        printf("| %.20s |",col->title);
        current = current->next;
    }
}

void show_cdataframe(CDATAFRAME* dataframe){
    unsigned int i;
    if ((dataframe == NULL) || (dataframe->size == 0)) {
        return;
    }
    lnode *current = get_first_node(dataframe->list);
    if (current == NULL) {
        printf("Dataframe vide \n");
        return;
    }
    while (current->next != NULL) {
        print_col_names(dataframe);
        current->data;
        current = get_next_node(dataframe->list, current);
    }
    for (i = 0 ; i < dataframe->nb_line ; i++) {
        current = get_first_node(dataframe->list);
        while (current->next != NULL) {
            print_val_in_col(current->data, i);
            current = get_next_node(dataframe->list, current);
        }
    }
    printf("\n");
}

void delete_column_cdf(CDATAFRAME *cdf, char *col_name){
    if (cdf == NULL || col_name == NULL || cdf->list == NULL || cdf->list->head == NULL)
    {
        return;
    }

    lnode *node = cdf->list->head;
    COLUMN *col = NULL;
    dllist *list = cdf->list;

    while (node != NULL) {

        col = node->data;
        if (strcmp(col->title, col_name) == 0) {
            lst_delete_lnode(list, node);
            delete_column(&col);
            cdf->size--;
            return;
        }
        node = node->next;
    }

    printf("La colonne \" %s \" n'a pas été trouvée dans le dataframe. \n", col_name);
}

void delete_cdf_line(CDATAFRAME *cdf, int position){
    lnode *node = cdf->list->head;
    for (int i = 0 ; i < cdf->size ; i++){
        delete_value_column(node->data,position);
        node = node->next;
    }
}

void replace_value_cdf(CDATAFRAME *cdf, int row_location, int col_location){
    int i;
    unsigned int tmp = 0; // tmp will be used to keep the column size
    lnode *node = cdf->list->head;
    COLUMN *col = NULL;
    for (i = 0 ; i < col_location - 1 ; i++){
        node = node->next;
    }
    col = node->data;
    tmp = col->size;
    col->size = row_location - 1;
    printf("Saisissez la nouvelle valeur que vous souhaitez : \n");
    insert_user_val(col);
    col->size = tmp;
}