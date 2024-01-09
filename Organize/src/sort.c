/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-camille.billard
** File description:
** sort
*/

#include "../include/shell.h"

static int is_wrong_sort(char *sort)
{
    if (my_strcmp(sort, "NAME") == 0)
        return NAME;
    if (my_strcmp(sort, "TYPE") == 0)
        return TYPE;
    if (my_strcmp(sort, "ID") == 0)
        return ID;
    return 84;
}

static list *get_last_node(list *head)
{
    list *temp = head;

    while (temp) {
        if (!temp->next)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void sort_list(list **head, sort_type sort)
{
    list *first_node = *head;
    list *last_node = get_last_node(first_node);

    switch (sort) {
        case NAME:
            return quick_sort(first_node, last_node, &namecmp);
        case TYPE:
            return quick_sort(first_node, last_node, &typecmp);
        case ID:
            return quick_sort(first_node, last_node, &idcmp);
        case NAMER:
            return quick_sort(first_node, last_node, &namercmp);
        case TYPER:
            return quick_sort(first_node, last_node, &typercmp);
        case IDR:
            return quick_sort(first_node, last_node, &idrcmp);
        case END:
            return;
    }
    return;
}

int lentab(char **tab)
{
    int i = 0;

    while (tab[i])
        i++;
    return i;
}

sort_type *reverse_tab(char **args)
{
    int len = lentab(args);
    sort_type *sort_tab = malloc((size_t)((len) * (int)sizeof(sort_type *)));
    int index = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (my_strcmp(args[i], "-r") != 0) {
            sort_tab[index] = is_wrong_sort(args[i]);
        } else {
            sort_tab[index] = (sort_type)(is_wrong_sort(args[i - 1]) + 3);
            i--;
        }
        index++;
    }
    sort_tab[index] = END;
    return sort_tab;
}

int sort(void *data, char **args)
{
    list **head = (list **)data;
    sort_type *sort_tab = reverse_tab(args);

    if (args[0] == NULL)
        return 84;
    for (int i = 0; sort_tab[i] != END; i++) {
        if (sort_tab[i] == 84 || sort_tab[i] == 87)
            return 84;
        sort_list(head, sort_tab[i]);
    }
    free(sort_tab);
    return 0;
}
