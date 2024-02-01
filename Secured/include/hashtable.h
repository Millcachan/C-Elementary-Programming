/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/


#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include <stdlib.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <limits.h>
    #include <stdio.h>

typedef struct case_s {
    int hash;
    char *value;
    struct case_s *next;
} case_t;

typedef struct line_s {
    int index;
    case_t *cases;
} line_t;

typedef struct hashtable_s {
    int (*hash)(char *, int);
    int size;
    line_t **lines;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

//Lib
int my_putchar(char c);
int my_put_nbr(long long nb);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_strdup(char const *src);
int mini_printf(const char *format, ...);

#endif /* HASHTABLE_H */
