#include "../includes/shapes.h"

void draw_losange(SDL_Renderer * renderer, coord *points)
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
	// tracer des côtés
	int dist_y2_y3 = _abs(third_point->y - second_point->y); // distance absolue entre l'ordonnée du second et du troisième point
	int dist_x_3_1 = _abs(third_point->x - first_point->x); // distance absolue entre les absisces du premier de troisième point

	// on dessine les côtés gauches et droits ici à l'aide des distances calculées
	SDL_SetRenderDrawColor(renderer, 255, 127, 0, SDL_ALPHA_OPAQUE);
	Draw_line(renderer, second_point->x - dist_x_3_1, first_point->y, third_point->x - dist_x_3_1, first_point->y - dist_y2_y3);
	SDL_SetRenderDrawColor(renderer, 255, 128, 0, SDL_ALPHA_OPAQUE);
	Draw_line(renderer, second_point->x, second_point->y, third_point->x, third_point->y);
	// on itère par pas de 2 sur la distance ordonnée du 3eme point et ordonée du second
	for (int i = 0; i < _abs(third_point->y - second_point->y); i += 2)
	{
		// on dessine comme ça les contours du bas et du haut car les lignes sont déssinés "horizontalement"
		if (i + 2 < _abs(third_point->y - second_point->y) && i > 0)
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		else
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		// on trace une ligne entre le premier et le second point (jusqu'à arrivé au 3eme grâce à la boucle)
		// on décalle que les ordonées ça nous donne un losange (en decalant aussi les absisce on obtient un triangle)
		Draw_line(renderer, first_point->x, first_point->y - (2 + i), second_point->x, second_point->y - (2 + i));
	}
}
