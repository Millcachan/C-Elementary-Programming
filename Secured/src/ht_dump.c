/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** ht_dump.c
*/

#include "../include/hashtable.h"

void display_line(line_t *line)
{
    case_t *temp = line->cases;

    mini_printf("[%d]:\n", line->index);
    while (temp) {
        mini_printf("> %d - %s\n", temp->hash, temp->value);
        temp = temp->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        display_line(ht->lines[i]);
    }
}
