/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-camille.billard
** File description:
** list
*/

#include "../include/shell.h"

list *free_list(list *hardware)
{
    list *temp = NULL;

    while (hardware) {
        temp = hardware->next;
        free(hardware->data->name);
        free(hardware->data);
        free(hardware);
        hardware = temp;
    }
    return (hardware);
}

int my_list_size(list const *begin)
{
    int len = 0;

    while (begin) {
        len++;
        begin = begin->next;
    }
    return (len);
}

static void free_node(list *to_free)
{
    char *types[5] = {"ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE"};

    my_putstr(types[to_free->data->type], 1);
    my_putstr(" n°", 1);
    my_putnbr(to_free->data->ID, 1);
    my_putstr(" - \"", 1);
    my_putstr(to_free->data->name, 1);
    my_putstr("\" deleted.\n", 1);
    free(to_free->data->name);
    free(to_free->data);
    free(to_free);
}

int del_node(list **head, int ID)
{
    list *temp;
    list *current = *head;

    if ((*head)->data->ID == ID) {
        temp = *head;
        *head = (*head)->next;
        free_node(temp);
        return 0;
    }
    while (current->next != NULL) {
        if (current->next->data->ID == ID) {
            temp = current->next;
            current->next = current->next->next;
            free_node(temp);
            return 0;
        }
        current = current->next;
    }
    return 84;
}

static list *create_cell(type type, char *name, int ID)
{
    list *cell = malloc(sizeof(list));
    data_t *data = malloc(sizeof(data_t));

    if (!cell || !data)
        return (NULL);
    data->type = type;
    data->name = my_strdup(name);
    data->ID = ID;
    cell->next = NULL;
    cell->data = data;
    return (cell);
}

list *add_list(list **hardware, type type, char *name, int ID)
{
    list *cell = create_cell(type, name, ID);

    cell->next = *hardware;
    return (cell);
}

void my_rev_list(list **begin)
{
    list *next = NULL;
    list *previous = NULL;
    list *current = *begin;

    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *begin = previous;
}
