/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** test_ht_search.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void);

Test (ht_search, search_in_null, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, -10);
    cr_assert_null(ht_search(ht, "Hey"));
    delete_hashtable(ht);
}

Test (ht_search, search_a_null, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    cr_assert_null(ht_search(ht, NULL));
    delete_hashtable(ht);
}

Test (ht_search, search_existing, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_insert(ht, "aartekl=oa", "Hery");
    ht_insert(ht, "b", "Hery");
    cr_assert_str_eq("Hery", ht_search(ht, "b"));
    delete_hashtable(ht);
}

Test (ht_search, search_not_existing, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_insert(ht, "aartekl=oa", "Hery");
    ht_insert(ht, "b", "Hery");
    cr_assert_null(ht_search(ht, "HEY"));
    delete_hashtable(ht);
}