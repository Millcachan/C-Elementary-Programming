/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** A simplified version of the printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void);

Test (mini_printf, check_false_flags, .init=redirect_all_std)
{
    mini_printf("%t", "hey");
    cr_assert_stdout_eq_str("");
}

Test (mini_printf, all_int, .init=redirect_all_std)
{
    mini_printf("%d %d %d %d", 0, 1234, 1000, 1290);
    cr_assert_stdout_eq_str("0 1234 1000 1290");
}