/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** print a char
*/

#include "../include/hashtable.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
