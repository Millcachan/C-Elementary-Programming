/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** new_hashtable.c
*/

#include "../include/hashtable.h"

line_t *add_line(int index)
{
    line_t *temp = malloc(sizeof(line_t));

    temp->cases = NULL;
    temp->index = index;
    return temp;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht;

    if (len <= 0)
        return NULL;
    ht = malloc(sizeof(hashtable_t));
    ht->hash = hash;
    ht->size = len;
    ht->lines = malloc(sizeof(line_t *) * len);
    for (int i = 0; i < len; i++) {
        ht->lines[i] = add_line(i);
    }
    return ht;
}
