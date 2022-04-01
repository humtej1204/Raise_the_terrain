#include "head.h"
/**
 * init_instance - Function that init a new instance of
 * a rendering context for a window
 *
 * @instance: pointer to a render structure
 *
 * Return: 0 if the program End Successfully, 1 if an error
 */
int init_instance(SDL_Instance *instance)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}

	/* Create a new Window Instance */
	instance->window = SDL_CreateWindow(
			"Hello, SDL2",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			window_width,
			window_height,
			SDL_WINDOW_OPENGL
			);

	if (instance->window == NULL)
	{
		printf("SDL_CreateWindow ERROR: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Create a new Render instance linked to the window */
	instance->renderer = SDL_CreateRenderer(
			instance->window,
			-1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
			);

	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		printf("SDL_CreateRenderer ERROR: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	return (0);
}

/**
 * poll_events - Function that work with keyboard events
 *
 * @elements: Pointer to the struct elements
 *
 * Return: 0 if no event is select
 */
int poll_events(elem *elements)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				/* If ESC is pressed */
				if (key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					return (1);
				if (key.keysym.scancode == SDL_SCANCODE_LEFT)
					elements->rot_angle = elements->rot_angle + 20;
				if (key.keysym.scancode == SDL_SCANCODE_RIGHT)
					elements->rot_angle = elements->rot_angle - 20;
				if (key.keysym.scancode == SDL_SCANCODE_UP)
					elements->size_fact = elements->size_fact + 1;
				if (key.keysym.scancode == SDL_SCANCODE_DOWN)
				{
					if (elements->size_fact != 1)
						elements->size_fact = elements->size_fact - 1;
				}
				break;
		}
	}
	return (0);
}

/**
 * draw_2D_ejes - Draw 2D ejes
 *
 * @renderer: pointer to the render element in instance structure
 */
void draw_2D_ejes(SDL_Renderer *renderer)
{
	vec2 vect2;
	int angle, x = window_width / 2, y = window_height / 2;

	/* Eje X */
	vect2.x = 400;
	vect2.y = 0;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(
			renderer,
			x - vect2.x, y - vect2.y,
			x + vect2.x, y + vect2.y);
	/* Eje Y */
	vect2.x = 0;
	vect2.y = 400;
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(
			renderer,
			x - vect2.x, y - vect2.y,
			x + vect2.x, y + vect2.y);
}

/**
 * draw_3D_ejes - Draw 3D ejes
 *
 * @renderer: pointer to the render element in instance structure
 */
void draw_3D_ejes(SDL_Renderer *renderer)
{
	vec3 vect3;
	vec2 vect2;
	int angle, x = window_width / 2, y = window_height / 2;

	/* Eje X */
	vect3.x = 400;
	vect3.y = 0;
	vect3.z = 0;
	conv_3dp_to_2dp(renderer, &vect3, &vect2);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(
			renderer,
			x, y,
			x + vect2.x, y + vect2.y);
	/* Eje Y */
	vect3.x = 0;
	vect3.y = 400;
	vect3.z = 0;
	conv_3dp_to_2dp(renderer, &vect3, &vect2);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(
			renderer,
			x, y,
			x + vect2.x, y + vect2.y);
	/* Eje Z */
	vect3.x = 0;
	vect3.y = 0;
	vect3.z = 400;
	conv_3dp_to_2dp(renderer, &vect3, &vect2);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderDrawLine(
			renderer,
			x, y,
			x + vect2.x, y + vect2.y);
}
