#include "head.h"
/**
 * draw_grid_3d - Draw a grid in 3 Dimentions
 *
 * @renderer: pointer to the render element in the instance structure
 * @n: size of the square, amount of points in the height and width
 * @elements: pointer to the structure elem
 */
void draw_grid_3d(SDL_Renderer *renderer, int n, elem *elements)
{
	/* x and y are the zero ejes */
	int x0 = window_width / 2, y0 = window_height * 0.3,
	    x = x0, y = y0, i, j, g = 0;
	vec2 vect2, vect2_1;
	vec3 vect3, vect3_1;

	/* Vectors */
	int array_x[64], array_y[64],
	array_z[64] = {
		120, 60, 40, 60, 20, -20, -80, -120,
		40, 20, 30, 30, -10, -40, -90, -110,
		20, 30, 10, 06, -6, -20, -26, -90,
		00, -6, 10, 10, -6, -20, -20, -40,
		-20, -20, -18, -14, -40, -20, -20, -30,
		-10, -10, -10, -10, -8, -20, -20, -30,
		20, 10, 10, 10, 10, 04, 10, -10,
		30, 24, 24, 22, 20, 18, 14, 16
	};

	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			array_x[g] = i * elements->segm_sep;
			array_y[g] = j * elements->segm_sep;
			g++;
		}
	}
	g = 0;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

	for (j = 0; j <= n; j++)
	{
		for (i = 0; i <= n; i++)
		{
			vect3.x = array_x[g] * elements->size_fact;
			vect3.y = array_y[g] * elements->size_fact;
			vect3.z = array_z[g] * elements->size_fact;
			rot_3d_in_z(renderer, &vect3, elements->rot_angle);
			conv_3dp_to_2dp(renderer, &vect3, &vect2);

			/* Draw Points */
			SDL_RenderDrawPoint(
					renderer,
					x0 + vect2.x, y0 + vect2.y);

			/********** Draw line in X eje **********/
			/* Next point in X eje */
			vect3_1.x = array_x[g + 1] * elements->size_fact;
			vect3_1.y = array_y[g + 1] * elements->size_fact;
			vect3_1.z = array_z[g + 1] * elements->size_fact;

			/* Draw line */
			if (i != n)
			{
				rot_3d_in_z(renderer, &vect3_1, elements->rot_angle);
				conv_3dp_to_2dp(renderer, &vect3_1, &vect2_1);
				SDL_RenderDrawLine(
						renderer,
						x0 + vect2.x, y0 + vect2.y,
						x0 + vect2_1.x, y0 + vect2_1.y);
			}

			/********** Draw line in Y eje **********/
			vect3_1.x = array_x[g + n + 1] * elements->size_fact;
			vect3_1.y = array_y[g + n + 1] * elements->size_fact;
			vect3_1.z = array_z[g + n + 1] * elements->size_fact;

			/* Draw line */
			if (j != n)
			{
				rot_3d_in_z(renderer, &vect3_1, elements->rot_angle);
				conv_3dp_to_2dp(renderer, &vect3_1, &vect2_1);
				SDL_RenderDrawLine(
						renderer,
						x0 + vect2.x, y0 + vect2.y,
						x0 + vect2_1.x, y0 + vect2_1.y);
			}
			g++;

			vect3.x = array_x[g];
			vect3.y = array_y[g];
			vect3.z = array_z[g];
		}
	}
}
/**
 * draw_pnts - set points as a chess table
 *
 * @renderer: pointer to the render element in the instance structure
 * @n: size of the square, amount of points in the height and width
 */
void draw_pnts(SDL_Renderer *renderer, int n)
{
	/* x and y are the zero ejes */
	int x0 = window_width / 2, y0 = window_height * 0.3,
	    x = x0, y = y0, a = 100, i, j;
	vec2 vect2, vect2x, vect2y;
	vec3 vect3, vect3x, vect3y;

	/* Zero Point */
	vect3.x = x;
	vect3.y = y;
	vect3.z = 0;
	/* X factor */
	vect3x.x = a;
	vect3x.y = 0;
	vect3x.z = 0;
	conv_3dp_to_2dp(renderer, &vect3x, &vect2x);
	/* Y factor */
	vect3y.x = 0;
	vect3y.y = a;
	vect3y.z = 0;
	conv_3dp_to_2dp(renderer, &vect3y, &vect2y);
	/* Z factor */

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	for (j = 0; j <= n; j++)
	{
		for (i = 0; i <= n; i++)
		{
			SDL_RenderDrawPoint(
					renderer,
					x, y
					);

			SDL_RenderDrawPoint(
					renderer,
					x, y
					);

			x = x + vect2x.x;
			y = y + vect2x.y;
		}
		x = x0 - (vect2x.x * (j + 1));
		y = y0 + (vect2x.y * (j + 1));
	}
}
