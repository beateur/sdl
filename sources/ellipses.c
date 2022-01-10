#include "../includes/shapes.h"

/*
/// même principe que les cercles pour les ellipses on utilise un ratio artiraire de 2 pour avoir des décallages plus grands
/// le calcul d'erreur permet d'obtenir un arrondien se basant sur des itérations linéaire 
*/
void draw_ellipse(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius)
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
		SDL_RenderDrawPoint(renderer, centreX + (x * 2), centreY - y);
		SDL_RenderDrawPoint(renderer, centreX + (x * 2), centreY + y);
		SDL_RenderDrawPoint(renderer, centreX + (y * 2), centreY - x);
		SDL_RenderDrawPoint(renderer, centreX + (y * 2), centreY + x);

		// côté gauche du cercle
		SDL_RenderDrawPoint(renderer, centreX - (x * 2), centreY - y);
		SDL_RenderDrawPoint(renderer, centreX - (x * 2), centreY + y);
		SDL_RenderDrawPoint(renderer, centreX - (y * 2), centreY - x);
		SDL_RenderDrawPoint(renderer, centreX - (y * 2), centreY + x);

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

void fill_ellipse(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius, couleur *couleur)
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

		for (int i = centreY - y; i <= (centreY + y); i += 1)
		{
			// en modifiant la couleur avec la structure de couleur à taton on peut obtenir des effets beaux (le i/4 est arbitraire)
			SDL_SetRenderDrawColor(renderer, couleur[i % 316].r,couleur[i % 316].g,couleur[i % 316].b + i/4, 255);

			// ces points dessinent les quartiles gauche et droite (on fait varier le x)
			SDL_RenderDrawPoint(renderer, centreX - (x * 2), i);
			SDL_RenderDrawPoint(renderer, centreX - (y * 2), i);
			SDL_RenderDrawPoint(renderer, centreX + (x * 2), i);
			SDL_RenderDrawPoint(renderer, centreX + (y * 2), i);

			// ces points dessinent les quartiles haut et bas (on fait varier le y)
			SDL_RenderDrawPoint(renderer, (i - centreX) * 2, - x + centreY);
			SDL_RenderDrawPoint(renderer, (i - centreX) * 2, - y + centreY);
			SDL_RenderDrawPoint(renderer, (i - centreX) * 2, x + centreY);
			SDL_RenderDrawPoint(renderer, (i - centreX) * 2, y + centreY);
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
