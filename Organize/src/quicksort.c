/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-camille.billard
** File description:
** quick_sort
*/

#include "../include/shell.h"

static list *partition(list *first, list *last, int (*cmp)())
{
    list *pivot = first;
    list *front = first;
    data_t *temp = 0;

    while (front != NULL && front != last) {
        if (cmp(front->data, last->data) <= 0) {
            pivot = first;
            temp = first->data;
            first->data = front->data;
            front->data = temp;
            first = first->next;
        }
        front = front->next;
    }
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}

void quick_sort(list *first, list *last, int (*cmp)())
{
    list *pivot = partition(first, last, cmp);

    if (first == last)
        return;
    if (pivot != NULL && pivot->next != NULL)
        quick_sort(pivot->next, last, cmp);
    if (pivot != NULL && first != pivot)
        quick_sort(first, pivot, cmp);
}
