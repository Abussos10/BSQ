/*
** EPITECH PROJECT, 2022
** Biggest Square project
** File description:
** bsq
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/bsq.h"

int main(int ac, char **av)
{
    struct stat buf;
    stat(av[1], &buf);
    int size = buf.st_size;
    char *buffer = malloc(sizeof(char *) * (size + 1));
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (_ERROR_EMPTY_FILE_);
    read(fd, buffer, size);
    bsq(buffer, size);
    free(buffer);
    close(fd);
    return (0);
}

int bsq(char *buffer, int size)
{
    st_bsq in;
    in.bytes = size;
    fill_struct(&in, buffer);
    parse_map(&in);
    print_x(&in);
    display_map(in);
    free_array(&in);
    return (0);
}

// replacing every case of the bsq afterward
void print_x(st_bsq *in)
{
    int x, y;
    for (x = in->bsqx; x > (in->bsqx - in->sqrsize); x--) {
        for (y = in->bsqy; y > (in->bsqy - in->sqrsize); y--) {
            in->map[x][y] = 'x';
        }
    }
}

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
    write(1, map, in.bytes);
}
