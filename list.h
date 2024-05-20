#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H

#include "column.h"


typedef struct lnode_
{
    COLUMN* data;
    struct lnode_ *prev;
    struct lnode_ *next;

}lnode;


typedef struct dllist_{
    lnode *head;
    lnode *tail;
}dllist;

/**
* création d'un noeud
*/
lnode *lst_create_lnode(void *dat);

/**
* crée la liste et retourne un pointeur sur cette dernière
*/
dllist *lst_create_list();

/**
* supprimer la liste
*/
void lst_delete_list(dllist * lst);

/**
* Insère pnew au début de la liste lst
*/
void lst_insert_head(dllist * lst, lnode * pnew);

/**
* Insère pnew à la fin de la liste lst
*/
void lst_insert_tail(dllist * lst, lnode * pnew);

/**
* Insère l'élément pnew juste après ptr dans la liste lst
*/
void lst_insert_after(dllist * lst, lnode * pnew, lnode * ptr);

/**
* Supprime le premier élément de la liste
*/
void lst_delete_head(dllist * lst);

/**
* Supprime le dernier élément de la liste
*/
void lst_delete_tail(dllist * lst);

/**
* Supprime le lnode pointé par ptr
*/
void lst_delete_lnode(dllist * lst, lnode * ptr);

/**
* Supprime tous les éléments de la liste lst
*/
void lst_erase(dllist * lst);

/**
* retourne le premier node s'il existe sinon NULL
*/
lnode *get_first_node(dllist * lst);

/**
* retourne le dernier node s'il existe sinon NULL
*/
lnode *get_last_node(dllist * lst);

/**
* retourne le node suivant
*/
lnode *get_next_node(dllist * lst, lnode * lnode);

/**
* retourne le node precedent
*/
void *get_previous_elem(dllist * lst, lnode * lnode);

#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_LIST_H
