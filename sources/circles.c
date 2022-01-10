#include "../includes/shapes.h"

void fill_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius, couleur *couleur)
{
	const int32_t diameter = (radius * 2);

	int32_t x = (radius - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);

	while (x >= y)
	{
		for (int i = centreY - y; i <= (centreY + y); i += 1)
		{
			// en modifiant la couleur avec la structure de couleur à taton on peut obtenir des effets beaux (le i/4 est arbitraire)
			SDL_SetRenderDrawColor(renderer, couleur[i % 316].r,couleur[i % 316].g,couleur[i % 316].b + i/4, 255);

			// ces points dessinent les quartiles gauche et droite (on fait varier le x)
			SDL_RenderDrawPoint(renderer, centreX - x, i);
			SDL_RenderDrawPoint(renderer, centreX - y, i);
			SDL_RenderDrawPoint(renderer, centreX + x, i);
			SDL_RenderDrawPoint(renderer, centreX + y, i);

			// ces points dessinent les quartiles haut et bas (on fait varier le y)
			SDL_RenderDrawPoint(renderer, i, centreX - x);
			SDL_RenderDrawPoint(renderer, i, centreX - y);
			SDL_RenderDrawPoint(renderer, i, centreX + x);
			SDL_RenderDrawPoint(renderer, i, centreX + y);
		}

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}

void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
	const int32_t diameter = (radius * 2);

	int32_t x = (radius - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	while (x >= y)
	{
		//  côté droit du cercle
		SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);

		// côté gauche du cercle
		SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
		SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
		SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}
