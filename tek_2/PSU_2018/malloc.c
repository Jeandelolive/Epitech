/*
** EPITECH PROJECT, 2019
** PSU_project
** File description:
** malloc.c
*/

#include <unistd.h>
#include "struct.h"

extern list_t *head_list;

void *malloc(size_t size)
{
    int i = 1;
    while (i < size) 
        i = i * 2;
    if (head_list != NULL) {
        list_t *tmp = head_list;
        while (tmp->next != NULL) {
            if (tmp->size >= size && tmp->var_bool == UNUSED) {
                tmp->var_bool = USED;
                return (tmp->ptr);
            }
            tmp = tmp->next;
        }
    }
    if (head_list == NULL) {
        return (create_list(i));
    }
    else {
        return (add_in_list(i));
    }
}

int size_list()
{
    int i = 0;
    list_t *tmp = head_list;

    while (tmp != NULL) {
        i = i + 1;
        tmp = tmp->next;
    }
    return (i);
}

void free(void *ptr)
{
    int i = 0;
    list_t *tmp = head_list;
    if (head_list->ptr == ptr) {
        head_list->var_bool = UNUSED;
        return;
    }
    while (tmp->ptr != ptr && tmp->next != NULL) {
        tmp = tmp->next;
    }
    if (tmp->ptr == ptr) {
        tmp->var_bool = UNUSED;
    }
}

void find_old_ptr(list_t *tmp, list_t *ptr)
{
    while (tmp->ptr != ptr || tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->var_bool = UNUSED;
}

void *realloc(void *ptr , size_t size)
{
    list_t *tmp = head_list;
    int check = 0;
    if (ptr == NULL)
        return (NULL);
    while (tmp->next != NULL) {
        if (tmp->var_bool == UNUSED && tmp->size >= size) {
            write(1, "1\n", 2);            
            tmp->var_bool = USED;
            if (check == 0) {
                find_old_ptr(tmp, ptr);
            }
            return (tmp->ptr);
        }
        if (tmp->ptr == ptr) {
            tmp->var_bool = UNUSED;
            check = 1;
        }
        tmp = tmp->next;
    }
    return (malloc(size));
}