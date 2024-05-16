//
// Created by aurel on 13/05/2024.
//

#include "sort.h"
#include "column.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void sort(COLUMN* col, int sort_dir){
    if ((col == NULL) || ((sort_dir != DESC) && (sort_dir != ASC)) || col->data == NULL){
        return;
    }
    if(((col->valid_index == 1) && (col->sort_dir == sort_dir)) || (col->size <=1)){
        col->sort_dir = sort_dir;
        col->valid_index = 1;
        return;
    }
    if(col->index == NULL){
        create_index(col);
    }
    if (col->valid_index == -1){
        insertion_sort(col, sort_dir);
    }
    else{
        quicksort(col, 0, col->size-1, sort_dir);
    }
    col->sort_dir = sort_dir;
    col->valid_index = 1;
}

unsigned int partition(COLUMN* col, unsigned int left , unsigned int right, int sort_dir){
    unsigned long long int pivot = col->index[right];
    unsigned int i = left-1, j;

    for(j = left ; j < right; j++){
        if(((sort_dir == ASC) && (compare_in_col(col, col->index[j], pivot) <= 0))||
        ((sort_dir == DESC) && (compare_in_col(col, col->index[j], pivot) >= 0))){
            i++;
            swap(&col->index[j], &col->index[i]);
        }
    }
    swap(&col->index[i+1], &col->index[right]);

    return i+1;
}

void quicksort(COLUMN* col, unsigned int left , unsigned int right, int sort_dir){
    unsigned int pi;
    if(left < right){
        pi =  partition(col, left , right, sort_dir);
        quicksort(col, left , pi -1, sort_dir);
        quicksort(col, pi + 1, right, sort_dir);
    }
}

void create_index(COLUMN *col){
    if ((col == NULL) || (col->index != NULL)){
        return;
    }
    unsigned long long int i;
    col->index = (unsigned long long int *) malloc(col->size * sizeof(unsigned long long int));
    for(i = 0; i < col->size; i++){
        col->index[i] = i;
    }
}

void erase_index(COLUMN *col){
    free(col->index);
    col->index = NULL;
}

int compare_in_col(COLUMN *col, unsigned long long int i, unsigned long long int j){
    int res;
    switch (col->column_type) {

        case INT:
            if (*((int*)col->data[i]) > *((int*)col->data[j])){
                return 1;
            }
            if (*((int*)col->data[i]) < *((int*)col->data[j])){
                return -1;
            }
            break;
        case UINT:
            if (*((unsigned int*)col->data[i]) > *((unsigned int*)col->data[j])){
                return 1;
            }
            if (*((unsigned int*)col->data[i]) < *((unsigned int*)col->data[j])){
                return -1;
            }
            break;

        case FLOAT:
            if (*((float*)col->data[i]) > *((float*)col->data[j])){
                return 1;
            }
            if (*((float*)col->data[i]) < *((float*)col->data[j])){
                return -1;
            }
            break;

        case DOUBLE:
            if (*((double*)col->data[i]) > *((double*)col->data[j])){
                return 1;
            }
            if (*((double*)col->data[i]) < *((double*)col->data[j])){
                return -1;
            }
            break;

        case CHAR:
            if (*((char*)col->data[i]) > (*((char*)col->data[j]))){
                return 1;
            }
            if (*((char*)col->data[i]) < (*((char*)col->data[j]))){
                return -1;
            }
            break;

        case STRING:
            res = strcmp((char*)col->data[i], (char*)col->data[j]);
            if(res>0){
                return 1;
            }
            if(res<0){
                return -1;
            }
            break;
        default:
            break;
    }
    return 0;
}

int compare_val_in_col(COLUMN *col, unsigned long long int i, void* val) {
    int res;
    switch (col->column_type) {

        case INT:
            if (*((int*)col->data[i]) > *(int*) val){
                return 1;
            }
            if (*((int*)col->data[i]) < *(int*) val){
                return -1;
            }
            break;
        case UINT:
            if (*((unsigned int*)col->data[i]) > *(int*) val){
                return 1;
            }
            if (*((unsigned int*)col->data[i]) < *(int*) val){
                return -1;
            }
            break;

        case FLOAT:
            if (*((float*)col->data[i]) > *(float*) val){
                return 1;
            }
            if (*((float*)col->data[i]) < *(float*) val){
                return -1;
            }
            break;

        case DOUBLE:
            if (*((double*)col->data[i]) > *(double*) val){
                return 1;
            }
            if (*((double*)col->data[i]) < *(double*) val){
                return -1;
            }
            break;

        case CHAR:
            if (*((char*)col->data[i]) > *(char*) val){
                return 1;
            }
            if (*((char*)col->data[i]) < *(char*) val){
                return -1;
            }
            break;

        case STRING:
            res = strcmp((char*)col->data[i], (char*)val);
            if(res>0){
                return 1;
            }
            if(res<0){
                return -1;
            }
            break;
        default:
            break;
    }
    return 0;
}

void swap(unsigned long long int *a, unsigned long long int *b){
    unsigned long long int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(COLUMN *col, int sort_dir){
    unsigned long long int k;
    int j;
    for(int i=1; i< (col->size); i++){
        k = col->index[i];
        j = i - 1;
        if (sort_dir == DESC) {
            while((j>=0) && (compare_in_col(col, k, col->index[j]) > 0)){
                col->index[j+1] = col->index[j];
                j--;
            }
        }
        else {
            while((j >= 0) && (compare_in_col(col, k, col->index[j]) < 0)){
                col->index[j + 1] = col->index[j];
                j--;
            }
        }
        col->index[j+1] = k;

    }
}

void print_col_by_index(COLUMN *col){
    char str[MAX_SIZE];
    unsigned long long int i;
    for (i = 0; i < col->size; i++){
        convert_value(col, col->index[i], str, MAX_SIZE);
        printf("[%llu] %s\n", i, str);
    }
}


int check_index(COLUMN *col){
    if (col == NULL) {
        return 0;
    }
    return col->valid_index;
}

void update_index(COLUMN *col){
    sort(col, col->sort_dir);
}


