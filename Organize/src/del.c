/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-camille.billard
** File description:
** del
*/

#include "../include/shell.h"

int del(void *data, char **args)
{
    list **hardware = (list **)data;

    if (!(*hardware))
        return 84;
    for (int i = 0; args[i] != NULL; i++)
        if (del_node(hardware, str_to_int(args[i])) == 84)
            return 84;
    return 0;
}
