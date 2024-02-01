/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** return the len of an str
*/

#include "../include/hashtable.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
