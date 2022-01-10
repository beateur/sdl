#include "../includes/shapes.h"

void push_back_coordonnees(coord **points, coord *new)
{
  coord *latest; // créer un élément grace auquel on pourra itérer sur la suite de maillon sans déplacer
  //le curseur original qui nous a été envoyé par le main et qui servira plus tard (il ne faut jamais perdre le curseur original)

  if (!points) // uniquement s'il y a un problème indéfini car aucune adresse n'est censée être nulle pas même celle des éléments pointant sur NULL
    return ;
  if (!(*points)) // premier passage pas besoin d'itérer puisqu'il n'y a aucunn élément existant dans la chaîne
    *points = new;
  else
  {
    latest = *points; // notre élément latest pointe mtn sur le début de la chaîne de maillons
    while (latest->next) // tant qu'il existe un prochain maillon
      latest = latest->next; // on y va (latest pointe sur le maillon suivant)
    latest->next = new; // latest est arrivé au dernier maillon de la file dans lequel le pointeur ->next pointe sur NULl
    // on va donc faire pointer ce pointeur sur le nouveau maillon a ajouter
  }
}

void init_new_coordonnees(coord *new, int x, int y)
{
  new->x = x;
  new->y = y;
  new->next = NULL;
}
