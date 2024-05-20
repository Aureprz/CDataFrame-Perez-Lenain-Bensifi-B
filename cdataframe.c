#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>

#define MAX_SIZE 32

// 1. Alimentation

CDATAFRAME *create_empty_cdataframe(ENUM_TYPE* cdftype, int size){
    CDATAFRAME* cdf = NULL;
    cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
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

CDATAFRAME* create_cdf_program(){
    int size = 3;
    ENUM_TYPE cdftype = 3;
    lnode* node = NULL;
    COLUMN* col = NULL;
    CDATAFRAME* cdf = create_empty_cdataframe(&cdftype,size);
    char title[] = "Colonne";
    int i,j;
    int cpt=0;
    int val;
    for (i = 0 ; i < size ; i++){
        col = create_column(*cdf->list_type,title);
        cpt++;
        for (j = 0 ; j < 3 ; j++){
            val = j + cpt;
            col->data[col->size] = (COL_TYPE *) malloc(sizeof(int));
            *((int*)col->data[col->size]) = ((int)val);
        }
        node = lst_create_lnode(col);
        lst_insert_tail(cdf->list, node);
    }
    return cdf;
}



int cellexist_cdataframe(CDATAFRAME* cdf, void* value){
    int cpt=0;
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return cpt;
    }
    lnode* current = cdf->list->head;
    while (current->next != NULL){
        cpt += exist_col(current->data, value);
        if (cpt > 0){
            return cpt;
        }
        current = get_next_node(cdf->list, current);
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
    return cpt;
}

int cellssup_cdataframe(CDATAFRAME* dataframe, void* value) {
    int cpt = 0;
    if ((dataframe == NULL) || (dataframe->size == 0)) {
        return cpt;
    }
    lnode *current = get_first_node(dataframe->list);
    if (current == NULL) {
        return cpt;
    }
    while (current->next != NULL) {
        cpt += cellssup_col(current->data, value);
        current = get_next_node(dataframe->list, current);

    }
    return cpt;
}

void rename_col(CDATAFRAME* cdf, char* title_replaced){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
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

void print_col_names(CDATAFRAME* cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    lnode* current = cdf->list->head;
    COLUMN* col;
    while (current->next != NULL){
        col = current->data;
        printf("| %-20.20s |",col->title);
        current = current->next;
    }
}

void display_dataframe(CDATAFRAME* cdf){
    unsigned int i;
    if ((cdf == NULL) || cdf->list || cdf->size == 0) {
        printf("Dataframe vide \n");
        return;
    }
    lnode *current = get_first_node(cdf->list);
    while (current->next != NULL) {
        print_col_names(cdf);
        current->data;
        current = get_next_node(cdf->list, current);
    }
    for (i = 0 ; i < cdf->nb_line ; i++) {
        current = get_first_node(cdf->list);
        while (current->next != NULL) {
            print_val_in_col(current->data, i);
            current = get_next_node(cdf->list, current);
        }
    }
    printf("\n");
}

void delete_column_cdf(CDATAFRAME *cdf, char *col_name){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
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
    printf("La colonne \" %s \" n'a pas été trouvée dans le DataFrame. \n", col_name);
}

void delete_cdf_line(CDATAFRAME *cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    int pos=0;
    do{
        printf("Choisissez la position à laquelle vous souhaitez retirer une ligne : \n");
        scanf("%d",&pos);
    }while(pos<=0);
    lnode *node = cdf->list->head;
    for (int i = 0 ; i < cdf->size ; i++){
        delete_value_column(node->data,pos);
        node = node->next;
    }
}

int column_number(CDATAFRAME* cdf){
    int cpt=0;
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return cpt;
    }
    lnode* current = cdf->list->head;
    char* title = current->data->title;
    while (current->next != NULL){
        if (strlen(title) != 0){
            cpt++;
            current = current->next;
        }
    }
    return cpt;
}

int line_number(CDATAFRAME* cdf){
    int cpt=0;
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return cpt;
    }
    int i;
    COLUMN* col = cdf->list->head->data;
    for (i = 0 ; i < col->size ; i++){
        cpt++;
    }
    return cpt;
}

void replace_value_cdf(CDATAFRAME *cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    int i;
    unsigned int tmp; // tmp will be used to keep the column size
    lnode *node = cdf->list->head;
    COLUMN *col = NULL;
    int row_location=0;
    int col_location=0;
    do{
        printf("Choisissez la ligne où vous souhaitez remplacer la valeur : \n");
        scanf("%d",&row_location);
    }while(row_location<=0);
    do{
        printf("Choisissez la colonne où vous souhaitez remplacer la valeur : \n");
        scanf("%d",&col_location);
    }while(col_location<=0);
    if (col_location >= cdf->size){
        col_location = cdf->size;
    }
    for (i = 0 ; i < col_location - 1 ; i++){
        node = node->next;
    }
    col = node->data;
    tmp = col->size;
    col->size = row_location - 1;
    printf("Saisissez la nouvelle valeur que vous souhaitez : \n");
    insert_user_val(col);
    col->size = tmp;
    printf("La valeur a bien été remplacée.\n");
}

void append_column_dataframe(CDATAFRAME* cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    COLUMN* col;
    lnode* current = cdf->list->head;
    int pos;
    int i;
    col = create_col_user();
    lnode* node = lst_create_lnode(col);
    do{
        printf("Choisissez la position à laquelle vous souhaitez rajouter une colonne : \n");
        scanf("%d",&pos);
    }while(pos<=0);
    for (i = 0 ; i < cdf->size ; i++){
        current = current->next;
        if (pos == 1){
            lst_insert_head(cdf->list,node);
            return;
        }
        if (pos >= cdf->size){
            lst_insert_tail(cdf->list,node);
            return;
        }
        if (i+1 == pos){
            lst_insert_after(cdf->list,node,current);
            return;
        }
    }
    printf("La colonne \" %s \" a bien été ajoutée à la position %d dans le DataFrame.\n",col->title,pos);
}

void append_line_dataframe(CDATAFRAME *cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    int pos=0;
    do{
        printf("Choisissez la position à laquelle vous souhaitez rajouter une ligne : \n");
        scanf("%d",&pos);
    }while(pos<=0);
    lnode* node = cdf->list->head;
    COLUMN* col = node->data;
    int i;
    for (i = 0 ; i < cdf->size; i++){
        printf("Colonne \" %s \" \n",col->title);
        insert_user_val(col);
        node = node->next;
    }
    printf("La ligne a bien été ajoutée au DataFrame.\n");
}

void display_columns(CDATAFRAME* cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    lnode* current = cdf->list->head;
    COLUMN* col;
    int i;
    int start=0; int end=0;
    do{
        printf("Choisir la position de la colonne de départ : \n");
        scanf("%d",&start);
    }while(start<0);
    do{
        printf("Choisir la position de la colonne de fin : \n");
        scanf("%d",&end);
    }while(end<0);
    if (end >= cdf->size){
        end = cdf->size;
    }
    for (i = 0 ; i < start ; i++){
        current = current->next;
    }
    current = current->next;
    col = current->data;
    for (i = start ; i < end ; i++){
        printf("| %-20.20s |\n",col->title);
        print_col(col);
    }
}

void display_lines(CDATAFRAME* cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    lnode* current = cdf->list->head;
    COLUMN* col = current->data;
    unsigned long long int i;
    char str[32];
    int start=0; int end=0;
    do{
        printf("Choisir la position de la ligne de départ : \n");
        scanf("%d",&start);
    }while(start<0);
    do{
        printf("Choisir la position de la ligne de fin : \n");
        scanf("%d",&end);
    }while(end<0);
    if (end >= col->size){
        end = cdf->size;
    }
    for (i = start ; i < end ; i++){
        convert_value(col,i,str,32);
        printf("|  %s  |\n",col->title);
        printf("|  %s  |", str);
        printf("\n");
        current = current->next;
    }
}