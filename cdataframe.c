#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define MAX_SIZE 32

// 1. Alimentation

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size){
    CDATAFRAME  *cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    cdf->list = *lst_create_list();
    cdf->cdataframe_type = *cdftype;
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
        } while ((value <=0) || (value>8));
        list_type[i] = value+1; // because NULLVAL isn't that useful
    }
    cdf = create_empty_cdataframe(list_type, size);
    for ( i = 0 ; i < size ; i++){
        printf("Choisissez un titre pour la colonne %d : ",i+1);
        scanf(" %s", *title);
        col = create_column(cdf->cdataframe_type,*title);
        newnode = lst_create_lnode(col);
        lst_insert_tail(&cdf->list, newnode);
    }
    return cdf;
}

// 2. Affichage



// 3. Opérations usuelles

void print_col_names(CDATAFRAME* cdf, unsigned int size){
    lnode* current = cdf->list.head;
    int i;
    COLUMN* col;
    for (i = 0 ; i < size ; i++){
        col = current->data;
        printf(" %s",col->title);
        current = current->next;
    }
}