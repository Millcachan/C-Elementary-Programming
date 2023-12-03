/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-settingup-camille.billard
** File description:
** generator
*/

#include "../include/my.h"

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

static int test_pattern(char *pattern, char *charside, int *side)
{
    for (int i = 0; pattern[i] != '\0'; i++)
        if (pattern[i] != '.' && pattern[i] != 'o' && pattern[i] != '\0')
            return 1;
    for (int i = 0; charside[i] != '\0'; i++) {
        if (charside[i] < '0' || charside[i] > '9')
            return 1;
        *side *= 10;
        *side += charside[i] - 48;
    }
    return 0;
}

char *create_map(int side, char *pattern, char *charside)
{
    int size = side * (side + 1) + my_strlen(charside) + 1;
    char *buf = malloc(sizeof(char) * (size + 1) + 1);
    int p_position = 0;
    int i;

    for (i = 0; i < (size + 1) + 1; i++)
        buf[i] = '\0';
    for (i = 0; i < my_strlen(charside); i++)
        buf[i] = charside[i];
    for (i = 0; i < (side * (side + 1) + 1); i++) {
        if (i % (side + 1) == 0) {
            buf[i + my_strlen(charside)] = '\n';
            continue;
        }
        if (p_position == my_strlen(pattern) )
            p_position = 0;
        buf[i + my_strlen(charside)] = pattern[p_position];
        p_position++;
    }
    return buf;
}

int *set_map_generator(char *buf, int side, char *charside)
{
    int i = 0;
    int x = 0;
    int *map = malloc(sizeof(int *) * (side * side) + my_strlen(charside) + 2);

    while (buf[i] != '\n')
        i++;
    for (x = 0; buf[++i] != '\0'; x++)
        map[x] = check_char(buf[i]);
    map[x] = -2;
    return map;
}

struct map *map_generator(char *charside, char *pattern)
{
    struct map *map = malloc(sizeof(struct map));
    int side = 0;

    if (pattern[0] == '\0') {
        free(map);
        exit(84);
    }
    if (test_pattern(pattern, charside, &side) == 1) {
        free(map);
        exit(84);
    }
    map->height = side;
    map->length = side;
    map->buf = create_map(side, pattern, charside);
    if (map->buf[0] == '\0') {
        free(map);
        exit(84);
    }
    map->map = set_map_generator(map->buf, side, charside);
    return map;
}
