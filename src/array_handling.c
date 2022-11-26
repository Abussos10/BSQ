/*
** EPITECH PROJECT, 2022
** MAP
** File description:
** array_handling
*/

#include "../include/bsq.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function that fill fill some value and initialize to zero others
int fill_struct(st_bsq *in, char *buffer)
{
    in->buffer = buffer;
    in->size = get_map_size(buffer);
    in->rows = in->size;
    in->cols = get_cols(buffer);
    in->orix = 0, in->oriy = 0, in->bsqx = 0, in->bsqy = 0;
    in->count = 0, in->largest = 0, in->point = 0, in->error = 0;
    in->error = create_array(in);
    return (in->error);
}

// function that create the array i will use to parse my map
int create_array(st_bsq *in)
{
    int i, j, start = get_start(in->buffer);
    in->map = malloc(in->rows * sizeof(int *));

    for (i = 0; i < in->rows; i++)
        in->map[i] = malloc(in->cols * sizeof(int));

    for (i = 0; i < in->rows; i++) {
        for (j = 0; j < in->cols; j++, start++)
            in->map[i][j] = in->buffer[start];
        if (in->map[i][in->cols - 1] != '\n')
            return (_ERROR_CORRUPTED_COLS_);
    }

    return (0);
}

// function that free my 2D Array
void free_array(st_bsq *in)
{
    int i;

    for (i = 0; i < in->rows; i++)
        free(in->map[i]);
    free(in->map);
}
