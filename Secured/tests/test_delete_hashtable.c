/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** test_delete_hashtable.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void);

Test (delete_hashtable, delete_hashtable_NULL, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, -10);
    delete_hashtable(ht);
}

Test (delete_hashtable, delete_good_hashtable, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    delete_hashtable(ht);
}

Test (delete_hashtable, delete_filled_hashtable, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 10);
    ht_insert(ht, "HEY", "Value");
    delete_hashtable(ht);
}
