#include "head.h"
/**
 * draw_points - set points as a chess table
 *
 * @renderer: pointer to the render
 * @n: size of the square, amount of points in the height and width
 */
void draw_points(SDL_Renderer *renderer, int n)
{
	int x, y;

	for (y = 1; y <= n; y++)
	{
		for (x = 1; x <= n; x++)
		{
			SDL_RenderDrawPoint(renderer, x * 100, y * 100);
		}
	}
}

int main(int argc, char* argv[])
{
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
                SDL_Window* window = NULL;
                SDL_Renderer* renderer = NULL;

                if (SDL_CreateWindowAndRenderer(1280, 960, 0, &window, &renderer) == 0) {
                        SDL_bool done = SDL_FALSE;

                        while (!done) {
                                SDL_Event event;

                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                                SDL_RenderClear(renderer);

                                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                                
				/*  */
				draw_points(renderer, 7);
                                
				SDL_RenderPresent(renderer);

                                while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_QUIT) {
                                                done = SDL_TRUE;
                                        }
                                }
                        }
                }

                if (renderer) {
                        SDL_DestroyRenderer(renderer);
                }
                if (window) {
                        SDL_DestroyWindow(window);
                }
        }
        SDL_Quit();
        return 0;
}
