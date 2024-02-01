/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** test_ht_delete.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void);

Test (ht_delete, delete_in_null_ht, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, -10);
    ht_insert(ht, "Hey", "Value");
    cr_assert_eq(84, ht_delete(ht, "Hey"));
    delete_hashtable(ht);
}

Test (ht_delete, good_delete, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    ht_insert(ht, "HEY", "Value");
    cr_assert_eq(0, ht_delete(ht, "HEY"));
    delete_hashtable(ht);
}

Test (ht_delete, delete_NULL, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    ht_insert(ht, "Hey", "Value");
    cr_assert_eq(84, ht_delete(ht, NULL));
    delete_hashtable(ht);
}

Test (ht_delete, delete_in_multiple_cells, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_insert(ht, "aartekl=oa", "Hery");
    ht_insert(ht, "b", "Hery");
    cr_assert_eq(0, ht_delete(ht, "b"));
    delete_hashtable(ht);
}

Test (ht_delete, delete_in_multiple_cells_second, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_insert(ht, "aartekl=oa", "Hery");
    ht_insert(ht, "b", "Hery");
    cr_assert_eq(0, ht_delete(ht, "aartekl=oa"));
    delete_hashtable(ht);
}