##
## EPITECH PROJECT, 2022
## Makefile ls binary
## File description:
## MY_LS
##

CC = gcc
SRC = $(shell find src/ -type f -name '*.c')
OBJ = $(SRC: .c=.o)
CFLAGS  = -Wall -Wextra -g
DIR = include/
NAME = bsq

all: libuild build

libuild:
	cd lib/my ; make
clean:
	rm -f *.o
fclean:
	rm -f $(NAME)
re: fclean all

build: libuild
	   $(CC) -o $(NAME) $(SRC) $(DIR)libmy.a $(CFLAGS)
