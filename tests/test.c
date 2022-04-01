#include "head.h"

int main(int argc, char* argv[])
{
        if (SDL_Init(SDL_INIT_VIDEO) == 0) {
                SDL_Window* window = NULL;
                SDL_Renderer* renderer = NULL;

                if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer) == 0) {
                        SDL_bool done = SDL_FALSE;

                        while (!done) {
                                SDL_Event event;

                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                                SDL_RenderClear(renderer);

                                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                                
				/*  */
				draw_points(renderer, 7);
				//draw_grid_3d(renderer, 7);
				//draw_plane(renderer);
				//draw_pnts(renderer, 7);
				//draw_grid_3d(renderer, 7);
                                
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
