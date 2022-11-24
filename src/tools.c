/*
** EPITECH PROJECT, 2022
** TOOLS FOR BSQ
** File description:
** tools
*/

#include "../include/bsq.h"

// simple function to extract the size from buffer
int get_map_size(char *buffer)
{
    int i, j, size = 0;

    for (i = 0; buffer[i + 1] != '\n'; i++);
    for (j = 1; i >= 0; i--, j *= 10)
            size += (j * (buffer[i] - 48));

    return (size);
}

// function to get the index where the map starts in buffer
int get_start(char *buffer)
{
    int i;

    for (i = 0; buffer[i - 1] != '\n'; i++);

    return (i);
}

// coding style...
int check_point(char c)
{
    if (c == '.')
        return (1);
    else
        return (0);
}
