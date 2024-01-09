/*
** EPITECH PROJECT, 2023
** 1.3
** File description:
** put_fonctions
*/

#include "../include/shell.h"

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

int my_putstr(char *str, int fd)
{
    return (int)(write(fd, str, (size_t)my_strlen(str)));
}

void my_putnbr(long long nbr, int fd)
{
    if (nbr < 0) {
        my_putchar('-', fd);
        nbr = -nbr;
    }
    if (nbr >= 10)
        my_putnbr(nbr / 10, fd);
    my_putchar((char)('0' + nbr % 10), fd);
}
