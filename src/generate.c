/*
** EPITECH PROJECT, 2022
** GENERATE BOARD
** File description:
** generate
*/

#include "../include/my.h"
#include "../include/bsq.h"
#include <stdio.h>
#include <stdlib.h>

int map_error(char *size, char *pattern)
{
    int nsize = 0;
    if (is_number(size) == 0)
        return (_ERROR_WRONG_SIZE_INPUT_);
    if (is_bsq_friendly(pattern) == 0)
        return (_ERROR_WRONG_PATTERN_INPUT_);
    if ((nsize = my_getnbr(size)) <= 0)
        return (_ERROR_EMPTY_MAP_);
    generating_map(size, nsize, pattern);

    return (0);
}

// EN COURS...
int generating_map(char *size, int nsize, char *pattern)
{
    int len = (nsize * (nsize + 1)) + get_int_len(nsize) + 2;
    int *map = malloc(len * sizeof(char) + 1);
    map[len] = '\0';
    int i;
    return (0);
}
