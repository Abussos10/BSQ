##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## C POOL DAY 10
##

CC = gcc

INCLUDE = $(wildcard '*.h')
DIR = ../../include/
LIBS = libmy.a

SRC = $(shell find . -type f -name '*.c')
CFLAGS = -I $(DIR)$(INCLUDE) -Wall -Wextra
OBJ = $(SRC:.c=.o)

$(LIBS): $(OBJ)
	@mkdir -p $(DIR)
	$(CC) -c $(SRC)
	ar rc $(LIBS) $(OBJ)
	cp -n $(LIBS) $(DIR)$(LIBS)
	#cp -n $(LIBS) ../$(LIBS)
	#cp -n $(LIBS) ../../
	make clean

clean:
	rm -f *.o *~

clear:
	find ../../ -name "*.a" -type f -delete

re:
	make clear ; make
