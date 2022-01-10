#ifndef _SHAPES_H_
# define _SHAPES_H_

# include <stdio.h>
# include <SDL.h>

typedef struct couleur couleur ;
typedef struct coordonnee coord ;

struct couleur
{
	char r;
	char g;
	char b;
};

struct coordonnee
{
  int x;
  int y;
  struct coordonnee *next; // l'adresse à laquelle se situe les éléments d'une autre structure de type coordonnee
};

double _abs(int nb);
void fill_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius, couleur *couleur);
void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
couleur *gradient1(int cmax);
void Draw_horizontal_line(SDL_Renderer * renderer, int32_t altitude, int32_t debut, int32_t fin);
void Draw_vertical_line(SDL_Renderer * renderer, int32_t altitude, int32_t absisce, int32_t fin);
void Draw_line(SDL_Renderer * renderer, int32_t x_begin, int32_t y_begin, int32_t x_end, int32_t y_end);
void push_back_coordonnees(coord **points, coord *new);
void init_new_coordonnees(coord *new, int x, int y);
void draw_losange(SDL_Renderer * renderer, coord *points);
void DrawRectangle(SDL_Renderer *renderer, int32_t hauteur, int32_t largeur, int32_t altitude);
void fill_rectangle(SDL_Renderer *renderer, int32_t hauteur, int32_t largeur, int32_t altitude, couleur *couleur);
void draw_triangle_filled(SDL_Renderer * renderer, coord *points);
void draw_ellipse(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius);
void fill_ellipse(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius, couleur *couleur);
#endif
