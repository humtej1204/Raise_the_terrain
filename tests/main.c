#include "head.h"

static const int width = 800;
static const int height = 600;

int main(int argc, char **argv)
{
	/* Initialize SDL */
	SDL_Init(SDL_INIT_VIDEO);

	/* Create an SDL Window */
	SDL_Window *window = SDL_CreateWindow(
			"Hello, SDL2",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_OPENGL
			);

	/* Create a Render (Accelerated and in SYNC with the display refresh rate) */
	SDL_Renderer *renderer = SDL_CreateRenderer(
			window,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
			);

	/* Set Color */
	SDL_SetRenderDrawColor(renderer, 159, 123, 147, 255);

	bool run = true;
	SDL_Event event;
	while(run)
	{
		/* Process events */
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				run = false;
		}

		/* Clean Screen */
		SDL_RenderClear(renderer);

		/* Draw */
		

		/* Show what was drawn */
		SDL_RenderPresent(renderer);
	}

	/**
	 * Set Delay
	 * SDL_Delay(5000);
	 */

	/* Release resources */
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
