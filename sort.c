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
    unsigned long long int k;
    int j;
    char str1[MAX_SIZE], str2[MAX_SIZE];

    if ((col == NULL) || ((sort_dir != DESC) && (sort_dir != ASC)) || col->data == NULL){
        return;
    }

    if(((col->valid_index == 1) && (col->sort_dir == sort_dir)) || (col->size <=1)){
        col->sort_dir = sort_dir;
        col->valid_index = 1;
        return;
    }
    /*TODO: add sort_dir condition */
    if (col->valid_index == -1){
        for(int i=2; i< col->size; i++){
            k = col->index[i];
            convert_value(col, k, str1, MAX_SIZE);
            j = i - 1;
            convert_value(col, col->index[j], str2, MAX_SIZE);

            while((j>0) && (strcmp(str2, str1) > 0)){
                col->index[j+1] = col->index[j];
                j--;
                convert_value(col, col->index[j], str2, MAX_SIZE);
            }
            col->index[j+1] = k;

        }
    }
    else{
        /*TODO: Tri rapide(Quicksort) p25*/
    }
    col->sort_dir = sort_dir;
    col->valid_index = 1;
    return;
}

unsigned long long int partition(COLUMN* col, int left , int right){
    /*TODO partition*/
    return 1;
}

void quicksort(COLUMN* col, int left , int right){
    /*TODO (Quicksort) p25*/
}

void create_index(COLUMN *col){
    if ((col == NULL) || (col->index == NULL)){
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