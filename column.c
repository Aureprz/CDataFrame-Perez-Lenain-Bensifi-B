#define MAX_SIZE 32
#include "sort.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

COLUMN *create_column(ENUM_TYPE type, char *title){
    COLUMN* col = NULL;
    col = (COLUMN*) malloc(sizeof(COLUMN));
    if (col == NULL){
        return col;
    }
    char* title2 = (char*) malloc(sizeof(char)* MAX_SIZE);
    strcpy(title2, title);
    col->title = title2;
    col->column_type = type;
    col->data = NULL;
    col->index = NULL;
    col->valid_index = 0;
    col->max_size = -20;
    col->size = 0;
    col->sort_dir = 0;
    return col;
}

COLUMN* create_col_user(){
    char title[MAX_SIZE];
    int i=0;
    ENUM_TYPE type;
    printf("Veuillez saisir le titre de la colonne : \n");
    scanf(" %s", title);
    do {
        printf("Veuillez saisir le type de la colonne : \n");
        printf("NULLVAL [1] , UINT[2], INT[3], CHAR[4], FLOAT[5], DOUBLE[6], STRING[7], STRUCTURE[8]\n");
        scanf(" %d", &i);
    } while ((i <=0) || (i>8));
    type = i;
    return create_column(type, title);
}




int insert_user_val(COLUMN *col){
    unsigned int vuint;
    int vint;
    float vfloat;
    double vdouble;
    char vchar;
    char vstr[MAX_SIZE];
    int res=1;

    switch (col->column_type) {
        case UINT:
            printf("Veuillez entrer un entier positif : \n");
            scanf("%d", &vuint);
            insert_value(col,&vuint);
            break;
        case INT:
            printf("Veuillez entrer un entier : \n");
            scanf("%d",&vint);
            insert_value(col,&vint);
            break;
        case CHAR:
            printf("Veuillez entrer un caractère : \n");
            scanf("%c",&vchar);
            insert_value(col,&vchar);
            break;
        case FLOAT:
            printf("Veuillez entrer une valeur réel : \n");
            scanf("%f",&vfloat);
            insert_value(col,&vfloat);
            break;
        case DOUBLE:
            printf("Veuillez entrer une valeur réel : \n");
            scanf("%lf",&vdouble);
            insert_value(col,&vdouble);
            break;
        case STRING:
            printf("Veuillez entrer une chaine de caractères : \n");
            scanf(" %s",vstr);
            insert_value(col,vstr);
            break;
        default:
            printf("ERREUR \n");
            res = 0;
    }
    return res;
}

int insert_value(COLUMN *col, void *value){
    if (col == NULL){
        return 0;
    }
    // check memory space
    if (col->size >= col->max_size) {
        if (col->max_size == 0) {
            col->data = malloc(32 * sizeof(COL_TYPE));
        } else {
            realloc(col->data, (col->max_size + 32) * sizeof(COL_TYPE));
        }
        col->max_size += 32;
        if (col->data == NULL) {
            return 0;
        }
    }

    if(value == NULL){
        col->data[col->size] = NULL;
        col->size++;
        return 1;
    }
    switch(col->column_type){

        case INT:
            col->data[col->size] = (COL_TYPE *) malloc(sizeof(int));
            *((int*)col->data[col->size]) = *((int*)value);
            break;
        case FLOAT:
            col->data[col->size] = (COL_TYPE *) malloc(sizeof(float));
            *((float*)col->data[col->size]) = *((float*)value);
            break;
        case UINT:
            col->data[col->size] = (COL_TYPE *) malloc(sizeof(unsigned int));
            *((unsigned int*)col->data[col->size]) = *((unsigned int*)value);
            break;
        case CHAR:
            col->data[col->size] = (COL_TYPE *) malloc(sizeof(char));
            *((char*)col->data[col->size]) = *((char*)value);
            break;
        case DOUBLE:
            col->data[col->size] = (COL_TYPE *) malloc(sizeof(double));
            *((double*)col->data[col->size]) = *((double*)value);
            break;
        case STRING:
            col->data[col->size] = (COL_TYPE *) malloc(sizeof(char*));
            *((char**)col->data[col->size]) = *((char**)value);
            break;
        case STRUCTURE:
            col->data[col->size] = (COL_TYPE *) malloc(sizeof(void*));
            *((void**)col->data[col->size]) = *((void**)value);
            break;
        default:
            return 0;

    }
    col->size++;
    return 1;
}

void delete_value_column(COLUMN *col, int location){
    int i;
    if (col == NULL || location <= 0){
        return;
    }
    for (i = location - 1 ; i < col->size ; i++){
        col->data[i] = col->data[i+1];
    }
    col->size--;
}

void delete_column(COLUMN **col){
    for (unsigned int i=0; i< (*col)->size; i++){
        free((*col)->data[i]);
    }
    free((*col)->data);
    erase_index(*col);
    free(col);
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
    if (col->data[i] == NULL){
        snprintf(str, size, "NULL");
        return;
    }
        switch (col->column_type) {

            case INT:
                snprintf(str, size, "%d", *((int *) col->data[i]));
                break;
            case UINT:
                snprintf(str, size, "%i", *((unsigned int *) col->data[i]));
                break;
            case FLOAT:
                snprintf(str, size, "%f", *((float *) col->data[i]));
                break;
            case DOUBLE:
                snprintf(str, size, "%lf", *((double *) col->data[i]));
                break;
            case CHAR:
                snprintf(str, size, "%c", *((char *) col->data[i]));
                break;
            case STRING:
                snprintf(str, size, "%s", (char *) col->data[i]);
                break;
            case STRUCTURE:
                snprintf(str, size, "STRUCTURE");
                break;
            default:
                snprintf(str, size, "CONVERSION ERROR");
                break;
        }
}


void print_col(COLUMN* col){
    unsigned long long int i;
    for (i = 0; i < col->size; i++){
        print_val_in_col(col, i);
    }
}

void print_val_in_col(COLUMN* col , unsigned long long int index){
    if (col == NULL ||index >= col->size){
        printf("Index incorrect \n");
        return;
    }
    char str[MAX_SIZE];
    convert_value(col, index, str, MAX_SIZE);
    printf("[%llu] %-20.20s \n", index, str);
}

int exist_col(COLUMN* col, void *value){
    if (col == NULL || col->size == 0){
        return 0;
    }
    for(unsigned long long int i = 0; i < col->size; i++){
        switch (col->column_type) {

            case INT:
                if (*((int*)col->data[i]) == *((int *)value)){
                    return 1;
                }
                break;
            case UINT:
                if (*((unsigned int*)col->data[i]) == *((unsigned int *)value)){
                    return 1;
                }
                break;
            case FLOAT:
                if (*((float*)col->data[i]) == *((float *)value)){
                    return 1;
                }
                break;
            case DOUBLE:
                if (*((double*)col->data[i]) == *((double *)value)){
                    return 1;
                }
                break;
            case CHAR:
                if (*((char*)col->data[i]) == *((char *)value)){
                    return 1;
                }
                break;
            case STRING:
                if (strcmp((char*)col->data[i], (char *)value) == 0){
                    return 1;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}

int cellsequal_col(COLUMN* col, void *value){
    int cpt = 0;
    if (col == NULL || col->size == 0){
        return 0;
    }
    for(unsigned long long int i = 0; i < col->size; i++){
        switch (col->column_type) {

            case INT:
                if (*((int*)col->data[i]) == *((int *)value)){
                    cpt++;
                }
                break;
            case UINT:
                if (*((unsigned int*)col->data[i]) == *((unsigned int *)value)){
                    cpt++;
                }
                break;
            case FLOAT:
                if (*((float*)col->data[i]) == *((float *)value)){
                    cpt++;
                }
                break;
            case DOUBLE:
                if (*((double*)col->data[i]) == *((double *)value)){
                    cpt++;
                }
                break;
            case CHAR:
                if (*((char*)col->data[i]) == *((char *)value)){
                    cpt++;
                }
                break;
            case STRING:
                if (strcmp((char*)col->data[i], (char *)value) == 0){
                    cpt++;
                }
                break;
            default:
                break;
        }
    }
    return cpt;
}


int cellssup_col(COLUMN* col, void *value){
    int cpt = 0;
    if (col == NULL || col->size == 0){
        return 0;
    }
    for(unsigned long long int i = 0; i < col->size; i++){
        switch (col->column_type) {

            case INT:
                if (*((int*)col->data[i]) > *((int *)value)){
                    cpt++;
                }
                break;
            case UINT:
                if (*((unsigned int*)col->data[i]) > *((unsigned int *)value)){
                    cpt++;
                }
                break;
            case FLOAT:
                if (*((float*)col->data[i]) > *((float *)value)){
                    cpt++;
                }
                break;
            case DOUBLE:
                if (*((double*)col->data[i]) > *((double *)value)){
                    cpt++;
                }
                break;
            case CHAR:
                if (*((char*)col->data[i]) > *((char *)value)){
                    cpt++;
                }
                break;
            case STRING:
                if (strcmp((char*)col->data[i], (char *)value) > 0){
                    cpt++;
                }
                break;
            default:
                break;
        }
    }
    return cpt;
}




int cellsinf_col(COLUMN* col, void *value){
    int cpt = 0;
    if (col == NULL || col->size == 0){
        return 0;
    }
    for(unsigned long long int i = 0; i < col->size; i++){
        switch (col->column_type) {

            case INT:
                if (*((int*)col->data[i]) < *((int *)value)){
                    cpt++;
                }
                break;
            case UINT:
                if (*((unsigned int*)col->data[i]) < *((unsigned int *)value)){
                    cpt++;
                }
                break;
            case FLOAT:
                if (*((float*)col->data[i]) < *((float *)value)){
                    cpt++;
                }
                break;
            case DOUBLE:
                if (*((double*)col->data[i]) < *((double *)value)){
                    cpt++;
                }
                break;
            case CHAR:
                if (*((char*)col->data[i]) < *((char *)value)){
                    cpt++;
                }
                break;
            case STRING:
                if (strcmp((char*)col->data[i], (char *)value) < 0){
                    cpt++;
                }
                break;
            default:
                break;
        }
    }
    return cpt;
}


