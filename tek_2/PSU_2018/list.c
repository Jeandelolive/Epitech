/*
** EPITECH PROJECT, 2019
** Liste chainée
** File description:
** list.c
*/

#include <unistd.h>
#include "struct.h"

list_t *head_list = NULL;

void *create_list(size_t var_size)
{
    head_list = sbrk(sizeof(list_t));
    void *ptr = sbrk(var_size);
    if (ptr == (void *)-1)
    return (NULL);
    head_list->next = NULL;
    head_list->var_bool = USED;
    head_list->size = var_size;
    head_list->ptr = ptr;
    return (ptr);
}

void *add_in_list(size_t var_size)
{
    list_t *tmp = head_list;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = sbrk(sizeof(list_t));    
    void *ptr = sbrk(var_size);
    if (ptr == (void *)-1) {
        return (NULL);   
    }
    tmp->next->var_bool = USED;
    tmp->next->size = var_size;
    tmp->next->ptr = ptr;
    return (ptr);
}

void del_first_elem()
{
    if (head_list == NULL)
        return;
    head_list = head_list->next;
}

void del_in_list(void *var_ptr)
{
    if (head_list->ptr == var_ptr)
        del_first_elem();
    list_t *tmp = head_list;
    while (tmp->next->ptr == var_ptr)
        tmp = tmp->next;
    tmp->next = tmp->next->next;
    return;
}