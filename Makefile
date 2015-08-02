CC = g++
FLAGS = -Wall -Wextra -Werror
EXEC = xor-algorithm

all:
	$(CC) src/main.cpp -o $(FLAGS)

clear:
	rm -f $(CC)
