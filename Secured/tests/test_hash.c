/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** test_hash.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void)
{
    cr_redirect_stdout() ;
    cr_redirect_stderr() ;
}

Test (hash, hashing_NULL, .init=redirect_all_std)
{
    cr_assert_eq(84, hash(NULL, 5));
}

Test (hash, hashing_short_value, .init=redirect_all_std)
{
    cr_assert_eq(850453, hash("Hey", 5));
}