#include "head.h"

/**
 * conv_3dp_to_2dp - Convert 3d point to 2d point
 *
 * @renderer: pointer to the render element in instance structure
 * @vect3: pointer to the structure vec3, point get in 3 dimentions
 * to be converted in a 2 dimentions point
 * @vect2: pointer to the structure vec2 where the point converted
 * will be stored
 */
void conv_3dp_to_2dp(SDL_Renderer *renderer, vec3 *vect3, vec2 *vect2)
{
	double angle = 60, rad = angle / 180,
	       fact_x = cos(rad), fact_y = sin(rad),
	       xx = (vect3->x * fact_x), yx = (vect3->y * fact_x),
	       zx = 0,
	       xy = (vect3->x * fact_y), yy = (vect3->y * fact_y),
	       zy = vect3->z;

	if (vect3->y)
	{
		yx = yx * (-1);
	}

	if (vect3->z)
	{
		zx = zx * (-1);
		zy = zy * (-1);
	}

	vect2->x = xx + yx + zx;
	vect2->y = xy + yy + zy;
}

/**
 * rot_3d_in_z - Rotate a point about the Z axis
 *
 * @renderer: pointer to the render element in instance structure
 * @vect3: pointer to the structure vec3, point get in 3 dimentions
 * to be rotated
 * @angle: angle that we'll use to rotate the point
 */
void rot_3d_in_z(SDL_Renderer *renderer, vec3 *vect3, int angle)
{
	float a;
	int Rx, Ry;

	a = angle * M_PI / 180;

	Rx = vect3->x * cos(a) - vect3->y * sin(a);
	Ry = vect3->x * sin(a) + vect3->y * cos(a);

	vect3->x = Rx;
	vect3->y = Ry;
}

/**
 * draw_plane - set points as a chess table
 *
 * @renderer: pointer to the render
 */

/* Draw 3D ejes */
void draw_plane(SDL_Renderer *renderer)
{
	vec3 vect3;
	vec2 vect2;
	int i, x = window_width / 2, y = window_height / 2;
	int array_coord[3][3] = {
		{400, 0, 0},
		{0, 400, 0},
		{0, 0, 400}
	};

	for (i = 0; i < 3; i++)
	{
		vect3.x = array_coord[i][0];
		vect3.y = array_coord[i][1];
		vect3.z = array_coord[i][2];
		conv_3dp_to_2dp(renderer, &vect3, &vect2);
		/* Eje X */
		if (i == 0)
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		/* Eje Y */
		if (i == 1)
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		/* Eje Z */
		if (i == 2)
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		SDL_RenderDrawLine(renderer,
				x, y,
				x + vect2.x, y + vect2.y);
	}
}

