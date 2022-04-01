#include "head.h"

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
	while(1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);

		if (poll_events(&elements) == 1)
			break;

		/* Draw */
		//draw_2D_ejes(instance.renderer);
		//draw_3D_ejes(instance.renderer);
		//draw_grid_2d(instance.renderer, 7);
		draw_grid_3d(instance.renderer, 7, &elements);
		//draw_pnts(instance.renderer, 7);
		//draw_plane(instance.renderer);

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
