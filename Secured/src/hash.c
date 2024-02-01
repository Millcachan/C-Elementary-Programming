/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-secured-titouan.pradoura
** File description:
** hash.c
*/

#include "../include/hashtable.h"

int power_ten(int n)
{
    int result = 1;

    for (int i = 0; i < n; ++i) {
        result *= 10;
    }
    return result;
}

int get_middle_number(unsigned long long number, int nb_number)
{
    int size_nb = 0;
    int middlePosition;
    int middle_nb;
    unsigned long long temp = number;

    while (temp != 0) {
        temp /= 10;
        ++size_nb;
    }
    middlePosition = (size_nb - nb_number) / 2;
    middle_nb = (number / power_ten(middlePosition)) % power_ten(nb_number);
    return middle_nb;
}

int mid_square_quarter(char *key, int start, int end)
{
    int total = 0;

    for (int i = start; i < end; i++) {
        total += key[i] * key[i];
    }
    if (total == 0)
        total = 256;
    total *= total;
    return get_middle_number(total, 2);
}

int hash(char *key, int tab_len)
{
    int len;
    unsigned long long value = 0;

    if (!key)
        return 84;
    len = my_strlen(key);
    value += mid_square_quarter(key, 0, len / 4);
    value *= 100;
    value += mid_square_quarter(key, len / 4, len / 2);
    value *= 100;
    value += mid_square_quarter(key, len / 2, len / 4 + len / 2);
    value *= 100;
    value += mid_square_quarter(key, len / 4 + len / 2, len);
    value *= value;
    return get_middle_number(value, 6);
}
