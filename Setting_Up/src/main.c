/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-camille.billard
** File description:
** main
*/

#include "../include/my.h"

void error_handling_generator(int ac)
{
    if (ac != 3)
        exit(84);
}

void error_handling_file(int stat, struct stat *buf)
{
    if (stat == -1)
        exit(84);
    if (S_ISDIR(buf->st_mode) != 0)
        exit(84);
    if (buf->st_size == 0)
        exit(84);
}

int main(int ac, char **av)
{
    struct stat buf;
    struct map *map;
    struct max *max;

    if (ac == 2) {
        error_handling_file(stat(av[1], &buf), &buf);
        map = fill_map(av[1], buf.st_size);
    } else {
        error_handling_generator(ac);
        map = map_generator(av[1], av[2]);
    }
    max = algo(map->map, map->length);
    biggest_square(map, max);
    my_putmap(map->buf);
    free(map->map);
    free(map->buf);
    free(map);
    free(max);
    return 0;
}
