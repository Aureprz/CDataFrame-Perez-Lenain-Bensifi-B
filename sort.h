//
// Created by aurel on 13/05/2024.
//

#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_SORT_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_SORT_H

#include "column.h"

#define ASC 0
#define DESC 1

/**
* @brief: Sort a column according to agivenorder
* @param1: Pointer to the column to sort
* @param2: Sort type (ASC or DESC)
*/
void sort(COLUMN* col, int sort_dir);

/**
 * @brief: Remove the index of a column
 * @param1: Pointer to the column
 */
void erase_index(COLUMN *col);

/**
 * @brief: Check if an index is correct
 * @param1: Pointer to the column
 * @return: 0: index not existing,-1: the index exists but invalid,
 1: the index is correct
 */
int check_index(COLUMN *col);

/**
 * @brief: Update the index
 * @param1: Pointer to the column
 */
void update_index(COLUMN *col);

void create_index(COLUMN *col);

unsigned int partition(COLUMN* col, unsigned int left , unsigned int right, int sort_dir);

void quicksort(COLUMN* col, unsigned int left , unsigned int right, int sort_dir);

void swap(unsigned long long int *a, unsigned long long int *b);

int compare_in_col(COLUMN *col, unsigned long long int i , unsigned long long int j);

void insertion_sort(COLUMN *col, int sort_dir);

#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_SORT_H
