/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** delete_hashtable.c
*/

#include "../include/hashtable.h"

void delete_line(line_t *line)
{
    case_t *next;

    while (line->cases) {
        next = line->cases->next;
        free(line->cases->value);
        free(line->cases);
        line->cases = next;
    }
    free(line);
}

void delete_hashtable(hashtable_t *ht)
{
    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        delete_line(ht->lines[i]);
    }
    free(ht->lines);
    free(ht);
}
