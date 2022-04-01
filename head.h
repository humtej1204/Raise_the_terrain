#ifndef HEADER
#define HEADER

/* Constants */
#define window_width 1600
#define window_height 900
#define PI 3.14159265

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <SDL2/SDL.h>


/* Structures */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;
/* 2D Vector Struct */
typedef struct vec2
{
        int x, y;
} vec2;
/* 3D Vector Struct */
typedef struct vec3
{
        int x, y, z;
} vec3;
/* Other Elements */
typedef struct elements
{
	int rot_angle;
	int segm_sep;
	int size_fact;
} elem;


/* Prototypes */
int init_instance(SDL_Instance *instance);
int poll_events(elem *elements);

/* Draw Ejes */
void draw_2D_ejes(SDL_Renderer *renderer);
void draw_3D_ejes(SDL_Renderer *renderer);

/* 2D functions */
void draw_grid_2d(SDL_Renderer *renderer, int n);

/* 3D functions */
void draw_grid_3d(SDL_Renderer *renderer, int n, elem *elements);
void draw_pnts(SDL_Renderer *renderer, int n);
void draw_plane(SDL_Renderer *renderer);

/* Matemathical functions */
void conv_3dp_to_2dp(SDL_Renderer *renderer, vec3 *vect3, vec2 *vect2);
void rot_3d_in_z(SDL_Renderer *renderer, vec3 *vect3, int angle);

#endif
