/*
** EPITECH PROJECT, 2022
** SPECIAL CASES
** File description:
** special_cases
*/

#include "../include/bsq.h"

// checking for single square
int print_one(st_bsq *in)
{
    int x, y = 0;
    for (x = in->rows - 1; x >= 0; x--) {
        for (y = in->cols - 2; y >= 0; y--) {
            check_one(in, x, y);
        }
    }
    return (0);
}

// checking for one sqr
int check_one(st_bsq *in, int x, int y)
{
    char curr = in->map[x][y];
    if (curr != '.')
        return (1);
    if (curr == '.')
        store_one(in, x, y);

    return (0);
}

// storing last one sqr
void store_one(st_bsq *in, int x, int y)
{
    in->largest = 1;
    in->sqrsize = 1;
    in->orix = x;
    in->oriy = y;
}
