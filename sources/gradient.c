#include "../includes/shapes.h"

couleur *gradient1(int cmax)
{
	couleur *t = (couleur *)malloc(cmax *sizeof(couleur));
	for(int i=0;i<cmax;i++)
	{
		t[i].r = (255*i)/(cmax-1);
		t[i].g = 0;
		t[i].b = 0;
	}
	return t;
}
