/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** test_new_hashtable.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void);

Test (new_hashtable, creating_hashtable_bad_len, .init=redirect_all_std)
{
    cr_assert_null(new_hashtable(&hash, -1));
}

Test (new_hashtable, creating_hashtable, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    cr_assert_eq(10, ht->size);
}
