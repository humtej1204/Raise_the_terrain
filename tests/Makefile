# Variables
CC = gcc
SDL2_FLAGS = `sdl2-config --cflags --libs`
CFLAGS = -lm

# Targets
all:
	rm -rf 0 01 02 03 04 05 06 07

test: test.c 3d_functions.c 3d_functions_02.c
	$(CC) test.c 3d_functions.c 3d_functions_02.c 2d_functions.c $(SDL2_FLAGS) $(CFLAGS) -o 0

1: main.c
	$(CC) main.c $(SDL2_FLAGS) -o 01

2: main_02.c
	$(CC) main_02.c $(SDL2_FLAGS) -o 02

3: SDL_RenderDrawLine.c
	$(CC) SDL_RenderDrawLine.c $(SDL2_FLAGS) -o 03

4: SDL_RenderDrawLines.c
	$(CC) SDL_RenderDrawLines.c $(SDL2_FLAGS) -o 04

5: SDL_RenderDrawPoints.c
	$(CC) SDL_RenderDrawPoints.c $(SDL2_FLAGS) -o 05

6: 03_lines_3d_plane.c 3d_functions.c 3d_functions_02.c
	$(CC) 03_lines_3d_plane.c 3d_functions.c 3d_functions_02.c $(SDL2_FLAGS) $(CFLAGS) -o 06

7: 04_lines_grid_3d_level01.c 3d_functions.c 3d_functions_02.c
	$(CC) 04_lines_grid_3d_level01.c 3d_functions.c 3d_functions_02.c $(SDL2_FLAGS) $(CFLAGS) -o 07
