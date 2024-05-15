#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H

#include "column.h"


typedef struct lnode_
{
    COLUMN* ln_data;
    struct lnode *prev;
    struct lnode *next;

}lnode;


typedef struct dllist
{
    int size;
    lnode *head;
    lnode *tail;
}dllist;

typedef dllist CDATAFRAME;


/**
 * @brief: Initialize the CDataFrame
 * @param1: Pointer to the CDataFrame to create
 * @return: 1 if the CDataFrame is correctly created 0 otherwise
 */
int init(dllist *list);

/**
 * @brief: Adds an column to the first position of the CDataFrame
 * @param1: Pointer to the CDataFrame to edit
 * @param2: Value to add to the CDataFrame
 * @return: 1 if the column is correctly inserted 0 otherwise
 */
int add_first(dllist *list, COLUMN *column);

/**
 * @brief: Adds an column to the last position of the CDataFrame
 * @param1: Pointer to the CDataFrame to edit
 * @param2: Value to add to the CDataFrame
 * @return: 1 if the column is correctly inserted 0 otherwise
 */
int add_last(dllist *list, COLUMN *column);

/**
 * @brief: Remove the first column of the CDataFrame
 * @param1: Pointer to the CDataFrame to edit
 * @return: 1 if the value is correctly removed 0 otherwise
 */
int remove_first(dllist *list);

/**
 * @brief: Remove the last column of the CDataFrame
 * @param1: Pointer to the CDataFrame to edit
 * @return: 1 if the value is correctly removed 0 otherwise
 */
int remove_last(dllist *list);

/**
 * @brief: Shows the entire CDataFrame
 * @param1: Pointer to the CDataFrame to show
 * @return: 1 if there is no error 0 otherwise
 */
int view(dllist *list);

/**
 * @brief: Clear the CDataFrame
 * @param1: Pointer to the CDataFrame to clear
 * @return: 1 if the CDataFrame is correctly cleared 0 otherwise
 */
int clear(dllist *list);

/**
 * @brief: Sort the CDataFrame in ascending or descending order by the number of element per column
 * @param1: Pointer to the CDataFrame to sort
 * @param2: If 0 sort in ascending order \n
 *        : if 1 sort in descending order
 * @return: 1 if the CDataFrame is correctly sorted 0 otherwise
 */
int sort(dllist *list, int *ascending);

/**
 * @brief: Access a to a specific element in a CDataFrame by its index
 * @param1: Pointer to the CDataFrame
 * @param2: the column where the element is located
 * @param3: the line where the element is located
 * @param4: If 0 starts at the beginning \n
 *        : If 1 start at the end
 * @param5: Pointer that will point to the element
 * @return: 1 if the CDataFrame is correctly sorted 0 otherwise
 */
int view_element(dllist *list, int column, int line, int method, COL_TYPE *value);

#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H
