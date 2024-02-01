/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** Print a full number
*/

#include "../include/hashtable.h"

int my_put_nbr(long long nbr)
{
    if (nbr >= 10)
        my_put_nbr(nbr / 10);
    my_putchar((char)('0' + nbr % 10));
    return 0;
}
