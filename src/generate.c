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

// some handling error for map generation case
int map_error(char *size, char *pattern)
{
    int nsize = 0;
    if (is_number(size) == 0)
        return (_ERROR_WRONG_SIZE_INPUT_);
    if (is_bsq_friendly(pattern) == 0)
        return (_ERROR_WRONG_PATTERN_INPUT_);
    if ((nsize = my_getnbr(size)) <= 0)
        return (_ERROR_EMPTY_MAP_);
    generating_map(size, pattern, nsize);

    return (0);
}

// allocating the right size for my map generation
int generating_map(char *size, char *pattern, int nsize)
{
    int slen = (nsize * (nsize + 1)) + get_int_len(nsize) + 2;
    char *map = (char *) malloc((slen + 1) * sizeof(char));
    map = fill_map(map, size, pattern, slen);
    bsq(map, slen - 1);
    free(map);
    return (0);
}

// function that fill my allocated map with pattern
char *fill_map(char *map, char *size, char *pattern, int slen)
{
    int i, j = 0, gap, index = 0, nsize = my_getnbr(size);
    for (i = 0; size[i] != '\0'; i++, index++)
        map[index] = size[i];
    map[index] = '\n';
    for (i = 0, gap = 1, index++; index < slen; index++, i++, gap++) {
        if (pattern[i] == '\0')
            i = 0;
        if (gap == nsize + 1) {
            map[index] = '\n';
            i--, j++;
            gap = 0;
            continue;
        }
        if (j < nsize)
            map[index] = pattern[i];
    }
    map[slen] = '\0';
    return (map);
}
