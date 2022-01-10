#include "../includes/shapes.h"

void DrawRectangle(SDL_Renderer *renderer, int32_t hauteur, int32_t largeur, int32_t altitude)
{
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

	Draw_vertical_line(renderer, altitude, altitude, hauteur);
	Draw_vertical_line(renderer, altitude, altitude + largeur, hauteur);
	Draw_horizontal_line(renderer, altitude, altitude, largeur);
	Draw_horizontal_line(renderer, altitude + hauteur, altitude, largeur);
}

void fill_rectangle(SDL_Renderer *renderer, int32_t hauteur, int32_t largeur, int32_t altitude, couleur *couleur)
{
	for (int i = 0; i < largeur; i += 1) {
		SDL_SetRenderDrawColor(renderer, couleur[i % 316].r,couleur[i % 316].g,couleur[i % 316].b, 255);

		Draw_vertical_line(renderer, altitude, altitude + i, hauteur);
	}
}
