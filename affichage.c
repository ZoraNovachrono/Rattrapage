#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>

#include "affichage.h"

SDL_Rect draw(SDL_Renderer* renderer, int x, int y, int largeur, int longueur,
    int R, int G, int B) {
    SDL_Rect gameobj = { x, y, largeur, longueur };
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    SDL_RenderFillRect(renderer, &gameobj);
    return gameobj;
}

SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) {
        printf("Erreur lors du chargement de l'image : %s\n", IMG_GetError());
        return NULL; // Retourne NULL pour indiquer une erreur
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface); // Libérer la surface, nous n'en avons plus besoin
    if (!texture) {
        printf("Erreur lors de la création de la texture : %s\n", 
            SDL_GetError());
        return NULL; // Retourne NULL pour indiquer une erreur
    }
    return texture;
}

void renderImage(SDL_Renderer* renderer, SDL_Texture* texture,
    int posx, int posy, int width, int height) {
    SDL_Rect destRect = { posx, posy, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}