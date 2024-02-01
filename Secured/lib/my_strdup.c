/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** allocate memory to an str
*/

#include "../include/hashtable.h"

char *my_strdup(char const *src)
{
    char *dest;
    int len = 0;

    while (src[len] != '\0') {
        len++;
    }
    dest = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }
    return dest;
}
