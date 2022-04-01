#include "head.h"
/**
 * draw_grid_2d - set points as a chess table
 *
 * @renderer: pointer to the render
 * @n: size of the square, amount of points in the height and width
 */
void draw_grid_2d(SDL_Renderer *renderer, int n)
{
        /* x and y are the zero ejes */
        int x = window_width * 0.3, y = window_height * 0.1,
	    a = 100, i, j;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	for (j = 0; j <= n; j++)
        {
                for (i = 0; i <= n; i++)
                {
                        if (i != n)
                                SDL_RenderDrawLine(
                                                renderer,
                                                x, y,
                                                x + a, y);
                        if (j != n)
                                SDL_RenderDrawLine(
                                                renderer,
                                                x, y,
                                                x, y + a);

                        x = x + a;
                }
                x = window_width * 0.3;
                y = y + a;
        }
}
