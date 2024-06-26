#pragma once
#ifndef AFFICHAGE_H
#define AFFICHAGE_H

SDL_Rect draw(SDL_Renderer* renderer, int x, int y, int largeur,
	int longueur, int R, int G, int B);

SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);

void renderImage(SDL_Renderer* renderer, SDL_Texture* texture, int posx,
	int posy, int width, int height);
#endif