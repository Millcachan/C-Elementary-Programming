/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** ht_delete.c
*/

#include "../include/hashtable.h"

static void delete_node(case_t **temp, case_t **prev, line_t *copy)
{
    if ((*prev))
        (*prev)->next = (*temp)->next;
    else
        copy->cases = (*temp)->next;
    free((*temp)->value);
    free((*temp));
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hashed;
    int deleted = 0;
    line_t *copy;
    case_t *prev = NULL;
    case_t *temp;

    if (!key || !ht)
        return 84;
    hashed = ht->hash(key, my_strlen(key));
    copy = ht->lines[hashed % ht->size];
    temp = copy->cases;
    while (temp) {
        if (temp->hash == hashed) {
            delete_node(&temp, &prev, copy);
            deleted = 1;
        }
        prev = temp;
        temp = temp->next;
    }
    return 84 - (84 * deleted);
}
