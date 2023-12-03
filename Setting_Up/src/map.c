/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-camille.billard
** File description:
** map
*/

#include "../include/my.h"

static int mini(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    if (c <= a && c <= b)
        return c;
    return 84;
}

static void max_value(struct max *max, int min, int x, int y)
{
    if (min > max->value) {
        max->value = min;
        max->x = x;
        max->y = y;
    }
    return;
}

static int get_length(char const *filepath)
{
    char buf[1];
    int fd = open(filepath, O_RDONLY);
    int length = 0;

    read(fd, buf, 1);
    while (buf[0] != '\n')
        read(fd, buf, 1);
    read(fd, buf, 1);
    while (buf[0] != '\n') {
        read(fd, buf, 1);
        length++;
    }
    close(fd);
    return length;
}

static int get_height(char const *filepath)
{
    char buf[1];
    int fd = open(filepath, O_RDONLY);
    int nb = 0;

    if (fd == -1)
        exit(84);
    read(fd, buf, 1);
    while (buf[0] != '\n') {
        if (buf[0] >= '0' && buf[0] <= '9') {
            nb = nb * 10;
            nb += (buf[0] - 48);
            read(fd, buf, 1);
            continue;
        }
        close(fd);
        exit(84);
    }
    close(fd);
    return nb;
}

static int check_char(char c)
{
    if (c == '\n')
        return -1;
    if (c == 'o')
        return 0;
    if (c == '.')
        return 1;
    exit(84);
}

int *set_map(char const *filepath, off_t size, char *buf, int nb)
{
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    int x = 0;
    int *map = malloc(size * sizeof(int));
    int height = 0;

    buf[read(fd, buf, size)] = '\0';
    while (buf[i] != '\n')
        i++;
    for (x = 0; buf[++i] != '\0'; x++) {
        map[x] = check_char(buf[i]);
        height += (map[x] == -1);
    }
    if (height != nb || nb == 0) {
        free(map);
        exit(84);
    }
    map[x] = -2;
    close(fd);
    return map;
}

struct map *fill_map(char const *filepath, off_t size)
{
    struct map *map = malloc(sizeof(struct map));
    char *buf = malloc(sizeof(char) * size + 1);

    map->height = get_height(filepath);
    map->length = get_length(filepath);
    map->buf = buf;
    map->map = set_map(filepath, size, buf, map->height);
    return map;
}

struct max *algo(int *map, int l)
{
    struct max *max = malloc(sizeof(struct max));
    int h = -1;

    *max = (struct max){0};
    for (int i = 0; map[i] != -2; i++)
        if (map[i] > max->value)
            max_value(max, map[i], i, h++);
    for (int i = l + 1; map[i] != -2; i++) {
        if (i % (l + 1) == 0 && map[i] > max->value)
            max_value(max, map[i], i % (l + 1), h);
        if (i % (l + 1) == 0)
            continue;
        h = (i % (l + 1) == 0) ? h : h + (map[i] == -1);
        if (map[i] == 1) {
            map[i] = mini(map[i - 1], map[i - (l + 1)], map[i - (l + 2)]) + 1;
            max_value(max, map[i], i % (l + 1), h);
        }
    }
    return max;
}

void biggest_square(struct map *map, struct max *max)
{
    int pos = max->x + ((max->y + 1) * (map->length + 1));
    int nbr = 0;

    while (map->buf[nbr] != '\n')
        nbr++;
    nbr++;
    for (int i = 0; i < max->value; i++) {
        for (int j = 0; j < max->value; j++) {
            map->buf[pos + nbr - i - (j * (map->length + 1))] = 'x';
        }
    }
}
