#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "item.h"
#include "affichage.h"


void spawnItem(SDL_Renderer* renderer, int* nbreItem,
	int* itemX, int* itemY, int x, int y) {

	if (*nbreItem == 1)
	{
		draw(renderer, *itemX, *itemY, 30, 30, 255, 0, 0);
		//printf("item : %d %d", *itemX, *itemY);
		if ((x <= *itemX + 30 && x >= *itemX ||
			x + 50 <= *itemX + 30 && x + 50 >= *itemX) &&
			(y <= *itemY + 30 && y >= *itemY ||
				y + 50 <= *itemY + 30 && y + 50 >= *itemY))
		{
			//printf("collision");
			*nbreItem = 0;
		}
	}
	else
	{
		*itemX = rand() % (800-30+1);
		*itemY = rand() % (600 -30 + 1);
		draw(renderer, *itemX, *itemY, 30, 30, 255, 0, 0);
		//printf("item : %d %d", *itemX, *itemY);
		*nbreItem = 1;
	}
}

