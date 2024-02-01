/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** test_ht_dump.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void);

Test (ht_dump, display_base_ht, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 3);
    char *temp = "[0]:\n[1]:\n[2]:\n";

    ht_dump(ht);
    cr_assert_stdout_eq_str(temp);
    delete_hashtable(ht);
}

Test (ht_dump, display_with_case, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 1);
    char *temp = "[0]:\n> 850453 - Value\n";

    ht_insert(ht, "Hey", "Value");
    ht_dump(ht);
    cr_assert_stdout_eq_str(temp);
    delete_hashtable(ht);
}

Test (ht_dump, display_wrong_ht, .init=redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, -3);
    char *temp = "";

    ht_dump(ht);
    cr_assert_stdout_eq_str(temp);
    delete_hashtable(ht);
}