# Variables
CC = gcc
SDL2_FLAGS = `sdl2-config --cflags --libs`
CFLAGS = -lm
FUNCTIONS_FILES = main_functions.c 3d_functions.c 3d_functions_grid.c 2d_functions_grid.c

# Targets
all:
	rm -rf 0 01 02 03 04 05 06 07

test: test.c 3d_functions.c 3d_functions_02.c
	$(CC) test.c $(FUNCTIONS_FILES) $(SDL2_FLAGS) $(CFLAGS) -o 0

1: main.c $(FUNCTIONS_FILES)
	$(CC) main.c $(FUNCTIONS_FILES) $(SDL2_FLAGS) $(CFLAGS) -o 01

