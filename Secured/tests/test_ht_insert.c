/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** test_ht_insert.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void);

Test (ht_insert, insert_in_null_ht, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, -10);
    ht_insert(ht, "Hey", "Value");
    delete_hashtable(ht);
}

Test (ht_insert, good_insert, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    ht_insert(ht, "HEY", "Value");
    delete_hashtable(ht);
}

Test (ht_insert, insert_null_key, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    ht_insert(ht, NULL, "Value");
    delete_hashtable(ht);
}

Test (ht_insert, change_cells_value, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_insert(ht, "aartekl=oa", "Hery");
    ht_insert(ht, "b", "Hery");
    ht_insert(ht, "b", "Second value");
    delete_hashtable(ht);
}

Test (ht_insert, insert_null_value, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    ht_insert(ht, "Value", NULL);
    delete_hashtable(ht);
}