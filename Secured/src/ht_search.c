/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** ht_search.c
*/

#include "../include/hashtable.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int hashed;
    line_t *copy;

    if (!key || !ht)
        return NULL;
    hashed = ht->hash(key, my_strlen(key));
    copy = ht->lines[hashed % ht->size];
    while (copy->cases) {
        if (copy->cases->hash == hashed) {
            return copy->cases->value;
        }
        copy->cases = copy->cases->next;
    }
    return NULL;
}
