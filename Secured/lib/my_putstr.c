/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-titouan.pradoura
** File description:
** my_putstr.c
*/

#include "../include/hashtable.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
