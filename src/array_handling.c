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

void fill_struct(st_bsq *in, char *buffer)
{
    in->buffer = buffer;
    in->size = get_map_size(buffer);
    in->rows = in->size;
    in->cols = in->size + 1;
    in->orix = 0;
    in->oriy = 0;
    in->bsqx = 0;
    in->bsqy = 0;
    in->count = 0;
    in->largest = 0;
    create_array(in);
}

void create_array(st_bsq *in)
{
    int i, j, start = get_start(in->buffer);
    in->map = malloc(in->rows * sizeof(int *));

    for (i = 0; i < in->rows; i++)
        in->map[i] = malloc(in->cols * sizeof(int));

    for (i = 0; i < in->rows; i++) {
        for (j = 0; j < in->cols; j++, start++)
            in->map[i][j] = in->buffer[start];
    }

}

void free_array(st_bsq *in)
{
    int i;

    for (i = 0; i < in->rows; i++)
        free(in->map[i]);
    free(in->map);
}
