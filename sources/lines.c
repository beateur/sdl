#include "../includes/shapes.h"


void Draw_horizontal_line(SDL_Renderer * renderer, int32_t altitude, int32_t debut, int32_t fin)
{
	int   i = debut;

	while (i < (debut + fin))
	{
		SDL_RenderDrawPoint(renderer, i++, altitude);
	}
}

void Draw_vertical_line(SDL_Renderer * renderer, int32_t altitude, int32_t absisce, int32_t fin)
{
	int   i = 0;

	while (i < fin)
	{
		SDL_RenderDrawPoint(renderer, absisce, altitude + i++);
	}
}

/*
/// la fonction draw line est capable de tracer n'importe quelle ligne pointillée entre 2 coordonnées données
/// 4 cas:
/// - l'absisce et l'ordonée du premier point sont tout 2 supérieur a celles du second
/// - seule l'absisce du premier est supérieure à celle du second
/// - seule l'ordonnée du premier est supérieure à celle du second
/// - l'absisce et l'ordonée du second point sont tout 2 supérieur a celles du premier
*/

void Draw_line(SDL_Renderer * renderer, int32_t x_begin, int32_t y_begin, int32_t x_end, int32_t y_end)
{
	double   x_tracer = _abs(x_begin - x_end);
	double   y_tracer = _abs(y_begin - y_end);
	double diff = x_tracer - y_tracer;
	double scale; // diff et scale permettent de savoir qu'elle translation entre la translation sur l'axe des ordonnées
	// ou celle sur l'axe des absisces nécéssitera le plus d'itérations et l'objectif est grâce au scale d'avoir autant
	// d'itérations pour les 2 translations (on perd en précision néanmoins)

	if (x_tracer == 0 || y_tracer == 0)
		scale = 1;
	else
		scale = diff > 0 ? (double)((double)x_tracer/(double)y_tracer): (double)((double)y_tracer/(double)x_tracer);
	while (x_tracer || y_tracer)
	{
		if (x_begin > x_end && y_begin > y_end)
			SDL_RenderDrawPoint(renderer, x_begin - x_tracer, y_begin - y_tracer);
		else if (x_begin > x_end)
			SDL_RenderDrawPoint(renderer, x_begin - x_tracer, y_begin + y_tracer);
		else if (y_begin > y_end)
			SDL_RenderDrawPoint(renderer, x_begin + x_tracer, y_begin - y_tracer);
		else
			SDL_RenderDrawPoint(renderer, x_begin + x_tracer, y_begin + y_tracer);
		if (diff > 0)
		{
			if (x_tracer > scale)
				x_tracer -= scale;
			else if (x_tracer > 0)
				x_tracer -= x_tracer;
			if (y_tracer > 0)
				y_tracer--;
		}
		else
		{
			if (y_tracer > scale)
				y_tracer -= scale;
			else if (y_tracer > 0)
				y_tracer -= y_tracer;
			if (x_tracer > 0)
				x_tracer--;
		}
	}
}
