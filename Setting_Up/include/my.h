/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef MY_H
    #define MY_H

struct max {
    int x;
    int y;
    int value;
};

struct map {
    char *buf;
    int height;
    int length;
    int *map;
};

int my_putstr(char *str);
int my_strlen(char *str);
void my_putmap(char *buf);
void my_putnbr(long long nbr);
struct max *algo(int *map, int l);
void biggest_square(struct map *map, struct max *max);
struct map *fill_map(char const *filepath, off_t size);
struct map *map_generator(char *charside, char *pattern);
int *set_map(char const *filepath, off_t size, char *buf, int nb);
#endif
