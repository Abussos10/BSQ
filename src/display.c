/*
** EPITECH PROJECT, 2022
** DISPLAY MAP BY CHUNKS
** File description:
** display
*/

#include "../include/bsq.h"

// displaying the map with only one system call
void display_map(st_bsq in)
{
    int x, y, i = 0;
    char *map = (char *) malloc((in.bytes + 1) * sizeof(char));

    for (x = 0; x < in.rows; x++) {
        for (y = 0; y < in.cols; y++, i++) {
            map[i] = in.map[x][y];
        }
    }
    map[i + 1] = '\0';
    rec_chunk(in, map);
    free(map);
}

// hardly calculating how many chunks to print (ratio)
int rec_chunk(st_bsq in, char *map)
{
    int i, start, end = CHUNK;
    int nbchunk = (in.bytes / CHUNK) + 1;
    int lastchunk = (in.bytes % CHUNK) - get_int_len(in.size);
    for (i = 1, start = 0; i < nbchunk; i++, start += CHUNK, end += CHUNK)
        print_chunk(map, CHUNK, start, end);
    end -= CHUNK;
    end += lastchunk;
    print_chunk(map, lastchunk - 2, start, end - 1);

    return (0);
}

// allocating and printing a chunk of (4096 bytes)
int print_chunk(char *map, int size, int start, int end)
{
    char *chunk = (char *) malloc((size + 1) * sizeof(char));
    int i, j = 0;
    for (i = start; i != end; i++, j++)
        chunk[j] = map[i];
    write(1, chunk, size);
    free(chunk);

    return (0);
}
