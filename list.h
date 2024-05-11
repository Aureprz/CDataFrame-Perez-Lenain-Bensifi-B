#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H

#include "column.h"


/**
* Element lnode
*/
typedef struct lnode_ {
    void *data;
    struct lnode_ *prev;
    struct lnode_ *next;
} lnode;


/**
* A list
*/
typedef struct list_ {
    lnode *head;
    lnode *tail;
} list;


/**
 * @brief: Initialize node
 * @param1: Pointer to the data
 * @return: Pointer to the node
 */
lnode *lst_create_lnode(void *dat);


/**
 * @brief: Initialize a list
 * @return: Pointer to the list
 */
list *lst_create_list();


/**
 * @brief: Delete a list
 * @param1: Pointer to the list
 */
void lst_delete_list(list * lst);


/**
 * @brief: Insert a pnew to the beginning of the list
 * @param1: Pointer to the list
 * @param2: Pointer to the new head/node
 */
void lst_insert_head(list * lst, lnode * pnew);


/**
 * @brief: Insert a pnew to the end of the list
 * @param1: Pointer to the list
 * @param2: Pointer to the new tail/node
 */
void lst_insert_tail(list * lst, lnode * pnew);


/**
 * @brief: Insert the new node pointed by pnew after the node pointed by ptr
 * @param1: Pointer to the list
 * @param2: Pointer to the new node
 * @param3: Pointer to the node
 */
void lst_insert_after(list * lst, lnode * pnew, lnode * ptr);


/**
 * @brief: Delete the first element of the list
 * @param1: Pointer to the list
 */
void lst_delete_head(list * lst);


/**
 * @brief: Delete the last element of the list
 * @param1: Pointer to the list
 */
void lst_delete_tail(list * lst);


/**
 * @brief: Delete the node pointed by ptr
 * @param1: Pointer to the list
 * @param2: Pointer to the node
 */
void lst_delete_lnode(list * lst, lnode * ptr);


/**
 * @brief: Delete all the elements of the list
 * @param1: Pointer to the list
 */
void lst_erase(list * lst);


/**
 * @brief: Return the first node
 * @param1: Pointer to the CDataFrame to create
 * @return: 1 if the CDataFrame is correctly created 0 otherwise
 */
lnode *get_first_node(list * lst);


/**
 * @brief: Initialize the CDataFrame
 * @param1: Pointer to the CDataFrame to create
 * @return: 1 if the CDataFrame is correctly created 0 otherwise
 */
lnode *get_last_node(list * lst);


/**
 * @brief: return the pointer next node
 * @param1: Pointer to list
 * @param2: Pointer to the node
 * @return: Pointer to the next node
 */
lnode *get_next_node(list * lst, lnode * lnode);


/**
 * @brief: Initialize the CDataFrame
 * @param1: Pointer to the CDataFrame to create
 */
void *get_previous_elem(list * lst, lnode * lnode);

#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H
