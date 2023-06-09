/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include "../include/my.h"
    #define _ERROR_EMPTY_FILE_          84
    #define _ERROR_WRONG_ARG_           84
    #define _ERROR_WRONG_SIZE_INPUT_    84
    #define _ERROR_WRONG_PATTERN_INPUT_ 84
    #define _ERROR_EMPTY_MAP_           84
    #define _ERROR_CORRUPTED_MAP_       84
    #define _ERROR_CORRUPTED_COLS_      84

    #define CHUNK                       4096

typedef struct bsq_infos {
    int **map;
    char *buffer;
    int rows;
    int cols;
    int size;
    int bytes;

    int orix;
    int oriy;

    int bsqx;
    int bsqy;
    int largest;
    int sqrsize;
    int count;

    int error;
    int point;
} st_bsq;

// bsq.c :
int bsq(char *buffer, int size);
void print_x(st_bsq *in);

// array_handling.c :
int fill_struct(st_bsq *in, char *buffer);
int create_array(st_bsq *in);
void free_array(st_bsq *in);

// tools.c
int get_map_size(char *buffer);
int get_start(char *buffer);
int check_point(char c);
int get_cols(char *buffer);

// parse_map.c
int parse_map(st_bsq *in);
int check_sqr(st_bsq *in, int x, int y);
int covid(st_bsq *in, int x, int y);
int spread(st_bsq *in, int x, int y, int size);
void store_largest(st_bsq *in, int count);

// generate.c
int map_error(char *size, char *pattern);
int generating_map(char *size, char *pattern, int nsize);
char *fill_map(char *map, char *size, char *pattern, int slen);

// special_case.c
int print_one(st_bsq *in);
int check_one(st_bsq *in, int x, int y);
void store_one(st_bsq *in, int x, int y);

// display.c
void display_map(st_bsq in);
int rec_chunk(st_bsq in, char *map);
int print_chunk(char *map, int size, int start, int end);

#endif /* !BSQ_H_ */
