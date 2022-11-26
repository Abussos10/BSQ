/*
** EPITECH PROJECT, 2022
** Biggest Square project
** File description:
** bsq
*/

#include "../include/bsq.h"

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (_ERROR_WRONG_ARG_);
    struct stat buf;
    char *buffer;
    int size, fd, error = 0;
    if (ac == 2) {
        stat(av[1], &buf);
        size = buf.st_size;
        buffer = malloc(sizeof(char *) * (size + 1));
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return (_ERROR_EMPTY_FILE_);
        read(fd, buffer, size);
        error = bsq(buffer, size);
        close(fd);
        free(buffer);
    } else
        return (map_error(av[1], av[2]));
    return (error);
}

// calling every function i need to resolve a map
int bsq(char *buffer, int size)
{
    int error = 0;
    st_bsq in;
    in.bytes = size;
    error = fill_struct(&in, buffer);
    if (parse_map(&in) != 0) {
        free_array(&in);
        return (_ERROR_CORRUPTED_MAP_);
    }
    if (in.largest != 0)
        print_x(&in);
    display_map(in);
    free_array(&in);
    return (error);
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
