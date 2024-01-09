/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SHELL_H
    #define SHELL_H

typedef enum hardware_type {
    ACTUATOR,
    DEVICE,
    PROCESSOR,
    SENSOR,
    WIRE
} type;

typedef enum sort {
    NAME,
    TYPE,
    ID,
    NAMER,
    TYPER,
    IDR,
    END
} sort_type;

typedef struct data_s {
    type type;
    char *name;
    int ID;
} data_t;

typedef struct linked_list {
    struct linked_list *next;
    data_t *data;
} list;

int my_strlen(char *str);
char *my_strdup(char *src);
void my_rev_list(list **begin);
int workshop_shell(void *data);
int str_to_int(const char *str);
list *free_list(list *hardware);
void my_putchar(char c, int fd);
int add(void *data, char **args);
int del(void *data, char **args);
int my_putstr(char *str, int fd);
int del_node(list **head, int ID);
int my_strcmp(char *s1, char *s2);
int sort(void *data, char **args);
int disp(void *data, char **args);
int idcmp(data_t *d1, data_t *d2);
int idrcmp(data_t *d1, data_t *d2);
int typecmp(data_t *d1, data_t *d2);
int namecmp(data_t *d1, data_t *d2);
int my_list_size(list const *begin);
int namercmp(data_t *d1, data_t *d2);
int typercmp(data_t *d1, data_t *d2);
void my_putnbr(long long nbr, int fd);
char *my_strcat(char *dest, char *src);
void quick_sort(list *first, list *last, int (*cmp)());
list *add_list(list **hardware, type type, char *name, int ID);

#endif
