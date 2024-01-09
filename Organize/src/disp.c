/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-camille.billard
** File description:
** disp
*/

#include "../include/shell.h"

int disp(void *data, char **args)
{
    list **hardware = (list **)data;
    list *temp = *hardware;
    char *types[5] = {"ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE"};

    if (args[0])
        return 84;
    while (temp) {
        my_putstr(types[temp->data->type], 1);
        my_putstr(" n°", 1);
        my_putnbr(temp->data->ID, 1);
        my_putstr(" - \"", 1);
        my_putstr(temp->data->name, 1);
        my_putstr("\"\n", 1);
        temp = temp->next;
    }
    return 0;
}
