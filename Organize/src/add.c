/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-camille.billard
** File description:
** add
*/

#include "../include/shell.h"

type is_wrong_type(char *to_test)
{
    if (my_strcmp(to_test, "ACTUATOR") == 0)
        return ACTUATOR;
    if (my_strcmp(to_test, "DEVICE") == 0)
        return DEVICE;
    if (my_strcmp(to_test, "PROCESSOR") == 0)
        return PROCESSOR;
    if (my_strcmp(to_test, "SENSOR") == 0)
        return SENSOR;
    if (my_strcmp(to_test, "WIRE") == 0)
        return WIRE;
    return 84;
}

int add(void *data, char **args)
{
    list **hardware = (list **)data;
    static int add_ID = 0;
    type type;

    for (int index = 0; args[index]; index += 2) {
        type = is_wrong_type(args[index]);
        if (type == 84 || args[index + 1] == NULL)
            return 84;
        my_putstr(args[index], 1);
        my_putstr(" n°", 1);
        my_putnbr(add_ID, 1);
        my_putstr(" - \"", 1);
        my_putstr(args[index + 1], 1);
        my_putstr("\" added.\n", 1);
        *hardware = add_list(hardware, type, args[index + 1], add_ID);
        add_ID++;
    }
    return (args[0] == NULL) * 84;
}
