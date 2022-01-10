#include "includes/shapes.h"

SDL_Window *win;
SDL_Renderer *renderer;

/* les paramètres argc et argv sont OBLIGATOIRES ! */
int main(int argc, char *argv[])
{
	SDL_Event events;
	int x; /* coord. x du coin haut gauche de la fenêtre */
	int y; /* coord. y du coin haut gauche de la fenêtre */
	int w; /* largeur de la fenêtre */
	int h; /* hauteur de la fenêtre */
	int running;

	/* SDL doit être initialisé */

	(void)argc;
	(void)argv;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"error : %s\n", SDL_GetError());
		return -1;
	}

	/* on crée la fenêtre et on la montre */
	x = 60;
	y = 60;
	w = 800;
	h = 600;
	win = SDL_CreateWindow("Fractale",
			x, y, w, h,
			SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"error : %s\n", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
				"error : %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return -1;
	}
	/* on sélectionne la couleur blanche */
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	/*
	 * on remplit un "tableau" de la taille de la fenêtre
	 * avec la couleur ci-dessus
	 */
	SDL_RenderClear(renderer);


  couleur *c = gradient1(316);


  // draw line

  // les quadrilatères
  DrawRectangle(renderer, 101, 81, 69);
  fill_rectangle(renderer, 100, 80, 70, c);

  // les cercles
  DrawCircle(renderer, 500, 500, 71);
  fill_circle(renderer, 500, 500, 70, c);

	// le triangle
	coord *triangle_points; // cree un pointeur sur le premier maillon d'une suite de structure

	triangle_points = NULL; // initialisé a null pour pouvoir construire dessus (l'autre méthode est de crée un maillon vide au début)
  coord *new; // crée un pointeur sur structure
  new = (coord *)malloc(sizeof(coord)); // allouer de la mémoire
  init_new_coordonnees(new, 100, 200); // initialisé ce nouveau maillon qui sera ensuite ajouté à la suite de maillons
  push_back_coordonnees(&triangle_points, new); // on l'envoie à la fin de la suite d'éléments (autant qu'on veut de point on réitère l'opération)

  new = (coord *)malloc(sizeof(coord));
  init_new_coordonnees(new, 200, 300);
  push_back_coordonnees(&triangle_points, new);

  new = (coord *)malloc(sizeof(coord));
  init_new_coordonnees(new, 200, 100);
  push_back_coordonnees(&triangle_points, new);

  // triangle
  draw_triangle_filled(renderer, triangle_points);

	coord *losange_points;

	losange_points = NULL;
	new = (coord *)malloc(sizeof(coord));
  init_new_coordonnees(new, 250, 250);
  push_back_coordonnees(&losange_points, new);

	new = (coord *)malloc(sizeof(coord));
  init_new_coordonnees(new, 450, 400);
  push_back_coordonnees(&losange_points, new);

	new = (coord *)malloc(sizeof(coord));
  init_new_coordonnees(new, 450, 300);
  push_back_coordonnees(&losange_points, new);

	draw_losange(renderer, losange_points);

	draw_ellipse(renderer, 300, 450, 71);
	fill_ellipse(renderer, 300, 450, 69, c);

  /* on affiche le "tableau" dans la fenêtre */
  SDL_RenderPresent(renderer);

	running = 1;
	while (running)
	{
		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{
				/* cliquer sur la croix ferme la fenêtre */
				case SDL_QUIT:
					/* on sort de la boucle */
					running = 0;
					break;
				case SDL_KEYDOWN:
					switch (events.key.keysym.sym)
					{
						case 'q':
							running = 0;
							break;
					}
			}
		}
	}
  SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
