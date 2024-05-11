
#define MAX_SIZE 512


#include "column.h"
#include <stdio.h>
#include <stdlib.h>

COLUMN *create_column(ENUM_TYPE type, char *title){
    COLUMN* col = NULL;
    col = (COLUMN*) malloc(sizeof(COLUMN));
    if (col == NULL){
        return col;
    }
    col->title = title;
    col->column_type = type;
    col->data = NULL;
    col->max_size = 0;
    col->size = 0;
    return col;
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

void delete_column(COLUMN **col){
    for (unsigned int i=0; i< (*col)->size; i++){
        free((*col)->data[i]);
    }
    free((*col)->data);
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
    char str[MAX_SIZE];
    unsigned long long int i;
    for (i = 0; i < col->size; i++){
        convert_value(col, i, str, MAX_SIZE);
        printf("[%llu] %s\n", i, str);
    }
}


