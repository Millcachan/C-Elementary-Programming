/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-camille.billard
** File description:
** main
*/

#include "../include/shell.h"

int main(int argc, char **argv)
{
    list *head = NULL;
    int return_value = 0;

    if (argc != 1 && my_strcmp(argv[0], "./organized") == 0)
        return 84;
    return_value = workshop_shell(&head);
    free_list(head);
    return return_value;
}
