##
## EPITECH PROJECT, 2022
## Makefile ls binary
## File description:
## MY_LS
##

CC = gcc
SRC = $(shell find src/ -type f -name '*.c')
OBJ = $(SRC: .c=.o)
CFLAGS  = -Wall -Wextra -O2
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
		@echo "\033[1;33mStarting...\033[0m"
	   $(CC) -o $(NAME) $(SRC) $(DIR)libmy.a $(CFLAGS)
		@echo "\033[1;33mThose warnings are here because I'm using -O2 for optimization.\033[0m"
		@echo "\033[1;32m[Process completed]\033[0m"