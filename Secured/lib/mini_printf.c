/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** A simplified version of the printf
*/

#include <stdarg.h>
#include "../include/hashtable.h"

static int case_d(va_list ap, char flag)
{
    return my_put_nbr(va_arg(ap, int));
}

static int case_s(va_list ap, char flag)
{
    return my_putstr(va_arg(ap, char *));
}

int check_flag(char flag, va_list ap)
{
    char *flag_list = "ids";
    int (*function[3])(va_list, char) = {case_d,
        case_d, case_s};

    for (int i = 0; i < 3; i++) {
        if (flag == flag_list[i]) {
            return ((function[i])(ap, flag));
        }
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int count = 0;

    va_start(ap, format);
    while (format[i]) {
        if (format[i] == '%') {
            count = count + check_flag(format[i + 1], ap);
            i++;
        } else {
            count ++;
            my_putchar(format[i]);
        }
        i++;
    }
    va_end(ap);
    return count;
}
