/*
** EPITECH PROJECT, 2022
** PARSING BSQ MAP AND DOING THE THING
** File description:
** parse_map
*/

#include "../include/bsq.h"
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

// basically parsing map backward
int parse_map(st_bsq *in)
{
    int x, y;

    for (x = in->rows - 1; x >= 0; x--) {
        for (y = in->cols - 2; y >= 0; y--) {
            check_sqr(in, x, y);
        }
    }
    if (in->largest == 0)
        print_one(in);
    return (in->error);
}

// main of checking square functions
int check_sqr(st_bsq *in, int x, int y)
{
    char curr = in->map[x][y];
    if (curr == 'o' || curr == '\n')
        return (0);
    else if (curr == '.' && in->point == 0)
        in->point = 1;

    if (curr != 'o' && curr != '.' && curr != '\n') {
        in->error = _ERROR_CORRUPTED_MAP_;
        return (_ERROR_CORRUPTED_MAP_);
    }
    covid(in, x, y);

    return (0);
}

// checking for each 'origin' position
int covid(st_bsq *in, int x, int y)
{
    in->orix = x;
    in->oriy = y;
    spread(in, (x - 1), (y - 1), 2);

    return (0);
}

// checking for bigger and bigger square (checking diagonal neighborhood)
int spread(st_bsq *in, int x, int y, int size)
{
    int i, j, count = 0;
    if (x < 0 || y < 0 || (x - size) < 0 || (y - size) < 0)
        return (0);
    for (i = x; i < (x + size); i++) {
        for (j = y; j < (y + size); j++)
            count += check_point(in->map[i][j]);
        if (count < 0)
            return (0);
    }
    if (count == size * size) {
        if (count >= in->largest)
            store_largest(in, count);
        return (spread(in, (x - 1), (y - 1), size + 1));
    }

    return (0);
}

// storing the current biggest square in my struct
void store_largest(st_bsq *in, int count)
{
    in->bsqx = in->orix;
    in->bsqy = in->oriy;
    in->largest = count;
    in->sqrsize = my_compute_square_root(count);
}
