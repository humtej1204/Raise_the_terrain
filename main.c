#include "head.h"
/**
 * main - Main function (Start point)
 *
 * Return: Return 0 if all it's OK
 */
int main(void)
{
	SDL_Instance instance;
	elem elements;

	elements.rot_angle = 0;
	elements.segm_sep = 75;
	elements.size_fact = 1;

	if (init_instance(&instance) != 0)
		return (1);

	/* Infinite Loop */
	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);

		if (poll_events(&elements) == 1)
			break;

		/* Draw */
		draw_grid_3d(instance.renderer, 7, &elements);

		SDL_RenderPresent(instance.renderer);
		/**
		 * More info about SDL Functions:
		 * https://wiki.libsdl.org/CategoryAPI
		 * https://wiki.libsdl.org/wiki/index
		 */
	}

	/* Quit SDL */
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}
