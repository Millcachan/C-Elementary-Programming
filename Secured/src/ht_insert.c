/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** ht_insert.c
*/

#include "../include/hashtable.h"

int change_cells(case_t **copy, int hash, char *value)
{
    case_t *temp = (*copy);

    while (temp) {
        if (temp->hash == hash) {
            free(temp->value);
            temp->value = my_strdup(value);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void add_cells(case_t **copy, int hash, char *value)
{
    case_t *temp = malloc(sizeof(case_t));

    temp->hash = hash;
    temp->value = my_strdup(value);
    temp->next = (*copy);
    (*copy) = temp;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int hashed;

    if (!key || !ht || !value)
        return 84;
    hashed = ht->hash(key, ht->size);
    if (change_cells(&ht->lines[hashed % ht->size]->cases, hashed, value) == 0)
        add_cells(&ht->lines[hashed % ht->size]->cases, hashed, value);
    return 0;
}
