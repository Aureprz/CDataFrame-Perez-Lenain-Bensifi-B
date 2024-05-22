#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>
#include "sort.h"
#define MAX_SIZE 20

// 1. Alimentation

CDATAFRAME *create_empty_cdataframe(ENUM_TYPE* cdftype, int size){
    CDATAFRAME* cdf = NULL;
    COLUMN* col = NULL;
    lnode* newnode = NULL;
    char title[MAX_SIZE];
    int error;
    cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    cdf->list = lst_create_list();
    cdf->list_type =  cdftype;
    cdf->size = size;
    for(int i= 0; i < size; i++){
        do {
            printf("Choisissez un titre pour la colonne %d : \n ", i + 1);
            error = lire(title, MAX_SIZE);
            viderBuffer();
        }while (!error);
        col = create_column(*cdf->list_type,title);
        newnode = lst_create_lnode(col);
        lst_insert_tail(cdf->list, newnode);
    }
    return cdf;
}


CDATAFRAME* create_cdf_user(){
    int size = 0;
    int value = 0;
    int i;
    CDATAFRAME* cdf;
    do{
        printf("Veuillez saisir le nombre de colonnes de votre CDataFrame : \n");
        scanf("%d", &size);
        viderBuffer();
    }while(size <= 0);
    ENUM_TYPE list_type[size];
    for( i=0; i < size; i++){
        printf("============ Colonne [%d] ============\n",i+1);
        do {
            printf("Veuillez saisir le type de la colonne %d : \n", i+1);
            printf("UINT[1], INT[2], CHAR[3], FLOAT[4], DOUBLE[5], STRING[6], STRUCTURE[7]\n");
            scanf(" %d", &value);
            viderBuffer();
        } while ((value <=0) || (value>=8));
        list_type[i] = value+1; // because NULLVAL isn't that useful
    }
    cdf = create_empty_cdataframe(list_type, size);
    return cdf;
}

CDATAFRAME* create_cdf_program(){
    int nb_col = 3;
    int i,nb_line=10;
    int cpt=0;
    int val;
    ENUM_TYPE cdftype[3] ={3,3,3};
    lnode* node = NULL;
    CDATAFRAME* cdf = create_empty_cdataframe(cdftype,nb_col);
    node = cdf->list->head;
    while (node->next!=NULL){
        for(i =0; i < nb_line; i++){
            val = cpt + i;
            insert_value(node->data, &val);
        }
        cpt++;
        node = node->next;
    }
    for(i =0; i < nb_line; i++){
        val = cpt + i;
        insert_value(node->data, &val);
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
        printf("|%26s|",col->title);
        current = current->next;
    }
    col = current->data;
    printf("|%26s|",col->title);
    printf("\n");
}

void display_dataframe(CDATAFRAME* cdf){
    unsigned int i;
    if ((cdf == NULL) || cdf->list == NULL || cdf->size == 0) {
        printf("Dataframe vide \n");
        return;
    }
    print_col_names(cdf);
    for (i = 0 ; i < cdf->list->head->data->size ; i++) {
        lnode *current = get_first_node(cdf->list);
        while (current->next != NULL) {
            if (current->data->size > i)
                print_val_in_col(current->data, i);
            else
                printf("NULL");
            printf("|");
            current = get_next_node(cdf->list, current);
        }
        if (current->data->size > i)
            print_val_in_col(current->data, i);
        else
            printf("NULL");
        printf("|");
        printf("\n");
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
    printf("La colonne \" %s \" n'a pas ete trouvee dans le DataFrame. \n", col_name);
}

void delete_cdf_line(CDATAFRAME *cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    int pos=0;
    do{
        printf("Choisissez la position a laquelle vous souhaitez retirer une ligne : \n");
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
        printf("Choisissez la ligne ou vous souhaitez remplacer la valeur : \n");
        scanf("%d",&row_location);
    }while(row_location<=0);
    do{
        printf("Choisissez la colonne ou vous souhaitez remplacer la valeur : \n");
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
    printf("La valeur a bien ete remplacee.\n");
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
        printf("Choisissez la position a laquelle vous souhaitez rajouter une colonne : \n");
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
    printf("La colonne \" %s \" a bien ete ajoutee à la position %d dans le DataFrame.\n",col->title,pos);
}

void append_line_dataframe(CDATAFRAME *cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }

    int pos=0;
    unsigned long long int i, temp;
    lnode* current = cdf->list->head;
    COLUMN* col = current->data;
    do{
        printf("Choisissez la position a laquelle vous souhaitez rajouter une ligne : \n");
        scanf("%d",&pos);
    }while(pos<0 || pos > col->size);

    printf("Colonne \" %s \" \n",col->title);
    while(current->next != NULL){
        insert_user_val(col);
        if(col->index == NULL)
            create_index(col);
        for (i = col->size ; i > pos; i--) {
            temp = col->index[i-2];
            col->index[i-2] = col->index[i-1];
        }
        col->index[col->size-1] = temp;
        current = current->next;
        col = current->data;
    }

    printf("La ligne a bien ete ajoutee au DataFrame.\n");
}

void display_columns(CDATAFRAME* cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    lnode* current = NULL;
    COLUMN* col;
    unsigned long long j;
    int start=0; int end=0,i , error;
    do{
        printf("Choisissez la position de la colonne de depart [min: %u]: \n",cdf->size-1);
        error = scanf("%d",&start);
    }while(!(error) || (start < 0) || (start >= cdf->size));
    do{
        printf("Choisissez la position de la colonne de fin [max: %u]: \n",cdf->size-1);
        error = scanf("%d",&end);
    }while(!(error) || (end < start) || (end>= cdf->size));

    current = get_elem_index(cdf->list, start);
    col = current->data;

    for (i = start ; i < end ; i++){
        printf("|%26s|",col->title);
        current = current->next;
        col = current->data;
    }
    printf("|%26s|",col->title);
    printf("\n");

    for (j = 0 ; j < cdf->list->head->data->size ; j++) {
        current = get_elem_index(cdf->list, start);
        for (i = start ; i < end ; i++){
            if (current->data->size > i)
                print_val_in_col(current->data, j);
            else
                printf("|NULL                      |");
            printf("|");
            current = get_next_node(cdf->list, current);
        }
        if (current->data->size > j)
            print_val_in_col(current->data, j);
        else
            printf("|NULL");
        printf("|");
        printf("\n");
    }
    printf("\n");
}

void display_lines(CDATAFRAME* cdf){
    if (cdf == NULL || cdf->list == NULL || cdf->list->head == NULL){
        printf("Dataframe vide.");
        return;
    }
    lnode* current = cdf->list->head;
    COLUMN* col = current->data;
    unsigned long long int start=0, end=0, i;
    int error;
    do{
        printf("Choisir la position de la ligne de depart [max: %d]: \n",col->size-1);
        error = scanf("%llu",&start);
    }while(!(error) || (start >= col->size));
    do{
        printf("Choisir la position de la ligne de fin [max: %u]: \n",col->size-1);
        error = scanf("%llu",&end);
    }while(!(error) || (end>= col->size));


    print_col_names(cdf);
    printf("\n");
    for (i = start ; i <= end ; i++) {
        current = get_first_node(cdf->list);
        while (current->next != NULL) {
            if (current->data->size > i)
                print_val_in_col(current->data, i);
            else
                printf("NULL");
            printf("|");
            current = get_next_node(cdf->list, current);
        }
        if (current->data->size > i)
            print_val_in_col(current->data, i);
        else
            printf("|NULL                      |");
        printf("|");
        printf("\n");
    }
    printf("\n");
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        if (strlen(chaine) == 0)
        {
            strcpy(chaine, "|               Pas de nom |");
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void sort_column_in_cdf(CDATAFRAME* cdf){
    int i,pos=0;
    int sort_order=-1;
    if ((cdf == NULL) || (cdf->list == NULL)){
        printf("Dataframe vide. \n");
        return;
    }
    lnode* current = cdf->list->head;
    do{
        printf("Entrez la position de la colonne que vous souhaitez trier : \n");
        scanf("%d", &pos);
    }while(pos <= 0);
    if (pos >= cdf->size){
        pos = cdf->size;
    }
    for (i = 0 ; i < cdf->size ; i++){
        if (i == pos){
            printf("Dans quel ordre souhaitez-vous trier les données de la colonne ? \n");
            do{
                printf("0 - Ordre ascendant/croissant \n");
                printf("1 - Ordre descendant/decroissant \n");
                scanf("%d", &sort_order);
            }while((sort_order != 0) && (sort_order!=1));
            (current->data,sort_order);
            return;
        }
        current = current->next;
    }
}


void display_dataframe_by_index(CDATAFRAME* cdf){
    unsigned int i;
    if ((cdf == NULL) || cdf->list == NULL || cdf->size == 0) {
        printf("Dataframe vide \n");
        return;
    }
    print_col_names(cdf);
    for (i = 0 ; i < cdf->list->head->data->size ; i++) {
        lnode * current = get_first_node(cdf->list);
        while (current->next != NULL) {
            if (current->data->size > i)
                if(current->data->index != NULL) {
                    print_val_in_col(current->data, current->data->index[i]);
                }
                else{
                    print_val_in_col(current->data, i);
                }

            else
                printf("NULL");
            printf("|");
            current = get_next_node(cdf->list, current);
        }
        if (current->data->size > i)
            if(current->data->index != NULL) {
                print_val_in_col(current->data, current->data->index[i]);
            }
            else{
                print_val_in_col(current->data, i);
            }
        else
            printf("NULL");
        printf("|");
        printf("\n");
    }
    printf("\n");
}

void sort_cdf(CDATAFRAME *cdf){
    if ((cdf == NULL) || cdf->list == NULL || cdf->size == 0) {
        printf("Dataframe vide \n");
        return;
    }
    lnode * current = get_first_node(cdf->list);
    while (current->next != NULL) {
        update_index(current->data);
        current = current->next;
    }
}