#include "../includes/shapes.h"

void draw_triangle_filled(SDL_Renderer * renderer, coord *points)
{
	coord *first_point;
	coord *second_point;
	coord *third_point;

	first_point = points;
	second_point = points->next;
	third_point = points->next->next;
	if (!first_point || !second_point || !third_point)
	{
		fprintf(stderr, "pas assez de points pour tracer un triangle");
		return ;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
	Draw_line(renderer, first_point->x, first_point->y, second_point->x, second_point->y);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	Draw_line(renderer, second_point->x, second_point->y, third_point->x, third_point->y);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	Draw_line(renderer, first_point->x, first_point->y, third_point->x, third_point->y);
	for (int i = 0; i < _abs(third_point->x - first_point->x); i += 2)
	{
		if (i > 0)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			Draw_line(renderer, third_point->x - i, third_point->y + i, second_point->x - i, second_point->y - i);
		}
	}
}
