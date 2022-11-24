/*
** EPITECH PROJECT, 2022
** STRDUP
** File description:
** CPOOL DAY 8
*/

#include <stddef.h>
#include <stdlib.h>

int len(char const *str);

char *my_strdup(char const *src)
{
    char *dup;
    int i;

    dup = malloc(len(src) + 1);

    if (dup == NULL)
        return (0);

    for (i = 0; src[i] != '\0'; i++)
        dup[i] = src[i];

    return (dup);
}
