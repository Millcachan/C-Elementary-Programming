/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-camille.billard
** File description:
** rcmp
*/

#include "../include/shell.h"

int namercmp(data_t *d1, data_t *d2)
{
    int i = 0;
    char *s1 = d1->name;
    char *s2 = d2->name;

    while (1) {
        if (s1[i] < s2[i])
            return 1;
        if (s1[i] > s2[i])
            return -1;
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
        i++;
    }
}

int typercmp(data_t *d1, data_t *d2)
{
    if (d1->type < d2->type)
        return 1;
    if (d1->type > d2->type)
        return -1;
    return 0;
}

int idrcmp(data_t *d1, data_t *d2)
{
    if (d1->ID < d2->ID)
        return 1;
    return -1;
}
