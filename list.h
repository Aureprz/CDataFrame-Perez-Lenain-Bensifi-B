#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H

#include "column.h"


typedef struct lnode_
{
    COLUMN* data;
    struct lnode_ *prev;
    struct lnode_ *next;

}lnode;


typedef struct dllist
{
    int size;
    lnode *head;
    lnode *tail;
}dllist;




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

void lst_erase(dllist * lst);

lnode *lst_create_lnode(void *dat);
dllist *lst_create_list();
void lst_delete_list(dllist * lst);
void lst_insert_head(dllist * lst, lnode * pnew);
void lst_insert_tail(dllist * lst, lnode * pnew);
void lst_insert_after(dllist * lst, lnode * pnew, lnode * ptr);
void lst_delete_head(dllist * lst);
void lst_delete_tail(dllist * lst);
void lst_delete_lnode(dllist * lst, lnode * ptr);
void lst_erase(dllist * lst);
lnode *get_first_node(dllist * lst);
lnode *get_last_node(dllist * lst);
lnode *get_next_node(dllist * lst, lnode * lnode);
void *get_previous_elem(dllist * lst, lnode * lnode);


#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H
