/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_
    #define _ERROR_EMPTY_FILE_ 85

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

} st_bsq;

// bsq.c :
int bsq(char *buffer, int size);
void print_x(st_bsq *in);

// array_handling.c :
void fill_struct(st_bsq *in, char *buffer);
void create_array(st_bsq *in);
void free_array(st_bsq *in);

// tools.c
int get_map_size(char *buffer);
int get_start(char *buffer);
int check_point(char c);


// parse_map.c
void parse_map(st_bsq *in);
int check_sqr(st_bsq *in, int x, int y);
int covid(st_bsq *in, int x, int y);
int spread(st_bsq *in, int x, int y, int size);
void store_largest(st_bsq *in, int count);


void display_map(st_bsq in);

#endif /* !BSQ_H_ */
