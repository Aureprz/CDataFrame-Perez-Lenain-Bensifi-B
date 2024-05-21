#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

lnode *lst_create_lnode(void *dat) {
    lnode *ptmp = (lnode *) malloc(sizeof(lnode));
    ptmp->data = dat;
    ptmp->next = NULL;
    ptmp->prev = NULL;
    return ptmp;
}
dllist *lst_create_list() {
    dllist *lst = (dllist *) malloc(sizeof(dllist));
    lst->head = NULL;
    lst->tail = NULL;
    return lst;
}
void lst_delete_list(dllist * lst) {
    lst_erase(lst);
    free(lst);
}
void lst_insert_head(dllist * lst, lnode * pnew) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
        return;
    }
    pnew->next = lst->head;
    pnew->prev = NULL;
    lst->head = pnew;
    pnew->next->prev = pnew;
}
void lst_insert_tail(dllist * lst, lnode * pnew) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
        return;
    }
    pnew->next = NULL;
    pnew->prev = lst->tail;
    lst->tail = pnew;
    pnew->prev->next = pnew;
}
void lst_insert_after(dllist * lst, lnode * pnew, lnode * ptr) {
    if (lst->head == NULL) {
        lst->head = pnew;
        lst->tail = pnew;
    } else if (ptr == NULL) {
        return;
    } else if (lst->tail == ptr) {
        lst_insert_tail(lst, pnew);
    } else {
        pnew->next = ptr->next;
        pnew->prev = ptr;
        pnew->next->prev = pnew;
        pnew->prev->next = pnew;
    }
}
void lst_delete_head(dllist * lst) {
    if (lst->head->next == NULL) {
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return;
    }
    lst->head = lst->head->next;
    free(lst->head->prev);
    lst->head->prev = NULL;
}
void lst_delete_tail(dllist * lst) {
    if (lst->tail->prev == NULL) {
        free(lst->tail);
        lst->head = NULL;
        lst->tail = NULL;
        return;
    }
    lst->tail = lst->tail->prev;
    free(lst->tail->next);
    lst->tail->next = NULL;
}
void lst_delete_lnode(dllist * lst, lnode * ptr) {
    if (ptr == NULL)
        return;
    if (ptr == lst->head) {
        lst_delete_head(lst);
        return;
    }
    if (ptr == lst->tail) {
        lst_delete_tail(lst);
        return;
    }
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    free(ptr);
}
void lst_erase(dllist * lst) {
    if (lst->head == NULL)
        return;
    while (lst->head != lst->tail) {
        lst->head = lst->head->next;
        free(lst->head->prev);
    }
    free(lst->head);
    lst->head = NULL;
    lst->tail = NULL;
}
lnode *get_first_node(dllist * lst) {
    if (lst->head == NULL)
        return NULL;
    return lst->head;
}
lnode *get_last_node(dllist * lst) {
    if (lst->tail == NULL)
        return NULL;
    return lst->tail;
}
lnode *get_next_node(dllist * lst, lnode * lnode) {
    if (lnode == NULL)
        return NULL;
    return lnode->next;
}
void *get_previous_elem(dllist * lst, lnode * lnode) {
    if (lnode == NULL)
        return NULL;
    return lnode->prev;
}

void *get_elem_index(dllist * lst, int index){
    if (lst == NULL|| lst->head == NULL)
        return NULL;
    int i = 0;
    lnode* current = lst->head;
    while (current->next !=NULL && (i < index)){
        current = current->next;
        i++;
    }
    return current;
}