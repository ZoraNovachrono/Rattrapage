#include <SDL.h>
#include <stdio.h>

#include "affichage.h"

SDL_Rect draw(SDL_Renderer* renderer, int x, int y, int largeur, int longueur,
    int R, int G, int B) {
    SDL_Rect gameobj = { x, y, largeur, longueur };
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    SDL_RenderFillRect(renderer, &gameobj);
    return gameobj;
}